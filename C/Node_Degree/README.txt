****************************************************
Erik Zorn-Wallentin	 node_degree.c
Monday, May. 09 / 2016
****************************************************

**********************
Compilation
**********************

To compile the program use the terminal and type in "gcc -Wall -ansi node_degree.c -o node_degree" into the terminal as long as you are in the same directory as the files.
Gcc (GNU Compiler Collection) is a compiler that will compile the c file into a binary executable (.exe file) using the above command.

**********************
Running the program(s) 
**********************

Type ./node_degree or node_degree to run the program in the terminal as long as you are in the same directory as the files.

****************************
GENERAL INFO FOR ANY READER 
****************************

**IMPORTANT READ FOR USER**

		
This program was created to polish and improve my C programming skills during my spare time.
This was created in several languages in my repository of code to show the differences in each language with the same functionality.
		
This is Node Degree in Basic Graph Statistics, if you don't know what that is see link:
https://en.wikipedia.org/wiki/Degree_(graph_theory)
	
In graph theory, the degree of a node is the number of edges coming into it or going out of it.
		
The program will convert the user input to a result in Node Degree.
		
It starts off by waiting for user input with a menu displayed to the user.
Menu:
	1) Calculate node degree from file --- input.txt
	2) Quit the program (q)
Choosing option 1 from menu will read the text file "input.txt" which has all the data and display the result to the user.
As long as format in file stays the same, the user can change the data and it will correctly calculate it if you run the program again.
	
The program has error checking to determine if the input from user was valid or not in some cases.
	
File Format:
	The first integer N, is on the first line and it is showing how many nodes we are using.
	The rest of the numbers are undirected graph values as a series of number pairs ( a and b).
	The number pairs show which two nodes that are connected and that is also called an edge.
	Using the pairs we find out the degree of each node as you can see below.
	
Use Case:
	Input:	3
			2	2
			1	3
	Output:
			Node 1 has a degree of 1
			Node 2 has a degree of 2
			Node 3 has a degree of 3
				
	Understanding the program from Input:
			3 		---> The number of total nodes
			2	2	---> Add 2 counters to node 2
			1	3	---> Add 1 counter to node 1 and 1 counter to node 3
	
The program comes with a input.txt that contains a dataset for 16 nodes and their degree.

**************************
Bibliography / References
**************************

https://en.wikipedia.org/wiki/Degree_(graph_theory)

*****************
Known Limitations
*****************

The program was designed to take input from a text file called input.txt and must exist for program to work properly.


