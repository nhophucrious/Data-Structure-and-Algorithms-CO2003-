/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SLinkedList.h
 * Author: LTSACH
 *
 * Created on 19 August 2020, 16:56
 */

#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

#include "list/IList.h"

#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;

template <class T>
class SLinkedList;

template <class T>
class SLinkedList : public IList<T>
{
public:
    class Iterator; //forward declaration
    class Node;     //forward declaration

protected:
    Node *head; //this node does not contain user's data
    Node *tail; //this node does not contain user's data
    int count;  //keep number of items stored in the list
    bool (*itemEqual)(T &lhs, T &rhs);
    void (*deleteUserData)(SLinkedList<T> *);

public:
    SLinkedList(
        void (*deleteUserData)(SLinkedList<T> *) = 0,
        bool (*itemEqual)(T &, T &) = 0);
    SLinkedList(const SLinkedList<T> &list); // copy constructor
    SLinkedList<T> &operator=(const SLinkedList<T> &list);
    ~SLinkedList();

    //Inherit from IList: BEGIN
    void add(T e);
    void add(int index, T e);
    T removeAt(int index);
    bool removeItem(T item, void (*removeItemData)(T) = 0);
    bool empty();
    int size();
    void clear();
    T &get(int index);
    int indexOf(T item);
    bool contains(T item);
    string toString(string (*item2str)(T &) = 0);
    //Inherit from IList: BEGIN

    void println(string (*item2str)(T &) = 0)
    {
        cout << toString(item2str) << endl;
    }
    void setDeleteUserDataPtr(void (*deleteUserData)(SLinkedList<T> *) = 0)
    {
        this->deleteUserData = deleteUserData;
    }

    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }

    static void free(SLinkedList<T> *list)
    {
        typename SLinkedList<T>::Iterator it = list->begin();
        while (it != list->end())
        {
            delete *it;
            it++;
        }
    }

protected:
    static bool equals(T &lhs, T &rhs, bool (*itemEqual)(T &, T &))
    {
        if (itemEqual == 0)
            return lhs == rhs;
        else
            return itemEqual(lhs, rhs);
    }

    void copyFrom(const SLinkedList<T> &list);
    void removeInternalData();

    //////////////////////////////////////////////////////////////////////
    ////////////////////////  INNER CLASSES DEFNITION ////////////////////
    //////////////////////////////////////////////////////////////////////
public:
    class Node
    {
    public:
        T data;
        Node *next;

    public:
        Node(Node *next = 0)
        {
            this->next = next;
        }
        Node(T data, Node *next = 0)
        {
            this->data = data;
            this->next = next;
        }
    };

    //////////////////////////////////////////////////////////////////////
    //Iterator
    class Iterator
    {
    private:
        SLinkedList<T> *pList;
        Node *pNode;

    public:
        Iterator(SLinkedList<T> *pList = 0, bool begin = true)
        {
            if (begin)
            {
                if (pList != 0)
                    this->pNode = pList->head->next;
                else
                    pNode = 0;
            }
            else
            {
                if (pList != 0)
                    this->pNode = pList->tail;
                else
                    pNode = 0;
            }
            this->pList = pList;
        }

        Iterator &operator=(const Iterator &iterator)
        {
            this->pNode = iterator.pNode;
            this->pList = iterator.pList;
            return *this;
        }
        /*
         * remove: slow, O(n), why?
         * while-loop can have n iterations
         * => Use DLinkedList when need a linked-list
         */
        void remove(void (*removeItemData)(T) = 0)
        {
            Node *pCur = this->pList->head->next;
            Node *pPrev = this->pList->head;
            bool found = false;
            while (pCur != this->pList->tail)
            {
                found = SLinkedList<T>::equals(pNode->data, pCur->data, pList->itemEqual);
                if (found)
                {
                    //detach
                    pPrev->next = pCur->next;
                    if (pList->tail->next == pCur)
                        pList->tail->next = pPrev; //update tail if needed
                    pList->count -= 1;             //dec count in list
                    pCur->next = 0;

                    //remove users data + node :
                    if (removeItemData != 0)
                        removeItemData(pCur->data);
                    delete pCur;

                    //prepare for next iteration, usually: it++

                    this->pNode = pPrev;
                    return;
                }

                //go next:
                pCur = pCur->next;
                pPrev = pPrev->next;
            } //while
        }

        T &operator*()
        {
            return pNode->data;
        }
        bool operator!=(const Iterator &iterator)
        {
            return pNode != iterator.pNode;
        }
        // Prefix ++ overload
        Iterator &operator++()
        {
            pNode = pNode->next;
            return *this;
        }
        // Postfix ++ overload
        Iterator operator++(int)
        {
            Iterator iterator = *this;
            ++*this;
            return iterator;
        }
    };
};

//////////////////////////////////////////////////////////////////////
////////////////////////     METHOD DEFNITION      ///////////////////
//////////////////////////////////////////////////////////////////////

template <class T>
SLinkedList<T>::SLinkedList(
    void (*deleteUserData)(SLinkedList<T> *),
    bool (*itemEqual)(T &, T &))
{
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->next = head;
    count = 0;
    this->itemEqual = itemEqual;
    this->deleteUserData = deleteUserData;
}

template <class T>
void SLinkedList<T>::copyFrom(const SLinkedList<T> &list)
{
    //Initialize this list to the empty condition
    this->count = 0;
    this->head->next = this->tail;
    this->tail->next = this->head;

    //Copy pointers from "list"
    this->deleteUserData = list.deleteUserData;
    this->itemEqual = list.itemEqual;

    //Copy data from "list"
    Node *ptr = list.head->next;
    while (ptr != list.tail)
    {
        this->add(ptr->data);
        ptr = ptr->next;
    }
}

template <class T>
void SLinkedList<T>::removeInternalData()
{
    //Remove user's data of this list
    if (deleteUserData != 0)
        deleteUserData(this);

    //Remove this list's data (i.e. Node)
    if ((head != 0) & (tail != 0))
    {
        Node *ptr = head->next;
        while (ptr != tail)
        {
            Node *next = ptr->next;
            delete ptr;
            ptr = next;
        }
    }
}

template <class T>
SLinkedList<T>::SLinkedList(const SLinkedList<T> &list)
{
    //Initialize to the empty condition
    //YOUR CODE HERE:  create two dummy nodes: head and tail
    head = tail = new Node();
    copyFrom(list);
}

template <class T>
SLinkedList<T> &SLinkedList<T>::operator=(const SLinkedList<T> &list)
{
    removeInternalData();
    copyFrom(list);

    return *this;
}

template <class T>
SLinkedList<T>::~SLinkedList()
{
    removeInternalData();
    //YOUR CODE HERE: delete dummy nodes
    if (head != NULL)
        delete head;
    if (tail != NULL)
        delete tail;
    count = 0;
}

