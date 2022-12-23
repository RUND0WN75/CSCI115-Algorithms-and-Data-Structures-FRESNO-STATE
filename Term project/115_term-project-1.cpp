// 115_term-project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <array>
#include <vector>
#include <ctime>   
#include <algorithm>
#include <unordered_map>
using namespace std;

// prints out the vector, was used for debugging purposes.
void print_vec(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }
    cout << endl;
}
//selection sort function (was edited to accomodate vectors.)
void selection_sort(vector<int> arr, int size) {
    int min = 0;
    for (int i = 0; i < size - 1; i++) {
        min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) min = j;
        }
        swap(arr[i], arr[min]);
    }

}
// merge portion of merge sort 
void merge(vector<int> &arr, int start, int middle, int end) {
    int temp_left = start; //Getting left subarray
    int a = (middle - start) + 1; //Size of left subarray
    int* sub_left = new int[a];
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
    //print_vec(arr);
    delete[] sub_left;
    delete[] sub_right;
    

}

//Merge sort function (was edited to accomadate vectors.)
void merge_sort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);
        merge(arr, left, middle, right);
        //print_vec(arr);

    }

}
// funstion to call merge sort w/o changing the given array to keep thing fair.
void call_merge_sort(vector<int> arr, int left, int right) {
    merge_sort(arr, left, right);
}
// A function to implement bubble sort(was edited to accomadate vectors.)
void bubble_sort(vector <int> arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
   // print_vec(arr);
}
//Counting sort 
void counting_sort(vector<int> input) {
    vector<int> output(input.size(), 0);

    //Obtaining max element in vector
    int max = input.at(0);
    for (int m = 0; m < input.size(); m++) {
        if (max < input[m]) max = input[m];
    }

    vector<int> aux(max + 1, 0);
    //Loop through input array and store count of each element in the auxiliary array such that the element is the index of the auxiliary array and value is the count of that element
    int val;
    for (int i = 0; i < input.size(); i++) {
        val = input[i];
        aux[val]++;
    }

    //Loop through auxiliary array and cumulatively add values of the array
    for (int j = 1; j <= max; j++) aux[j] += aux[j - 1];

    for (int i = input.size() - 1; i >= 0; i--) {
        //output.at(aux.at(input.at(i)));
        output[--aux[input[i]]] = input[i];
    }

    //Ensuring the output array is the same size as the input array
    for (int j = 0; j < input.size(); j++) input[j] = output[j];

    //uncomment for debugging
    //print_vec(input);
    //cout << endl;
}


//Radix sort
void radix_sort(vector<int> input) {
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
            val = (input.at(l) / (int)(pow(10, i))) % 10;
            aux.at(val)++;
        }

        //Loop through auxiliary array and cumulatively add values of the array
        for (int j = 1; j <= aux.size() - 1; j++) aux[j] += aux[j - 1];

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
    //uncomment for debugging
    //print_vec(input);
    //cout << endl;
}
//pivoting last
int partition_pivot_last(vector <int> &array, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            swap(array[++i], array[j]);
        }
    }

    swap(array[i + 1], array[high]);
    //print_vec(array);
    return (i + 1); 

}
//pivoting median
int partition_pivot_median(vector <int> &array, int low, int high)
{
    int pivot;
    int mid = (low + high) / 2;
    if (array[mid] < array[low])
        swap(array[mid], array[low]);
    if (array[high] < array[low])
        swap(array[high], array[low]);
    if (array[high] < array[mid])
        swap(array[high], array[mid]);
    swap(array[mid], array[high - 1]);
    pivot = array[high - 1];
    //print_vec(array);
    return partition_pivot_last(array, low, high);
    
}
//sorting from median  pivot, seems to like a best all rounder
//(was edited to accomadate vectors.)
void quick_sort(vector <int> arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition_pivot_median(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
    //print_vec(arr);
}

void insertion_sort(vector <int> vec, int n){
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = vec.at(i);
        j = i - 1;

        while (j >= 0 && vec.at(j) > key)
        {
            vec.at(j + 1) = vec.at(j);
            j = j - 1;
        }
        vec. at(j + 1) = key;
    }
    //print_vec(vec);
}
// heapify portion of heap sort
void max_heapify(vector<int>& Arr, int n, int i) {
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && Arr.at(left) > Arr.at(max))
        max = left;

    if (right < n && Arr.at(right) > Arr.at(max))
        max = right;


    if (max != i) {
        swap(Arr.at(i), Arr.at(max));
        max_heapify(Arr, n, max);
    }
};

void heap_sort(vector<int> Arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(Arr, n, i);


    for (int i = n - 1; i >= 0; i--) {
        swap(Arr.at(0), Arr.at(i));
        max_heapify(Arr, i, 0);
    }
   // print_vec(Arr);
} //Heapifies entire list Min Heap






