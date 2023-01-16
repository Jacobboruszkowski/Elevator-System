#include "elevator.h"
#include "elevatorcontrolsystem.h"

Elevator::Elevator(ElevatorControlSystem *ECS, Floor *f, int e, QObject *parent)
    : QObject{parent}, ECS(ECS), currCase(0), canMove(true), elevNum(e), floor(f), generalTimer(new QTimer(this)), simulateTimer(new QTimer(this))
{

}

Elevator::~Elevator()
{
    // delete timers
    delete simulateTimer;
    delete generalTimer;
}

// simple getters

int Elevator::getFloorLevelNum()
{
    return floor->getLevelNum();
}

int Elevator::getDirection()
{
    return direction;
}


void Elevator::begin()
{
    // connects the timer so that it triggers the simulate function everytime it fires
    connect(simulateTimer, SIGNAL(timeout()), this, SLOT(simulateCases()));
    simulateTimer->start(10000); // every 10 seconds (must be 10 seconds as to avoid timers conflicting which would result in duplicate outputs in certain cases)
}


// help case
void Elevator::helpCase(int h)
{
    // checkbox is checked
    if (h)
    {
        // switch case to help
        currCase = 1;
        cout<< "elevator " << elevNum << " is now in the help case" << endl;
    }
    else
    {
        currCase = 0;
        cout<< "elevator " << elevNum << "'s helpline disconnected" << endl;
        cout<< "elevator " << elevNum << " is now in the base case" << endl;
    }
}

// fire case
void Elevator::fireCase(int f)
{
    // checkbox is checked
    if (f)
    {
        currCase = 3;
        cout<< "elevator " << elevNum << " is now in the fire case" << endl;
    }
    else
    {
        currCase = 0;
        cout<< "elevator " << elevNum << " is now in the base case" << endl;
    }
}

// overload case
void Elevator::overloadCase(int o)
{
    // checkbox is checked
    if (o)
    {
        currCase = 4;
        cout<< "elevator " << elevNum << " is now in the overload case" << endl;
    }
    else
    {
        currCase = 0;
        cout<< "elevator " << elevNum << " is now in the base case" << endl;
    }
}

// onstacle case
void Elevator::obstacleCase(int o)
{
    // checkbox is checked
    if (o)
    {
        currCase = 2;
        cout<< "elevator " << elevNum << " is now in the door obstacle case" << endl;
    }
    else
    {
        currCase = 0;
        cout<< "elevator " << elevNum << " is now in the base case" << endl;
    }
}

// power out case
void Elevator::poweroutCase(int p)
{
    // checkbox is checked
    if (p)
    {
        currCase = 5;
        cout<< "elevator " << elevNum << " is now in the powerout case" << endl;
    }
    else
    {
        currCase = 0;
        cout<< "elevator " << elevNum << " is now in the base case" << endl;
    }
}

bool Elevator::inFloors(Floor *f)
{
    // checks if floors list contains given floor
    return floorsList.contains(f);
}

void Elevator::popFloor(Floor *f)
{
    // removes given floor
    floorsList.removeOne(f);
}

// main sim
void Elevator::simulateCases()
{
    if (currCase == 0) // base case
    {
        // make sure moving is allowed and that there are floors selected to move to
        if (!floorsList.empty() && canMove)
        {
            move();
        }
    }
    else
    {
        handleSimCase();
    }

}

// handles sims cases
void Elevator::handleSimCase()
{
    // ifs to check if one of the extension cases active on elevator
    if (currCase == 1) // help case
    {
        cout<< "elevator " << elevNum << "'s helpline connected" << endl;
        cout<< "elevator " << elevNum << " has called 911!" << endl;
        currCase = 6;
    }
    else if (currCase == 2) // door obstacle case
    {
        openDoor();
    }
    else if (currCase == 3) // fire case
    {
        moveToSafeFloor();
    }
    else if (currCase == 4)    // overload case
    {
        closeDoor();
    }
    else if (currCase == 5) // power out case
    {
        moveToSafeFloor();
    }
    else // stay put case
    {
        // do nothing
        // used to avoid console spam
    }
}

// add floor to elevator
void Elevator::addFloor(Floor *f)
{
    cout << "floor " << f->getLevelNum() << " has been added to elevator " << elevNum << endl;
    // pushes floor into floors list
    floorsList.push_back(f);
    // emits update signal for floors
    emit floorsUpdated();
}

