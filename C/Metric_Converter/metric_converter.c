/* 	
	Author: Erik Zorn - Wallentin 
	Created: May. 05 / 2016
		
	This program was created to polish and improve my Python programming skills during my spare time.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
		
	The script is on Metric Conversion, if you don't know what that is, see below link:
	www.metric-conversions.org/length/kilometers-to-meters.htm
		
	The program will calculate Kilometre to Metre, and Metre to Kilometre.
		
	It starts off by waiting for user input with a menu displayed to the user.
	Menu:
		1) Kilometre to Metre (km to m)
		2) Metre to Kilometre (m to km)
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
			float metresConverted = 0;
			float kilometresInput = 0;
			/* Variables that are used for error checking to see if input is a number or not */
			char input[100] = "";
			int result = 0;
   
			printf("*** Converting Kilometre to Metre (km to m) ***\n");
			printf("Please enter Kilometre value: \n");
			scanf ("%s", input);
			
			/* Check if the input is acceptable */
			result = checkIsNumber(input);
			if (result == EXIT_SUCCESS){
				kilometresInput = (float)atof(input);

				/* Convert from Kilometre to Metre */
				metresConverted = kilometresInput / 0.001;
				printf("Metre result: %.5f\n", metresConverted);
			}

			menu();
			/* Clear buffer */
			while (getchar() != '\n');
		}else if (userInput == '2'){
			system("clear");
			
			/* Variables we will use our formula on */
			float kilometresConverted = 0;
			float metresInput = 0;
			/* Variables that are used for error checking to see if input is a number or not */
			char input[100] = "";
			int result = 0;
   
			printf("*** Metre to Kilometre (m to km) ***\n");
			printf("Please enter Metre value: \n");
			scanf ("%s", input);
			
			/* Check if the input is acceptable */
			result = checkIsNumber(input);
			if (result == EXIT_SUCCESS){
				metresInput = (float)atof(input);

				/* Convert from Metre to Kilometre */
				kilometresConverted = metresInput * 0.001;
				printf("Kilometre result: %.5f\n", kilometresConverted);
				
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
	printf("1) Kilometre to Metre (km to m)\n");
	printf("2) Metre to Kilometre (m to km)\n");
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