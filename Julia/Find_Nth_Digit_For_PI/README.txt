****************************************************
Erik Zorn-Wallentin	 find_nth_digit_for_pi.jl
Wednesday, May. 11 / 2016
****************************************************

*************
Julia Info
*************

Compiles and runs on Julia version: Julia 0.4.3
I do not confirm that it will run on newer or older versions of Julia.

**********************
Compilation and Running the program(s) 
**********************

Make sure you are in the same directory as the file.
Type "julia find_nth_digit_for_pi.jl" to compile and run the program in the terminal as long as you are in the same directory as the files.

****************************
GENERAL INFO FOR ANY READER 
****************************

**IMPORTANT READ FOR USER**

This program was created to polish and improve my Julia programming skills during my spare time.
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

NONE