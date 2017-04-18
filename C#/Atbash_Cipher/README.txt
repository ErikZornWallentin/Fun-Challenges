****************************************************
Erik Zorn-Wallentin	 AtbashCipher.sln
Tuesday, May. 17 / 2016
****************************************************

*************
Setup C#
*************

Download and install Microsoft .NET Framework
Once it is download get the path of the .NET Framework on your computer.
Example:
	PATH -- Add the path to your environment variables:
	C:\Windows\Microsoft.NET\Framework\v4.0.30319

AND	
	
Microsoft Visual Studio 2015
Download and install Microsoft Visual Studio 2015
Open Microsoft Visual Studio and open a project to run the C# programs.

*************
C# Info
*************

Compiles and runs on Microsoft Visual Studio 2015.
I do not confirm that it will run on newer or older versions of Microsoft Visual Studio.

***************************************
Compilation and Running the program(s) 
***************************************

Open the *.sln file in this directory in Microsoft Visual Studio as a project, and press on the green arrow ">" button to run the program.
It will compile and run for you and will give you further instructions on how to manage the program.

****************************
GENERAL INFO FOR ANY READER 
****************************

**IMPORTANT READ FOR USER**

This program was created to polish and improve my C# programming skills.
This was created in several languages in my repository of code to show the differences in each language with the same functionality.

This script is on Atbash Cipher, if you don't know what that is, see below link:
https://en.wikipedia.org/wiki/Atbash
	
The program will use atbash cipher to convert English to Atbash or Atbash to English.
	
It starts off by waiting for user input.
In textbox on the screen you input a word and hit "Cipher" button to cipher the word!
You can reset the cipher at any time to get back to the original state that the program started in.
Program handles error checking for incorrect input, also will preserve uppercase or lowercase of letter.
	
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

**************************
Bibliography / References
**************************

https://en.wikipedia.org/wiki/Atbash

*****************
Known Limitations
*****************

NONE