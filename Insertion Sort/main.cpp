/*
 * File: main.cpp
 * Author: Arvand Marandi         
 * Date Modified: 9/22/22
 * Description: Tests out different sorting algorithms and prints out the run time for each sorting agorithm.
 */

#include<iostream>
#include<vector>
#include "main.h"

using namespace std;

int main(int argc, char *argv[]){

    int n;

    if(argc == 2){
        n = stoi(argv[1]);
    }else{
        cout << "n size not specified, defaulting to 1000" << endl;
        n = 1000;
    }

    //set the random seed to the current time
    //gives a better chance at generating different numbers each run
    srand(time(0));
    
    //create an initial vector to hold integers
    vector<int> vec; 

    //create a vector of sort pointers
    vector<Sort*> sortVector;

    // insertion sort pointer
    InsertionSort* iSort = new InsertionSort();

    //add insertion sort to vector
    sortVector.push_back(iSort);

    //go through each object in the vector and test each sort
    for(int i = 0; i < sortVector.size(); i++){
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << sortVector.at(i)->toString() << endl;
        testSort(sortVector.at(i), vec, "Ascending", n, 5);
        testSort(sortVector.at(i), vec, "Descending", n, 5);
        testSort(sortVector.at(i), vec, "Random", n, 5);
        cout << "--------------------------------------------------------------------------------" << endl;

    }

    return 0;
}

void testSort(Sort* sort, vector<int> &vec, string initialCondition, int size, int iterationCount){
    
    double averageTime = 0.0;
    string results;

    for(int i = 0; i < iterationCount; i++){

        //fill the vector with data
        if(initialCondition == "Random"){
            fillVectorRandom(vec, size);
        }else if(initialCondition == "Ascending"){
            fillVectorAsc(vec, size);
        }else if(initialCondition == "Descending"){
            fillVectorDsc(vec, size);
        }

        //sort the data
        sort->sortVector(vec);

        //verify data is sorted correctly
        sort->checkSorted(vec);

        //keep track of time
        averageTime += sort->sortTime;

        //clear the vector
        vec.clear();
    }

    //calculate the average time
    averageTime = averageTime / iterationCount;

    //output information to console
    // **NOTE**
    // you can comment my cout lines and create you own, then redirect to a file
    // using the linux command line > for easier logging!
    //
    // keep this original output format for your final submission
    cout << sort->name << ", input data: " << initialCondition;
    cout << ", n=" << size << ", average time: " << averageTime << " secs" << endl;

}

void printVector(vector<int> &vec){
    for(int i = 0; i < vec.size(); i++){
        cout << vec.at(i) << " ";
    }
    cout << endl;
}

void fillVectorRandom(vector<int> &vec, int count){

    int min = 0;
    int max = 1000000000;

    for(int i = 0; i < count; i++){
        vec.push_back(rand() % (max - min) + min);
    }

}

void fillVectorAsc(vector<int> &vec, int count){

    for(int i = 0; i < count; i++){
        vec.push_back(i);
    }


}

void fillVectorDsc(vector<int> &vec, int count){

    for(int i = count; i > 0; i--){
        vec.push_back(i);
    }

}



