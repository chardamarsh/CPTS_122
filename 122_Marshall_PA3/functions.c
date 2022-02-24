/* Programmer: Charles Marshall
*
Class : CPTS 122; Lab section 13

Programming Assignment : PA 2 & PA 3 : Digital Music Manager and Doubly Linked Lists

Date : 1 - 29 - 2022

Description : This file contains the function definitions to do the following:

Display a menu of commands;
Create a playlist of music as a linked list read from a .csv file;
Edit, insert, sort, and delete each song in the playlist;
Play each song in the playlist, either in order or shuffled.

*/
#include "functions.h"

int mainMenu()
{
	char command[3];
	int i = 0;
	printf(" Please select a command below.\n\n");
	printf("(1)\tLoad\n(2)\tStore\n(3)\tDisplay\n(4)\tInsert\n(5)\tDelete\n(6)\tEdit\n(7)\tSort\n(8)\tRate\n(9)\tPlay\n(10)\tShuffle\n(11)\tExit\n");
	do
	{
		scanf("%2s", &command);
		i = atoi(command);
		if (i < 1 || i > 11)
		{
			printf("\ninvalid selection. Please re-enter.\n");
		}
	} while (i < 1 || i > 11);
	return i;
}

Node* makeNode(infile)
{
	Node* pMem = (Node*)malloc(sizeof(Node));
	char row[1000];
	fgets(row, 1000, infile);
	if (pMem != NULL)
	{
		strcpy(pMem->data.artist, strtok(row, ","));
		if((int)pMem->data.artist[0] == 34) //if the char = 34 (ASCII), then the artist has a first and last name in the entry.
		{
			strcat(pMem->data.artist, ",");
			strcat(pMem->data.artist, strtok(NULL, ","));
		}
		strcpy(pMem->data.album, strtok(NULL, ","));
		strcpy(pMem->data.song, strtok(NULL, ","));
		strcpy(pMem->data.genre, strtok(NULL, ","));
		pMem->data.length.minutes = atoi(strtok(NULL, ":"));
		pMem->data.length.seconds = atoi(strtok(NULL, ","));
		pMem->data.timesPlayed = atoi(strtok(NULL, ","));
		pMem->data.rating = atoi(strtok(NULL, ","));

		if (pMem->data.timesPlayed < 0) //These statements are used to make data from .csv file conform to the minimum and maximum values allowed per the assignment. 
		{
			pMem->data.timesPlayed = 0;
		}
		if (pMem->data.rating < 0)
		{
			pMem->data.rating = 1;
		}
		if (pMem->data.rating > 5)
		{
			pMem->data.rating = 5;
		}

		pMem->prevNode = NULL;
		pMem->nextNode = NULL;
	}
	return pMem;
}


void load(FILE* infile, Node** playlist)
{
	if (*playlist == NULL)
	{
		int i = 0;
		while (!feof(infile))
		{
			Node* pMem = makeNode(infile);
			if (pMem != NULL)
			{
				if (*playlist != NULL)
				{
					(*playlist)->prevNode = pMem;
					pMem->nextNode = *playlist;
				}
				*playlist = pMem;
			}
			++i;
		}
		printf("\n%d songs loaded.\n", i);
		fclose(infile);
	}
	else
	{
		printf("\nPlaylist already loaded.\n");
	}
}

void store(Node** playlist, FILE* outfile)
{
	if (*playlist == NULL)
	{
		printf("Playlist not loaded. Please use the 'Load' command before storing a playlist. ");
	}
	else
	{
		int i = 0;
		Node* pCur = *playlist, * pPrev = NULL;
		while (pCur->nextNode != NULL)
		{
			pPrev = pCur;
			pCur = pCur->nextNode;
		}
		while (pCur != NULL)
		{
			fprintf(outfile, "%s,", pCur->data.artist);
			fprintf(outfile,"%s,", pCur->data.album);
			fprintf(outfile,"%s,", pCur->data.song);
			fprintf(outfile, "%s,", pCur->data.genre);
			fprintf(outfile, "%d:", pCur->data.length.minutes);
			fprintf(outfile, "%d,", pCur->data.length.seconds);
			fprintf(outfile, "%d,", pCur->data.timesPlayed);
			fprintf(outfile, "%d\n", pCur->data.rating);
			pPrev = pCur;
			pCur = pCur->prevNode;
			++i;
		}
		printf("\n%d songs stored to output file.\n", i);
		fclose(outfile);
	}
}

