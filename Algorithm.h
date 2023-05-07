#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__
#include <iostream>
#include "Puzzle.h"
#include "Node.h"


using namespace std;


class Algorithm {
    private:
        Node* initial_node;
        int expanded_nodes; // total number of expanded nodes
        int max_nodes_queue; // maximum number of nodes in the queue at any one time
        int goal_depth; // depth of the goal node


    public:
        Algorithm(const vector<int>& initial); 
        void uniform_cost_search();
        void a_star_misplaced_tile(); // A* with Misplaced Tile heuristic function algo
        void a_star_search_euclid();
};


#endif