#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;
#pragma once


class BinaryTree
{
private:

	struct Node
	{
		int num;
		Node* leftPtr; // Points to left node
		Node* rightPtr; // Points to right node

	};
	Node* root; // Pointer to root of Tree

	void insertNode(Node*&, Node*&); // Inserts a user entered number into the Tree 


public:
	BinaryTree(); // Constructor
	~BinaryTree(); // Destructor
	void addNum(int); // Adds a number into the Tree
	void userNum(); // Asks user for a number and adds it to the tree
	bool searchTree(int); // Searches the tree for a value, returns true if its found
	Node* searchAndDelete(Node*, int); // Searches if a number is in the tree and deletes it if it is
	void displayAll(int, int, int); // Display Tree in LNR, NLR, and LRN formats
	void displayGraphically(Node*, int xPos, int yPos, double width); //Displays tree in a visual format
	void displayLNR(Node*); // Displays Binary Tree in LNR 
	void displayNLR(Node*); // Displays Binary Tree in NLR
	void displayLRN(Node*); // Displays Binary Tree in LRN
	void gotoxy(int column, int line); // Configures output location
	void destroyTree(Node*); // Called by the destructor to free memory
};