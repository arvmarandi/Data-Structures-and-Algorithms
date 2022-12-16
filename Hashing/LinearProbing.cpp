#include "Hash.h"
#include <ctype.h>

class LinearProbing : public Hash{
    public:

        //EVC constructor
        //set the type to "Linear Probing"
        //set the initial table size to be length of the vector passed in
        //set initial load factor to 0.0
        //set item count to 0
        LinearProbing(std::vector<std::string> & vec){
            setType("Linear Probing");
            setTableSize(vec.size());
            setLoadFactor(0.0);
            setItemCount(0);
        }

        //Given a string, calculate the hashkey based on the sum of the chars
        int hashFunction(std::string str){
            int sum = 0;
            int length = str.length();
            for(int i = 0; i < length; i++)
            {
                sum += str[i];
            }
            return (sum%getTableSize());
        }

        //Use linear probing strategy to insert an item into the hashtable
        //If a collision occurs, it should probe until it finds an empty location.
        //  an empty, or free location, is either the empty string "" or an element
        //  marked by lazy deletion.
        //After each insert, check if the table needs to be rehashed. If it does,
        //  perform the rehash
        void insertItem(std::vector<std::string> & vec, std::string str){
            if(vec[hashFunction(str)] == "" || vec[hashFunction(str)] == "DELETED") //check for collisions 
                {
                vec[hashFunction(str)] = str; //insert if there are no collisions
                setLoadFactor(1.0/getTableSize() + getLoadFactor()); //adding 1 to the load factor because we are doing an insertion
                setItemCount(getTableSize() + 1);
                if(checkRehash(vec))
                {
                    rehash(vec);
                }
                }
                else
                {
                int i = 1;
                while(((vec[hashFunction(str)] != "")) || i < getTableSize()) //while there are still collisions and we haven't incremented through the entire vector
                {
                    int temp = (hashFunction(str) + i) % getTableSize();
                    if(vec[temp] == "" || vec[temp] == "DELETED") //if the index is not being taken
                    {
                        vec[temp] = str; //insert the string at the new index
                        setLoadFactor(1.0/getTableSize() + getLoadFactor()); //adding 1 to the load factor because we are doing an insertion
                        setItemCount(getTableSize() + 1);
                        if(checkRehash(vec))
                        {
                            rehash(vec);
                        }
                        
                        break; //stop the loop
                    }
                    i++; //if not, increment by 1
                }
            }
            
        }

        //Perform lazy deletion on the hash table
        //To mark an element as deleted, use the string "DELETED"
        //When removing an item it should also decrease the load factor
        void removeItem(std::vector<std::string> & vec, std::string str){
            int target = hashFunction(str);
            if(vec[target] == str){ //if the target is found at its original key, then lazy delete
                vec[target] = "DELETED";
                setLoadFactor(-1.0/getTableSize() + getLoadFactor()); //removing 1 from the load factor because we are doing an insertion
                setItemCount(getTableSize() - 1);
            }
            else
            {
                int i = 1;
                while(i < getTableSize()) //while we haven't linearly traversed through the entire vector
                {
                    int temp = (hashFunction(str) + i) % getTableSize(); //creating the new key and adding i, which increments by 1 through each loop
                    if(vec[temp] == str) //if we have found the target at the next index, conduct a lazy delete and stop the loop
                    {
                        vec[temp] = "DELETED";
                        setLoadFactor(-1.0/getTableSize() + getLoadFactor()); //removing 1 from the load factor because we are doing an insertion
                        setItemCount(getTableSize() - 1);
                        break;
                    }
                    else if(vec[temp] == "") // if we have found an empty string, stop the loop
                    {
                        break;
                    }
                    else //if we have not found the target and have not stumbled across an empty string, increment i by 1.
                    {
                        i++;
                    }       
                }
            }
        }

        //Search the hashtable for an item
        //Use the hashkey to find the index where the item should belong
        //  and perform linear traversal until you find the item or reach
        //  empty space.
        //Function should return true if the item was found, and false if not found
        bool findItem(std::vector<std::string> & vec, std::string str){
            int target = hashFunction(str);
            bool found = false;
            if(vec[target] == str) //if the target is found at its original key, then return true
                found = true;
            else
            {
                int i = 1;
                while(i < getTableSize()) //while we haven't linearly traversed through the entire vector
                {
                    int temp = (hashFunction(str) + i) % getTableSize(); //creating the new key and adding i, which increments by 1 through each loop
                    if(vec[temp] == str) //if we have found the target at the next index, return true and stop the loop
                    {
                        found = true;
                        break;
                    }
                    else if(vec[temp] == "") // if we have found an empty string, return false and stop the loop
                    {
                        break;
                    }
                    else //if we have not found the target and have not stumbled across an empty string, return false by default and increment i by 1.
                    {
                        i++;
                    }       
                }
            }
            return found;
        }

        //Rehash the hash table
        //double the size of the table to the next largest prime
        //move all the elements over from the old table to the new table
        //update all attributes of the hash table (size, load factor, etc.)
        void rehash(std::vector<std::string> & vec){
                int oldTableSize = getTableSize();
                std::vector<std::string> temp(oldTableSize);
                for(int i = 0; i < oldTableSize; i++) //putting the elements of the old vector into a temporary vector
                {
                    if(vec[i] != "DELETED")
                        temp[i] = vec[i];
                }
                setTableSize(calcNewTableSize(getTableSize())); //calculates the new table size and sets the table size to this new table size.
                setLoadFactor(0.0); //resets the load factor
                vec.clear(); //clears the vector of its old elements
                vec.resize(getTableSize()); //resizes the vector to the new table size
                for(int j = 0; j < oldTableSize; j++) //putting the elements of the old vector into the new, resized vector
                {
                    if(temp[j] != "")
                        insertItem(vec,temp[j]); //insert the item into the vector using linear probing
                }
        }

        //Print the stats of the hash table first, then the contents
        //stats include: table size, load factor, number of collisions, and any others you may think of
        void printTable(std::vector<std::string> &vec){
            std::cout << "Table Size: " << getTableSize() << std::endl;
            std::cout << "Load Factor: " << getLoadFactor() << std::endl;

            for(int i = 0; i < getTableSize(); i++)
            {
                std::cout << "Key: " << i << "| Contents: " << vec[i] << std::endl;
            }
        }

        //checkRehash will return true if the current table needs to be rehash, false if not
        //This function should also print a message indicating a rehash is occuring as well as
        //  the current load factor
        bool checkRehash(std::vector<std::string> & vec){
            bool check = false; //flag variable that returns true if the hash table needs to be rehashed
            if(getLoadFactor() > 0.5) //will only rehash if the load factor is greater than 0.5
            {
                std::cout << "rehash occuring" << std::endl; //lets the console know that a rehash is occuring
                check = true; //marks the flag as true if a rehash is happening
            }
            return check;
        }
        

};