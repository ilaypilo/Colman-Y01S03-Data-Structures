//
// Created by Bar Zrihan on 12/09/2017.
//

#ifndef Y01S03_QUEUEROUNDLIST_H
#define Y01S03_QUEUEROUNDLIST_H

#include "RoundList.h"

using namespace std;

template<class T>
class QueueRoundList : public RoundList<T> {

public:
    QueueRoundList() : RoundList<T>() {}

    explicit QueueRoundList(const T &item) : RoundList<T>(item) {}

    T dequeue() {
        if (this->getSize() == 0) throw "queue is empty";

        auto poped = this->begin().getPointer()->getData();
        this->remove(this->begin());
        return poped;
    }

    void enqueue(const T &newItem) {
        this->insert(newItem, this->end());
    }

    ~QueueRoundList() {
        while (this->getSize()) {
            this->dequeue();
        }
    }
};


#endif //Y01S03_QUEUEROUNDLIST_H