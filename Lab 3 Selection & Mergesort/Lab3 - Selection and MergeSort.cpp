// Lab3 - Selection and MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <array>
#include <cmath>
#include <chrono>
using namespace std;

//Selection sort function
void selection_sort(int arr[], int size) {
    int min = 0;
    for (int i = 0; i < size - 1; i++) {
        min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) min = j;
        }
        swap(arr[i], arr[min]);
    }
}

//Merge function
void merge(int arr[], int start, int middle, int end) {
    int temp_left = start; //Getting left subarray
    int a = (middle - start) + 1; //Size of left subarray
    int *sub_left = new int[a];
    for (int i = 0; i < a; i++) {
        sub_left[i] = arr[i + start];
    }

    int temp_right = middle + 1; //Getting right subarray
    int b = end - middle; //Size of right subarray
    int* sub_right = new int[b];
    for (int j = 0; j < b; j++) {
        sub_right[j] = arr[j + middle + 1];
    }

    temp_left = 0; temp_right = 0;

    for (int k = start; k <= end; k++) {
        if (temp_left >= a) { //When left subarray is empty
            arr[k] = sub_right[temp_right];
            temp_right++;
        }

        else if (temp_right >= b) { //When right subarray is empty
            arr[k] = sub_left[temp_left];
            temp_left++;
        }
        else if (sub_left[temp_left] <= sub_right[temp_right]) {
            arr[k] = sub_left[temp_left];
            temp_left++;
        }

        else if (sub_right[temp_right] < sub_left[temp_left]) {
            arr[k] = sub_right[temp_right];
            temp_right++;
        }
    }
    delete[] sub_left;
    delete[] sub_right;
}

//Merge sort function
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

//Printing out sorted array
void print(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

//Benchmarking selection and merge sort
void timer(int arr[], int size) {
    cout << "Running time for selection sort: ";
    auto time1 = chrono::high_resolution_clock::now();
    selection_sort(arr, size);
    auto time2 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = time2 - time1;
    cout << duration.count() << endl;

    cout << "Running time for merge sort: ";
    auto time3 = chrono::high_resolution_clock::now();
    selection_sort(arr, size);
    auto time4 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration2 = time4 - time3;
    cout << duration2.count() << endl;
}

//Reverse an array for benchmarking
void rev(int arr[], int a, int b) {
    while (a < b) {
        int x = arr[a];
        arr[a] = arr[b];
        arr[b] = x;
        a++;
        b--;
    }
}

int main() {
    int arr[] = { 22,4,21,7,18,3,25,1,39,20,0,5,100,75 };
    int arr2[] = { 0,1,3,4,5,7,10,25,75,18,41,62,120 }; //Half sorted array
    int size = sizeof(arr) / sizeof(int);

    cout << "Unsorted array: ";
    print(arr,size);
    cout << "Sorted array using selection sort: ";
    selection_sort(arr, size);
    print(arr, size);
    cout << "Sorted array using merge sort:     ";
    merge_sort(arr, 0, size - 1);
    print(arr, size);
    cout << endl;
    timer(arr,size);

    cout << "Running time for half sorted array: ";
    auto time4 = chrono::high_resolution_clock::now();
    rev(arr2, 0, size - 1);
    auto time3 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration2 = time4 - time3;
    cout << abs(duration2.count()) << endl;

    cout << "Running time for reversed list: ";
    auto time1 = chrono::high_resolution_clock::now();
    rev(arr, 0, size - 1);
    auto time2 = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = time2 - time1;
    cout << duration.count() << endl;
    cout << "Reversed array: ";
    print(arr, size);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu