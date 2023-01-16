/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *FloorUp;
    QPushButton *FloorDown;
    QLabel *label_2;
    QCheckBox *Elev1Floor3;
    QCheckBox *Elev1Floor2;
    QCheckBox *Elev1Floor1;
    QCheckBox *Elev1OpenDoor;
    QCheckBox *Elev1CloseDoor;
    QCheckBox *Elev2CloseDoor;
    QCheckBox *Elev2Floor3;
    QCheckBox *Elev2OpenDoor;
    QLabel *label_3;
    QCheckBox *Elev2Floor2;
    QCheckBox *Elev2Floor1;
    QLabel *label_4;
    QCheckBox *Elev1Overload;
    QCheckBox *Elev1Fire;
    QCheckBox *Elev1Obstacle;
    QCheckBox *Elev2Obstacle;
    QLabel *label_5;
    QCheckBox *Elev2Overload;
    QCheckBox *Elev2Fire;
    QLabel *label_6;
    QCheckBox *PowerOut;
    QCheckBox *FireBuilding;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
    QFrame *line_9;
    QLabel *label_7;
    QRadioButton *Strategy1;
    QRadioButton *Strategy2;
    QFrame *line_10;
    QCheckBox *Elev2Help;
    QCheckBox *Elev1Help;
    QComboBox *FloorLevelNum;
    QPushButton *CheckFloors;
    QLabel *label_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 220, 63, 20));
        QFont font;
        font.setBold(true);
        font.setUnderline(true);
        label->setFont(font);
        FloorUp = new QPushButton(centralwidget);
        FloorUp->setObjectName("FloorUp");
        FloorUp->setGeometry(QRect(60, 290, 83, 29));
        FloorDown = new QPushButton(centralwidget);
        FloorDown->setObjectName("FloorDown");
        FloorDown->setGeometry(QRect(60, 330, 83, 29));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(310, 70, 81, 20));
        label_2->setFont(font);
        Elev1Floor3 = new QCheckBox(centralwidget);
        Elev1Floor3->setObjectName("Elev1Floor3");
        Elev1Floor3->setGeometry(QRect(310, 100, 93, 26));
        Elev1Floor2 = new QCheckBox(centralwidget);
        Elev1Floor2->setObjectName("Elev1Floor2");
        Elev1Floor2->setGeometry(QRect(310, 130, 93, 26));
        Elev1Floor1 = new QCheckBox(centralwidget);
        Elev1Floor1->setObjectName("Elev1Floor1");
        Elev1Floor1->setGeometry(QRect(310, 160, 93, 26));
        Elev1OpenDoor = new QCheckBox(centralwidget);
        Elev1OpenDoor->setObjectName("Elev1OpenDoor");
        Elev1OpenDoor->setGeometry(QRect(250, 220, 111, 21));
        Elev1CloseDoor = new QCheckBox(centralwidget);
        Elev1CloseDoor->setObjectName("Elev1CloseDoor");
        Elev1CloseDoor->setGeometry(QRect(360, 220, 111, 21));
        Elev2CloseDoor = new QCheckBox(centralwidget);
        Elev2CloseDoor->setObjectName("Elev2CloseDoor");
        Elev2CloseDoor->setGeometry(QRect(660, 220, 111, 21));
        Elev2Floor3 = new QCheckBox(centralwidget);
        Elev2Floor3->setObjectName("Elev2Floor3");
        Elev2Floor3->setGeometry(QRect(610, 100, 93, 26));
        Elev2OpenDoor = new QCheckBox(centralwidget);
        Elev2OpenDoor->setObjectName("Elev2OpenDoor");
        Elev2OpenDoor->setGeometry(QRect(550, 220, 111, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(610, 70, 71, 21));
        label_3->setFont(font);
        Elev2Floor2 = new QCheckBox(centralwidget);
        Elev2Floor2->setObjectName("Elev2Floor2");
        Elev2Floor2->setGeometry(QRect(610, 130, 93, 26));
        Elev2Floor1 = new QCheckBox(centralwidget);
        Elev2Floor1->setObjectName("Elev2Floor1");
        Elev2Floor1->setGeometry(QRect(610, 160, 93, 26));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(290, 280, 131, 51));
        label_4->setFont(font);
        Elev1Overload = new QCheckBox(centralwidget);
        Elev1Overload->setObjectName("Elev1Overload");
        Elev1Overload->setGeometry(QRect(250, 330, 93, 26));
        Elev1Fire = new QCheckBox(centralwidget);
        Elev1Fire->setObjectName("Elev1Fire");
        Elev1Fire->setGeometry(QRect(360, 330, 121, 31));
        Elev1Obstacle = new QCheckBox(centralwidget);
        Elev1Obstacle->setObjectName("Elev1Obstacle");
        Elev1Obstacle->setGeometry(QRect(280, 360, 141, 31));
        Elev2Obstacle = new QCheckBox(centralwidget);
        Elev2Obstacle->setObjectName("Elev2Obstacle");
        Elev2Obstacle->setGeometry(QRect(570, 360, 141, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(580, 280, 131, 51));
        label_5->setFont(font);
        Elev2Overload = new QCheckBox(centralwidget);
        Elev2Overload->setObjectName("Elev2Overload");
        Elev2Overload->setGeometry(QRect(540, 330, 93, 26));
        Elev2Fire = new QCheckBox(centralwidget);
        Elev2Fire->setObjectName("Elev2Fire");
        Elev2Fire->setGeometry(QRect(650, 330, 121, 31));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(420, 400, 111, 31));
        label_6->setFont(font);
        PowerOut = new QCheckBox(centralwidget);
        PowerOut->setObjectName("PowerOut");
        PowerOut->setGeometry(QRect(380, 430, 93, 26));
        FireBuilding = new QCheckBox(centralwidget);
        FireBuilding->setObjectName("FireBuilding");
        FireBuilding->setGeometry(QRect(500, 420, 131, 41));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(180, 30, 20, 551));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(187, 270, 611, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(480, 30, 20, 371));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(190, 390, 611, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(190, 530, 621, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName("line_6");
        line_6->setGeometry(QRect(20, 210, 171, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(centralwidget);
        line_7->setObjectName("line_7");
        line_7->setGeometry(QRect(20, 370, 171, 20));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(centralwidget);
        line_8->setObjectName("line_8");
        line_8->setGeometry(QRect(10, 220, 16, 161));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);
        line_9 = new QFrame(centralwidget);
        line_9->setObjectName("line_9");
        line_9->setGeometry(QRect(190, 20, 621, 16));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(440, 470, 111, 31));
        label_7->setFont(font);
        Strategy1 = new QRadioButton(centralwidget);
        Strategy1->setObjectName("Strategy1");
        Strategy1->setGeometry(QRect(370, 500, 112, 26));
        Strategy2 = new QRadioButton(centralwidget);
        Strategy2->setObjectName("Strategy2");
        Strategy2->setGeometry(QRect(500, 500, 112, 26));
        line_10 = new QFrame(centralwidget);
        line_10->setObjectName("line_10");
        line_10->setGeometry(QRect(190, 460, 621, 20));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);
        Elev2Help = new QCheckBox(centralwidget);
        Elev2Help->setObjectName("Elev2Help");
        Elev2Help->setGeometry(QRect(600, 190, 93, 26));
        Elev1Help = new QCheckBox(centralwidget);
        Elev1Help->setObjectName("Elev1Help");
        Elev1Help->setGeometry(QRect(300, 190, 93, 26));
        FloorLevelNum = new QComboBox(centralwidget);
        FloorLevelNum->addItem(QString());
        FloorLevelNum->addItem(QString());
        FloorLevelNum->addItem(QString());
        FloorLevelNum->setObjectName("FloorLevelNum");
        FloorLevelNum->setGeometry(QRect(60, 250, 82, 28));
        CheckFloors = new QPushButton(centralwidget);
        CheckFloors->setObjectName("CheckFloors");
        CheckFloors->setGeometry(QRect(10, 140, 171, 51));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(430, 5, 151, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Floor", nullptr));
        FloorUp->setText(QCoreApplication::translate("MainWindow", "Floor Up", nullptr));
        FloorDown->setText(QCoreApplication::translate("MainWindow", "Floor Down", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Elevator 1", nullptr));
        Elev1Floor3->setText(QCoreApplication::translate("MainWindow", "Floor 3", nullptr));
        Elev1Floor2->setText(QCoreApplication::translate("MainWindow", "Floor 2", nullptr));
        Elev1Floor1->setText(QCoreApplication::translate("MainWindow", "Floor 1", nullptr));
        Elev1OpenDoor->setText(QCoreApplication::translate("MainWindow", "Open Door", nullptr));
        Elev1CloseDoor->setText(QCoreApplication::translate("MainWindow", "Close Door", nullptr));
        Elev2CloseDoor->setText(QCoreApplication::translate("MainWindow", "Close Door", nullptr));
        Elev2Floor3->setText(QCoreApplication::translate("MainWindow", "Floor 3", nullptr));
        Elev2OpenDoor->setText(QCoreApplication::translate("MainWindow", "Open Door", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Elevator 2", nullptr));
        Elev2Floor2->setText(QCoreApplication::translate("MainWindow", "Floor 2", nullptr));
        Elev2Floor1->setText(QCoreApplication::translate("MainWindow", "Floor 1", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Testing Elevator 1", nullptr));
        Elev1Overload->setText(QCoreApplication::translate("MainWindow", "Overload", nullptr));
        Elev1Fire->setText(QCoreApplication::translate("MainWindow", "Fire Elevator", nullptr));
        Elev1Obstacle->setText(QCoreApplication::translate("MainWindow", "Obstacle in Door", nullptr));
        Elev2Obstacle->setText(QCoreApplication::translate("MainWindow", "Obstacle in Door", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Testing Elevator 2", nullptr));
        Elev2Overload->setText(QCoreApplication::translate("MainWindow", "Overload", nullptr));
        Elev2Fire->setText(QCoreApplication::translate("MainWindow", "Fire Elevator", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "General Testing", nullptr));
        PowerOut->setText(QCoreApplication::translate("MainWindow", "Power Out", nullptr));
        FireBuilding->setText(QCoreApplication::translate("MainWindow", "Fire in Building", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Strategies", nullptr));
        Strategy1->setText(QCoreApplication::translate("MainWindow", "Strategy 1", nullptr));
        Strategy2->setText(QCoreApplication::translate("MainWindow", "Strategy 2", nullptr));
        Elev2Help->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        Elev1Help->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        FloorLevelNum->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        FloorLevelNum->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        FloorLevelNum->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));

        CheckFloors->setText(QCoreApplication::translate("MainWindow", "CHECK CURRENT FLOORS", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "SAFE FLOOR: FLOOR 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
