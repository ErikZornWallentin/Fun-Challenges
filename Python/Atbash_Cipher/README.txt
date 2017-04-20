****************************************************
Erik Zorn-Wallentin	 atbash_cipher.py
Tuesday, May. 10 / 2016
****************************************************

*************
Python Info
*************

Compiles and runs on Python version: Python 2.7.7
I do not confirm that it will run on newer or older versions of Python.

It does contain the path: #!/usr/bin/python at top of file.


**********************
Compilation and Running the program(s) 
**********************

Make sure you are in the same directory as the file.
Type "python atbash_cipher.py" to compile and run the program in the terminal as long as you are in the same directory as the files.

****************************
GENERAL INFO FOR ANY READER 
****************************

**IMPORTANT READ FOR USER**

This program was created to polish and improve my Python programming skills during my spare time.
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

NONE