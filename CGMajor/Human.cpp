/*
 * CG Major Project, Monsoon 2015
 * Author: Sarthak Ahuja, 2012088 | IIIT-Delhi
 *
 * Description:
 */

#include "Human.h"
#include "Human_Joints.h"
#include "glm/glm.hpp"
#include "vector3D.h"
#include "QMessageBox"
#include <string>
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

/*
 * Setup the Human Body
 */
Human::Human(GLuint program, GLint attribute_coord2d, GLuint vbo_triangle, GLint attribute_v_color,int w, int h)
{
    /*
     * Initialize Joints
     */
    Joint* joint_elbow_l = new Bone_Elbow_L(program, attribute_coord2d, vbo_triangle, attribute_v_color,w, h, ELBOW_L);
    body.push_back(joint_elbow_l);
    Joint* joint_elbow_r = new Bone_Elbow_R(program, attribute_coord2d, vbo_triangle, attribute_v_color,w, h, ELBOW_R);
    body.push_back(joint_elbow_r);

    Joint* joint_shoulder_r = new Bone_Shoulder_R(program, attribute_coord2d, vbo_triangle, attribute_v_color,w, h, SHOULDER_R);
    body.push_back(joint_shoulder_r);
    Joint* joint_shoulder_l = new Bone_Shoulder_L(program, attribute_coord2d, vbo_triangle, attribute_v_color,w, h, SHOULDER_L);
    body.push_back(joint_shoulder_l);
    Joint* joint_foot_l = new Bone_Foot_L(program, attribute_coord2d, vbo_triangle, attribute_v_color,w, h, FOOT_L);
    body.push_back(joint_foot_l);
    Joint* joint_foot_r = new Bone_Foot_R(program, attribute_coord2d, vbo_triangle, attribute_v_color,w, h, FOOT_R);
    body.push_back(joint_foot_r);
    Joint* joint_hip_r = new Bone_Hip_R(program, attribute_coord2d, vbo_triangle, attribute_v_color,w, h, HIP_R);
    body.push_back(joint_hip_r);
    Joint* joint_hip_l = new Bone_Hip_L(program, attribute_coord2d, vbo_triangle, attribute_v_color,w, h, HIP_L);
    body.push_back(joint_hip_l);

    Joint* joint_ankle_l = new Bone_Ankle_L(program, attribute_coord2d, vbo_triangle, attribute_v_color,w, h, ANKLE_L);
    body.push_back(joint_ankle_l);
    Joint* joint_ankle_r = new Bone_Ankle_R(program, attribute_coord2d, vbo_triangle, attribute_v_color,w, h, ANKLE_R);
    body.push_back(joint_ankle_r);
    Joint* joint_knee_l = new Bone_Knee_L(program, attribute_coord2d, vbo_triangle, attribute_v_color,w, h, KNEE_L);
    body.push_back(joint_knee_l);
    Joint* joint_knee_r = new Bone_Knee_R(program, attribute_coord2d, vbo_triangle, attribute_v_color,w, h, KNEE_R);
    body.push_back(joint_knee_r);
    Joint* joint_center = new Bone_Center(program, attribute_coord2d, vbo_triangle, attribute_v_color,w, h, CENTER);
    body.push_back(joint_center);
    Joint* joint_spine = new Bone_Spine(program, attribute_coord2d, vbo_triangle, attribute_v_color,w, h, SPINE);
    body.push_back(joint_spine);



    Joint* joint_collar = new Bone_Collar(program, attribute_coord2d, vbo_triangle, attribute_v_color,w, h, COLLAR);
    body.push_back(joint_collar);

    Joint* joint_wrist_l = new Bone_Wrist_L(program, attribute_coord2d, vbo_triangle, attribute_v_color,w, h, WRIST_L);
    body.push_back(joint_wrist_l);
    Joint* joint_wrist_r = new Bone_Wrist_R(program, attribute_coord2d, vbo_triangle, attribute_v_color,w, h, WRIST_R);
    body.push_back(joint_wrist_r);
    Joint* joint_hand_l = new Bone_Hand_L(program, attribute_coord2d, vbo_triangle, attribute_v_color,w, h, HAND_L);
    body.push_back(joint_hand_l);
    Joint* joint_hand_r = new Bone_Hand_R(program, attribute_coord2d, vbo_triangle, attribute_v_color,w, h, HAND_R);
    body.push_back(joint_hand_r);




    Joint* joint_head = new Bone_Head(program, attribute_coord2d, vbo_triangle, attribute_v_color,w, h, HEAD);
    body.push_back(joint_head);

    /*
     * Set Parents
     */
    joint_center->setParent(NULL);
    joint_spine->setParent(joint_center);
    joint_head->setParent(joint_collar);
    joint_collar->setParent(joint_spine);
    joint_hip_l->setParent(joint_center);
    joint_hip_r->setParent(joint_center);
    joint_knee_l->setParent(joint_hip_l);
    joint_knee_r->setParent(joint_hip_r);
    joint_ankle_l->setParent(joint_knee_l);
    joint_ankle_r->setParent(joint_knee_r);
    joint_foot_l->setParent(joint_ankle_l);
    joint_foot_r->setParent(joint_ankle_r);
    joint_shoulder_l->setParent(joint_collar);
    joint_shoulder_r->setParent(joint_collar);
    joint_elbow_l->setParent(joint_shoulder_l);
    joint_elbow_r->setParent(joint_shoulder_r);
    joint_wrist_l->setParent(joint_elbow_l);
    joint_wrist_r->setParent(joint_elbow_r);
    joint_hand_l->setParent(joint_wrist_l);
    joint_hand_r->setParent(joint_wrist_r);

    /*
     * Set Children
     */
    std::vector<Joint*> center_children;
    center_children.push_back(joint_spine);
    center_children.push_back(joint_hip_l);
    center_children.push_back(joint_hip_r);
    joint_center->setChildren(center_children);
    std::vector<Joint*> spine_children;
    spine_children.push_back(joint_collar);
    joint_spine->setChildren(spine_children);
    std::vector<Joint*> collar_children;
    collar_children.push_back(joint_head);
    collar_children.push_back(joint_shoulder_l);
    collar_children.push_back(joint_shoulder_r);
    joint_collar->setChildren(collar_children);
    std::vector<Joint*> head_children;
    joint_head->setChildren(head_children);
    std::vector<Joint*> shoulder_l_children;
    shoulder_l_children.push_back(joint_elbow_l);
    joint_shoulder_l->setChildren(shoulder_l_children);
    std::vector<Joint*> elbow_l_children;
    elbow_l_children.push_back(joint_wrist_l);
    joint_elbow_l->setChildren(elbow_l_children);
    std::vector<Joint*> wrist_l_children;
    wrist_l_children.push_back(joint_hand_l);
    joint_wrist_l->setChildren(wrist_l_children);
    std::vector<Joint*> hand_l_children;
    joint_hand_l->setChildren(hand_l_children);
    std::vector<Joint*> shoulder_r_children;
    shoulder_r_children.push_back(joint_elbow_r);
    joint_shoulder_r->setChildren(shoulder_r_children);
    std::vector<Joint*> elbow_r_children;
    elbow_r_children.push_back(joint_wrist_r);
    joint_elbow_r->setChildren(elbow_r_children);
    std::vector<Joint*> wrist_r_children;
    wrist_r_children.push_back(joint_hand_r);
    joint_wrist_r->setChildren(wrist_r_children);
    std::vector<Joint*> hand_r_children;
    joint_hand_r->setChildren(hand_r_children);
    std::vector<Joint*> hip_l_children;
    hip_l_children.push_back(joint_knee_l);
    joint_hip_l->setChildren(hip_l_children);
    std::vector<Joint*> knee_l_children;
    knee_l_children.push_back(joint_ankle_l);
    joint_knee_l->setChildren(knee_l_children);
    std::vector<Joint*> ankle_l_children;
    ankle_l_children.push_back(joint_foot_l);
    joint_ankle_l->setChildren(ankle_l_children);
    std::vector<Joint*> foot_l_children;
    joint_foot_l->setChildren(foot_l_children);
    std::vector<Joint*> hip_r_children;
    hip_r_children.push_back(joint_knee_r);
    joint_hip_r->setChildren(hip_r_children);
    std::vector<Joint*> knee_r_children;
    knee_r_children.push_back(joint_ankle_r);
    joint_knee_r->setChildren(knee_r_children);
    std::vector<Joint*> ankle_r_children;
    ankle_r_children.push_back(joint_foot_r);
    joint_ankle_r->setChildren(ankle_r_children);
    std::vector<Joint*> foot_r_children;
    joint_foot_r->setChildren(foot_r_children);

    /*
     * Mark Tips Range is [-1,1]
     *          |
     *      ----|----
     *          |
     *         / \
     *        /   \
     *      -/     \-
     */
    QPointF center_tip;
    center_tip.setX(0);
    center_tip.setY(-0.05);
    joint_center->setTip(center_tip);
    QPointF spine_tip;
    spine_tip.setX(0);
    spine_tip.setY(0.3);
    joint_spine->setTip(spine_tip);
    QPointF collar_tip;
    collar_tip.setX(0);
    collar_tip.setY(0.8);
    joint_collar->setTip(collar_tip);
    QPointF head_tip;
    head_tip.setX(0);
    head_tip.setY(0.9);
    joint_head->setTip(head_tip);
    QPointF shoulder_l_tip;
    shoulder_l_tip.setX(-0.4);
    shoulder_l_tip.setY(0.8);
    joint_shoulder_l->setTip(shoulder_l_tip);
    QPointF elbow_l_tip;
    elbow_l_tip.setX(-0.42);
    elbow_l_tip.setY(0.3);
    joint_elbow_l->setTip(elbow_l_tip);
    QPointF wrist_l_tip;
    wrist_l_tip.setX(-0.6);
    wrist_l_tip.setY(-0.1);
    joint_wrist_l->setTip(wrist_l_tip);
    QPointF hand_l_tip;
    hand_l_tip.setX(-0.68);
    hand_l_tip.setY(-0.44);
    joint_hand_l->setTip(hand_l_tip);
    QPointF shoulder_r_tip;
    shoulder_r_tip.setX(0.4);
    shoulder_r_tip.setY(0.8);
    joint_shoulder_r->setTip(shoulder_r_tip);
    QPointF elbow_r_tip;
    elbow_r_tip.setX(0.42);
    elbow_r_tip.setY(0.3);
    joint_elbow_r->setTip(elbow_r_tip);
    QPointF wrist_r_tip;
    wrist_r_tip.setX(0.6);
    wrist_r_tip.setY(-0.1);
    joint_wrist_r->setTip(wrist_r_tip);
    QPointF hand_r_tip;
    hand_r_tip.setX(0.68);
    hand_r_tip.setY(-0.44);
    joint_hand_r->setTip(hand_r_tip);
    QPointF hip_l_tip;
    hip_l_tip.setX(-0.16);
    hip_l_tip.setY(-0.1);
    joint_hip_l->setTip(hip_l_tip);
    QPointF knee_l_tip;
    knee_l_tip.setX(-0.22);
    knee_l_tip.setY(-0.58);
    joint_knee_l->setTip(knee_l_tip);
    QPointF ankle_l_tip;
    ankle_l_tip.setX(-0.3);
    ankle_l_tip.setY(-0.9);
    joint_ankle_l->setTip(ankle_l_tip);
    QPointF foot_l_tip;
    foot_l_tip.setX(-0.38);
    foot_l_tip.setY(-0.95);
    joint_foot_l->setTip(foot_l_tip);
    QPointF hip_r_tip;
    hip_r_tip.setX(0.16);
    hip_r_tip.setY(-0.1);
    joint_hip_r->setTip(hip_r_tip);
    QPointF knee_r_tip;
    knee_r_tip.setX(0.22);
    knee_r_tip.setY(-0.58);
    joint_knee_r->setTip(knee_r_tip);
    QPointF ankle_r_tip;
    ankle_r_tip.setX(0.3);
    ankle_r_tip.setY(-0.9);
    joint_ankle_r->setTip(ankle_r_tip);
    QPointF foot_r_tip;
    foot_r_tip.setX(0.38);
    foot_r_tip.setY(-0.95);
    joint_foot_r->setTip(foot_r_tip);

    prev_len=-1;
    prev_x=-1;
    prev_y=-1;
    this->jointTree=joint_center;
}

