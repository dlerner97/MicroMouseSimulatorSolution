/**
 * @file main.cpp
 * @author Shon Cortes, Dani Lerner, Derrick Jackson
 * @brief Final-Project-Group1
 * @version 0.1
 * @date 2020-12-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "LandBasedWheeled/LandBasedWheeled.h"
#include "LandBasedTracked/LandBasedTracked.h"
#include "LandBasedRobot/LandBasedRobot.h"
#include "Algorithm/Algorithm.h"
#include "Maze/Maze.h"
#include <array>
#include <iostream>
#include <memory>

/**
 * @brief 
 * 
 * @return int 
 */

int main() {
    // Create robot instance
    std::shared_ptr<fp::LandBasedRobot> robot = std::make_shared<fp::LandBasedWheeled>("Robot", 0,0);

    // Create Maze instance
    std::array<int, 2> goal{7,8};
    fp::Maze maze(*robot, goal);

    // Create Path Plan instance
    fp::Algorithm algorithm(maze);

    // Run
    algorithm.FindCenter();
    return 0;
}
