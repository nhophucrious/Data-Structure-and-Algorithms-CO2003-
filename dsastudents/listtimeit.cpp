#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

#include "list/XArrayList.h"
#include "list/SLinkedList.h"
#include "list/DLinkedList.h"
#include "list/IList.h"
#include "sorting/ISort.h"
#include "sorting/BubbleSort.h"
#include "sorting/StraightInsertionSort.h"
#include "sorting/StraightSelectionSort.h"
#include "sorting/ShellSort.h"
#include "sorting/QuickSort.h"
#include "sorting/DLinkedListSE.h"
#include "sorting/SLinkedListSE.h"
#include "sorting/HeapSort.h"
#include "util/ArrayLib.h"
#include <algorithm>

/*
NOTE:
  * SHOULD define other functions to support the implementation of "meter"
  * Parameters: read the explanation presented above
*/
double ArraySort(ISort<int> *psort, int *ptr_sizes, int size, int nexec = 10)
{
    duration<double> diff;
    int *random;
    for (int i = 0; i < nexec; i++)
    {
        random = genIntArray(ptr_sizes[size], 0, ptr_sizes[size] - 1);
        auto start = high_resolution_clock ::now();                                     //start counting time;
        psort->sort(random, ptr_sizes[size], &SortSimpleOrder<int>::compare4Ascending); // Do addfirst operation
        auto end = high_resolution_clock ::now();                                       //end counting time
        diff += chrono::duration<double, milli>(end - start);                           //store and increase the differece
        delete[] random;                                                                // return the size before adding
    }
    diff /= (nexec);
    return diff.count();
}
double SLListSort(SLinkedListSE<int> *pList, int *ptr_sizes, int size, int nexec = 10)
{
    pList->clear();
    int *genList = genIntArray(ptr_sizes[size], 0, ptr_sizes[size] - 1);
    duration<double> diff;
    for (int i = 0; i < ptr_sizes[size]; i++)
    {
        pList->add(genList[i]);
    }
    for (int i = 0; i < nexec; i++)
    {
        auto start = high_resolution_clock ::now();            //start counting time;
        pList->sort(&SortSimpleOrder<int>::compare4Ascending); // Do addfirst operation
        auto end = high_resolution_clock ::now();              //end counting time
        diff += chrono::duration<double, milli>(end - start);  //store and increase the differece                                  // return the size before adding
    }
    pList->clear();
    delete[] genList;
    diff /= (nexec);
    return diff.count();
}
double DLListSort(DLinkedListSE<int> *pList, int *ptr_sizes, int size, int nexec = 10)
{
    pList->clear();
    int *genList = genIntArray(ptr_sizes[size], 0, ptr_sizes[size] - 1);
    duration<double> diff;
    for (int i = 0; i < ptr_sizes[size]; i++)
    {
        pList->add(genList[i]);
    }
    for (int i = 0; i < nexec; i++)
    {
        auto start = high_resolution_clock ::now();            //start counting time;
        pList->sort(&SortSimpleOrder<int>::compare4Ascending); // Do addfirst operation
        auto end = high_resolution_clock ::now();              //end counting time
        diff += chrono::duration<double, milli>(end - start);  //store and increase the differece                                  // return the size before adding
    }
    pList->clear();
    delete[] genList;
    diff /= (nexec);
    return diff.count();
}
double ArraySortWorst(ISort<int> *psort, int *ptr_sizes, int size, int nexec = 10)
{
    duration<double> diff;
    int *random;
    for (int i = 0; i < nexec; i++)
    {
        random = genIntArray(ptr_sizes[size], 0, ptr_sizes[size] - 1);
        psort->sort(random, ptr_sizes[size], &SortSimpleOrder<int>::compare4Desending);
        auto start = high_resolution_clock ::now();                                     //start counting time;
        psort->sort(random, ptr_sizes[size], &SortSimpleOrder<int>::compare4Ascending); // Do addfirst operation
        auto end = high_resolution_clock ::now();                                       //end counting time
        diff += chrono::duration<double, milli>(end - start);                           //store and increase the differece
        delete[] random;                                                                // return the size before adding
    }
    diff /= (nexec);
    return diff.count();
}
double ArraySortBest(ISort<int> *psort, int *ptr_sizes, int size, int nexec = 10)
{
    duration<double> diff;
    int *random;
    for (int i = 0; i < nexec; i++)
    {
        random = genIntArray(ptr_sizes[size], 0, ptr_sizes[size] - 1);
        psort->sort(random, ptr_sizes[size], &SortSimpleOrder<int>::compare4Ascending);
        auto start = high_resolution_clock ::now();                                     //start counting time;
        psort->sort(random, ptr_sizes[size], &SortSimpleOrder<int>::compare4Ascending); // Do addfirst operation
        auto end = high_resolution_clock ::now();                                       //end counting time
        diff += chrono::duration<double, milli>(end - start);                           //store and increase the differece
        delete[] random;                                                                // return the size before adding
    }
    diff /= (nexec);
    return diff.count();
}
double DLListSortWorst(DLinkedListSE<int> *pList, int *ptr_sizes, int size, int nexec = 10)
{
    pList->clear();
    int *genList = genIntArray(ptr_sizes[size], 0, ptr_sizes[size] - 1);
    duration<double> diff;
    for (int i = 0; i < ptr_sizes[size]; i++)
    {
        pList->add(genList[i]);
    }
    pList->sort(&SortSimpleOrder<int>::compare4Desending);
    for (int i = 0; i < nexec; i++)
    {
        auto start = high_resolution_clock ::now();            //start counting time;
        pList->sort(&SortSimpleOrder<int>::compare4Ascending); // Do addfirst operation
        auto end = high_resolution_clock ::now();              //end counting time
        diff += chrono::duration<double, milli>(end - start);  //store and increase the differece                                  // return the size before adding
    }
    pList->clear();
    delete[] genList;
    diff /= (nexec);
    return diff.count();
}
double SLListSortWorst(SLinkedListSE<int> *pList, int *ptr_sizes, int size, int nexec = 10)
{
    pList->clear();
    int *genList = genIntArray(ptr_sizes[size], 0, ptr_sizes[size] - 1);
    duration<double> diff;
    for (int i = 0; i < ptr_sizes[size]; i++)
    {
        pList->add(genList[i]);
    }
    pList->sort(&SortSimpleOrder<int>::compare4Desending);
    for (int i = 0; i < nexec; i++)
    {
        auto start = high_resolution_clock ::now();            //start counting time;
        pList->sort(&SortSimpleOrder<int>::compare4Ascending); // Do addfirst operation
        auto end = high_resolution_clock ::now();              //end counting time
        diff += chrono::duration<double, milli>(end - start);  //store and increase the differece                                  // return the size before adding
    }
    delete[] genList;
    pList->clear();
    diff /= (nexec);
    return diff.count();
}
double SLListSortBest(SLinkedListSE<int> *pList, int *ptr_sizes, int size, int nexec = 10)
{
    pList->clear();
    int *genList = genIntArray(ptr_sizes[size], 0, ptr_sizes[size] - 1);
    duration<double> diff;
    for (int i = 0; i < ptr_sizes[size]; i++)
    {
        pList->add(genList[i]);
    }
    pList->sort(&SortSimpleOrder<int>::compare4Ascending);
    for (int i = 0; i < nexec; i++)
    {
        auto start = high_resolution_clock ::now();            //start counting time;
        pList->sort(&SortSimpleOrder<int>::compare4Ascending); // Do addfirst operation
        auto end = high_resolution_clock ::now();              //end counting time
        diff += chrono::duration<double, milli>(end - start);  //store and increase the differece                                  // return the size before adding
    }
    delete[] genList;
    pList->clear();
    diff /= (nexec);
    return diff.count();
}
double DLListSortBest(DLinkedListSE<int> *pList, int *ptr_sizes, int size, int nexec = 10)
{
    pList->clear();
    int *genList = genIntArray(ptr_sizes[size], 0, ptr_sizes[size] - 1);
    duration<double> diff;
    for (int i = 0; i < ptr_sizes[size]; i++)
    {
        pList->add(genList[i]);
    }
    pList->sort(&SortSimpleOrder<int>::compare4Ascending);
    for (int i = 0; i < nexec; i++)
    {
        auto start = high_resolution_clock ::now();            //start counting time;
        pList->sort(&SortSimpleOrder<int>::compare4Ascending); // Do addfirst operation
        auto end = high_resolution_clock ::now();              //end counting time
        diff += chrono::duration<double, milli>(end - start);  //store and increase the differece                                  // return the size before adding
    }
    pList->clear();
    delete[] genList;
    diff /= (nexec);
    return diff.count();
}

