// Lab8 BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include "Lab8 HEADER file.h"
using namespace std;

int main() {

    BST node;
    int num = 0;
    while (true) {
        for (int i = 0; i < 5; i++) {
            int x = rand() % 50;
            node.insert(node.get_root(), x);
            //cout << node.get_root()->data << endl;
        }

        cout << "Inserted elements: ";
        node.print_all(node.get_root());

        cout << endl;
        cout << "Post-order: ";
        node.print_post(node.get_root());

        cout << endl;
        cout << "Largest element in the tree: ";
        cout << node.maximum(node.get_root());

        cout << endl;
        cout << "Insert a number for look up: ";
        cin >> num;

        node.findNode(node.get_root(), num);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu