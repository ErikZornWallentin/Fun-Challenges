/************************* simple_math_flashcards.c ****************************
Student Name: Erik Zorn - Wallentin       Student Number: 0864583
Date: Wed, Nov.06 / 2013                  Course Name: CIS1500
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

	The script is a flashcard game that allows you to choose what type of math you want to do in take several "tests" in that category of math.

	When the program runs it will ask the user for input for multiplication, addition or quit.
	You need to input the proper data such as m,a, or q to advance to the next menu.
	When you pick a menu option such as m, you will now play 5 rounds of a flashcard game.
	The user should input the correct data and it will bring you back to the menu after 5 rounds.
	The same game is played for the addition part, and if you press q for quit you will exit the program.
	If you input incorrect data during flashcard game it will loop till you input the correct data.
	Please follow the rest of the instructions in the program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAXSIZE 100                                      /* The max size for a4 */

char menu(char input);                                   /* Menu function at start */       
int multiplication(int multInput);                       /* Multiplication function */
int addition(int addInput);                              /* Addition function*/
int division(int divInput);                              /* Division function */
int subtraction(int subInput);                           /* Subtraction function */
int getNumberWithErrorCheck(int * theNumber, int size);  /* Error checking function */

int main()
{
    char input = '0';                                    /* Input data for menu */
    char mainMenu = '0';                                 /* Main menu variable */
    int checker = 1;                                     /* Variable used to exit program */
    int multInput = 0;                                   /* Multiplication input variable */
    int multMenu= 0;                                     /* Multiplication menu variable */
    int addInput = 0;                                    /* Addition input variable */
    int addMenu = 0;                                     /* Addition menu variable */
    int divInput = 0;                                    /* Division input variable */
    int divMenu = 0;                                     /* Division menu variable */
    int subInput = 0;                                    /* Subtraction input variable */
    int subMenu = 0;                                     /* Subtraction menu variable */

    
    srand (time(NULL));                          
    
    do
    {
        /* Call the main menu function to display the main menu at start of program */
        mainMenu = menu(input);
        
        /* If user presses 'm' go into multiplication menu */
        if (mainMenu == 'm')        
        {
            multMenu = multiplication(multInput);
			/*I did this if statement to get rid of any warnings*/
			if (multMenu != 99)
				{

				}
			}
        /* If user presses 'a' go into addition menu */
        else if (mainMenu == 'a')
        {
            addMenu = addition(addInput);
		   /*I did this if statement to get rid of any warnings*/
			if (addMenu != 99)
			{

			}
		}
		/* If user presses 'd' go into division menu */
        else if (mainMenu == 'd')
        {
            divMenu = division(divInput);
		   /*I did this if statement to get rid of any warnings*/
			if (divMenu != 99)
			{

			}
		}
		/* If user presses 's' go into subtraction menu */
        else if (mainMenu == 's')
        {
            subMenu = subtraction(subInput);
		   /*I did this if statement to get rid of any warnings*/
			if (subMenu != 99)
			{

			}
        }
        /* If user presses 'q' quit the program! */
        else if (mainMenu == 'q')
        {
			printf("Program is now quitting! Thanks for playing\n\n");
			checker = 0;
        }
        /* If user does not input valid info for menu give an error */
		else
		{
			printf("Invalid input, please try again!\n\n");
			sleep(1);
		} 
          
    }while(checker == 1);
    return 0;
}

/*-------
	Purpose: The main menu that is displayed to the user
	Parameters: input ( takes in a character value as the input from menu option)
	Return: userInput ( returns a character back from pressed menu option )
-------*/
char menu(char input)
{
    system("clear");
    char userInput = input;
	
    printf("\nPlease choose one of the following:\n");
    printf("(m)ultiplication flashcard game\n");
    printf("(a)ddition flashcard game\n");
    printf("(d)ivision flashcard game\n");
    printf("(s)ubtraction flashcard game\n");
    printf("(q)uit the program\n");
    userInput = getchar();
	
    return (userInput);
}

/*-------
	Purpose: The multiplication function and flashcard part for multiplication
	Parameters: multInput ( takes in an integer value as the input from menu option)
	Return: multInput ( returns an integer back from multiplication flash card result )
-------*/
int multiplication(int multInput)
{
    int score = 0;                                     /* The score variable */
    int newScore = 0;                                  /* The new score variable */
    int multOne = 0;                                   /* First multiplication number */
    int multTwo = 0;                                   /* Second multiplication number */
    int multTotal = 0;                                 /* Multiplication total */
    int highestNum = 9;                                /* Highest random number used is 9 */
    int errorCode;                                     /* Error code variable */
    int multInput2;                                    /* This variable fixes problems */

    do
    {	
        
        multOne = (rand()%highestNum);
        multTwo = (rand()%highestNum);
        printf("\nYour current score is %d out of %d\n",score,newScore);
        printf("What is %d X %d?\n",multOne,multTwo);
        multTotal = multOne * multTwo;
        scanf("%d", &multInput);
        multInput2 = multInput;
		errorCode = getNumberWithErrorCheck(&multInput,4);
        
        if (errorCode == 0)
		{
        
            if (multInput2 == multTotal)
            {
                printf("Correct!\n");
                score = score + 1;
                newScore = newScore + 1;
                errorCode = 3; 

            }
            else
            {
                printf("Incorrect, the correct answer was %d\n",multTotal);
                newScore = newScore + 1; 
                errorCode = 3;
            }
        }
    }while(newScore < 5);
    printf("Your final score is %d out of %d\n",score,newScore);
    printf("Please wait a few seconds!\n\n");
    sleep(2);
    return (multInput);
}

