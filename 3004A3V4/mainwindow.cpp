#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , keepDoorOpenedTimer(new QTimer(this)), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // creating ecs
    ECS = new ElevatorControlSystem();

    // connecting all objects (buttons, checkboxes...)

    connect(ui->CheckFloors, SIGNAL(released()), this, SLOT(displayCurrentFloors()));

    // connect floor field
    floor = ECS->getFloor1();
    connect(ui->FloorUp, SIGNAL(released()), this, SLOT(requestElevatorGoingUp()));
    connect(ui->FloorDown, SIGNAL(released()), this, SLOT(requestElevatorGoingDown()));
    connect(ui->FloorLevelNum, SIGNAL(activated(int)), this, SLOT(setFloor(int)));
    // set to false to grey out floor down when on floor 1 and combo box not updated
    ui->FloorDown->setEnabled(false);

    // connect elevator 1 field
    connect(ECS->getElevator1(), SIGNAL(floorsUpdated()), this, SLOT(updateElevator1CheckedFloors()));

    connect(ui->Elev1Floor3, SIGNAL(released()), ECS->getElevator1(), SLOT(addFloor3()));
    connect(ui->Elev1Floor2, SIGNAL(released()), ECS->getElevator1(), SLOT(addFloor2()));
    connect(ui->Elev1Floor1, SIGNAL(released()), ECS->getElevator1(), SLOT(addFloor1()));
    connect(ui->Elev1Help, SIGNAL(stateChanged(int)), this, SLOT(elevator1Help(int)));
    connect(ui->Elev1OpenDoor, SIGNAL(pressed()), this, SLOT(elevator1OpenDoorPressed()));
    connect(ui->Elev1OpenDoor, SIGNAL(released()), this, SLOT(elevator1OpenDoorReleased()));
    connect(ui->Elev1CloseDoor, SIGNAL(clicked(bool)), this, SLOT(elevator1CloseDoor()));

    connect(ui->Elev1Overload, SIGNAL(stateChanged(int)), this, SLOT(elevator1Overload(int)));
    connect(ui->Elev1Fire, SIGNAL(stateChanged(int)), this, SLOT(elevator1Fire(int)));
    connect(ui->Elev1Obstacle, SIGNAL(stateChanged(int)), this, SLOT(elevator1Obstacle(int)));

    // connect elevator 2 field
    connect(ECS->getElevator2(), SIGNAL(floorsUpdated()), this, SLOT(updateElevator2CheckedFloors()));

    connect(ui->Elev2Floor3, SIGNAL(released()), ECS->getElevator2(), SLOT(addFloor3()));
    connect(ui->Elev2Floor2, SIGNAL(released()), ECS->getElevator2(), SLOT(addFloor2()));
    connect(ui->Elev2Floor1, SIGNAL(released()), ECS->getElevator2(), SLOT(addFloor1()));
    connect(ui->Elev2Help, SIGNAL(stateChanged(int)), this, SLOT(elevator2Help(int)));
    connect(ui->Elev2OpenDoor, SIGNAL(pressed()), this, SLOT(elevator2OpenDoorPressed()));
    connect(ui->Elev2OpenDoor, SIGNAL(released()), this, SLOT(elevator2OpenDoorReleased()));
    connect(ui->Elev2CloseDoor, SIGNAL(clicked(bool)), this, SLOT(elevator2CloseDoor()));

    connect(ui->Elev2Overload, SIGNAL(stateChanged(int)), this, SLOT(elevator2Overload(int)));
    connect(ui->Elev2Fire, SIGNAL(stateChanged(int)), this, SLOT(elevator2Fire(int)));
    connect(ui->Elev2Obstacle, SIGNAL(stateChanged(int)), this, SLOT(elevator2Obstacle(int)));

    // general testing field
    connect(ui->PowerOut, SIGNAL(stateChanged(int)), this, SLOT(powerout(int)));
    connect(ui->FireBuilding, SIGNAL(stateChanged(int)), this, SLOT(buildingFire(int)));

    // strategy field
    ui->Strategy1->setChecked(true);
    connect(ui->Strategy1, SIGNAL(released()), ECS, SLOT(swapStrat()));
    connect(ui->Strategy2, SIGNAL(released()), ECS, SLOT(swapStrat()));

    // begin simulation
    ECS->beginSimulation();
}

