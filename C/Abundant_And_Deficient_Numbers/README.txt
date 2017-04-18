****************************************************
Erik Zorn-Wallentin	 abundant_and_deficient_numbers.c
Monday, May. 09 / 2016
****************************************************

**********************
Compilation
**********************

To compile the program use the terminal and type in "gcc -Wall -ansi abundant_and_deficient_numbers.c -o abundant_and_deficient_numbers" into the terminal as long as you are in the same directory as the files.
Gcc (GNU Compiler Collection) is a compiler that will compile the c file into a binary executable (.exe file) using the above command.

**********************
Running the program(s) 
**********************

Type ./abundant_and_deficient_numbers or abundant_and_deficient_numbers to run the program in the terminal as long as you are in the same directory as the files.

****************************
GENERAL INFO FOR ANY READER 
****************************

**IMPORTANT READ FOR USER**

		
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
	

**************************
Bibliography / References
**************************

http://www.positiveintegers.org/IntegerTables/1-100

*****************
Known Limitations
*****************

The program was designed to only accept values between 1-1000 as the correct input from user.


