#include <iostream>
#include "Algorithm.h"
#include "Puzzle.h"

using namespace std;

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
            cout << "FOUND GOAL :) ";
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

// A* misplaced tile algo
void Algorithm::a_star_misplaced_tile() {
    priority_queue<Node*, vector<Node*>, greater<Node*>> pq;
    vector<Node*> visited_nodes;

    pq.push(initial_node);
    max_nodes_queue = 1;

    while (!pq.empty()) {
        Node* currNode = pq.top();
        pq.pop();
        visited_nodes.push_back(currNode);


        if (currNode->puzzle.is_goal()) {
            cout << "FOUND GOAL :)";
            currNode->puzzle.print_puzzle();
            goal_depth = currNode->cost;
            break;
        }

        expanded_nodes++;
        cout << "Expanding this node: " << endl;
        currNode->puzzle.print_puzzle();
        cout << "The best state to expand with g(n) = " << currNode->cost << " and h(n) = " << currNode->h << " is..." << endl;

        vector<Puzzle> nodes = currNode->puzzle.expand_children();


        // creating the nodes for each child
        for (int i = 0; i < nodes.size(); ++i) {
            Node* child = new Node(nodes.at(i), currNode, currNode->cost+1);
            child->priority = child->cost + child->h; // Update the priority for A*
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
                max_nodes_queue = max(max_nodes_queue, static_cast<int>(pq.size()));
            }
            else {
                delete child;
            }
        }
    }

    //outputing end statistics
    cout << "To solve this problem the search algorithm expanded a total of " << expanded_nodes << " nodes." << endl;
    cout << "The maximum number of nodes in the queue at any one time was: " << max_nodes_queue << "." << endl;
    cout << "The depth of the goal node was: " << goal_depth << "." << endl;
}

        
