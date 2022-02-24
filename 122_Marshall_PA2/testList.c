#include "testList.h"

void testInsert(void)
{
	//Since the insert function relies on user input, the test point must be manually entered by the user.
	// The insert() function itself checks for valid data.
	//“Perry, Katy”, album title = “Witness”, song title = “Chained to the Rhythm”, genre = “pop”, song length = “4:36”, times played = -1, rating = 6.
	Node* playlist = NULL;
	insert(&playlist);
	if (playlist != NULL)
	{
		printf("\nPlaylist successfully updated.");
	}
	else
	{
		printf("\nSong not added.");
	}
}

void testDelete(void)
{
	Node* pMem = (Node*)malloc(sizeof(Node));

	strcpy(pMem->data.artist, "Perry, Katy");
	strcpy(pMem->data.album, "Witness");
	strcpy(pMem->data.song, "Chained to the Rythym");
	strcpy(pMem->data.genre, "pop");
	pMem->data.length.minutes = 4;
	pMem->data.length.seconds = 36;
	pMem->data.timesPlayed = 3;
	pMem->data.rating = 5;

	delete(&pMem);
	if (pMem == NULL)
	{
		printf("\nSong deleted successfully.");
	}
	else
	{
		printf("Memory not deallocated.");
	}
}

void testShuffle(void)
{
	FILE* infile;
	infile = fopen("musicPlayList1.csv", "r");
	int* order;
	Node* pList = NULL;
	for (int i = 0; i < 3; i++)
	{
		pList = makeNode(infile);
		if (i != 2)
		{
			pList = pList->nextNode;
		}
	}
	fclose(infile);
	if (pList != NULL)
	{
		order = shuffle(&pList);
		if (order[0] == 3 && order[1] == 1 && order[2] == 2) // desired order is 3,1,2 per assignment guidlelines.
		{
			printf("\nOrder is 3, 1, 2.\n");
		}
		else
		{
			printf("\nOrder is not 3, 1, 2.\n");
		}
	}
	
}