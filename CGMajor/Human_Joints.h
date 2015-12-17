/*
 * CG Major Project, Monsoon 2015
 * Author: Sarthak Ahuja, 2012088 | IIIT-Delhi
 *
 * Description:
 */

#pragma once

#ifndef HUMAN_JOINTS_H
#define HUMAN_JOINTS_H

#include "Human.h"


class Bone_Center : public Joint
{
public:
    Bone_Center(GLuint vb0, GLuint program, GLint attrib1, GLint attrib2 , int w, int h, int id) : Joint(vb0,program,attrib1,attrib2, w,h, id){
        this->loadTexture();
    }
    virtual ~Bone_Center(){}

    void init(){
    }
    void createVertices();
    void drawGraphic();
    void loadTexture();
    bool checkConstraints(Transformation T){
        /*
         * To be implemented Correctly
         */
        if((this->getTransformation().getRotation()+T.getRotation())<3.14){
            qDebug("Constraint: %f",this->getTransformation().getRotation()+T.getRotation());
            return true;
        }
        return false;
    }
};

class Bone_Spine : public Joint
{
public:
    Bone_Spine(GLuint vb0, GLuint program, GLint attrib1, GLint attrib2 , int w, int h, int id) : Joint(vb0,program,attrib1,attrib2, w,h, id){
        this->loadTexture();
    }
    virtual ~Bone_Spine(){}

    void init(){
    }
    void createVertices();
    void drawGraphic();
    void loadTexture();
    bool checkConstraints(Transformation T){
        /*
         * To be implemented Correctly
         */
        if((this->getTransformation().getRotation()+T.getRotation())<3.14){
            qDebug("Constraint: %f",this->getTransformation().getRotation()+T.getRotation());
            return true;
        }
        return false;
    }
};
class Bone_Collar : public Joint
{
public:
    Bone_Collar(GLuint vb0, GLuint program, GLint attrib1, GLint attrib2 , int w, int h, int id) : Joint(vb0,program,attrib1,attrib2, w,h, id){
        this->loadTexture();
    }
    virtual ~Bone_Collar(){}

    void init(){
    }
    void createVertices();
    void drawGraphic();
    void loadTexture();
    bool checkConstraints(Transformation T){
        /*
         * To be implemented Correctly
         */
        if((this->getTransformation().getRotation()+T.getRotation())<3.14){
            qDebug("Constraint: %f",this->getTransformation().getRotation()+T.getRotation());
            return true;
        }
        return false;
    }
};
class Bone_Shoulder_L : public Joint
{
public:
    Bone_Shoulder_L(GLuint vb0, GLuint program, GLint attrib1, GLint attrib2 , int w, int h, int id) : Joint(vb0,program,attrib1,attrib2, w,h, id){
        this->loadTexture();
    }
    virtual ~Bone_Shoulder_L(){}

    void init(){
    }
    void createVertices();
    void drawGraphic();
    void loadTexture();
    bool checkConstraints(Transformation T){
        /*
         * To be implemented Correctly
         */
        if((this->getTransformation().getRotation()+T.getRotation())<3.14){
            qDebug("Constraint: %f",this->getTransformation().getRotation()+T.getRotation());
            return true;
        }
        return false;
    }
};
class Bone_Shoulder_R : public Joint
{
public:
    Bone_Shoulder_R(GLuint vb0, GLuint program, GLint attrib1, GLint attrib2 , int w, int h, int id) : Joint(vb0,program,attrib1,attrib2, w,h, id){
        this->loadTexture();
    }
    virtual ~Bone_Shoulder_R(){}

    void init(){
    }
    void createVertices();
    void drawGraphic();
    void loadTexture();
    bool checkConstraints(Transformation T){
        /*
         * To be implemented Correctly
         */
        if((this->getTransformation().getRotation()+T.getRotation())<3.14){
            qDebug("Constraint: %f",this->getTransformation().getRotation()+T.getRotation());
            return true;
        }
        return false;
    }
};
class Bone_Elbow_L : public Joint
{
public:
    Bone_Elbow_L(GLuint vb0, GLuint program, GLint attrib1, GLint attrib2 , int w, int h, int id) : Joint(vb0,program,attrib1,attrib2, w,h, id){
        this->loadTexture();
    }
    virtual ~Bone_Elbow_L(){}

    void init(){
    }
    void createVertices();
    void drawGraphic();
    void loadTexture();
    bool checkConstraints(Transformation T){
        /*
         * To be implemented Correctly
         */
        if((this->getTransformation().getRotation()+T.getRotation())<3.14){
            qDebug("Constraint: %f",this->getTransformation().getRotation()+T.getRotation());
            return true;
        }
        return false;
    }
};
class Bone_Elbow_R : public Joint
{
public:
    Bone_Elbow_R(GLuint vb0, GLuint program, GLint attrib1, GLint attrib2 , int w, int h, int id) : Joint(vb0,program,attrib1,attrib2, w,h, id){
        this->loadTexture();
    }
    virtual ~Bone_Elbow_R(){}