void meter(ISort<int> *bubble, ISort<int> *selection, ISort<int> *insertion,
           ISort<int> *shell, ISort<int> *heap, ISort<int> *quick, DLinkedListSE<int> *DSE,
           SLinkedListSE<int> *SSE,
           string csvfile, int *ptr_sizes, int nsizes, int nexec = 10)
{
    // cout << "\t\t\t\t\t\t\t\tA part of data sample:" << endl;
    // cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "index/nsizes:\t" << setw(6) << 'n' << "\t->" << setw(14) << "BubbleSort"
         << setw(14) << "InsertionSort" << setw(14) << "SelectionSort" << setw(14) << "ShellSort"
         << setw(14) << "HeapSort" << setw(14) << "QuickSort" << setw(14) << "S_MergeSort" << setw(14) << "D_MergeSort" << '\n';

    std::ofstream myfile;
    myfile.open(csvfile);
    myfile << "Size,Bubble,Insertion,Selection,Shell,Heap,Quick,S_MergeSort,D_MergeSort\n";
    for (int i = 0; i < nsizes; i++)
    {
        string bb = to_string(ArraySort(bubble, ptr_sizes, i, nexec));
        string isort = to_string(ArraySort(insertion, ptr_sizes, i, nexec));
        string ssort = to_string(ArraySort(selection, ptr_sizes, i, nexec));
        string shells = to_string(ArraySort(shell, ptr_sizes, i, nexec));
        string heaps = to_string(ArraySort(heap, ptr_sizes, i, nexec));
        string quicks = to_string(ArraySort(quick, ptr_sizes, i, nexec));
        string DList = to_string(DLListSort(DSE, ptr_sizes, i, nexec));
        string SList = to_string(SLListSort(SSE, ptr_sizes, i, nexec));
        if (!(i % 10))
            cout
                << '[' << setw(2) << i << "/100]:\t" << setw(6) << ptr_sizes[i] << "\t->";
        if (!(i % 10))
        {
            cout << fixed << setw(13) << setprecision(8) << bb << ',';
            cout << fixed << setw(13) << setprecision(8) << isort << ',';
            cout << fixed << setw(13) << setprecision(8) << ssort << ',';
            cout << fixed << setw(13) << setprecision(8) << shells << ',';
            cout << fixed << setw(13) << setprecision(8) << heaps << ',';
            cout << fixed << setw(13) << setprecision(8) << quicks << ',';
            cout << fixed << setw(13) << setprecision(8) << DList << ',';
            cout << fixed << setw(13) << setprecision(8) << SList << ',';
            cout << endl;
        }
        myfile << to_string(ptr_sizes[i]) << "," << bb << "," << isort << "," << ssort << "," << shells << ","
               << heaps << "," << quicks << "," << SList << "," << DList << '\n';
    }
    myfile.close();
    cout << "\t\t\t\t\t\t Printing the values into CSV files..." << endl;
}

void meterWorst(ISort<int> *bubble, ISort<int> *selection, ISort<int> *insertion,
                ISort<int> *shell, ISort<int> *heap, ISort<int> *quick, DLinkedListSE<int> *DSE,
                SLinkedListSE<int> *SSE,
                string csvfile, int *ptr_sizes, int nsizes, int nexec = 10)
{
    // cout << "\t\t\t\t\t\t\t\tA part of data sample WORST CASE:" << endl;
    // cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "index/nsizes:\t" << setw(6) << 'n' << "\t->" << setw(14) << "BubbleSort"
         << setw(14) << "InsertionSort" << setw(14) << "SelectionSort" << setw(14) << "ShellSort"
         << setw(14) << "HeapSort" << setw(14) << "QuickSort" << setw(14) << "S_MergeSort" << setw(14) << "D_MergeSort" << '\n';

    std::ofstream myfile;
    myfile.open(csvfile);
    myfile << "Size,Bubble,Insertion,Selection,Shell,Heap,Quick,S_MergeSort,D_MergeSort\n";
    for (int i = 0; i < nsizes; i++)
    {
        string bb = to_string(ArraySortWorst(bubble, ptr_sizes, i, nexec));
        string isort = to_string(ArraySortWorst(insertion, ptr_sizes, i, nexec));
        string ssort = to_string(ArraySortWorst(selection, ptr_sizes, i, nexec));
        string shells = to_string(ArraySortWorst(shell, ptr_sizes, i, nexec));
        string heaps = to_string(ArraySortWorst(heap, ptr_sizes, i, nexec));
        string quicks = to_string(ArraySortWorst(quick, ptr_sizes, i, nexec));
        string DList = to_string(DLListSortWorst(DSE, ptr_sizes, i, nexec));
        string SList = to_string(SLListSortWorst(SSE, ptr_sizes, i, nexec));
        if (!(i % 10))
            cout
                << '[' << setw(2) << i << "/100]:\t" << setw(6) << ptr_sizes[i] << "\t->";
        if (!(i % 10))
        {
            cout << fixed << setw(13) << setprecision(8) << bb << ',';
            cout << fixed << setw(13) << setprecision(8) << isort << ',';
            cout << fixed << setw(13) << setprecision(8) << ssort << ',';
            cout << fixed << setw(13) << setprecision(8) << shells << ',';
            cout << fixed << setw(13) << setprecision(8) << heaps << ',';
            cout << fixed << setw(13) << setprecision(8) << quicks << ',';
            cout << fixed << setw(13) << setprecision(8) << DList << ',';
            cout << fixed << setw(13) << setprecision(8) << SList << ',';
            cout << endl;
        }
        myfile << to_string(ptr_sizes[i]) << "," << bb << "," << isort << "," << ssort << "," << shells << ","
               << heaps << "," << quicks << "," << SList << "," << DList << '\n';
    }
    myfile.close();
    cout << "\t\t\t\t\t\t Printing the values into CSV files..." << endl;
}

