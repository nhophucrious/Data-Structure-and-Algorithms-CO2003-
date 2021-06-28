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

template<class T>
class DLinkedListSE: public DLinkedList<T>{
public:
    
    DLinkedListSE(
            void (*removeData)(DLinkedList<T>*)=0, 
            bool (*itemEQ)(T&, T&)=0 ) : 
            DLinkedList<T>(removeData, itemEQ){
        
    };
    void sort(int (*comparator)(T&,T&)=0){
        //YOUR CODE HERE
    };
    
protected:
    static int compare(T& lhs, T& rhs, int (*comparator)(T&,T&)=0){
        if(comparator != 0) return comparator(lhs, rhs);
        else{
            if(lhs < rhs) return -1;
            else if(lhs > rhs) return +1;
            else return 0;
        }
    }
    void mergeSort(typename DLinkedList<T>::Node*& head, int (*comparator)(T&,T&)=0){
        //YOUR CODE HERE
        if ((head != 0) && (head->next != 0))
        {
            typename SLinkedList<T>::Node *second;
            devide(head, second);
            mergeSort(head, comparator);
            mergeSort(second, comparator);
            merge(head, second, comparator);
        }
    };
    void devide(typename DLinkedList<T>::Node*& first, typename DLinkedList<T>::Node*& second){
        //YOUR CODE HERE
        typename SLinkedList<T>::Node *slow, *fast;
        if (head == NULL && head->next == NULL)
        {
            first = NULL;
            second = head;
        }
        else
        {
            slow = head;
            fast = head->next;
            while(fast!=NULL)
            {
                fast = fast->next;
                if(fast!=NULL)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
        }
        first = head;
        second = slow->next;
        second->prev = NULL;
        slow->next = NULL;
    }
    void merge(typename DLinkedList<T>::Node*& first, typename DLinkedList<T>::Node*& second, int (*comparator)(T&,T&)=0){
        //YOUR CODE HERE
        if(comparator(first->data,second->data) == 1)
        {
            first->next = merge(first->next,second);
        }
        else
        {
            second->next = merge(first, second->data);
        }
    }
};

#endif /* DLINKEDLISTSE_H */

