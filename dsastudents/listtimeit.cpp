#include <iostream>
#include <fstream>
#include <chrono>
#include <time.h>
using namespace std;
using namespace std::chrono;

#include "list/XArrayList.h"
#include "list/SLinkedList.h"
#include "list/DLinkedList.h"
#include "list/IList.h"
#include "util/ArrayLib.h"
#include <algorithm>

/*
NOTE:
  * SHOULD define other functions to support the implementation of "meter"
  * Parameters: read the explanation presented above
*/

int randomNumber(int size)
{
    int lower = 0;
    int upper = size - 1;
    srand(time(NULL));
    int number = (rand() % (upper - lower) + lower);
    return number;
}

double addRand(IList<int> *plist, string csvfile, int *ptr_sizes, int size, int nexec = 10, int ntries = 10)
{
    duration<double, milli> diff;
    // Fullfill a list
    for (int i = 0; i < ptr_sizes[size]; i++)
    {
        plist->add(1);
    }
    // loop for calculating the time
    for (int j = 0; j < nexec; j++)
    {
        for (int k = 0; k < ntries; k++)
        {
            int K = randomNumber(ptr_sizes[size]);
            auto start = high_resolution_clock ::now();           //start counting time;
            plist->add(K, 1);                                     // Do addfirst operation
            auto end = high_resolution_clock ::now();             //end counting time
            diff += chrono::duration<double, milli>(end - start); //store and increase the differece
            plist->removeAt(0);                                   // return the size before adding
        }
    }
    plist->clear(); // prepare to make a new list
    diff /= (nexec * ntries);
    return diff.count();
}
double addFirst(IList<int> *plist, string csvfile, int *ptr_sizes, int size, int nexec = 10, int ntries = 10)
{
    duration<double, milli> diff;
    // Fullfill a list
    for (int i = 0; i < ptr_sizes[size]; i++)
    {
        plist->add(1);
    }

    // loop for calculating the time
    for (int j = 0; j < nexec; j++)
    {
        auto start = high_resolution_clock ::now(); //start counting time;
        plist->add(0, 1);                           // Do addfirst operation;
        auto end = high_resolution_clock ::now();   //end counting time
        diff += chrono::duration<double, milli>(end - start);
        plist->removeAt(0); //remove the size before
    }
    plist->clear(); // prepare to make a new list
    diff /= (nexec);
    return diff.count();
}
double addLastPos(IList<int> *plist, string csvfile, int *ptr_sizes, int size, int nexec = 10, int ntries = 10)
{
    duration<double, milli> diff;
    // Fullfill a list
    for (int i = 0; i < ptr_sizes[size]; i++)
    {
        plist->add(1);
    }

    for (int j = 0; j < nexec; j++)
    {
        auto start = high_resolution_clock ::now(); //start counting time;
        plist->add(1);                              // Do addfirst operation
        auto end = high_resolution_clock ::now();   //end counting time
        diff += chrono::duration<double, milli>(end - start);
        plist->removeAt(0); //remove the size before
    }
    plist->clear(); // prepare to make a new list
    diff /= (nexec);
    return diff.count();
}
double removeFirstPos(IList<int> *plist, string csvfile, int *ptr_sizes, int size, int nexec = 10, int ntries = 10)
{
    duration<double, milli> diff;
    // Fullfill a list
    for (int i = 0; i < ptr_sizes[size]; i++)
    {
        plist->add(1);
    }

    // loop for calculating the time
    for (int j = 0; j < nexec; j++)
    {
        auto start = high_resolution_clock ::now(); //start counting time;
        plist->removeAt(0);                         // Do addfirst operation
        auto end = high_resolution_clock ::now();   //end counting time
        diff += chrono::duration<double, milli>(end - start);
        plist->add(1);
    }
    plist->clear(); // prepare to make a new list
    diff /= (nexec);
    return diff.count();
}

