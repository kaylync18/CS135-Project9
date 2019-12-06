//
//obtains coordinates for selecting cards
//

_Bool(int *row, int *col, int coord[][], int difficulty, int result){

  getDifficulty(difficulty);
  displayBoard()

  
 do{
  switch(difficulty){
  
  case 1:
  
  printf("Enter coordinates from 1 to 2.\n");
  scanf("%d %d", row, col);

  printf("Enter coordinates from 1 to 2.\n");
  scanf("%d %d", row, col);
  
  gameWon(result);
  break;

  case 2:
  printf("Enter coordinates from 1 to 4.\n");
  scanf("%d %d", row, col);
  
  printf("Enter coordinates from 1 to 4.\n");
  scanf("%d %d", row, col);

  gameWon(result);
  break;
  
  case 3:
  printf("Enter coordinates from 1 to 6.\n");
  scanf("%d %d", row, col);

  printf("Enter coordinates from 1 to 4.\n");
  scanf("%d %d", row, col);

  gameWon(result);
  break;
  }
 }while(result!=1)
}

