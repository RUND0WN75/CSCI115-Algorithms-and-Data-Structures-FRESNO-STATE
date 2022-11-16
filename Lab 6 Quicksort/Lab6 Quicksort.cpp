// Lab6 Quicksort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <utility>
#include <chrono>
using namespace std;

//Partition
int partition(int *A, int low, int high) {
    int pivot = A[(low+high)/2];
    int i = low;
    int j = high;
    int size = (int)(sizeof(A) / sizeof(int)); //Getting size of the array
    int index = rand() % size; //Getting a random element
    //swap(A[low], A[index]);
    while (true) {
        while (A[i] < pivot) i++;
        while (A[j] > pivot) j--;
        if (i < j) swap(A[i], A[j]);
        else return j;
    }
    //return j;
}

//Finished quicksort()
void quicksort(int *arr, int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quicksort(arr, p, q);
        quicksort(arr, q + 1, r);
    }
}

void print(int* arr, int size) {
    //Outputting array
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
}

int main() {
    int arr[10] = {};
    //int arr[] = {15,11,115,18,75,22,40};
    int size = (int)(sizeof(arr) / sizeof(int)); //Getting size of the array
    int flag = 0;
    int start = arr[0], end = size - 1, med = (start + end) / 2, x = rand() % size;
    for (int i = 0; i < size; i++) arr[i] = rand() % 100;

    cout << "Initial array: ";
    print(arr, size);

    cout << endl;

    while (true) {
        cout << "Select '0' for pivot 1, '1' for pivot 2, or '2' for pivot 3: ";
        cin >> flag;

        //First element
        if (flag == 0) {
            cout << "Execution time for pivot 1 (first element in the list): ";
            auto time1 = chrono::high_resolution_clock::now();
            quicksort(arr, 0, size - 1);
            auto time2 = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration = time2 - time1;
            cout << duration.count() << endl;
            cout << "Sorted array: ";
            print(arr, size);
            cout << endl;
            cout << endl;
        }

        //Random element
        else if (flag == 1) {
            cout << "Execution time for pivot 2 (random element in the list): ";
            auto time3 = chrono::high_resolution_clock::now();
            quicksort(arr, x, size - 1);
            auto time4 = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration2 = time4 - time3;
            cout << duration2.count() << endl;
            cout << "Sorted array: ";
            print(arr, size);
            cout << endl;
            cout << endl;
        }

        //Median element
        else if (flag == 2) {
            cout << "Execution time for pivot 3 (median element in the list): ";
            auto time5 = chrono::high_resolution_clock::now();
            quicksort(arr, med, size - 1);
            auto time6 = chrono::high_resolution_clock::now();
            chrono::duration<double, milli> duration3 = time6 - time5;
            cout << duration3.count() << endl;
            cout << "Sorted array: ";
            print(arr, size);
            cout << endl;
            cout << endl;
        }

        else cout << "Invalid flag!\n";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu