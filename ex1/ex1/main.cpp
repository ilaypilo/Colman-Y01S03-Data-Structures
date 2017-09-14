#include <iostream>
#include <time.h>
#include <random>
#include "Tree.h"
#include "unittest.h"

int main() {

	// testing
	testTree();
	testQueueRoundList();

	// init random seed
	srand(time(nullptr));
	rand(); rand(); rand();
	// create vector list to store the numbers
    vector<int> numList({});
	// pick 50 random numbers
	for (auto i=0; i<50; i++)
	{
		numList.push_back(rand() % 999 +1);
	}
	
	// create binary tree
    auto myTree = new Tree<int>();

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
	
	myTree->printTreeBFSOrder();

	delete myTree;


    return 0;
}
