****************************************************
Erik Zorn-Wallentin	 FindNthDigitForPI.java
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

Type "java FindNthDigitForPI" to run the main class file for the program.

****************************
GENERAL INFO FOR ANY READER 
****************************

**IMPORTANT READ FOR USER**

This program was created to polish and improve my Java programming skills.
This was created in several languages in my repository of code to show the differences in each language with the same functionality.
	
This script uses Bailey-Borwein-Plouffe Formula (BBP Formula) to calculate PI to the nth digit.
		
If you don't know the BBP formula see this wiki link:
https://en.wikipedia.org/wiki/Bailey%E2%80%93Borwein%E2%80%93Plouffe_formula
		
It starts off by waiting for user input. 
In the textbox on the screen you input a number and hit "Calculate" button to calculate PI to nth digit!
Make sure it is below 10 otherwise it will throw an error to say it should be between 0-10.	

**************************
Bibliography / References
**************************

https://en.wikipedia.org/wiki/Bailey%E2%80%93Borwein%E2%80%93Plouffe_formula

*****************
Known Limitations
*****************

NONE