// delete the whole ui
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setFloor(int f)
{
    if (f == 0) // floor 1
    {
        floor = ECS->getFloor1();

        ui->FloorUp->setEnabled(true);
        ui->FloorDown->setEnabled(false);
    }
    else if (f == 1) // floor 2
    {
        floor = ECS->getFloor2();

        ui->FloorUp->setEnabled(true);
        ui->FloorDown->setEnabled(true);
    }
    else // floor 3
    {
        floor = ECS->getFloor3();

        ui->FloorUp->setEnabled(false);
        ui->FloorDown->setEnabled(true);
    }
}

// requests elev up direction
void MainWindow::requestElevatorGoingUp()
{
    ECS->floorRequest(floor, true);
}

// requests elev down direction
void MainWindow::requestElevatorGoingDown()
{
    ECS->floorRequest(floor, false);
}

// elev 1 open door pressed
void MainWindow::elevator1OpenDoorPressed()
{
    cout << "elevator 1's door is being held opened!" << endl;
    ui->Elev1OpenDoor->setChecked(true);
    connect(keepDoorOpenedTimer, SIGNAL(timeout()), ECS->getElevator1(), SLOT(openDoor()));
}

// elev 2 open door released
void MainWindow::elevator2OpenDoorReleased()
{
    cout << "elevator 2's door is no longer being held opened!" << endl;
    ui->Elev2OpenDoor->setChecked(false);
    delete keepDoorOpenedTimer;
    keepDoorOpenedTimer = new QTimer(this);
}

// elev 1 close door
void MainWindow::elevator1CloseDoor()
{
    ECS->getElevator1()->closeDoor();
    ui->Elev1CloseDoor->setChecked(false);
}

// elev 2 close door
void MainWindow::elevator2CloseDoor()
{
    ECS->getElevator2()->closeDoor();
    ui->Elev2CloseDoor->setChecked(false);
}

// elev 1 open door released
void MainWindow::elevator1OpenDoorReleased()
{
    cout << "elevator 1's door is no longer being held opened!" << endl;
    ui->Elev1OpenDoor->setChecked(false);
    delete keepDoorOpenedTimer;
    keepDoorOpenedTimer = new QTimer(this);
}

// elev 2 open door pressed
void MainWindow::elevator2OpenDoorPressed()
{
    cout << "elevator 2's door is being held opened!" << endl;
    ui->Elev2OpenDoor->setChecked(true);
    connect(keepDoorOpenedTimer, SIGNAL(timeout()), ECS->getElevator2(), SLOT(openDoor()));
}

// update floor checkboxes (elev 1)
void MainWindow::updateElevator1CheckedFloors()
{
    ui->Elev1Floor1->setChecked(ECS->getElevator1()->inFloors(ECS->getFloor1()));
    ui->Elev1Floor2->setChecked(ECS->getElevator1()->inFloors(ECS->getFloor2()));
    ui->Elev1Floor3->setChecked(ECS->getElevator1()->inFloors(ECS->getFloor3()));
}

// update floor checkboxes (elev 2)
void MainWindow::updateElevator2CheckedFloors()
{
    ui->Elev2Floor1->setChecked(ECS->getElevator2()->inFloors(ECS->getFloor1()));
    ui->Elev2Floor2->setChecked(ECS->getElevator2()->inFloors(ECS->getFloor2()));
    ui->Elev2Floor3->setChecked(ECS->getElevator2()->inFloors(ECS->getFloor3()));
}

void MainWindow::elevator1Help(int h)
{
    ECS->getElevator1()->helpCase(h);

    // deal with checkboxes
    if (h)
    {
        ui->Elev1Floor1->setEnabled(false);
        ui->Elev1Floor2->setEnabled(false);
        ui->Elev1Floor3->setEnabled(false);
    }
    else
    {
        ui->Elev1Floor1->setEnabled(true);
        ui->Elev1Floor2->setEnabled(true);
        ui->Elev1Floor3->setEnabled(true);
    }
}

