#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__
#include <iostream>
#include "Puzzle.h"
#include "Node.h"
#include <queue>

using namespace std;

class Algorithm {
    private:
        Node* initial_node;

    public:
        Algorithm(const vector<int>& initial); 
        void uniform_cost_search();
        void a_star_search();
        void a_star_search_euclid();
};

#endif