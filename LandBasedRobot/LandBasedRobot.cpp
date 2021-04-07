//
// Created by dani on 12/8/20.
//

#include "LandBasedRobot.h"

// Go forward method
void fp::LandBasedRobot::GoForward() {
//    std::cout << "LandBasedRobot::GoUp is called\n";
    if (heading_==kN){
        y_++;
    }
    else if (heading_==kE){
        x_++;
    }
    else if (heading_==kS){
        y_--;
    }
    else if (heading_==kW){
        x_--;
    }
}

// Go backwards
void fp::LandBasedRobot::GoDown() {
//    std::cout << "LandBasedRobot::GoDown is called\n";
    if (heading_==kN){
        y_--;
    }
    else if (heading_==kE){
        x_--;
    }
    else if (heading_==kS){
        y_++;
    }
    else if (heading_==kW){
        x_++;
    }
}

// Turn left
void fp::LandBasedRobot::TurnLeft() {
//    std::cout << "LandBasedRobot::TurnLeft is called\n";

    int temp=(int)heading_;
    temp--;
    if (temp<0) {
        temp=3;
    }
    heading_=static_cast<Dir>(temp);
}

// Turn right
void fp::LandBasedRobot::TurnRight() {
//    std::cout << "LandBasedRobot::TurnRight is called\n";
    int temp=(int)heading_;
    temp++;
    if (temp>3) {
        temp=0;
    }
    heading_=static_cast<Dir>(temp);
}

// Set y-pos
void fp::LandBasedRobot::set_x(int x) {
//    std::cout << "LandBasedRobot::set_x is called\n";
    x_ = x;
}

// Get current x-pos
int fp::LandBasedRobot::get_x() {
//    std::cout << "LandBasedRobot::get_x is called\n";
    return x_;
}

// Set y-pos
void fp::LandBasedRobot::set_y(int y) {
//    std::cout << "LandBasedRobot::set_y is called\n";
    y_ = y;
}

// Get current y-pos
int fp::LandBasedRobot::get_y() {
//    std::cout << "LandBasedRobot::get_y is called\n";
    return y_;
}

// Get current heading
fp::LandBasedRobot::Dir fp::LandBasedRobot::get_heading(){
    return heading_;
}

// Get integer heading
int fp::LandBasedRobot::get_int_heading() {
    return (int)heading_;
}

/*
 * The rest are unused
 */

void fp::LandBasedRobot::PickUp(std::string) {
    std::cout << "LandBasedRobot::PickUp is called\n";
}

void fp::LandBasedRobot::Release(std::string) {
    std::cout << "LandBasedRobot::Release is called\n";
}




