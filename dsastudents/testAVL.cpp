#include <iostream>
using namespace std;
#include "list/SLinkedList.h"
#include"list/DLinkedList.h"
#include "sorting/BubbleSort.h"
#include "sorting/ShellSort.h"
#include "sorting/StraightInsertionSort.h"
#include "sorting/StraightSelectionSort.h"
#include "heap/Heap.h"
#include "util/sampleFunc.h"
#include "sorting/BubbleSortDemo.h"
#include "sorting/StraightInsertionSortDemo.h"
#include "sorting/StraightSelectionSortDemo.h"
#include "sorting/HeapSortDemo.h"
#include "sorting/ListSortDemo.h"
#include "hash/XHashMapDemo.h"
#include "hash/XHashMap.h"
#include "sorting/ShellSortDemo.h"
#include "sorting/XArrayListSE.h"
#include<iostream>
#include"hash/XHashMap.h"
#include"graph/UGraphModel.h"
using namespace std;

bool vertexEQ(int& lhs, int& rhs){
    return lhs == rhs;
}
string vertex2str(int& item){
    return std::to_string(item);
}
void quiz(){
    int vertices[] = {1, 2, 3, 4, 5};
    int from[] = {1, 2, 3, 3, 4};
    int to[]   = {3, 3, 4, 5, 5};
    int nedges = 4;
    UGraphModel<int> graph(&vertexEQ, &vertex2str);
    for(int v: vertices) graph.add(v);
    for(int idx=0; idx < nedges; idx++) graph.connect(from[idx], to[idx]);
    DLinkedList<typename UGraphModel<int>::VertexNode*>::Iterator it = graph.nodeList;
    while(it != graph.nodeList.end())
    {
        
        cout << "In Degree: " << (*it)->inDegree() << " ,Out Degree: " << (*it)->outDegree() << endl;
    }
}

int main()
{
    quiz();
    return 0;
}
