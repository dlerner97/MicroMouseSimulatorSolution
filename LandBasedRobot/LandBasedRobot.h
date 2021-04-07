//
// Created by dani on 12/8/20.
//

#pragma once

#include <string>
#include <iostream>

namespace fp {
    class LandBasedRobot {

        /*
         * Land based robot base class
        */

    public:
        enum Dir {
            kN,
            kE,
            kS,
            kW
        };

        LandBasedRobot(std::string name, int x=0, int y=0, Dir heading=kN): name_{name}, x_{x}, y_{y}, heading_{heading}{
//            std::cout << "LandBasedRobot constructor called\n";

        }

        virtual void GoForward();
        virtual void GoDown();
        virtual void TurnLeft();
        virtual void TurnRight();
        virtual void PickUp(std::string);
        virtual void Release(std::string);
        virtual void set_x(int x);
        virtual int get_x();
        virtual void set_y(int y);
        virtual int get_y();
        virtual Dir get_heading();
        virtual int get_int_heading();

        virtual ~LandBasedRobot(){
            std::cout << "LandBasedRobot destructor called\n";
        }

    protected:
        std::string name_;
        double speed_;
        double width_;
        double length_;
        double height_;
        double capacity_;
        int x_, y_;
        Dir heading_;

    };
}


