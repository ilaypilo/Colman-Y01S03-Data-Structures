//
// Created by Bar Zrihan on 12/09/2017.
//

#ifndef Y01S03_ROUNDLIST_H
#define Y01S03_ROUNDLIST_H


using namespace std;

template<class T>
class RoundList {

    template<class E>
    class Item {
        Item<E> *_next;
        Item<E> *_prev;
        E _data;
    public:

        Item() : _next(nullptr), _prev(nullptr) {}

        explicit Item(const E &data) : _next(nullptr), _prev(nullptr), _data(data) {}

        Item(const Item<E> &item) : _next(item.getNext()), _prev(item.getPrev()), _data(item.getData()) {}

        void setNext(Item<E> *next) { _next = next; }

        void setPrev(Item<E> *prev) { _prev = prev; }

        Item<E> *getNext() const { return _next; }

        Item<E> *getPrev() const { return _prev; }

        void setData(const E &data) { _data = data; }

        const E &getData() const { return _data; }
    };

    Item<T> *_head;
    int _size;

public:
    RoundList() : _head(new Item<T>(0)), _size(0) {
        _head->setNext(_head);
        _head->setPrev(_head);
    }

    explicit RoundList(const T &item) : _head(new Item<T>(item)), _size(1) {
        _head->setNext(_head);
        _head->setPrev(_head);
    }

    class Iterator {
        Item<T> *p;
    public:
        Iterator(Item<T> *pt = NULL) : p(pt) {}

        Iterator operator++(int) {
            Iterator temp = *this;
            p = p->getNext();
            return temp;
        }

        Item<T> *getPointer() {
            return p;
        }

        Iterator &operator++() {
            p = p->getNext();
            return *this;
        }

        Iterator &operator--() {
            p = p->getPrev();
            return *this;
        }

        const T &operator*() {
            return p->getData();
        }

        friend class RoundList;

        int operator!=(Iterator itr) const {
            return (p != itr.p);
        }
    };

    Iterator begin() {
        return _head;
    }

    Iterator end() {
        return _head->getPrev();
    }

    void insert(const T &newItem, Iterator it) {
        auto *pNewItem = new Item<T>(newItem);
        // if RoundList is empty
        if (!getSize()) {
            _head = pNewItem;
            _head->setNext(_head);
            _head->setPrev(_head);
            _size++;
            return;
        }

        pNewItem->setNext(it.p->getNext());
        pNewItem->setPrev(it.p);

        it.p->getNext()->setPrev(pNewItem);
        it.p->setNext(pNewItem);
        _size++;
    }

    Iterator remove(Iterator it) {
        if (it.p == _head) {
            if (getSize() == 1) {
                // make RoundList empty
//                _head->setData(nullptr);
                _size--;
                return nullptr;
            }
            _head = _head->getNext();
        }

        auto *nextitem = it.p->getNext();  // take next pointer to return to the user

        // take the pointer and point to the next item and prev item
        it.p->getPrev()->setNext(it.p->getNext());
        it.p->getNext()->setPrev(it.p->getPrev());

        // delete the Iterator
        delete it.p;
        _size--;
        return nextitem;
    }

    int getSize() { return _size; }

    virtual ~RoundList() {
        // Create two iterators, one for head and one for tail
        while (_size) { remove(begin()); }

        delete _head;
    }

};


#endif //Y01S03_ROUNDLIST_H