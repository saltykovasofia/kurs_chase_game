#include "Prey.h"

Prey::Prey(Point2D left_ , Point2D right_ , int curDirection_){
    setCoordinates(left_,right_);
    setDirection(curDirection_);
}


void Prey::UpdateCoordinates(){
    std::pair<Point2D,Point2D> tmp = getCoordinates();
    Point2D left_ = tmp.first;
    Point2D right_ = tmp.second;
    int curDirection_ = getDirrection();
    switch(curDirection_){
        case 0: left_.y--; right_.y--; break;
        case 1: left_.x++; right_.x++; break;
        case 2: left_.y++; right_.y++; break;
        case 3: left_.x--; right_.x--; break;
        case 4: left_.y--; right_.y--; left_.x--; right_.x--; break;
        case 5: left_.y--; right_.y--; left_.x++; right_.x++; break;
        case 6: left_.y++; right_.y++; left_.x++; right_.x++; break;
        case 7: left_.y++; right_.y++; left_.x--; right_.x--; break;
    }
    setCoordinates(left_,right_);
}

void Prey::UpdateDirection(int dir){
    if(dir>7 || dir < 0)return;
    setDirection(dir);
}