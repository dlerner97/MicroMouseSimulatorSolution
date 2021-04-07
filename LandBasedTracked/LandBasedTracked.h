//
// Created by dani on 12/8/20.
//

#pragma  once

#include "../LandBasedRobot/LandBasedRobot.h"
#include <memory>
#include <string>

namespace fp {
    class LandBasedTracked: public LandBasedRobot {

        /*
         * Derived land base tracked class
         */

    protected:
        std::shared_ptr<std::string> track_type;

    public:

        LandBasedTracked(std::string name, int x, int y):   fp::LandBasedRobot(name, x,y) {
//            std::cout << "LandBasedTracked constructor called\n";
        }

        virtual void GoForward() override;
        virtual void GoDown() override;
        virtual void TurnLeft() override;
        virtual void TurnRight() override;
        virtual void PickUp(std::string) override;
        virtual void Release(std::string) override;
        virtual void set_x(int x) override;
        virtual int get_x() override;
        virtual void set_y(int y) override;
        virtual int get_y() override;
        virtual fp::LandBasedRobot::Dir get_heading() override;
        virtual int get_int_heading() override;

        virtual ~LandBasedTracked() override;

    };
}
