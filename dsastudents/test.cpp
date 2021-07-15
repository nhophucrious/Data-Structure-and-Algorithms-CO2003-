#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

#include "list/XArrayList.h"
#include "list/SLinkedList.h"
#include "list/DLinkedList.h"
#include "sorting/ISort.h"
#include "heap/Heap.h"
#include "heap/IHeap.h"
#include "sorting/HeapSort.h"
#include "sorting/BubbleSort.h"
#include "sorting/ShellSort.h"
#include "sorting/StraightInsertionSort.h"
#include "sorting/StraightSelectionSort.h"
#include "sorting/SLinkedListSE.h"
#include "sorting/DLinkedListSE.h"
#include "sorting/QuickSort.h"
#include "util/ArrayLib.h"
#include "geom/Vector3D.h"
#include <algorithm>

/*
NOTE:
  * SHOULD define other functions to support the implementation of "meter"
  * Parameters: read the explanation presented above
*/

template <typename T>
int Ascending(T &lhs, T &rhs)
{
    if (lhs < rhs)
        return -1;
    else if (lhs > rhs)
        return +1;
    else
        return 0;
}
template <typename T>
int Desending(T &lhs, T &rhs)
{
    if (lhs < rhs)
        return +1;
    else if (lhs > rhs)
        return -1;
    else
        return 0;
}
double LinearSort(ISort<int> *pSort, int *ptr_sizes, int size, int nexec = 10, int ntries = 10)
{
    duration<double> diff;
    int *random;
    for (int i = 0; i < nexec; i++)
    {
            random = genIntArray(ptr_sizes[size], 0, ptr_sizes[size] - 1);
            auto start = high_resolution_clock ::now();           //start counting time;
            pSort->sort(random, ptr_sizes[i], &Ascending);        // Do Sort operation
            auto end = high_resolution_clock ::now();             //end counting time
            diff += chrono::duration<double, milli>(end - start); //store and increase the differece                                  // return the size before adding
    }
    delete[] random;
    diff /= (nexec);
    return diff.count();
}
void meter(BubbleSort<int>* bubble,StraightInsertionSort<int>* insert,
 StraightSelectionSort<int> *selection,  ShellSort<int>* shell, HeapSort<int>* heap, QuickSort<int> *quick
string csvfile, int *ptr_sizes, int nsizes, int nexec = 10, int ntries = 10)
{
    cout << "\t\t\t\t\t\t\t\tA part of data sample:" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "index/nsizes:\t" << setw(6) << 'n' << "\t->" << setw(14) << "bubbleSort," << setw(14) << "insertionSort," << setw(14) << "selectionSort" << setw(14) << "shellSort" << setw(14) << "quickSort" << setw(14) << "S_mergeSort" << setw(14) << "D_mergeSort" << '\n';

    std::ofstream myfile;
    myfile.open(csvfile);
    myfile << "A_size,XarrayList,SLinkedList,DLinkedList(ms),BST(ms),AVL(ms)\n";
    for (int i = 0; i < nsizes; i++)
    {

        if (!(i % 10))
            cout
                << '[' << setw(2) << i << "/100]:\t" << setw(6) << ptr_sizes[i] << "\t->";
        if (!(i % 10))
        {
            cout << fixed << setw(13) << setprecision(8) << A_arp << ',';
            cout << fixed << setw(13) << setprecision(8) << S_arp << ',';
            cout << fixed << setw(13) << setprecision(8) << D_arp << ',';
            cout << fixed << setw(13) << setprecision(8) << BST << ',';
            cout << fixed << setw(13) << setprecision(8) << AVL << ',';
            cout << endl;
        }
        myfile << to_string(ptr_sizes[i]) << "," << A_arp << "," << S_arp << "," << D_arp << "," << BST << "," << AVL << '\n';
    }
    myfile.close();
    cout << "\t\t\t\t\t\t Printing the values into CSV files..." << endl;
}
/////////////////////////////////////////////////////////////////////////////
// YOUR ARE NOT REQUIRED TO CHANGE THE FOLLOWING FUNCTIONS
/////////////////////////////////////////////////////////////////////////////

int get_int(char **begin, char **end, const string &option, int _default)
{
    char **ptr = std::find(begin, end, option);
    if (ptr != end && ++ptr != end)
        return stoi(*ptr);
    else
        return _default;
}

int main(int argc, char **argv)
{
    int nsizes, nexec, max_length, ntries;

    nsizes = get_int(argv, argv + argc, "-nsizes", 50);
    nexec = get_int(argv, argv + argc, "-nexec", 20);
    max_length = get_int(argv, argv + argc, "-max_length", 1000);
    ntries = get_int(argv, argv + argc, "-ntries", 10);
    int *ptr_sizes = genIntArray(nsizes, 1, max_length);
    meter(&alist, &slist, &dlist, &bst, &avl, "Vector3DLT.csv", ptr_sizes, nsizes, nexec, ntries);
}