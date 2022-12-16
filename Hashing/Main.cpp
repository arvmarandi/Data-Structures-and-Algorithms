#include "Main.h"

//below are the test cases. Uncomment the function calls to activate test case. Currently, it is testing multiple collisions using linear probing.
int main(){

    // testLinearInsertOneCollision();
    testLinearInsertMultipleCollisionRehash();
    // testInsertionOnDeleted();
    // testFindWithDeleted();
    // testWrapping();
    //testQuadraticInsertOneCollision();
    // testQuadraticInsertMultipleCollisionRehash();
    // testQuadraticInsertionOnDeleted();
    // testQuadraticFindWithDeleted();

}

//print out the hash table after each operation
//showing your program can resolve collisions and
//rehash properly.

void testLinearInsertMultipleCollisionRehash(){

    //creates a new vector of size 11
    std::vector<std::string> hashTable(11);

    //create a new linearHash object
    LinearProbing* linearHash = new LinearProbing(hashTable);

    //print the empty hash table
    linearHash->printTable(hashTable);

    //each of these strings hash to be the same
    linearHash->insertItem(hashTable, "abcdefg");
    linearHash->insertItem(hashTable, "bcdefga");
    linearHash->insertItem(hashTable, "cdefgab");
    linearHash->insertItem(hashTable, "defgabc");
    linearHash->insertItem(hashTable, "efgabcd"); 
    linearHash->insertItem(hashTable, "fgabcde");
    linearHash->insertItem(hashTable, "gabcdef");

    //print the new hashTable
    linearHash->printTable(hashTable);

    //prints the load factor
    std::cout << linearHash->getLoadFactor() << std::endl;

    assert(linearHash->getTableSize() == 23);

    delete linearHash;
}

//simple test case to check that a collision is resolved with linear probing
void testLinearInsertOneCollision(){

    //setup the states of the test
    std::vector<std::string>hashTable(11);

    LinearProbing* linearHash = new LinearProbing(hashTable);

    linearHash->printTable(hashTable);

    linearHash->insertItem(hashTable, "abc");
    linearHash->insertItem(hashTable, "bac");
    linearHash->insertItem(hashTable, "cba");

    linearHash->printTable(hashTable);

    //check that "abc" and "bac" were placed in the correct locations
    int index = linearHash->hashFunction("abc");
    assert(hashTable.at(index) == "abc" && hashTable.at(index + 1) == "bac");

    std::cout << "test case passed: linear probing insertion one collison" << std::endl;

    delete linearHash;

}

void testInsertionOnDeleted(){
    //creates a new vector of size 11
    std::vector<std::string> hashTable(11);
    //create a new linearHash object
    LinearProbing* linearHash = new LinearProbing(hashTable);
    //print the empty hash table
    linearHash->printTable(hashTable);
    //inserts an item into the hash table
    linearHash->insertItem(hashTable, "abcdefg");
    //print the hash table with the new insertion
    linearHash->printTable(hashTable);
    //removes that same item
    linearHash->removeItem(hashTable, "abcdefg");
    //prints the new hash table, that has the removed item in it
    linearHash->printTable(hashTable);
    //inserts item at the index of the deleted item
    linearHash->insertItem(hashTable, "bcdefga");
    //print the new hash table
    linearHash->printTable(hashTable);

    delete linearHash;

}

void testFindWithDeleted(){
    //creates a new vector of size 11
    std::vector<std::string> hashTable(11);
    //create a new linearHash object
    LinearProbing* linearHash = new LinearProbing(hashTable);
    //print the empty hash table
    linearHash->printTable(hashTable);
    linearHash->insertItem(hashTable, "abcdefg");
    linearHash->insertItem(hashTable, "bcdefga");
    linearHash->insertItem(hashTable, "cdefgab");
    linearHash->insertItem(hashTable, "defgabc");
    linearHash->insertItem(hashTable, "efgabcd");
    linearHash->insertItem(hashTable, "fgabcde");
    linearHash->insertItem(hashTable, "gabcdef");
    //prints the full hash table
    linearHash->printTable(hashTable);
    //removes an item from the hash table
    linearHash->removeItem(hashTable, "fgabcde");
    //prints the new hash table
    linearHash->printTable(hashTable);
    //finds the item in the table that follows after the removed item, to test if the find item function can find items past removed items
    if((linearHash->findItem(hashTable, "gabcdef") == 1))
        std::cout<< "FOUND ITEM" << std::endl;
    
    delete linearHash;
}

