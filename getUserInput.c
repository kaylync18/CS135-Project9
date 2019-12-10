//
//gets coordinates input by the user to flip designated cards in an array.
//

#include <stdio.h>

_Bool(int row, int col, int coord[][], int SIZE, int match){

getDifficulty=SIZE;
checkMatch=match;

switch(SIZE){

case 1:
do{
printf("Enter your coordinates from 1 to 2\n");
scanf("%d %d", &row, &col);
printf("Enter your coordinates from 1 to 2\n");
scanf("%d %d", &row, &col);
}while(match!=1);
break;

case 2:
do{
printf("Enter your coordinates from 1 to 4\n");
scanf("%d %d", &row, &col);
printf("Enter your coordinates from 1 to 4\n");
scanf("%d %d", &row, &col);
}while(match!=1);
break;

case 3:
do{
printf("Enter your coordinates from 1 to 6\n");
scanf("%d %d", &row, &col);
printf("Enter your coordinates from 1 to 6\n");
scanf("%d %d", &row, &col);
}while(match!=1);
return 0;
break;
}

return 1;
}
