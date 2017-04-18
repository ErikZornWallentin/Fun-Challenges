/* 	
	Author: Erik Zorn - Wallentin 
	Created: May. 09 / 2016
		
	This program was created to polish and improve my C programming skills during my spare time.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
		
	This is script is on Abundant and Deficient Number, if you don't know what that is, see below link:
	http://www.positiveintegers.org/IntegerTables/1-100
		
	The program will determine if the given number is abundant, deficient or neither.
	The program also has error checking and will only accept numbers between 1-1000.
	Any other input that is not a number between 1-1000 will throw and error.
		
	It starts off by waiting for user input with a menu displayed to the user.
	Menu:
		1) Abundant and Deficient Numbers
		2) Quit the program (q)
	Choosing an option from the menu will allow you to do a specific task and ask for more input.
	Once it gives you the result from the task it will return you to the menu.
	
	Example Use:
		Consider the number 21. Its divisors are 1, 3, 7 and 21, and their sum is 32. 
		Because 32 is less than 2 x 21, the number 21 is deficient. 
		Its deficiency is 2 x 21 - 32 = 10.
		
		The integer 12 is the first abundant number. Its divisors are 1, 2, 3, 4, 6, and 12, and their sum is 28. 
		Because 28 is greater than 2 x 12, the number 12 is abundant. 
		It's abundant by is 28 - 24 = 4.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function Prototypes */
void menu();
int checkIsNumber(char * input);
int divisors(int x);

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
			int k = 0;
			int divisorsSum = 0;
			/* Variables that are used for error checking to see if input is a number or not */
			char input[100] = "";
			int errorCheck = 0;
   
			printf("*** Abundant and Deficient Numbers ***\n");
			printf("Numbers between 1-1000 only accepted\n");
			printf("Check if number is abundant, deficient, or perfect: \n");
			scanf ("%s", input);
			
			/* Check if the input is acceptable */
			errorCheck = checkIsNumber(input);
			if (errorCheck == EXIT_SUCCESS){
				k = (int)atoi(input);
				/* Check if number is abundant, deficient, or perfect */
				divisorsSum = divisors(k);
				
				if (k <= 0) {
					printf("Make sure value is above 0!\n");
				} else if (k > 1000) {
					printf("Make sure value is 1000 or BELOW!\n");
				} else {
					if (divisorsSum < k*2){
						printf("Deficient\n");
					}else if (divisorsSum > k*2){
						int result = divisorsSum  - (k*2);
						printf("Abundant by %d\n", result);
					}else{
						printf("Neither\n");
					}
				}
			}else{
				printf("Please use numbers between 1-1000!\n");
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
	printf("1) Abundant and Deficient Numbers\n");
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

/*-------
	Purpose: Mods the given number "x" and if the remainder is 0 it will append it to the total sum
	Parameters: x (integer to be checked against )
	Return: sum (returns the sum of the divided numbers that have no remainder)
-------*/
int divisors(int x){
	int sum = 0;
	int i = 0;

	for (i = 1; i <= x; i++){
		if (x % i == 0){
			/* If you can divide the number into the given number, mod will spit out 0 */
			/* We only care about numbers that can divide into the given number */
			/* Any numbers that give remainders we ignore */
			
			/*printf ("ADDING: %d\n", i);*/
			sum += i;
		}
	}

	return sum;
}