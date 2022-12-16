/**
 * @file bubbleSort.h
 * @author Arvand Marandi   
 * @brief Bubble Sort
 * @version 0.1
 * @date 9/22/22
 */

#include "sort.h"


class BubbleSort : public Sort{

    public:
        //default constructor for BubbleSort()
        BubbleSort(){
            name = "Bubble Sort";
        }

        // doSort contains the basic sort function of Bubble Sort, excluding the swap of numbers, which is included in the doSwap function
        void doSort(vector<int> &vec) {
            int i, j;
            for (i = 0; i < vec.size() - 1; i++)
                for (j = 0; j < vec.size() - i - 1; j++)
                    if (vec.at(j) > vec.at(j + 1))
                        doSwap(vec.at(j), vec.at(j + 1));
        }

        //performs a swap if the number at index j is greater than the index j+1
        void doSwap(int &a, int &b){
            int temp;
            temp = a;
            a = b;
            b = temp;
        }

    



};