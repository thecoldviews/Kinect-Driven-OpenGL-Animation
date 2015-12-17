/*
 * CG Major Project, Monsoon 2015
 * Author: Sarthak Ahuja, 2012088 | IIIT-Delhi
 *
 * Description:
 */


#include"GL\glew.h"
#include "Human_Joints.h"

void Bone_Center::loadTexture(){
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures("C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Body\\center.png");
}

void Bone_Center::createVertices(){
    int i;
    double L=0.1;
    if (!this)
        return;

    if(this->getParent()){
        double m = (this->getParent()->getTip().y()-this->getTip().y())/(this->getParent()->getTip().x()-this->getTip().x());
        double m_norm=-1/m;
        double dx=sqrt( pow(L,2) / (1 + pow(m_norm,2)) ) / 2;
        double dy=m_norm * dx;
        this->vertex[0].x = this->getParent()->getTip().x()-dx;
        this->vertex[0].y = this->getParent()->getTip().y()-dy;

        this->vertex[1].x = this->getParent()->getTip().x()+dx;
        this->vertex[1].y = this->getParent()->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()-dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }
    else{
        double dx=L*1.5;
        double dy=L*1.5;
        this->vertex[0].x = this->getTip().x()-dx;
        this->vertex[0].y = this->getTip().y()-dy;

        this->vertex[1].x = this->getTip().x()-dx;
        this->vertex[1].y = this->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()+dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }

    for (i = 0; i < 4; i++)
    {
        this->vertex[i].r = 0;
        this->vertex[i].g = 0;
        this->vertex[i].b = 1;
    }
}

void Bone_Center::drawGraphic()
{
        if(debug) qDebug("Debug: '%d'", this->getID());

        glLineWidth(2.5);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //MESH
        glBegin(GL_QUADS);
                    glTexCoord2f(0.0f, 0.0f);

                    glVertex2f(this->vertex[0].x, this->vertex[0].y);
                    glTexCoord2f(0.0f, 1.0f);

                    glVertex2f(this->vertex[1].x, this->vertex[1].y);
                    glTexCoord2f(1.0f, 1.0f);

                    glVertex2f(this->vertex[2].x, this->vertex[2].y);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex2f(this->vertex[3].x, this->vertex[3].y);

        glEnd();
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
        glFlush();
        glColor3f(0.0, 1.0, 0.0);
        //BONES
        glBegin(GL_LINES);
        if(this->getParent()!=NULL){
            glVertex2f(this->getTip().x(), this->getTip().y());
            glVertex2f(this->getParent()->getTip().x(), this->getParent()->getTip().y());
        }
        glEnd();

    GLfloat x1,x2,y1,y2;
    if(debug) qDebug("Debug: '%s'", "Debugging...");
    if(this->getID()==CENTER){
        x1=0;
        y1=0;
    }
    else{
        x1=this->getParent()->getTip().x();
        y1=this->getParent()->getTip().y();
    }


//    x2=this->getTip().x();
//    y2=this->getTip().y();
//    if(debug) qDebug("Debug: '%f %f %f %f'", x1,y1,x2,y2);
//    GLfloat triangle_vertices[] = {
//             x1, y1, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF(),
//             x2, y2, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF()

//     };
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glUseProgram(program);
//    glEnableVertexAttribArray(attribute_coord2d);
//    glEnableVertexAttribArray(attribute_v_color);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glVertexAttribPointer(
//        attribute_coord2d,   // attribute
//        2,                   // number of elements per vertex, here (x,y)
//        GL_FLOAT,            // the type of each element
//        GL_FALSE,            // take our values as-is
//        5 * sizeof(GLfloat), // next coord2d appears every 5 floats
//        0                    // offset of the first element
//    );
//    glVertexAttribPointer(
//        attribute_v_color,      // attribute
//        3,                      // number of elements per vertex, here (r,g,b)
//        GL_FLOAT,               // the type of each element
//        GL_FALSE,               // take our values as-is
//        5 * sizeof(GLfloat),    // next color appears every 5 floats
//        (GLvoid*) (2 * sizeof(GLfloat))  // offset of first element
//    );
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    /* Push each element in buffer_vertices to the vertex shader */
//    glDrawArrays(GL_LINE_LOOP, 0,2);
//    if(debug) qDebug("Debug: '%s'", "DRAWING LINE-------");
//    glDisableVertexAttribArray(attribute_coord2d);
//    glDisableVertexAttribArray(attribute_v_color);
}

//2
void Bone_Collar::loadTexture(){
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures("C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Body\\collar.png");
}

void Bone_Collar::createVertices(){
    int i;
    double L=0.5;
    double L_=0.1;
    double L__=0.1;
    if (!this)
        return;

    if(this->getParent()){
        double alpha = atan2(this->getParent()->getTip().y()-this->getTip().y(), this->getParent()->getTip().x()-this->getTip().x());

        double x_tip = this->getTip().x() + L_ * cos(alpha);
        double y_tip = this->getTip().y() + L_ * sin(alpha);
        double x__tip = this->getParent()->getTip().x() + L__ * cos(alpha);
        double y__tip = this->getParent()->getTip().y() + L__ * sin(alpha);

        double m = (this->getParent()->getTip().y()-this->getTip().y())/(this->getParent()->getTip().x()-this->getTip().x());
        double m_norm=-1/m;

        double dx=(sqrt( pow(L,2) / (1 + pow(m_norm,2)) ) / 2);
        double dy=m_norm * dx;
        this->vertex[0].x = x__tip-dx;
        this->vertex[0].y = y__tip-dy;

        this->vertex[1].x = x__tip+dx;
        this->vertex[1].y = y__tip+dy;

        this->vertex[2].x = x_tip+dx;
        this->vertex[2].y = y_tip+dy;

        this->vertex[3].x = x_tip-dx;
        this->vertex[3].y = y_tip-dy;
    }
    else{
        double dx=L*2;
        double dy=L*2;
        this->vertex[0].x = this->getTip().x()-dx;
        this->vertex[0].y = this->getTip().y()-dy;

        this->vertex[1].x = this->getTip().x()-dx;
        this->vertex[1].y = this->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()+dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }

    for (i = 0; i < 4; i++)
    {
        this->vertex[i].r = 0;
        this->vertex[i].g = 0;
        this->vertex[i].b = 1;
    }
}

void Bone_Collar::drawGraphic()
{
        if(debug) qDebug("Debug: '%d'", this->getID());

        glLineWidth(2.5);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);

        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        //MESH
        glBegin(GL_QUADS);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex2f(this->vertex[0].x, this->vertex[0].y);
                    glTexCoord2f(0.0f, 0.0f);


                    glVertex2f(this->vertex[1].x, this->vertex[1].y);
                    glTexCoord2f(0.0f, 1.0f);


                    glVertex2f(this->vertex[2].x, this->vertex[2].y);
                    glTexCoord2f(1.0f, 1.0f);

                    glVertex2f(this->vertex[3].x, this->vertex[3].y);



        glEnd();
        glDisable(GL_TEXTURE_2D);
//        glColor3f(0.0, 1.0, 0.0);
//        //BONES
//        glBegin(GL_LINES);
//        if(this->getParent()!=NULL){
//            glVertex2f(this->getTip().x(), this->getTip().y());
//            glVertex2f(this->getParent()->getTip().x(), this->getParent()->getTip().y());
//        }
//        glEnd();

//    GLfloat x1,x2,y1,y2;
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    if(this->getID()==CENTER){
//        x1=0;
//        y1=0;
//    }
//    else{
//        x1=this->getParent()->getTip().x();
//        y1=this->getParent()->getTip().y();
//    }


//    x2=this->getTip().x();
//    y2=this->getTip().y();
//    if(debug) qDebug("Debug: '%f %f %f %f'", x1,y1,x2,y2);
//    GLfloat triangle_vertices[] = {
//             x1, y1, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF(),
//             x2, y2, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF()

//     };
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glUseProgram(program);
//    glEnableVertexAttribArray(attribute_coord2d);
//    glEnableVertexAttribArray(attribute_v_color);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glVertexAttribPointer(
//        attribute_coord2d,   // attribute
//        2,                   // number of elements per vertex, here (x,y)
//        GL_FLOAT,            // the type of each element
//        GL_FALSE,            // take our values as-is
//        5 * sizeof(GLfloat), // next coord2d appears every 5 floats
//        0                    // offset of the first element
//    );
//    glVertexAttribPointer(
//        attribute_v_color,      // attribute
//        3,                      // number of elements per vertex, here (r,g,b)
//        GL_FLOAT,               // the type of each element
//        GL_FALSE,               // take our values as-is
//        5 * sizeof(GLfloat),    // next color appears every 5 floats
//        (GLvoid*) (2 * sizeof(GLfloat))  // offset of first element
//    );
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    /* Push each element in buffer_vertices to the vertex shader */
//    glDrawArrays(GL_LINE_LOOP, 0,2);
//    if(debug) qDebug("Debug: '%s'", "DRAWING LINE-------");
//    glDisableVertexAttribArray(attribute_coord2d);
//    glDisableVertexAttribArray(attribute_v_color);
}

//3
void Bone_Spine::loadTexture(){
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures("C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Body\\spine.png");
}

void Bone_Spine::createVertices(){
    int i;
    double L=0.3;
    double L_=0.1;
    if (!this)
        return;

    if(this->getParent()){
        double alpha = atan2(this->getParent()->getTip().y()-this->getTip().y(), this->getParent()->getTip().x()-this->getTip().x());

        double x_tip = this->getTip().x() - L_ * cos(alpha);
        double y_tip = this->getTip().y() - L_ * sin(alpha);


        double m = (this->getParent()->getTip().y()-this->getTip().y())/(this->getParent()->getTip().x()-this->getTip().x());
        double m_norm=-1/m;
        double dx=sqrt( pow(L,2) / (1 + pow(m_norm,2)) ) / 2;
        double dy=m_norm * dx;
        this->vertex[0].x = this->getParent()->getTip().x()-dx;
        this->vertex[0].y = this->getParent()->getTip().y()-dy;

        this->vertex[1].x = this->getParent()->getTip().x()+dx;
        this->vertex[1].y = this->getParent()->getTip().y()+dy;

        this->vertex[2].x = x_tip+dx;
        this->vertex[2].y = y_tip+dy;

        this->vertex[3].x = x_tip-dx;
        this->vertex[3].y = y_tip-dy;
    }
    else{
        double dx=L*2;
        double dy=L*2;
        this->vertex[0].x = this->getTip().x()-dx;
        this->vertex[0].y = this->getTip().y()-dy;

        this->vertex[1].x = this->getTip().x()-dx;
        this->vertex[1].y = this->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()+dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }

    for (i = 0; i < 4; i++)
    {
        this->vertex[i].r = 0;
        this->vertex[i].g = 0;
        this->vertex[i].b = 1;
    }
}

