/*
 * CG Major Project, Monsoon 2015
 * Author: Sarthak Ahuja, 2012088 | IIIT-Delhi
 *
 * Description:
 */

#ifndef HUMAN_H
#define HUMAN_H

#include<Joint.h>
#include<map>
#include<Character.h>

enum HUMAN_JOINT_ID
{
    NONE=-1,
    CENTER=1,
    HIP_R=17,
    HIP_L=13,
    SPINE=2,
    KNEE_L=14,
    KNEE_R=18,
    COLLAR=3,
    ANKLE_L=15,
    ANKLE_R=19,
    SHOULDER_L=5,
    SHOULDER_R=9,
    HEAD=4,
    FOOT_L=16,
    FOOT_R=20,
    ELBOW_L=6,
    ELBOW_R=10,
    WRIST_L=7,
    WRIST_R=11,
    HAND_L=8,
    HAND_R=12
};

class Human : public Character
{
protected:
    bool debug=false;
    int anchor;
    double prev_len;
    double prev_x;
    double prev_y;
    double INTERPOLATION=7;
    bool scalet=false;
    bool interpolat=false;
public:
    Joint* jointTree;

    std::map<int,std::pair<double,double> > Rigging;
    std::vector<Joint*> body;
    Human(GLuint program, GLint attribute_coord2d, GLuint vbo_triangle, GLint attribute_v_color, int w, int h);
    void performRigging(std::map<int,std::pair<double,double> > Rigging);
    void matchSkeleton(Joint* root);
    int getAnchor();
    void setAnchor(int);
    std::vector<Joint*>getBody(){
        return body;
    }
    Transformation findT();
    void moveJoint(Transformation T);
    void moveJointUniform(Transformation T);
    void updatePose(Transformation T);
    void draw(Joint* root);
    Joint* findJoint(Joint*, int);
    void setInterp(bool a){
        interpolat=a;
    }
    void setScaleT(bool a){
        scalet=a;
    }
};

#endif // HUMAN_H
