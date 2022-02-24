/* Programmer: Charles Marshall
*
Class : CPTS 122; Lab section 13

Programming Assignment : PA 2-3 : Digital Music Manager and Doubly Linked Lists

Date : 1 - 29 - 2022

Description : This file contains the headers and descriptions for the functions used in this assignment.

*/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
//#include <>

typedef struct duration
{
	unsigned int minutes;
	unsigned int seconds;
}Duration;

typedef struct record
{
	char artist[50];
	char album[50];
	char song[50];
	char genre[50];
	Duration length;
	unsigned int timesPlayed;
	unsigned int rating;
}Record;

typedef struct node
{
	Record data;
	struct node* nextNode;
	struct node* prevNode;
}Node;



/*************************************************************************************************************************************************************
  * Function:              mainMenu()                                                                                                                        *
  * Date Created:          1/29/2022                                                                                                                         *
  * Date Last Modified:    1/29/2022                                                                                                                         *
  * Description:		   Prints a menu and returns an integer based on user input.                                                                         *
  * Input parameters:      none                                                                                                                              *
  * Returns:               none                                                                                                                              *
  * Preconditions:         Returns an integer from user input.                                                                                               *
  * Postconditions:        The returned integer is used to determine which function to select and run in main(),                                             *
  ************************************************************************************************************************************************************/
int mainMenu();

/*************************************************************************************************************************************************************
  * Function:              makeNode()                                                                                                                        *
  * Date Created:          1/29/2022                                                                                                                         *
  * Date Last Modified:    1/29/2022                                                                                                                         *
  * Description:		   Creates a doubly linked node which contains a Record struct.                                                                      *
  * Input parameters:      a .csv file opened for reading.                                                                                                   *
  * Returns:               a single node containing data from one line of the input .csv file.                                                               *
  * Preconditions:         the .csv file must be open for reading.                                                                                           *
  * Postconditions:        The returned pointer to a Node will contain data from the .csv file.                                                              *
  ************************************************************************************************************************************************************/
Node* makeNode(infile);

/*************************************************************************************************************************************************************
  * Function:              load()                                                                                                                            *
  * Date Created:          1/29/2022                                                                                                                         *
  * Date Last Modified:    1/30/2022                                                                                                                         *
  * Description:		   Loads all data from a .csv file to a doubly linked list.                                                                          *
  * Input parameters:      a .csv file opened for reading.                                                                                                   *
  * Returns:               none                                                                                                                              *
  * Preconditions:         the .csv file must be open for reading.                                                                                           *
  * Postconditions:        The linked list passed to the function will contain all data from the passed in .csv file.                                        *
  ************************************************************************************************************************************************************/
void load(FILE* infile, Node** playlist);

/*************************************************************************************************************************************************************
  * Function:              store()                                                                                                                           *
  * Date Created:          1/30/2022                                                                                                                         *
  * Date Last Modified:    1/30/2022                                                                                                                         *
  * Description:		   Stores data from a doubly linked list to a .csv file.                                                                             *
  * Input parameters:      a .csv file opened for writing.                                                                                                   *
  * Returns:               none                                                                                                                              *
  * Preconditions:         the .csv file must be open for writing, and the linked list cannot be NULL.                                                       *
  * Postconditions:        the .csv file will be overwritten with data from the linked list.                                                                 *
  ************************************************************************************************************************************************************/
void store(Node** playlist, FILE* outfile);

/*************************************************************************************************************************************************************
  * Function:              display()                                                                                                                         *
  * Date Created:          1/31/2022                                                                                                                         *
  * Date Last Modified:    2/9/2022                                                                                                                          *
  * Description:		   Displays data from the linked list to the user's screen.                                                                          *
  * Input parameters:      A doubly linked list containing playlist data.                                                                                    *
  * Returns:               none                                                                                                                              *
  * Preconditions:         the linked list must not be NULL.                                                                                                 *
  * Postconditions:        none                                                                                                                              *
  ************************************************************************************************************************************************************/
void display(Node** playlist);

/*************************************************************************************************************************************************************
  * Function:              edit()                                                                                                                            *
  * Date Created:          2/2/2022                                                                                                                          *
  * Date Last Modified:    2/9/2022                                                                                                                          *
  * Description:		   Edits user-selected data from a linked list containing playlist data.                                                             *
  * Input parameters:      A doubly linked list containing playlist data.                                                                                    *
  * Returns:               none                                                                                                                              *
  * Preconditions:         the linked list must not be NULL.                                                                                                 *
  * Postconditions:        The linked list will be updated with data defined by the user.                                                                    *
  ************************************************************************************************************************************************************/
