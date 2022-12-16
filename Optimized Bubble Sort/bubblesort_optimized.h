/**
 * @file bubblesort_optimized.h
 * @author Arvand Marandi
 * @brief Optimized version of Bubble Sort
 * @version 0.1
 * @date 9/22/22
 */

#include "sort.h"

class BubbleSortOptimized : public Sort{

    public:
        //default constructor of BubbleSortOptimized()
        BubbleSortOptimized(){
            name = "Bubble Sort (Optimized)";
        }

        //the doSort function of the optimized version of Bubble Sort is a do-while loop that will flag the program if the array is already sorted
        void doSort(std::vector<int> &vec)
        {
        bool swap;

        do
        {
            swap = false;
            for (int count = 0; count < (vec.size() - 1); count++)
            {
                if (vec[count] > vec[count + 1])
                {
                    doSwap(vec.at(count), vec.at(count + 1));
                    swap = true;
                }
            }
        } while (swap);
            
        }

        //swaps the numbers in an array
        void doSwap(int &a, int &b){
            int temp;
            temp = a;
            a = b;
            b = temp;

        }


};