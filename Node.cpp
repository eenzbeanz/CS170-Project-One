#include "Node.h"
#include "Puzzle.h"


Puzzle::Puzzle() {
  state = {0,0,0,0,0,0,0,0,0};
  zero_pos = -1;
}


//Node::Node(const Puzzle& puzz, Node* par, int c) : puzzle(puzz), parent(par), cost(c), h(c + get_heuristic(puzz)) {}

Node::Node(const Puzzle& p, Node* par, int c) {
  puzzle = p;
  parent = par;
  cost = c;
  h = get_heuristic(p);
  int priority = c + h;
}

// calculate h(n) as the # of misplaced tiles
int Node::get_heuristic(const Puzzle& p) {
  int hn = 0;
  vector<int> GOAL =  {1,2,3,4,5,6,7,8,0};
 

  // compares each index of the puzzle at i to the goal
  for (int i = 0; i < 9; ++i) {
    if (p.state[i] != 0 && p.state[i] != GOAL[i]) {
      hn++;
    }
  }

  return hn;
}

// new constructor for euclidean distance heuristic
Node::Node(const Puzzle& p, Node* par, int c, bool use_euclidean_distance) {
  puzzle = p;
  parent = par;
  cost = c;
  h = get_euclidean_heuristic(p);
  priority = c + h;
}

// add method for euclidean distance heuristic
int Node::get_euclidean_heuristic(const Puzzle& p) {
  int hn = 0;


  for (int i = 0; i < 9; ++i) {
    int value = p.state[i];
    if (value != 0) {
      int targetX = (value - 1) / 3;
      int targetY = (value - 1) % 3;
      int currentX = i / 3;
      int currentY = i % 3;
      hn += sqrt((currentX - targetX) * (currentX - targetX) + (currentY - targetY) * (currentY - targetY));
    }
  }


  return hn;
}

// overloaded operator to check which h(n) is greater
bool Node::operator<(const Node& n) const {
  return h > n.h;
}