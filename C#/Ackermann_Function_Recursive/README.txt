****************************************************
Erik Zorn-Wallentin	 AckermannFunctionRecursive.sln
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
	N: 10
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