/* 	
	Author: Erik Zorn - Wallentin 
	Created: May. 05 / 2016
		
	This program was created to polish and improve my C programming skills during my spare time.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
		
	This is Factorial, if you don't know what that is see link:
	https://en.wikipedia.org/wiki/Factorial
		
	The program will convert the user input to a result in factorial.
		
	It starts off by waiting for user input with a menu displayed to the user.
	Menu:
		1) Calculate factorial
		2) Quit the program (q)
	Choosing an option from the menu will allow you to do a specific conversion and ask for more input.
	Once it gives you the result from the conversion it will return you to the menu.
	
	The program has error checking to determine if the input from user was valid or not.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
			float factorialResult = 0;
			float factorialInput = 0;
			/* Variables that are used for error checking to see if input is a number or not */
			char input[100] = "";
			int result = 0;
   
			printf("*** Factorial ***\n");
			printf("Please enter value (example 4): \n");
			scanf ("%s", input);
			
			/* Check if the input is acceptable */
			result = checkIsNumber(input);
			if (result == EXIT_SUCCESS){
				factorialInput = (float)atof(input);

				if (factorialInput < 0) {
					factorialResult = -1;
				} else if (factorialInput == 0) {
					factorialResult = 1;
				} else {
					float result = factorialInput;
						
					while (factorialInput > 2) {
						factorialInput -= 1;
						result *= factorialInput;
					}	
					factorialResult = result;
				}
				printf("Factorial result: %f\n", factorialResult);
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
	printf("\nPlease choose one of the following using (1,2):\n");
	printf("1) Calculate factorial\n");
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