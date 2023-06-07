#include <iostream>
#include <string>
#include "BinarySearchTree.h"

class Test
{
    BST<int>* testTree;

public:
    Test(int x)
    {
        testTree = new BST<int>(x);
    }

    ~Test()
    {
        delete testTree;
    }

    bool addToTree(int x)
    {
        bool result = testTree->add(x);
        return result;
    }

    void showNode(int x)
    {
        testTree->showNode(x);
    }

    void bfs(){
        testTree->bf_tranverse();
    }
};

int main()
{
    Test tree1 = Test(50);
    tree1.addToTree(17);
    tree1.addToTree(72);
    tree1.addToTree(12);
    tree1.addToTree(9);
    tree1.addToTree(14);
    tree1.addToTree(23);
    tree1.addToTree(19);
    tree1.addToTree(76);
    tree1.addToTree(54);
    tree1.addToTree(67);

    tree1.showNode(9);
    tree1.showNode(50);
    tree1.showNode(72);
    tree1.showNode(33);

    tree1.bfs();
    return 0;
}