void MainWindow::elevator2Help(int h)
{
    ECS->getElevator2()->helpCase(h);

    // deal with checkboxes
    if (h)
    {
        ui->Elev2Floor1->setEnabled(false);
        ui->Elev2Floor2->setEnabled(false);
        ui->Elev2Floor3->setEnabled(false);
    }
    else
    {
        ui->Elev2Floor1->setEnabled(true);
        ui->Elev2Floor2->setEnabled(true);
        ui->Elev2Floor3->setEnabled(true);
    }
}

void MainWindow::elevator1Overload(int o)
{
    ECS->getElevator1()->overloadCase(o);

    // deal with checkboxes
    if (o)
    {
        ui->Elev1Floor1->setEnabled(false);
        ui->Elev1Floor2->setEnabled(false);
        ui->Elev1Floor3->setEnabled(false);
        ui->Elev1Help->setEnabled(false);
        ui->Elev1OpenDoor->setEnabled(false);
        ui->Elev1CloseDoor->setEnabled(false);
        ui->Elev1Fire->setEnabled(false);
        ui->Elev1Obstacle->setEnabled(false);

    }
    else
    {
        ui->Elev1Floor1->setEnabled(true);
        ui->Elev1Floor2->setEnabled(true);
        ui->Elev1Floor3->setEnabled(true);
        ui->Elev1Help->setEnabled(true);
        ui->Elev1OpenDoor->setEnabled(true);
        ui->Elev1CloseDoor->setEnabled(true);
        ui->Elev1Fire->setEnabled(true);
        ui->Elev1Obstacle->setEnabled(true);
    }
}

void MainWindow::elevator2Overload(int o)
{
    ECS->getElevator2()->overloadCase(o);

    // deal with checkboxes
    if (o)
    {
        ui->Elev2Floor1->setEnabled(false);
        ui->Elev2Floor2->setEnabled(false);
        ui->Elev2Floor3->setEnabled(false);
        ui->Elev2Help->setEnabled(false);
        ui->Elev2OpenDoor->setEnabled(false);
        ui->Elev2CloseDoor->setEnabled(false);
        ui->Elev2Fire->setEnabled(false);
        ui->Elev2Obstacle->setEnabled(false);
    }
    else
    {
        ui->Elev2Floor1->setEnabled(true);
        ui->Elev2Floor2->setEnabled(true);
        ui->Elev2Floor3->setEnabled(true);
        ui->Elev2Help->setEnabled(true);
        ui->Elev2OpenDoor->setEnabled(true);
        ui->Elev2CloseDoor->setEnabled(true);
        ui->Elev2Fire->setEnabled(true);
        ui->Elev2Obstacle->setEnabled(true);
    }
}

void MainWindow::elevator1Fire(int f)
{
    ECS->getElevator1()->fireCase(f);

    // deal with checkboxes
    if (f)
    {
        ui->Elev1Floor1->setEnabled(false);
        ui->Elev1Floor2->setEnabled(false);
        ui->Elev1Floor3->setEnabled(false);
        ui->Elev1Help->setEnabled(false);
        ui->Elev1OpenDoor->setEnabled(false);
        ui->Elev1CloseDoor->setEnabled(false);
        ui->Elev1Overload->setEnabled(false);
        ui->Elev1Obstacle->setEnabled(false);
    }
    else
    {
        ui->Elev1Floor1->setEnabled(true);
        ui->Elev1Floor2->setEnabled(true);
        ui->Elev1Floor3->setEnabled(true);
        ui->Elev1Help->setEnabled(true);
        ui->Elev1OpenDoor->setEnabled(true);
        ui->Elev1CloseDoor->setEnabled(true);
        ui->Elev2Overload->setEnabled(true);
        ui->Elev2Fire->setEnabled(true);
        ui->Elev1Overload->setEnabled(true);
        ui->Elev1Obstacle->setEnabled(true);
    }
}