void testWrapping(){
    //creates a new vector of size 11
    std::vector<std::string> hashTable(11);

    //create a new linearHash object
    LinearProbing* linearHash = new LinearProbing(hashTable);

    //print the empty hash table
    linearHash->printTable(hashTable);

    //each of these strings hash to be the same
    linearHash->insertItem(hashTable, "abcdefg");
    linearHash->insertItem(hashTable, "bcdefga");
    linearHash->insertItem(hashTable, "cdefgab");
    linearHash->insertItem(hashTable, "defgabc");
    linearHash->insertItem(hashTable, "efgabcd"); 

    //print the new hashTable
    linearHash->printTable(hashTable);

    //prints the load factor
    std::cout << linearHash->getLoadFactor() << std::endl;

    delete linearHash; 
}

void testQuadraticInsertMultipleCollisionRehash(){

    //creates a new vector of size 11
    std::vector<std::string> hashTable(11);

    //create a new quadraticHash object
    QuadraticProbing* quadraticHash = new QuadraticProbing(hashTable);

    //print the empty hash table
    quadraticHash->printTable(hashTable);

    //each of these strings hash to be the same
    quadraticHash->insertItem(hashTable, "abcdefg");
    quadraticHash->insertItem(hashTable, "bcdefga");
    quadraticHash->insertItem(hashTable, "cdefgab");
    quadraticHash->insertItem(hashTable, "defgabc");
    quadraticHash->insertItem(hashTable, "efgabcd"); 
    quadraticHash->insertItem(hashTable, "fgabcde");
    quadraticHash->insertItem(hashTable, "gabcdef");

    //print the new hashTable
    quadraticHash->printTable(hashTable);

    //prints the load factor
    std::cout << quadraticHash->getLoadFactor() << std::endl;

    assert(quadraticHash->getTableSize() == 23);

    delete quadraticHash;
}

//simple test case to check that a collision is resolved with linear probing
void testQuadraticInsertOneCollision(){

    //setup the states of the test
    std::vector<std::string>hashTable(11);

    QuadraticProbing* quadraticHash = new QuadraticProbing(hashTable);

    quadraticHash->printTable(hashTable);

    quadraticHash->insertItem(hashTable, "abcd");
    quadraticHash->insertItem(hashTable, "bacd");

    quadraticHash->printTable(hashTable);

    //check that "abc" and "bac" were placed in the correct locations
    int index = quadraticHash->hashFunction("ab");
    assert(hashTable.at(index) == "ab" && hashTable.at(index + 1) == "ba");

    std::cout << "test case passed: linear probing insertion one collison" << std::endl;

    delete quadraticHash;

}


void testQuadraticInsertionOnDeleted(){
    //creates a new vector of size 11
    std::vector<std::string> hashTable(11);
    //create a new quadraticHash object
    QuadraticProbing* quadraticHash = new QuadraticProbing(hashTable);
    //print the empty hash table
    quadraticHash->printTable(hashTable);
    //inserts an item into the hash table
    quadraticHash->insertItem(hashTable, "abcdefg");
    //print the hash table with the new insertion
    quadraticHash->printTable(hashTable);
    //removes that same item
    quadraticHash->removeItem(hashTable, "abcdefg");
    //prints the new hash table, that has the removed item in it
    quadraticHash->printTable(hashTable);
    //inserts item at the index of the deleted item
    quadraticHash->insertItem(hashTable, "bcdefga");
    //print the new hash table
    quadraticHash->printTable(hashTable);

    delete quadraticHash;

}

void testQuadraticFindWithDeleted(){
    //creates a new vector of size 11
    std::vector<std::string> hashTable(11);
    //create a new quadraticHash object
    QuadraticProbing* quadraticHash = new QuadraticProbing(hashTable);
    //print the empty hash table
    quadraticHash->printTable(hashTable);
    quadraticHash->insertItem(hashTable, "abcdefg");
    quadraticHash->insertItem(hashTable, "bcdefga");
    quadraticHash->insertItem(hashTable, "cdefgab");
    quadraticHash->insertItem(hashTable, "defgabc");
    quadraticHash->insertItem(hashTable, "efgabcd");
    quadraticHash->insertItem(hashTable, "fgabcde");
    quadraticHash->insertItem(hashTable, "gabcdef");
    //prints the full hash table
    quadraticHash->printTable(hashTable);
    //removes an item from the hash table
    quadraticHash->removeItem(hashTable, "fgabcde");
    //prints the new hash table
    quadraticHash->printTable(hashTable);
    //finds the item in the table that follows after the removed item, to test if the find item function can find items past removed items
    if((quadraticHash->findItem(hashTable, "gabcdef") == 1))
        std::cout<< "FOUND ITEM" << std::endl;
    
    delete quadraticHash;
}