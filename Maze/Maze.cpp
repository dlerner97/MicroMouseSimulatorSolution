//
// Created by dani on 12/8/20.
//

#include "Maze.h"
#include <iostream>

// Getter for maze dimensions
std::array<int, 2> fp::Maze::GetMazeDim() {
    std::array<int, 2> shape{width_, height_};
    return shape;
}

// Index grid with custom coordinate system
std::string& fp::Maze::Index(int row, int col) {
    return grid_[height_- 1 - row][col];
}

// Check individual wall in given direction
bool fp::Maze::CheckWall(fp::LandBasedRobot::Dir dir) {
    fp::LandBasedRobot::Dir heading=robot_->get_heading();
    int shift = (int)dir-(int)heading;

    if (shift==0){
        return fp::API::wallFront();
    }
    else if(shift==1 || shift==-3){
        return fp::API::wallRight();
    }
    else if(shift==-1 || shift==3){
        return fp::API::wallLeft();
    }
    return false;
}

// Check all left, right, and front wall
void fp::Maze::CheckAllWalls() {

    int col = robot_->get_x();
    int row = robot_->get_y();

    // If wall in given dir, append letter to denote the direction of wall
    std::string str_new = "";
    if(fp::Maze::CheckWall(fp::LandBasedRobot::kN)){
        str_new += "n";
        fp::API::setWall(col, row, 'n');
    }
    if(fp::Maze::CheckWall(fp::LandBasedRobot::kE)){
        str_new += "e";
        fp::API::setWall(col, row, 'e');
    }
    if(fp::Maze::CheckWall(fp::LandBasedRobot::kS)){
        str_new += "s";
        fp::API::setWall(col, row, 's');
    }
    if(fp::Maze::CheckWall(fp::LandBasedRobot::kW)){
        str_new += "w";
        fp::API::setWall(col, row, 'w');
    }

    // For testing no solution (maze 3)
//    if(col == 5 && row == 2) {
//        str_new += "n";
//        fp::API::setWall(5, 2, 'n');
//    }

    // Set grid element to direction string
    fp::Maze::Index(row, col) = str_new;
}

// Move forward
bool fp::Maze::GoForward() {
    fp::LandBasedRobot::Dir heading=robot_->get_heading();
    int col = robot_->get_x();
    int row = robot_->get_y();
    std::string strs[4]{"n","e","s","w"};
    // If wall present...
    if (fp::Maze::Index(row, col).find(strs[(int)heading]) == std::string::npos) {
        // Move forward
        fp::API::moveForward();
        robot_->GoForward();
        return true;
    // Otherwise return false
    } else {
//        std::cerr << "Cannot Move Forward" << std::endl;
        return false;
    }
}

// Turn right
void fp::Maze::TurnRight() {
    robot_->TurnRight();
    fp::API::turnRight();

    int row = robot_->get_y();
    int col = robot_->get_x();
    int heading = (int)robot_->get_heading() + 1;
    if(heading > 3) heading = 0;

    char chars[4]{'n','e','s','w'};
    std::string strs[4]{"n","e","s","w"};

    // Automatically check 4th wall whenever it turns
    if (fp::Maze::Index(row, col).find(strs[heading]) == std::string::npos) {
        if (fp::Maze::CheckWall(static_cast<fp::LandBasedRobot::Dir>(heading))) {
            fp::Maze::Index(row, col) += strs[heading];
            fp::API::setWall(col, row, chars[heading]);
        }
    }
}

// Turn left
void fp::Maze::TurnLeft() {
    robot_->TurnLeft();
    fp::API::turnLeft();

    int row = robot_->get_y();
    int col = robot_->get_x();
    int heading = (int)robot_->get_heading() - 1;
    if(heading < 0) heading = 3;

    char chars[4]{'n','e','s','w'};
    std::string strs[4]{"n","e","s","w"};

    // Automatically check 4th wall whenever it turns
    if (fp::Maze::Index(row, col).find(strs[heading]) == std::string::npos) {
        if (fp::Maze::CheckWall(static_cast<fp::LandBasedRobot::Dir>(heading))){
            fp::Maze::Index(row, col) += strs[heading];
            fp::API::setWall(col, row, chars[heading]);
        }
    }
}

// Utility method for debugging
void fp::Maze::PrintMaze(){

    int curr_col = robot_->get_x();
    int curr_row = robot_->get_y();
    std::cerr << curr_row << std::endl;

    for (int row = height_-1; row > -1; row--){
        for (int col = 0; col < width_; col++){
            if(col == curr_col && row == curr_row){
                std::cerr << "R";
            } else {
                std::cerr << fp::Maze::Index(row, col);
            }
            std::cerr << " ";
        }
        std::cerr << std::endl;
    }
}

// Clear all maze colors
void fp::Maze::ClearAllColor() {
    API::clearAllColor();
}

// Set cell color
void fp::Maze::SetCellColor(std::array<int, 2> pos, char color) {
    API::setColor(pos[1],pos[0], color);
}

// Set colors of all goal cell
void fp::Maze::SetGoalColors() {
    fp::Maze::SetCellColor(std::array<int,2>{7,7}, 'c');
    fp::Maze::SetCellColor(std::array<int,2>{8,7}, 'c');
    fp::Maze::SetCellColor(std::array<int,2>{7,8}, 'c');
    fp::Maze::SetCellColor(std::array<int,2>{8,8}, 'c');
}

// Robot getter
fp::LandBasedRobot& fp::Maze::get_robot() {
    return *robot_;
}

// Goal position getter
std::array<int, 2> fp::Maze::get_goal_pos() {
    return goal_pos_;
}

// Grid getter
const std::vector<std::vector<std::string>>& fp::Maze::get_grid() {
    return grid_;
}