int Human::getAnchor(){
    return this->anchor;
}

void Human::setAnchor(int anchor){
    this->anchor=anchor;
}

/*
 * Move Joint and all it's children by a certain angle
 */
void Human::moveJoint(Transformation T){
    if(debug) qDebug("Debug: '%s'", "Moving Joint");
    Joint* Anchor = findJoint(jointTree,this->getAnchor());
    if(Anchor!=NULL){
        if(debug) qDebug("Anchor ID: '%d'", Anchor->getID());
        if(Anchor->checkConstraints(T)){
            updatePose(T);
            QMessageBox msgBox;
            msgBox.setText(patch::to_string(Anchor->getID()).c_str());
            //msgBox.exec();
            //updatePose(T);
            Anchor->transform(T);
            for(int i=0;i<Anchor->getChildren().size();i++){
                QMessageBox msgBox;
                msgBox.setText(patch::to_string("KIDS").c_str());
                //msgBox.exec();
                if(debug) qDebug("Debug: '%s'", "Moving Joint");
                Joint* child=Anchor->getChildren()[i];
                if(debug) qDebug("Debug: '%s'", "Moving Joint");
                if(debug) qDebug("Debug: 'Anchor: %f %f'", Anchor->getTip().x(),Anchor->getTip().y());
                child->transformAbout(T,Anchor);
                if(debug) qDebug("Debug: '%s'", "Moving Joint");
            }
        }
    }
}

