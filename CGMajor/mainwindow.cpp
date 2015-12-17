/*
 * CG Major Project, Monsoon 2015
 * Author: Sarthak Ahuja, 2012088 | IIIT-Delhi
 *
 * Description:
 */

#include "mainwindow.h"
#include <qcolordialog.h>
#include "ui_mainwindow.h"
#include <qmessagebox.h>
#include <string.h>
#include <fstream>
#include <iostream>


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupWidgets();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setAnchor()
{
    if (B_ANKLE_L->isChecked())
    {
        if(debug) qDebug("Deubg: '%s'", "Left Ankle!");
        scene->human->setAnchor(ANKLE_L);
    }
    else if (B_HIP_L->isChecked())
    {
        if(debug) qDebug("Deubg: '%s'", "Left HIP!");
        scene->human->setAnchor(HIP_L);

    }
    else if (B_HIP_R->isChecked())
    {
        if(debug) qDebug("Deubg: '%s'", "Right HIP!");
        scene->human->setAnchor(HIP_R);

    }
    else if (B_HEAD->isChecked())
    {
        if(debug) qDebug("Deubg: '%s'", "HEAD!");
        scene->human->setAnchor(HEAD);

    }
    else if (B_SHOULDER_L->isChecked())
    {
        if(debug) qDebug("Deubg: '%s'", "Left Shoulder!");
        scene->human->setAnchor(SHOULDER_L);

    }
    else if (B_SHOULDER_R->isChecked())
    {
        if(debug) qDebug("Deubg: '%s'", "Right Shoulder!");
        scene->human->setAnchor(SHOULDER_R);

    }
    else if (B_ANKLE_R->isChecked())
    {
        if(debug) qDebug("Deubg: '%s'", "Right Ankle!");
        scene->human->setAnchor(ANKLE_R);
    }
    else if (B_FOOT_L->isChecked())
    {
        if(debug) qDebug("Deubg: '%s'", "Left Foot!");
        scene->human->setAnchor(FOOT_L);

    }
    else if (B_FOOT_R->isChecked())
    {
        if(debug) qDebug("Deubg: '%s'", "Right Foot!");
        scene->human->setAnchor(FOOT_R);

    }
    else if (B_CENTER->isChecked())
    {
        if(debug) qDebug("Deubg: '%s'", "Center!");
        scene->human->setAnchor(CENTER);

    }
    else if (B_SPINE->isChecked())
    {
        if(debug) qDebug("Deubg: '%s'", "Spine!");
        scene->human->setAnchor(SPINE);

    }
    else if (B_COLLAR->isChecked())
    {
        if(debug) qDebug("Deubg: '%s'", "Collar!");
        scene->human->setAnchor(COLLAR);

    }
    else if (B_ELBOW_L->isChecked())
    {
        if(debug) qDebug("Deubg: '%s'", "Left Elbow!");
        scene->human->setAnchor(ELBOW_L);

    }
    else if (B_ELBOW_R->isChecked())
    {
        if(debug) qDebug("Deubg: '%s'", "Right Elbow!");
        scene->human->setAnchor(ELBOW_R);

    }
    else if (B_KNEE_L->isChecked())
    {
        if(debug) qDebug("Deubg: '%s'", "Left KNEE!");
        scene->human->setAnchor(KNEE_L);

    }
    else if (B_KNEE_R->isChecked())
    {
        if(debug) qDebug("Deubg: '%s'", "Right KNEE!");
        scene->human->setAnchor(KNEE_R);

    }
    else if (B_WRIST_L->isChecked())
    {
        if(debug) qDebug("Deubg: '%s'", "Left Wrist!");
        scene->human->setAnchor(WRIST_L);

    }
    else if (B_WRIST_R->isChecked())
    {
        if(debug) qDebug("Deubg: '%s'", "Right Wrist!");
        scene->human->setAnchor(WRIST_R);

    }

    else if (B_HAND_L->isChecked())
    {
        if(debug) qDebug("Deubg: '%s'", "Left Hand!");
        scene->human->setAnchor(HAND_L);

    }
    else if (B_HAND_R->isChecked())
    {
        if(debug) qDebug("Deubg: '%s'", "Right HAND!");
        scene->human->setAnchor(HAND_R);

    }
    else
    {
        if(debug) qDebug("Deubg: '%s'", "None!");
        scene->human->setAnchor(NONE);
    }
}

