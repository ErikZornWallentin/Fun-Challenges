#!/usr/bin/python

'''
	Author: Erik Zorn - Wallentin 
	Created: May. 10 / 2016
		
	This program was created to polish and improve my Python programming skills during my spare time.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
		
	This is Factorial, if you don't know what that is see link:
	https://en.wikipedia.org/wiki/Factorial
		
	The program will convert the user input to a result in factorial.
		
	It starts off by waiting for user input with a menu displayed to the user.
	Menu:
		1) Calculate factorial
		2) Quit the program (q)
	Choosing an option from the menu will allow you to do a specific conversion and ask for more input.
	Once it gives you the result from the conversion it will return you to the menu.
	
	The program has error checking to determine if the input from user was valid or not.
'''

import sys, timeit, datetime
import time
import os

'''
	Purpose: The main menu that is displayed to the user
	Parameters: NONE
	Return: NONE
'''
def menu():
	print("Please choose one of the following using (1,2):")
	print("1) Calculate factorial")
	print("2) Quit the program (q)")

'''
	Purpose: Checks if the input is only numbers, and gives a correct return value ( success or failure ) depending on the result
	Parameters: input ( string input to be checked if it's only numbers )
	Return: result (EXIT_SUCESS is 0 or EXIT_FAILURE is 1 or higher)
'''
def checkIsNumber(input):
	for i in range(len(input)):
		if (input[i].isdigit() == False):
			print ("Entered input is not a number!\n")
			return 0
	return 1

userInput = '0'
checker = 1

os.system('clear')
menu()

while (checker == 1):
	userInput = raw_input("Please enter a menu option: ")
	
	if (userInput == '1'):
		os.system('clear')
		
		#Variables we will use our formula on
		factorialResult = 0
		factorialInput = 0
		input = "0"
		
		print("*** Calculate Factorial ***\n")
		input = raw_input("Please enter value (example 4): ")
		
		#Check if the input is acceptable
		errorCheck = checkIsNumber(input)
		if (errorCheck == 1):
			factorialInput = int(input)

			if (factorialInput < 0):
				factorialResult = -1
			elif (factorialInput == 0):
				factorialResult = 1
			else:
				result = factorialInput
	
				while (factorialInput > 2):
					factorialInput -= 1
					result *= factorialInput
				factorialResult = result
			print("Factorial result: %d\n" % factorialResult)
		menu()
	elif (userInput == '2' or userInput == 'q'):
		print("\nNow quitting the program!\n")
		checker = 0
	else:
		os.system('clear')
		print("Incorrect input, try again!\n")
		menu()