void Human::moveJointUniform(Transformation T){
    if(debug) qDebug("Debug: '%s'", "Moving Joint Uniformly");
    for(int i=0;i<body.size();i++){
            Joint* joint=body[i];
            joint->transform(T);
    }
}

/*
 * Find a joint
 */
Joint* Human::findJoint(Joint* root,int id){
    if(root->getID()==id){
        return root;
    }
    else{
        if(root->getChildren().size()>0){
            for(int i=0;i<root->getChildren().size();i++){
                Joint* temp=this->findJoint(root->getChildren().at(i),id);
                if(temp!=NULL){
                    return temp;
                }
            }
            return NULL;
        }
        else{
            return NULL;
        }
    }
}

void Human::updatePose(Transformation T){
    if(debug) qDebug("Debug: '%s'", "Updating Pose");
    Joint* Anchor = findJoint(jointTree,this->getAnchor());
    if(Anchor!=NULL){
        if(debug) qDebug("Debug: '%s'", "Updating Pose");
        double theta = T.getRotation();
        double scale = T.getScale();
        double x=T.getX();
        double y=T.getY();
        Anchor->T.setRotation(Anchor->T.getRotation()+theta);
        Anchor->T.setScale(Anchor->T.getScale()*scale);
        Anchor->T.setTranslationX(Anchor->T.getX()+x);
        Anchor->T.setTranslationY(Anchor->T.getY()+y);
        if(debug) qDebug("Debug: '%s'", "Updating Pose");
    }
}

