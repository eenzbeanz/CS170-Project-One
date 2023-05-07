struct Compare {
    bool operator()(const Node* a, const Node* b) const {
        return a->cost + a->h > b->cost + b->h;
    }
};


Algorithm::Algorithm(const vector<int>& initial) {
    initial_node = new Node(Puzzle(initial));
}


void Algorithm::a_star_misplaced_tile() {
    priority_queue<Node*, vector<Node*>, Compare> pq;
    vector<Node*> visited_nodes;
    int expanded_nodes = 0;
    int max_nodes_queue = 1;
    int goal_depth = 0;


    pq.push(initial_node);


    while (!pq.empty()) {
        Node* currNode = pq.top();
        pq.pop();
        max_nodes_queue = max(max_nodes_queue, static_cast<int>(pq.size()) + 1);
        visited_nodes.push_back(currNode);


        if (currNode->puzzle.is_goal()) {
            cout << "FOUND GOAL!";
            currNode->puzzle.print_puzzle();
            goal_depth = currNode->cost;
            break;
        }


        vector<Puzzle> nodes = currNode->puzzle.expand_children();
        expanded_nodes++;


        cout << endl << "The best state to expand with g(n) = " << currNode->cost << " and h(n) = " << currNode->h << " is..." << endl;
        cout << "Expanding this node: " << endl;
        currNode->puzzle.print_puzzle();


        for (int i = 0; i < nodes.size(); ++i) {
            Node* child = new Node(nodes.at(i), currNode, currNode->cost + 1);
            bool visited = false;


            for (int i = 0; i < visited_nodes.size(); ++i) {
                Node* tempVisitedNode = visited_nodes.at(i);
                if (tempVisitedNode->puzzle.get_state() == child->puzzle.get_state()) {
                    visited = true;
                    break;
                }
            }


            if (visited == false) {
                pq.push(child);
            } else {
                delete child;
            }
        }
    }


    cout << "To solve this problem the search algorithm expanded a total of " << expanded_nodes << " nodes." << endl;
    cout << "The maximum number of nodes in the queue at any one time was: " << max_nodes_queue << "." << endl;
    cout << "The depth of the goal node was: " << goal_depth << "." << endl;
}