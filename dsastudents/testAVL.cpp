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
int main()
{
    simpleMap();
    return 0;
}

vector<bool> check(size, false);
vector<uint8> sym;
vector<float> symfreq;
for(int i = 0; i < size; i++)
{
    if(check[i] == true) continue;
    int count = 1;
    sym.push_back(data[i]);
    for (int j = i + 1; j < n; j++)
    {
        if(data[j] == data[i])
        {
            check[j] = true;
            count++;
        }
    }
    symfreq.push_back(count);
}

vector<bool>met(sym.size(),false);
int count = 0;
while(count < sym.size())
{
    auto it = find(sym.begin(),sym.end(),min);
    int index = it - sym.begin();
    check[index] = true;
    min = 999;
    for (int i = 1; i < arr.size(); i++)
    {
        if(arr[i] < min && check[i] == false)
            min = arr[i];
    }
    count++;
}