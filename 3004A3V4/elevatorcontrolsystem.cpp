#include "elevatorcontrolsystem.h"

ElevatorControlSystem::ElevatorControlSystem(QObject *parent)
    : QObject{parent}, useStrat1(true)
{
    // initialize floors and elevators
    floor1 = new Floor(1);
    floor2 = new Floor(2);
    floor3 = new Floor(3);
    elevator1 = new Elevator(this, floor1, 1);
    elevator2 = new Elevator(this, floor1, 2);
}

ElevatorControlSystem::~ElevatorControlSystem()
{
    // delete floor and elevator objects
    delete floor1;
    delete floor2;
    delete floor3;
    delete elevator1;
    delete elevator2;
}


// simple getter functionality for the floors and elevators
Floor *ElevatorControlSystem::getFloor1()
{
    return floor1;
}

Floor *ElevatorControlSystem::getFloor2()
{
    return floor2;
}

Floor *ElevatorControlSystem::getFloor3()
{
    return floor3;
}

Elevator *ElevatorControlSystem::getElevator1()
{
    return elevator1;
}

Elevator *ElevatorControlSystem::getElevator2()
{
    return elevator2;
}

// begins sim for both elevators
void ElevatorControlSystem::beginSimulation()
{
    elevator1->begin();
    elevator2->begin();
}

// handling fire amd power out for both elevators (building itself)
void ElevatorControlSystem::fireCase(int f)
{
    elevator1->fireCase(f);
    elevator2->fireCase(f);
}

void ElevatorControlSystem::poweroutCase(int p)
{
    elevator1->poweroutCase(p);
    elevator2->poweroutCase(p);
}

void ElevatorControlSystem::swapStrat()
{
    useStrat1 = !useStrat1;

    if (useStrat1)
    {
        cout << "using strategy 1, elevator centered strategy" << endl;
    }
    else
    {
        cout << "using strategy 2, destination known strategy" << endl;
    }
}

// finds closest elevator
Elevator *ElevatorControlSystem::ElevatorCentered(Floor *f)
{
    Elevator* e = NULL;

    // elevator 1 is closer
    if (abs(elevator1->getFloorLevelNum()-f->getLevelNum()) < abs(elevator2->getFloorLevelNum()-f->getLevelNum()))
    {
        e = elevator1;
    }
    // elevator 2 is closer
    else if (abs(elevator1->getFloorLevelNum()-f->getLevelNum()) > abs(elevator2->getFloorLevelNum()-f->getLevelNum()))
    {
        e = elevator2;
    }
    // both elevators are equal distances away, so just send either, I chose elevator 2
    else
    {
        e = elevator2;
    }

    return e;
}

Elevator *ElevatorControlSystem::DestinationKnown(Floor *f)
{
    // if floor is in elev 1
    if (elevator1->inFloors(f))
    {
        // use elev 1
        return elevator1;
    }
    // else if floor is in elev 2
    else if (elevator2->inFloors(f))
    {
        // use elev 2
        return elevator2;
    }
    // otherwise use a random elevator
    else
    {
        // generate random
        int num = QRandomGenerator::global()->generate()%2;
        // check what number was generated
        if (num == 0)
        {
            return elevator1;
        }
        else
        {
            return elevator2;
        }
    }


}

// floor request and add floor requested to elevator
void ElevatorControlSystem::floorRequest(Floor *f, bool upOrDowm)
{
    // check if elevator requested up or down
    if (upOrDowm)
    {
        cout << "floor up request made, elevator on the way" << endl;
    }
    else
    {
        cout << "floor down request made, elevator on the way" << endl;
    }

    // finds elevator
    Elevator *foundElevator;
    // determine strategy
    if (useStrat1)
    {
        foundElevator = ElevatorCentered(f);
    }
    else
    {
        foundElevator = DestinationKnown(f);
    }

    // add floor to the correct elevator
    foundElevator->addFloor(f);
}
