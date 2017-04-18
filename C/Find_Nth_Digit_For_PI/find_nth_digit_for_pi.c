/* 	
	Author: Erik Zorn - Wallentin 
	Created: May. 05 / 2016
		
	This program was created to polish and improve my C programming skills during my spare time.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
		
	This script uses Bailey-Borwein-Plouffe Formula (BBP Formula) to calculate PI to the nth digit.
		
	If you don't know the BBP formula see this wiki link:
	https://en.wikipedia.org/wiki/Bailey%E2%80%93Borwein%E2%80%93Plouffe_formula
		
	The program will convert the user input to a result in PI at nth digit.
		
	It starts off by waiting for user input with a menu displayed to the user.
	Menu:
		1) Calculate PI to nth digit *max 10 digits*
		2) Quit the program (q)
	Choosing an option from the menu will allow you to do a specific conversion and ask for more input.
	Once it gives you the result from the conversion it will return you to the menu.
	
	The program has error checking to determine if the input from user was valid or not.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/* Function Prototypes */
void menu();
int checkIsNumber(char * input);

int main(){
	char userInput = '0';		  /* The main menu user input variable */
	int checker = 1;			  /* Checks if user wants to quit or not from main menu */
	
	/* Call the main menu function to display the main menu */
	menu();
	
	do{
		userInput = getchar(); 
		
		if (userInput == '1'){
			system("clear");
			
			/* Variables we will use our formula on */
			float pi = 0;
			int k = 0;
			int i = 0;
			/* Variables that are used for error checking to see if input is a number or not */
			char input[100] = "";
			int result = 0;
   
			printf("*** The BBP Formula to Calculate PI ***\n");
			printf("Please enter digit to calculate to (nth): \n");
			scanf ("%s", input);
			
			/* Check if the input is acceptable */
			result = checkIsNumber(input);
			if (result == EXIT_SUCCESS){
				k = (int)atoi(input);
				
				if (k <= 0){
					printf("Error - Please give a number greater than 0!\n");
				}else if (k > 10){
					printf("Error - Please give a number less than 10!\n");
				}else{
					/* BBP formula, using integral SUM and base 16 for PI */
					for (i = 0; i < k; i++){
						pi += ( 1.0 / pow( 16, i ) ) * ( (4.0 / (8.0 * i + 1.0)) -
																  (2.0 / (8.0 * i + 4.0)) -
																  (1.0 / (8.0 * i + 5.0)) -
																  (1.0 / (8.0 * i + 6.0)) );
					}
					/* Set the output to only show the nth digit by using k variable */
					printf("PI result at nth digit: %.*f\n", k, pi);
				}
			}

			menu();
			/* Clear buffer */
			while (getchar() != '\n');
		}else if (userInput == '2' || userInput == 'q'){
			printf("Now quitting the program!\n");	
			checker = 0;	
		}else{
			system("clear");
			printf("Incorrect input, try again!\n");
			menu();
			
			/* Clear buffer */
			while (getchar() != '\n');
		}
	}while(checker == 1);			
	
	return 0;
}

/*-------
	Purpose: The main menu that is displayed to the user
	Parameters: NONE
	Return: NONE
-------*/
void menu(){
	printf("\nThe BBP Formula to Calculate PI\n");
	printf("Please choose one of the following using (1,2):\n");
	printf("1) Calculate PI to nth digit *max 10 digits*\n");
	printf("2) Quit the program (q)\n");  
}

/*-------
	Purpose: Checks if the input is only numbers, and gives a correct return value ( success or failure ) depending on the result
	Parameters: input ( char array input to be checked if it's only numbers )
	Return: result (EXIT_SUCESS is 0 or EXIT_FAILURE is 1 or higher)
-------*/
int checkIsNumber(char * input){
    int length = 0;
	int i = 0;
	
    length = strlen (input);
	
    for (i = 0; i < length; i++){
		if (!isdigit((int)input[i])){
            printf ("Entered input is incorrect!\n");
            return EXIT_FAILURE;
        }
	}
	
	return EXIT_SUCCESS;
}