// Aaron's code / Edited by Kaylyn & Aaron

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define n 100
#define m 100

int getMenuChoice();
void randomizedBoard (int size, int arr[]);
void assignSpots( int size, int value[36], int symbol[36], int board[6][6]);
//void generateBoard(int size);
//void checkMatch(int size, int board[6][6],int xy[4],int match);
_Bool checkMatch(char symArr[], int r1, int c1, int r2, int c2);
void getUserInput (int *row, int *col, int diff_size);

int main()
{
	int difficultylevel, difficulty, root,choice, value[36], board[6][6], xy[73], match = 0;
	
	int symbol[36] = { 
	33, 33, 34, 34,
	35, 35, 36, 36,
	37, 37, 38, 38, 
	42, 42, 43, 43,
	47, 47, 60, 60,
	61, 61, 62, 62,
	63, 63, 64 ,64,
	40, 40, 41, 41,
	46, 46, 45, 45
	}; //Symbols
	

	_Bool flag = 1;
	while (flag == 1)
	{
		switch (choice= getMenuChoice())
		{
			case 1: printf ("Enter Difficulty (1, 2, or 3): \n");
				scanf ("%d", &difficultylevel);
				difficulty = difficultylevel * 2;
				randomizedBoard(difficulty,value);
				assignSpots(difficulty, value, symbol, board);
				playGame (difficulty, board);
				break;
			case 2: //
				break;
			case 0: flag = 0;
				break;
		}
	}
		return 0;
}

int getMenuChoice()
{
	int choice;
	
		printf ("***MEMORY!***\n");
		printf ("1 - Play Game\n2 - Check Scores\n0 - EXIT\n");
		scanf ("%d", &choice);
		return choice;
		
}

void playGame (int diff_size, char symbols[diff_size][diff_size])
{
	_Bool matchedArr[nrow][ncol];	// true = matched -> "flip" ; false = unmatched -> "facedown"
	int numMatches = 0;
	
	for (int ri=0; ri<diff_size; ri++)
	{
		for (int ci=0; ci<diff_size; ci++)
		{
			matchedArr[ri][ci] = 0;		// preset each element to false (unmatched)
		}
	}
	
	do 
	{
		displayBoard(difficulty, value, matchedArr);
		getUserInput(&row, &col, diff_size);
		getUserInput(&row, &col, diff_size);
		if (checkMatch(symbols, r1, c1, r2, c2) == 1)
		{
			matchedArr[rowc1][colc1] = 1;
			matchedArr[rowc2][colc2] = 1;
			numMatches++;
		}
		displayBoard(difficulty, value, matchedArr);
	} while (numMatches != (difficulty*difficulty)/2);
	
}

void randomizedBoard(int size, int arr[])
{
	int temp, random;
	for (int i = 0; i < size * size; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < size*size; i++)
	{
		temp = arr[i];
		random = rand() % (size*size);

		arr[i] = arr[random];
		arr[random] = temp;
	} // This will randomize the selected symbols in the array.
}

void assignSpots(int size, int value[36], int symbol[36], int board[6][6])
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			{
				board[i][j] = symbol[value[count]];
				count++;
			}
	}
}


_Bool checkMatch(char symArr[], int r1, int c1, int r2, int c2)
{
	if (symArr[rowc1][colc1] == symArr[rowc2][colc2])
	{
		return 1;
	}
	return 0;
}

void getUserInput (int *row, int *col, int diff_size)
{
	printf("Enter your coordinates from 1 to %d\n", diff_size);
	scanf("%d %d", &row, &col);
	printf("Enter your coordinates from 1 to %d\n", diff_size);
	scanf("%d %d", &row, &col);
}
	
void displayBoard (int diff_size, char symArr[diff_size][diff_size], _Bool matchedArr)
{
	for (int ri=0; ri<nrow; ri++)
	{
		for (int ci=0; ci<numc; ci++)
		{
			if (matchedArr[ri][ci] == 0)
			{
				printf("[ ] ");
			}
			else if (matchedArr[ri][ci] == 1)
			{
				printf("[%c] ", symArr[ri][ci]);
			}
		}
		printf("\n");
	}			
}

/*void generateBoard(int size)
{
	for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				{
					printf ("[]");
				}
			printf ("\n");
		}
}
*/
/*void checkMatch(int size, int board[size][size],int xy[4], int match)
{
	int r1,c1,r2,c2, count = 0;

	_Bool flag = 1;
	do 
	{
	printf ("Enter your coordinates from 1 to %d\n", size);
	scanf ("%d %d", &r1,&c1);
		if (r1 < 0|| r1 > size|| c1 < 0 || c1 > size)
		{
			printf ("Please enter a valid coordinates\n");
		}
		else
		{
			flag = 0;
		}
	}while(flag);

	flag = 1;
	do 
	{
	printf ("Enter your coordinates from 1 to %d\n", size);
	scanf ("%d %d", &r2,&c2);
	if (r2< 0|| r2 > size|| c2 < 0 || c2 > size)
	{
		printf ("Please enter a valid coordinates\n");
	}
	else
	{
		flag = 0;
	}
	}while(flag);

	for (int i = 0; i < size; i++)
		{
			int matches = size*size / 2;
			for (int j = 0; j < size; j++)
				{
					if (((r1-1) == i && (c1-1) == j) || ((r2-1) == i && (c2-1) == j)) 
						{
							printf ("[%c]", board[i][j]);
						}
					else
						{
							printf ("[]");
						}
				}
			printf ("\n");
		}
	if (board[r1-1][c1-1] == board[r2-1][c2-1])
		{
			printf ("MATCHED!\n");
			count++;
			xy[0] = count;
			xy[1] = r1;
			xy[2] = c1;
			xy[3] = r2;
			xy[4] = c2;
			match++;
		}
	else
		{
			printf ("TRY AGAIN!\n");
		}
	
}
*/
