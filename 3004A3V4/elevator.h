#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QObject>
#include <QList>
#include <QTimer>
#include "floor.h"

using namespace std;

class ElevatorControlSystem;

class Elevator : public QObject
{
    Q_OBJECT

    // private variables

    // ecs
    ElevatorControlSystem* ECS;

    // represent elev cases and direction of elev
    int currCase;
    int direction;

    // check if can move
    bool canMove;

    // number of an elevator
    int elevNum;

    // floor
    Floor *floor;

    // using QList for good list functionality offered by QT
    QList<Floor *> floorsList;

    // a general timer, and a timer used for elevator simulation (elevator move simulation)
    // using QTimer offered by QT
    QTimer *generalTimer;
    QTimer *simulateTimer;

    public:
        explicit Elevator(ElevatorControlSystem *, Floor *, int, QObject *parent = nullptr);
        ~Elevator();

        // beings sim for elevs
        void begin();

        // check if floor is in floors
        bool inFloors(Floor *);
        // pops floor off of floor list
        void popFloor(Floor *);

        // handles non base case
        void handleCaseOnClose();

        // handles sim cases
        void handleSimCase();

        // finds floor
        void findFloor();

        // finds direction
        void findDirection();

        // gets elevators floor number
        int getFloorLevelNum();

        // gets elevators direction
        int getDirection();

        // setter for timers (sets proper timer)
        void setTimer(int);

    signals:
        // updates floors
        void floorsUpdated();

    public slots:
        // runs the sumulation (based on the cases)
        void simulateCases();

        // handles reaching a floor
        void floorReached();

        // opens door
        void openDoor();
        // closes door
        void closeDoor();

        // allows elevator to move
        void allowMoving();
        // move elevator
        void move();
        // moves elevator to safe floor (in this program, floor 1 is always set as the safe floor)
        void moveToSafeFloor();

        // extension use cases
        // *** sends ints from checkbox ***
        void helpCase(int);
        void overloadCase(int);
        void poweroutCase(int);
        void obstacleCase(int);
        void fireCase(int);

        // adds floors, in this program there are 3 floors
        void addFloor1();
        void addFloor2();
        void addFloor3();
        void addFloor(Floor *);
};

#endif // ELEVATOR_H