void Human::draw(Joint* root){
    if(debug) qDebug("Debug: '%s'", "Debugging...");

    //Display Kinect Data
    for(int i=0;i<body.size();i++){
        Joint* joint=body[i];
        joint->createVertices();
        joint->drawGraphic();
    }
//    if(root->getChildren().size()>0){
//        if(debug) qDebug("Debug: '%s'", "Debugging...");
//        for(int i=0;i<root->getChildren().size();i++){
//            if(debug) qDebug("Debug: '%s'", "Debugging...");
//            Joint* child=root->getChildren().at(i);
//            draw(child);
//        }
//    }

}

Transformation Human::findT(){
    int anchorId=this->getAnchor();
    Joint* j=this->findJoint(this->jointTree,anchorId);

    int parentId=j->getParent()->getID();

    double kinect_x_parent,kinect_y_parent;
    double kinect_x_anchor,kinect_y_anchor;

    std::pair<double,double> kinect_parent=Rigging.at(parentId);
    std::pair<double,double> kinect_anchor=Rigging.at(anchorId);

    //Bring to Origin
    kinect_x_anchor=kinect_anchor.first-0.5;
    kinect_y_anchor=-kinect_anchor.second+0.5;
    kinect_x_parent=kinect_parent.first-0.5;
    kinect_y_parent=-kinect_parent.second+0.5;

    double x_parent,y_parent;
    double x_anchor,y_anchor;

    x_parent=j->getParent()->getTip().x();
    y_parent=j->getParent()->getTip().y();
    x_anchor=j->getTip().x();
    y_anchor=j->getTip().y();

    Vector3D kinect(kinect_x_anchor-kinect_x_parent,kinect_y_anchor-kinect_y_parent,0);
    Vector3D me(x_anchor-x_parent,y_anchor-y_parent,0);

    kinect.normalize();
    me.normalize();

    double dp = dotProduct(kinect,me);

    double angle = acos(dp);
    Vector3D cross = crossProduct(kinect, me);
    Vector3D Vn(0,0,1);
    if (dotProduct(Vn, cross) > 0) { // Or > 0
      angle = -angle;
    }
    if(debug) qDebug("Debug: 'Angle: %f'",angle);

    Transformation T;
    T.setRotation(angle);
    return T;
}

void Human::performRigging(std::map<int,std::pair<double,double> > Rigging){
    this->Rigging=Rigging;
}


void Human::matchSkeleton(Joint* root){

    if(debug) qDebug("Debug: '%s'", "Debugging...");
    if(root->getID()==1){
        if(debug) qDebug("New Incoming Frame: '%s'", "Yo");
        for(int i=1;i<21;i++){

            if(debug) qDebug("Debug: '%d %f %f'",i, Rigging.at(i).first,Rigging.at(i).second);
        }
        double new_x=Rigging.at(1).first;
        double new_y=Rigging.at(1).second;
        double new_len=Rigging.at(17).first-Rigging.at(13).first;
        if(prev_len==-1 || prev_x==-1 || prev_y==-1){
            prev_len=new_len;
            prev_x=new_x;
            prev_y=new_y;
        }
        this->setAnchor(root->getID());
        QMessageBox msgBox;
        msgBox.setText(patch::to_string(new_x-prev_x).c_str());
        //msgBox.exec();
        Transformation T_;
        Transformation T__;
        T_.setScale(new_len/prev_len);
        T__.setTranslationX(new_x-prev_x);
        //T__.setTranslationY(new_y-prev_y);
        if(scalet){

        moveJointUniform(T__);
        moveJointUniform(T_);
        }
        prev_len=new_len;
        prev_x=new_x;
    }
    else{
//        QMessageBox msgBox;
//        msgBox.setText("On a Joint");
//        msgBox.exec();
        this->setAnchor(root->getID());
        Transformation T_=findT();
        if(interpolat==true){
            double theta_i=T_.getRotation()/INTERPOLATION;
            for(int i=0;i<INTERPOLATION;i++){
                Transformation* Ti=new Transformation();
                Ti->setRotation(theta_i);
                moveJoint(*Ti);
            }
        }
        else{
            moveJoint(T_);
        }
    }
    if(root->getChildren().size()>0){
        if(debug) qDebug("Debug: '%s'", "Debugging...");
        for(int i=0;i<root->getChildren().size();i++){
            if(debug) qDebug("Debug: '%s'", "Debugging...");
            Joint* child=root->getChildren().at(i);
            matchSkeleton(child);
        }
    }
}


//void Human::matchSkeleton(Joint* root){
//    if(debug) qDebug("New Incoming Frame: '%s'", "Yo");
//    for(int i=1;i<21;i++){
//        if(debug) qDebug("Debug: '%d %f %f'",i, Rigging.at(i).first,Rigging.at(i).second);
//        Joint* j=findJoint(root,i);
//        QPointF p;

//        j->setTip(p);
//    }
//}

