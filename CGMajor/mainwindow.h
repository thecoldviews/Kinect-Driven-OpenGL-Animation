/*
 * CG Major Project, Monsoon 2015
 * Author: Sarthak Ahuja, 2012088 | IIIT-Delhi
 *
 * Description:
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Human.h>
#include <Scene.h>
#include <QWidgetList>
#include <QLabel>
#include <QSlider>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    int dataset;
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_SHOULDER_L_clicked();

    void on_ELBOW_L_clicked();

    void on_WRIST_L_clicked();

    void on_HAND_L_clicked();

    void on_HIP_L_clicked();

    void on_KNEE_L_clicked();

    void on_ANKLE_L_clicked();

    void on_FOOT_L_clicked();

    void on_CENTER_clicked();

    void on_SPINE_clicked();

    void on_COLLAR_clicked();

    void on_HEAD_clicked();

    void on_SHOULDER_R_clicked();

    void on_ELBOW_R_clicked();

    void on_WRIST_R_clicked();

    void on_HAND_R_clicked();

    void on_HIP_R_clicked();

    void on_KNEE_R_clicked();

    void on_ANKLE_R_clicked();

    void on_FOOT_R_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_valueChanged(const QString &arg1);

    void on_RUN_clicked();

    void on_RESET_clicked();

    void on_LIVE_clicked();

    void on_STOP_clicked();

    void on_pushButton_toggled(bool checked);

    void on_pushButton_3_toggled(bool checked);

    void on_pushButton_4_toggled(bool checked);

    void on_horizontalSlider_valueChanged(int value);

private:
    bool debug=false;
    Ui::MainWindow *ui;
    void setupWidgets();
    void setAnchor();
    void checkButtons(int);
    Scene* scene;
    QPushButton* B_CENTER;
    QPushButton* B_HEAD;
    QPushButton* B_SPINE;
    QPushButton* B_COLLAR;
    QPushButton* B_SHOULDER_R;
    QPushButton* B_SHOULDER_L;
    QPushButton* B_ELBOW_R;
    QPushButton* B_ELBOW_L;
    QPushButton* B_WRIST_R;
    QPushButton* B_WRIST_L;
    QPushButton* B_HAND_R;
    QPushButton* B_HAND_L;
    QPushButton* B_HIP_R;
    QPushButton* B_HIP_L;
    QPushButton* B_KNEE_R;
    QPushButton* B_KNEE_L;
    QPushButton* B_ANKLE_R;
    QPushButton* B_ANKLE_L;
    QPushButton* B_FOOT_R;
    QPushButton* B_FOOT_L;
    QPushButton* B_RUN;
    QPushButton* B_LIVE;
};

#endif // MAINWINDOW_H
