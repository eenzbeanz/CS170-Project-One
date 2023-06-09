#include <iostream>
#include <vector>
#include <string>
#include <queue>
// #include "Puzzle.h"
// #include "Node.h"
#include "Algorithm.h"

using namespace std;

int main() {

    int userInput;
    int zeroIndex = 0;
    vector<int> userPuzzle = {1,2,4,3,5,6,7,8,0};

    cout << "Welcome to the 8 puzzle solver!" << endl;
    cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << endl;
    cin >> userInput;

    if (userInput == 1) {
        cout << "Your puzzle is: " << endl;
        for (int i = 0; i < userPuzzle.size(); ++i) {
            cout << userPuzzle.at(i);
            if ((i == 2) || (i == 5)) {
                cout << endl;
            }
        }
        cout << endl;
    }

    else {
        int userNum;
        cout << "Enter the puzzle using spaces or tabs between numbers" << endl;

        for (int i = 0; i < 9; ++i) {
            cin >> userNum;
            if (userNum == 0) {
                zeroIndex = i;
            }
            userPuzzle.at(i) = userNum;
        }

        cout << "Your puzzle is: " << endl;
        for (int i = 0; i < userPuzzle.size(); ++i) {
            cout << userPuzzle.at(i);
            if ((i == 2) || (i == 5)) {
                cout << endl;
            }
        }
        cout << endl;
    }

    int userAlgorithm;

    cout << "Enter your choice of algorithm: " << endl;
    cout << "1 - Uniform Cost Search" << endl;
    cout << "2 - A* with the Misplaced Tile heuristic" << endl;
    cout << "3 - A* with the Euclidean distance heuristic" << endl;

    cin >> userAlgorithm;

    Algorithm solve_puzzle(userPuzzle);

    if (userAlgorithm == 1) {
        solve_puzzle.uniform_cost_search();
    }

    if (userAlgorithm == 2) {
        solve_puzzle.a_star_misplaced_tile();
    }

    if (userAlgorithm == 3) {
        solve_puzzle.a_star_search_euclid();
    }

    return 0;
}