void MainWindow::checkButtons(int jointId){
    if(debug) qDebug("Deubg: '%d'", jointId);
    if(jointId==HEAD){
        //B_HEAD->setChecked(true);
    }
    else{
        B_HEAD->setChecked(false);
    }
    if(jointId==SPINE){
        //B_SPINE->setChecked(true);
    }
    else{
        B_SPINE->setChecked(false);
    }
    if(jointId==COLLAR){
        //B_COLLAR->setChecked(true);
    }
    else{
        B_COLLAR->setChecked(false);
    }
    if(jointId==CENTER){
        //B_CENTER->setChecked(true);
    }
    else{
        B_CENTER->setChecked(false);
    }
    if(jointId==SHOULDER_L){
        //B_SHOULDER_L->setChecked(true);
    }
    else{
        B_SHOULDER_L->setChecked(false);
    }
    if(jointId==SHOULDER_R){
        //B_SHOULDER_R->setChecked(true);
    }
    else{
        B_SHOULDER_R->setChecked(false);
    }
    if(jointId==ELBOW_L){
        //B_ELBOW_L->setChecked(true);
    }
    else{
        B_ELBOW_L->setChecked(false);
    }
    if(jointId==ELBOW_R){
        //B_ELBOW_R->setChecked(true);
    }
    else{
        B_ELBOW_R->setChecked(false);
    }
    if(jointId==WRIST_L){
       // B_WRIST_L->setChecked(true);
    }
    else{
        B_WRIST_L->setChecked(false);
    }
    if(jointId==WRIST_R){
        //B_WRIST_R->setChecked(true);
    }
    else{
        B_WRIST_R->setChecked(false);
    }
    if(jointId==HAND_L){
        //B_HAND_L->setChecked(true);
    }
    else{
        B_HAND_L->setChecked(false);
    }
    if(jointId==HAND_R){
        //B_HAND_R->setChecked(true);
    }
    else{
        B_HAND_R->setChecked(false);
    }
    if(jointId==HIP_L){
       // B_HIP_L->setChecked(true);
    }
    else{
        B_HIP_L->setChecked(false);
    }

    if(jointId==HIP_R){
        //B_HIP_R->setChecked(true);
    }
    else{
        B_HIP_R->setChecked(false);
    }
    if(jointId==KNEE_L){
        //B_KNEE_L->setChecked(true);
    }
    else{
        B_KNEE_L->setChecked(false);
    }
    if(jointId==KNEE_R){
       // B_KNEE_R->setChecked(true);
    }
    else{
        B_KNEE_R->setChecked(false);
    }
    if(jointId==ANKLE_L){
        //B_ANKLE_L->setChecked(true);
    }
    else{
        B_ANKLE_L->setChecked(false);
    }
    if(jointId==ANKLE_R){
        //B_ANKLE_R->setChecked(true);
    }
    else{
        B_ANKLE_R->setChecked(false);
    }
    if(jointId==FOOT_L){
        //B_FOOT_L->setChecked(true);
    }
    else{
        B_FOOT_L->setChecked(false);
    }
    if(jointId==FOOT_R){
        //B_FOOT_R->setChecked(true);
    }
    else{
        B_FOOT_R->setChecked(false);
    }
}

