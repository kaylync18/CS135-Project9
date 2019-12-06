// aaronduigan

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define n 100
#define m 100
void randomizedBoard (int size);
void getMenuChoice();
int main()
{
	
	getMenuChoice();
}

void getMenuChoice()
{
	int difficulty, choice;
	_Bool flag = 1;
	while (flag == 1)
	{
		printf ("***MEMORY!***\n");
		printf ("1 - Play Game\n2 - Check Scores\n0 - EXIT\n");
		scanf ("%d", &choice);
		switch (choice)
		{
			case 1: printf ("Enter Difficulty (1, 2, or 3): ");
				scanf ("%d", &difficulty);
				difficulty = difficulty * 2;
				randomizedBoard(difficulty);
				break;
			case 2: //
				break;
			case 0: flag = 0;
				break;
		}
	}
}

void randomizedBoard(int size)
{
	int symbols[n] = {33, 34, 35, 36 ,37 ,38 , 39, 40, 41, 42, 43 , 45, 46, 47,48, 49,50, 51, 52 ,53, 54 ,55, 56,57, 58, 59, 60, 61, 62,63, 33, 34, 35, 36 ,37 ,38 , 39, 40, 41, 42, 43 , 45, 46, 47,48, 49,50, 51, 52 ,53, 54 ,55, 56,57, 58, 59, 60, 61, 62,63};

	printf ("\n");
	srand((unsigned)time(NULL));
	//int coordinates[n][m];
	int end = 0;
	for (int x = 0; x < size; x++) // ignore this part cause I'm still trying to figure out how to randomized the card and print it.
		{
			for (int y = 0; y < size; y++)
				{
					symbols[n] = rand() % 62;
					printf ("[%c] ",symbols[n]); //Randmomize stuff but not working the way I want it.
				
				}
			printf("\n");
		}
}





