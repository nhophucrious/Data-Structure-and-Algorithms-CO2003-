#include <iostream>
#include <iomanip>
#include <sstream>
#include "tree/BST.h"
#include "tree/AVL.h"
#include "list/DLinkedList.h"
#include "geom/Point3D.h"
#include "geom/Vector3D.h"
#include "stacknqueue/Stack.h"
#include "stacknqueue/Queue.h"

using namespace std;

/*
      10
     /  \
    5    20
           \
            50
            /
          20
 
 
 
 */
void demo_tree_1(){
    BST<int, int*> tree;
    int ptr[] = {10, 20, 50, 5, 20, 60};
    for(int key: ptr) tree.add(key, new int(key*2));
    tree.println();
    bool found = false;
    //int* value = tree.remove(20, &found);
    int* value = tree.search(20, found);
    cout << (found? "Key: Found" : "Key: Not found") << endl;
    if(found && (value != NULL)){
        cout << "Found Value: " << *value << endl;
    }
    
}

string value2str(int*& value){
    stringstream os;
    os << *value;
    return os.str();
}
void demo_tree_2(){
    BST<int, int*> tree;
    int ptr[] = {10, 20, 50, 5, 20, 60};
    for(int key: ptr) tree.add(key, new int(key*2));
    tree.println();
    DLinkedList<int*> alist = tree.ascendingList();
    DLinkedList<int*> dlist = tree.descendingList();
    alist.println(&value2str);
    dlist.println(&value2str);
    
}


/*
 * Store vectors in 3D-Space in the BST
 *  key: length of vectors
 *  value: vectors
 v = [2, 0, 0]
  => length: 2
 */

void tree_vector(){
    BST<float, Vector3D*> tree;
    int size = 10;
    Vector3D* ptr = Vector3D::genVectors(size, -10, +10);
    for(int idx =0; idx < size; idx++){
        tree.add(ptr[idx].length(), new Vector3D(ptr[idx]));
    }
    DLinkedList<float> list = tree.bfsKey();
    float total = 0;
    //O(size^2)
    /*
     for(int idx=0; idx < list.size(); idx++) total += list.get(idx);
     #iterations:
     get(0): 1
     get(1): 2
     get(2): 3
     ....
     SUM = 1 + 2 + ... + size-1 = (size-1)size/2
    */
    
    //O(n)
    DLinkedList<float>::Iterator it;
    for(it=list.begin(); it != list.end(); it++) total +=  *it;
    cout << "average: " << total/list.size() << endl;
    
    
}

string vec2str(Vector3D*& vec){
    stringstream os;
    os << vec->length();
    return os.str();
}
void tree_vector_2(){
    BST<float, Vector3D*> tree;
    int size = 10;
    Vector3D* ptr = Vector3D::genVectors(size, -10, +10);
    for(int idx =0; idx < size; idx++){
        tree.add(ptr[idx].length(), new Vector3D(ptr[idx]));
    }
    //tree.println();
    //select vectors with length within [5, 10]
    DLinkedList<Vector3D*> all = tree.bfs();
    all.println(&vec2str);
    
    DLinkedList<Vector3D*> list = tree.select(5,10);
    list.println(&vec2str);
    
}



void demo_tree_3(){
    AVL<int, int*> tree;
    int size = 1000;
    for(int key=0; key < size; key++) tree.add(key);
    cout << "Height: " << tree.height() << endl;
    
}

int main(int arc, char** argv){
    tree_vector_2();
    return 0;
}

/*
      10
      / \
     5   20
    / \   \
   1   7   50
 * 
 * key to remove: 55
 * key to remove: 7
 * key to remove: 10
 
 * 
 *     10
      /  \
     5   20
    /     \
   1      50
 * 
      10
      / \
     1   20
      \   \
       7   50
         
 *
 */