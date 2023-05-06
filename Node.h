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

        Node(const Puzzle& puzz, Node* par = nullptr, int c = 0);
        int get_heuristic(const Puzzle& puzz); // gets heuristic cost
        bool operator<(const Node& n) const;
}