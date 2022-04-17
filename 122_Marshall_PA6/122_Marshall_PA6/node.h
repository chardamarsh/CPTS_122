/* Programmer: Charles Marshall
*
Class : CPTS 122; Lab section 13

Programming Assignment : PA 6 : Morse Code Lookup BST

Date : 3 - 27 - 2022

Description : This file contains the class header for the BST Node class.

*/
#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node
{
public:

	friend class Tree;
	Node(string str = "", char c  = '\0');
	~Node();

	Node* getLeft() const;
	Node* getRight() const;
	char getChar() const;
	string getString() const;

	void setLeft(Node* const newLeft);
	void setRight(Node* const newRight);
	void setChar(const char newChar);
	void setString(const string newString);

	void printNode();

private:
	string nodeString;
	char nodeChar;
	Node* leftNode;
	Node* rightNode;
};