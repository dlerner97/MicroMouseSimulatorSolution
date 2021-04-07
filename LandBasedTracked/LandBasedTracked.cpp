//
// Created by dani on 12/8/20.
//

#include "LandBasedTracked.h"
#include <iostream>

void fp::LandBasedTracked::GoForward() {
//    std::cout << "LandBasedTracked::GoUp is called\n";
    fp::LandBasedRobot::GoForward();
}

void fp::LandBasedTracked::GoDown() {
//    std::cout << "LandBasedTracked::GoDown is called\n";
    fp::LandBasedRobot::GoDown();
}

void fp::LandBasedTracked::TurnLeft() {
//    std::cout << "LandBasedTracked::TurnLeft is called\n";
    fp::LandBasedRobot::TurnLeft();
}

void fp::LandBasedTracked::TurnRight() {
//    std::cout << "LandBasedTracked::TurnRight is called\n";
    fp::LandBasedRobot::TurnRight();
}

void fp::LandBasedTracked::set_x(int x) {
//    std::cout << "LandBasedTracked::set_x is called\n";
    fp::LandBasedRobot::set_x(x);
}

int fp::LandBasedTracked::get_x() {
//    std::cout << "LandBasedTracked::get_x is called\n";
    return fp::LandBasedRobot::get_x();
}

void fp::LandBasedTracked::set_y(int y) {
//    std::cout << "LandBasedTracked::set_y is called\n";
    fp::LandBasedRobot::set_y(y);
}

int fp::LandBasedTracked::get_y() {
//    std::cout << "LandBasedTracked::get_y is called\n";
    return fp::LandBasedRobot::get_y();
}

fp::LandBasedRobot::Dir fp::LandBasedTracked::get_heading() {
    return fp::LandBasedRobot::get_heading();
}

int fp::LandBasedTracked::get_int_heading() {
    return LandBasedRobot::get_int_heading();
}

fp::LandBasedTracked::~LandBasedTracked() {
    std::cout << "LandBasedTracked destructor called\n";
}

/*
 * Unused
 */

void fp::LandBasedTracked::PickUp(std::string) {
    std::cout << "LandBasedTracked::PickUp is called\n";
}

void fp::LandBasedTracked::Release(std::string) {
    std::cout << "LandBasedTracked::Release is called\n";
}