void meterBest(ISort<int> *bubble, ISort<int> *selection, ISort<int> *insertion,
               ISort<int> *shell, ISort<int> *heap, ISort<int> *quick, DLinkedListSE<int> *DSE,
               SLinkedListSE<int> *SSE,
               string csvfile, int *ptr_sizes, int nsizes, int nexec = 10)
{
    // cout << "\t\t\t\t\t\t\t\tA part of data sample WORST CASE:" << endl;
    // cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "index/nsizes:\t" << setw(6) << 'n' << "\t->" << setw(14) << "BubbleSort"
         << setw(14) << "InsertionSort" << setw(14) << "SelectionSort" << setw(14) << "ShellSort"
         << setw(14) << "HeapSort" << setw(14) << "QuickSort" << setw(14) << "S_MergeSort" << setw(14) << "D_MergeSort" << '\n';

    std::ofstream myfile;
    myfile.open(csvfile);
    myfile << "Size,Bubble,Insertion,Selection,Shell,Heap,Quick,S_MergeSort,D_MergeSort\n";
    for (int i = 0; i < nsizes; i++)
    {
        string bb = to_string(ArraySortBest(bubble, ptr_sizes, i, nexec));
        string isort = to_string(ArraySortBest(insertion, ptr_sizes, i, nexec));
        string ssort = to_string(ArraySortBest(selection, ptr_sizes, i, nexec));
        string shells = to_string(ArraySortBest(shell, ptr_sizes, i, nexec));
        string heaps = to_string(ArraySortBest(heap, ptr_sizes, i, nexec));
        string quicks = to_string(ArraySortBest(quick, ptr_sizes, i, nexec));
        string DList = to_string(DLListSortBest(DSE, ptr_sizes, i, nexec));
        string SList = to_string(SLListSortBest(SSE, ptr_sizes, i, nexec));
        if (!(i % 10))
            cout
                << '[' << setw(2) << i << "/100]:\t" << setw(6) << ptr_sizes[i] << "\t->";
        if (!(i % 10))
        {
            cout << fixed << setw(13) << setprecision(8) << bb << ',';
            cout << fixed << setw(13) << setprecision(8) << isort << ',';
            cout << fixed << setw(13) << setprecision(8) << ssort << ',';
            cout << fixed << setw(13) << setprecision(8) << shells << ',';
            cout << fixed << setw(13) << setprecision(8) << heaps << ',';
            cout << fixed << setw(13) << setprecision(8) << quicks << ',';
            cout << fixed << setw(13) << setprecision(8) << DList << ',';
            cout << fixed << setw(13) << setprecision(8) << SList << ',';
            cout << endl;
        }
        myfile << to_string(ptr_sizes[i]) << "," << bb << "," << isort << "," << ssort << "," << shells << ","
               << heaps << "," << quicks << "," << SList << "," << DList << '\n';
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

string get_string(char **begin, char **end, const string &option, string _default)
{
    char **ptr = std::find(begin, end, option);
    if (ptr != end && ++ptr != end)
        return string(*ptr);
    else
        return _default;
}
bool option_exist(char **begin, char **end, const string &option)
{
    return std::find(begin, end, option) != end;
}

int main(int argc, char **argv)
{
    int nsizes, nexec, max_length, ntries;

    nsizes = get_int(argv, argv + argc, "-nsizes", 50);          //200
    nexec = get_int(argv, argv + argc, "-nexec", 20);            //200
    max_length = get_int(argv, argv + argc, "-max_length", 100); //10000
    // ntries = get_int(argv, argv + argc, "-ntries", 10);
    int *ptr_sizes = genIntArray(nsizes, 1, max_length);
    BubbleSort<int> bubble;
    StraightInsertionSort<int> insertion;
    StraightSelectionSort<int> selection;
    int num_segments[] = {1, 3, 7, 9, 11, 13, 15, 17, 19, 21};
    ShellSort<int> shell(num_segments, 10);
    HeapSort<int> heap;
    QuickSort<int> quick;
    SLinkedListSE<int> SList;
    DLinkedListSE<int> DList;

    if (option_exist(argv, argv + argc, "-n"))
    {
        cout << endl;
        cout << "Normal Case: Time measurement" << endl;
        cout << string(80, '-') << endl;

        string filename = get_string(argv, argv + argc, "-n", "");
        meter(&bubble, &selection, &insertion, &shell, &heap, &quick, &DList, &SList, filename, ptr_sizes, nsizes, nexec);
    }
    if (option_exist(argv, argv + argc, "-w"))
    {
        cout << endl;
        cout << "Worst Case: Time measurement" << endl;
        cout << string(80, '-') << endl;

        string filename = get_string(argv, argv + argc, "-w", "");
        meterWorst(&bubble, &selection, &insertion, &shell, &heap, &quick, &DList, &SList, filename, ptr_sizes, nsizes, nexec);
    }
    if (option_exist(argv, argv + argc, "-b"))
    {
        cout << endl;
        cout << "Best Case: Time measurement" << endl;
        cout << string(80, '-') << endl;
        string filename = get_string(argv, argv + argc, "-b", "");
        meterBest(&bubble, &selection, &insertion, &shell, &heap, &quick, &DList, &SList, filename, ptr_sizes, nsizes, nexec);
    }
}