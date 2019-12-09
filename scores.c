//Kaylyn Caselli		NetID: kaylync
//CS135 Lab Section 1102	Project 9

//Update game Scoreboard

#include <stdio.h>
#include <string.h>

#define NUM 10
#define LENGTH 20

void saveScore(int newScore);
int readScores(int scores[], char names[]);
void writeScores(int numScores, int scores[], char names[]);

int main()
{

	int newScore;

	saveScore(int newScore);

	return 0;
}


void saveScore(int newScore)
{
	int scores[];
	char names[];
	int newName;
	int tempscore;
	char tempname;	
	int numScores;
	
	numScores = readScores(scores[], names[]);

	printf("Enter name: ");			// Edit display to executible
	scanf("%s", &newName);

	for (int i=0; i<numScores; i++)
	{
		if (newScore > scores[i])
		{
			tempscore = scores[i];
			scores[i] = newScore;
			newScore = tempscore;
			
			strcpy(tempname, list[i]);
			strcpy(list[i], newName);
			strcpy(newName, tempname);
		}
		else if (i = numScores-1)
		{
			scores[i] = newScore;
		}
		
		if (numScores < NUM)
		{
			numScores++;
		}
	}
	
	writeScores(numScores, scores[], names[]);
	
}


int readScores(int scores[], char names[])
{
	FILE* scores_fp;	
	int arrIndex=0;
	int count=0;

	scores_fp = fopen(scores.txt, "r");	
	
	if (scores_fp == NULL)
	{
		fprintf(stderr, "Can't open scores.txt);
		return 1;
	}
	
	while (scores_fp == 1)
	{		
		fscanf(scores.txt, "%s %d", &names[arrIndex];
		count++;
		arrIndex++;
	}
	
	fclose (scores.txt);

	return count;
}


void writeScores(int numScores, int scores[], char names[])
{
	FILE* scores_fp;	

	scores_fp = fopen(scores.txt, "w");
	
	if (scores_fp == 1)
	{
		for (int i=0; i<numScores; i++)
		{
			fprintf(scores.txt, "%s %d\n", names[i], scores[i]);
		}
	
	fclose (scores.txt);
}


