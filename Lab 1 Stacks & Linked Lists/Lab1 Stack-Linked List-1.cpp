// Lab1 Stack-Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
using namespace std;

//---------STACK DATA STRUCTURE PORTION---------------------
//Struct for stack
struct Stack {
    int top = -1;
    int arr[10] = {}; //Array of ints for stack data structure;
    bool isFull() { return top >= (int)((sizeof(arr) / sizeof(int)) - 1); }
    void push(int a);
    int pop();
    int peek();
    void print();
};

//Perform push operation on stack
void Stack::push(int a) {
    if (!isFull()) {
        top++;
        arr[top] = a;
    }
    else {
        cout << "Stack Overflow\n";
        cout << top << endl;
    }
}

//Perform pop operation on stack
int Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow\n";
        return -1;
    }
    else {
        int retval = arr[top];
        top--;
        return retval;
    }
}

//Perform peek operation on stack
int Stack::peek() {
    if (top < 0) {
        cout << "Stack Underflow\n";
        return -1;
    }
    else return arr[top];
}

//Print out all elements of stack
void Stack::print() {
    for (auto i = top; i >= 0; i--) cout << arr[i] << " ";
    cout << endl;
}

//----------LINKED LIST DATA STRUCTURE PORTION-----------------------

//Class for linked list

struct Node {
    int data;
    Node* next;
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

struct LL {
    Node* head = nullptr;
    LL (int new_data) {
        head = new Node(new_data, nullptr);
    }

    LL() { head = nullptr; }
    void insert(int b);
    void del_first();
    void del_last();
    void LLprint();
};

//Insert data into linked list
    void LL::insert(int b) {
        Node* x = new Node(b, head);
        head = x;
    }

    //Delete first item from linked list
    void LL::del_first() {
        if (head == nullptr) return;
        Node* x = head;
        head = head->next;
        delete x;
    }

    //Delete last item from linked list
    void LL::del_last() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            return;
        }
        Node* x = head;
        Node* y = head;
        while (x->next != nullptr) {
            x = x->next;
            if (x->next != nullptr) y = y->next;
        }
        x = nullptr;
        y->next = x;
        return;
    }

    //Display contents of linked list
    void LL::LLprint() {
        Node* a = head;
        while (a != nullptr) {
            cout << a->data << " ";
            a = a->next;
        }
        cout << endl;
    }
    
/* Linked list
next = head
head = new node
new node = next
*/

int main() {
    //Implementation of stack
    Stack x;
    x.push(20);
    x.push(40);
    x.push(60);
    
    cout << "Items in the stack: ";
    x.print();
    cout << "Popped item is: " << x.pop() << endl;
    cout << "Peeked item is: " << x.peek() << endl;
    cout << "Items in the stack: ";
    x.print();

    cout << endl;

    //-------------------------------------------------

    //Implementation of linked list
    //Insert 3 numbers into linked list
    LL* head = new LL();
    head->insert(60);
    head->insert(40);
    head->insert(20);
    cout << "Items in the linked list: ";
    head->LLprint();

    //Delete first and last elements
    head->del_first();
    cout << "Items in the linked list after deleting the first element: ";
    head->LLprint();
    head->del_last();
    cout << "Items in the linked list after deleting the last element: ";
    head->LLprint();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu