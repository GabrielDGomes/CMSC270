#include <iostream>
#include <string>
#include <queue>

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

template <class T>
class BST
{
    struct Node
    {
        T _x;
        Node *_parent;
        Node *_left;
        Node *_right;

        Node(T x, Node *parent = nullptr, Node *left = nullptr, Node *right = nullptr)
            : _x(x), _parent(parent), _left(left), _right(right) {}
    };

    int _n;
    Node *_root;

public:
    // constructor
    BST();
    BST(T x);

    // destructor
    ~BST();

    // is x in the tree?
    bool isElement(T x) const;
    Node *find(T x) const;

    void splice(Node *u);
    void remove_Node(Node *u);
    bool add_child(Node *p, Node *u);
    bool add(T x);
    T remove(T x);

    int size() const;
    void showNode(T x) const;
    void bf_tranverse() const;
};

template <class T>
BST<T>::BST()
{
    _n = 0;
    _root = nullptr;
}

template <class T>
BST<T>::BST(T x)
{
    _n = 1;
    _root = new Node(x);
}

template <class T>
BST<T>::~BST()
{
    // TODO: Implement destructor to deallocate memory
}

template <class T>
bool BST<T>::isElement(T x) const
{
    Node *currentNode = _root;
    while (currentNode != nullptr)
    {
        if (x < currentNode->_x)
        {
            currentNode = currentNode->_left;
        }
        else if (x > currentNode->_x)
        {
            currentNode = currentNode->_right;
        }
        else
        {
            return true;
        }
    }
    return false;
}

template <class T>
typename BST<T>::Node *BST<T>::find(T x) const
{
    Node *w = _root;
    while (w != nullptr && w->_x != x)
    {
        if (x < w->_x)
        {
            w = w->_left;
        }
        else
        {
            w = w->_right;
        }
    }
    return w;
}

template <class T>
bool BST<T>::add_child(Node *p, Node *u)
{
    if (p == nullptr)
    {
        _root = u;
    }
    else if (u->_x < p->_x)
    {
        p->_left = u;
    }
    else if (u->_x > p->_x)
    {
        p->_right = u;
    }
    else
    {
        return false; // Duplicate value
    }
    u->_parent = p;
    _n++;
    return true;
}

template <class T>
bool BST<T>::add(T x)
{
    Node *p = find(x);
    Node *xNew = new Node(x);
    return add_child(p, xNew);
}

template <class T>
void BST<T>::splice(Node *u)
{
    Node *s, *p;
    if (u->_left != nullptr)
    {
        s = u->_left;
    }
    else
    {
        s = u->_right;
    }

    if (u == _root)
    {
        _root = s;
        p = nullptr;
    }
    else
    {
        p = u->_parent;
        if (p->_left == u)
        {
            p->_left = s;
        }
        else
        {
            p->_right = s;
        }
    }

    if (s != nullptr)
    {
        s->_parent = p;
    }

    delete u;
    _n--;
}

template <class T>
void BST<T>::remove_Node(Node *u)
{
    if (u->_left == nullptr || u->_right == nullptr)
    {
        splice(u);
    }
    else
    {
        Node *w = u->_right;
        while (w->_left != nullptr)
        {
            w = w->_left;
        }
        u->_x = w->_x;
        remove_Node(w);
    }
}

template <class T>
T BST<T>::remove(T x)
{
    Node *u = find(x);
    if (u == nullptr)
    {
        return T(); // Return default value for type T if element not found
    }
    remove_Node(u);
    return x;
}

template <class T>
int BST<T>::size() const
{
    return _n;
}

template <class T>
void BST<T>::showNode(T x) const
{
    Node *u = find(x);
    if (isElement(x)) {
        std::cout << "Node not found." << std::endl;
        return;
    }
    std::cout << "Parent: ";
    if (u->_parent != nullptr)
    {
        std::cout << u->_parent->_x;
    }
    else
    {
        std::cout << "Null";
    }
    std::cout << std::endl;
    std::cout << "Left child: ";
    if (u->_left != nullptr)
    {
        std::cout << u->_left->_x;
    }
    else
    {
        std::cout << "Null";
    }
    std::cout << std::endl;
    std::cout << "Right child: ";
    if (u->_right != nullptr)
    {
        std::cout << u->_right->_x;
    }
    else
    {
        std::cout << "Null";
    }
    std::cout << std::endl;
}




template <class T>
void BST<T>::bf_tranverse() const
{
    std::queue<Node *> q;
    if (_root != nullptr)
    {
        q.push(_root);
    }

    while (!q.empty())
    {
        Node *u = q.front();
        q.pop();

        std::cout << u->_x << " ";

        if (u->_left != nullptr)
        {
            q.push(u->_left);
        }

        if (u->_right != nullptr)
        {
            q.push(u->_right);
        }
    }
}

#endif /* BINARYSEARCHTREE_H_ */
