#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "elevatorcontrolsystem.h"
#include "floor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    // ecs
    ElevatorControlSystem *ECS;

    // door open timer
    QTimer *keepDoorOpenedTimer;

    // floor
    Floor *floor;

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:
        Ui::MainWindow *ui;

    public slots:
        // setter for floor
        void setFloor(int);

        // open door pressed and released (elev 2)
        void elevator2OpenDoorPressed();
        void elevator2OpenDoorReleased();

        // open door pressed and released (elev 1)
        void elevator1OpenDoorPressed();
        void elevator1OpenDoorReleased();

        // request up and down
        void requestElevatorGoingUp();
        void requestElevatorGoingDown();

        // elev 1 and 2 close door
        void elevator1CloseDoor();
        void elevator2CloseDoor();

        // update checked floors
        void updateElevator1CheckedFloors();
        void updateElevator2CheckedFloors();

        // help
        void elevator1Help(int);
        void elevator2Help(int);

        // overload
        void elevator1Overload(int);
        void elevator2Overload(int);

        // fire
        void elevator1Fire(int);
        void elevator2Fire(int);

        // obstacles
        void elevator1Obstacle(int);
        void elevator2Obstacle(int);

        // power out and fire in building
        void powerout(int);
        void buildingFire(int);

        // display floors of elevs
        void displayCurrentFloors();
};
#endif // MAINWINDOW_H
