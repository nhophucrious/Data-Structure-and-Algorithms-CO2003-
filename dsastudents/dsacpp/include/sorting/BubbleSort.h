/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BubbleSort.h
 * Author: LTSACH
 *
 * Created on 23 August 2020, 17:16
 */

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "sorting/ISort.h"

template <class T>
class BubbleSort : public ISort<T>
{
public:
    void sort(T array[], int size, int (*comparator)(T &, T &))
    {
        //YOUR CODE HERE
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size;j++)
            {
                if (comparator(array[j], array[i]) == -1)
                {
                    T temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }
};

#endif /* BUBBLESORT_H */