// fill the vector from 1 to size x
vector<int> fill_vec(int x) {
    vector<int> vec;
    for (int i = 1; i <= x; i++) {
        vec.push_back(i);
        //cout << vec.at(i-1)<<" ";
    }

    cout << endl;
    return vec;
}
// runs the time test for all sorting algrothms and writes the results to the respective output file
void time_test() {
    cout << "time testing code\n";
    // opens all files to write to
    ofstream mergefile;
    mergefile.open("merge.txt");
    fstream selectfile;
    selectfile.open("select.txt");
    ofstream insertfile;
    insertfile.open("insert.txt");
    ofstream bubblefile;
    bubblefile.open("bubble.txt");
    ofstream quickfile;
    quickfile.open("quick.txt");
    ofstream heapfile;
    heapfile.open("heap.txt");
    ofstream countfile;
    countfile.open("count.txt");
    ofstream radixfile;
    radixfile.open("radix.txt");
    
        
    vector<int> sorted;//pre sorted
    vector<int> worst;// reverse sorted
    vector<int> half;//half sorted/ half random
    vector<int> rand;//completely
    int n = 0; // will be set to size of the vector
    clock_t time_req;
        
        
        
    for (int j = 0; j < 3; j++) {

        for (int i = 1; i <= 5; i++) {
            sorted = fill_vec(pow(10, i));
            n = sorted.size();
            //testing sort
            time_req = clock();
            call_merge_sort(sorted, 0, n - 1);
            time_req = clock() - time_req;
            // writes the time to the file, set and forget.
            if (i==1)mergefile << "sorted" << endl <<  (double)time_req / CLOCKS_PER_SEC << endl;
            else mergefile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            selection_sort(sorted, n);
            time_req = clock() - time_req;
            if (i == 1)selectfile << "sorted" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else selectfile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            insertion_sort(sorted, n);
            time_req = clock() - time_req;
            if (i == 1)insertfile << "sorted" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else insertfile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            bubble_sort(sorted, n);
            time_req = clock() - time_req;
            if (i == 1) bubblefile << "sorted" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else bubblefile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            quick_sort(sorted, 0, n - 1);
            time_req = clock() - time_req;
            if (i == 1)quickfile << "sorted" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else quickfile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            heap_sort(sorted, n);
            time_req = clock() - time_req;
            if (i == 1)heapfile << "sorted" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else heapfile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            radix_sort(sorted);
            time_req = clock() - time_req;
            if (i == 1) radixfile << "sorted" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else radixfile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            counting_sort(sorted);
            time_req = clock() - time_req;
            if (i == 1) countfile << "sorted" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else countfile << (double)time_req / CLOCKS_PER_SEC << endl;

        }
        // deletes the vector for optimization of memory
        sorted.clear();
        //the rest follow suit
        for (int i = 1; i <= 5; i++) {
            worst = fill_vec(pow(10, i));
            n = worst.size();
            reverse(worst.begin(), worst.end());
            //testing sort
            time_req = clock();
            call_merge_sort(worst, 0, n - 1);
            time_req = clock() - time_req;
            if (i == 1)mergefile << "reversed" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else mergefile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            selection_sort(worst, n);
            time_req = clock() - time_req;
            if (i == 1)selectfile << "reversed" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else selectfile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            insertion_sort(worst, n);
            time_req = clock() - time_req;
            if (i == 1)insertfile << "reversed" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else insertfile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            bubble_sort(worst, n);
            time_req = clock() - time_req;
            if (i == 1)bubblefile << "reversed" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else bubblefile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            quick_sort(worst, 0, n - 1);
            time_req = clock() - time_req;
            if (i == 1)quickfile << "reversed" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else quickfile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            heap_sort(worst, n);
            time_req = clock() - time_req;
            if (i == 1)heapfile << "reversed" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else heapfile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            radix_sort(worst);
            time_req = clock() - time_req;
            if (i == 1)radixfile << "reversed" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else radixfile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            counting_sort(worst);
            time_req = clock() - time_req;
            if (i == 1)countfile << "reversed" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else countfile << (double)time_req / CLOCKS_PER_SEC << endl;

        }
        worst.clear();

        for (int i = 1; i <= 5; i++) {
            half = fill_vec(pow(10, i));
            n = half.size();
            random_shuffle(half.begin() + half.size() / 2, half.end());
            time_req = clock();
            call_merge_sort(half, 0, n - 1);
            time_req = clock() - time_req;
            if (i == 1)mergefile << "half" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else mergefile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            selection_sort(half, n);
            time_req = clock() - time_req;
            if (i == 1)selectfile << "half" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else selectfile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            insertion_sort(half, n);
            time_req = clock() - time_req;
            if (i == 1)insertfile << "half" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else insertfile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            bubble_sort(half, n);
            time_req = clock() - time_req;
            if (i == 1)bubblefile << "half" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else bubblefile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            quick_sort(half, 0, n - 1);
            time_req = clock() - time_req;
            if (i == 1)quickfile << "half" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else quickfile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            heap_sort(half, n);
            time_req = clock() - time_req;
            if (i == 1)heapfile << "half" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else heapfile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            radix_sort(half);
            time_req = clock() - time_req;
            if (i == 1)radixfile << "half" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else radixfile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            counting_sort(half);
            time_req = clock() - time_req;
            if (i == 1)countfile << "half" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else countfile << (double)time_req / CLOCKS_PER_SEC << endl;

        }
        half.clear();

        for (int i = 1; i <= 5; i++) {
            rand = fill_vec(pow(10, i));
            n = rand.size();
            random_shuffle(rand.begin(), rand.end());
            time_req = clock();
            call_merge_sort(rand, 0, n - 1);
            time_req = clock() - time_req; 
            if (i == 1)mergefile << "random" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else mergefile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            selection_sort(rand, n);
            time_req = clock() - time_req;
            if (i == 1)selectfile << "random" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else selectfile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            insertion_sort(rand, n);
            time_req = clock() - time_req;
            if (i == 1)insertfile << "random" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else insertfile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            bubble_sort(rand, n);
            time_req = clock() - time_req;
            if (i == 1)bubblefile << "random" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else bubblefile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            quick_sort(rand, 0, n - 1);
            time_req = clock() - time_req;
            if (i == 1)quickfile << "random" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else quickfile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            heap_sort(rand, n);
            time_req = clock() - time_req;
            if (i == 1)heapfile << "random" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else heapfile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            radix_sort(rand);
            time_req = clock() - time_req;
            if (i == 1)radixfile << "random" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else radixfile << (double)time_req / CLOCKS_PER_SEC << endl;
            time_req = clock();
            counting_sort(rand);
            time_req = clock() - time_req;
            if (i == 1)countfile << "random" << endl << (double)time_req / CLOCKS_PER_SEC << endl;
            else countfile << (double)time_req / CLOCKS_PER_SEC << endl;

        }
        rand.clear();
    }
    
    //closes files.
    mergefile.close();
    selectfile.close();
    insertfile.close();
    bubblefile.close(); 
    quickfile.close(); 
    heapfile.close(); 
    radixfile.close();
    countfile.close();
    //cout << "done writeing to file\n";
    cout << "time test are finished.\n";
}

