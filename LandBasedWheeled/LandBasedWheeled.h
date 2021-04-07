//
// Created by dani on 12/8/20.
//

#pragma once

#include "../LandBasedRobot/LandBasedRobot.h"
#include <memory>
#include <string>

namespace fp {
    class LandBasedWheeled: public LandBasedRobot {
    protected:
        std::shared_ptr<std::string> wheel_type;

    public:

        LandBasedWheeled(std::string name, int x, int y): LandBasedRobot(name, x,y) {
//            std::cout << "LandBasedWheeled constructor called\n";
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

        virtual ~LandBasedWheeled() override {
            std::cout << "LandBasedWheeled destructor called\n";
        }

    };
}