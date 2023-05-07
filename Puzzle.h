#ifndef _PUZZLE_H__
#define _PUZZLE_H__
#include "Node.h"
#include <iostream>
#include <vector>

using namespace std;

const int GOAL[9] = {1,2,3,4,5,6,7,8,0};

class Puzzle {
    private:
        vector<int> state; // current state
        int zero_pos; // position of zero
        int get_zero_pos(); // find position of zero

    public:
        Puzzle(const std::vector<int>& start_state);
        bool is_goal() const;
        vector<Puzzle> expand_children() const;
        void print_puzzle() const;
        vector<int> get_state() const;
};

#endif