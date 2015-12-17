/*
 * CG Major Project, Monsoon 2015
 * Author: Sarthak Ahuja, 2012088 | IIIT-Delhi
 *
 * Description:
 */

#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H


#include <GL/gl.h>
#include <glm/glm.hpp>

class Transformation
{
private:
    bool debug=false;
    double theta;
    double scale;
    double translationx;
    double translationy;
public:
    Transformation();
    void setRotation(double);
    double getRotation(){
        return theta;
    }
    double getScale(){
        return scale;
    }
    double getX(){
        return translationx;
    }
    double getY(){
        return translationy;
    }
    void setTranslationX(double);
    void setTranslationY(double);
    void setScale(double);
    glm::mat3 generateModel();
};

#endif // TRANSFORMATION_H
