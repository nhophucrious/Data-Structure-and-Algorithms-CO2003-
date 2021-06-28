#include <iostream>
#include <tree/AVL.h>
#include <tree/BST.h>
#include <list/DLinkedList.h>
#include "geom/Point3D.h"

int main()
{
    int ptr[] = {10,52,98,32,68,92,40,13,42,63,99,100};
    AVL<int, int*> tree;
    for(int key: ptr) tree.add(key);
    tree.println();
    cout << endl;
    cout << "Value is: " << tree.remove(13) << endl;
    tree.println();
}