//Kaylyn Caselli	NetID: kaylync
//CS135.1001		Project 9

// Display Memory Game Board


void displayBoard (int nrow, int ncol, char symArr[nrow][ncol], _Bool matchedArr)
{
	/* Code to update matched array (put into main function)
	
	_Bool matchedArr[nrow][ncol];	// true = matched -> "flip" ; false = unmatched -> "facedown"	

	if (symArr[rowc1][colc1] == symArr[rowc2][colc2])
	{
		matchedArr[rowc1][colc1] = 1;
		matchedArr[rowc1][colc2] = 1;
	}
	*/

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
	}
			
}
