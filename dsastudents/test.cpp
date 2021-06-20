#include <iostream>
#include "list/SLinkedList.h"
#include "list/DLinkedList.h"
using namespace std;

int main()
{
    {
        //Test add();
        DLinkedList<int> list;
        cout << "list trống: " << list.toString() << endl;
        list.add(1);
        cout << "list sau khi add: " << list.toString() << endl;
        list.add(2);
        cout << "list sau khi add: " << list.toString() << endl;
        list.add(-2);
        cout << "list sau khi add: " << list.toString() << endl;
    } 
    /*{
        //test add(index, value)
        SLinkedList<int> list;
        try
        {
            cout << "list trống: " << list.toString() << endl;
            list.add(0, 1);
            cout << "list sau khi add vô index 0: " << list.toString() << endl;
            for (int i = 2; i < 10; i++)
                list.add(0, i);
            cout << "list sau khi add vô index 0: " << list.toString() << endl;
            list.add(list.size(), -2);
            cout << "list sau khi add vô cuối chuỗi: " << list.toString() << endl;
            list.add(3, 10);
            cout << "list sau khi add vô index 3: " << list.toString() << endl;
            //list.add(-2,-3);
            //cout << "list sau khi add vô index < 0: " << list.toString() << endl;
            list.add(list.size() + 1, -3);
            cout << "list sau khi add vô index > size(): " << list.toString() << endl;
        }
        catch (std::out_of_range)
        {
            cout << "wrong" << endl;
        }
    }*/

    {
        //test get
        // DLinkedList<int> list;
        // cout << "list trống: " << list.toString() << endl;
        // list.add(0, 1);
        // cout << "list sau khi add vô index 0: " << list.toString() << endl;
        // for (int i = 2; i < 10; i++)
        //     list.add(0, i);
        // cout << "list sau khi add vô index 0: " << list.toString() << endl;
        // list.add(list.size(), -2);
        // cout << "list sau khi add vô cuối chuỗi: " << list.toString() << endl;
        // list.add(3, 10);
        // cout << "list sau khi add vô index 3: " << list.toString() << endl;
        // /////////////////////////////////////////////////////////////////////////
        // try
        // {
        // cout << "get() index 0: " << list.get(0) << endl;
        // cout << "get() index cuối: " << list.get(list.size()-1) << endl;
        // cout << "get() index giữa bất kỳ, index 5: "  << list.get(5) << endl;
        // ////////////////////////////////////////////////////////////////////////
        // list.clear();
        // cout << "list trống: " << list.toString() << endl;
        // cout << "Size cuả list: " << list.size() << endl;
        // list.get(1);
        // }
        // catch(std::out_of_range)
        // {
        //     cout << "get() wrong" << endl;
        // }
    }

    {
        // SLinkedList<int> list;
        // cout << "list trống: " << list.toString() << endl;
        // list.add(0, 1);
        // cout << "list sau khi add vô index 0: " << list.toString() << endl;
        // for (int i = 2; i < 10; i++)
        //     list.add(0, i);
        // cout << "list sau khi add vô index 0: " << list.toString() << endl;
        // list.add(list.size(), -2);
        // cout << "list sau khi add vô cuối chuỗi: " << list.toString() << endl;
        // list.add(3, 10);
        // cout << "list sau khi add vô index 3: " << list.toString() << endl;

        // try
        // {
        //     cout << "Size cuả list: " << list.size() << endl;
        //     cout << "indexOf() value 0: " << list.indexOf(0) << endl;
        //     cout << "indexOf() value size()-1 : " << list.indexOf(list.size()-1) << endl;
        //     cout << "indexOf() value 5: "  << list.indexOf(5) << endl;
        //     list.clear();
        //     cout << "list trống: " << list.toString() << endl;
        //     cout << "Size cuả list: " << list.size() << endl;
        //     cout << "indexOf() value 5: "  << list.indexOf(5) << endl;
        // }

        // catch(std::out_of_range)
        // {
        //     std::cerr << "wrong"  << '\n';
        // }
    }
    {
        // try{
        // SLinkedList<int> list;
        // cout << "list trống: " << list.toString() << endl;
        // list.add(0, 1);
        // cout << "list sau khi add vô index 0: " << list.toString() << endl;
        // for (int i = 2; i < 10; i++)
        //     list.add(0, i);
        // cout << "list sau khi add vô index 0: " << list.toString() << endl;
        // list.add(list.size(), -2);
        // cout << "list sau khi add vô cuối chuỗi: " << list.toString() << endl;
        // list.add(3, 10);
        // cout << "list sau khi add vô index 3: " << list.toString() << endl;
        // //////////////////////////////////////////////////////////////////
        // list.removeAt(0);
        // cout << "list sau khi removeAt(0) " << list.toString() << endl;
        // cout << "Size cuả list: " << list.size() << endl;
        // list.removeAt(list.size()-1);
        // cout << "list sau khi removeAt(list.size()-1) " << list.toString() << endl;
        // list.removeAt(list.size());
        // cout << "list sau khi removeAt(list.size()) " << list.toString() << endl;
        // }
        // catch(std::out_of_range)
        // {
        //     cout << "wrong" << endl;
        // }
    }
    {
        // try
        // {
        //     SLinkedList<int> list;
        //     cout << "list trống: " << list.toString() << endl;
        //     list.add(0, 1);
        //     cout << "list sau khi add vô index 0: " << list.toString() << endl;
        //     for (int i = 2; i < 10; i++)
        //         list.add(0, i);
        //     cout << "list sau khi add vô index 0: " << list.toString() << endl;
        //     list.add(list.size(), -2);
        //     cout << "list sau khi add vô cuối chuỗi: " << list.toString() << endl;
        //     list.add(3, 10);
        //     cout << "list sau khi add vô index 3: " << list.toString() << endl;
        //     ///////////////////////////////////////////////////////////////////
        //     cout << "Size cuả list: " << list.size() << endl;
        //     cout << list.removeItem(10) << endl;
        //     cout << "list sau khi removeItem(10) " << list.toString() << endl;
        //     cout << "Size cuả list: " << list.size() << endl;
        //     cout << list.removeItem(9) << endl;
        //     cout << "list sau khi removeItem(9) " << list.toString() << endl;
        //     cout << "Size cuả list: " << list.size() << endl;
        //     cout << list.removeItem(list.size()-1) << endl;
        //     cout << "list sau khi removeItem(list.size()-1) " << list.toString() << endl;
        //     cout << "Size cuả list: " << list.size() << endl;
        //     cout << list.removeItem(list.size()) << endl;
        //     cout << "list sau khi removeItem(list.size()) " << list.toString() << endl;
        // }
        //     catch(std::out_of_range)
        //     {
        //         cout << "wrong" << endl;
        // }
    }
}