//
// Created by Bar Zrihan on 12/09/2017.
//

#ifndef Y01S03_QUEUEROUNDLIST_H
#define Y01S03_QUEUEROUNDLIST_H

#include <iostream>
#include "RoundList.h"

using namespace std;

template<class T>
class QueueRoundList: public RoundList<T> {

public:
	QueueRoundList() : RoundList<T>() {}
    explicit QueueRoundList(const T &item): RoundList<T>(item) {}

	T dequeue() {
		if (this->getSize() == 0) 
		{
			throw exception("queue is empty");
		}
        auto poped = new T (*this->begin());
        this->remove();
        return *poped;
    }

    void enqueue(const T &newItem) 
	{
		insert(newItem);
    }

};


#endif //Y01S03_QUEUEROUNDLIST_H
