
#pragma once
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST {
private:
    Node* root;
public:
    BST();
    Node* get_root() { return this->root; }
    void print_post(Node* root);
    void print_all(Node* root);
    Node* insert(Node* root, int data);
    void findNode(Node* root, int data);
    int maximum(Node* root);
};

BST::BST() { this->root = nullptr; }

//Print all elements inserted in the tree, order doesn't matter
void BST::print_all(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    print_all(root->right);
    print_all(root->left);
}

//Post order traversal
void BST::print_post(Node* root) {
    if (root == nullptr) return;
    print_post(root->left);
    print_post(root->right);
    cout << root->data << " ";
}

//Inserting a node into the tree
Node* BST::insert(Node* root, int data) {
    if (this->root == nullptr) {
        this->root = new Node(data);
        return this->root;
    }
    if (root == nullptr) return new Node(data);
    else if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

//Searching for a node in the tree
void BST::findNode(Node* root, int data) {

    //If root is null
    if (root == nullptr) cout << "Not found\n";

    if (root->data == data) cout << data << endl;

    //if data is greater than the root's data
    if (root->data < data) return findNode(root->right, data);

    //if data is smaller than the root's data
    if (root->data > data) return findNode(root->left, data);
}

//Finding the maximum node in the tree
int BST::maximum(Node* root) {
    if (root == nullptr) return -1;
    else if (root->right == nullptr) return root->data;
    else return maximum(root->right);
}