void edit(Node** playlist, int shortcut);

//2/7/2022
//2/9/2022
/*************************************************************************************************************************************************************
  * Function:              insert()                                                                                                                            *
  * Date Created:          2/7/2022                                                                                                                          *
  * Date Last Modified:    2/9/2022                                                                                                                          *
  * Description:		   Inserts a new song to the playlist from user input.                                                                               *
  * Input parameters:      A doubly linked list functioning as a playlist; the list can either be empty or contain songs.                                    *
  * Returns:               none                                                                                                                              *
  * Preconditions:         The input list must be declared.                                                                                                  *
  * Postconditions:        The head of the linked list will be updated with the new song from user input.                                                    *
  ************************************************************************************************************************************************************/
void insert(Node** playlist);

//2/9/2022
/*************************************************************************************************************************************************************
  * Function:              delete()                                                                                                                          *
  * Date Created:          2/9/2022                                                                                                                          *
  * Date Last Modified:    2/9/2022                                                                                                                          *
  * Description:		   Deletes a node from a linked list selected by the user.                                                                           *
  * Input parameters:      A doubly linked list containing playlist data.                                                                                    *
  * Returns:               none                                                                                                                              *
  * Preconditions:         the linked list must not be NULL.                                                                                                 *
  * Postconditions:        The user selected song will be deleted from the playlist and its memory will be freed.                                            *
  ************************************************************************************************************************************************************/
void delete(Node** playlist);

/*************************************************************************************************************************************************************
  * Function:              sort()                                                                                                                            *
  * Date Created:          2/10/2022                                                                                                                         *
  * Date Last Modified:    2/12/2022                                                                                                                         *
  * Description:		   Sorts the input list by artist, album, rating, or times played.                                                                   *
  * Input parameters:      A doubly linked list containing playlist data.                                                                                    *
  * Returns:               none                                                                                                                              *
  * Preconditions:         the input list must not be NULL.                                                                                                  *
  * Postconditions:        The input/output list will be sorted by the parameter selected by the user.                                                       *
  ************************************************************************************************************************************************************/
void sort(Node** playlist);

/*************************************************************************************************************************************************************
  * Function:              rate()                                                                                                                            *
  * Date Created:          2/12/2022                                                                                                                         *
  * Date Last Modified:    2/12/2022                                                                                                                         *
  * Description:		   Edits the rating of a user-selected song within a playlist.                                                                       *
  * Input parameters:      A doubly linked list containing playlist data.                                                                                    *
  * Returns:               none                                                                                                                              *
  * Preconditions:         the linked list must not be NULL.                                                                                                 *
  * Postconditions:        The selected song within the linked list will contain a new rating 1-5 defined by the user.                                       *
  ************************************************************************************************************************************************************/
void rate(Node** playlist);

/*************************************************************************************************************************************************************
  * Function:              play()                                                                                                                             *
  * Date Created:          2/11/2022                                                                                                                          *
  * Date Last Modified:    2/11/2022                                                                                                                          *
  * Description:		   "plays" each song in the playlist by displaying each song in the list on the                                                       *
							screen for an amount of time based on each songs' duration.                                                                       *
  * Input parameters:      A doubly linked list containing playlist data.                                                                                     *
  * Returns:               none                                                                                                                               *
  * Preconditions:         the linked list must not be NULL.                                                                                                  *
  * Postconditions:        none                                                                                                                               *
  ************************************************************************************************************************************************************/
void play(Node** playlist);

/*************************************************************************************************************************************************************
  * Function:              shuffle()                                                                                                                         *
  * Date Created:          2/11/2022                                                                                                                         *
  * Date Last Modified:    2/14/2022                                                                                                                         *
  * Description:		   "plays" each song in the list in a randomized order.                                                                              *
  * Input parameters:      A doubly linked list containing playlist data.                                                                                    *
  * Returns:               none                                                                                                                              *
  * Preconditions:         the linked list must not be NULL.                                                                                                 *
  * Postconditions:        none                                                                                                                              *
  ************************************************************************************************************************************************************/
int* shuffle(Node** playlist);



#endif