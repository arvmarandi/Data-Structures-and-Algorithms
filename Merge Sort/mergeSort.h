/**
 * @file mergeSort.h
 * @author Arvand Marandi
 * @brief Merge sort
 * @version 0.1
 * @date 9/28/22
 */

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "sort.h"

class MergeSort : public Sort{

    public:
        //default constructor for MergeSort()
        MergeSort(){
            name = "Merge Sort"; 
        }

        //the doSort function calls the initial mergeSort function
        void doSort(std::vector<int> &vec){
            mergeSort(vec);
        }

        //this mergeSort function takes in a vector, creates a temporary vector, and then sends in the vector, temporary vector, and the size of the vector into another mergeSort function
        void mergeSort(std::vector<int> & a){

            std::vector<int> tmpArray(a.size());
            mergeSort(a, tmpArray, 0, a.size( ) - 1); 

        }

        //this mergeSort function makes recursive calls and splits up the vectors into halves, and then sends in these halves into the merge function for the merge function to perform the sorts
        void mergeSort(std::vector<int> & a, std::vector<int> & tmpArray, int left, int right){
            
            if( left < right )
            {
                int center = ( left + right ) / 2;
                mergeSort( a, tmpArray, left, center );
                mergeSort( a, tmpArray, center + 1, right );
                merge( a, tmpArray, left, center + 1, right );
            }

        }

        //this function takes in the split up vectors and performs the proper sorts
        void merge(std::vector<int> & a, std::vector<int> & tmpArray, int leftPos, int rightPos, int rightEnd){

            int leftEnd = rightPos - 1;
            int tmpPos = leftPos;
            int numElements = rightEnd - leftPos + 1;
            
            while( leftPos <= leftEnd && rightPos <= rightEnd )
                if( a[ leftPos ] <= a[ rightPos ] )
                    tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );
                else
                    tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );
            
            while( leftPos <= leftEnd ) 
                tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );
            
            while( rightPos <= rightEnd ) 
                tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );
            
           
            for( int i = 0; i < numElements; ++i, --rightEnd )
                a[ rightEnd ] = std::move( tmpArray[ rightEnd ] );

        }

};

 #endif