void Bone_Spine::drawGraphic()
{
        if(debug) qDebug("Debug: '%d'", this->getID());

        glLineWidth(2.5);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //MESH
        glBegin(GL_QUADS);
                     glTexCoord2f(1.0f, 0.0f);

                    glVertex2f(this->vertex[0].x, this->vertex[0].y);
                    glTexCoord2f(0.0f, 0.0f);

                    glVertex2f(this->vertex[1].x, this->vertex[1].y);
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex2f(this->vertex[2].x, this->vertex[2].y);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex2f(this->vertex[3].x, this->vertex[3].y);

        glEnd();
        glDisable(GL_TEXTURE_2D);
//        glColor3f(0.0, 1.0, 0.0);
//        //BONES
//        glBegin(GL_LINES);
//        if(this->getParent()!=NULL){
//            glVertex2f(this->getTip().x(), this->getTip().y());
//            glVertex2f(this->getParent()->getTip().x(), this->getParent()->getTip().y());
//        }
//        glEnd();

//    GLfloat x1,x2,y1,y2;
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    if(this->getID()==CENTER){
//        x1=0;
//        y1=0;
//    }
//    else{
//        x1=this->getParent()->getTip().x();
//        y1=this->getParent()->getTip().y();
//    }


//    x2=this->getTip().x();
//    y2=this->getTip().y();
//    if(debug) qDebug("Debug: '%f %f %f %f'", x1,y1,x2,y2);
//    GLfloat triangle_vertices[] = {
//             x1, y1, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF(),
//             x2, y2, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF()

//     };
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glUseProgram(program);
//    glEnableVertexAttribArray(attribute_coord2d);
//    glEnableVertexAttribArray(attribute_v_color);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glVertexAttribPointer(
//        attribute_coord2d,   // attribute
//        2,                   // number of elements per vertex, here (x,y)
//        GL_FLOAT,            // the type of each element
//        GL_FALSE,            // take our values as-is
//        5 * sizeof(GLfloat), // next coord2d appears every 5 floats
//        0                    // offset of the first element
//    );
//    glVertexAttribPointer(
//        attribute_v_color,      // attribute
//        3,                      // number of elements per vertex, here (r,g,b)
//        GL_FLOAT,               // the type of each element
//        GL_FALSE,               // take our values as-is
//        5 * sizeof(GLfloat),    // next color appears every 5 floats
//        (GLvoid*) (2 * sizeof(GLfloat))  // offset of first element
//    );
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    /* Push each element in buffer_vertices to the vertex shader */
//    glDrawArrays(GL_LINE_LOOP, 0,2);
//    if(debug) qDebug("Debug: '%s'", "DRAWING LINE-------");
//    glDisableVertexAttribArray(attribute_coord2d);
//    glDisableVertexAttribArray(attribute_v_color);
}

//4
void Bone_Shoulder_L::loadTexture(){
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures("C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Body\\leftshoulder.png");
}

void Bone_Shoulder_L::createVertices(){
    int i;
    double L=0.2;
    double L_=0.4;
    double L__=0.1;
    if (!this)
        return;

    if(this->getParent()){
        double alpha = atan2(this->getParent()->getTip().y()-this->getTip().y(), this->getParent()->getTip().x()-this->getTip().x());

        double x_tip = this->getTip().x() - L_ * cos(alpha);
        double y_tip = this->getTip().y() - L_ * sin(alpha);
        double x__tip = this->getParent()->getTip().x() - L__ * cos(alpha);
        double y__tip = this->getParent()->getTip().y() - L__ * sin(alpha);

        double m = (this->getParent()->getTip().y()-this->getTip().y())/(this->getParent()->getTip().x()-this->getTip().x());
        double m_norm=-1/m;

        double dx=(sqrt( pow(L,2) / (1 + pow(m_norm,2)) ) / 2);
        double dy=m_norm * dx;
        this->vertex[0].x = x__tip-dx;
        this->vertex[0].y = y__tip-dy;

        this->vertex[1].x = x__tip+dx;
        this->vertex[1].y = y__tip+dy;

        this->vertex[2].x = x_tip+dx;
        this->vertex[2].y = y_tip+dy;

        this->vertex[3].x = x_tip-dx;
        this->vertex[3].y = y_tip-dy;
    }
    else{
        double dx=L*2;
        double dy=L*2;
        this->vertex[0].x = this->getTip().x()-dx;
        this->vertex[0].y = this->getTip().y()-dy;

        this->vertex[1].x = this->getTip().x()-dx;
        this->vertex[1].y = this->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()+dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }

    for (i = 0; i < 4; i++)
    {
        this->vertex[i].r = 0;
        this->vertex[i].g = 0;
        this->vertex[i].b = 1;
    }
}

void Bone_Shoulder_L::drawGraphic()
{
        if(debug) qDebug("Debug: '%d'", this->getID());

        glLineWidth(2.5);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //MESH
        glBegin(GL_QUADS);
                    glTexCoord2f(1.0f, 0.0f);

                    glVertex2f(this->vertex[0].x, this->vertex[0].y);
                    glTexCoord2f(0.0f, 0.0f);

                    glVertex2f(this->vertex[1].x, this->vertex[1].y);
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex2f(this->vertex[2].x, this->vertex[2].y);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex2f(this->vertex[3].x, this->vertex[3].y);

        glEnd();
        glDisable(GL_TEXTURE_2D);
//        glColor3f(0.0, 1.0, 0.0);
//        //BONES
//        glBegin(GL_LINES);
//        if(this->getParent()!=NULL){
//            glVertex2f(this->getTip().x(), this->getTip().y());
//            glVertex2f(this->getParent()->getTip().x(), this->getParent()->getTip().y());
//        }
//        glEnd();

//    GLfloat x1,x2,y1,y2;
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    if(this->getID()==CENTER){
//        x1=0;
//        y1=0;
//    }
//    else{
//        x1=this->getParent()->getTip().x();
//        y1=this->getParent()->getTip().y();
//    }


//    x2=this->getTip().x();
//    y2=this->getTip().y();
//    if(debug) qDebug("Debug: '%f %f %f %f'", x1,y1,x2,y2);
//    GLfloat triangle_vertices[] = {
//             x1, y1, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF(),
//             x2, y2, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF()

//     };
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glUseProgram(program);
//    glEnableVertexAttribArray(attribute_coord2d);
//    glEnableVertexAttribArray(attribute_v_color);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glVertexAttribPointer(
//        attribute_coord2d,   // attribute
//        2,                   // number of elements per vertex, here (x,y)
//        GL_FLOAT,            // the type of each element
//        GL_FALSE,            // take our values as-is
//        5 * sizeof(GLfloat), // next coord2d appears every 5 floats
//        0                    // offset of the first element
//    );
//    glVertexAttribPointer(
//        attribute_v_color,      // attribute
//        3,                      // number of elements per vertex, here (r,g,b)
//        GL_FLOAT,               // the type of each element
//        GL_FALSE,               // take our values as-is
//        5 * sizeof(GLfloat),    // next color appears every 5 floats
//        (GLvoid*) (2 * sizeof(GLfloat))  // offset of first element
//    );
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    /* Push each element in buffer_vertices to the vertex shader */
//    glDrawArrays(GL_LINE_LOOP, 0,2);
//    if(debug) qDebug("Debug: '%s'", "DRAWING LINE-------");
//    glDisableVertexAttribArray(attribute_coord2d);
//    glDisableVertexAttribArray(attribute_v_color);
}

//5
void Bone_Shoulder_R::loadTexture(){
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures("C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Body\\rightshoulder.png");
}

void Bone_Shoulder_R::createVertices(){
    int i;
    double L=0.2;
    double L_=0.4;
    double L__=0.1;
    if (!this)
        return;

    if(this->getParent()){
        double alpha = atan2(this->getParent()->getTip().y()-this->getTip().y(), this->getParent()->getTip().x()-this->getTip().x());

        double x_tip = this->getTip().x() - L_ * cos(alpha);
        double y_tip = this->getTip().y() - L_ * sin(alpha);
        double x__tip = this->getParent()->getTip().x() - L__ * cos(alpha);
        double y__tip = this->getParent()->getTip().y() - L__ * sin(alpha);

        double m = (this->getParent()->getTip().y()-this->getTip().y())/(this->getParent()->getTip().x()-this->getTip().x());
        double m_norm=-1/m;

        double dx=(sqrt( pow(L,2) / (1 + pow(m_norm,2)) ) / 2);
        double dy=m_norm * dx;
        this->vertex[0].x = x__tip-dx;
        this->vertex[0].y = y__tip-dy;

        this->vertex[1].x = x__tip+dx;
        this->vertex[1].y = y__tip+dy;

        this->vertex[2].x = x_tip+dx;
        this->vertex[2].y = y_tip+dy;

        this->vertex[3].x = x_tip-dx;
        this->vertex[3].y = y_tip-dy;
    }
    else{
        double dx=L*2;
        double dy=L*2;
        this->vertex[0].x = this->getTip().x()-dx;
        this->vertex[0].y = this->getTip().y()-dy;

        this->vertex[1].x = this->getTip().x()-dx;
        this->vertex[1].y = this->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()+dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }

    for (i = 0; i < 4; i++)
    {
        this->vertex[i].r = 0;
        this->vertex[i].g = 0;
        this->vertex[i].b = 1;
    }
}

void Bone_Shoulder_R::drawGraphic()
{
        if(debug) qDebug("Debug: '%d'", this->getID());

        glLineWidth(2.5);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //MESH
        glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 0.0f);

        glVertex2f(this->vertex[0].x, this->vertex[0].y);
        glTexCoord2f(0.0f, 0.0f);

        glVertex2f(this->vertex[1].x, this->vertex[1].y);
        glTexCoord2f(0.0f, 1.0f);
        glVertex2f(this->vertex[2].x, this->vertex[2].y);
        glTexCoord2f(1.0f, 1.0f);
        glVertex2f(this->vertex[3].x, this->vertex[3].y);

        glEnd();
        glDisable(GL_TEXTURE_2D);
//        glColor3f(0.0, 1.0, 0.0);
//        //BONES
//        glBegin(GL_LINES);
//        if(this->getParent()!=NULL){
//            glVertex2f(this->getTip().x(), this->getTip().y());
//            glVertex2f(this->getParent()->getTip().x(), this->getParent()->getTip().y());
//        }
//        glEnd();

//    GLfloat x1,x2,y1,y2;
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    if(this->getID()==CENTER){
//        x1=0;
//        y1=0;
//    }
//    else{
//        x1=this->getParent()->getTip().x();
//        y1=this->getParent()->getTip().y();
//    }


//    x2=this->getTip().x();
//    y2=this->getTip().y();
//    if(debug) qDebug("Debug: '%f %f %f %f'", x1,y1,x2,y2);
//    GLfloat triangle_vertices[] = {
//             x1, y1, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF(),
//             x2, y2, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF()

//     };
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glUseProgram(program);
//    glEnableVertexAttribArray(attribute_coord2d);
//    glEnableVertexAttribArray(attribute_v_color);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glVertexAttribPointer(
//        attribute_coord2d,   // attribute
//        2,                   // number of elements per vertex, here (x,y)
//        GL_FLOAT,            // the type of each element
//        GL_FALSE,            // take our values as-is
//        5 * sizeof(GLfloat), // next coord2d appears every 5 floats
//        0                    // offset of the first element
//    );
//    glVertexAttribPointer(
//        attribute_v_color,      // attribute
//        3,                      // number of elements per vertex, here (r,g,b)
//        GL_FLOAT,               // the type of each element
//        GL_FALSE,               // take our values as-is
//        5 * sizeof(GLfloat),    // next color appears every 5 floats
//        (GLvoid*) (2 * sizeof(GLfloat))  // offset of first element
//    );
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    /* Push each element in buffer_vertices to the vertex shader */
//    glDrawArrays(GL_LINE_LOOP, 0,2);
//    if(debug) qDebug("Debug: '%s'", "DRAWING LINE-------");
//    glDisableVertexAttribArray(attribute_coord2d);
//    glDisableVertexAttribArray(attribute_v_color);
}

//6
void Bone_Elbow_L::loadTexture(){
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures("C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Body\\rightelbow.png");
}

void Bone_Elbow_L::createVertices(){
    int i;
    double L=0.2;
    double L_=0.1;
    if (!this)
        return;

    if(this->getParent()){
        double alpha = atan2(this->getParent()->getTip().y()-this->getTip().y(), this->getParent()->getTip().x()-this->getTip().x());

        double x_tip = this->getTip().x() - L_ * cos(alpha);
        double y_tip = this->getTip().y() - L_ * sin(alpha);


        double m = (this->getParent()->getTip().y()-this->getTip().y())/(this->getParent()->getTip().x()-this->getTip().x());
        double m_norm=-1/m;
        double dx=sqrt( pow(L,2) / (1 + pow(m_norm,2)) ) / 2;
        double dy=m_norm * dx;
        this->vertex[0].x = this->getParent()->getTip().x()-dx;
        this->vertex[0].y = this->getParent()->getTip().y()-dy;

        this->vertex[1].x = this->getParent()->getTip().x()+dx;
        this->vertex[1].y = this->getParent()->getTip().y()+dy;

        this->vertex[2].x = x_tip+dx;
        this->vertex[2].y = y_tip+dy;

        this->vertex[3].x = x_tip-dx;
        this->vertex[3].y = y_tip-dy;
    }
    else{
        double dx=L*2;
        double dy=L*2;
        this->vertex[0].x = this->getTip().x()-dx;
        this->vertex[0].y = this->getTip().y()-dy;

        this->vertex[1].x = this->getTip().x()-dx;
        this->vertex[1].y = this->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()+dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }

    for (i = 0; i < 4; i++)
    {
        this->vertex[i].r = 0;
        this->vertex[i].g = 0;
        this->vertex[i].b = 1;
    }
}

void Bone_Elbow_L::drawGraphic()
{
        if(debug) qDebug("Debug: '%d'", this->getID());

        glLineWidth(2.5);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //MESH
        glBegin(GL_QUADS);
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex2f(this->vertex[0].x, this->vertex[0].y);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex2f(this->vertex[1].x, this->vertex[1].y);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex2f(this->vertex[2].x, this->vertex[2].y);
                    glTexCoord2f(0.0f, 0.0f);
                    glVertex2f(this->vertex[3].x, this->vertex[3].y);

        glEnd();
        glDisable(GL_TEXTURE_2D);
//        glColor3f(0.0, 1.0, 0.0);
//        //BONES
//        glBegin(GL_LINES);
//        if(this->getParent()!=NULL){
//            glVertex2f(this->getTip().x(), this->getTip().y());
//            glVertex2f(this->getParent()->getTip().x(), this->getParent()->getTip().y());
//        }
//        glEnd();

//    GLfloat x1,x2,y1,y2;
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    if(this->getID()==CENTER){
//        x1=0;
//        y1=0;
//    }
//    else{
//        x1=this->getParent()->getTip().x();
//        y1=this->getParent()->getTip().y();
//    }


//    x2=this->getTip().x();
//    y2=this->getTip().y();
//    if(debug) qDebug("Debug: '%f %f %f %f'", x1,y1,x2,y2);
//    GLfloat triangle_vertices[] = {
//             x1, y1, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF(),
//             x2, y2, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF()

//     };
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glUseProgram(program);
//    glEnableVertexAttribArray(attribute_coord2d);
//    glEnableVertexAttribArray(attribute_v_color);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glVertexAttribPointer(
//        attribute_coord2d,   // attribute
//        2,                   // number of elements per vertex, here (x,y)
//        GL_FLOAT,            // the type of each element
//        GL_FALSE,            // take our values as-is
//        5 * sizeof(GLfloat), // next coord2d appears every 5 floats
//        0                    // offset of the first element
//    );
//    glVertexAttribPointer(
//        attribute_v_color,      // attribute
//        3,                      // number of elements per vertex, here (r,g,b)
//        GL_FLOAT,               // the type of each element
//        GL_FALSE,               // take our values as-is
//        5 * sizeof(GLfloat),    // next color appears every 5 floats
//        (GLvoid*) (2 * sizeof(GLfloat))  // offset of first element
//    );
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    /* Push each element in buffer_vertices to the vertex shader */
//    glDrawArrays(GL_LINE_LOOP, 0,2);
//    if(debug) qDebug("Debug: '%s'", "DRAWING LINE-------");
//    glDisableVertexAttribArray(attribute_coord2d);
//    glDisableVertexAttribArray(attribute_v_color);
}

//7
void Bone_Elbow_R::loadTexture(){
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures("C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Body\\leftelbow.png");
}

void Bone_Elbow_R::createVertices(){
    int i;
    double L=0.2;
    double L_=0.1;
    if (!this)
        return;

    if(this->getParent()){
        double alpha = atan2(this->getParent()->getTip().y()-this->getTip().y(), this->getParent()->getTip().x()-this->getTip().x());

        double x_tip = this->getTip().x() - L_ * cos(alpha);
        double y_tip = this->getTip().y() - L_ * sin(alpha);


        double m = (this->getParent()->getTip().y()-this->getTip().y())/(this->getParent()->getTip().x()-this->getTip().x());
        double m_norm=-1/m;
        double dx=sqrt( pow(L,2) / (1 + pow(m_norm,2)) ) / 2;
        double dy=m_norm * dx;
        this->vertex[0].x = this->getParent()->getTip().x()-dx;
        this->vertex[0].y = this->getParent()->getTip().y()-dy;

        this->vertex[1].x = this->getParent()->getTip().x()+dx;
        this->vertex[1].y = this->getParent()->getTip().y()+dy;

        this->vertex[2].x = x_tip+dx;
        this->vertex[2].y = y_tip+dy;

        this->vertex[3].x = x_tip-dx;
        this->vertex[3].y = y_tip-dy;
    }
    else{
        double dx=L*2;
        double dy=L*2;
        this->vertex[0].x = this->getTip().x()-dx;
        this->vertex[0].y = this->getTip().y()-dy;

        this->vertex[1].x = this->getTip().x()-dx;
        this->vertex[1].y = this->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()+dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }

    for (i = 0; i < 4; i++)
    {
        this->vertex[i].r = 0;
        this->vertex[i].g = 0;
        this->vertex[i].b = 1;
    }
}

void Bone_Elbow_R::drawGraphic()
{
        if(debug) qDebug("Debug: '%d'", this->getID());

        glLineWidth(2.5);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //MESH
        glBegin(GL_QUADS);
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex2f(this->vertex[0].x, this->vertex[0].y);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex2f(this->vertex[1].x, this->vertex[1].y);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex2f(this->vertex[2].x, this->vertex[2].y);
                    glTexCoord2f(0.0f, 0.0f);
                    glVertex2f(this->vertex[3].x, this->vertex[3].y);

        glEnd();
        glDisable(GL_TEXTURE_2D);
//        glColor3f(0.0, 1.0, 0.0);
//        //BONES
//        glBegin(GL_LINES);
//        if(this->getParent()!=NULL){
//            glVertex2f(this->getTip().x(), this->getTip().y());
//            glVertex2f(this->getParent()->getTip().x(), this->getParent()->getTip().y());
//        }
//        glEnd();

//    GLfloat x1,x2,y1,y2;
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    if(this->getID()==CENTER){
//        x1=0;
//        y1=0;
//    }
//    else{
//        x1=this->getParent()->getTip().x();
//        y1=this->getParent()->getTip().y();
//    }


//    x2=this->getTip().x();
//    y2=this->getTip().y();
//    if(debug) qDebug("Debug: '%f %f %f %f'", x1,y1,x2,y2);
//    GLfloat triangle_vertices[] = {
//             x1, y1, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF(),
//             x2, y2, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF()

//     };
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glUseProgram(program);
//    glEnableVertexAttribArray(attribute_coord2d);
//    glEnableVertexAttribArray(attribute_v_color);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glVertexAttribPointer(
//        attribute_coord2d,   // attribute
//        2,                   // number of elements per vertex, here (x,y)
//        GL_FLOAT,            // the type of each element
//        GL_FALSE,            // take our values as-is
//        5 * sizeof(GLfloat), // next coord2d appears every 5 floats
//        0                    // offset of the first element
//    );
//    glVertexAttribPointer(
//        attribute_v_color,      // attribute
//        3,                      // number of elements per vertex, here (r,g,b)
//        GL_FLOAT,               // the type of each element
//        GL_FALSE,               // take our values as-is
//        5 * sizeof(GLfloat),    // next color appears every 5 floats
//        (GLvoid*) (2 * sizeof(GLfloat))  // offset of first element
//    );
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    /* Push each element in buffer_vertices to the vertex shader */
//    glDrawArrays(GL_LINE_LOOP, 0,2);
//    if(debug) qDebug("Debug: '%s'", "DRAWING LINE-------");
//    glDisableVertexAttribArray(attribute_coord2d);
//    glDisableVertexAttribArray(attribute_v_color);
}

//8
void Bone_Hand_L::loadTexture(){
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures("C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Body\\lefthand.png");
}

void Bone_Hand_L::createVertices(){
    int i;
    double L=0.2;
    if (!this)
        return;

    if(this->getParent()){
        double m = (this->getParent()->getTip().y()-this->getTip().y())/(this->getParent()->getTip().x()-this->getTip().x());
        double m_norm=-1/m;
        double dx=sqrt( pow(L,2) / (1 + pow(m_norm,2)) ) / 2;
        double dy=m_norm * dx;
        this->vertex[0].x = this->getParent()->getTip().x()-dx;
        this->vertex[0].y = this->getParent()->getTip().y()-dy;

        this->vertex[1].x = this->getParent()->getTip().x()+dx;
        this->vertex[1].y = this->getParent()->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()-dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }
    else{
        double dx=L*2;
        double dy=L*2;
        this->vertex[0].x = this->getTip().x()-dx;
        this->vertex[0].y = this->getTip().y()-dy;

        this->vertex[1].x = this->getTip().x()-dx;
        this->vertex[1].y = this->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()+dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }

    for (i = 0; i < 4; i++)
    {
        this->vertex[i].r = 0;
        this->vertex[i].g = 0;
        this->vertex[i].b = 1;
    }
}

void Bone_Hand_L::drawGraphic()
{
        if(debug) qDebug("Debug: '%d'", this->getID());

        glLineWidth(2.5);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //MESH
        glBegin(GL_QUADS);
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex2f(this->vertex[0].x, this->vertex[0].y);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex2f(this->vertex[1].x, this->vertex[1].y);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex2f(this->vertex[2].x, this->vertex[2].y);
                    glTexCoord2f(0.0f, 0.0f);
                    glVertex2f(this->vertex[3].x, this->vertex[3].y);

        glEnd();
        glDisable(GL_TEXTURE_2D);
//        glColor3f(0.0, 1.0, 0.0);
//        //BONES
//        glBegin(GL_LINES);
//        if(this->getParent()!=NULL){
//            glVertex2f(this->getTip().x(), this->getTip().y());
//            glVertex2f(this->getParent()->getTip().x(), this->getParent()->getTip().y());
//        }
//        glEnd();

//    GLfloat x1,x2,y1,y2;
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    if(this->getID()==CENTER){
//        x1=0;
//        y1=0;
//    }
//    else{
//        x1=this->getParent()->getTip().x();
//        y1=this->getParent()->getTip().y();
//    }


//    x2=this->getTip().x();
//    y2=this->getTip().y();
//    if(debug) qDebug("Debug: '%f %f %f %f'", x1,y1,x2,y2);
//    GLfloat triangle_vertices[] = {
//             x1, y1, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF(),
//             x2, y2, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF()

//     };
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glUseProgram(program);
//    glEnableVertexAttribArray(attribute_coord2d);
//    glEnableVertexAttribArray(attribute_v_color);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glVertexAttribPointer(
//        attribute_coord2d,   // attribute
//        2,                   // number of elements per vertex, here (x,y)
//        GL_FLOAT,            // the type of each element
//        GL_FALSE,            // take our values as-is
//        5 * sizeof(GLfloat), // next coord2d appears every 5 floats
//        0                    // offset of the first element
//    );
//    glVertexAttribPointer(
//        attribute_v_color,      // attribute
//        3,                      // number of elements per vertex, here (r,g,b)
//        GL_FLOAT,               // the type of each element
//        GL_FALSE,               // take our values as-is
//        5 * sizeof(GLfloat),    // next color appears every 5 floats
//        (GLvoid*) (2 * sizeof(GLfloat))  // offset of first element
//    );
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    /* Push each element in buffer_vertices to the vertex shader */
//    glDrawArrays(GL_LINE_LOOP, 0,2);
//    if(debug) qDebug("Debug: '%s'", "DRAWING LINE-------");
//    glDisableVertexAttribArray(attribute_coord2d);
//    glDisableVertexAttribArray(attribute_v_color);
}

//9
void Bone_Hand_R::loadTexture(){
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures("C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Body\\righthand.png");
}

void Bone_Hand_R::createVertices(){
    int i;
    double L=0.2;
    if (!this)
        return;

    if(this->getParent()){
        double m = (this->getParent()->getTip().y()-this->getTip().y())/(this->getParent()->getTip().x()-this->getTip().x());
        double m_norm=-1/m;
        double dx=sqrt( pow(L,2) / (1 + pow(m_norm,2)) ) / 2;
        double dy=m_norm * dx;
        this->vertex[0].x = this->getParent()->getTip().x()-dx;
        this->vertex[0].y = this->getParent()->getTip().y()-dy;

        this->vertex[1].x = this->getParent()->getTip().x()+dx;
        this->vertex[1].y = this->getParent()->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()-dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }
    else{
        double dx=L*2;
        double dy=L*2;
        this->vertex[0].x = this->getTip().x()-dx;
        this->vertex[0].y = this->getTip().y()-dy;

        this->vertex[1].x = this->getTip().x()-dx;
        this->vertex[1].y = this->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()+dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }

    for (i = 0; i < 4; i++)
    {
        this->vertex[i].r = 0;
        this->vertex[i].g = 0;
        this->vertex[i].b = 1;
    }
}

void Bone_Hand_R::drawGraphic()
{
        if(debug) qDebug("Debug: '%d'", this->getID());

        glLineWidth(2.5);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //MESH
        glBegin(GL_QUADS);
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex2f(this->vertex[0].x, this->vertex[0].y);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex2f(this->vertex[1].x, this->vertex[1].y);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex2f(this->vertex[2].x, this->vertex[2].y);
                    glTexCoord2f(0.0f, 0.0f);
                    glVertex2f(this->vertex[3].x, this->vertex[3].y);

        glEnd();
        glDisable(GL_TEXTURE_2D);
//        glColor3f(0.0, 1.0, 0.0);
//        //BONES
//        glBegin(GL_LINES);
//        if(this->getParent()!=NULL){
//            glVertex2f(this->getTip().x(), this->getTip().y());
//            glVertex2f(this->getParent()->getTip().x(), this->getParent()->getTip().y());
//        }
//        glEnd();

//    GLfloat x1,x2,y1,y2;
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    if(this->getID()==CENTER){
//        x1=0;
//        y1=0;
//    }
//    else{
//        x1=this->getParent()->getTip().x();
//        y1=this->getParent()->getTip().y();
//    }


//    x2=this->getTip().x();
//    y2=this->getTip().y();
//    if(debug) qDebug("Debug: '%f %f %f %f'", x1,y1,x2,y2);
//    GLfloat triangle_vertices[] = {
//             x1, y1, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF(),
//             x2, y2, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF()

//     };
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glUseProgram(program);
//    glEnableVertexAttribArray(attribute_coord2d);
//    glEnableVertexAttribArray(attribute_v_color);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glVertexAttribPointer(
//        attribute_coord2d,   // attribute
//        2,                   // number of elements per vertex, here (x,y)
//        GL_FLOAT,            // the type of each element
//        GL_FALSE,            // take our values as-is
//        5 * sizeof(GLfloat), // next coord2d appears every 5 floats
//        0                    // offset of the first element
//    );
//    glVertexAttribPointer(
//        attribute_v_color,      // attribute
//        3,                      // number of elements per vertex, here (r,g,b)
//        GL_FLOAT,               // the type of each element
//        GL_FALSE,               // take our values as-is
//        5 * sizeof(GLfloat),    // next color appears every 5 floats
//        (GLvoid*) (2 * sizeof(GLfloat))  // offset of first element
//    );
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    /* Push each element in buffer_vertices to the vertex shader */
//    glDrawArrays(GL_LINE_LOOP, 0,2);
//    if(debug) qDebug("Debug: '%s'", "DRAWING LINE-------");
//    glDisableVertexAttribArray(attribute_coord2d);
//    glDisableVertexAttribArray(attribute_v_color);
}

//10
void Bone_Wrist_L::loadTexture(){
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures("C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Body\\leftwrist.png");
}

void Bone_Wrist_L::createVertices(){
    int i;
    double L=0.3;
    if (!this)
        return;

    if(this->getParent()){
        double m = (this->getParent()->getTip().y()-this->getTip().y())/(this->getParent()->getTip().x()-this->getTip().x());
        double m_norm=-1/m;
        double dx=sqrt( pow(L,2) / (1 + pow(m_norm,2)) ) / 2;
        double dy=m_norm * dx;
        this->vertex[0].x = this->getParent()->getTip().x()-dx;
        this->vertex[0].y = this->getParent()->getTip().y()-dy;

        this->vertex[1].x = this->getParent()->getTip().x()+dx;
        this->vertex[1].y = this->getParent()->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()-dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }
    else{
        double dx=L*2;
        double dy=L*2;
        this->vertex[0].x = this->getTip().x()-dx;
        this->vertex[0].y = this->getTip().y()-dy;

        this->vertex[1].x = this->getTip().x()-dx;
        this->vertex[1].y = this->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()+dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }

    for (i = 0; i < 4; i++)
    {
        this->vertex[i].r = 0;
        this->vertex[i].g = 0;
        this->vertex[i].b = 1;
    }
}

void Bone_Wrist_L::drawGraphic()
{
        if(debug) qDebug("Debug: '%d'", this->getID());

        glLineWidth(2.5);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //MESH
        glBegin(GL_QUADS);
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex2f(this->vertex[0].x, this->vertex[0].y);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex2f(this->vertex[1].x, this->vertex[1].y);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex2f(this->vertex[2].x, this->vertex[2].y);
                    glTexCoord2f(0.0f, 0.0f);
                    glVertex2f(this->vertex[3].x, this->vertex[3].y);

        glEnd();
        glDisable(GL_TEXTURE_2D);
//        glColor3f(0.0, 1.0, 0.0);
//        //BONES
//        glBegin(GL_LINES);
//        if(this->getParent()!=NULL){
//            glVertex2f(this->getTip().x(), this->getTip().y());
//            glVertex2f(this->getParent()->getTip().x(), this->getParent()->getTip().y());
//        }
//        glEnd();

//    GLfloat x1,x2,y1,y2;
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    if(this->getID()==CENTER){
//        x1=0;
//        y1=0;
//    }
//    else{
//        x1=this->getParent()->getTip().x();
//        y1=this->getParent()->getTip().y();
//    }


//    x2=this->getTip().x();
//    y2=this->getTip().y();
//    if(debug) qDebug("Debug: '%f %f %f %f'", x1,y1,x2,y2);
//    GLfloat triangle_vertices[] = {
//             x1, y1, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF(),
//             x2, y2, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF()

//     };
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glUseProgram(program);
//    glEnableVertexAttribArray(attribute_coord2d);
//    glEnableVertexAttribArray(attribute_v_color);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glVertexAttribPointer(
//        attribute_coord2d,   // attribute
//        2,                   // number of elements per vertex, here (x,y)
//        GL_FLOAT,            // the type of each element
//        GL_FALSE,            // take our values as-is
//        5 * sizeof(GLfloat), // next coord2d appears every 5 floats
//        0                    // offset of the first element
//    );
//    glVertexAttribPointer(
//        attribute_v_color,      // attribute
//        3,                      // number of elements per vertex, here (r,g,b)
//        GL_FLOAT,               // the type of each element
//        GL_FALSE,               // take our values as-is
//        5 * sizeof(GLfloat),    // next color appears every 5 floats
//        (GLvoid*) (2 * sizeof(GLfloat))  // offset of first element
//    );
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    /* Push each element in buffer_vertices to the vertex shader */
//    glDrawArrays(GL_LINE_LOOP, 0,2);
//    if(debug) qDebug("Debug: '%s'", "DRAWING LINE-------");
//    glDisableVertexAttribArray(attribute_coord2d);
//    glDisableVertexAttribArray(attribute_v_color);
}

//11
void Bone_Wrist_R::loadTexture(){
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures("C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Body\\rightwrist.png");
}

void Bone_Wrist_R::createVertices(){
    int i;
    double L=0.3;
    double L_=0.01;
    if (!this)
        return;

    if(this->getParent()){
        double alpha = atan2(this->getParent()->getTip().y()-this->getTip().y(), this->getParent()->getTip().x()-this->getTip().x());

        double x_tip = this->getTip().x() - L_ * cos(alpha);
        double y_tip = this->getTip().y() - L_ * sin(alpha);


        double m = (this->getParent()->getTip().y()-this->getTip().y())/(this->getParent()->getTip().x()-this->getTip().x());
        double m_norm=-1/m;
        double dx=sqrt( pow(L,2) / (1 + pow(m_norm,2)) ) / 2;
        double dy=m_norm * dx;
        this->vertex[0].x = this->getParent()->getTip().x()-dx;
        this->vertex[0].y = this->getParent()->getTip().y()-dy;

        this->vertex[1].x = this->getParent()->getTip().x()+dx;
        this->vertex[1].y = this->getParent()->getTip().y()+dy;

        this->vertex[2].x = x_tip+dx;
        this->vertex[2].y = y_tip+dy;

        this->vertex[3].x = x_tip-dx;
        this->vertex[3].y = y_tip-dy;
    }
    else{
        double dx=L*2;
        double dy=L*2;
        this->vertex[0].x = this->getTip().x()-dx;
        this->vertex[0].y = this->getTip().y()-dy;

        this->vertex[1].x = this->getTip().x()-dx;
        this->vertex[1].y = this->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()+dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }

    for (i = 0; i < 4; i++)
    {
        this->vertex[i].r = 0;
        this->vertex[i].g = 0;
        this->vertex[i].b = 1;
    }
}

void Bone_Wrist_R::drawGraphic()
{
        if(debug) qDebug("Debug: '%d'", this->getID());

        glLineWidth(2.5);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //MESH
        glBegin(GL_QUADS);
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex2f(this->vertex[0].x, this->vertex[0].y);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex2f(this->vertex[1].x, this->vertex[1].y);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex2f(this->vertex[2].x, this->vertex[2].y);
                    glTexCoord2f(0.0f, 0.0f);
                    glVertex2f(this->vertex[3].x, this->vertex[3].y);

        glEnd();
        glDisable(GL_TEXTURE_2D);
//        glColor3f(0.0, 1.0, 0.0);
//        //BONES
//        glBegin(GL_LINES);
//        if(this->getParent()!=NULL){
//            glVertex2f(this->getTip().x(), this->getTip().y());
//            glVertex2f(this->getParent()->getTip().x(), this->getParent()->getTip().y());
//        }
//        glEnd();

//    GLfloat x1,x2,y1,y2;
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    if(this->getID()==CENTER){
//        x1=0;
//        y1=0;
//    }
//    else{
//        x1=this->getParent()->getTip().x();
//        y1=this->getParent()->getTip().y();
//    }


//    x2=this->getTip().x();
//    y2=this->getTip().y();
//    if(debug) qDebug("Debug: '%f %f %f %f'", x1,y1,x2,y2);
//    GLfloat triangle_vertices[] = {
//             x1, y1, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF(),
//             x2, y2, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF()

//     };
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glUseProgram(program);
//    glEnableVertexAttribArray(attribute_coord2d);
//    glEnableVertexAttribArray(attribute_v_color);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glVertexAttribPointer(
//        attribute_coord2d,   // attribute
//        2,                   // number of elements per vertex, here (x,y)
//        GL_FLOAT,            // the type of each element
//        GL_FALSE,            // take our values as-is
//        5 * sizeof(GLfloat), // next coord2d appears every 5 floats
//        0                    // offset of the first element
//    );
//    glVertexAttribPointer(
//        attribute_v_color,      // attribute
//        3,                      // number of elements per vertex, here (r,g,b)
//        GL_FLOAT,               // the type of each element
//        GL_FALSE,               // take our values as-is
//        5 * sizeof(GLfloat),    // next color appears every 5 floats
//        (GLvoid*) (2 * sizeof(GLfloat))  // offset of first element
//    );
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    /* Push each element in buffer_vertices to the vertex shader */
//    glDrawArrays(GL_LINE_LOOP, 0,2);
//    if(debug) qDebug("Debug: '%s'", "DRAWING LINE-------");
//    glDisableVertexAttribArray(attribute_coord2d);
//    glDisableVertexAttribArray(attribute_v_color);
}

//12
void Bone_Hip_L::loadTexture(){
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures("C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Body\\lefthip.png");
}

void Bone_Hip_L::createVertices(){
    int i;
    double L=0.2;
    double L_=0.1;
    if (!this)
        return;

    if(this->getParent()){
        double alpha = atan2(this->getParent()->getTip().y()-this->getTip().y(), this->getParent()->getTip().x()-this->getTip().x());

        double x_tip = this->getTip().x() - L_ * cos(alpha);
        double y_tip = this->getTip().y() - L_ * sin(alpha);


        double m = (this->getParent()->getTip().y()-this->getTip().y())/(this->getParent()->getTip().x()-this->getTip().x());
        double m_norm=-1/m;
        double dx=sqrt( pow(L,2) / (1 + pow(m_norm,2)) ) / 2;
        double dy=m_norm * dx;
        this->vertex[0].x = this->getParent()->getTip().x()-dx;
        this->vertex[0].y = this->getParent()->getTip().y()-dy;

        this->vertex[1].x = this->getParent()->getTip().x()+dx;
        this->vertex[1].y = this->getParent()->getTip().y()+dy;

        this->vertex[2].x = x_tip+dx;
        this->vertex[2].y = y_tip+dy;

        this->vertex[3].x = x_tip-dx;
        this->vertex[3].y = y_tip-dy;
    }
    else{
        double dx=L*2;
        double dy=L*2;
        this->vertex[0].x = this->getTip().x()-dx;
        this->vertex[0].y = this->getTip().y()-dy;

        this->vertex[1].x = this->getTip().x()-dx;
        this->vertex[1].y = this->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()+dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }

    for (i = 0; i < 4; i++)
    {
        this->vertex[i].r = 0;
        this->vertex[i].g = 0;
        this->vertex[i].b = 1;
    }
}

void Bone_Hip_L::drawGraphic()
{
        if(debug) qDebug("Debug: '%d'", this->getID());

        glLineWidth(2.5);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //MESH
        glBegin(GL_QUADS);
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex2f(this->vertex[0].x, this->vertex[0].y);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex2f(this->vertex[1].x, this->vertex[1].y);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex2f(this->vertex[2].x, this->vertex[2].y);
                    glTexCoord2f(0.0f, 0.0f);
                    glVertex2f(this->vertex[3].x, this->vertex[3].y);

        glEnd();
        glDisable(GL_TEXTURE_2D);
//        glColor3f(0.0, 1.0, 0.0);
//        //BONES
//        glBegin(GL_LINES);
//        if(this->getParent()!=NULL){
//            glVertex2f(this->getTip().x(), this->getTip().y());
//            glVertex2f(this->getParent()->getTip().x(), this->getParent()->getTip().y());
//        }
//        glEnd();

//    GLfloat x1,x2,y1,y2;
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    if(this->getID()==CENTER){
//        x1=0;
//        y1=0;
//    }
//    else{
//        x1=this->getParent()->getTip().x();
//        y1=this->getParent()->getTip().y();
//    }


//    x2=this->getTip().x();
//    y2=this->getTip().y();
//    if(debug) qDebug("Debug: '%f %f %f %f'", x1,y1,x2,y2);
//    GLfloat triangle_vertices[] = {
//             x1, y1, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF(),
//             x2, y2, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF()

//     };
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glUseProgram(program);
//    glEnableVertexAttribArray(attribute_coord2d);
//    glEnableVertexAttribArray(attribute_v_color);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glVertexAttribPointer(
//        attribute_coord2d,   // attribute
//        2,                   // number of elements per vertex, here (x,y)
//        GL_FLOAT,            // the type of each element
//        GL_FALSE,            // take our values as-is
//        5 * sizeof(GLfloat), // next coord2d appears every 5 floats
//        0                    // offset of the first element
//    );
//    glVertexAttribPointer(
//        attribute_v_color,      // attribute
//        3,                      // number of elements per vertex, here (r,g,b)
//        GL_FLOAT,               // the type of each element
//        GL_FALSE,               // take our values as-is
//        5 * sizeof(GLfloat),    // next color appears every 5 floats
//        (GLvoid*) (2 * sizeof(GLfloat))  // offset of first element
//    );
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    /* Push each element in buffer_vertices to the vertex shader */
//    glDrawArrays(GL_LINE_LOOP, 0,2);
//    if(debug) qDebug("Debug: '%s'", "DRAWING LINE-------");
//    glDisableVertexAttribArray(attribute_coord2d);
//    glDisableVertexAttribArray(attribute_v_color);
}

//13
void Bone_Hip_R::loadTexture(){
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures("C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Body\\righthip.png");
}

void Bone_Hip_R::createVertices(){
    int i;
    double L=0.2;
    double L_=0.1;
    if (!this)
        return;

    if(this->getParent()){
        double alpha = atan2(this->getParent()->getTip().y()-this->getTip().y(), this->getParent()->getTip().x()-this->getTip().x());

        double x_tip = this->getTip().x() - L_ * cos(alpha);
        double y_tip = this->getTip().y() - L_ * sin(alpha);


        double m = (this->getParent()->getTip().y()-this->getTip().y())/(this->getParent()->getTip().x()-this->getTip().x());
        double m_norm=-1/m;
        double dx=sqrt( pow(L,2) / (1 + pow(m_norm,2)) ) / 2;
        double dy=m_norm * dx;
        this->vertex[0].x = this->getParent()->getTip().x()-dx;
        this->vertex[0].y = this->getParent()->getTip().y()-dy;

        this->vertex[1].x = this->getParent()->getTip().x()+dx;
        this->vertex[1].y = this->getParent()->getTip().y()+dy;

        this->vertex[2].x = x_tip+dx;
        this->vertex[2].y = y_tip+dy;

        this->vertex[3].x = x_tip-dx;
        this->vertex[3].y = y_tip-dy;
    }
    else{
        double dx=L*2;
        double dy=L*2;
        this->vertex[0].x = this->getTip().x()-dx;
        this->vertex[0].y = this->getTip().y()-dy;

        this->vertex[1].x = this->getTip().x()-dx;
        this->vertex[1].y = this->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()+dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }

    for (i = 0; i < 4; i++)
    {
        this->vertex[i].r = 0;
        this->vertex[i].g = 0;
        this->vertex[i].b = 1;
    }
}

void Bone_Hip_R::drawGraphic()
{
        if(debug) qDebug("Debug: '%d'", this->getID());

        glLineWidth(2.5);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //MESH
        glBegin(GL_QUADS);
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex2f(this->vertex[0].x, this->vertex[0].y);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex2f(this->vertex[1].x, this->vertex[1].y);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex2f(this->vertex[2].x, this->vertex[2].y);
                    glTexCoord2f(0.0f, 0.0f);
                    glVertex2f(this->vertex[3].x, this->vertex[3].y);

        glEnd();
        glDisable(GL_TEXTURE_2D);
//        glColor3f(0.0, 1.0, 0.0);
//        //BONES
//        glBegin(GL_LINES);
//        if(this->getParent()!=NULL){
//            glVertex2f(this->getTip().x(), this->getTip().y());
//            glVertex2f(this->getParent()->getTip().x(), this->getParent()->getTip().y());
//        }
//        glEnd();

//    GLfloat x1,x2,y1,y2;
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    if(this->getID()==CENTER){
//        x1=0;
//        y1=0;
//    }
//    else{
//        x1=this->getParent()->getTip().x();
//        y1=this->getParent()->getTip().y();
//    }


//    x2=this->getTip().x();
//    y2=this->getTip().y();
//    if(debug) qDebug("Debug: '%f %f %f %f'", x1,y1,x2,y2);
//    GLfloat triangle_vertices[] = {
//             x1, y1, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF(),
//             x2, y2, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF()

//     };
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glUseProgram(program);
//    glEnableVertexAttribArray(attribute_coord2d);
//    glEnableVertexAttribArray(attribute_v_color);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glVertexAttribPointer(
//        attribute_coord2d,   // attribute
//        2,                   // number of elements per vertex, here (x,y)
//        GL_FLOAT,            // the type of each element
//        GL_FALSE,            // take our values as-is
//        5 * sizeof(GLfloat), // next coord2d appears every 5 floats
//        0                    // offset of the first element
//    );
//    glVertexAttribPointer(
//        attribute_v_color,      // attribute
//        3,                      // number of elements per vertex, here (r,g,b)
//        GL_FLOAT,               // the type of each element
//        GL_FALSE,               // take our values as-is
//        5 * sizeof(GLfloat),    // next color appears every 5 floats
//        (GLvoid*) (2 * sizeof(GLfloat))  // offset of first element
//    );
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    /* Push each element in buffer_vertices to the vertex shader */
//    glDrawArrays(GL_LINE_LOOP, 0,2);
//    if(debug) qDebug("Debug: '%s'", "DRAWING LINE-------");
//    glDisableVertexAttribArray(attribute_coord2d);
//    glDisableVertexAttribArray(attribute_v_color);
}

//14
void Bone_Knee_L::loadTexture(){
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures("C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Body\\leftknee.png");
}

void Bone_Knee_L::createVertices(){
    int i;
    double L=0.3;
    double L_=0.1;
    if (!this)
        return;

    if(this->getParent()){
        double alpha = atan2(this->getParent()->getTip().y()-this->getTip().y(), this->getParent()->getTip().x()-this->getTip().x());

        double x_tip = this->getTip().x() - L_ * cos(alpha);
        double y_tip = this->getTip().y() - L_ * sin(alpha);


        double m = (this->getParent()->getTip().y()-this->getTip().y())/(this->getParent()->getTip().x()-this->getTip().x());
        double m_norm=-1/m;
        double dx=sqrt( pow(L,2) / (1 + pow(m_norm,2)) ) / 2;
        double dy=m_norm * dx;
        this->vertex[0].x = this->getParent()->getTip().x()-dx;
        this->vertex[0].y = this->getParent()->getTip().y()-dy;

        this->vertex[1].x = this->getParent()->getTip().x()+dx;
        this->vertex[1].y = this->getParent()->getTip().y()+dy;

        this->vertex[2].x = x_tip+dx;
        this->vertex[2].y = y_tip+dy;

        this->vertex[3].x = x_tip-dx;
        this->vertex[3].y = y_tip-dy;
    }
    else{
        double dx=L*2;
        double dy=L*2;
        this->vertex[0].x = this->getTip().x()-dx;
        this->vertex[0].y = this->getTip().y()-dy;

        this->vertex[1].x = this->getTip().x()-dx;
        this->vertex[1].y = this->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()+dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }

    for (i = 0; i < 4; i++)
    {
        this->vertex[i].r = 0;
        this->vertex[i].g = 0;
        this->vertex[i].b = 1;
    }
}

void Bone_Knee_L::drawGraphic()
{
        if(debug) qDebug("Debug: '%d'", this->getID());

        glLineWidth(2.5);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //MESH
        glBegin(GL_QUADS);
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex2f(this->vertex[0].x, this->vertex[0].y);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex2f(this->vertex[1].x, this->vertex[1].y);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex2f(this->vertex[2].x, this->vertex[2].y);
                    glTexCoord2f(0.0f, 0.0f);
                    glVertex2f(this->vertex[3].x, this->vertex[3].y);

        glEnd();
        glDisable(GL_TEXTURE_2D);
//        glColor3f(0.0, 1.0, 0.0);
//        //BONES
//        glBegin(GL_LINES);
//        if(this->getParent()!=NULL){
//            glVertex2f(this->getTip().x(), this->getTip().y());
//            glVertex2f(this->getParent()->getTip().x(), this->getParent()->getTip().y());
//        }
//        glEnd();

//    GLfloat x1,x2,y1,y2;
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    if(this->getID()==CENTER){
//        x1=0;
//        y1=0;
//    }
//    else{
//        x1=this->getParent()->getTip().x();
//        y1=this->getParent()->getTip().y();
//    }


//    x2=this->getTip().x();
//    y2=this->getTip().y();
//    if(debug) qDebug("Debug: '%f %f %f %f'", x1,y1,x2,y2);
//    GLfloat triangle_vertices[] = {
//             x1, y1, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF(),
//             x2, y2, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF()

//     };
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glUseProgram(program);
//    glEnableVertexAttribArray(attribute_coord2d);
//    glEnableVertexAttribArray(attribute_v_color);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glVertexAttribPointer(
//        attribute_coord2d,   // attribute
//        2,                   // number of elements per vertex, here (x,y)
//        GL_FLOAT,            // the type of each element
//        GL_FALSE,            // take our values as-is
//        5 * sizeof(GLfloat), // next coord2d appears every 5 floats
//        0                    // offset of the first element
//    );
//    glVertexAttribPointer(
//        attribute_v_color,      // attribute
//        3,                      // number of elements per vertex, here (r,g,b)
//        GL_FLOAT,               // the type of each element
//        GL_FALSE,               // take our values as-is
//        5 * sizeof(GLfloat),    // next color appears every 5 floats
//        (GLvoid*) (2 * sizeof(GLfloat))  // offset of first element
//    );
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    /* Push each element in buffer_vertices to the vertex shader */
//    glDrawArrays(GL_LINE_LOOP, 0,2);
//    if(debug) qDebug("Debug: '%s'", "DRAWING LINE-------");
//    glDisableVertexAttribArray(attribute_coord2d);
//    glDisableVertexAttribArray(attribute_v_color);
}

//15
void Bone_Knee_R::loadTexture(){
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures("C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Body\\rightknee.png");
}

void Bone_Knee_R::createVertices(){
    int i;
    double L=0.3;
    double L_=0.1;
    if (!this)
        return;

    if(this->getParent()){
        double alpha = atan2(this->getParent()->getTip().y()-this->getTip().y(), this->getParent()->getTip().x()-this->getTip().x());

        double x_tip = this->getTip().x() - L_ * cos(alpha);
        double y_tip = this->getTip().y() - L_ * sin(alpha);


        double m = (this->getParent()->getTip().y()-this->getTip().y())/(this->getParent()->getTip().x()-this->getTip().x());
        double m_norm=-1/m;
        double dx=sqrt( pow(L,2) / (1 + pow(m_norm,2)) ) / 2;
        double dy=m_norm * dx;
        this->vertex[0].x = this->getParent()->getTip().x()-dx;
        this->vertex[0].y = this->getParent()->getTip().y()-dy;

        this->vertex[1].x = this->getParent()->getTip().x()+dx;
        this->vertex[1].y = this->getParent()->getTip().y()+dy;

        this->vertex[2].x = x_tip+dx;
        this->vertex[2].y = y_tip+dy;

        this->vertex[3].x = x_tip-dx;
        this->vertex[3].y = y_tip-dy;
    }
    else{
        double dx=L*2;
        double dy=L*2;
        this->vertex[0].x = this->getTip().x()-dx;
        this->vertex[0].y = this->getTip().y()-dy;

        this->vertex[1].x = this->getTip().x()-dx;
        this->vertex[1].y = this->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()+dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }

    for (i = 0; i < 4; i++)
    {
        this->vertex[i].r = 0;
        this->vertex[i].g = 0;
        this->vertex[i].b = 1;
    }
}

void Bone_Knee_R::drawGraphic()
{
        if(debug) qDebug("Debug: '%d'", this->getID());

        glLineWidth(2.5);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //MESH
        glBegin(GL_QUADS);
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex2f(this->vertex[0].x, this->vertex[0].y);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex2f(this->vertex[1].x, this->vertex[1].y);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex2f(this->vertex[2].x, this->vertex[2].y);
                    glTexCoord2f(0.0f, 0.0f);
                    glVertex2f(this->vertex[3].x, this->vertex[3].y);

        glEnd();
        glDisable(GL_TEXTURE_2D);
//        glColor3f(0.0, 1.0, 0.0);
//        //BONES
//        glBegin(GL_LINES);
//        if(this->getParent()!=NULL){
//            glVertex2f(this->getTip().x(), this->getTip().y());
//            glVertex2f(this->getParent()->getTip().x(), this->getParent()->getTip().y());
//        }
//        glEnd();

//    GLfloat x1,x2,y1,y2;
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    if(this->getID()==CENTER){
//        x1=0;
//        y1=0;
//    }
//    else{
//        x1=this->getParent()->getTip().x();
//        y1=this->getParent()->getTip().y();
//    }


//    x2=this->getTip().x();
//    y2=this->getTip().y();
//    if(debug) qDebug("Debug: '%f %f %f %f'", x1,y1,x2,y2);
//    GLfloat triangle_vertices[] = {
//             x1, y1, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF(),
//             x2, y2, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF()

//     };
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glUseProgram(program);
//    glEnableVertexAttribArray(attribute_coord2d);
//    glEnableVertexAttribArray(attribute_v_color);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glVertexAttribPointer(
//        attribute_coord2d,   // attribute
//        2,                   // number of elements per vertex, here (x,y)
//        GL_FLOAT,            // the type of each element
//        GL_FALSE,            // take our values as-is
//        5 * sizeof(GLfloat), // next coord2d appears every 5 floats
//        0                    // offset of the first element
//    );
//    glVertexAttribPointer(
//        attribute_v_color,      // attribute
//        3,                      // number of elements per vertex, here (r,g,b)
//        GL_FLOAT,               // the type of each element
//        GL_FALSE,               // take our values as-is
//        5 * sizeof(GLfloat),    // next color appears every 5 floats
//        (GLvoid*) (2 * sizeof(GLfloat))  // offset of first element
//    );
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    /* Push each element in buffer_vertices to the vertex shader */
//    glDrawArrays(GL_LINE_LOOP, 0,2);
//    if(debug) qDebug("Debug: '%s'", "DRAWING LINE-------");
//    glDisableVertexAttribArray(attribute_coord2d);
//    glDisableVertexAttribArray(attribute_v_color);
}

//16
void Bone_Ankle_L::loadTexture(){
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures("C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Body\\rightankle.png");
}

void Bone_Ankle_L::createVertices(){
    int i;
    double L=0.3;
    double L_=0.01;
    if (!this)
        return;

    if(this->getParent()){
        double alpha = atan2(this->getParent()->getTip().y()-this->getTip().y(), this->getParent()->getTip().x()-this->getTip().x());

        double x_tip = this->getTip().x() - L_ * cos(alpha);
        double y_tip = this->getTip().y() - L_ * sin(alpha);


        double m = (this->getParent()->getTip().y()-this->getTip().y())/(this->getParent()->getTip().x()-this->getTip().x());
        double m_norm=-1/m;
        double dx=sqrt( pow(L,2) / (1 + pow(m_norm,2)) ) / 2;
        double dy=m_norm * dx;
        this->vertex[0].x = this->getParent()->getTip().x()-dx;
        this->vertex[0].y = this->getParent()->getTip().y()-dy;

        this->vertex[1].x = this->getParent()->getTip().x()+dx;
        this->vertex[1].y = this->getParent()->getTip().y()+dy;

        this->vertex[2].x = x_tip+dx;
        this->vertex[2].y = y_tip+dy;

        this->vertex[3].x = x_tip-dx;
        this->vertex[3].y = y_tip-dy;
    }
    else{
        double dx=L*2;
        double dy=L*2;
        this->vertex[0].x = this->getTip().x()-dx;
        this->vertex[0].y = this->getTip().y()-dy;

        this->vertex[1].x = this->getTip().x()-dx;
        this->vertex[1].y = this->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()+dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }

    for (i = 0; i < 4; i++)
    {
        this->vertex[i].r = 0;
        this->vertex[i].g = 0;
        this->vertex[i].b = 1;
    }
}

void Bone_Ankle_L::drawGraphic()
{
        if(debug) qDebug("Debug: '%d'", this->getID());

        glLineWidth(2.5);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //MESH
        glBegin(GL_QUADS);
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex2f(this->vertex[0].x, this->vertex[0].y);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex2f(this->vertex[1].x, this->vertex[1].y);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex2f(this->vertex[2].x, this->vertex[2].y);
                    glTexCoord2f(0.0f, 0.0f);
                    glVertex2f(this->vertex[3].x, this->vertex[3].y);

        glEnd();
        glDisable(GL_TEXTURE_2D);
//        glColor3f(0.0, 1.0, 0.0);
//        //BONES
//        glBegin(GL_LINES);
//        if(this->getParent()!=NULL){
//            glVertex2f(this->getTip().x(), this->getTip().y());
//            glVertex2f(this->getParent()->getTip().x(), this->getParent()->getTip().y());
//        }
//        glEnd();

//    GLfloat x1,x2,y1,y2;
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    if(this->getID()==CENTER){
//        x1=0;
//        y1=0;
//    }
//    else{
//        x1=this->getParent()->getTip().x();
//        y1=this->getParent()->getTip().y();
//    }


//    x2=this->getTip().x();
//    y2=this->getTip().y();
//    if(debug) qDebug("Debug: '%f %f %f %f'", x1,y1,x2,y2);
//    GLfloat triangle_vertices[] = {
//             x1, y1, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF(),
//             x2, y2, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF()

//     };
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glUseProgram(program);
//    glEnableVertexAttribArray(attribute_coord2d);
//    glEnableVertexAttribArray(attribute_v_color);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glVertexAttribPointer(
//        attribute_coord2d,   // attribute
//        2,                   // number of elements per vertex, here (x,y)
//        GL_FLOAT,            // the type of each element
//        GL_FALSE,            // take our values as-is
//        5 * sizeof(GLfloat), // next coord2d appears every 5 floats
//        0                    // offset of the first element
//    );
//    glVertexAttribPointer(
//        attribute_v_color,      // attribute
//        3,                      // number of elements per vertex, here (r,g,b)
//        GL_FLOAT,               // the type of each element
//        GL_FALSE,               // take our values as-is
//        5 * sizeof(GLfloat),    // next color appears every 5 floats
//        (GLvoid*) (2 * sizeof(GLfloat))  // offset of first element
//    );
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    /* Push each element in buffer_vertices to the vertex shader */
//    glDrawArrays(GL_LINE_LOOP, 0,2);
//    if(debug) qDebug("Debug: '%s'", "DRAWING LINE-------");
//    glDisableVertexAttribArray(attribute_coord2d);
//    glDisableVertexAttribArray(attribute_v_color);
}

//17
void Bone_Ankle_R::loadTexture(){
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures("C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Body\\leftankle.png");
}

void Bone_Ankle_R::createVertices(){
    int i;
    double L=0.3;
    double L_=0.01;
    if (!this)
        return;

    if(this->getParent()){
        double alpha = atan2(this->getParent()->getTip().y()-this->getTip().y(), this->getParent()->getTip().x()-this->getTip().x());

        double x_tip = this->getTip().x() - L_ * cos(alpha);
        double y_tip = this->getTip().y() - L_ * sin(alpha);


        double m = (this->getParent()->getTip().y()-this->getTip().y())/(this->getParent()->getTip().x()-this->getTip().x());
        double m_norm=-1/m;
        double dx=sqrt( pow(L,2) / (1 + pow(m_norm,2)) ) / 2;
        double dy=m_norm * dx;
        this->vertex[0].x = this->getParent()->getTip().x()-dx;
        this->vertex[0].y = this->getParent()->getTip().y()-dy;

        this->vertex[1].x = this->getParent()->getTip().x()+dx;
        this->vertex[1].y = this->getParent()->getTip().y()+dy;

        this->vertex[2].x = x_tip+dx;
        this->vertex[2].y = y_tip+dy;

        this->vertex[3].x = x_tip-dx;
        this->vertex[3].y = y_tip-dy;
    }
    else{
        double dx=L*2;
        double dy=L*2;
        this->vertex[0].x = this->getTip().x()-dx;
        this->vertex[0].y = this->getTip().y()-dy;

        this->vertex[1].x = this->getTip().x()-dx;
        this->vertex[1].y = this->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()+dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }

    for (i = 0; i < 4; i++)
    {
        this->vertex[i].r = 0;
        this->vertex[i].g = 0;
        this->vertex[i].b = 1;
    }
}

void Bone_Ankle_R::drawGraphic()
{
        if(debug) qDebug("Debug: '%d'", this->getID());

        glLineWidth(2.5);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //MESH
        glBegin(GL_QUADS);
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex2f(this->vertex[0].x, this->vertex[0].y);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex2f(this->vertex[1].x, this->vertex[1].y);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex2f(this->vertex[2].x, this->vertex[2].y);
                    glTexCoord2f(0.0f, 0.0f);
                    glVertex2f(this->vertex[3].x, this->vertex[3].y);

        glEnd();
        glDisable(GL_TEXTURE_2D);
//        glColor3f(0.0, 1.0, 0.0);
//        //BONES
//        glBegin(GL_LINES);
//        if(this->getParent()!=NULL){
//            glVertex2f(this->getTip().x(), this->getTip().y());
//            glVertex2f(this->getParent()->getTip().x(), this->getParent()->getTip().y());
//        }
//        glEnd();

//    GLfloat x1,x2,y1,y2;
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    if(this->getID()==CENTER){
//        x1=0;
//        y1=0;
//    }
//    else{
//        x1=this->getParent()->getTip().x();
//        y1=this->getParent()->getTip().y();
//    }


//    x2=this->getTip().x();
//    y2=this->getTip().y();
//    if(debug) qDebug("Debug: '%f %f %f %f'", x1,y1,x2,y2);
//    GLfloat triangle_vertices[] = {
//             x1, y1, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF(),
//             x2, y2, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF()

//     };
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glUseProgram(program);
//    glEnableVertexAttribArray(attribute_coord2d);
//    glEnableVertexAttribArray(attribute_v_color);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glVertexAttribPointer(
//        attribute_coord2d,   // attribute
//        2,                   // number of elements per vertex, here (x,y)
//        GL_FLOAT,            // the type of each element
//        GL_FALSE,            // take our values as-is
//        5 * sizeof(GLfloat), // next coord2d appears every 5 floats
//        0                    // offset of the first element
//    );
//    glVertexAttribPointer(
//        attribute_v_color,      // attribute
//        3,                      // number of elements per vertex, here (r,g,b)
//        GL_FLOAT,               // the type of each element
//        GL_FALSE,               // take our values as-is
//        5 * sizeof(GLfloat),    // next color appears every 5 floats
//        (GLvoid*) (2 * sizeof(GLfloat))  // offset of first element
//    );
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    /* Push each element in buffer_vertices to the vertex shader */
//    glDrawArrays(GL_LINE_LOOP, 0,2);
//    if(debug) qDebug("Debug: '%s'", "DRAWING LINE-------");
//    glDisableVertexAttribArray(attribute_coord2d);
//    glDisableVertexAttribArray(attribute_v_color);
}

//18
void Bone_Foot_L::loadTexture(){
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures("C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Body\\leftfoot.png");
}

void Bone_Foot_L::createVertices(){
    int i;
    double L=0.1;
    double L_=0.05;
    if (!this)
        return;

    if(this->getParent()){
        double alpha = atan2(this->getParent()->getTip().y()-this->getTip().y(), this->getParent()->getTip().x()-this->getTip().x());

        double x_tip = this->getTip().x() - L_ * cos(alpha);
        double y_tip = this->getTip().y() - L_ * sin(alpha);


        double m = (this->getParent()->getTip().y()-this->getTip().y())/(this->getParent()->getTip().x()-this->getTip().x());
        double m_norm=-1/m;
        double dx=sqrt( pow(L,2) / (1 + pow(m_norm,2)) ) / 2;
        double dy=m_norm * dx;
        this->vertex[0].x = this->getParent()->getTip().x()-dx;
        this->vertex[0].y = this->getParent()->getTip().y()-dy;

        this->vertex[1].x = this->getParent()->getTip().x()+dx;
        this->vertex[1].y = this->getParent()->getTip().y()+dy;

        this->vertex[2].x = x_tip+dx;
        this->vertex[2].y = y_tip+dy;

        this->vertex[3].x = x_tip-dx;
        this->vertex[3].y = y_tip-dy;
    }
    else{
        double dx=L*2;
        double dy=L*2;
        this->vertex[0].x = this->getTip().x()-dx;
        this->vertex[0].y = this->getTip().y()-dy;

        this->vertex[1].x = this->getTip().x()-dx;
        this->vertex[1].y = this->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()+dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }

    for (i = 0; i < 4; i++)
    {
        this->vertex[i].r = 0;
        this->vertex[i].g = 0;
        this->vertex[i].b = 1;
    }
}

void Bone_Foot_L::drawGraphic()
{
        if(debug) qDebug("Debug: '%d'", this->getID());

        glLineWidth(2.5);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //MESH
        glBegin(GL_QUADS);
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex2f(this->vertex[0].x, this->vertex[0].y);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex2f(this->vertex[1].x, this->vertex[1].y);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex2f(this->vertex[2].x, this->vertex[2].y);
                    glTexCoord2f(0.0f, 0.0f);
                    glVertex2f(this->vertex[3].x, this->vertex[3].y);

        glEnd();
        glDisable(GL_TEXTURE_2D);
//        glColor3f(0.0, 1.0, 0.0);
//        //BONES
//        glBegin(GL_LINES);
//        if(this->getParent()!=NULL){
//            glVertex2f(this->getTip().x(), this->getTip().y());
//            glVertex2f(this->getParent()->getTip().x(), this->getParent()->getTip().y());
//        }
//        glEnd();

//    GLfloat x1,x2,y1,y2;
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    if(this->getID()==CENTER){
//        x1=0;
//        y1=0;
//    }
//    else{
//        x1=this->getParent()->getTip().x();
//        y1=this->getParent()->getTip().y();
//    }


//    x2=this->getTip().x();
//    y2=this->getTip().y();
//    if(debug) qDebug("Debug: '%f %f %f %f'", x1,y1,x2,y2);
//    GLfloat triangle_vertices[] = {
//             x1, y1, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF(),
//             x2, y2, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF()

//     };
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glUseProgram(program);
//    glEnableVertexAttribArray(attribute_coord2d);
//    glEnableVertexAttribArray(attribute_v_color);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glVertexAttribPointer(
//        attribute_coord2d,   // attribute
//        2,                   // number of elements per vertex, here (x,y)
//        GL_FLOAT,            // the type of each element
//        GL_FALSE,            // take our values as-is
//        5 * sizeof(GLfloat), // next coord2d appears every 5 floats
//        0                    // offset of the first element
//    );
//    glVertexAttribPointer(
//        attribute_v_color,      // attribute
//        3,                      // number of elements per vertex, here (r,g,b)
//        GL_FLOAT,               // the type of each element
//        GL_FALSE,               // take our values as-is
//        5 * sizeof(GLfloat),    // next color appears every 5 floats
//        (GLvoid*) (2 * sizeof(GLfloat))  // offset of first element
//    );
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    /* Push each element in buffer_vertices to the vertex shader */
//    glDrawArrays(GL_LINE_LOOP, 0,2);
//    if(debug) qDebug("Debug: '%s'", "DRAWING LINE-------");
//    glDisableVertexAttribArray(attribute_coord2d);
//    glDisableVertexAttribArray(attribute_v_color);
}

void Bone_Foot_R::loadTexture(){
glEnable(GL_TEXTURE_2D);
LoadGLTextures("C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Body\\rightfoot.png");
}

void Bone_Foot_R::createVertices(){
int i;
double L=0.1;
double L_=0.05;
if (!this)
    return;

if(this->getParent()){
    double alpha = atan2(this->getParent()->getTip().y()-this->getTip().y(), this->getParent()->getTip().x()-this->getTip().x());

    double x_tip = this->getTip().x() - L_ * cos(alpha);
    double y_tip = this->getTip().y() - L_ * sin(alpha);


    double m = (this->getParent()->getTip().y()-this->getTip().y())/(this->getParent()->getTip().x()-this->getTip().x());
    double m_norm=-1/m;
    double dx=sqrt( pow(L,2) / (1 + pow(m_norm,2)) ) / 2;
    double dy=m_norm * dx;
    this->vertex[0].x = this->getParent()->getTip().x()-dx;
    this->vertex[0].y = this->getParent()->getTip().y()-dy;

    this->vertex[1].x = this->getParent()->getTip().x()+dx;
    this->vertex[1].y = this->getParent()->getTip().y()+dy;

    this->vertex[2].x = x_tip+dx;
    this->vertex[2].y = y_tip+dy;

    this->vertex[3].x = x_tip-dx;
    this->vertex[3].y = y_tip-dy;
}
else{
    double dx=L*2;
    double dy=L*2;
    this->vertex[0].x = this->getTip().x()-dx;
    this->vertex[0].y = this->getTip().y()-dy;

    this->vertex[1].x = this->getTip().x()-dx;
    this->vertex[1].y = this->getTip().y()+dy;

    this->vertex[2].x = this->getTip().x()+dx;
    this->vertex[2].y = this->getTip().y()+dy;

    this->vertex[3].x = this->getTip().x()+dx;
    this->vertex[3].y = this->getTip().y()-dy;
}

for (i = 0; i < 4; i++)
{
    this->vertex[i].r = 0;
    this->vertex[i].g = 0;
    this->vertex[i].b = 1;
}
}

void Bone_Foot_R::drawGraphic()
{
    if(debug) qDebug("Debug: '%d'", this->getID());

    glLineWidth(2.5);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBindTexture(GL_TEXTURE_2D, Texture);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //MESH
    glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 1.0f);
                glVertex2f(this->vertex[0].x, this->vertex[0].y);
                glTexCoord2f(1.0f, 1.0f);
                glVertex2f(this->vertex[1].x, this->vertex[1].y);
                glTexCoord2f(1.0f, 0.0f);
                glVertex2f(this->vertex[2].x, this->vertex[2].y);
                glTexCoord2f(0.0f, 0.0f);
                glVertex2f(this->vertex[3].x, this->vertex[3].y);

    glEnd();
    glDisable(GL_TEXTURE_2D);
//        glColor3f(0.0, 1.0, 0.0);
//        //BONES
//        glBegin(GL_LINES);
//        if(this->getParent()!=NULL){
//            glVertex2f(this->getTip().x(), this->getTip().y());
//            glVertex2f(this->getParent()->getTip().x(), this->getParent()->getTip().y());
//        }
//        glEnd();

//    GLfloat x1,x2,y1,y2;
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    if(this->getID()==CENTER){
//        x1=0;
//        y1=0;
//    }
//    else{
//        x1=this->getParent()->getTip().x();
//        y1=this->getParent()->getTip().y();
//    }


//    x2=this->getTip().x();
//    y2=this->getTip().y();
//    if(debug) qDebug("Debug: '%f %f %f %f'", x1,y1,x2,y2);
//    GLfloat triangle_vertices[] = {
//             x1, y1, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF(),
//             x2, y2, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF()

//     };
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glUseProgram(program);
//    glEnableVertexAttribArray(attribute_coord2d);
//    glEnableVertexAttribArray(attribute_v_color);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glVertexAttribPointer(
//        attribute_coord2d,   // attribute
//        2,                   // number of elements per vertex, here (x,y)
//        GL_FLOAT,            // the type of each element
//        GL_FALSE,            // take our values as-is
//        5 * sizeof(GLfloat), // next coord2d appears every 5 floats
//        0                    // offset of the first element
//    );
//    glVertexAttribPointer(
//        attribute_v_color,      // attribute
//        3,                      // number of elements per vertex, here (r,g,b)
//        GL_FLOAT,               // the type of each element
//        GL_FALSE,               // take our values as-is
//        5 * sizeof(GLfloat),    // next color appears every 5 floats
//        (GLvoid*) (2 * sizeof(GLfloat))  // offset of first element
//    );
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    /* Push each element in buffer_vertices to the vertex shader */
//    glDrawArrays(GL_LINE_LOOP, 0,2);
//    if(debug) qDebug("Debug: '%s'", "DRAWING LINE-------");
//    glDisableVertexAttribArray(attribute_coord2d);
//    glDisableVertexAttribArray(attribute_v_color);
}

//20

void Bone_Head::loadTexture(){
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures("C:\\Users\\Sarthak\\Dropbox\\IIITDsem7\\CG\\Project\\Body\\head.png");
}

void Bone_Head::createVertices(){
    int i;
    double L=0.15;
    double L_=0.2;
    if (!this)
        return;

    if(this->getParent()){
        double alpha = atan2(this->getParent()->getTip().y()-this->getTip().y(), this->getParent()->getTip().x()-this->getTip().x());

        double x_tip = this->getParent()->getTip().x() + L_ * cos(alpha);
        double y_tip = this->getParent()->getTip().y() + L_ * sin(alpha);

        double m = (this->getParent()->getTip().y()-this->getTip().y())/(this->getParent()->getTip().x()-this->getTip().x());
        double m_norm=-1/m;
        double dx=sqrt( pow(L,2) / (1 + pow(m_norm,2)) ) / 2;
        double dy=m_norm * dx;
        this->vertex[0].x = x_tip-dx;
        this->vertex[0].y = y_tip-dy;

        this->vertex[1].x = x_tip+dx;
        this->vertex[1].y = y_tip+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()-dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }
    else{
        double dx=L*2;
        double dy=L*2;
        this->vertex[0].x = this->getTip().x()-dx;
        this->vertex[0].y = this->getTip().y()-dy;

        this->vertex[1].x = this->getTip().x()-dx;
        this->vertex[1].y = this->getTip().y()+dy;

        this->vertex[2].x = this->getTip().x()+dx;
        this->vertex[2].y = this->getTip().y()+dy;

        this->vertex[3].x = this->getTip().x()+dx;
        this->vertex[3].y = this->getTip().y()-dy;
    }

    for (i = 0; i < 4; i++)
    {
        this->vertex[i].r = 0;
        this->vertex[i].g = 0;
        this->vertex[i].b = 1;
    }
}

void Bone_Head::drawGraphic()
{
        if(debug) qDebug("Debug: '%d'", this->getID());

        glLineWidth(2.5);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glEnable(GL_COLOR_MATERIAL);

        glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //MESH
        glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 0.0f);

                    glVertex2f(this->vertex[0].x, this->vertex[0].y);
                    glTexCoord2f(0.0f, 0.0f);

                    glVertex2f(this->vertex[1].x, this->vertex[1].y);
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex2f(this->vertex[2].x, this->vertex[2].y);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex2f(this->vertex[3].x, this->vertex[3].y);

        glEnd();
        glDisable(GL_TEXTURE_2D);
//        glColor3f(0.0, 1.0, 0.0);
//        //BONES
//        glBegin(GL_LINES);
//        if(this->getParent()!=NULL){
//            glVertex2f(this->getTip().x(), this->getTip().y());
//            glVertex2f(this->getParent()->getTip().x(), this->getParent()->getTip().y());
//        }
//        glEnd();

//    GLfloat x1,x2,y1,y2;
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    if(this->getID()==CENTER){
//        x1=0;
//        y1=0;
//    }
//    else{
//        x1=this->getParent()->getTip().x();
//        y1=this->getParent()->getTip().y();
//    }


//    x2=this->getTip().x();
//    y2=this->getTip().y();
//    if(debug) qDebug("Debug: '%f %f %f %f'", x1,y1,x2,y2);
//    GLfloat triangle_vertices[] = {
//             x1, y1, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF(),
//             x2, y2, colorStroke.redF(), colorStroke.greenF(), colorStroke.blueF()

//     };
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glUseProgram(program);
//    glEnableVertexAttribArray(attribute_coord2d);
//    glEnableVertexAttribArray(attribute_v_color);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    glVertexAttribPointer(
//        attribute_coord2d,   // attribute
//        2,                   // number of elements per vertex, here (x,y)
//        GL_FLOAT,            // the type of each element
//        GL_FALSE,            // take our values as-is
//        5 * sizeof(GLfloat), // next coord2d appears every 5 floats
//        0                    // offset of the first element
//    );
//    glVertexAttribPointer(
//        attribute_v_color,      // attribute
//        3,                      // number of elements per vertex, here (r,g,b)
//        GL_FLOAT,               // the type of each element
//        GL_FALSE,               // take our values as-is
//        5 * sizeof(GLfloat),    // next color appears every 5 floats
//        (GLvoid*) (2 * sizeof(GLfloat))  // offset of first element
//    );
//    if(debug) qDebug("Debug: '%s'", "Debugging...");
//    /* Push each element in buffer_vertices to the vertex shader */
//    glDrawArrays(GL_LINE_LOOP, 0,2);
//    if(debug) qDebug("Debug: '%s'", "DRAWING LINE-------");
//    glDisableVertexAttribArray(attribute_coord2d);
//    glDisableVertexAttribArray(attribute_v_color);
}
