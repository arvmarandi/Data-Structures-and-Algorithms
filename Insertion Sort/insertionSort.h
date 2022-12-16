/**
 * @file insertionSort.h
 * @author Arvand Marandi   
 * @brief Insertion Sort
 * @version 0.1
 * @date 9/22/22
 */

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "sort.h"

class InsertionSort : public Sort{

    public:
        //default constructor of InsertionSort()
        InsertionSort(){
            name = "Insertion Sort";
        }

        void doSort(std::vector<int> &vec) {
            int i, key, j; 
            //the for loop creates a subarray and with each pass of the for loop, the subarray increases by size 1, until the subarray is as large as the size of the original array. Disclaimer, this for loop doesn't actually create a subarray, but it's conceptually the same thing. 
            for (i = 1; i < vec.size(); i++)
            { 
                key = vec[i]; 
                j = i - 1; 
                //the while loop parses through the subarray and performs the sort
                while (j >= 0 && vec[j] > key)
                { 
                    vec[j + 1] = vec[j]; 
                    j = j - 1; 
                } 
                vec[j + 1] = key; 
            } 
            

        }

};

#endif