/*-------
	Purpose: The addition function with flashcard part
	Parameters: addInput ( takes in an integer value as the input from menu option)
	Return: addInput ( returns an integer back from multiplication flash card result )
-------*/
int addition(int addInput)
{
    int score = 0;                                     /* The score variable */
    int newScore = 0;                                  /* The new score variable */
    int addOne = 0;                                    /* First addition number */
    int addTwo = 0;                                    /* Second addition number */
    int addTotal = 0;                                  /* Addition total */
    int highestNum = 9;                                /* Highest random number used is 9 */
    int errorCode;                                     /* Error code variable */
    int addInput2;                                     /* This variable fixes problems */

    do
    {	
        
        addOne = (rand()%highestNum);
        addTwo = (rand()%highestNum);
        printf("\nYour current score is %d out of %d\n",score,newScore);
        printf("What is %d + %d?\n",addOne,addTwo);
        addTotal = addOne + addTwo;
        scanf("%d", &addInput);
        addInput2 = addInput;
		errorCode = getNumberWithErrorCheck(&addInput,4);
        
        if (errorCode == 0)
		{
        
            if (addInput2 == addTotal)
            {
                printf("Correct!\n");
                score = score + 1;
                newScore = newScore + 1;
                errorCode = 3; 

            }
            else
            {
                printf("Incorrect, the correct answer was %d\n",addTotal);
                newScore = newScore + 1; 
                errorCode = 3;
            }
        }
    }while(newScore < 5);
    printf("Your final score is %d out of %d\n",score,newScore);
    printf("Please wait a few seconds!\n\n");
    sleep(2);
    return (addInput);
}

/*-------
	Purpose: The division function and flashcard part for division
	Parameters: addInput ( takes in an integer value as the input from menu option)
	Return: addInput ( returns an integer back from multiplication flash card result )
-------*/
int division(int divInput)
{
    int score = 0;                                     /* The score variable */
    int newScore = 0;                                  /* The new score variable */
    int divOne = 0;                                    /* First division number */
    int divTwo = 0;                                    /* Second division number */
    double divTotal = 0;                               /* Division total */
    int highestNum = 9;                                /* Highest random number used is 9 */
    int errorCode;                                     /* Error code variable */
    int divInput2;                                     /* This variable fixes problems */

    do
    {	
        
        divOne = (rand()%highestNum);
        divTwo = (rand()%highestNum);
        printf("\nYour current score is %d out of %d\n",score,newScore);
        printf("What is %d / %d?\n",divOne,divTwo);
		if (divTwo != 0)
        {
            divTotal = divOne / divTwo;	
        }
        else
		{
            divTotal = 0;        
        }
        scanf("%d", &divInput);
        divInput2 = divInput;
		errorCode = getNumberWithErrorCheck(&divInput,4);
        
        if (errorCode == 0)
		{
        
            if (divInput2 == divTotal)
            {
                printf("Correct!\n");
                score = score + 1;
                newScore = newScore + 1;
                errorCode = 3; 
            }
            else
            {
                printf("Incorrect, the correct answer was %0.2lf\n",divTotal);
                newScore = newScore + 1; 
                errorCode = 3;
            }
        }
    }while(newScore < 5);
    printf("Your final score is %d out of %d\n",score,newScore);
    printf("Please wait a few seconds!\n\n");
    sleep(2);
    return (divInput);
}

/*-------
	Purpose: The subtraction function with flashcard part
	Parameters: addInput ( takes in an integer value as the input from menu option)
	Return: addInput ( returns an integer back from multiplication flash card result )
-------*/
int subtraction(int subInput)
{
    int score = 0;                                     /* The score variable */
    int newScore = 0;                                  /* The new score variable */
    int subOne = 0;                                    /* First subtraction number */
    int subTwo = 0;                                    /* Second subtraction number */
    int subTotal = 0;                                  /* Subtraction total */
    int highestNum = 9;                                /* Highest random number used is 9 */
    int errorCode;                                     /* Error code variable */
    int subInput2;                                     /* This variable fixes problems */

    do
    {	
        
        subOne = (rand()%highestNum);
        subTwo = (rand()%highestNum);
        printf("\nYour current score is %d out of %d\n",score,newScore);
        printf("What is %d - %d?\n",subOne,subTwo);
        subTotal = subOne - subTwo;
        scanf("%d", &subInput);
        subInput2 = subInput;
		errorCode = getNumberWithErrorCheck(&subInput,4);
        
        if (errorCode == 0)
		{
        
            if (subInput2 == subTotal)
            {
                printf("Correct!\n");
                score = score + 1;
                newScore = newScore + 1;
                errorCode = 3; 

            }
            else
            {
                printf("Incorrect, the correct answer was %d\n",subTotal);
                newScore = newScore + 1; 
                errorCode = 3;
            }
        }
    }while(newScore < 5);
    printf("Your final score is %d out of %d\n",score,newScore);
    printf("Please wait a few seconds!\n\n");
    sleep(2);
    return (subInput);
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
       
    if (i+1 < strlen(inputString))
    {
        printf("Invalid input, please try again!\n");
		
       	/* There was an error */
        * theNumber = -99;
		
       	return -1;
    }
    else
    {
        *theNumber = (int)atol(inputString);	
    }   

    return 0;
}