void display(Node** playlist)
{
	char validation[3];
	int option = 0;
	int stopRepeating = 0;//used to ensure input validation error message is only displayed once.
	Node* pCur = *playlist, * pPrev = NULL;
	if (*playlist == NULL)
	{
		printf("Playlist not loaded. Please use the 'Load' command before using the display command.");
		option = 3;
	}
	else
	{	
		while (pCur->nextNode != NULL)
		{
			pPrev = pCur;
			pCur = pCur->nextNode;
		}
	}
	if (option != 3)
	{
		printf("\nDISPLAY OPTIONS:\n(1) Display all songs in current playlist\n(2) Search for specific artist\n(3) Cancel \n");
	}
	do
	{
		scanf("%1s", &validation);
		option = atoi(validation);

		if ((option < 1 || option > 3) && stopRepeating == 0)
		{
			printf("Invalid selection. Please re-enter.\n");
			stopRepeating++;
		}
	}while (option < 1 || option > 3);

	if (option == 1)
	{
		Node* pCur = *playlist, * pPrev = NULL;
		while (pCur->nextNode != NULL)
		{
			pPrev = pCur;
			pCur = pCur->nextNode;
		}
		while (pCur != NULL)
		{
			printf("%s,", pCur->data.artist);
			printf( "%s,", pCur->data.album);
			printf("%s,", pCur->data.song);
			printf("%s,", pCur->data.genre);
			printf("%d:", pCur->data.length.minutes);
			printf("%d,", pCur->data.length.seconds);
			printf("%d,", pCur->data.timesPlayed);
			printf("%d\n", pCur->data.rating);
			pPrev = pCur;
			pCur = pCur->prevNode;
		}
	}
	if (option == 2)
	{
		Node* pCur = *playlist, * pPrev = NULL;
		printf("\nPlease enter an artist name. (Case-Sensitive)\n"); //currently only works for single names, e.g. entering "Garth Brooks" will not return songs by the artist, but "Garth" or "Brooks" will.
		int check = 0;
		while (check == 0)
		{
			while (pCur->nextNode != NULL)
			{
				pPrev = pCur;
				pCur = pCur->nextNode;
			}
			char artist[50];
			char* found;
			scanf("%49s", &artist);
			while (pCur->prevNode != NULL)
			{
				found = strstr(pCur->data.artist, artist);
				if (found != NULL)
				{
					printf("\n%s,", pCur->data.artist);
					printf("%s, ", pCur->data.album);
					printf("%s, ", pCur->data.song);
					printf("%s, ", pCur->data.genre);
					printf("%d:", pCur->data.length.minutes);
					printf("%d, ", pCur->data.length.seconds);
					printf("%d, ", pCur->data.timesPlayed);
					printf("%d\n", pCur->data.rating);
					check = 1;
				}
				pPrev = pCur;
				pCur = pCur->prevNode;
			}
			if (check == 0)
			{
				printf("\nArtist not found, please re-enter.\n");
			}
		}
	}
}

