#include <iostream>
using namespace std;

class Node {
public:
	Node(int data){
		this->data = data;
		this->LeftChild = NULL;
		this->RightChild = NULL;
	};
	int data;
	Node* LeftChild;
	Node* RightChild;
};

class BST {
private:
	Node* root;

public:
	BST();
	Node* getRoot(){ return this->root; };
	void printTree(Node *root);
	Node* InsertNode(Node *root,int data);
	bool FindNode(Node *root,int data);
	int Largest(Node *root);
};
