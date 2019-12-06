//Kaylyn Caselli	NetID: kaylync
//CS135.1001		Project 9

// Update a Scoreboard

// #define NUM 10	//number of scores listed in scoreboard

void updateScores (int argc, char* argv[], char newName[], int newScore)
{
	FILE* fp1;
	char ch1;
	int num;
	
	int scores[NUM];
	char names[][len];	

	if (argc != 3)
	{
		fprintf (stderr, "Usage: %s input\n", argv[0]);
		return 1;
	}

	if (( fp1 = fopen (argv[1], "w")) == NULL)
	{
		fprintf (stderr, "Can not open %s\n%s input.txt\n", argv[1], argv[0]);
		return 1;
	}
	

	
	for (int i=0; 


	getScores (NUM, scores);
	sortScores (NUM, SIZE, scores, names);
	addNewScore (NUM, newName, scores);


void getScores(int num, int scores[])
{
	for (int i=0; i<num; i++)
	{
		fscanf(fp1, "%s %d", &names[i], &scores[i]);
	}
}
	

void sortScores(int num, int len, int scores[], char names[][len])
{
	int tempscore;
	char tempname[len];
	_Bool swap = 0;
	
	do
	{
		swap = 0;
		for (int i = 0; i<=num-i; i++)
		{
			if (scores[i+1] > scores[i])
			{
				tempscore = scores[i+1];
				tempname = names[i+1];
				scores[i+1] = scores[i];
				names[i+1] = names[i];
				scores[i] = tempscore;
				names[i] = tempname;
				swap = 1;
			}
			
		}
	} while (swap != 0);
}

void addnewScore (int num, int newScore, char newName, int scores[])
{
	_Bool placed = 0;

	if (newScore < scores[num-1])
	{
		scores[num-1] = newScore;
	}
	else 
	{
		for (int i=0; i<num && placed!=1; i++)
		{
			if (newScore > scores[i])
			{
				scores[i] = newScore;
				placed = 1;
			}
		}
	}
}
				
// C Board Saving Scoreboard in .txt file
