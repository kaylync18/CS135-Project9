//
//
//

#include <stdio.h>
#ifndef scoreboard.c

#include <scoreboard.c>

int displayScores(int argc, char* argv[])
{
 
 int display;
 FILE *outScore;

  if (argc!=2){
	printf("Usage: ./scoreboard.c inScore outScore\n");
	return 0;
	}
  if ((outScore=fopen(argv[1], "r"))==NULL){
	printf("Can't open %s.\n",argv[1]);
	return 0;
	}
  while(fscanf(outScore, "%d", &display)==1){
	printf("%d", display);
	}

  fclose(outScore);
  return 0;

}
