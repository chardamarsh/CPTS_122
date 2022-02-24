/* Programmer: Charles Marshall
*
Class : CPTS 122; Lab section 13

Programming Assignment : PA 2 : Digital Music Manager and Doubly Linked Lists

Date : 1 - 29 - 2022

Description : This file uses the functions defined in functions.c to simulate a digital music manager.

*/
#include "functions.h"

int main()
{
	FILE* infile;
	FILE* outfile;

	int* shuffleorder;

	srand(time(NULL));
	
	infile = fopen("musicPlayList1.csv", "r");

	Node* playlist = NULL;
	if (!infile)
	{
		printf("Playlist not found.\n");
	}
	if (infile != NULL)
	{
		int command = 0;
		while (command != 11)
		{
			command = mainMenu();
			system("cls");
			if (command == 1)
			{
				//infile = fopen("musicPlayList.csv", "r");
				load(infile, &playlist);
				//fclose(infile);
			}
			if (command == 2)
			{
				outfile = fopen("musicPlayList1.csv", "w");
				store(&playlist, outfile);
				//fclose(outfile);
			}
			if (command == 3)
			{
				display(&playlist);
			}
			if (command == 4)
			{
				insert(&playlist);
			}
			if (command == 5)
			{
				delete(&playlist);
			}
			if (command == 6)
			{
				edit(&playlist, 1);
			}
			if (command == 7)
			{
				sort(&playlist);
			}
			if (command == 8)
			{
				rate(&playlist);
			}
			if (command == 9)
			{
				play(&playlist);
			}
			if (command == 10)
			{
				shuffle(&playlist);
			}
			system("pause");
			system("cls");
		}
	}

	return 0;
}