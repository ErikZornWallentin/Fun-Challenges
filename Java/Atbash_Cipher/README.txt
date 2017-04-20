****************************************************
Erik Zorn-Wallentin	 AtbashCipher.java
Thursday, May. 12 / 2016
****************************************************

*************
Setup Java
*************

Download and install the Java Development Kit from Oracle site.
Once it is download get the path of the JDK and JRE and set the paths to CLASSPATH and PATH in environment variables
Example:
	CLASSPATH -- Add the path of JDK and JRE up to the bin:
	C:\Program Files\Java\jdk1.8.0_60\bin;C:\Program Files\Java\jre1.8.0_60\bin;.
	
	PATH -- Add the path of JDK and JRE up to the bin:
	C:\Program Files\Java\jdk1.8.0_60\bin;C:\Program Files\Java\jre1.8.0_60\bin

*************
Java Info
*************

Compiles and runs on Java version: Java 1.8.0
I do not confirm that it will run on newer or older versions of Java.

***************************************
Compilation and Running the program(s) 
***************************************

Make sure you are in the same directory as the file.
Type "javac *.java" to compile all java script(s) in the directory and only works if you are in the same directory as the files.

Type "java AtbashCipher" to run the main class file for the program.

****************************
GENERAL INFO FOR ANY READER 
****************************

**IMPORTANT READ FOR USER**

This program was created to polish and improve my Java programming skills.
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

https://en.wikipedia.org/wiki/Factorial

*****************
Known Limitations
*****************

NONE