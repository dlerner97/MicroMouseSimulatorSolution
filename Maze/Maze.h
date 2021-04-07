//
// Created by dani on 12/8/20.
//

#pragma once

#include <array>
#include <vector>
#include <memory>
#include <string>
#include "../LandBasedRobot/LandBasedRobot.h"
#include "../API/API.h"

namespace fp {
    class Maze {

        /*
         * Maze class for interacting with the API
         */

    private:
        int width_;
        int height_;
        std::vector<std::vector<std::string>> grid_;
        fp::LandBasedRobot* robot_;
        std::array<int, 2> goal_pos_;

    public:
        Maze(fp::LandBasedRobot& robot, std::array<int,2> goal_pos) : robot_{&robot}, goal_pos_{goal_pos} {
            width_ = fp::API::mazeWidth();
            height_ = fp::API::mazeHeight();
            grid_.resize(height_, std::vector<std::string>(width_, "."));
        }

        std::array<int, 2> GetMazeDim();
        std::string& Index(int row,int col);
        bool CheckWall(fp::LandBasedRobot::Dir dir);
        void CheckAllWalls();
        bool GoForward();
        void PrintMaze();
        void TurnRight();
        void TurnLeft();
        fp::LandBasedRobot& get_robot();
        std::array<int, 2> get_goal_pos();
        void SetCellColor(std::array<int,2>, char);
        void SetGoalColors();
        void ClearAllColor();
        const std::vector<std::vector<std::string>>& get_grid();
    };
}

