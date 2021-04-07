//
// Created by dani on 12/8/20.
//

#pragma once

#include <stack>
#include <array>
#include <vector>
#include "../Maze/Maze.h"

namespace fp {
    class Algorithm {

    /*
     * Algorithm Class
     *
     * Path planning algorithm for micro-mouse simulator.
     */

    public:
        // Constructor
        Algorithm(fp::Maze& maze) : maze_{&maze} {
            width_ = maze_->GetMazeDim()[0];
            height_ = maze_->GetMazeDim()[1];
            visited_.resize(height_, std::vector<bool>(width_, false));
            stack_.push(std::array<int,2>{0,0});
            maze_->CheckAllWalls();
            maze_->SetGoalColors();
        }

        std::_Bit_reference IndexVisited(int row, int col);
        bool FindSinglePath(int row, int col);
        std::array<bool,2> ExecutePath();
        void PrintVisited();
        bool FindCenter();

    private:
        std::stack<std::array<int,2>> stack_;
        std::vector<std::vector<bool>> visited_;
        fp::Maze* maze_;
        int height_;
        int width_;
        int prev_heading_{0};
        bool first_iter_{true};
    };
}

