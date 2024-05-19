#include "Character.h"

std::pair<Point2D,Point2D> Character::getCoordinates(){
    return {this->left,this->right};
}

int Character::getDirrection(){
    return curDirection; 
}

void Character::setDirection(int d){
    curDirection = d;
}



void Character::setCoordinates(Point2D left_,Point2D right_){
    left = left_;
    right = right_;
}