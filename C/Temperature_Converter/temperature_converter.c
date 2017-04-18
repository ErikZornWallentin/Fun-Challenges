/* 	
	Author: Erik Zorn - Wallentin 
	Created: May. 05 / 2016
		
	This program was created to polish and improve my C programming skills during my spare time.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
		
	The script is on Temperature Conversion, if you don't know what that is, see both links:
	http://www.rapidtables.com/convert/temperature/how-celsius-to-fahrenheit.htm
	http://www.metric-conversions.org/temperature/fahrenheit-to-celsius.htm
		
	The program will calculate Fahrenheit to Celsius, and Celsius to Fahrenheit.
		
	It starts off by waiting for user input with a menu displayed to the user.
	Menu:
		1) Fahrenheit to Celsius (F to C)
		2) Celsius to Fahrenheit (C to F)
		3) Quit the program (q)
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
			float celsiusConverted = 0;
			float fahrenheitInput = 0;
			/* Variables that are used for error checking to see if input is a number or not */
			char input[100] = "";
			int result = 0;
   
			printf("*** Converting Fahrenheit to Celsius (F to C) ***\n");
			printf("Please enter Fahrenheit value: \n");
			scanf ("%s", input);
			
			/* Check if the input is acceptable */
			result = checkIsNumber(input);
			if (result == EXIT_SUCCESS){
				fahrenheitInput = (float)atof(input);

				/* Convert from Fahrenheit to Celsius */
				celsiusConverted = ( fahrenheitInput - 32 ) / 1.8;
				printf("Celsius result: %f\n", celsiusConverted);
			}

			menu();
			/* Clear buffer */
			while (getchar() != '\n');
		}else if (userInput == '2'){
			system("clear");
			
			/* Variables we will use our formula on */
			float fahrenheitConverted = 0;
			float celsiusInput = 0;
			/* Variables that are used for error checking to see if input is a number or not */
			char input[100] = "";
			int result = 0;
   
			printf("*** Converting Celsius to Fahrenheit (C to F) ***\n");
			printf("Please enter Celsius value: \n");
			scanf ("%s", input);
			
			/* Check if the input is acceptable */
			result = checkIsNumber(input);
			if (result == EXIT_SUCCESS){
				celsiusInput = (float)atof(input);

				/* Convert from Celsius to Fahrenheit */
				fahrenheitConverted = ( celsiusInput * 1.8 ) + 32;
				printf("Fahrenheit result: %f\n", fahrenheitConverted);
				
			}
			
			menu();
			/* Clear buffer */
			while (getchar() != '\n');
		}else if (userInput == '3' || userInput == 'q'){
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
	printf("\nPlease choose one of the following using (1,2,3):\n");
	printf("1) Fahrenheit to Celsius (F to C)\n");
	printf("2) Celsius to Fahrenheit (C to F)\n");
	printf("3) Quit the program (q)\n");  
}

/*-------
	Purpose: Checks if the input is only numbers and periods, and gives a correct return value (success or failure) depending on the result
	Parameters: input (char array input to be checked if it's only numbers and periods)
	Return: result (EXIT_SUCESS is 0 or EXIT_FAILURE is 1 or higher)
-------*/
int checkIsNumber(char * input){
    int length = 0;
	int i = 0;
	int periodCounter = 0;
	
    length = strlen (input);
	
    for (i = 0; i < length; i++){
		if (input[i] == '-' && i == 0){
			/* Accept input when we have a negative number (only allow negative sign as first character) */
		}else if (input[i] == '.'){
			/* Count when we see a '.' because we will allow float numbers as an acceptable input, but not multiple periods */
			periodCounter++;
			if (periodCounter > 1){
				printf ("Entered input is not a number!\n");
				return EXIT_FAILURE;
			}
		}else if (!isdigit((int)input[i])){
            printf ("Entered input is not a number!\n");
            return EXIT_FAILURE;
        }
	}
	
	return EXIT_SUCCESS;
}