void MainWindow::setupWidgets()
{
    this->dataset=0;
    //Our Scene
    scene = ui->W_Scene;

    //Center
    B_CENTER = ui->CENTER;
    //Spine
    B_SPINE = ui->SPINE;
    //Collar
    B_COLLAR = ui->COLLAR;
    //Head
    B_HEAD = ui->HEAD;
    //Right Shoulder
    B_SHOULDER_R = ui->SHOULDER_R;
    //Right Elbow
    B_ELBOW_R = ui->ELBOW_R;
    //Right Wrist
    B_WRIST_R = ui->WRIST_R;
    //Right Hand
    B_HAND_R = ui->HAND_R;
    //Right Hip
    B_HIP_R = ui->HIP_R;
    //Right Knee
    B_KNEE_R = ui->KNEE_R;
    //Right Ankle
    B_ANKLE_R = ui->ANKLE_R;
    //Right Foot
    B_FOOT_R = ui->FOOT_R;
    //Left Shoulder
    B_SHOULDER_L = ui->SHOULDER_L;
    //Left Elbow
    B_ELBOW_L = ui->ELBOW_L;
    //Left Wrist
    B_WRIST_L = ui->WRIST_L;
    //Left Hand
    B_HAND_L = ui->HAND_L;
    //Left Hip
    B_HIP_L = ui->HIP_L;
    //Left Knee
    B_KNEE_L = ui->KNEE_L;
    //Left Ankle
    B_ANKLE_L = ui->ANKLE_L;
    //Left Foot
    B_FOOT_L = ui->FOOT_L;

    B_RUN = ui->RUN;

    B_LIVE=ui->LIVE;
    //setAnchor();
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_SHOULDER_L_clicked()
{
    checkButtons(SHOULDER_L);
    setAnchor();
}

void MainWindow::on_ELBOW_L_clicked()
{
    checkButtons(ELBOW_L);
    setAnchor();
}

void MainWindow::on_WRIST_L_clicked()
{
    checkButtons(WRIST_L);
    setAnchor();
}

void MainWindow::on_HAND_L_clicked()
{
    checkButtons(HAND_L);
    setAnchor();
}

void MainWindow::on_HIP_L_clicked()
{
    checkButtons(HIP_L);
    setAnchor();
}

void MainWindow::on_KNEE_L_clicked()
{
    checkButtons(KNEE_L);
    setAnchor();
}

void MainWindow::on_ANKLE_L_clicked()
{
    checkButtons(ANKLE_L);
    setAnchor();
}

void MainWindow::on_FOOT_L_clicked()
{
    checkButtons(FOOT_L);
    setAnchor();
}

void MainWindow::on_CENTER_clicked()
{
    checkButtons(CENTER);
    setAnchor();

}

void MainWindow::on_SPINE_clicked()
{
    checkButtons(SPINE);
    setAnchor();
}

void MainWindow::on_COLLAR_clicked()
{
    checkButtons(COLLAR);
    setAnchor();
}

void MainWindow::on_HEAD_clicked()
{
    checkButtons(HEAD);
    setAnchor();
}

void MainWindow::on_SHOULDER_R_clicked()
{
    checkButtons(SHOULDER_R);
    setAnchor();
}

void MainWindow::on_ELBOW_R_clicked()
{
    checkButtons(ELBOW_R);
    setAnchor();
}

void MainWindow::on_WRIST_R_clicked()
{
    checkButtons(WRIST_R);
    setAnchor();
}

void MainWindow::on_HAND_R_clicked()
{
    checkButtons(HAND_R);
    setAnchor();
}

void MainWindow::on_HIP_R_clicked()
{
    checkButtons(HIP_R);
    setAnchor();
}

void MainWindow::on_KNEE_R_clicked()
{
    checkButtons(KNEE_R);
    setAnchor();
}

void MainWindow::on_ANKLE_R_clicked()
{
    checkButtons(ANKLE_R);
    setAnchor();
}

void MainWindow::on_FOOT_R_clicked()
{
    checkButtons(FOOT_R);
    setAnchor();
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    if(debug) qDebug("Deubg: '%d'", arg1);
    this->dataset=arg1;
}

void MainWindow::on_spinBox_valueChanged(const QString &arg1)
{
    if(debug) qDebug("Deubg: '%s'", "Change Happened");

}

void MainWindow::on_RUN_clicked()
{
    if(debug) qDebug("Deubg: '%d'", this->dataset);
    scene->dataSet=new DataSet();
    scene->dataSet->fetchDataSet(this->dataset);
    scene->runData();
}

void MainWindow::on_RESET_clicked()
{
    scene->reset();

}

void MainWindow::on_LIVE_clicked()
{

        if(debug) qDebug("Deubg: '%d'", this->dataset);
        scene->liveData=new DataSet();
        scene->liveData->setRunning(true);
        scene->runLive();

}

void MainWindow::on_STOP_clicked()
{
    scene->liveData->setRunning(false);
    if(debug) qDebug("Deubg: '%s'", 'NOT LIVE');
}

void MainWindow::on_pushButton_toggled(bool checked)
{
    this->scene->human->setInterp(checked);
}

void MainWindow::on_pushButton_3_toggled(bool checked)
{
    this->scene->human->setScaleT(checked);
}

void MainWindow::on_pushButton_4_toggled(bool checked)
{
    this->scene->setFilter(checked);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    qDebug("Deubg: '%d'", value);
    this->scene->setWindows(value);
}