// adding floors
void Elevator::addFloor1()
{
    addFloor(ECS->getFloor1());
}

void Elevator::addFloor2()
{
    addFloor(ECS->getFloor2());
}

void Elevator::addFloor3()
{
    addFloor(ECS->getFloor3());
}

// setting timer events
void Elevator::setTimer(int t)
{
    if (t == 0)
    {
        delete generalTimer;
        generalTimer = new QTimer(this);
        connect(generalTimer, SIGNAL(timeout()), this, SLOT(closeDoor()));
        generalTimer->start(3000); // 3 seconds
    }
    else if (t == 1)
    {
        delete generalTimer;
        generalTimer = new QTimer(this);
        connect(generalTimer, SIGNAL(timeout()), this, SLOT(allowMoving()));
        generalTimer->start(3000); // 3 seconds
    }
    else if (t == 2)
    {
        delete generalTimer;
        generalTimer = new QTimer(this);
        connect(generalTimer, SIGNAL(timeout()), this, SLOT(floorReached()));
        generalTimer->start(3000); // every 3 seconds
    }
}

// find direction of elevator
void Elevator::findDirection()
{
    // determine direction
    if (floor->getLevelNum() == floorsList[0]->getLevelNum())
    {
        direction = 0; // stay at floor
    }
    else if (floor->getLevelNum() > floorsList[0]->getLevelNum())
    {
        direction = 2; // go down
    }
    else
    {
        direction = 1; // go up
    }
}

// move elevator
void Elevator::move()
{
    // find direction
    findDirection();

    // simulate floor move time
    if (direction == 1 || direction == 2)
    {
        canMove = false;

        setTimer(2);

    }
    // dont need to simulate any floor movement time since we already at the correct floor
    else if (direction == 0)
    {
        floorReached();
    }
}

void Elevator::moveToSafeFloor()
{
    // moves to safe floor (which will always be floor 1)
    floorsList.clear();
    floorsList.push_back(ECS->getFloor1());
    move();
}

// find a desired floor
void Elevator::findFloor()
{
    // update the floor if the elevator moved through the floors
    if (direction == 2) // elevator moved up
    {
        if (floor->getLevelNum() == 3) // previous floor was floor 3
        {
            floor = ECS->getFloor2();
        }
        else // previous floor was floor 2
        {
            floor = ECS->getFloor1();
        }
    }
    else if (direction == 1) // elevator moved down
    {
        if (floor->getLevelNum() == 1) // previous floor was floor 1
        {
            floor = ECS->getFloor2();
        }
        else // previous floor was floor 2
        {
            floor = ECS->getFloor3();
        }
    }
}

// desired floor reached
void Elevator::floorReached()
{
    // finds floor
    findFloor();

    cout << "elevator " << elevNum << "'s floor = " << floor->getLevelNum() << endl;

    // determine if the elevator should stop at this floor
    // if floor isnt a desired floor
    if (!inFloors(floor))
    {
        // we can move
        canMove = true;
    }
    else
    {
        // pops and updates floors
        popFloor(floor);
        emit floorsUpdated();

        // ring bell
        cout<< "elevator " << elevNum << "'s bell is ringing" << endl;

        // open the door
        openDoor();
    }
}


void Elevator::openDoor()
{
    cout<< "elevator " << elevNum << "'s door is opened" << endl;

    // set proper timer
    setTimer(0);
}

void Elevator::closeDoor()
{
    if (currCase == 0) // base case
    {
        cout << "elevator " << elevNum << "'s door is closing" << endl;

        // set proper timer
        setTimer(1);
    }
    else
    {
        // handle close for extension cases
        handleCaseOnClose();
    }
}

void Elevator::handleCaseOnClose()
{
    if (currCase == 2) // door obstacle case
    {
        cout<< "elevator " << elevNum << "'s door is obstructed, the door will be opened" << endl;
        openDoor();
    }
    else if (currCase == 3) // fire case
    {
        cout << "FIRE PLEASE DISEMBARK" << endl;
        // stay put
        currCase = 6;
    }
    else if (currCase == 4)  // overload case
    {
        cout << "elevator " << elevNum << "'s door is closing!\nunable to close door!\nplease reduce cargo weight" << endl;
        openDoor();

    }
    else if (currCase == 5) // power out case
    {
        cout << "POWER OUT PLEASE DISEMBARK" << endl;
        // stay put
        currCase = 6;
    }
}

void Elevator::allowMoving()
{
    // allow move
    canMove = true;
}
