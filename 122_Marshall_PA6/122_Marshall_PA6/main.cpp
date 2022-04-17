/* Programmer: Charles Marshall
*
Class : CPTS 122; Lab section 13

Programming Assignment : PA 6 : Morse Code Lookup BST

Date : 3 - 27 - 2022

Description : This uses the class Tree and Node and their defined functions to convert a string from two input files: 
	MorseTable.txt, which contains a conversion table from characters to morse code, and Convert.txt, which contains a string to be converted to morse code. 

*/

#include "tree.h"

int main(void)
{
	ifstream morseFile;
	ifstream stringFile;
	Tree MorseBST;
	string inputString;
	string inputStringLine;
	string outputCode;

	

	morseFile.open("MorseTable.txt");
	stringFile.open("Convert.txt");

	if (morseFile.is_open() && stringFile.is_open())
	{
		while (!stringFile.eof())
		{
			getline(stringFile, inputStringLine); //reads string to be converted line by line.
			inputString += inputStringLine; //Adds each line to the full string.
		}



		outputCode = MorseBST.MorseCodeCoversion(inputString, morseFile);

		//MorseBST.print();  //use to test the print function

		//system("pause");

		cout << inputString << endl;


		cout << outputCode << endl;
		system("pause");

		morseFile.close();
		stringFile.close();
	}





	return 0;
}