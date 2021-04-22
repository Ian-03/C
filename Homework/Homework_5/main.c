/*
how to use this program: 
when the program ask you to type a positionyou just need 
to type to letters together, doesnt matter if it's lower or
upper case, examples: aa, Be, CC, ea, etc...
*/

#include<stdio.h>
#include<time.h>
#include<ctype.h>
#include<stdlib.h>
#include"func.h"

int main (){
	
	int c, contpos=0, b, i, j;
	
	char pos[2];
	
	printf ("Type the size of the board (4-26 recommended): ");
	scanf ("%d", &size);
	
	b=size*size;
	
	do{
	printf ("\nNumber of mines (0 - %d): ", b);
	scanf ("%d", &nmines);
	}while (nmines < 0 || nmines > b);
	
	board (nmines);
	
	do{
		printf("\n");
		
		printboard (externalboard);	
			
		printf ("\nType a position: ");		
		scanf ("%s", pos);
		
		pos[0] = toupper(pos[0]), pos[1] = toupper(pos[1]);
		
		if (internalboard[pos[1] - 'A' + 1][pos[0] - 'A' + 1] != 'X'){ 
			
			if (internalboard[pos[1] - 'A' + 1][pos[0] - 'A' + 1] == '0'){ //i couldn't do the recursive reveal but I did this to make it a little easier if it is a 0
				
				for (i = pos[1] - 'A'; i < pos[1] + 3 - 'A'; i++){
					
					for ( j = pos[0] - 'A'; j < pos[0] + 3 - 'A'; j++){
						
						if (isdigit(internalboard[i][j])){   
						
							externalboard[i][j] = internalboard[i][j];
						}
					}
					
				}
			}else externalboard[pos[1] - 'A' + 1][pos[0] - 'A' + 1] = internalboard[pos[1] - 'A' + 1][pos[0] - 'A' + 1];	
			
		}else{
			
			printboard (internalboard);
			
			printf ("\nYOU LOSE :C");
			
			return 0;
		}
		
		if (winner (externalboard)){
			
			printboard (externalboard);
			printf("\nCONGRATULATIONS, YOU WON");
			
			return 0;
		}
		
	}while(1); 
	
	return 0;
}

void board (int nmines){
	
	srand(time(NULL));
	
	int i, j, k, m, cont=0, rand1, rand2;  //fill the matrix 

		for (i = 1; i <= size; i++){
			
		externalboard[i][0] = internalboard[i][0] = i + 'A' - 1;
		
		for (j = 1; j <= size; j++){
			
			externalboard[0][j] = internalboard[0][j] = j + 'A' - 1;
			
			internalboard[i][j] = '0';	
						
			externalboard[i][j] = '#';		
		}
	}
	
	while (nmines != 0){                 //put the random mines
		rand1 = (rand() % (size))+1;
		rand2 = (rand() % (size))+1;
		
		if (internalboard[rand1][rand2] == '0'){
			internalboard[rand1][rand2] = 'X';
			nmines--;
		}
	}
	
	for (i = 1; i <= size; i++){   //check the  number of mines that are in the neighboring boxes.
		
		for (j = 1; j <= size; j++){
			
			if (internalboard[i][j] == '0'){
				
				for (k = i; k < i + 3; k++){		//a mini matrix 3x3 to search for mines 
					
					for (m = j; m < j + 3; m++){
						
						if (internalboard[k-1][m-1] == 'X'){   
							cont++;
						}
					}
				}
				
				internalboard[i][j] = cont + '0';
				
				cont = 0;
			}
		}
	}
}

void printboard (char array[30][30]){
	
	int i, j;
	
	for (i = 0; i <= size; i++){
		
		for (j = 0; j <= size; j++){
		
			printf("%c ", array[i][j]);
		}
		printf("\n");
	}
	
}

int winner (char array[30][30]){
	
	int i, j, cont = 0;
	
	for (i = 0; i <= size; i++){
		
		for (j = 0; j <= size; j++){
		
			if (array[i][j] == '#'){      //if the amount of # and mines are the same that means that it is a win
				cont++;
			}
		}
	}
	
	return (cont == nmines) ? 1 : 0;
}


