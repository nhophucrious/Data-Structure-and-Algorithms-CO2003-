#include <iostream>
#include <fstream>
#include <chrono>
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
    duration<double> diff;
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
    duration<double> diff;
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
    duration<double> diff;
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
    duration<double> diff;
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
    duration<double> diff;
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
    duration<double> diff;
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
            plist->removeAt(K);                                   // Do addfirst operation
            auto end = high_resolution_clock ::now();             //end counting time
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
    duration<double> diff;
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
            plist->get(K);                                        // Do addfirst operation
            auto end = high_resolution_clock ::now();             //end counting time
            diff += chrono::duration<double, milli>(end - start); //store and increase the differece                                        //restore the before size
        }
    }
    plist->clear(); // prepare to make a new list
    diff /= (nexec * ntries);
    return diff.count();
}
double getFirst(IList<int> *plist, string csvfile, int *ptr_sizes, int size, int nexec = 10, int ntries = 10)
{
    duration<double> diff;
    // Fullfill a list
    for (int i = 0; i < ptr_sizes[size]; i++)
    {
        plist->add(1);
    }

    // loop for calculating the time
    for (int j = 0; j < nexec; j++)
    {
        auto start = high_resolution_clock ::now(); //start counting time;
        plist->get(0);                           // Do addfirst operation;
        auto end = high_resolution_clock ::now();   //end counting time
        diff += chrono::duration<double,milli>(end - start);
    }
    plist->clear(); // prepare to make a new list
    diff /= (nexec);
    return diff.count();
}
double getLast(IList<int> *plist, string csvfile, int *ptr_sizes, int size, int nexec = 10, int ntries = 10)
{
    duration<double> diff;
    // Fullfill a list
    for (int i = 0; i < ptr_sizes[size]; i++)
    {
        plist->add(1);
    }

    // loop for calculating the time
    for (int j = 0; j < nexec; j++)
    {
        auto start = high_resolution_clock ::now(); //start counting time;
        plist->get(plist->size()-1);                           // Do addfirst operation;
        auto end = high_resolution_clock ::now();   //end counting time
        diff += chrono::duration<double, milli>(end - start);
    }
    plist->clear(); // prepare to make a new list
    diff /= (nexec);
    return diff.count();
}

