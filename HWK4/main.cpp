#include <iostream>
#include <string>
#include "BinarySearchTree.h"

int main() {
    BST<int> tree1 = BST<int>(50); 
    tree1.add(17);
    tree1.add(12);
    tree1.add(9);
    tree1.add(14);
    tree1.add(19);
    tree1.add(23);
    tree1.add(72);
    tree1.add(76);
    tree1.add(54);
    tree1.add(12);
    tree1.add(67);

    tree1.showNode(50);
    
}