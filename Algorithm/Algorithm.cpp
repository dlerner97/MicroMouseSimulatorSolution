//
// Created by dani on 12/8/20.
//

#include "Algorithm.h"
#include <array>
#include <string>
#include <chrono>

// Index the "visited" grid with custom coordinate system
std::_Bit_reference fp::Algorithm::IndexVisited(int row, int col) {
    return visited_[height_ - 1 - row][col];
}

// Find path between current position and center with recursion
bool fp::Algorithm::FindSinglePath(int new_row, int new_col) {

    std::array<int,2> goal_pos = maze_->get_goal_pos();
    std::vector<std::vector<std::string>> temp_grid = maze_->get_grid();

    // If currently at the goal position, return true
    if(new_row == goal_pos[1] && new_col == goal_pos[0]) {
        stack_.push(std::array<int, 2>{new_row, new_col});
        return true;
    }

    // If the previous move is illegal (i.e leave map, hit visited block), return false
    else if (new_row >= height_ || new_row < 0 || new_col >= width_ || new_col < 0 || fp::Algorithm::IndexVisited(new_row, new_col)) {
//        std::cerr << "nr: "<< new_row << " nc: " << new_col << std::endl;
        return false;
    }

    // When generating new path plan, take priority away from last visited direction to optimize algorithm
    std::array<bool, 4> priority{true, true, true, true};
    int opposite_heading{prev_heading_};
    bool check_last_dir{false};

    std::array<int, 4> row_opposite_heading{1, 0, -1, 0};
    std::array<int, 4> col_opposite_heading{0, 1, 0, -1};

    if (first_iter_) {
        opposite_heading += 2;
        if(opposite_heading == 4) opposite_heading = 0;
        else if (opposite_heading == 5) opposite_heading = 1;

        priority[opposite_heading] = false;
        first_iter_ = false;
        check_last_dir = true;
    }

    // Set the cell to "visited"
    fp::Algorithm::IndexVisited(new_row, new_col) = true;

    // Add cell to stack
    stack_.push(std::array<int,2>{new_row, new_col});

    // Get the wall positions from the map class
    std::string surr_walls = maze_->Index(new_row, new_col);

    // Create new branch. Go in any allowed direction.

    // Go south
    if (priority[2] && surr_walls.find("s") == std::string::npos && FindSinglePath(new_row-1, new_col)) return true;

    // Go east
    else if (priority[1] && surr_walls.find("e") == std::string::npos && FindSinglePath(new_row, new_col+1)) return true;

    // Go north
    else if (priority[0] && surr_walls.find("n") == std::string::npos && FindSinglePath(new_row+1, new_col)) return true;

    // Go south
    else if (priority[3] && surr_walls.find("w") == std::string::npos && FindSinglePath(new_row, new_col-1)) return true;

    // If direction loses priority, implement it here.
    else if (check_last_dir && FindSinglePath(new_row+row_opposite_heading[opposite_heading], new_col+col_opposite_heading[opposite_heading])) return true;

    // If no direction allowed, take cell off stack and backtrack/cut off branch
    stack_.pop();
    return false;
}

// Execute the path. Starts with a path plan and ends by moving the mouse
std::array<bool,2> fp::Algorithm::ExecutePath() {

//    std::cerr << "Finding New Path..." << std::endl;

    // Reset visited matrix
    for(int row = 0; row < height_; row++) {
        for(int col = 0; col < width_; col++) {
            fp::Algorithm::IndexVisited(row, col) = false;
        }
    }

    // Get robot info
    int col = maze_->get_robot().get_x();
    int row = maze_->get_robot().get_y();
    int heading = maze_->get_robot().get_int_heading();

    // Find single path if available. Else no paths available
    first_iter_ = true;
    bool can_find_path = fp::Algorithm::FindSinglePath(row, col);
    if(!can_find_path) return std::array<bool, 2> {false, false};

//    fp::Algorithm::PrintVisited();

//    std::cerr << "Executing Path..." << std::endl;

    // Reverse stack
    std::stack<std::array<int,2>> temp_stack;
    while(!stack_.empty()) {
        std::array<int,2> next_loc{stack_.top()};
        maze_->SetCellColor(next_loc, 'r');
        temp_stack.push(next_loc);
        stack_.pop();
    }
    maze_->SetGoalColors();
    temp_stack.pop();

    // Move the robot while the stack has positions
    while(!temp_stack.empty()) {
        std::array<int, 2> next_loc{temp_stack.top()};

        temp_stack.pop();
        int row_next{next_loc[0]};
        int col_next{next_loc[1]};
        int delta_row{row_next - row};
        int delta_col{col_next - col};

        int dir;

        // Find the direction of the next cell
        if (delta_col == 1) {
            dir = 1;
        } else if (delta_col == -1) {
            dir = 3;
        } else if (delta_row == 1) {
            dir = 0;
        } else if (delta_row == -1){
            dir = 2;
        } else {
            continue;
        }

        // Turn the robot according to the direction we must go in
        int delta_heading{dir - heading};

        if(delta_heading == 1 || delta_heading == -3){
            maze_->TurnRight();
        }
        else if(delta_heading==-1 || delta_heading==3){
            maze_->TurnLeft();
        } else if (delta_heading == 2 || delta_heading == -2) {
            maze_->TurnLeft();
            maze_->TurnLeft();
        }

        // Store previous heading for priority
        prev_heading_ = heading;
        heading = maze_->get_robot().get_int_heading();

        // Now that our orientation is correct, move forward if possible
        if(!maze_->GoForward()) {
            // If not, clear map and return false
            maze_->ClearAllColor();
            maze_->SetGoalColors();
            return std::array<bool,2> {false, can_find_path};
        }

        // If we can, check for walls in new location and continue the while loop
        maze_->CheckAllWalls();

        // Increment row
        row += delta_row;
        col += delta_col;

    }
    return std::array<bool,2> {true, can_find_path};
}

// Full path planning algorithm
bool fp::Algorithm::FindCenter() {
    auto start = std::chrono::high_resolution_clock::now();
    std::array<bool,2> end_conditions{false, true};
    int counter = 0;

    // While we can find a path and when we finish a plan execution, execute a new path
    while(!end_conditions[0] && end_conditions[1]) {
        counter++;
        end_conditions = fp::Algorithm::ExecutePath();
    }
    std::cerr << counter << std::endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop-start);
    std::cerr << duration.count() << std::endl;
    if (!end_conditions[1]) {
        std::cerr << "Cannot find path :(" << std::endl;
    } else {
        std::cerr << "Done!!!" << std::endl;
    }
}

// Helpful utility method for debugging
void fp::Algorithm::PrintVisited(){
    int goal_x = maze_->get_goal_pos()[0];
    int goal_y = maze_->get_goal_pos()[1];
    int curr_col = maze_->get_robot().get_x();
    int curr_row = maze_-> get_robot().get_y();
    for (int row = height_-1; row > -1; row--){
        for (int col = 0; col < width_; col++){
            if (row == goal_y && col == goal_x) {
                std::cerr << 'G';
            } else if (row == curr_row && col == curr_col) {
                std::cerr << 'R';
            } else
                std::cerr << fp::Algorithm::IndexVisited(row, col);
            std::cerr << " ";
        }
        std::cerr << std::endl;
    }
}