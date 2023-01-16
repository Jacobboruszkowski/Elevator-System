#ifndef FLOOR_H
#define FLOOR_H

#include <QObject>
#include <iostream>
using namespace std;

class Floor : public QObject
{
    Q_OBJECT

    // floor level
    int levelNum;

    public:
        explicit Floor(int, QObject *parent = nullptr);

        // getter for floor level
        int getLevelNum();

    signals:


    public slots:

};

#endif // FLOOR_H
