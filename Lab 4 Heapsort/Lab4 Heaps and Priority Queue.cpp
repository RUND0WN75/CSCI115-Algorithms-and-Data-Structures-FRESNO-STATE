// Lab4 Heaps and Priority Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <array>
using namespace std;

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
}

//-----------Max heap----------
//Maintain max heap property
void maxheapify(int arr[], int i, int size) { //i = index
    int left = 2*i+1;
    int right = 2*i+2;
    int largest_node = i;
    if ((left <= size) && (arr[left] > arr[largest_node])) largest_node = left;
    if ((right <= size) && (arr[right] > arr[largest_node])) largest_node = right;
    if (arr[i] != arr[largest_node]) {
        int temp = arr[i];
        arr[i] = arr[largest_node];
        arr[largest_node] = temp;
        maxheapify(arr, largest_node, size);
    }
}

//Build entire heap list
void buildmaxheap(int arr[],int size) {
    int x = (size / 2)-1;
    for (int i = x; i >= 0; i--) maxheapify(arr, i, size-1);
    print(arr, size);
    cout << endl;
}

//Print array in ascending order
void ascendingHeap(int arr[], int size) { //Ascending heapsort
    buildmaxheap(arr, size);
    int x = size - 1;
    while (x >= 0) {
        //cout << "Swapping " << arr[0] << " and " << arr[x] << endl;
        int temp = arr[x];
        arr[x] = arr[0];
        arr[0] = temp;
        x--;
        maxheapify(arr, 0, x);
    }
    cout << "Ascending heap: ";
    print(arr, size);
}

//Modify value of a node in max heap
void modify_maxheap(int arr[],int a, int new_val) { //new_val = value to be passed in
    arr[a] = new_val; //a = index
    while (a != 0) {
        int root = (a - 1) / 2; //root = parent node
        if (arr[a] > arr[root]) {
            int x = arr[a];
            arr[a] = arr[root];
            arr[root] = x;
            a = root;
        }
        else break;
    }
}

//Insert a node in max heap
void insert_maxheap(int arr[], int size, int a) {
    if (size >= sizeof(arr) / sizeof(int)) {
        int* temp = new int[size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        arr = temp;
    }
    size++;
    int x = size - 1;
    arr[x] = a;
    modify_maxheap(arr, x, a);
    print(arr, size);
}

//Extract max element in max heap
void extract_maxheap(int arr[],int size) {
    int temp = arr[0];
    int x = arr[size - 1];
    arr[0] = x;
    size--;
    maxheapify(arr,0,size);
    cout << temp << endl;
    print(arr,size);
}

//----------Min heap----------
//Maintain min heap property
void minheapify(int arr[], int i, int size) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest_node = i;
    if ((left <= size) && (arr[left] < arr[smallest_node])) smallest_node = left;
    if ((right <= size) && (arr[right] < arr[smallest_node])) smallest_node = right;
    if (arr[i] != arr[smallest_node]) {
        int temp = arr[i];
        arr[i] = arr[smallest_node];
        arr[smallest_node] = temp;
        minheapify(arr, smallest_node, size);
    }
}

void buildminheap(int arr[], int size) {
    int x = (size / 2) - 1;
    for (int i = x; i >= 0; i--) minheapify(arr, i,size - 1);
    print(arr, size);
    cout << endl;
}

void descendingHeap(int arr[], int size) {
    buildminheap(arr, size);
    //print(arr, size);
    cout << endl;
    int x = size - 1;
    while (x >= 0) {
        //cout << "Swapping " << arr[0] << " and " << arr[x] << endl;
        int temp = arr[x];
        arr[x] = arr[0];
        arr[0] = temp;
        x--;
        minheapify(arr, 0, x);
    }
    cout << "Descending heap: ";
    print(arr, size);
}

//Modify value of a node in min heap
void modify_minheap(int arr[], int a, int new_val) {
    arr[a] = new_val; //a = index
    while (a != 0) {
        int root = (a - 1) / 2; //root = parent node
        if (arr[a] < arr[root]) {
            int x = arr[a];
            arr[a] = arr[root];
            arr[root] = x;
            a = root;
        }
        else break;
    }
}

//Insert a node in min heap
void insert_minheap(int arr[], int size, int a) {
    if (size >= sizeof(arr) / sizeof(int)) {
        int* temp = new int[size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        arr = temp;
    }
    size++;
    int x = size - 1;
    arr[x] = a;
    modify_minheap(arr, x, a);
    print(arr, size);
}

//Extract min element in min heap
void extract_minheap(int arr[], int size) {
    int temp = arr[0];
    int x = arr[size - 1];
    arr[0] = x;
    size--;
    minheapify(arr, 0, size);
    cout << temp << endl;
    print(arr, size);
}

int main() {
    cout << "Enter 0 for ascending order or 1 for descending order: ";
    int x = 0, y = 0;
    int arr[] = {4,0,3,2,9,6};
    cin >> x;

    cout << endl;

    //If user inputs 0 for ascending order
    if (x == 0) {
        ascendingHeap(arr, 6);
        cout << endl;
        cout << "Sorted max heap: \n";
        buildmaxheap(arr,6);
        cout << "Extracting max element: ";
        extract_maxheap(arr, 6);
        cout << endl;
        cout << "Input element: ";
        cin >> y;
        insert_maxheap(arr, 5, y);
        cout << endl;
        cout << "Element inserted in the heap: " << y << endl;
    }

    //If user inputs 1 for descending order
    else if (x == 1) {
        descendingHeap(arr, 6);
        cout << endl;
        cout << "Sorted min heap: ";
        buildminheap(arr, 6);
        cout << "Extracting min element: ";
        extract_minheap(arr, 6);
        cout << endl;
        cout << "Input element: ";
        cin >> y;
        insert_minheap(arr, 5, y);
        cout << endl;
        cout << "Element inserted in the heap: " << y << endl;
    }

    //Error checking
    else {
        cout << "Invalid input\n";
        exit(0);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu