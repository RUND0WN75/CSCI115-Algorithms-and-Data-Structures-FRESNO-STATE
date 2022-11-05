// Lab2 - Fibonacci numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <cmath>
#include <array>
using namespace std;

/*
Fibonacci equation
f(0) = 0
f(1) = 1
f(n) = f(n-1) + f(n-2) for n > 1
*/

//Recursive method - don't input numbers bigger than 10 
unsigned long long rec(int n) {
		if (n == 0 || n == 1) return n;
		else return rec(n - 1) + rec(n - 2);
}

//Iterative method
unsigned long long iter(int n) {
	unsigned long long prev = 0;
	unsigned long long cur = 1;
	unsigned long long next = prev + cur;
	if (n == 0 || n == 1) return n;
	for (int i = 2; i < n; i++) {
		prev = cur;
		cur = next;
		next = prev + cur;
	}
	return next;
}

int main() {
		int x = 0;
		cout << "Input: ";
		cin >> x;
		cout << endl;

		clock_t time = clock();
		
		cout << "Output using recursion: " << rec(x) << endl;
		time = clock() - time;
		cout << "Running time with recursion: " << (float)time / CLOCKS_PER_SEC << endl;
		cout << endl;
		
		time = clock();

		cout << "Output using iteration: " << iter(x) << endl;
		time = clock() - time;
		cout << "Running time with iteration: " << (float)time / CLOCKS_PER_SEC << endl;
		cout << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu