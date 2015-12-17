/*
 * CG Major Project, Monsoon 2015
 * Author: Sarthak Ahuja, 2012088 | IIIT-Delhi
 *
 * Description:
 */

#include "Joint.h"
#include "qmessagebox.h"

/*
 * Simple Multiplication with Transformation Matrix
 */
void Joint::transform(Transformation T){
    float tempx,tempy,tempx1,tempy1;
    if(this->getParent()==NULL){
        QMessageBox msgBox;
                msgBox.setText("Parent");
                //msgBox.exec();
        tempx=0;
        tempy=0;
    }
    else{
    if(debug) qDebug("Debug: 'Initial: %f %f'",this->getParent()->getTip().x(),this->getParent()->getTip().y() );
    //if(debug) qDebug("Debug: 'Initial: %f %f'",J->getTip().x(),J->getTip().y() );
    tempx=this->getTip().x()-this->getParent()->getTip().x();
    tempy=this->getTip().y()-this->getParent()->getTip().y();

    }
    //if(debug) qDebug("Debug: 'Initial: %f %f'",tempx,tempy );
    glm::mat3 matT =T.generateModel();
    tempx1=matT[0][0]*tempx+matT[0][1]*tempy+matT[0][2];
    tempy1=matT[1][0]*tempx+matT[1][1]*tempy+matT[1][2];
    QPointF newPoint;
    if(this->getParent()==NULL){
        newPoint.setX(tempx1);
        newPoint.setY(tempy1);
    }
    else{
        newPoint.setX(tempx1+this->getParent()->getTip().x());
        newPoint.setY(tempy1+this->getParent()->getTip().y());

    }
    if(debug) qDebug("Debug: 'Final: %f %f'",newPoint.x(),newPoint.y());
    this->setTip(newPoint);
}

void Joint::transformAbout(Transformation T, Joint* J){
    /*
     * Bring to Origin, Transform, Send Back
     */

    float tempx,tempy,tempx1,tempy1;
    if(J->getParent()==NULL){
        tempx=this->getTip().x();
        tempy=this->getTip().y();
        QMessageBox msgBox;
                msgBox.setText("Around Center");
                //msgBox.exec();
    }
    else{
        QMessageBox msgBox;
                msgBox.setText("Child");
                //msgBox.exec();
        if(debug) qDebug("Debug: 'Initial: %f %f'",J->getParent()->getTip().x(),J->getParent()->getTip().y() );
        //if(debug) qDebug("Debug: 'Initial: %f %f'",J->getTip().x(),J->getTip().y() );
        tempx=this->getTip().x()-J->getParent()->getTip().x();
        tempy=this->getTip().y()-J->getParent()->getTip().y();

    }
    if(debug) qDebug("Debug: 'Initial: %f %f'",tempx,tempy );
    glm::mat3 matT =T.generateModel();
    tempx1=matT[0][0]*tempx+matT[0][1]*tempy+matT[0][2];
    tempy1=matT[1][0]*tempx+matT[1][1]*tempy+matT[1][2];
    QPointF newPoint;
    if(J->getParent()==NULL){
        newPoint.setX(tempx1);
        newPoint.setY(tempy1);
    }
    else{
        newPoint.setX(tempx1+J->getParent()->getTip().x());
        newPoint.setY(tempy1+J->getParent()->getTip().y());
        if(debug) qDebug("Debug: 'Final: %f %f'",newPoint.x(),newPoint.y());
    }
    QMessageBox msgBox;
            msgBox.setText("Check");
            //msgBox.exec();
    this->setTip(newPoint);
    for(int i=0;i<this->getChildren().size();i++){
        Joint* child;
        child=this->getChildren().at(i);
        if(debug) qDebug("Debug: 'Child: %d'",child->getID());
        child->transformAbout(T,J);
    }

}
