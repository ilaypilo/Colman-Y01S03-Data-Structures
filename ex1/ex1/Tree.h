#pragma once
#include "TreeNode.h"
#include <fstream>
#include "QueueRoundList.h"


template <class T>
class Tree
{
    TreeNode<T>* _root;
public:
	Tree() : _root(nullptr) {};
    explicit Tree(T root) : _root(new TreeNode<T>(root)) {};
    ~Tree()
    {
        delete _root;
    }
    void insert(T & key)
	{
		// tree is empty
		if (!_root)
		{
			_root = new TreeNode<T>(key);
			_root->setLeft(nullptr);
			_root->setRight(nullptr);
		}
		else
		{
			_root->insert(key);
		}
    }
    void printTreeBFSOrder()
    {
        QueueRoundList<TreeNode<T>*> q(getRoot());

        while (q.getSize())
        {
            TreeNode<T>* tmp = q.dequeue();

            cout << tmp->getKey() << ", ";
            if (tmp->getLeft()){
                q.enqueue(tmp->getLeft());
            }
            if (tmp->getRight()){
                q.enqueue(tmp->getRight());
            }

        }
    }
    TreeNode<T>* getRoot() const
    {
        return _root;
    }
};
