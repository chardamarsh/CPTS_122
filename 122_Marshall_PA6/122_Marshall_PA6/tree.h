/* Programmer: Charles Marshall
*
Class : CPTS 122; Lab section 13

Programming Assignment : PA 6 : Morse Code Lookup BST

Date : 3 - 27 - 2022

Description : This file contains the class header for the Tree class.

*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "node.h"

class Tree
{
public:
	friend class Node;

	Tree(Node* newRoot = nullptr);
	~Tree();

	void insert(Node* tree, string str, char c);
	void insert(string str, char c);

	void print(Node* tree);
	void print();

	void search(Node* tree, string* morse, char c);

	string MorseCodeCoversion(string str, ifstream& infile);

	


private:
	void destroyTree(Node* tree);
	Node* rootNode;
};