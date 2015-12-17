/*
 * CG Major Project, Monsoon 2015
 * Author: Sarthak Ahuja, 2012088 | IIIT-Delhi
 *
 * Description:
 */

#include<shader_utils.h>
#include"Scene.h"
#include"qevent.h"
#include "unistd.h"
#include "Filter.h"

#include <sstream>
#include "QMessageBox"
#include"qapplication.h"


namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}
Scene::Scene(QWidget *parent) : QGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    filter=new Filter();
}

Scene::~Scene()
{

}

void Scene::initializeGL()
{

     GLenum glew_status = glewInit();

     glClearColor(1.0f, 1.0f, 1.0f, 1.0f);


     if (glew_status != GLEW_OK)
     {
       fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_status));

     }


     GLint compile_ok = GL_FALSE, link_ok = GL_FALSE;

     GLuint vs,fs;

     vs = create_shader("../CGMajor/triangle.v.glsl",GL_VERTEX_SHADER);
     fs = create_shader("../CGMajor/triangle.f.glsl",GL_FRAGMENT_SHADER);


     program = glCreateProgram();
     glAttachShader(program, vs);
     glAttachShader(program, fs);
     glLinkProgram(program);
     glGetProgramiv(program, GL_LINK_STATUS, &link_ok);
     if (!link_ok) {
        fprintf(stderr, "glLinkProgram:");
        print_log(program);
     }
     glGenBuffers(1, &vbo_triangle);
     glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
     const char* attribute_name = "coord2d";
     attribute_coord2d = glGetAttribLocation(program, attribute_name);
     attribute_name = "v_color";
     attribute_v_color = glGetAttribLocation(program, attribute_name);
     if (attribute_v_color == -1) {
       fprintf(stderr, "Could not bind attribute %s\n", attribute_name);
       return;
     }

     human=new Human(program, attribute_coord2d, vbo_triangle, attribute_v_color, this->width(), this->height());
}

void Scene::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);

}

void Scene::paintGL()
{
    if(debug) if(debug) qDebug("Debug: '%s'", "Paint Screen");
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPointSize(10.0f);
    glLineWidth(10.0f);
    if(debug) if(debug) qDebug("Debug: '%s'", "Debugging...");
    this->human->draw(this->human->jointTree);
    this->body=this->human->getBody();


    //Display Kinect Data
    for(int i=0;i<body.size();i++){
        Joint* joint=body[i];
        glLineWidth(2.5);

        if(joint->getID()!=this->human->getAnchor()){
            glColor3f(0.0, 1.0, 0.0);
        }
        else{
            glColor3f(0.0, 0.0, 0.0);
        }
        if(joint->getParent()!=NULL){
            if(this->human->Rigging.size()!=0){
                int parentId=joint->getParent()->getID();
                int thisId=joint->getID();

                //Bring to Origin
                double kinect_x_anchor=this->human->Rigging.at(thisId).first-0.5;
                double kinect_y_anchor=-this->human->Rigging.at(thisId).second+0.5;
                double kinect_x_parent=this->human->Rigging.at(parentId).first-0.5;
                double kinect_y_parent=-this->human->Rigging.at(parentId).second+0.5;

                glBegin(GL_LINES);
                glVertex2f(kinect_x_anchor, kinect_y_anchor);
                glVertex2f(kinect_x_parent, kinect_y_parent);
                glEnd();
            }
        }
    }
}

void  Scene::mousePressEvent(QMouseEvent* e)
{
        if(debug) if(debug) qDebug("Debug: '%s'", "Mouse Pressed");
        if(e->button() == Qt::LeftButton)
        {
            human->moveJoint(calculateTransformation(0));
            //human->updatePose(calculateTransformation());
            repaint();
        }
        if(e->button() == Qt::RightButton)
        {
            human->moveJoint(calculateTransformation(1));
            //human->updatePose(calculateTransformation());
            repaint();
        }
}
/*
void Scene::mousePressEvent(QMouseEvent* e)
{

    if(debug) if(debug) qDebug("Debug: '%s'", "Mouse Pressed");
	if(e->button() == Qt::LeftButton)
	{
        startPoint = e->localPos();
	}
}

void Scene::mouseMoveEvent(QMouseEvent* e)
{

    if(debug) if(debug) qDebug("Debug: '%s'", "Mouse Move");
	if(e->buttons() & Qt::LeftButton)
	{
        if ((e->pos() - startPoint).manhattanLength() < QApplication::startDragDistance())
        {
            return;
        }
        endPoint = e->localPos();

        if(this->human->getAnchor() != NONE)
       {
            human->moveJoint(calculateTransformation());
            repaint();
        }
	}
}

void Scene::mouseReleaseEvent(QMouseEvent* e)
{

        if(debug) if(debug) qDebug("Debug: '%s'", "Mouse Released");

        human->moveJoint(calculateTransformation());
        human->updatePose(calculateTransformation());
        repaint();
}
*/
Transformation Scene::calculateTransformation(int i){
        Transformation T;
        /*
        QPointF a;
        a.setX(this->human->findJoint(this->human->jointTree,this->human->getAnchor())->getTip().x()-this->startPoint.x());
        a.setY(this->human->findJoint(this->human->jointTree,this->human->getAnchor())->getTip().y()-this->startPoint.y());
        if(debug) if(debug) qDebug("Debug: 'Rotation -a %f %f'", a.x(),a.y());
        QPointF b;
        b.setX(this->human->findJoint(this->human->jointTree,this->human->getAnchor())->getTip().x()-this->endPoint.x());
        b.setY(this->human->findJoint(this->human->jointTree,this->human->getAnchor())->getTip().y()-this->endPoint.y());
        if(debug) if(debug) qDebug("Debug: 'Rotation -b %f %f'", b.x(),b.y());
        if(debug) if(debug) qDebug("Debug: 'Rotation - %s'", "theta");
        double num=a.x()*b.x()+a.y()*b.y();
        double den=sqrt(pow(a.x(),2)+pow(a.y(),2))*sqrt(pow(b.x(),2)+pow(b.y(),2));
        double theta=acos(num/den);
        if(den==0){
            theta=0;
        }
        else{
            theta=acos(num/den);
        }
*/
        if(i==0){
            T.setRotation(0.1);
        }
        else{
            T.setRotation(-0.1);
        }

        if(debug) if(debug) qDebug("Debug: 'Rotation - %f'", 0.1);
        return T;
}

void Scene::reset(){
    human=new Human(program, attribute_coord2d, vbo_triangle, attribute_v_color, this->width(), this->height());
    repaint();
}

void Scene::runData(){
    std::vector< std::map <int, std::pair<double, double> > > frames= dataSet->getData();
    if(doFilter){
        frames = filter->doFilter(frames);

        QMessageBox msgBox;
        msgBox.setText(patch::to_string(frames.size()).c_str());
        msgBox.exec();
    }
    for(int i=0;i<frames.size();i++){
        human->performRigging(frames.at(i));
        human->matchSkeleton(human->jointTree);
        Sleep(25);
        repaint();
    }
}

void Scene::runLive(){
    Sleep(3000);
    while(liveData->getRunning()){
        if(debug) if(debug) qDebug("Debug: 'Debugging - %f'", 0.1);
        liveData->fetch();
        std::vector< std::map <int, std::pair<double, double> > > frames= liveData->getData();

        if(doFilter){
            frames = filter->doFilter(frames);

        }

        for(int i=0;i<frames.size();i++){
            human->performRigging(frames.at(i));
            human->matchSkeleton(human->jointTree);
            Sleep(25);
            repaint();
        }
        liveData->clear();
    }
}
