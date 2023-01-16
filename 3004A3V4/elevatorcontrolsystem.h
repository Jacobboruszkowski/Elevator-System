#ifndef ELEVATORCONTROLSYSTEM_H
#define ELEVATORCONTROLSYSTEM_H

#include <QObject>
#include <QRandomGenerator>
#include "elevator.h"
#include "floor.h"
using namespace std;

class ElevatorControlSystem : public QObject
{
    Q_OBJECT

    // check strat
    bool useStrat1;

    // floors
    Floor *floor1;
    Floor *floor2;
    Floor *floor3;

    // elevators
    Elevator *elevator1;
    Elevator *elevator2;

    public:
        explicit ElevatorControlSystem(QObject *parent = nullptr);
        ~ElevatorControlSystem();

        // begins simulation for elevators (starts timer for sim)
        void beginSimulation();

        // handles floor requests
        void floorRequest(Floor *, bool);

        // strats
        Elevator* ElevatorCentered(Floor *);
        Elevator *DestinationKnown(Floor *);

        // getters for floors
        Floor *getFloor1();
        Floor *getFloor2();
        Floor *getFloor3();

        // getters for elevators
        Elevator *getElevator1();
        Elevator *getElevator2();

    signals:


    public slots:
        // extensions for all elevators (building itslef)
        void fireCase(int);
        void poweroutCase(int);

        // swap strat
        void swapStrat();
};

#endif // ELEVATORCONTROLSYSTEM_H

