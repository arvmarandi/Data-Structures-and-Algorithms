/**
 * @file sort.h
 * @author Arvand Marandi
 * @brief Getters and Setters for Sort
 * @version 0.1
 * @date 9/22/22
 */

#ifndef SORT_H
#define SORT_H

#include<vector>
#include<string>
#include <iostream>
#include <assert.h>
using namespace std;

class Sort{

    public:
        std::string name;
        double sortTime;
        clock_t time_begin;
        clock_t time_end;

        /**
         *  Converts the results of a sorting algorithm's run to a string
         */
        std::string toString() {
            std::string str = "Sort type: " + name;
            return str;
        }

        // General API for getters and setters
        std::string getName() {
            return name; 
        }

        double getSortTime() {
            return sortTime; 
        }

        void checkSorted(std::vector<int> &vec){
            if(vec.size() > 1){
                for(int i = 1; i < vec.size(); i++){
                    assert (vec.at(i - 1) <= vec.at(i));
                }
            }
        }

        void sortVector(std::vector<int> & vec){

            sortTime = 0.0;
            time_begin = clock();

            doSort(vec);

            time_end = clock();
            sortTime = (time_end - time_begin) / (double)CLOCKS_PER_SEC;
     
        }

        // doSort should be implemented by each sorting class implementations
        virtual void doSort(std::vector<int> & vec) = 0;

};

#endif