void MainWindow::elevator2Fire(int f)
{
    ECS->getElevator2()->fireCase(f);

    // deal with checkboxes
    if (f)
    {
        ui->Elev2Floor1->setEnabled(false);
        ui->Elev2Floor2->setEnabled(false);
        ui->Elev2Floor3->setEnabled(false);
        ui->Elev2Help->setEnabled(false);
        ui->Elev2OpenDoor->setEnabled(false);
        ui->Elev2CloseDoor->setEnabled(false);
        ui->Elev2Overload->setEnabled(false);
        ui->Elev2Obstacle->setEnabled(false);
    }
    else
    {
        ui->Elev2Floor1->setEnabled(true);
        ui->Elev2Floor2->setEnabled(true);
        ui->Elev2Floor3->setEnabled(true);
        ui->Elev2Help->setEnabled(true);
        ui->Elev2OpenDoor->setEnabled(true);
        ui->Elev2CloseDoor->setEnabled(true);
        ui->Elev2Overload->setEnabled(true);
        ui->Elev2Obstacle->setEnabled(true);
    }
}

void MainWindow::elevator1Obstacle(int o)
{
    ECS->getElevator1()->obstacleCase(o);

    // deal with checkboxes
    if (o)
    {
        ui->Elev1Floor1->setEnabled(false);
        ui->Elev1Floor2->setEnabled(false);
        ui->Elev1Floor3->setEnabled(false);
        ui->Elev1Help->setEnabled(false);
        ui->Elev1Overload->setEnabled(false);
        ui->Elev1Fire->setEnabled(false);
    }
    else
    {
        ui->Elev1Floor1->setEnabled(true);
        ui->Elev1Floor2->setEnabled(true);
        ui->Elev1Floor3->setEnabled(true);
        ui->Elev1Help->setEnabled(true);
        ui->Elev1OpenDoor->setEnabled(true);
        ui->Elev1CloseDoor->setEnabled(true);
        ui->Elev1Overload->setEnabled(true);
        ui->Elev1Fire->setEnabled(true);
    }
}

void MainWindow::elevator2Obstacle(int o)
{
    ECS->getElevator2()->obstacleCase(o);

    // deal with checkboxes
    if (o)
    {
        ui->Elev2Floor1->setEnabled(false);
        ui->Elev2Floor2->setEnabled(false);
        ui->Elev2Floor3->setEnabled(false);
        ui->Elev2Help->setEnabled(false);
        ui->Elev2Overload->setEnabled(false);
        ui->Elev2Fire->setEnabled(false);
    }
    else
    {
        ui->Elev2Floor1->setEnabled(true);
        ui->Elev2Floor2->setEnabled(true);
        ui->Elev2Floor3->setEnabled(true);
        ui->Elev2Help->setEnabled(true);
        ui->Elev2OpenDoor->setEnabled(true);
        ui->Elev2CloseDoor->setEnabled(true);
        ui->Elev2Overload->setEnabled(true);
        ui->Elev2Fire->setEnabled(true);
    }
}

