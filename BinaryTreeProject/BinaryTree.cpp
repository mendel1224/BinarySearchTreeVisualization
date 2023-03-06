#include "BinaryTree.h"




void BinaryTree::insertNode(Node* &nodePtr , Node* &currentNode) // Function to recursively traverse the Tree and inset Node at the right location
{
	if (nodePtr == nullptr)
	{
		nodePtr = currentNode;
	}
	else if (currentNode->num < nodePtr->num)
	{
		insertNode(nodePtr->leftPtr, currentNode); // Search our left side for the correct posiion
	}
	else 
		insertNode(nodePtr->rightPtr, currentNode); // Search our right side for the correct position
}

BinaryTree::BinaryTree()
{
	root = nullptr; 
}

BinaryTree::~BinaryTree()
{
	destroyTree(root);
}



void BinaryTree::addNum(int number)
{
	Node *currentNode = nullptr; // Create a Node pointer and set to nullPTR
	currentNode = new Node; // Dynamically create a new Node and set the newNode pointer to point to it
	currentNode->num = number; // Store number in our Node

	currentNode->leftPtr = nullptr; 
	currentNode->rightPtr = nullptr;
	insertNode(root, currentNode); // Recursivley traverse tree and insert into the right spot
}

void BinaryTree::userNum()
{
	int num;
	cout << "Enter a number to be added to the tree:";
	cin >> num;
	addNum(num);
}

bool BinaryTree::searchTree(int value)
{
	// Searches the tree for a number. If the number is in the tree returns true, otherwise returns false
	
	Node* nodePtr = root;
	Node* temp = nullptr;
	while (nodePtr)
	{
		if (nodePtr->num == value)
		{
			temp = nodePtr;
			
			
			delete temp;
			return true;
		}
			
		
		else if (value < nodePtr->num)
		{
			nodePtr = nodePtr->leftPtr;
		}
		else
		{
			
			nodePtr = nodePtr->rightPtr;
		}
	}
	return false;
}

 BinaryTree::Node*  BinaryTree::searchAndDelete(Node* root, int number)
 {
	
	Node* temp;

	if (root == nullptr)
	{
		 return root;
	}

	if (number < root->num) // If less than the value in root, go left
	{
		root->leftPtr = searchAndDelete(root->leftPtr, number); 
	} 

	else if (number > root->num) // If number we are looking for is greater root value, go right
	{
		root->rightPtr = searchAndDelete(root->rightPtr, number);
	}

	else // If we have found our number
	{
		if (root->leftPtr == nullptr && root->rightPtr == nullptr)
		{
			delete root;    // Actually removing the memory. 
			root = nullptr; // move pointer to nullptr
			return root;    // Patching the parents pointer 
		}

		else if (root->leftPtr == nullptr) // If there is no left child
		{
			temp = root->rightPtr;
			delete root;
			return temp;
		}

		else if (root->rightPtr == nullptr ) // If there is no right child
		{
			temp = root->leftPtr;
			delete root;
			return temp;

		}
        else 
        { // IF there are 2 children
            Node* replacement = root->rightPtr;
            while (replacement->leftPtr != nullptr)
                replacement = replacement->leftPtr;

            root->num = replacement->num;
            root->rightPtr = searchAndDelete(root->rightPtr, replacement->num);

            return root;
        }
	}
	
	return root;
}



void BinaryTree::displayAll(int xPos, int yPos, int width) // Displays Tree graphically, and the outputs in LNR, NLR,LRN 
{
	char choice = ' ';
	int searchNumber;
	displayGraphically(root, xPos, yPos, width); // Displays Tree in a "Tree" like graphic
	
	cout << endl << endl << endl << endl;
	
	cout << "Displaying Tree in LNR format:" << endl;
	
	displayLNR(root);
	cout << endl << endl;
	
	
	cout << "Displaying Tree in NLR format:" << endl;
	
	displayNLR(root);
	cout << endl << endl;

	
	cout << "Displaying Tree in LRN format:" << endl;
	
	displayLRN(root);
	cout << endl << endl;
	
	// If user would like to a add a Node
	cout << " Would you like to add or  delete a Node? Enter A to add, D to delete, or enter any other key to continue: "  << endl;
	cin >> choice;
	if (choice == 'A' || choice == 'a')
	{
		userNum(); // Asks user for which number they would like to add then adds it to the tree 
		system("CLS");
		displayAll(xPos, yPos, width);
	}
	else if (choice == 'D' || choice == 'd')
	{
		cout << " What number is in the node you wish to delete?" << endl;
		cin >> searchNumber;
		searchAndDelete(root, searchNumber);
		
		system("CLS"); // Clear Screen and display updated tree
		displayAll(xPos, yPos, width);
	}
}

void BinaryTree::displayGraphically(Node * nodePtr, int xPos, int yPos,double  width)
{
	if (nodePtr)
	{
		gotoxy(xPos, yPos);
		cout << nodePtr->num << endl; // Print current node
		if (nodePtr->leftPtr)
		{
			gotoxy(xPos-2, yPos +1);
				cout << char(47);
		}
		if (nodePtr->rightPtr)
		{
			gotoxy(xPos + 2, yPos + 1);
			cout << char(92);
		}
		width = width / 2; // Width determines distance between 2 children
		displayGraphically(nodePtr->leftPtr, xPos - width, yPos + 2, width); // Traverse left
		displayGraphically(nodePtr->rightPtr, xPos + width, yPos + 2, width); // Traverse right
	}
	else
		return;
}


void BinaryTree::displayLNR(Node * nodePtr)
{
	if (nodePtr)
	{
		
		displayLNR(nodePtr->leftPtr); // Traverse left 
		cout << nodePtr->num << endl; // Print current node
		displayLNR(nodePtr->rightPtr); // Traverse right
	}
	else 
		return;
}

void BinaryTree::displayNLR(Node * nodePtr)
{
	if (nodePtr)
	{
		cout << nodePtr->num << endl; // Print current node
		
		
		displayNLR(nodePtr->leftPtr ); // Traverse left
		displayNLR(nodePtr->rightPtr); // Traverse right
	}
	else
		return;
}

void BinaryTree::displayLRN(Node* nodePtr)
{
	if (nodePtr)
	{
		displayLRN(nodePtr->leftPtr); // Traverse left
		displayLRN(nodePtr->rightPtr);  // Traverse right
		cout << nodePtr->num << endl; // Print current node
	}
}

void BinaryTree::gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

void BinaryTree::destroyTree(Node* pointer) // Function that traverses through the tree and deallocates memory
{
	if (pointer)
	{
		if (pointer->leftPtr) // Traverse left side
		{
			destroyTree(pointer->leftPtr);
		}
		if (pointer->rightPtr) // Traverse right side
		{
			destroyTree(pointer->rightPtr);
		}
		delete pointer; // Free memory
	
	}
}

