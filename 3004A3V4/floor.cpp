#include "floor.h"

Floor::Floor(int n, QObject *parent)
    : QObject{parent}, levelNum(n)
{

}

// getter for floor level
int Floor::getLevelNum()
{
    return levelNum;
}
