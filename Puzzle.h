#ifndef _PUZZLE_H__
#define _PUZZLE_H__
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;


//vector<int> GOAL =  {1,2,3,4,5,6,7,8,0};
 
class Puzzle {
    public:
        Puzzle(const vector<int> & start);
        Puzzle();
        //Puzzle puzzle;
        bool is_goal() const;
        vector<Puzzle> expand_children() const;
        void print_puzzle() const;
        vector<int> state; // current state
        int zero_pos; // position of zero
        int get_zero_pos(); // find position of zero
        vector<int> get_state();
};

#endif
