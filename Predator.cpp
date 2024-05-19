#include "Predator.h"

Predator::Predator(Point2D left_ , Point2D right_ , int curDirection_,int step_){
    setCoordinates(left_,right_);
    setDirection(curDirection_);
    step = step_;
}


void Predator::UpdateCoordinates(){
    std::pair<Point2D,Point2D> tmp = getCoordinates();
    Point2D left_ = tmp.first;
    Point2D right_ = tmp.second;
    int curDirection_ = getDirrection();
    switch(curDirection_){
        case 0: left_.y-=(step); right_.y-=(step); break;
        case 1: left_.x+=(step); right_.x+=(step); break;
        case 2: left_.y+=(step); right_.y+=(step); break;
        case 3: left_.x-=(step); right_.x-=(step); break;
    }
    setCoordinates(left_,right_);
}

void Predator::UpdateDirection(int dir){
    if(dir>3 || dir < 0)return;
    setDirection(dir);
}
