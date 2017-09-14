#include <iostream>
#include <time.h>
#include <random>
#include "Tree.h"
#include "unittest.h"

#define NUMBERS_TO_PUSH 50

int main() {

	// testing
	testTree();
	testQueueRoundList();

	// init random seed
	srand(time(nullptr));
	rand(); rand(); rand();
	// create vector list to store the numbers
    vector<int> numList({});
	cout << "Array: " << endl;
	// pick 50 random numbers
	for (auto i=0; i<NUMBERS_TO_PUSH; i++)
	{
		auto num = rand() % 999 + 1;
		cout << num << ", ";
		numList.push_back(num);
	}
	
	// create binary tree
    auto myTree = new Tree<int>();

	cout << endl;

	// insert the array to the tree
    for (auto num : numList)
    {
		try
		{
			myTree->insert(num);
		}
		catch (exception &e)
		{
			cout << num << " " << e.what() << endl;
		}
        
    }
	cout << "BFS Tree Order: " << endl;
	myTree->printTreeBFSOrder();

	delete myTree;


    return 0;
}
