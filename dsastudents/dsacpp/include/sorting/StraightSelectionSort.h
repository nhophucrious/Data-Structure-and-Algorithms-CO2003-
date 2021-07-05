/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StraightSelectionSort.h
 * Author: LTSACH
 *
 * Created on 23 August 2020, 17:10
 */

#ifndef STRAIGHTSELECTIONSORT_H
#define STRAIGHTSELECTIONSORT_H

#include "sorting/ISort.h"


template<class T>
class StraightSelectionSort: public ISort<T>{
public:   
    void sort(T array[], int size, int (*comparator)(T&,T&)){
        //YOUR CODE HERE
        int i, j, min;
        for(i = 0; i < size; i++)
        {
            min = i;
            for (j = i + 1; j < size;j++)
            {
                if((*comparator)(array[j],array[min]) == -1)
                    min = j;
            }
            T temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }
};



#endif /* STRAIGHTSELECTIONSORT_H */

