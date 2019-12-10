//
//displays names and scores of top ten players
//

#include <stdio.h>

void readScores(char names[21], int saved){

FILE *inScores, *outScore;
char *mode="r";
char readScore[]="scores.txt";

inScores=fopen(inScores, "r");

if (inScores==NULL){
  fprintf(stderr, "Can't open input file scores.txt!\n");
}

outScore=fopen(inScores, "a");

if(outScore==NULL){
  fprintf(stderr, "Can't open input file scoreboard.txt!\n");
}

while(fscanf(inScores, "%s %d", names, &saved)==10){
 fprintf(outScore, "%s %d\n", names, saved);
}

fclose(inScores);
fclose(outScore);

}