void edit(Node** playlist, int shortcut)
{
	int option = 0;
	char song[50];
	char validation[10]; //used to validate integer input from user.
	int stop = 0; //used to make sure only one invalid input message is displayed.
	//int value = 0;
	char* songFound;
	Node* pCur = *playlist, * pPrev = NULL;
	int check = 0;
	if (*playlist == NULL)
	{
		if (shortcut == 1)
		{
			printf("Playlist not loaded. Please use the 'Load' command before editing a playlist.");
		}
		else
		{
			printf("Playlist not loaded. Please use the 'Load' command before changing a rating.");
		}
		option = 1;
	}
	else
	{
		printf("\nPlease enter an artist name. (Case-Sensitive): "); //currently only works for single names, e.g. entering "Garth Brooks" will not return songs by the artist, but "Garth" or "Brooks" will.
		if (option == 0)
		{
			while (check == 0)
			{
				while (pCur->nextNode != NULL) //sets pCur to the top of the list.
				{
					pPrev = pCur;
					pCur = pCur->nextNode;
				}
				char artist[50];
				char* found;
				scanf("%49s", &artist);
				while (pCur->prevNode != NULL)
				{
					found = strstr(pCur->data.artist, artist); //if the search term matches with a string or substring within the linked list, the artist is found.
					if (found != NULL)
					{
						printf("\n%s,", pCur->data.artist);
						printf("%s, ", pCur->data.album);
						printf("%s, ", pCur->data.song);
						printf("%s, ", pCur->data.genre);
						printf("%d:", pCur->data.length.minutes);
						printf("%d, ", pCur->data.length.seconds);
						printf("%d, ", pCur->data.timesPlayed);
						printf("%d\n", pCur->data.rating);
						check++;
					}
					pPrev = pCur;
					pCur = pCur->prevNode; //traverses to the end of the list.
				}
				if (check == 0)
				{
					printf("\nArtist not found, please re-enter.\n");
				}
				if (check >= 1)
				{
					if (check > 1) //if check > 1 , there is more than one song by the selected artist in the playlist.
					{
						printf("\nPlease enter the name of the song to edit. (Case-Sensitive): ");
					}
					int songcheck = 0;
					while (option != 9 && songcheck == 0)
					{
						if (check > 1 && songcheck == 0) //if true, there are multiple songs.
						{
							scanf("%49s", song);
						}
						while (pCur->nextNode != NULL)
						{
							pPrev = pCur;
							pCur = pCur->nextNode;
						}
						while (pCur->prevNode != NULL && songcheck != 1)
						{
							songFound = strstr(pCur->data.song, song); //check for matching string/substring from search term and playlist.
							if (songFound != NULL || check == 1)
							{
								songcheck = 1;
								printf("\nSong selected: %s by %s\n", pCur->data.song, pCur->data.artist);

								while (option != 9)
								{
									if (shortcut == 1) //used to create a shortcut to implement the "rate" function.
									{
										printf("\nEditing Options:\n(1) Artist\n(2) Album\n(3) Song Name\n(4) Genre\n(5) Minutes\n(6) Seconds\n(7) Times Played\n(8) Rating\n(9) Cancel\n");
										scanf("%d", &option);
									}
									else
									{
										option = 8;
									}
									if (option < 1 || option > 9)
									{
										printf("\nInvalid option selected. Please re-enter. \n");
									}
									if (option == 1)
									{
										printf("\nEnter new artist name: ");
										scanf("%49s", &pCur->data.artist);
									}
									if (option == 2)
									{
										printf("\nEnter new album name: ");
										scanf("%49s", &pCur->data.album);
									}
									if (option == 3)
									{
										printf("\nEnter new song name: ");
										scanf("%49s", &pCur->data.song);
									}
									if (option == 4)
									{
										printf("\nEnter new genre name: ");
										scanf("%49s", &pCur->data.genre);
									}
									if (option == 5)
									{
										printf("\nEnter new minutes value: ");
										stop = 0;
										do
										{
											scanf("%9s", &validation);
											if (((int)validation[0] < 48 || (int)validation[0]> 57)) //if the ASCII value of the first char in the array is not that of a digit, the input is not accepted.
											{
												printf("\ninvalid value, please re-enter. ");
											}
											else
											{
												pCur->data.length.minutes = atoi(validation);
											}

										} while ((int)validation[0] < 48 || (int)validation[0]> 57);
									}
									if (option == 6)
									{
										printf("\nEnter new seconds value: ");
										do
										{
											scanf("%9s", &validation);
											if ((int)validation[0] < 48 || (int)validation[0]> 57)
											{
												printf("\ninvalid value, please re-enter. ");
											}
											else
											{
												pCur->data.length.seconds = atoi(validation);
											}

										} while ((int)validation[0] < 48 || (int)validation[0]> 57);
									}
									if (option == 7)
									{
										printf("\nEnter new times played value: ");
										do
										{
											scanf("%9s", &validation);
											if ((int)validation[0] < 48 || (int)validation[0]> 57)
											{
												printf("\ninvalid value, please re-enter. ");
											}
											else
											{
												pCur->data.timesPlayed = atoi(validation);
											}

										} while ((int)validation[0] < 48 || (int)validation[0]> 57);
									}
									if (option == 8)
									{
										printf("\nEnter new rating: ");
										do
										{
											scanf("%9s", &validation);
											if ((int)validation[0] < 48 || (int)validation[0]> 57)
											{
												printf("\ninvalid value, please re-enter. ");
											}
											else
											{
												pCur->data.rating = atoi(validation);
											}

										} while ((int)validation[0] < 48 || (int)validation[0]> 57);
										if (shortcut != 1)
										{
											option = 9;
										}
									}
								}
							}
							if (option != 9)
							{
								pPrev = pCur;
								pCur = pCur->prevNode;
							}
						}
						if (songcheck == 0)
						{
							printf("\nSong not found. Please re-enter.\n");
						}
					}
				}
			}
		}
	}
}

