#include "Point2D.h"
#include <utility>

#ifndef CHARACTER_H
#define CHARACTER_H


class Character {
private:
    Point2D left;
    Point2D right;
    int curDirection;    
public:
    std::pair<Point2D,Point2D> getCoordinates();
    int getDirrection();
    void setDirection(int d);
    void setCoordinates(Point2D left_,Point2D right_);
    virtual void UpdateCoordinates() = 0; 
    virtual void UpdateDirection(int dir) = 0;
};

#endif