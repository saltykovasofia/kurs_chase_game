#include "Character.h"


#ifndef PREDATOR_H
#define PREDATOR_H

class Predator : public Character {
private:
    int step;
public:
    Predator(Point2D left_ , Point2D right_ , int curDirection_,int step_);
    void UpdateCoordinates() override;
    void UpdateDirection(int dir) override;

};

#endif