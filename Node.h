#ifndef _NODE_H__
#define _NODE_H__
#include "Puzzle.h"
#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
        Puzzle puzzle;

        Node* parent;
        int cost; // cost of path
        int h; // h(n) or heuristic 
        int priority; // priority = cost + h

        Node(const Puzzle& puzz, Node* par = nullptr, int c = 0);
        Node(const Puzzle& puzz, Node* par, int c, bool use_euclidean_distance); //add new constructor for this
        int get_heuristic(const Puzzle& puzz); // gets heuristic cost
        int get_euclidean_heuristic(const Puzzle& puzz); //add method for ED heurisitc
        bool operator<(const Node& n) const;

};

#endif
