//
// Created by dani on 12/8/20.
//

#include "LandBasedWheeled.h"
#include <iostream>

void fp::LandBasedWheeled::GoForward() {
//    std::cout << "LandBasedWheeled::GoUp is called\n";
    fp::LandBasedRobot::GoForward();
}

void fp::LandBasedWheeled::GoDown() {
//    std::cout << "LandBasedWheeled::GoDown is called\n";
    fp::LandBasedRobot::GoDown();
}

void fp::LandBasedWheeled::TurnLeft() {
//    std::cout << "LandBasedWheeled::TurnLeft is called\n";
    fp::LandBasedRobot::TurnLeft();
}

void fp::LandBasedWheeled::TurnRight() {
//    std::cout << "LandBasedWheeled::TurnRight is called\n";
    fp::LandBasedRobot::TurnRight();
}

void fp::LandBasedWheeled::set_x(int x) {
//    std::cout << "LandBasedWheeled::set_x is called\n";
    fp::LandBasedRobot::set_x(x);
}

int fp::LandBasedWheeled::get_x() {
//    std::cout << "LandBasedWheeled::get_x is called\n";
    return fp::LandBasedRobot::get_x();
}

void fp::LandBasedWheeled::set_y(int y) {
//    std::cout << "LandBasedWheeled::set_y is called\n";
    fp::LandBasedRobot::set_y(y);
}

int fp::LandBasedWheeled::get_y() {
//    std::cout << "LandBasedWheeled::get_y is called\n";
    return fp::LandBasedRobot::get_y();
}

/*
 * Unused
 */

void fp::LandBasedWheeled::PickUp(std::string) {
    std::cout << "LandBasedWheeled::PickUp is called\n";
}

void fp::LandBasedWheeled::Release(std::string) {
    std::cout << "LandBasedWheeled::Release is called\n";
}


