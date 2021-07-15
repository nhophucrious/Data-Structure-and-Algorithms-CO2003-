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

template <class T>
class StraightSelectionSort : public ISort<T>
{
public:
    void sort(T array[], int size, int (*comparator)(T &, T &))
    {
        //YOUR CODE HERE
        int walker;
        int current = 0;
        int smallest;
        while (current < size - 1)
        {
            smallest = current;
            walker = current + 1;
            while (walker < size)
            {
                if (comparator(array[walker], array[smallest]) < 0)
                {
                    smallest = walker;
                }
                walker = walker + 1;
            }
            if (smallest != current)
            {
                T temp = array[current];
                array[current] = array[smallest];
                array[smallest] = temp;
            }
            current = current + 1;
        }
    }
};

#endif 