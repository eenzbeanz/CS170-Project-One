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
        priority_queue<Node> open_list;
        // a function that checks if node has been visited
        bool visited(const Node& node, const vector<Node>& closed_list);
        //mostly for output purposes
        int expanded_nodes; 
        int max_nodes_queue; 
        int goal_depth; 

    public:
        Algorithm(const vector<int>& initial); 
        void uniform_cost_search();
        void a_star_misplaced_tile();
        void a_star_search_euclid();
};

#endif
