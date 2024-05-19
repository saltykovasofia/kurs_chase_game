#include "Character.h"


#ifndef PREY_H
#define PREY_H

class Prey : public Character {
private:

public:
    Prey(Point2D left_ , Point2D right_ , int curDirection_);
    void UpdateCoordinates() override;
    void UpdateDirection(int dir) override;

};

#endif