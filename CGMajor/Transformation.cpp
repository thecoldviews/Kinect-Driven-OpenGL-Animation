/*
 * CG Major Project, Monsoon 2015
 * Author: Sarthak Ahuja, 2012088 | IIIT-Delhi
 *
 * Description:
 */

#include "Transformation.h"

Transformation::Transformation()
{
    this->theta=0;
    this->translationx=0;
    this->translationy=0;
    this->scale=1;
}

void Transformation::setRotation(double theta){
    this->theta=theta;
}

void Transformation::setTranslationX(double translation){
    this->translationx=translation;
}
void Transformation::setTranslationY(double translation){
    this->translationy=translation;
}


void Transformation::setScale(double scale){
    this->scale=scale;
}

glm::mat3 Transformation::generateModel(){
    glm::mat3 model;
    model[0][0] = scale*cos(theta); model[0][1] = -sin(theta); model[0][2] = translationx;
    model[1][0] = sin(theta); model[1][1] = scale*cos(theta); model[1][2] = translationy;
    model[2][0] = 0; model[2][1] = 0; model[2][2] = 1;
    return model;
}
