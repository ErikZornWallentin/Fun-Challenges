/************************* simple_lottery.c ****************************
Student Name: Erik Zorn - Wallentin  Student Number: 0864583
Date: Fri, Nov.22 / 2013             Course Name: CIS1500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/

/*
	This program was created during my 1st year of Software Engineering at University of Guelph.
	It is a very simple script for an assignment in my CIS*1500 class.
	Since this is a script I did in 1st year of University, this is not a current representation of my skill after graduating University of Guelph in Software Engineering.

	The script is a simple lottery checker that takes input from the user to set everything and after compare their results.
	Everything is fake and has limited functionality as requested by the assignment.

	When the program runs it will ask the user for input for the shown menu.
	You have several options to choose from:
		n) Enter your name and jackpot amount
		w) Enter winning number
		t) Enter ticket numbers
		e) Check to see if you won!
		q) Quit the program
	
	Program has sleep commands so it is slow, please check for the feedback as it will make sure you gave proper input before moving onto next menu options.
	This script has limited error checking functionality.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAXSIZE 100 

char menu();
int matchingNumbers(int winningNumbers[], int ticketNumbers[]);
int resultNumbers(int i, int ticketNumbers[]);
int getNumberWithErrorCheck(int * theNumber, int size);

int main()
{
    char userInput = '0';         /* The main menu user input variable */
    int checker = 1;              /* Checks if user wants to quit or not variable in main menu */
    int checker2 = 1;             /* Checks if user input was valid or not in jackpot input */
    int checker3 = 1;             /* Checks if user input was valid or not in ticket menu */
    int totalMoney = 0;           /* Total jackpot amount variable */
    char holder[10] = "";         /* Holds the user to view screen and fixes bug variable */
    char userName[10] = "";       /* Stores the users name in a variable */
    int winningNumbers[7] = {0};  /* Stores the numbers of winning ticket in a array variable */
    int ticketNumbers[7] = {0};   /* Stores the numbers of normal ticket in a array variable */
    int ticketNumbers1[7] = {0};  /* Stores the numbers of normal ticket in a array variable */
    int numOfMatches = 0;         /* Variable to check between winning and normal ticket matches */
    int number = 0;               /* User input variable for ticket numbers */
    int number2 = 0;              /* User input variable for ticket numbers for error and bug check */
    int number3 = 0;              /* User input variable for ticket numbers added */
    int again;                    /* Variable to check if they want to add more ticket numbers */	
    int i;                        /* Counter variable to print or get ticket numbers */
    int errorCode;                /* Error checker variable to check for bad input */
    int value = 0;                /* The amount won in $ variable */
    int winningEntered = 0;       /* Check if the user enter winning ticket numbers or not variable */
            
    do
    {
        /* Call the main menu function to display the main menu */
		menu();
		userInput = getchar(); 
        
        /* If user presses 'n' in the menu you can input your name and jackpot amount */
		if (userInput == 'n')
        {
            printf("Please enter your name: ");
            scanf("%s", userName);
            do
            {
                printf("Please enter the total Jackpot amount: ");
                scanf("%d", &number); 
				/* This is a placeholder that fixes a bug with error checking */
                number2 = number;
		
                /* Error checking part, it gives guidance on where you made the error */
                errorCode = getNumberWithErrorCheck(&number,4);
                if (errorCode == 0)
                {
                   totalMoney = number2;
                   checker2 = 0;  
                }
            }while(checker2 == 1);
            printf("Your name is: %s, and the total Jackpot is: %d$\n", userName, totalMoney);
            sleep(2);
     
        }
        /* If user presses 'w' in main menu they can add the winning numbers ticket */
		else if (userInput == 'w')
		{       
            printf("Please enter your winning numbers one at a time!\n");
            
			for (i = 0; i < 6; i++)
			{
				printf("Enter number: ");
                scanf("%d", &number);
                /* This is a placeholder that fixes a bug with error checking */
                number2 = number;
		
                /* Error checking part, it gives guidance on where you made the error */
                errorCode = getNumberWithErrorCheck(&number,4);
				if (errorCode == 0)
                {
                    if (number2 > 0 && number2 < 50)
					{
						winningNumbers[i] = number2;  
					}
					else
                    {
                        printf("Incorrect Input: Try a number between 1-49!\n");
						if (i == 0)
						{
							i = i - 1;
                        }
                        else
                        {	
							i = i - 1;
                        }	 
                    }
                }
				else
                {
                    i = i - 1; 
                }	
			}	
            
			printf("The winning numbers are: ");
			for(i = 0; i < 6; i++)
			{	
                printf("%d ", winningNumbers[i]);
            }
			
			winningEntered = 1;
			/* This is used to hold the screen to view the winning numbers till the user is satisfied,
				also without this part the screens become all weird without this part (used for error fixing) */	
			printf("\nPlease input something to continue..."); 
			scanf("%s", holder);   
		}
		/* If user presses 't' in main menu they can add ticket numbers and extra tickets */
		else if (userInput == 't')
		{     
            printf("Please enter your ticket numbers one at a time!\n");
            
			for (i = 0; i < 6; i++)
			{
				printf("Enter number: ");
				scanf("%d", &number);
				/* This is a placeholder that fixes a bug with error checking */
				number2 = number;
			
				/* Error checking part, it gives guidance on where you made the error */
				errorCode = getNumberWithErrorCheck(&number,4);
				if (errorCode == 0)
				{
					if (number2 > 0 && number2 < 50)
					{
						ticketNumbers[i] = number2;  
					}
					else
					{
						printf("Incorrect Input: Try a number between 1-49!\n");
						if (i == 0)
						{
							i = i - 1;
						}
						else
						{	
							i = i - 1;
						}	 
					}
				}
				else
				{
					i = i - 1; 
				}
			}
			
            printf("Would you like to add another ticket?\n");
            printf("'1' for yes and '2' for no\n");
			do
            {
                scanf("%d",&again);
                number3 = again;
		
				/* Error checking part, it gives guidance on where you made the error */
				errorCode = getNumberWithErrorCheck(&again,10);
				if (errorCode == 0)
                {
					if(number3 == 1)
                    { 
                        printf("Please enter your ticket numbers one at a time!\n");
            
						for (i = 0; i < 6; i++)
						{
							printf("Enter number: ");
                            scanf("%d", &number);
                            /* This is a placeholder that fixes a bug with error checking */
							number2 = number;
		
							/* Error checking part, it gives guidance on where you made the error */
							errorCode = getNumberWithErrorCheck(&number,4);
							if (errorCode == 0)
							{
								if (number2 > 0 && number2 < 50)
								{
									ticketNumbers1[i] = number2;  
								}
								else
								{
									printf("Incorrect Input: Try a number between 1-49!\n");
									if (i == 0)
									{
										i = i - 1;
									}
									else
									{	
										i = i - 1;
									}	 
								}
							}
							else
							{
								i = i - 1; 
							}
						}
                        printf("Please input numbers into keyboard to continue...");
                        number3 = 2;
                        sleep(1); 
                    }
                   
                    else if (number3 == 2)
                    {		
                        printf("The ticket numbers are: ");
                        printf("\n");
						for(i = 0; i < 6; i++)
						{	
							printf("%d ", ticketNumbers[i]);
						}
						printf("\n");
						for(i = 0; i < 6; i++)
						{	
							printf("%d ", ticketNumbers1[i]);
						}
			
						/* This is used to hold the screen to view the winning numbers till the user is satisfied,
							also without this part the screens become all weird without this part (used for error fixing) */	
						printf("\nPlease input something to continue..."); 
						scanf("%s", holder);
                        checker3 = 0;
                    }
                }
                /* The sleep for 1 second fixes a bug from making it not go back to main menu on random input. 
                   Sometimes it doesn't fix it, but greatly reduces the bug from happening */
                sleep(1.5);                         
            }while(checker3 == 1);
		}
		/* If user presses 'e' they can see their name and matches in the lottery game */
		else if (userInput == 'e')
		{
            if (winningEntered == 1)
            {
                printf("Hello %s!\n", userName);
                printf("The total jackpot is: $%d\n", totalMoney);
				numOfMatches = matchingNumbers(winningNumbers,ticketNumbers);
				printf("You have %d match(es)\n", numOfMatches);
            
                if (numOfMatches == 2)
                {
                    printf("You have won: A free to play ticket!");
                }
                else if (numOfMatches == 3)
            	{
               	    printf("You have won: $10\n");
                    printf("Your chances of winning this was 1 in 56.7 people");
            	}
                else if (numOfMatches == 4)
            	{
                    /* 4 matches out of 6 is 9% of the pools fund (combining 5/6 and 5/6+ bonus rules )*/
                    value = totalMoney * 0.9;
                    printf("You have won: $%d!\n", value);
                    printf("Your chances of winning this was 1 in 1,033 people");
            	}
            	else if (numOfMatches == 5)
            	{
                    /* 5 matches out of 6 is 11% of the pools fund (combining 5/6 and 5/6+ bonus rules )*/
                    value = totalMoney * 0.11;
                    printf("You have won: $%d!!\n", value);
                    printf("Your chances of winning this was 1 in 55,492 people");
            	}
            	else if (numOfMatches == 6)
            	{
                    /* Jackpot is 80% of the pools fund */
					value = totalMoney * 0.8;
					printf("You won the JACKPOT: $%d!!!!\n", value);
                    printf("Your chances of winning this was 1 in 13,983,816 people");
                }
				/* This is used to hold the screen to view the winning numbers till the user is satisfied,
                   also without this part the screens become all weird without this part (used for error fixing) */	
				printf("\nPlease input something to continue..."); 
				scanf("%s", holder);	
			}
            else
            {
                printf("Please enter winning number ticket!");
                sleep(1.5);
            }	     
		}
        /* If user presses 'q' the program will quit! */
		else if (userInput == 'q')
		{
			printf("Now quitting the program!\n");
			sleep(1);	
			checker = 0;	
		}
		else
		{
			printf("Incorrect input, try again!\n");
			sleep(1);			
		}
	}while(checker == 1);			
	return 0;
}

