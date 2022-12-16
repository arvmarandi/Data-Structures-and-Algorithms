#ifndef HASH_H
#define HASH_H

#include<string>
#include<vector>
#include<iostream>
#include<cmath>

class Hash{

    public:

        int calcNewTableSize(int prevSize){
            int newSize = prevSize * 2;
            if(isPrime(newSize))
                return newSize;
            else
            {
                while(isPrime(newSize) == false)
                {
                    newSize++;
                }
            }
            return newSize;
        }

        int getTableSize(){
            return tableSize;
        }

        double getLoadFactor(){
            return loadFactor;
        }

        std::string getType(){
            return type;
        }

        void setTableSize(int size){
            this->tableSize = size;
        }

        void setLoadFactor(double loadFactor){
            this->loadFactor = loadFactor;
        }

        void setType(std::string type){
            this->type = type;
        }

        int getItemCount(){
            return this->itemCount;
        }

        void setItemCount(int count){
            this->itemCount = count;
        }

        //helper function that checks if a number is prime
        bool isPrime(int number){
            bool answer = true;
            if(number == 1)
            {
                answer = false; //one is not considered a prime number
            }
            for(int i = 2; i < sqrt(number); i++) 
            {
                if((number % i) == 0)
                {
                    answer = false;
                    break;
                }
            }
            return answer;
        }

        virtual ~Hash(){

        }

        virtual int hashFunction(std::string) = 0;
        virtual void insertItem(std::vector<std::string> & vec, std::string str) = 0;
        virtual void removeItem(std::vector<std::string> & vec, std::string str) = 0;
        virtual bool findItem(std::vector<std::string> & vec, std::string str) = 0;
        virtual void rehash(std::vector<std::string> & vec) = 0;
        virtual void printTable(std::vector<std::string> & vec) = 0;
        virtual bool checkRehash(std::vector<std::string> & vec) = 0;

    private:

        std::string type;
        int tableSize;
        int itemCount;
        double loadFactor;

};

#endif