void insert(Node** playlist)
{
	Node* pHead = NULL;
	Node* pCur = *playlist, * pPrev = NULL;
	char validation[10];
	if (pCur != NULL)
	{
		while (pCur->nextNode != NULL)
		{
			pPrev = pCur;
			pCur = pCur->nextNode;
		}
	}
	*playlist = pCur;
	pHead = (Node*)malloc(sizeof(Node));
	if (pHead != NULL)
	{
		pHead->nextNode = NULL;
		pHead->prevNode = NULL;

		int inputcheck = 0;
		
		char c;
		printf("\nArtist: ");
		//c = getchar();
		//scanf("%49s", pHead->data.artist);
		fgets(pHead->data.artist, 49, stdin);
		pHead->data.artist[strlen(pHead->data.artist) - 1] = '\0';
		c = getchar();
		printf("\nAlbum: ");
		//scanf("%49s", &pHead->data.album);
		fgets(pHead->data.album, 49, stdin);
		pHead->data.album[strlen(pHead->data.album) - 1] = '\0';
		c = getchar();
		printf("\nSong Name: ");
		//scanf("%49s", &pHead->data.song);
		fgets(pHead->data.song, 49, stdin);
		pHead->data.song[strlen(pHead->data.song) - 1] = '\0';
		c = getchar();
		printf("\ngenre: ");
		//scanf("%49s", &pHead->data.genre);
		fgets(pHead->data.genre, 49, stdin);
		pHead->data.genre[strlen(pHead->data.genre) - 1] = '\0';
		c = getchar();
		printf("\nMinutes: ");
		do
		{
			scanf("%9s", &validation);
			if ((int)validation[0] < 48 || (int)validation[0]> 57)
			{
				printf("\ninvalid value, please re-enter. ");
			}
			else
			{
				pHead->data.length.minutes = atoi(validation);
			}

		} while ((int)validation[0] < 48 || (int)validation[0]> 57);
		
		printf("\nSeconds: ");
		do
		{
			scanf("%9s", &validation);
			if ((int)validation[0] < 48 || (int)validation[0]> 57)
			{
				printf("\ninvalid value, please re-enter. ");
			}
			else
			{
				pHead->data.length.seconds = atoi(validation);
			}

		} while ((int)validation[0] < 48 || (int)validation[0]> 57);
		
		printf("\nTimes Played: ");
		do
		{
			scanf("%9s", &validation);
			if ((int)validation[0] < 48 || (int)validation[0]> 57)
			{
				printf("\ninvalid value, please re-enter. ");
			}
			else
			{
				pHead->data.timesPlayed = atoi(validation);
			}

		} while ((int)validation[0] < 48 || (int)validation[0]> 57);

		printf("\nRating: ");
		do
		{
			scanf("%9s", &validation);
			if ((int)validation[0] < 49 || (int)validation[0]> 53)
			{
				printf("\nRating must be 1-5.");
			}
			else
			{
				pHead->data.rating = atoi(validation);
			}

		} while ((int)validation[0] < 49 || (int)validation[0]> 53);

		if (*playlist != NULL)
		{
				(*playlist)->nextNode = pHead;
				pHead->prevNode = *playlist;
		}
		*playlist = pHead;
		printf("\n%s by %s added to playlist.\n", pHead->data.song, pHead->data.artist);
	}
}

