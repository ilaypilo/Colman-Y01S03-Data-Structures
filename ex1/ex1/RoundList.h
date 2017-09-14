//
// Created by Bar Zrihan on 12/09/2017.
//

#ifndef Y01S03_ROUNDLIST_H
#define Y01S03_ROUNDLIST_H

#include <iostream>

using namespace std;

template<class T>
class RoundList {

    template<class E>
    class Item {
        Item<E> *_next;
        E _data;
    public:

        Item() : _next(NULL) {}

        Item(const E &data) : _next(NULL), _data(data) {}

        Item(const Item<E> &item) : _next(item.getNext()), _data(item.getData()) {}

        void setNext(Item<E> *next) { _next = next; }

        Item<E> *getNext() const { return _next; }

        void setData(const E &data) { _data = data; }

        const E &getData() const 
		{ 
			return _data; 
		}
    };

    Item<T> *_head;
    int _size;

public:
	RoundList() : _head(nullptr), _size(0) {}
    RoundList(const T &item) : _head(new Item<T>(item)), _size(1) 
	{ 
		_head->setNext(_head); 
	}

    class Iterator {
        Item<T> *p;
    public:
        Iterator(Item<T> *pt = NULL) : p(pt) {}

        Iterator operator++(int) 
		{
            Iterator temp = *this;
            p = p->getNext();
            return temp;
        }
        Item<T> * getPointer()
        {
            return p;
        }

        Iterator &operator++() {
            p = p->getNext();
            return *this;
        }

        const T &operator*() 
		{ 
			return p->getData(); 
		}

        friend class RoundList;

        int operator!=(Iterator itr) const 
		{
            return (p != itr.p);
        }
    };

    Iterator begin() 
	{ 
		return _head; 
	}

    void insert(const T &newItem) 
	{
		Item<T> *pNewItem = new Item<T>(newItem);
		if (!_head) 
		{
			_head = pNewItem;
			pNewItem->setNext(pNewItem);
		} 
		else 
		{
			auto tempNode = lastNode().p;
			pNewItem->setNext(tempNode->getNext());
			tempNode->setNext(pNewItem);
		}
		_size++;
    }

    int getSize() 
	{
        return _size;
    }
	Iterator lastNode() 
	{
		if (_size == 0)
		{
			throw exception("list is empty");
		}
		Iterator tempIt = begin();
		// find the pointer that his _next is the head
		while (tempIt.p->getNext() != begin().p)
		{
			tempIt++;
		}
		return tempIt;
	}
    void remove() 
	{
		if (_size == 0) 
		{
			throw exception("list is empty");
		} 
		if (_size == 1)
		{
			delete _head;
			_head = nullptr;
			_size--;
			return;
		}
        // point the last 
		lastNode().p->setNext(_head->getNext());
		auto tempHead = _head;
		_head = _head->getNext();
		delete tempHead;
        _size--;
    }

    ~RoundList() 
	{
        // Create two iterators, one for head and one for tail
		while (_size) 
		{
			remove();
		}

        delete _head;
    }

};


#endif //Y01S03_ROUNDLIST_H