    void init(){
    }
    void createVertices();
    void drawGraphic();
    void loadTexture();
    bool checkConstraints(Transformation T){
        /*
         * To be implemented Correctly
         */
        if((this->getTransformation().getRotation()+T.getRotation())<3.14){
            qDebug("Constraint: %f",this->getTransformation().getRotation()+T.getRotation());
            return true;
        }
        return false;
    }
};
class Bone_Wrist_L : public Joint
{
public:
    Bone_Wrist_L(GLuint vb0, GLuint program, GLint attrib1, GLint attrib2 , int w, int h, int id) : Joint(vb0,program,attrib1,attrib2, w,h, id){
        this->loadTexture();
    }
    virtual ~Bone_Wrist_L(){}

    void init(){
    }
    void createVertices();
    void drawGraphic();
    void loadTexture();
    bool checkConstraints(Transformation T){
        /*
         * To be implemented Correctly
         */
        if((this->getTransformation().getRotation()+T.getRotation())<3.14){
            qDebug("Constraint: %f",this->getTransformation().getRotation()+T.getRotation());
            return true;
        }
        return false;
    }
};
class Bone_Wrist_R : public Joint
{
public:
    Bone_Wrist_R(GLuint vb0, GLuint program, GLint attrib1, GLint attrib2 , int w, int h, int id) : Joint(vb0,program,attrib1,attrib2, w,h, id){
        this->loadTexture();
    }
    virtual ~Bone_Wrist_R(){}

    void init(){
    }
    void createVertices();
    void drawGraphic();
    void loadTexture();
    bool checkConstraints(Transformation T){
        /*
         * To be implemented Correctly
         */
        if((this->getTransformation().getRotation()+T.getRotation())<3.14){
            qDebug("Constraint: %f",this->getTransformation().getRotation()+T.getRotation());
            return true;
        }
        return false;
    }
};
class Bone_Hand_L : public Joint
{
public:
    Bone_Hand_L(GLuint vb0, GLuint program, GLint attrib1, GLint attrib2 , int w, int h, int id) : Joint(vb0,program,attrib1,attrib2, w,h, id){
        this->loadTexture();
    }
    virtual ~Bone_Hand_L(){}

    void init(){
    }
    void createVertices();
    void drawGraphic();
    void loadTexture();
    bool checkConstraints(Transformation T){
        /*
         * To be implemented Correctly
         */
        if((this->getTransformation().getRotation()+T.getRotation())<3.14){
            qDebug("Constraint: %f",this->getTransformation().getRotation()+T.getRotation());
            return true;
        }
        return false;
    }
};
class Bone_Hand_R : public Joint
{
public:
    Bone_Hand_R(GLuint vb0, GLuint program, GLint attrib1, GLint attrib2 , int w, int h, int id) : Joint(vb0,program,attrib1,attrib2, w,h, id){
        this->loadTexture();
    }
    virtual ~Bone_Hand_R(){}

    void init(){
    }
    void createVertices();
    void drawGraphic();
    void loadTexture();
    bool checkConstraints(Transformation T){
        /*
         * To be implemented Correctly
         */
        if((this->getTransformation().getRotation()+T.getRotation())<3.14){
            qDebug("Constraint: %f",this->getTransformation().getRotation()+T.getRotation());
            return true;
        }
        return false;
    }
};
class Bone_Hip_L : public Joint
{
public:
    Bone_Hip_L(GLuint vb0, GLuint program, GLint attrib1, GLint attrib2 , int w, int h, int id) : Joint(vb0,program,attrib1,attrib2, w,h, id){
        this->loadTexture();
    }
    virtual ~Bone_Hip_L(){}

    void init(){
    }
    void createVertices();
    void drawGraphic();
    void loadTexture();
    bool checkConstraints(Transformation T){
        /*
         * To be implemented Correctly
         */
        if((this->getTransformation().getRotation()+T.getRotation())<3.14){
            qDebug("Constraint: %f",this->getTransformation().getRotation()+T.getRotation());
            return true;
        }
        return false;
    }
};
class Bone_Hip_R : public Joint
{
public:
    Bone_Hip_R(GLuint vb0, GLuint program, GLint attrib1, GLint attrib2 , int w, int h, int id) : Joint(vb0,program,attrib1,attrib2, w,h, id){
        this->loadTexture();
    }
    virtual ~Bone_Hip_R(){}

    void init(){
    }
    void createVertices();
    void drawGraphic();
    void loadTexture();
    bool checkConstraints(Transformation T){
        /*
         * To be implemented Correctly
         */
        if((this->getTransformation().getRotation()+T.getRotation())<3.14){
            qDebug("Constraint: %f",this->getTransformation().getRotation()+T.getRotation());
            return true;
        }
        return false;
    }
};
class Bone_Knee_L : public Joint
{
public:
    Bone_Knee_L(GLuint vb0, GLuint program, GLint attrib1, GLint attrib2 , int w, int h, int id) : Joint(vb0,program,attrib1,attrib2, w,h, id){
        this->loadTexture();
    }
    virtual ~Bone_Knee_L(){}

