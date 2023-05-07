#include "Puzzle.h"
//#include "Node.h"

Puzzle::Puzzle(const vector<int>& start_state) : state(start_state), zero_pos(get_zero_pos()) {}

int Puzzle::get_zero_pos() {
    for (int i = 0; i < 9; ++i) {
        if (state[i] == 0) {
            return i;
        }
    }
    return -666;
}

vector<int> Puzzle::get_state(){  //GET THIS CHECKED
    return state;
}

vector<Puzzle> Puzzle::expand_children() const {
    vector<Puzzle> children; // push all children into this vector to be sorted in queue

    // moves zero position up and pushes it to into vector of puzzles
    if (zero_pos >= 3) {
        Puzzle puzz(state);
        swap(puzz.state[zero_pos], puzz.state[zero_pos - 3]); //figure out if p state = puzz state
        children.push_back(puzz); 
    }

    // moves zero position down and pushes it into vector of puzzles
    if (zero_pos <= 5) {
        Puzzle puzz(state);
        swap(puzz.state[zero_pos], puzz.state[zero_pos + 3]);
        children.push_back(puzz);
    }

    // moves zero position left and pushes it into vector of puzzles
    if (zero_pos >= 1 && zero_pos != 3 && zero_pos != 6) {
        Puzzle puzz(state);
        swap(puzz.state[zero_pos], puzz.state[zero_pos - 1]);
        children.push_back(puzz);
    }

    // moves zero position right and pushes it into vector of puzzles
    if (zero_pos <= 7 && zero_pos != 2 && zero_pos != 5) {
        Puzzle puzz(state);
        swap(puzz.state[zero_pos], puzz.state[zero_pos + 1]);
        children.push_back(puzz);
    }

    return children;
}

// compares indices of state to the goal, returns true if matches
bool Puzzle::is_goal() const {
    vector<int> GOAL =  {1,2,3,4,5,6,7,8,0};
 
    bool goal = true;
    for (int i = 0; i < 9; ++i) {
        if (state.at(i) != GOAL.at(i)) {
            goal = false;
        }
    }
    return goal;
}

void Puzzle::print_puzzle() const {
    for (int i = 0; i < 9; ++i) {
        cout << state.at(i) << " ";
        if ((i == 2) || (i == 5)) {
            cout << endl;
        }
    }
}