void delete(Node** playlist)
{

		Node* pCur = *playlist, * pPrev = NULL;
		char validation[2];
		int option = 0;


		if (*playlist == NULL)
		{
			printf("\nPlaylist is empty. Please use the 'Insert' or 'Load' functions first.\n");
			option = 2;
		}

		while (option == 0)
		{
			printf("\nPlease enter a single word from a song name. (Case-Sensitive)\n");
			while (pCur->nextNode != NULL && option == 0)
			{
				pPrev = pCur;
				pCur = pCur->nextNode;
			}
			char song[50];
			char* found;
			scanf("%49s", song);
			while (pCur->prevNode != NULL && option == 0)
			{

				found = strstr(pCur->data.song, song);
				if (found != NULL)
				{
					printf("\n%s,", pCur->data.artist);
					printf("%s, ", pCur->data.album);
					printf("%s, ", pCur->data.song);
					printf("%s, ", pCur->data.genre);
					printf("%d:", pCur->data.length.minutes);
					printf("%d, ", pCur->data.length.seconds);
					printf("%d, ", pCur->data.timesPlayed);
					printf("%d\n\n", pCur->data.rating);
					printf("\nAre you sure you want to delete %s by %s?\n(1) Yes\n(2) No\n", pCur->data.song, pCur->data.artist);
					do
					{
						scanf("%1s,", &validation);
						if ((int)validation[0] < 49 || (int)validation[0] > 50)
						{
							printf("Invalid input. Please re-enter.");
						}
						else
						{
							option = atoi(validation);
						}
					} while ((int)validation[0] < 49 || (int)validation[0] > 50);
					if (option == 1)
					{
						if (pCur != NULL)
						{
							if (*playlist == pCur)
							{
								*playlist = pCur->nextNode;
							}
							if (pCur->nextNode != NULL)
							{
								pCur->nextNode->prevNode = pCur->prevNode;
							}
							if (pCur->prevNode != NULL)
							{
								pCur->prevNode->nextNode = pCur->nextNode;
							}
							free(pCur);
							printf("\nSong deleted from playlist.\n");
						}
					}
				}
				if (option == 0)
				{
					pPrev = pCur;
					pCur = pCur->prevNode;
				}
			}
			if (option == 0)
			{
				printf("\nSong not found, please re-enter.\n");
			}
		}		
}



void sort(Node** playlist)
{
	
		Node* pCur = NULL, *pNext = NULL, *temp = NULL;
		temp = (Node*)malloc(sizeof(Node));
		char cmd[2];
		int option = 0;
		char c1, c2; //used to bypass quotation marks in the artist category.
		

		if (*playlist == NULL) 
		{
			printf("\nNo playlist found.\n");
		}

		if(*playlist != NULL)
		{
			printf("\nSort Options:\n(1) Artist(A-Z)\n(2) Album Title(A-Z)\n(3) Rating(1-5)\n(4) Times Played(Most-Least)\n");
			do
			{
				scanf("%2s", &cmd);
				option = atoi(cmd);
				if (option < 1 || option > 4)
				{
					printf("\ninvalid selection. Please re-enter.\n");
				}
			} while (option < 1 || option > 4);
			if (option == 1)
			{
				for (pCur = *playlist; pCur->nextNode != NULL; pCur = pCur->nextNode)
				{
					for (pNext = pCur->nextNode; pNext != NULL; pNext = pNext->nextNode)
					{
						c1 = pCur->data.artist[0];
						c2 = pNext->data.artist[0];
						if (c1 == '"')
						{
							c1 = pCur->data.artist[1];
						}
						if (c2 == '"')
						{
							c2 = pNext->data.artist[1];
						}
						if ((int)c1 < (int)c2)
						{
							temp->data = pCur->data;
							pCur->data = pNext->data;
							pNext->data = temp->data;
						}
					}
				}
			}
			if (option == 2)
			{
				for (pCur = *playlist; pCur->nextNode != NULL; pCur = pCur->nextNode)
				{
					for (pNext = pCur->nextNode; pNext != NULL; pNext = pNext->nextNode)
					{
						if (strcmp(pCur->data.album, pNext->data.album) < 0)
						{
							temp->data = pCur->data;
							pCur->data = pNext->data;
							pNext->data = temp->data;
						}
					}
				}
			}
			if (option == 3)
			{
				for (pCur = *playlist; pCur->nextNode != NULL; pCur = pCur->nextNode)
				{
					for (pNext = pCur->nextNode; pNext != NULL; pNext = pNext->nextNode)
					{
						if (pCur->data.rating >  pNext->data.rating)
						{
							temp->data = pCur->data;
							pCur->data = pNext->data;
							pNext->data = temp->data;
						}
					}
				}
			}
			if (option == 4)
			{
				for (pCur = *playlist; pCur->nextNode != NULL; pCur = pCur->nextNode)
				{
					for (pNext = pCur->nextNode; pNext != NULL; pNext = pNext->nextNode)
					{
						if (pCur->data.timesPlayed > pNext->data.timesPlayed)
						{
							temp->data = pCur->data;
							pCur->data = pNext->data;
							pNext->data = temp->data;
						}
					}
				}
			}
			printf("\nPlaylist sorted successfully.\n");
			*playlist = pCur;
		}
		
}

