#include <iostream>
#include <ctime>
#include "Tree.h"

#define NUMBERS_TO_PUSH 50

int main() {

    // init random seed
    srand(time(nullptr));
    rand();
    rand();
    rand();

    // create array to store the numbers
    int numArr[NUMBERS_TO_PUSH];
    cout << "Array: " << endl;

    for (auto i = 0; i < NUMBERS_TO_PUSH; i++) {
	    auto num = rand() % 999 + 1;
        cout << num << ", ";
        numArr[i] = num;
    }

    // create binary tree
    auto myTree = new Tree<int>();

    cout << endl;

    // insert the array to the tree
    for (auto i = 0; i < NUMBERS_TO_PUSH; i++) {
        myTree->insert(numArr[i]);
    }
    cout << "BFS Tree Order: " << endl;
    myTree->printTreeBFSOrder();

    delete myTree;

    return 0;
}