    void init(){
    }
    void createVertices();
    void drawGraphic();
    void loadTexture();
    bool checkConstraints(Transformation T){
        /*
         * To be implemented Correctly
         */
        if((this->getTransformation().getRotation()+T.getRotation())<3.14){
            qDebug("Constraint: %f",this->getTransformation().getRotation()+T.getRotation());
            return true;
        }
        return false;
    }
};
class Bone_Knee_R : public Joint
{
public:
    Bone_Knee_R(GLuint vb0, GLuint program, GLint attrib1, GLint attrib2 , int w, int h, int id) : Joint(vb0,program,attrib1,attrib2, w,h, id){
        this->loadTexture();
    }
    virtual ~Bone_Knee_R(){}

    void init(){
    }
    void createVertices();
    void drawGraphic();
    void loadTexture();
    bool checkConstraints(Transformation T){
        /*
         * To be implemented Correctly
         */
        if((this->getTransformation().getRotation()+T.getRotation())<3.14){
            qDebug("Constraint: %f",this->getTransformation().getRotation()+T.getRotation());
            return true;
        }
        return false;
    }
};
class Bone_Ankle_L : public Joint
{
public:
    Bone_Ankle_L(GLuint vb0, GLuint program, GLint attrib1, GLint attrib2 , int w, int h, int id) : Joint(vb0,program,attrib1,attrib2, w,h, id){
        this->loadTexture();
    }
    virtual ~Bone_Ankle_L(){}

    void init(){
    }
    void createVertices();
    void drawGraphic();
    void loadTexture();
    bool checkConstraints(Transformation T){
        /*
         * To be implemented Correctly
         */
        if((this->getTransformation().getRotation()+T.getRotation())<3.14){
            qDebug("Constraint: %f",this->getTransformation().getRotation()+T.getRotation());
            return true;
        }
        return false;
    }
};
class Bone_Ankle_R : public Joint
{
public:
    Bone_Ankle_R(GLuint vb0, GLuint program, GLint attrib1, GLint attrib2 , int w, int h, int id) : Joint(vb0,program,attrib1,attrib2, w,h, id){
        this->loadTexture();
    }
    virtual ~Bone_Ankle_R(){}

    void init(){
    }
    void createVertices();
    void drawGraphic();
    void loadTexture();
    bool checkConstraints(Transformation T){
        /*
         * To be implemented Correctly
         */
        if((this->getTransformation().getRotation()+T.getRotation())<3.14){
            qDebug("Constraint: %f",this->getTransformation().getRotation()+T.getRotation());
            return true;
        }
        return false;
    }
};
class Bone_Foot_L : public Joint
{
public:
    Bone_Foot_L(GLuint vb0, GLuint program, GLint attrib1, GLint attrib2 , int w, int h, int id) : Joint(vb0,program,attrib1,attrib2, w,h, id){
        this->loadTexture();
    }
    virtual ~Bone_Foot_L(){}

    void init(){
    }
    void createVertices();
    void drawGraphic();
    void loadTexture();
    bool checkConstraints(Transformation T){
        /*
         * To be implemented Correctly
         */
        if((this->getTransformation().getRotation()+T.getRotation())<3.14){
            qDebug("Constraint: %f",this->getTransformation().getRotation()+T.getRotation());
            return true;
        }
        return false;
    }
};
class Bone_Foot_R : public Joint
{
public:
    Bone_Foot_R(GLuint vb0, GLuint program, GLint attrib1, GLint attrib2 , int w, int h, int id) : Joint(vb0,program,attrib1,attrib2, w,h, id){
        this->loadTexture();
    }
    virtual ~Bone_Foot_R(){}

    void init(){
    }
    void createVertices();
    void drawGraphic();
    void loadTexture();
    bool checkConstraints(Transformation T){
        /*
         * To be implemented Correctly
         */
        if((this->getTransformation().getRotation()+T.getRotation())<3.14){
            qDebug("Constraint: %f",this->getTransformation().getRotation()+T.getRotation());
            return true;
        }
        return false;
    }
};



class Bone_Head : public Joint
{
public:
    Bone_Head (GLuint vb0, GLuint program, GLint attrib1, GLint attrib2 , int w, int h, int id) : Joint(vb0,program,attrib1,attrib2, w,h, id){
        this->loadTexture();
    }
    virtual ~Bone_Head (){}

    void init(){
    }
    void createVertices();
    void drawGraphic();
    void loadTexture();
    bool checkConstraints(Transformation T){
        /*
         * To be implemented Correctly
         */
        if((this->getTransformation().getRotation()+T.getRotation())<3.14){
            qDebug("Constraint: %f",this->getTransformation().getRotation()+T.getRotation());
            return true;
        }
        return false;
    }
};

#endif
