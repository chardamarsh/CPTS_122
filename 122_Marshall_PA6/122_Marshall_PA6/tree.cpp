/* Programmer: Charles Marshall
*
Class : CPTS 122; Lab section 13

Programming Assignment : PA 6 : Morse Code Lookup BST

Date : 3 - 27 - 2022

Description : This file contains the class function definitions for the Tree class.

*/
#include "tree.h"

Tree::Tree(Node* newRoot)
{
	this->rootNode = newRoot;
}
Tree::~Tree()
{
	this->destroyTree(this->rootNode);
}
/***********************************************************************************************************************************
  * Function:              insert()                                                                                                *
  * Description:		   Inserts a new node into a binary tree from left to right                                                *
  * Input parameters:      Tree root node, new string, new char                                                                    *
  * Returns:               none                                                                                                    *
  * Preconditions:         BST must be declared in memory.                                                                         *
  * Postconditions:        The tree will contain a new node with the input data.                                                   *
  **********************************************************************************************************************************/
void Tree::insert(Node* tree, string str, char c)
{
	bool left = false;
	if (tree == nullptr)
	{
		this->rootNode = new Node(str, c);
	}
	else
	{
		if ((int)c % 2 == 0) // uses ASCII value of the character to insert each character from left to right in the tree.
		{
			if (tree->getRight() == nullptr)
			{
				tree->setRight(new Node(str, c));
			}
			else
			{
				insert(tree->getRight(), str, c);
			}
		}
		else if ((int)c % 2 != 0)
		{
			if (tree->getLeft() == nullptr)
			{
				tree->setLeft(new Node(str, c));
			}
			else
			{
				insert(tree->getLeft(), str, c);
			}
		}

	}
}
void Tree::insert(string str, char c) //helper function for insert()
{
	insert(this->rootNode, str, c);
}

/***********************************************************************************************************************************
  * Function:              print()                                                                                                  *
  * Description:		   Recursively prints the data contained in a BST in order.                                                 *
  * Input parameters:      Root node of a BST                                                                                       *
  * Returns:               None																									    *
  * Preconditions:         Tree must not be nullptr.                                                                                *
  * Postconditions:        None                                                                                                     *
  **********************************************************************************************************************************/
void Tree::print(Node* tree)
{
	if (tree != nullptr)
	{
		print(tree->getLeft());
		cout << tree->getChar() << "  " << tree->getString();
		print(tree->getRight());
	}
}

void Tree::print()
{
	print(this->rootNode);
}

/***********************************************************************************************************************************
  * Function:              search()                                                                                                 *
  * Description:		   Searches for a matching character in a BST containing the coversion of characters to morse code.         *
  * Input parameters:      Root node pointer, Morse code string pointer, target char                                                *
  * Returns:               Updates input string pointer to contain the morse code coversion for the target char.                    *
  * Preconditions:         The array must not be empty, and the target char must have a valid morse code equivalent                 *
  * Postconditions:        none                                                                                                     *
  **********************************************************************************************************************************/
void Tree::search(Node* tree, string* Morse, char c) //must be a character contained in the tree.
{
	if (tree != nullptr)
	{
		if (tree->getChar() == c)
		{
			*Morse = tree->getString();
			return;
		}
		else
		{
			search(tree->getLeft(), Morse, c);
			search(tree->getRight(), Morse, c);
		}
	}
}

/***********************************************************************************************************************************
  * Function:              MorseCodeConversion()                                                                                    *
  * Description:		   Converts an input string to morse code using a file containing a morse code coversion table.             *
  * Input parameters:      String to be converted, morse code conversion file                                                       *
  * Returns:               String containing the morse code coversion of the input string.                                          *
  * Preconditions:         The Morse code file must be open. the input string must only contain chars with a morse code equivalent. *
  * Postconditions:        none                                                                                                     *
  **********************************************************************************************************************************/
string Tree::MorseCodeCoversion(string str, ifstream& infile)
{
	if (infile.is_open())
	{
		int len = str.length();
		char c = ' ';
		char ch;
		bool found = false;
		string chstr;
		string morseCode = "";
		string morseString = "";
		while (!infile.eof())
		{
			
			getline(infile, chstr);
			getline(infile, morseCode);

			c = chstr[0];
			this->insert(morseCode, c);
		}
		for (int i = 0; i < len; i++)
		{
			found = 0;
			ch = str[i];
			if ((int)ch > 96 && (int)ch < 123) //lower case chars to be converted to uppercase
			{
				this->search(this->rootNode, &morseCode, toupper(ch));
				morseString += morseCode;
				found = true;
			}
			if ((int)ch == 32) //space char
			{
				morseString += "   ";
				found = true;
			}
			if(found == false)
			{
				this->search(this->rootNode, &morseCode, ch);
				morseString += morseCode;
			}
			morseString += " ";

		}
		return morseString;
	}
}

/***********************************************************************************************************************************
  * Function:              destroyTree()                                                                                            *
  * Description:		   Recursively deletes the nodes contained in a BST in postorder.                                           *
  * Input parameters:      Root node pointer of the tree to be deleted.                                                             *
  * Returns:               None                                                                                                     *
  * Preconditions:         None                                                                                                     *
  * Postconditions:        Input BST will be removed from memory.                                                                   *
  **********************************************************************************************************************************/
void Tree::destroyTree(Node* tree)
{
	if (tree != nullptr)
	{
		destroyTree(tree->leftNode); //accessed via friend class
		destroyTree(tree->rightNode);
		delete tree;
	}
	if (this->rootNode != nullptr)
	{
		delete this->rootNode;
	}
}