void MainWindow::powerout(int p)
{
    ECS->poweroutCase(p);

    // deal with checkboxes
    if (p)
    {
        ui->Elev1Floor1->setEnabled(false);
        ui->Elev1Floor2->setEnabled(false);
        ui->Elev1Floor3->setEnabled(false);
        ui->Elev1Help->setEnabled(false);
        ui->Elev1OpenDoor->setEnabled(false);
        ui->Elev1CloseDoor->setEnabled(false);
        ui->Elev1Overload->setEnabled(false);
        ui->Elev1Fire->setEnabled(false);
        ui->Elev1Obstacle->setEnabled(false);

        ui->Elev2Floor1->setEnabled(false);
        ui->Elev2Floor2->setEnabled(false);
        ui->Elev2Floor3->setEnabled(false);
        ui->Elev2Help->setEnabled(false);
        ui->Elev2OpenDoor->setEnabled(false);
        ui->Elev2CloseDoor->setEnabled(false);
        ui->Elev2Overload->setEnabled(false);
        ui->Elev2Fire->setEnabled(false);
        ui->Elev2Obstacle->setEnabled(false);

        ui->FireBuilding->setEnabled(false);
    }
    else
    {
        ui->Elev1Floor1->setEnabled(true);
        ui->Elev1Floor2->setEnabled(true);
        ui->Elev1Floor3->setEnabled(true);
        ui->Elev1Help->setEnabled(true);
        ui->Elev1OpenDoor->setEnabled(true);
        ui->Elev1CloseDoor->setEnabled(true);
        ui->Elev1Overload->setEnabled(true);
        ui->Elev1Fire->setEnabled(true);
        ui->Elev1Obstacle->setEnabled(true);

        ui->Elev2Floor1->setEnabled(true);
        ui->Elev2Floor2->setEnabled(true);
        ui->Elev2Floor3->setEnabled(true);
        ui->Elev2Help->setEnabled(true);
        ui->Elev2OpenDoor->setEnabled(true);
        ui->Elev2CloseDoor->setEnabled(true);
        ui->Elev2Overload->setEnabled(true);
        ui->Elev2Fire->setEnabled(true);
        ui->Elev2Obstacle->setEnabled(true);

        ui->FireBuilding->setEnabled(true);
    }
}

void MainWindow::buildingFire(int bf)
{
    ECS->fireCase(bf);

    // deal with checkboxes
    if (bf)
    {
        ui->Elev1Floor1->setEnabled(false);
        ui->Elev1Floor2->setEnabled(false);
        ui->Elev1Floor3->setEnabled(false);
        ui->Elev1Help->setEnabled(false);
        ui->Elev1OpenDoor->setEnabled(false);
        ui->Elev1CloseDoor->setEnabled(false);
        ui->Elev1Overload->setEnabled(false);
        ui->Elev1Fire->setEnabled(false);
        ui->Elev1Obstacle->setEnabled(false);

        ui->Elev2Floor1->setEnabled(false);
        ui->Elev2Floor2->setEnabled(false);
        ui->Elev2Floor3->setEnabled(false);
        ui->Elev2Help->setEnabled(false);
        ui->Elev2OpenDoor->setEnabled(false);
        ui->Elev2CloseDoor->setEnabled(false);
        ui->Elev2Overload->setEnabled(false);
        ui->Elev2Fire->setEnabled(false);
        ui->Elev2Obstacle->setEnabled(false);

        ui->PowerOut->setEnabled(false);
    }
    // deal with checkboxes
    else
    {
        ui->Elev1Floor1->setEnabled(true);
        ui->Elev1Floor2->setEnabled(true);
        ui->Elev1Floor3->setEnabled(true);
        ui->Elev1Help->setEnabled(true);
        ui->Elev1OpenDoor->setEnabled(true);
        ui->Elev1CloseDoor->setEnabled(true);
        ui->Elev1Overload->setEnabled(true);
        ui->Elev1Fire->setEnabled(true);
        ui->Elev1Obstacle->setEnabled(true);

        ui->Elev2Floor1->setEnabled(true);
        ui->Elev2Floor2->setEnabled(true);
        ui->Elev2Floor3->setEnabled(true);
        ui->Elev2Help->setEnabled(true);
        ui->Elev2OpenDoor->setEnabled(true);
        ui->Elev2CloseDoor->setEnabled(true);
        ui->Elev2Overload->setEnabled(true);
        ui->Elev2Fire->setEnabled(true);
        ui->Elev2Obstacle->setEnabled(true);

        ui->PowerOut->setEnabled(true);
    }
}

// display current floors (for easier testing)
void MainWindow::displayCurrentFloors()
{
    cout << "elevator 1 is currently on floor " << ECS->getElevator1()->getFloorLevelNum() << endl;
    cout << "elevator 2 is currently on floor " << ECS->getElevator2()->getFloorLevelNum() << endl;
}


