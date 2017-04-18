/* 	
	Author: Erik Zorn - Wallentin 
	Created: May. 09 / 2016
		
	This program was created to polish and improve my C programming skills during my spare time.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
		
	This is Node Degree in Basic Graph Statistics, if you don't know what that is see link:
	https://en.wikipedia.org/wiki/Degree_(graph_theory)
		
	The program will convert the user input to a result in Node Degree.
		
	It starts off by waiting for user input with a menu displayed to the user.
	Menu:
		1) Calculate node degree from file --- input.txt
		2) Quit the program (q)
	Choosing option 1 from menu will read the text file "input.txt" which has all the data and display the result to the user.
	As long as format in file stays the same, the user can change the data and it will correctly calculate it if you run the program again.
	
	The program has error checking to determine if the input from user was valid or not in some cases.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function Prototypes */
void menu();
int checkIsNumber(char * input);
void node_degrees();

int main(){
	char userInput = '0';		  /* The main menu user input variable */
	int checker = 1;			  /* Checks if user wants to quit or not from main menu */
	
	/* Call the main menu function to display the main menu */
	menu();
	
	do{
		userInput = getchar(); 
		
		if (userInput == '1'){
			system("clear");
   
			printf("*** Calculate node degree from file --- input.txt ***\n");		
			node_degrees();

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
	printf("1) Calculate node degree from file --- input.txt\n");
	printf("2) Quit the program (q)\n");  
}

/*-------
	Purpose: Calculates and shows the degree of each node
	Parameters: NONE
	Return: NONE
-------*/
void node_degrees(){
   	FILE *fp = NULL;
   	int nodeAmount = 0;
   	int nodeDegrees[100];
   	int position = 0;
   	const char delimiter[2] = " ";
	char line[20];
	char * token;
    int i = 0;
    int foundNodeAmount = 0;
   	
   	
   	/* Initializes the array before using it */
   	for (i = 0; i < 100; i++){
    	nodeDegrees[i] = 0;  
    }
   	
   	fp = fopen("input.txt","r"); 
   	if( fp == NULL ){
    	perror("Error while opening the file.\n");
    	return;
   	}
 
	/* Check each line of the file, have a different setup for N and the degrees */
    while(fgets(line, sizeof line, fp) != NULL){
    
    	/* Checks if the file contains anything that is not a number and displays response to user if something went wrong */
    	int result = 0;
    	result = checkIsNumber(line);
    	if (result == EXIT_FAILURE){
    		return;
    	}
    	
    	/* N setup, so we can get the node amount and set the flag after */
    	if (foundNodeAmount == 0){
    		token = strtok(line, "\n");
    		nodeAmount = atoi(token);
    		foundNodeAmount = 1;
    	}else{
    		/* Get the degree amount and stored it for each node */
        	token = strtok(line, delimiter);
        	for(i = 0; i < 2; i++){
            	if(i == 0){   
                	position = atoi(token);
                	position = position - 1;
                	nodeDegrees[position] = nodeDegrees[position] + 1;
                	token = strtok(NULL, delimiter);
            	} else {
                	position = atoi(token);
                	position = position - 1;
                	nodeDegrees[position] = nodeDegrees[position] + 1;
            	}       
        	}
        }
    }
    
    /* Display the node and degree of each node to the user */
    for (i = 0; i < nodeAmount; i++){
    	printf("Node %d has a degree of %d\n", i+1, nodeDegrees[i]);  
    }
 
	fclose(fp);
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
	
	/* We do 1 less than length because we want to ignore the end of line character */
    for (i = 0; i < length - 1; i++){
		if (!isdigit((int)input[i]) && input[i] != ' '){
            printf ("Entered input is incorrect!\n");
            return EXIT_FAILURE;
        }
	}
	
	return EXIT_SUCCESS;
}