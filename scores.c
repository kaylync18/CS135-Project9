//Kaylyn Caselli		NetID: kaylync
//CS135 Lab Section 1102	Project 9

//Update game Scoreboard

#include <stdio.h>
#include <string.h>

#define NUM 10
#define LENGTH 20

void saveScore(int newScore);
int readScores(int *scores[], char *names[]);
void writeScores(int numScores, int *scores[], char *names[]);

int main()
{

	int newScore;

	saveScore(newScore);

	return 0;
}


void saveScore(int newScore)
{
	int scores[NUM];
	char names[NUM];
	char newName;
	int tempscore;
	char tempname;	
	int numScores;
	
	numScores = readScores(&scores, &names);

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
		
		if (numScores < NUM)
		{
			numScores++;
		}
	}
	
	writeScores(numScores, scores, names);
	
}


int readScores(int *scores[], char *names[])
{
	FILE* scores_fp;	
	int arrIndex=0;
	int count=0;
	char filename[] = "scores.txt";

	if (scores_fp = fopen(filename, "r") == NULL)
	{
		fprintf(stderr, "Can't open scores.txt\n");
		return 1;
	}
	
	while (scores_fp = fopen(filename, "r") == 1)
	{		
		fscanf(scores_fp, "%s %d", &names[arrIndex]);
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

	if (scores_fp = fopen(filename, "w") == 1)
	{
		for (int i=0; i<numScores; i++)
		{
			fprintf(scores_fp, "%s %d\n", names[i], scores[i]);
		}
	}
	fclose (scores_fp);
}


