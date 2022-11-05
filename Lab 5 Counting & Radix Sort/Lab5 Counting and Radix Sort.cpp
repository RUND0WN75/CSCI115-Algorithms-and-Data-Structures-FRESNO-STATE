// Lab5 Counting and Radix Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;

void print(vector<int> arr) {
    for (int x = 0; x < arr.size(); x+= 100) cout << arr.at(x) << " ";
}

//Counting sort
void countingsort(vector<int> input) {
    vector<int> output(input.size(),0);

    //Obtaining max element in vector
    int max = input.at(0);
    for (int m = 0; m < input.size(); m++) {
        if (max < input[m]) max = input[m];
    }

    vector<int> aux(max + 1,0);
    //Loop through input array and store count of each element in the auxiliary array such that the element is the index of the auxiliary array and value is the count of that element
    int val;
    for (int i = 0; i < input.size(); i++) {
        val = input[i];
        aux[val]++;
    }

    //Loop through auxiliary array and cumulatively add values of the array
    for (int j = 1; j <= max; j++) aux[j] += aux[j-1];
    
    for (int i = input.size() - 1; i >= 0; i--) {
        //output.at(aux.at(input.at(i)));
        output[--aux[input[i]]] = input[i];
    }

    //Ensuring the output array is the same size as the input array
    for (int j = 0; j < input.size(); j++) input[j] = output[j];

    print(input);
    cout << endl;
}

//Radix sort
void radixsort(vector<int> input) {
    //Obtaining max element in input array
    int max = input.at(0);
    for (int m = 0; m < input.size(); m++) {
        if (max < input.at(m)) max = input.at(m);
    }

    //Get # of digits of max element
    int d = int(log10(max) + 1);

    for (int i = 0; i < d; i++) {
        vector<int> aux(10, 0); //Auxiliary array w/ elements set to 0
        
        //Loop through input array and store count of each element in the auxiliary array such that the element is the index of the auxiliary array and value is the count of that element
        int val;
        for (int l = 0; l < input.size(); l++) {
            val = (input.at(l)/(int)(pow(10,i))) % 10;
            aux.at(val)++;
        }

        //Loop through auxiliary array and cumulatively add values of the array
        for (int j = 1; j <= aux.size()-1; j++) aux[j] += aux[j - 1];

        //Ensuring the output array is the same size as the input array
        vector<int> output(input.size(), 0);

        //Looping from the end of input array
        //Getting value at that position of input array
        //Use value as index to the auxiliary array, get value at that position of the auxiliary array
        //Decrement by one
        int x = 0;
        for (int k = input.size() - 1; k >= 0; k--) {
            x = (input.at(k) / (int)(pow(10, i))) % 10;
            aux.at(x) -= 1;
            output.at(aux.at(x)) = input.at(k);
        }
        for (int n = 0; n < input.size(); n++) input[n] = output[n];
    }

    print(input);
    cout << endl;
}

int main() {
    vector<int> arr{1,4,8,3,34,21,56,0,243,124};
    cout << "Array after counting sort: ";
    for (int i = 0; i < 40000; i++) arr.push_back(rand() % 438);
    cout << endl;
    
    //Recording execution times for sorting algorithms
    clock_t time = clock();
    countingsort(arr);
    time = clock() - time;
    cout << "Time complexity for counting sort: ";
    cout << (float)time / CLOCKS_PER_SEC << endl;
    
    cout << endl;
    
    cout << "Array after radix sort: \n";
    time = clock();
    radixsort(arr);
    time = clock() - time;
    cout << "Time complexity for radix sort: ";
    cout << (float)time / CLOCKS_PER_SEC << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu