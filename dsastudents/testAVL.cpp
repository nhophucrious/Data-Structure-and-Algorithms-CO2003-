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
using namespace std;

int main()
{
    XHashMap<int, int> map(&XHashMap<int,int>::simpleHash);
    cout << map.getCapacity() << endl;
    Pair<int, int> pairs[] = {
        Pair<int, int>(10, 20),
        Pair<int, int>(20, 40),
        Pair<int, int>(40, 80),
        Pair<int, int>(50, 100),
        Pair<int, int>(60, 120),
        Pair<int, int>(70, 140)};
    for(Pair<int, int> pair: pairs) map.put(pair.key, pair.value);
    map.println();
    // hashDemo1();
}
