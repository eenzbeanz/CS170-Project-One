#include <iostream>
#include "Algorithm.h"

using namespace std;



Algorithm::Algorithm(const vector<int>& initial) {
    initial_node = new Node(Puzzle(initial));
    expanded_nodes = 0;
    max_nodes_queue = 0;
    goal_depth = 0;
}

void Algorithm::uniform_cost_search() {
    priority_queue<Node*> pq;
    vector<Node*> visited_nodes;
    int expanded_nodes = 0;
    int max_nodes_queue = 1;
    int goal_depth = 0;

    pq.push(initial_node);

    while (!pq.empty()) {
        Node* currNode = pq.top();
        pq.pop();
        max_nodes_queue = max_nodes_queue - 1;
        visited_nodes.push_back(currNode);

        if (currNode->puzzle.is_goal()) {
            cout << "FOUND GOAL!" << endl;
            currNode->puzzle.print_puzzle();
            break;
        }
        goal_depth++;

        vector<Puzzle> nodes = currNode->puzzle.expand_children();
        expanded_nodes++;
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
                max_nodes_queue++;
            }
            else {
                delete child;
            }
        }
    }

    cout << endl;
    cout << "To solve this problem the search algorithm expanded a total of " << expanded_nodes << " nodes." << endl;
    cout << "The maximum number of nodes in the queue at any one time was: " << max_nodes_queue << "." << endl;
    cout << "The depth of the goal node was: " << goal_depth << "." << endl;
}


void Algorithm::a_star_misplaced_tile() {
    priority_queue<Node*, vector<Node*>, greater<Node*>> pq;
    vector<Node*> visited_nodes;


    pq.push(initial_node);
    max_nodes_queue = 0;


    while (!pq.empty()) {
        Node* currNode = pq.top();
        pq.pop();
        visited_nodes.push_back(currNode);


        if (currNode->puzzle.is_goal()) {
            cout << "FOUND GOAL!" << endl;
            currNode->puzzle.print_puzzle();
            goal_depth = currNode->cost;
            break;
        }


        expanded_nodes++;
        cout << "Expanding this node: " << endl;
        currNode -> puzzle.print_puzzle();
        cout << "The best state to expand with g(n) = " << currNode->cost << " and h(n) = " << currNode->h << " is..." << endl;


        vector<Puzzle> nodes = currNode->puzzle.expand_children();


        // creating nodes for each child
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

    cout << endl;
    cout << "To solve this problem the search algorithm expanded a total of " << expanded_nodes << " nodes." << endl;
    cout << "The maximum number of nodes in the queue at any one time was: " << max_nodes_queue << "." << endl;
    cout << "The depth of the goal node was: " << goal_depth << "." << endl;
}


void Algorithm::a_star_search_euclid() {
    priority_queue<Node*, vector<Node*>, greater<Node*>> pq;
    vector<Node*> visited_nodes;


    pq.push(initial_node);


    while (!pq.empty()) {
        Node* currNode = pq.top();
        pq.pop();
        visited_nodes.push_back(currNode);


        if (currNode->puzzle.is_goal()) {
            cout << "FOUND GOAL!" << endl;
            currNode->puzzle.print_puzzle();
            break;
        }


        cout << "Expanding this node: " << endl;
        currNode->puzzle.print_puzzle();
        cout << "The best state to expand with g(n) = " << currNode->cost << " and h(n) = " << currNode->h << " is..." << endl;


        vector<Puzzle> nodes = currNode->puzzle.expand_children();


        for (int i = 0; i < nodes.size(); ++i) {
            Node* child = new Node(nodes.at(i), currNode, currNode->cost + 1, true); // Set last parameter to true to use Euclidean distance heuristic
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

    cout << endl;
    cout << "To solve this problem the search algorithm expanded a total of " << expanded_nodes << " nodes." << endl;
    cout << "The maximum number of nodes in the queue at any one time was: " << max_nodes_queue << "." << endl;
    cout << "The depth of the goal node was: " << goal_depth << "." << endl;
}