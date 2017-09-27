#pragma once

using namespace std;

template<class T>
class TreeNode {

private:

    T *_key;
    TreeNode<T> *_parent;
    TreeNode<T> *_left;
    TreeNode<T> *_right;

public:
    // children constructor
    TreeNode(TreeNode<T> *parent, T *key) : _parent(parent), _key(key), _left(nullptr), _right(nullptr) {
        _key = new T(*key);
    }

    // root constructor
    explicit TreeNode(T &key) : _parent(nullptr), _left(nullptr), _right(nullptr) {
        _key = new T(key);
    }

    // destructor
    ~TreeNode() {
        delete _left;
        delete _right;
        delete _key;
    };


    T getKey() const {
        return *_key;
    }

    void setKey(T key) {
        _key = key;
    }

    void insert(T &key) {
        if (key <= *_key) {
            if (!_left) {
                _left = new TreeNode<T>(key);
                _left->_parent = this;
            } else {
                _left->insert(key);
            }
        } else if (key > *_key) {
            if (!_right) {
                _right = new TreeNode<T>(key);
                _right->_parent = this;
            } else {
                _right->insert(key);
            }
        }
    }

    void setLeft(TreeNode<T> *left) {
        _left = left;
    }

    void setRight(TreeNode<T> *right) {
        _right = right;
    }

    TreeNode<T> *getLeft() const {
        return _left;
    }

    TreeNode<T> *getRight() const {
        return _right;
    }

    TreeNode<T> *getParent() const {
        return _parent;
    }
};