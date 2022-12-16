/**
 * @file main.h
 * @author Arvand Marandi
 * @brief Tests out different sorting algorithms and prints out the run time for each sorting agorithm.
 * @version 0.1
 * @date 2022-09-12
 */

#ifndef MAIN_H
#define MAIN_H

#include<iostream>
#include "sort.h"
#include "insertionSort.h"

using namespace std;

void printVector(vector<int> &vec);
void fillVectorRandom(vector<int> &vec, int count);
void fillVectorAsc(vector<int> &vec, int count);
void fillVectorDsc(vector<int> &vec, int count);
void testSort(Sort* sort, vector<int> &vec, string initialCondition, int size, int iterationCount);

#endif