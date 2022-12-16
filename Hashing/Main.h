#ifndef MAIN_H
#define MAIN_H

#include<vector>
#include<iostream>
#include<assert.h>

//include files
#include "Hash.h"
#include "LinearProbing.cpp"
#include "QuadraticProbing.cpp"

using namespace std;

//function prototypes
void testLinearInsertOneCollision();
void testLinearInsertMultipleCollisionRehash();
void testInsertionOnDeleted();
void testFindWithDeleted();
void testWrapping();
void testQuadraticInsertOneCollision();
void testQuadraticInsertMultipleCollisionRehash();
void testQuadraticInsertionOnDeleted();
void testQuadraticFindWithDeleted();



#endif