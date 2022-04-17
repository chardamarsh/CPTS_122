/* Programmer: Charles Marshall
*
Class : CPTS 122; Lab section 13

Programming Assignment : PA 6 : Morse Code Lookup BST

Date : 3 - 27 - 2022

Description : This file contains the class function definitions for the BST Node class.

*/

#include "node.h"


Node::Node(string str, char c)
{
	this->nodeChar = c;
	this->nodeString = str;
}
Node::~Node()
{
	cout << "Deleting morse code for: " << this->nodeChar << endl;
	if (this->leftNode != nullptr)
	{
		delete this->leftNode;
	}
	if (this->rightNode != nullptr)
	{
		delete this->rightNode;
	}
}

Node* Node::getLeft() const
{
	return this->leftNode;
}
Node* Node::getRight() const
{
	return this->rightNode;
}
char Node::getChar() const
{
	return this->nodeChar;
}

string Node::getString() const
{
	return this->nodeString;
}

void Node::setLeft(Node* const newLeft)
{
	this->leftNode = newLeft;
}
void Node::setRight(Node* const newRight)
{
	this->rightNode = newRight;
}
void Node::setChar(const char newChar)
{
	this->nodeChar = newChar;
}
void Node::setString(const string newString)
{
	this->nodeString = newString;
}

void Node::printNode()
{
	cout << this->nodeString;
}