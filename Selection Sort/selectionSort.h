/**
 * @file selectionsort.h
 * @author Arvand Marandi
 * @brief Seleciton Sort
 * @version 0.1
 * @date 9/22/22
 */

#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "sort.h"


class SelectionSort : public Sort{

    public:
        //default constructor of SelectionSort()
        SelectionSort(){
            name = "Selection Sort";
        }

        //SelectionSort goes through an array, finds the minimum of the array, and then swaps the minimum with the number at the front of the array. It then loops back and repeats the process, ignoring the numbers at the front of the array that have already been sorted.
        void doSort(std::vector<int> &vec) {
        int i, j, min_idx;

        for (i = 0; i < vec.size() - 1; i++)
        {
            min_idx = i;
            for (j = i+1; j < vec.size(); j++)
            if (vec[j] < vec[min_idx])
                min_idx = j;
            if(min_idx!=i)
                std::swap(vec[min_idx], vec[i]);
        }
        

        }
    

};

#endif