void rate(Node** playlist)
{
	edit(playlist, 0);
}

void play(Node** playlist)
{
	Node* pCur = *playlist, * pPrev = NULL;
	int time = 0, seconds = 0;
	if (*playlist == NULL)
	{
		printf("\nPlaylist is empty. Please use the 'Insert' or 'Load' functions first.\n");
	}
	else
	{
		while (pCur->nextNode != NULL)
		{
			pPrev = pCur;
			pCur = pCur->nextNode;
		}
		while (pCur != NULL)
		{
			printf("\nNow playing: %s by %s\n", pCur->data.song, pCur->data.artist);
			seconds = ((pCur->data.length.minutes * 60) + pCur->data.length.seconds);

			while (time != 30)
			{
				Sleep(seconds);
				printf(".");
				time++;
			}
			time = 0;
			pCur->data.timesPlayed += 1;
			pCur = pCur->prevNode;
			system("cls");
		}
		printf("\nEnd of Playlist\n");
	}
}

int* shuffle(Node** playlist)
{
	Node* pCur = *playlist, *pPrev = NULL;
	int numSongs = 1;
	int time = 0, seconds = 0;
	int i = 0;
	int j = 0;
	int k = 0;

	if (*playlist == NULL)
	{
		printf("\nNo playlist found.\n");
	}
	else
	{
		while (pCur->prevNode != NULL) // return the list to the bottom.
		{
			pPrev = pCur;
			pCur = pCur->prevNode;
		}
		while (pCur->nextNode != NULL) // return the list to the top, and counts the number of songs in the playlist.
		{
			pPrev = pCur;
			pCur = pCur->nextNode;
			numSongs++;
		}
		int* arr = NULL;
		arr = (int)malloc(sizeof(int) * numSongs); //Create an ordered integer array with a cell for each song. e.g. [0,1,2,3,4,5] for 6 songs.
		for (int i = 0; i < numSongs; i++)
		{
			arr[i] = i;
		}
		for (int j = 0; j < numSongs; j++) //Randomize the order of the integer array.
		{
			int temp = arr[j];
			int random = rand() % numSongs;
			arr[j] = arr[random];
			arr[random] = temp;
		}

		while (k < numSongs)
		{
			j = 0;
			while (pCur->nextNode != NULL) // return list to the top.
			{
				pPrev = pCur;
				pCur = pCur->nextNode;
			}
			while (j < arr[k]) //Play the jth song in the playlist based on the random order in the array.
			{
				pCur = pCur->prevNode;
				j++;
			}
			printf("\nNow playing: %s by %s\n", pCur->data.song, pCur->data.artist);
			pCur->data.timesPlayed += 1;
			seconds = ((pCur->data.length.minutes * 60) + pCur->data.length.seconds);

			while (time != 30)
			{
				Sleep(seconds);
				printf(".");
				time++;
			}
			time = 0;
		
			system("cls");
			k++;
		}
		printf("\nEnd of Playlist\n");
		return arr;
	}
}