template <class T>
void SLinkedList<T>::add(T e)
{
    Node *newNode = new Node(e, tail);
    //YOUR CODE HERE:
    if (head->next == tail) // there is nothing in list (just HEAD and TAIL)
    {
        head->next = newNode; // Head will link to the new Node
        //newNode->next = tail; //Making connection between tail and newNode
        tail->next = newNode;
    }
    else
    {
        Node *oldTail = tail->next;
        oldTail->next = newNode;
        tail->next = newNode;
    }
    // Increase the size
    count += 1;
}
template <class T>
void SLinkedList<T>::add(int index, T e)
{
    if ((index < 0) || (index > count))
        throw std::out_of_range("The index is out of range!");
    //index in [0, count]
    //YOUR CODE HERE
    //////////////////////////////////////////////////////////
    if (empty() == true)
    {
        Node *newNode = new Node(e, tail); // append the node or insert when there is no node in the list
        head->next = newNode;              // Head will link to the new Node
        tail->next = newNode;
        count++;
    }
    else if (index == 0)
    {
        if (head->next == tail) // if there is no node in the list
        {
            Node *newNode = new Node(e, tail); // Make a New Node which NEXT pointer points to TAIL
            head->next = newNode;              // Head will point to newNode
            tail->next = newNode;              //tail will point to newNode
        }
        else
        {
            Node *newNode = new Node(e, head->next); // Make a NEW NODE which NEXT pointer point to first internal node
            head->next = newNode;                    // HEAD will point to New Node
        }
        count++; //Increase the size
    }
    else
    {
        Node *newNode = new Node(e, NULL);
        Node *ptr = head->next;             // get the first internal Node
        for (int i = 0; i < index - 1; i++) // loop to the index position
        {
            ptr = ptr->next;
        }
        if (ptr->next == tail) // if the last node of internal node
        {
            ptr->next = newNode;  // the last node points to new node
            newNode->next = tail; // newNode points to tail
            tail->next = newNode; //tail point to newNpde;
        }
        else // add in middle of list
        {
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
        //Increase the size
        count++;
    }
    //////////////////////////////////////////////////////////
    //Change tail->next if needed
    //if(index == count)
    //tail->next = newNode;
}
template <class T>
T SLinkedList<T>::removeAt(int index)
{
    if ((index < 0) || (index > count - 1))
        throw std::out_of_range("The index is out of range!");
    T answer;
    //YOUR CODE HERE
    if (index == 0)
    {
        Node *temp = head->next; //check the first internal node
        answer = temp->data;     // return value
        head->next = temp->next; // Move HEAD to the 2nd internal node
        delete temp;
    }
    else if (index == count - 1)
    {
        // get the first internal node
        Node *ptr = head->next;
        Node *newLastNode = head->next;

        while (ptr->next != tail) // if not the last internal node;
            ptr = ptr->next;      //move to next node
        Node *temp = ptr;         //store the last internal node as temp pointer
        answer = temp->data;      //get the return value

        while (newLastNode->next != ptr) //get the NEW last internal Node
        {
            newLastNode = newLastNode->next;
        }
        newLastNode->next = tail; //set the connection between NEW LAST INTERNAL NODE and TAIL
        tail->next = newLastNode;

        //Delete the last internal node
        delete temp;
    }
    else
    {
        Node *prev = head->next;            // get the first internal node
        Node *curr = prev->next;            //get the second internal node
        for (int i = 0; i < index - 1; i++) // loop until the current node is the node that we need to del
        {
            prev = prev->next;
            curr = curr->next;
        }
        prev->next = curr->next; // make connection between PREV with NEXT node of current
        if (curr->next == tail)  // if CURR is the last internal node;
            tail->next = prev;   // make connection between tail and NEW LAST NODE
        answer = curr->data;     // get return value;
        delete curr;             //delete the CURR
    }
    count--; // Decrease the size;
    return answer;
}

template <class T>
bool SLinkedList<T>::removeItem(T item, void (*removeItemData)(T))
{
    bool found = false;
    Node *Current = head->next;
    Node *Previous = head;
    while (Current != tail)
    {
        found = SLinkedList<T>::equals(Current->data, item, this->itemEqual);
        if (found == true)
        {
            Previous->next = Current->next;
            if (Previous->next == tail)
                tail->next = Previous;
            Current->next = NULL;
            if (removeItemData)
                removeItemData(Current->data);
            delete Current;
            count--;
            return true;
        }
        Current = Current->next;
        Previous = Previous->next;
    }
    return false;
}

template <class T>
bool SLinkedList<T>::empty()
{
    //YOUR CODE HERE
    return count < 1;
}

template <class T>
int SLinkedList<T>::size()
{
    //YOUR CODE HERE
    return count;
}

template <class T>
void SLinkedList<T>::clear()
{
    removeInternalData();
    //YOUR CODE HERE
    //Reset head and tail as initial
    head->next = tail;
    tail->next = head;
    count = 0;
}

template <class T>
T &SLinkedList<T>::get(int index)
{
    if ((index < 0) || (index > count - 1))
        throw std::out_of_range("The index is out of range!");
    if (index == 0)
    {
        return head->next->data;
    }
    else if (index == count - 1)
    {
        return tail->next->data;
    }
    else
    {
        Node *ptr = head;
        for (int i = -1; i < index; i++)
        {
            ptr = ptr->next;
        }
        return (ptr->data);
    }
    Node *ptr = head;
    for (int i = -1; i < index; i++)
    {
        ptr = ptr->next;
    }
    return (ptr->data);
}

template <class T>
int SLinkedList<T>::indexOf(T item)
{
    //YOUR CODE HERE
    if (empty() == true)
        return -1;
    int index = 0;
    Node *temp = head->next;
    while (temp != tail)
    {
        if (equals(temp->data, item, this->itemEqual) == true)
            return index;
        index++;
        temp = temp->next;
    }
    return -1;
}

template <class T>
bool SLinkedList<T>::contains(T item)
{
    if (empty() == true)
        return false;

    Node *temp = head->next;
    while (temp != tail)
    {
        if (equals((temp->data), item, this->itemEqual))
            return true;
        temp = temp->next;
    }
    return false;
}

template <class T>
string SLinkedList<T>::toString(string (*item2str)(T&) ){
    if(this->count <= 0) return "[]";
    
    stringstream itemos;
    Node* ptr = head->next;
    while(ptr != tail){
        if(item2str != 0) itemos << item2str(ptr->data) << ", ";
        else itemos << ptr->data << ", ";

        ptr = ptr->next;
    }
    //remove the last ", "
    string itemstr = itemos.str();
    itemstr = itemstr.substr(0, itemstr.rfind(','));
    return "[" + itemstr + "]";
}

#endif /* SLINKEDLIST_H */
