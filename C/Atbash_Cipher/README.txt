****************************************************
Erik Zorn-Wallentin	 atbash_cipher.c
Friday, May. 06 / 2016
****************************************************

**********************
Compilation
**********************

To compile the program use the terminal and type in "gcc -Wall -ansi atbash_cipher.c -o atbash_cipher" into the terminal as long as you are in the same directory as the files.
Gcc (GNU Compiler Collection) is a compiler that will compile the c file into a binary executable (.exe file) using the above command.

**********************
Running the program(s) 
**********************

Type ./atbash_cipher or atbash_cipher to run the program in the terminal as long as you are in the same directory as the files.

****************************
GENERAL INFO FOR ANY READER 
****************************

**IMPORTANT READ FOR USER**

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

**************************
Bibliography / References
**************************

https://en.wikipedia.org/wiki/Atbash

*****************
Known Limitations
*****************

The prgoram was designed to not accept any input that has an integer.