void meter(IList<int> *alist, IList<int> *slist, IList<int> *dlist, string csvfile, int *ptr_sizes, int nsizes, int nexec = 10, int ntries = 10)
{
    //YOUR CODE HERE

    cout << "\t\t\t\t\t\t\t\tA part of data sample:" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "index/nsizes:\t" << setw(6) << 'n' << "\t->" << setw(14) << "A_add(0,*)," << setw(14) << "A_add()," << setw(14) << "A_add(k,)," << setw(14) << "A_removeAt(0)," << setw(15) << "A_removeAt(n-1)," << setw(14) << "A_removeAt(k)," << setw(13) << "A_get(0)," << setw(13) << "A_get(n-1)," << setw(13) << "A_get(k)," << '\n';
    cout << setw(14) << "S_add(0,*)," << setw(14) << "S_add()," << setw(14) << "S_add(k,)," << setw(14) << "s_removeAt(0)," << setw(15) << "S_removeAt(n-1)," << setw(14) << "S_removeAt(k)," << setw(13) << "S_get(0)," <<setw(13) << "S_get(n-1)," <<setw(13) <<"S_get(k)," ;
    cout << setw(14) << "D_add(0,*)," << setw(14) << "D_add()," << setw(14) << "D_add(k,)," << setw(14) << "D_removeAt(0)," << setw(15) << "D_removeAt(n-1)," << setw(14) << "D_removeAt(k)," << setw(13) << "D_get(0)," <<setw(13) << "D_get(n-1)," <<setw(13) <<"D_get(k)," << '\n' ;
    std::ofstream myfile;
    myfile.open(csvfile);
    myfile << "A_size,A_addfirst(ms),A_addlast(ms),A_addrandpos(ms),A_removefirst(ms),A_removelast(ms),A_removerandpos(ms),A_getfirst(ms),A_getrandpos(ms),A_getlast(ms),";
    myfile << "S_addfirst(ms),S_addlast(ms),S_addrandpos(ms),S_removefirst(ms),S_removelast(ms),S_removerandpos(ms),S_getfirst(ms),S_getlast(ms),S_getrandpos(ms),";
    myfile << "D_addfirst(ms),D_addlast(ms),D_addrandpos(ms),D_removefirst(ms),D_removelast(ms),D_removerandpos(ms),D_getfirst(ms),D_getlast(ms),D_getrandpos(ms),\n";
    for (int i = 0; i < nsizes; i++)
    {
    string A_af = to_string(addFirst(alist, csvfile, ptr_sizes, i, nexec, ntries));
    string A_al = to_string(addLastPos(alist, csvfile, ptr_sizes, i, nexec, ntries));
    string A_arp = to_string(addRand(alist, csvfile, ptr_sizes, i, nexec, ntries));
    string A_rf = to_string(removeFirstPos(alist, csvfile, ptr_sizes, i, nexec, ntries));
    string A_rl = to_string(removeLastPos(alist, csvfile, ptr_sizes, i, nexec, ntries));
    string A_rrp = to_string(removeRandPos(alist, csvfile, ptr_sizes, i, nexec, ntries));
    string A_gf = to_string(getFirst(alist, csvfile, ptr_sizes, i, nexec, ntries));
    string A_gl = to_string(getLast(alist, csvfile, ptr_sizes, i, nexec, ntries));
    string A_grp = to_string(getRandPos(alist, csvfile, ptr_sizes, i, nexec, ntries));

    string S_af = to_string(addFirst(slist, csvfile, ptr_sizes, i, nexec, ntries));
    string S_al = to_string(addLastPos(slist, csvfile, ptr_sizes, i, nexec, ntries));
    string S_arp = to_string(addRand(slist, csvfile, ptr_sizes, i, nexec, ntries));
    string S_rf = to_string(removeFirstPos(slist, csvfile, ptr_sizes, i, nexec, ntries));
    string S_rl = to_string(removeLastPos(slist, csvfile, ptr_sizes, i, nexec, ntries));
    string S_rrp = to_string(removeRandPos(slist, csvfile, ptr_sizes, i, nexec, ntries));
    string S_gf = to_string(getFirst(slist, csvfile, ptr_sizes, i, nexec, ntries));
    string S_gl = to_string(getLast(slist, csvfile, ptr_sizes, i, nexec, ntries));
    string S_grp = to_string(getRandPos(slist, csvfile, ptr_sizes, i, nexec, ntries));

    string D_af = to_string(addFirst(dlist, csvfile, ptr_sizes, i, nexec, ntries));
    string D_al = to_string(addLastPos(dlist, csvfile, ptr_sizes, i, nexec, ntries));
    string D_arp = to_string(addRand(dlist, csvfile, ptr_sizes, i, nexec, ntries));
    string D_rf = to_string(removeFirstPos(dlist, csvfile, ptr_sizes, i, nexec, ntries));
    string D_rl = to_string(removeLastPos(dlist, csvfile, ptr_sizes, i, nexec, ntries));
    string D_rrp = to_string(removeRandPos(dlist, csvfile, ptr_sizes, i, nexec, ntries));
    string D_gf = to_string(getFirst(dlist, csvfile, ptr_sizes, i, nexec, ntries));
    string D_gl = to_string(getLast(dlist, csvfile, ptr_sizes, i, nexec, ntries));
    string D_grp = to_string(getRandPos(dlist, csvfile, ptr_sizes, i, nexec, ntries));

    if (!(i % 10))
            cout << '[' << setw(2) << i << "/100]:\t" << setw(6) << ptr_sizes[i] << "\t->";
        if (!(i % 10))
        {
            cout << fixed << setw(13) << setprecision(8) << A_af << ',';
            cout << fixed << setw(13) << setprecision(8) << A_al << ',';
            cout << fixed << setw(13) << setprecision(8) << A_arp << ',';
            cout << fixed << setw(13) << setprecision(8) << A_rf << ',';
            cout << fixed << setw(13) << setprecision(8) << A_rl << ',';
            cout << fixed << setw(13) << setprecision(8) << A_rrp << ',';
            cout << fixed << setw(13) << setprecision(8) << A_gf << ',';
            cout << fixed << setw(13) << setprecision(8) << A_gl << ',';
            cout << fixed << setw(13) << setprecision(8) << A_grp << ',';

            cout << fixed << setw(13) << setprecision(8) << S_af << ',';
            cout << fixed << setw(13) << setprecision(8) << S_al << ',';
            cout << fixed << setw(13) << setprecision(8) << S_arp << ',';
            cout << fixed << setw(13) << setprecision(8) << S_rf << ',';
            cout << fixed << setw(13) << setprecision(8) << S_rl << ',';
            cout << fixed << setw(13) << setprecision(8) << S_rrp << ',';
            cout << fixed << setw(13) << setprecision(8) << S_gf << ',';
            cout << fixed << setw(13) << setprecision(8) << S_gl << ',';
            cout << fixed << setw(13) << setprecision(8) << S_grp << ',';

            cout << fixed << setw(13) << setprecision(8) << D_af << ',';
            cout << fixed << setw(13) << setprecision(8) << D_al << ',';
            cout << fixed << setw(13) << setprecision(8) << D_arp << ',';
            cout << fixed << setw(13) << setprecision(8) << D_rf << ',';
            cout << fixed << setw(13) << setprecision(8) << D_rl << ',';
            cout << fixed << setw(13) << setprecision(8) << D_rrp << ',';
            cout << fixed << setw(13) << setprecision(8) << D_gf << ',';
            cout << fixed << setw(13) << setprecision(8) << D_gl << ',';
            cout << fixed << setw(13) << setprecision(8) << D_grp << ',';
            
            cout << endl;
        }
    myfile << to_string(ptr_sizes[i]) << "," << A_af << "," << A_al << "," << A_arp << "," << A_rf << "," << A_rl << "," << A_rrp << "," << A_gf << "," << A_gl << "," << A_grp << ",";
    myfile << S_af << "," << S_al << "," << S_arp << "," << S_rf << "," << S_rl << "," << S_rrp << "," << S_gf << "," << S_gl << "," << S_grp << ",";
    myfile << D_af << "," << D_al << "," << D_arp << "," << D_rf << "," << D_rl << "," << D_rrp << "," << D_gf << "," << D_gl << "," << D_grp << "," << '\n';
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
    XArrayList<int> alist;
    SLinkedList<int> slist;
    DLinkedList<int> dlist;

    nsizes = get_int(argv, argv + argc, "-nsizes", 50);
    nexec = get_int(argv, argv + argc, "-nexec", 20);
    max_length = get_int(argv, argv + argc, "-max_length", 1000);
    ntries = get_int(argv, argv + argc, "-ntries", 10);
    int *ptr_sizes = genIntArray(nsizes, 1, max_length);
    meter(&alist, &slist, &dlist, "allTime.csv", ptr_sizes, nsizes, nexec, ntries);

}