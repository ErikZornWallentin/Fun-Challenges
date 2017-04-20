****************************************************
Erik Zorn-Wallentin	 AbundantAndDeficientNumbers.java
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

Type "java AbundantAndDeficientNumbers" to run the main class file for the program.

****************************
GENERAL INFO FOR ANY READER 
****************************

**IMPORTANT READ FOR USER**

This program was created to polish and improve my Java programming skills.
This was created in several languages in my repository of code to show the differences in each language with the same functionality.
	
This is script is on Abundant and Deficient Number, if you don't know what that is, see below link:
http://www.positiveintegers.org/IntegerTables/1-100

Example use's:
Consider the number 21. Its divisors are 1, 3, 7 and 21, and their sum is 32. 
Because 32 is less than 2 x 21, the number 21 is deficient. 
Its deficiency is 2 x 21 - 32 = 10.

The integer 12 is the first abundant number. Its divisors are 1, 2, 3, 4, 6, and 12, and their sum is 28. 
Because 28 is greater than 2 x 12, the number 12 is abundant. 
It's abundant by is 28 - 24 = 4.

The program will determine if the given number is abundant, deficient or neither.
The program also has error checking and will only accept numbers between 1-1000.
Any other input that is not a number between 1-1000 will throw and error.

It starts off by waiting for user input. 
In both textbox's on the screen you input a number and hit "Calculate" button to determine what the number is.
You can reset the converter at any time to get back to the original state that the program started in.

**************************
Bibliography / References
**************************

http://www.positiveintegers.org/IntegerTables/1-100

*****************
Known Limitations
*****************

NONE