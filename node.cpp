// how to use heuristic for each case
Node::Node(const Puzzle& p, Node* par, int c, HeuristicType heuristic_type) {
  puzzle = p;
  parent = par;
  cost = c;


  if (heuristic_type == HeuristicType::MisplacedTiles) {
    h = get_heuristic(p);
  } else if (heuristic_type == HeuristicType::EuclideanDistance) {
    h = get_euclidean_heuristic(p);
  }


  priority = c + h;
}