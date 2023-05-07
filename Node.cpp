#include "Node.h"
#include "Puzzle.h"
#include <iostream>

using namespace std;

Node::Node(const Puzzle& puzz, Node* par, int c) : puzzle(puzz), parent(par), cost(c), h(c + get_heuristic(puzz)) {}

//calculate h(n) as the # of misplaced tiles
int Node::get_heuristic(const Puzzle& puzz) {
 int hn = 0;

  //compares each index of the puzzle at i to the goal
 for (int i = 0; i < 9; ++i) {
     vector<int> currState = puzz.get_state();
   if (currState[i] != 0 && currState[i] != GOAL[i]) 
     hn++;
   }
    return hn;
}


// overloaded operator to check which h(n) is greater
bool Node::operator<(const Node& n) const {
  return h > n.h;
}