// Returns number of pairs in arr[0..n-1] with sum equal
// to 'sum'
void getPairsCount(int arr[], int n, int sum)
{
    int count = 0; // Initialize result

    // Consider all possible pairs and check their sums
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == sum)
                count++;
    cout << count;
}
//find to 'sum'
void findPair(int nums[], int n, int target)
{
    // create an empty map
    unordered_map<int, int> map;

    // do for each element
    for (int i = 0; i < n; i++)
    {
        // check if pair (nums[i], target - nums[i]) exists

        // if the difference is seen before, print the pair
        if (map.find(target - nums[i]) != map.end())
        {
            cout << "Pair found (" << nums[map[target - nums[i]]] << ", "
                << nums[i] << ")\n";
            return;
        }

        // store index of the current element in the map
        map[nums[i]] = i;
    }

    // we reach here if the pair is not found
    cout << "Pair not found";
}

int main(){
    cout << "Enter 1 to run part one  of the project(sort time test), or 2 for part 2(2 sums)\n";
    int x = 0;
    cin >> x;
    // Part 1 provided by Rivera
    if (x==1) time_test();
    // part 2 provided by Gaur
    if (x == 2) {
        clock_t time;
        int x, arr[100], y, choice, a = 0;
        cout << endl << "CSCI 115 TERM PROJECT PART 2" << endl << "PRESS 1 FOR BRUTE FORCE" << endl << "PRESS 2 USING MOST EFFICIENT METHOD USING HASH TABLES" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << endl << "--- --- ---BRUTE FORCE--- --- ---" << endl << "PLEASE ENTER THE TOTAL ELEMENTS YOU WANT IN ARRAY :" << endl;
            cin >> x;
            cout << "PLEASE ENTER THE ELEMENTS YOU WANT IN YOUR ARRAY : " << endl;
            for (a = 1; a <= x; a++)
            {
                cout << "Element " << a << " is   :   ";
                cin >> arr[a];
            }
            cout << "Enter the sum to be printed" << endl;
            cin >> y;
            cout << "Count of pairs is" << endl;
            time = clock();
            getPairsCount(arr, x, y);
            time = clock() - time;
            cout << endl << endl << "Time Required for BRUTE FORCE sum : " << (float)time / CLOCKS_PER_SEC << " Seconds " << endl;
            break;

        case 2:
            cout << endl << "--- --- ---EFFICIENT METHOD--- --- ---" << endl << "PLEASE ENTER THE TOTAL ELEMENTS YOU WANT IN ARRAY :" << endl;
            cin >> x;
            cout << "PLEASE ENTER THE ELEMENTS YOU WANT IN YOUR ARRAY : " << endl;
            for (a = 1; a <= x; a++)
            {
                cout << "Element " << a << " is   :   ";
                cin >> arr[a];
            }
            cout << "Enter the sum to be printed" << endl;
            cin >> y;
            cout << "Count of pairs is" << endl;
            time = clock();
            findPair(arr, x, y);
            time = clock() - time;
            cout << endl << endl << "Time Required for EFFICIENT METHOD sum : " << (float)time / CLOCKS_PER_SEC << " Seconds " << endl;
            break;

        default:
            break;
        }
    }
    return 0;


   

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu