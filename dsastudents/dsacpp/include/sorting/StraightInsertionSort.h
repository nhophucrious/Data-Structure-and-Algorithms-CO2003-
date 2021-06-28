/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StraightInsertionSort.h
 * Author: LTSACH
 *
 * Created on 23 August 2020, 16:24
 */

#ifndef STRAIGHTINSERTIONSORT_H
#define STRAIGHTINSERTIONSORT_H
#include "sorting/ISort.h"

template<class T>
class StraightInsertionSort: public ISort<T>{
public:
    void sort(T array[], int size, int (*comparator)(T&,T&)){
        int i, j;
        T key;
        for (i = 0; i < size;i++)
        {
            key = array[i];
            j = i - 1;
            while(j>=0 && comparator(array[j],key) == 1)
            {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
    }
};

#endif /* STRAIGHTINSERTIONSORT_H */