/*-------
	Purpose: The main menu that is displayed to the user
	Parameters: NONE
	Return: userInput ( returns 0 )
-------*/
char menu()
{ 	
    system("clear");
    printf("\nPlease choose one of the following:\n");
    printf("Enter your name and jackpot amount (n)\n");
    printf("Enter winning number (w)\n");
    printf("Enter ticket numbers (t)\n");
    printf("Check to see if you won! (e)\n");
    printf("Quit the program (q)\n");
    return 0;
}

/*-------
	Purpose: The matching ticket number function
	Parameters: winningNumbers ( integer array of winning numbers given by user ), ticketNumbers ( integer array of ticket numbers given by user )
	Return: matching ( returns the matching amount )
-------*/
int matchingNumbers(int winningNumbers[], int ticketNumbers[])
{
    int matching = 0;
    int numOfMatch;
    int i;
  
    for (i = 0; i < 6; i++)
    {     
       numOfMatch = resultNumbers(winningNumbers[i],ticketNumbers);
       if(numOfMatch == 1)
       {
			matching = matching + 1;
       }		    
    }	
    return matching;
}

/*-------
	Purpose: The inner function that sends back true or false 
	Parameters: i ( the winning numbers slot ), ticketNumbers ( integer array of ticket numbers given by user )
	Return: result ( 0 for no results, 1 for having results )
-------*/
int resultNumbers(int i, int ticketNumbers[])
{
    int n;

    for (n = 0; n < 6; n++)
    {
        if (i == ticketNumbers[n])
		{
			return 1;
        }
    }            
    return 0;
}

/*-------
	Purpose: Error checking function to determine if we have an invalid character
	Parameters: theNumber ( integer pointer to the address of the number given ), size ( integer value of the size of the number )
	Return: result ( -1 is an error, or 0 is success )
-------*/
int getNumberWithErrorCheck(int * theNumber, int size)
{
    int i;
    char next;
    char inputString[MAXSIZE];
    if (size > MAXSIZE)        	    
    {
        size = MAXSIZE;
    }
    
	fgets(inputString,MAXSIZE,stdin);
    i = 0;
    next = inputString[i];     
    
	while ( i < size && next != '\0'&& isdigit(next)&& next !='\n')
    {     	
        i = i + 1;
        next = inputString[i];  
    }  
       
    if (i + 1 < strlen(inputString))
    {
        printf("Invalid input, please try numbers!\n");
       	/*there was an error*/
        * theNumber = -99;
       	return -1;   
    }
    else
    {
        *theNumber = (int)atol(inputString);   	
    }   

    return 0;
}
