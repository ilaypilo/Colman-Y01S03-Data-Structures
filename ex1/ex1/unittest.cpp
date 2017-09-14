#include <vector>
#include "Tree.h"
#include "unittest.h"
void testTree()
{
	std::vector<int> numList({ 45,89,14,23,78,90,1 });
	auto myTree = new Tree<int>(50);

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
}
void testQueueRoundList()
{

	auto quro = new QueueRoundList<int>();

	quro->enqueue(3);
	quro->enqueue(29);
	quro->enqueue(66);
	auto bla1 = quro->dequeue();
	auto bla2 = quro->dequeue();
	auto bla3 = quro->dequeue();
	try
	{
		quro->dequeue();
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	delete quro;

}