/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DLinkedListSE.h
 * Author: LTSACH
 *
 * Created on 31 August 2020, 14:13
 */

#ifndef DLINKEDLISTSE_H
#define DLINKEDLISTSE_H
#include "list/DLinkedList.h"
#include "sorting/ISort.h"

template <class T>
class DLinkedListSE : public DLinkedList<T>
{
public:
    DLinkedListSE(
        void (*removeData)(DLinkedList<T> *) = 0,
        bool (*itemEQ)(T &, T &) = 0) : DLinkedList<T>(removeData, itemEQ){

                                        };
    void sort(int (*comparator)(T &, T &) = 0)
    {
        //YOUR CODE HERE
        if (this->count > 0)
        {
            typename DLinkedList<T>::Node *first = this->head->next; //first user's data
            this->tail->prev->next = NULL;
            this->tail->prev = NULL; //to tail => to 0
            mergeSort(first, comparator);

            //find the last user's data
            typename DLinkedList<T>::Node *last = first;
            while (last->next != 0)
                last = last->next;

            //attach to head&tail of the list
            last->next = this->tail;
            this->tail->prev = last;
            this->head->next = first;
            first->prev = this->head;
        }
    };

protected:
    static int compare(T &lhs, T &rhs, int (*comparator)(T &, T &) = 0)
    {
        if (comparator != 0)
            return comparator(lhs, rhs);
        else
        {
            if (lhs < rhs)
                return -1;
            else if (lhs > rhs)
                return +1;
            else
                return 0;
        }
    }
    void mergeSort(typename DLinkedList<T>::Node *&head, int (*comparator)(T &, T &) = 0)
    {
        //YOUR CODE HERE
        if ((head != 0) && (head->next != 0))
        {
            typename DLinkedList<T>::Node *second;
            devide(head, second);
            mergeSort(head, comparator);
            mergeSort(second, comparator);
            merge(head, second, comparator);
        }
    };
    void devide(typename DLinkedList<T>::Node *&first, typename DLinkedList<T>::Node *&second)
    {
        //YOUR CODE HERE
        typename DLinkedList<T>::Node *slow, *fast;
        if (first == NULL)
        {
            return;
        }
        else
        {
            slow = first;
            fast = slow->next;
            while (fast != NULL)
            {
                fast = fast->next;
                if (fast != NULL)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
        }
        second = slow->next;
        slow->next = NULL;
        second->prev = NULL;
    }
    void merge(typename DLinkedList<T>::Node *&first, typename DLinkedList<T>::Node *&second, int (*comparator)(T &, T &) = 0)
    {
        if (first == NULL || second == NULL)
            return;
        typename DLinkedList<T>::Node *temp = NULL;
        if (compare(first->data, second->data, comparator) == -1)
        {
            temp = first;
            first = first->next;
        }
        else
        {
            temp = second;
            second = second->next;
        }
        typename DLinkedList<T>::Node *ptr = temp;

        while (first != NULL && second != NULL)
        {
            if (compare(first->data,second->data,comparator)==-1)
            {
                ptr->next = first;
                first = first->next;
            }
            else
            {
                ptr->next = second;
                second = second->next;
            }
            ptr = ptr->next;
        }
        if (first == NULL && second != NULL)
        {
            ptr->next = second;
        }
        if (second == NULL && first != NULL)
        {
            ptr->next = first;
        }
        typename DLinkedList<T>::Node *ptr2 = temp;
        while (ptr2->next != NULL)
        {
            ptr2->next->prev = ptr2;
            ptr2 = ptr2->next;
        }
        first = temp;
    }
};

#endif /* DLINKEDLISTSE_H */