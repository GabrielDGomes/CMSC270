#include <iostream>
#include <string>
#include <queue>
#ifndef BINARYSEARCHTREE_H_ // "header guards"
#define BINARYSEARCHTREE_H_ // prevents double inclusion

template <class T>
class BST
{
    struct Node
    {
        T _x;
        Node *_parent;
        Node *_left;
        Node *_right;
    };
    int _n;
    Node* _root;

public:
    // constructor
    BST();

    BST(T x);

    // destructor
    ~BST();

    Node *find(T x);

    void splice(Node *u);

    void remove_Node(Node *u);

    bool add_child(Node *p, Node *u);

    bool add(T x);

    Node *find_last(T x);

    void remove(T x);

    int size();

    void showNode(T x);

    void bf_tranverse();
};

template <class T>
BST<T>::BST()
{
    _n = 0;
}

template <class T>
BST<T>::BST(T x)
{
    _n = 0;
    _root = new Node;
    _root->_x = x;
    _root->_parent = nullptr;
    _root->_left = nullptr;
    _root->_right = nullptr;
}

template <class T>
BST<T>::~BST() {}

template <class T>
typename BST<T>::Node* BST<T>::find(T x)
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
            return currentNode;
        }
    }
    return nullptr;
}

template <class T>
bool BST<T>::add_child(Node *p, Node *u)
{
    if (p == nullptr)
    {
        _root = u;
    }
    else
    {
        if (u->_x < p->_x)
        {
            p->_left = u;
        }
        else if (u->_x > p->_x)
        {
            p->_right = u;
        }
        else
        {
            return false;
        }
        u->_parent = p;
    }
    _n++;
    return true;
}
template <class T>
bool BST<T>::add(T x)
{
    Node *p = find_last(x);
    Node *xNew = new Node;
    xNew->_x = x;
    xNew->_left = xNew->_right = nullptr;
    return add_child(p, xNew);
}

template<class T>
typename BST<T>::Node* BST<T>::find_last(T x) {
    Node *w = _root;
    Node *prev = new Node;
    while (w != nullptr){
        prev = w;
        if (x < w->_x){
            w = w->_left;
        }
        else if (x>w->_x)
        {
            w = w->_right;
        }
        else{
            return w;
        }
    }
    return prev;
}

template<class T>
void BST<T>::splice(Node *u)
{
    Node *s;
    Node *p;
    if (u->_left == nullptr)
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
    _n--;
}

template <class T>
void BST<T>::remove_Node(Node *u)
{
    Node *w;
    if ((u->_left == nullptr) || (u->_right == nullptr))
    {
        splice(u);
    }
    else
    {
        w = u->_right;
        while (w->_left != nullptr)
        {
            w = w->_left;
        }
        u->_x = w->_x;
        splice(w);
    }
}

template <class T>
void BST<T>::remove(T x)
{
    Node *u = find(x);
    remove_Node(u);
}

template <class T>
int BST<T>::size()
{
    return _n;
}

template <class T>
void BST<T>::showNode(T x)
{
    Node *u = find(x);

    if (u == nullptr)
    {
        std::cout << "Node not found." << std::endl;
        return;
    }

    std::cout << "Node value: " << u->_x << std::endl;

    if (u->_left == nullptr)
    {
        std::cout << "Left child: Null" << std::endl;
    }
    else
    {
        std::cout << "Left child: " << u->_left->_x << std::endl;
    }

    if (u->_right == nullptr)
    {
        std::cout << "Right child: Null" << std::endl;
    }
    else
    {
        std::cout << "Right child: " << u->_right->_x << std::endl;
    }

    if (u->_parent == nullptr)
    {
        std::cout << "Parent: Null" << std::endl;
    }
    else
    {
        std::cout << "Parent: " << u->_parent->_x << std::endl;
    }
}
template <class T>
void BST<T>::bf_tranverse()
{
    Node *r = _root;
    std::queue<Node*> q;

    if (r != nullptr)
    {
        q.push(r);
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
    std::cout << std::endl;
}
#endif /*BINARYSEARCHTREE_H_*/
