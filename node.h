Public:


//heuristic for A*
enum class HeuristicType {
  MisplacedTiles,
  EuclideanDistance
};


//new constructor
Node(const Puzzle& puzz, Node* par, int c, HeuristicType heuristic_type);