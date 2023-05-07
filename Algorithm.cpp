#include "Algorithm.h"

Algorithm::Algorithm(const vector<int>& initial) {
    initial_node = new Node(Puzzle(initial));
}

void Algorithm::uniform_cost_search() {
    priority_queue<Node*> pq;
    vector<Node*> visited_nodes;

    pq.push(initial_node);

    while (!pq.empty()) {
        Node* currNode = pq.top();
        pq.pop();
        visited_nodes.push_back(currNode);

        if (currNode->puzzle.is_goal()) {
            cout << "FOUND GOAL!";
            currNode->puzzle.print_puzzle();
            break;
        }

        vector<Puzzle> nodes = currNode->puzzle.expand_children();
        //print Expanding this puzzle (currNode)

        // creating nodes for each children
        for (int i = 0; i < nodes.size(); ++i) {
            Node* child = new Node(nodes.at(i), currNode, currNode->cost+1);
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
            }
            else {
                delete child;
            }
        }
    }
}



        