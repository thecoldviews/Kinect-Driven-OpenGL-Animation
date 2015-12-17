/*
 * CG Major Project, Monsoon 2015
 * Author: Sarthak Ahuja, 2012088 | IIIT-Delhi
 *
 * Description:
 */

#ifndef JOINT_H
#define JOINT_H

#include <Transformation.h>
#include <qcolordialog.h>
#include <qwidget.h>
#include <QGLWidget>

typedef struct
 {
    float x,	/* Coords */
          y,
          r,	/* Colors or texture infos */
          g,
          b;
 } Vertex;


class Joint
{

protected:
    bool debug=false;
    int JointId;
    Joint* parent;
    std::vector<Joint*> children;
    QPointF tip;
    int width;
    int height;
    GLuint Texture;
    Vertex vertex[4];
    QColor colorFill;
    QColor colorStroke;
    GLuint vbo_triangle;
    GLuint program;
    GLint attribute_coord2d;
    GLint attribute_v_color;

public:
    Transformation T;
    Joint(GLuint vb0, GLuint program, GLint attrib_coord2d,GLint attrib_v_color, int w, int h, int id){
        this->attribute_coord2d=attrib_coord2d;
        this->attribute_v_color=attrib_v_color;
        this->vbo_triangle=vb0;
        this->program=program;
        this->height=h;
        this->width=w;
        this->JointId=id;
        this->colorStroke = Qt::black;
        this->colorFill = Qt::black;
        Transformation T;
        T.setRotation(0);
        this->T=T;
    }
    virtual ~Joint(){}
    virtual void init()=0;
    virtual void drawGraphic()=0;
    virtual void createVertices()=0;
    virtual void loadTexture()=0;
    virtual bool checkConstraints(Transformation T)=0;
    void transform(Transformation T);
    void transformAbout(Transformation T, Joint* J);

    void setParent(Joint* parent){
        this->parent=parent;
    }

    Joint* getParent(){
        return this->parent;
    }

    void setTransformation(Transformation T){
        this->T=T;
    }

    Transformation getTransformation(){
        return this->T;
    }

    void setChildren(std::vector< Joint* >children){
        this->children=children;
    }

    std::vector<Joint*> getChildren(){
        return this->children;
    }

    QPointF getTip()
    {
        return tip;
    }

    void setID(int id)
    {
        this->JointId=id;
    }

    int getID(){
        return JointId;
    }

    void setTip(const QPointF& pos)
    {
        this->tip = pos;
    }

    void setFill(const QColor& color)
    {
        this->colorFill = color;
    }

    void setStroke(const QColor& color)
    {
        this->colorStroke = color;
    }

    void LoadGLTextures( const char * name )
    {
        QImage img;

        if(!img.load(name)){
            qDebug("Debug: '%s'", "NOT FOUND");
        }
        else{
            qDebug("Debug: '%s'", "FOUND");
        }

        QImage t = QGLWidget::convertToGLFormat(img);

        glGenTextures(1, &Texture);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexImage2D(GL_TEXTURE_2D, 0, 4, t.width(), t.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, t.bits());

        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glBindTexture( GL_TEXTURE_2D, 0 );
    }

};

#endif // JOINT_H
