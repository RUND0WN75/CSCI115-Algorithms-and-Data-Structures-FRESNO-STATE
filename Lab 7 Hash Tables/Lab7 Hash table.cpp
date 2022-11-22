// Lab7 Hash table.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <array>
#include <iomanip> //for setprecision(2)
#define SIZE 4001
using namespace std;

struct keyVal {
    string key;
    int count; //# of times an element gets inserted into the table
};

class HashTable {
    private:
        keyVal *arr; //Store words into hash table array
        int val; //To be used in arr_size
        int cost[SIZE] = {0}; //# of probes it takes to insert
        int probe = 0;
        int wordCount = 0;
        int updates[SIZE] = {0}; //# of accesses to an element
        int uniqueElements = 0;
    public:
        HashTable() {
            arr = new keyVal[SIZE];
            for (int i = 0; i < SIZE; i++) arr[i] = {"",-1};
        }
        int hashValue(string input);
        void update(string key);
        int arr_size(string* arr);
        void print();
};

//Printing out the number of unique words in the input file
void HashTable::print() {
    for (int i = 1; i < uniqueElements; i++) {
        cout << "Number of unique words: ";
        cout << this->uniqueElements << endl;
        cout << "Number of probes: ";
        cout << this->cost[uniqueElements - 1] << endl;
        cout << "cost[i]/updates[i] ratio: " << setprecision(2) << float(this->cost[i] / this->updates[i]) << fixed << endl;
        cout << endl;
    }
}

//Take a string as argument, calculate hash value and return it
int HashTable::hashValue(string input) {
    //Obtaining sum of ASCII value
    int hashSum = 0;
    for (int i = 0; i < input.size(); i++) hashSum += 100*sin((int)(input.at(i))); //Get ASCII value

    //Getting hash value
    return abs(hashSum % SIZE);
}

//
void HashTable::update(string key) {
    wordCount++;
    int n = hashValue(key); //Getting the index for the key

    while (arr[n].key != key and arr[n].key != "") {
        n++;
        probe++;
        if (n >= SIZE) n = 0;
    }

    //Update
    if (arr[n].key == key) arr[n].count++;
    else {
        //Insert
        uniqueElements++; //Count # of unique elements
        keyVal kV = { key, 1 };
        arr[n] = kV;
        updates[uniqueElements] = updates[uniqueElements - 1];
    }

    updates[uniqueElements]++;

    //Update the current amount of probes so far for the given list size
    cost[uniqueElements] = probe;
}

int main() {
    ifstream file;
    string line;
    HashTable ht;

    file.open("RomeoAndJuliet.txt"); //Read in romeo and juliet text file
    if (file.is_open()) {
        cout << "File successfully opened\n";
        while (file >> line) ht.update(line); //Inserting into hash table
        ht.print();
        file.close();
    }
    else cout << "Can't open file\n";

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu