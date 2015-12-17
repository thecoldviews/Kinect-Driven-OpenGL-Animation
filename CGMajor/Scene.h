#pragma once

#ifndef SCENE_H
#define SCENE_H

#include "Human.h"
#include <qfiledialog.h>
#include <Transformation.h>
#include <QOpenGLShaderProgram>
#include <QGLWidget>
#include <Filters.h>
#include <dataset.h>


/*
 * CG Major Project, Monsoon 2015
 * Author: Sarthak Ahuja, 2012088 | IIIT-Delhi
 *
 * Description:
 */

class Scene:public QGLWidget
{
private:
    QPointF startPoint;
    QPointF endPoint;

    Filter* filter;

    GLuint program;
    GLint attribute_coord2d;
    GLuint vbo_triangle;
    GLint attribute_v_color;

protected:

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mousePressEvent(QMouseEvent* e);
    //void mouseMoveEvent(QMouseEvent* e);
    //void mouseReleaseEvent(QMouseEvent* e);
    Transformation calculateTransformation(int);



public:
    bool debug=false;
    Human* human;
    bool doFilter=false;
    DataSet* dataSet;
    DataSet* liveData;
    std::vector<Joint*> body;
    void runData();
    void runLive();
    void setFilter(bool t){
        doFilter=t;

    }
    void setWindows(int t){
        filter->setWindow(t);
    }
    void reset();
    Scene(QWidget *parent = 0);
    ~Scene();
};

#endif // !Scene_H
