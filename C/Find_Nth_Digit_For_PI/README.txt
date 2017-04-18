****************************************************
Erik Zorn-Wallentin	 find_nth_digit_for_pi.c
Thursday, May. 05 / 2016
****************************************************

**********************
Compilation
**********************

To compile the program use the terminal and type in "gcc -Wall -ansi find_nth_digit_for_pi.c -o find_nth_digit_for_pi" into the terminal as long as you are in the same directory as the files.
Gcc (GNU Compiler Collection) is a compiler that will compile the c file into a binary executable (.exe file) using the above command.

**********************
Running the program(s) 
**********************

Type ./find_nth_digit_for_pi or find_nth_digit_for_pi to run the program in the terminal as long as you are in the same directory as the files.

****************************
GENERAL INFO FOR ANY READER 
****************************

**IMPORTANT READ FOR USER**

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

**************************
Bibliography / References
**************************

https://en.wikipedia.org/wiki/Bailey%E2%80%93Borwein%E2%80%93Plouffe_formula

*****************
Known Limitations
*****************

The prgoram was designed to not accept any value that is not an integer, or greater than 10, or less than 1.