double removeLastPos(IList<int> *plist, string csvfile, int *ptr_sizes, int size, int nexec = 10, int ntries = 10)
{
    duration<double,milli> diff;
    // Fullfill a list
    for (int i = 0; i < ptr_sizes[size]; i++)
    {
        plist->add(1);
    }

    // loop for calculating the time
    for (int j = 0; j < nexec; j++)
    {
        auto start = high_resolution_clock ::now(); //start counting time;
        plist->removeAt(plist->size() - 1);         // Do addfirst operation
        auto end = high_resolution_clock ::now();   //end counting time
        diff += chrono::duration<double, milli>(end - start);
        plist->add(1);
    }
    plist->clear(); 
    diff /= (nexec);
    return diff.count();
}
double removeRandPos(IList<int> *plist, string csvfile, int *ptr_sizes, int size, int nexec = 10, int ntries = 10)
{
    duration<double,milli> diff;
    // Fullfill a list
    for (int i = 0; i < ptr_sizes[size]; i++)
    {
        plist->add(1);
    }
    // loop for calculating the time
    for (int j = 0; j < nexec; j++)
    {
        for (int k = 0; k < ntries; k++)
        {
            int K = randomNumber(ptr_sizes[size]);
            auto start = high_resolution_clock ::now(); //start counting time;
            plist->removeAt(K);                         // Do addfirst operation
            auto end = high_resolution_clock ::now();   //end counting time
            diff += chrono::duration<double, milli>(end - start); //store and increase the differece
            plist->add(1);                                        //restore the before size
        }
    }
    plist->clear(); // prepare to make a new list
    diff /= (nexec * ntries);
    return diff.count();
}
double getRandPos(IList<int> *plist, string csvfile, int *ptr_sizes, int size, int nexec = 10, int ntries = 10)
{
    duration<double,milli> diff;
    // Fullfill a list
    for (int i = 0; i < ptr_sizes[size]; i++)
    {
        plist->add(1);
    }
    // loop for calculating the time
    for (int j = 0; j < nexec; j++)
    {
        for (int k = 0; k < ntries; k++)
        {
            int K = randomNumber(ptr_sizes[size]);
            auto start = high_resolution_clock ::now(); //start counting time;
            plist->get(K);                              // Do addfirst operation
            auto end = high_resolution_clock ::now();   //end counting time
            diff += chrono::duration<double, milli>(end - start); //store and increase the differece                                        //restore the before size                    
        }
    }
    plist->clear(); // prepare to make a new list
    diff /= (nexec * ntries);
    return diff.count();
}
void meter(IList<int> *plist, string csvfile, int *ptr_sizes, int nsizes, int nexec = 10, int ntries = 10)
{
    //YOUR CODE HERE

    std::ofstream myfile;
    myfile.open(csvfile);
    myfile << "size,addfirst(ms),addlast(ms),addrandpos(ms),removefirst(ms),removelast(ms),removerandpos(ms),getrandpos(ms),\n";
    for (int i = 0; i < nsizes; i++)
    {
        string af = to_string(addFirst(plist, csvfile, ptr_sizes, i, nexec, ntries));
        string al = to_string(addLastPos(plist, csvfile, ptr_sizes, i, nexec, ntries));
        string arp = to_string(addRand(plist, csvfile, ptr_sizes, i, nexec, ntries));
        string rf = to_string(removeFirstPos(plist, csvfile, ptr_sizes, i, nexec, ntries));
        string rl = to_string(removeLastPos(plist, csvfile, ptr_sizes, i, nexec, ntries));
        string rrp = to_string(removeRandPos(plist, csvfile, ptr_sizes, i, nexec, ntries));
        string grp = to_string(getRandPos(plist, csvfile, ptr_sizes, i, nexec, ntries));
        myfile << to_string(ptr_sizes[i]) << "," << af << "," << al << "," << arp << "," << rf << "," << rl << "," << rrp << "," << grp << '\n';
    }
    myfile.close();
    cout << "\t\t\t Printing the values into CSV files..." << endl;
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
    if (option_exist(argv, argv + argc, "-h"))
    {
        cout << "Show help" << endl;
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////////
    int nsizes, nexec, max_length, ntries;
    XArrayList<int> alist;
    SLinkedList<int> slist;
    DLinkedList<int> dlist;

    nsizes = get_int(argv, argv + argc, "-nsizes", 50);
    nexec = get_int(argv, argv + argc, "-nexec", 20);
    max_length = get_int(argv, argv + argc, "-max_length", 1000);
    ntries = get_int(argv, argv + argc, "-ntries", 10);
    int *ptr_sizes = genIntArray(nsizes, 1, max_length);

    //cout << nsizes << ", " << nexec << ", " << max_length << ", " << ntries << endl;
    if (option_exist(argv, argv + argc, "-a"))
    {
        cout << endl;
        cout << "XArrayList: Time measurement" << endl;
        cout << string(80, '-') << endl;

        string filename = get_string(argv, argv + argc, "-a", "");
        meter(&alist, filename, ptr_sizes, nsizes, nexec, ntries);
    }
    if (option_exist(argv, argv + argc, "-s"))
    {
        cout << endl;
        cout << "SLinkedList: Time measurement" << endl;
        cout << string(80, '-') << endl;

        string filename = get_string(argv, argv + argc, "-s", "");
        meter(&slist, filename, ptr_sizes, nsizes, nexec, ntries);
    }
    if (option_exist(argv, argv + argc, "-d"))
    {
        cout << endl;
        cout << "DLinkedList: Time measurement" << endl;
        cout << string(80, '-') << endl;
        string filename = get_string(argv, argv + argc, "-d", "");
        meter(&dlist, filename, ptr_sizes, nsizes, nexec, ntries);
    }
}