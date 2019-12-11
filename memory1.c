//Kaylyn Caselli	NetID:	kaylync
//Aaron Duigan			aaronduigan

//CS135.1001	Lab Section: 1102	Project 9

// Allow users to play game of memory of various difficulties and save their scores

// *** Group combined code / Edited by Kaylyn ***


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define SCORES 10
#define m 100

int getMenuChoice();
void randomizedBoard (int size, int arr[]);
void assignSpots( int size, int value[36], int symbol[36], int board[6][6]);
int playGame (int diff_size, int symbols[diff_size][diff_size]); //
void displayBoard(int diff_size, int symArr[diff_size][diff_size], _Bool matchedArr[diff_size][diff_size]);//
void saveScore(int newScore);
void writeScores(int numScores, int *scores[], char *names[]);
_Bool checkMatch(int diff_size, int symArr[diff_size][diff_size], int r1, int c1, int r2, int c2);//
void getUserInput (int *row, int *col, int diff_size);
int readScores(int scores[], char names[]);//

int main()
{
	int difficultylevel, difficulty, root,choice, value[36], board[6][6], xy[73], match = 0, score=0, save_choice;
	int r1, c1, r2, c2;
	int scores[SCORES];
	char names[SCORES];
		

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
			case 1: //Play Game
				printf ("Enter Difficulty (1, 2, or 3): \n");
				scanf ("%d", &difficultylevel);
				difficulty = difficultylevel * 2;
				
				randomizedBoard(difficulty,value);
				assignSpots(difficulty, value, symbol, board);
				
				score = playGame (difficulty, board);//
				
				printf("Save score?\n1- yes "); 		// Edit display to executable
				scanf("%d", &save_choice);//
				switch (save_choice)
				{
					case 1: saveScore(score);
						break;
				}
				
				break;
			case 2: // Display Scoreboard
				readScores(scores, names);//
				for (int i=0; i<difficulty; i++)
				{
					printf("%c %d\n", names[i], scores[i]);//
				}
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

int playGame (int diff_size, int symbols[diff_size][diff_size])//
{
	_Bool matchedArr[diff_size][diff_size];	// true = matched -> "flip" ; false = unmatched -> "facedown"
	int numMatches = 0;
	int scorecount = 0;
	int r1, c1, r2, c2;
	
	for (int ri=0; ri<diff_size; ri++)
	{
		for (int ci=0; ci<diff_size; ci++)
		{
			matchedArr[ri][ci] = 0;		// preset each element to false (unmatched)
		}
	}
	
	do 
	{
		displayBoard(diff_size, symbols, matchedArr);
		scorecount++;
		getUserInput(&r1, &c1, diff_size);
		getUserInput(&r2, &c2, diff_size);
		if (checkMatch(diff_size, symbols, r1, c1, r2, c2) == 1)
		{
			matchedArr[r1][c1] = 1;
			matchedArr[r2][c2] = 1;
			numMatches++;
			scorecount++;
		}
	displayBoard(diff_size, symbols, matchedArr);
	printf ("You won dude!");	// Edit display to executable
		
	return scorecount;
		
	} while (numMatches != (diff_size*diff_size)/2);	// Until Game is Won
	
	displayBoard(diff_size, symbols, matchedArr);
	
	
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


_Bool checkMatch(int diff_size, int symArr[diff_size][diff_size], int r1, int c1, int r2, int c2)
{
	if (symArr[r1][c1] == symArr[r2][c2])
	{
		return 1;
	}
	return 0;
}
void getUserInput (int *row, int *col, int diff_size)
{
	printf("Enter your coordinates from 1 to %d\n", diff_size);
	scanf("%d %d", row, col);
	printf("Enter your coordinates from 1 to %d\n", diff_size);
	scanf("%d %d", row, col);
}
	
void displayBoard(int diff_size, int symArr[diff_size][diff_size], _Bool matchedArr[diff_size][diff_size])//
{
	for (int ri=0; ri<diff_size; ri++)
	{
		for (int ci=0; ci<diff_size; ci++)
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



// Score Handling
void saveScore(int newScore)
{
	int scores[SCORES];
	char names[SCORES];
	char newName;
	int tempscore;
	char tempname;	
	int numScores;
	
	numScores = readScores(scores, names);

	printf("Enter name: ");			// Edit display to executible
	scanf("%s", &newName);

	for (int i=0; i<numScores; i++)
	{
		if (newScore > scores[i])
		{
			tempscore = scores[i];
			scores[i] = newScore;
			newScore = tempscore;
			
			strcpy(tempname, names[i]);
			strcpy(names[i], newName);
			strcpy(newName, tempname);
		}
		else if (i = numScores-1)
		{
			scores[i] = newScore;
		}
		
		if (numScores < SCORES)
		{
			numScores++;
		}
	}
	
	writeScores(numScores, &scores, &names);
	
}


int readScores(int scores[], char names[])
{
	FILE* scores_fp;	
	int arrIndex=0;
	int count=0;
	char filename[] = "scores.txt";

	if ((scores_fp = fopen(filename, "r")) == NULL)//
	{
		fprintf(stderr, "Can't open scores.txt\n");
		return 1;
	}
	
	while ((scores_fp = fopen(filename, "r")) == 1)//
	{		
		fscanf(scores_fp, "%c %d", &names[arrIndex], &count);//
		count++;
		arrIndex++;
	}
	
	fclose (scores_fp);

	return count;
}


void writeScores(int numScores, int *scores[], char *names[])
{
	FILE* scores_fp;	
	char filename[] = "scores.txt";	

	if ((scores_fp = fopen(filename, "w")) == 1)//
	{
		for (int i=0; i<numScores; i++)
		{
			fprintf(scores_fp, "%c %d\n", names[i], scores[i]);//
		}
	}
	fclose (scores_fp);
}
