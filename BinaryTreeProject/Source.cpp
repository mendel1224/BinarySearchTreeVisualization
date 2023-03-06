// Created by Menachem Shifrin
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include "BinaryTree.h"
using namespace std;





int main()
{
	int number;
	BinaryTree B;
	ifstream readFile;
	readFile.open("c:\\temp\\input.txt"); // Open file;
	if (readFile)
	{
		while (readFile >> number && number!=-1) 
		{
			B.addNum(number); // Place numbers into nodes and insert into tree
		}
	}
	else // If file can't be read
	{
		cout << "Error opening file";
	}
	cout << endl << endl;
	cout << "The tree:" << endl;
	B.displayAll(25, 5, 10.5); 
	
		return 0;
}