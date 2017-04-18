/* 	
	Author: Erik Zorn - Wallentin 
	Created: May. 06 / 2016
		
	This program was created to polish and improve my C programming skills during my spare time.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
		
	This script is on Atbash Cipher, if you don't know what that is, see below link:
	https://en.wikipedia.org/wiki/Atbash
	
	The program will use atbash cipher to convert English to Atbash or Atbash to English.
		
	Atbash is a simple substitution cipher originally for the Hebrew alphabet, but possible with any known alphabet. 
	It emerged around 500-600 BCE. 
	It works by substituting the first letter of an alphabet for the last letter, the second letter for the second to last and so on, effectively reversing the alphabet. 
	Here is the Atbash substitution table:
	Plain:  abcdefghijklmnopqrstuvwxyz
	Cipher: zyxwvutsrqponmlkjihgfedcba
		
	Example Use of Atbash Cipher:
		foobar                                       ---> ullyzi
		wizard                                       ---> draziw
		gsrh rh zm vcznkov lu gsv zgyzhs xrksvi      ---> this is an example of the atbash cipher
		
	It starts off by waiting for user input with a menu displayed to the user.
	Menu:
		1) Atbash Cipher
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
int checkIsCharacter(char * input);
void cipher(char * input);

int main(){
	char userInput = '0';		  /* The main menu user input variable */
	int checker = 1;			  /* Checks if user wants to quit or not from main menu */
	
	/* Call the main menu function to display the main menu */
	menu();
	
	do{
		userInput = getchar(); 
		
		if (userInput == '1'){
			system("clear");
			
			/* Variables that are used for error checking to see if input is a number or not */
			char input[100] = "";
			int result = 0;
   
			printf("*** Atbash Cipher ***\n");
			printf("Example 1: INPUT -> draziw ---- OUTPUT -> wizard \n");
			printf("Example 2: INPUT -> gsrh rh zm vcznkov ---- OUTPUT -> this is an example \n");
			printf("Cipher input using Atbash and English: \n");
			scanf(" %[^\n]s",input);
			
			/* Check if the input is acceptable */
			result = checkIsCharacter(input);
			if (result == EXIT_SUCCESS){
				cipher(input);
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
	printf("1) Atbash Cipher\n");
	printf("2) Quit the program (q)\n");  
}

/*-------
	Purpose: Checks if the input is only numbers and periods, and gives a correct return value ( success or failure ) depending on the result
	Parameters: input ( char array input to be checked if it's only numbers and periods )
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
	Purpose: Checks if the input is only characters and gives a correct return value ( success or failure ) depending on the result
	Parameters: input ( char array input to be checked if it's only characters )
	Return: result (EXIT_SUCESS is 0 or EXIT_FAILURE is 1 or higher)
-------*/
int checkIsCharacter(char * input){
    int length = 0;
	int i = 0;
	
    length = strlen (input);
	
    for (i = 0; i < length; i++){
		if (isdigit((int)input[i])){
            printf ("Entered input is incorrect!\n");
            return EXIT_FAILURE;
        }
	}
	
	return EXIT_SUCCESS;
}

/*-------
	Purpose: Converts plain english to atbash or atbash to plain english
	Parameters: input ( char array input to be checked if it's only characters )
	Return: NONE
-------*/
void cipher(char * input){
	char plainText[52] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char atbashCipher[52] = "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";
	char finalResult[100] = "";
	int resultSlot = 0;
	int foundLetter = 0;
	int length = 0;
	int i = 0;
	int n = 0;
	length = strlen (input);
	
	/* Cipher using English and Atbash */
	for (i = 0; i < length; i++){
		/* This loop checks for any characters that match the atbash cipher */
		for (n = 0; n < 52; n++){
			if (plainText[n] == input[i]){
				finalResult[resultSlot] = atbashCipher[n];
				resultSlot++;
				foundLetter = 1;
			}
		}
		
		/* If we have no matches in the atbash cipher just add the character to the result */		
		if (foundLetter == 0){
			finalResult[resultSlot] = input[i];
			resultSlot++;
		}
		foundLetter = 0;
	}
	printf("Cipher result: %s\n", finalResult);
}