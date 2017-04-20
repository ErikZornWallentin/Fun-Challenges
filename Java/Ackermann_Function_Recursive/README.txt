****************************************************
Erik Zorn-Wallentin	 AckermannFunctionRecursive.java
Friday, May. 13 / 2016
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

Type "java AckermannFunctionRecursive" to run the main class file for the program.

****************************
GENERAL INFO FOR ANY READER 
****************************

**IMPORTANT READ FOR USER**

This program was created to polish and improve my Java programming skills.
This was created in several languages in my repository of code to show the differences in each language with the same functionality.
	
This is Ackermann Function, if you don't know what that is see link:
https://en.wikipedia.org/wiki/Ackermann_function
	
	
It starts off by waiting for user input in M or N text boxes.
Once you give a numerical value, and press the calculate button it will calculate the result for you.
If you use low values from 0-3 in M and N it will calculate it almost instantly.
	
Java is not a very good language to calculate Ackermann Function in, as it cannot handle very high m or n values.
The program also contains error checking in m and n values.
	
Example use 1:
	M: 1
	N: 1
	Result: 3

Example use 2:
	M: 2
	N: 2
	Result: 7
	
Example use 3:
	M: 3
	N: 11
	Result: CRASH - Cannot handle this input

Example use 4:
	M: 4
	N: 4
	Result: CRASH - Cannot handle this input

**************************
Bibliography / References
**************************

https://en.wikipedia.org/wiki/Ackermann_function

*****************
Known Limitations
*****************

NONE