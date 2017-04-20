#!/usr/bin/python

'''
	Author: Erik Zorn - Wallentin 
	Created: May. 10 / 2016
		
	This program was created to polish and improve my Python programming skills during my spare time.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
		
	This script uses Bailey-Borwein-Plouffe Formula (BBP Formula) to calculate PI to the nth digit.
		
	If you don't know the BBP formula see this wiki link:
	https://en.wikipedia.org/wiki/Bailey%E2%80%93Borwein%E2%80%93Plouffe_formula
		
	The program will convert the user input to a result in PI at nth digit.
		
	It starts off by waiting for user input with a menu displayed to the user.
	Menu:
		1) Calculate PI to nth digit *max 10 digits*
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
	print("The BBP Formula to Calculate PI")
	print("Please choose one of the following using (1,2):")
	print("1) Calculate PI to nth digit *max 10 digits*")
	print("2) Quit the program (q)")

'''
	Purpose: Checks if the input is only numbers, and gives a correct return value ( success or failure ) depending on the result
	Parameters: input ( string input to be checked if it's only numbers )
	Return: result (EXIT_SUCESS is 0 or EXIT_FAILURE is 1 or higher)
'''
def checkIsNumber(input):
	for i in range(len(input)):
		if (input[i].isdigit() == False):
			print ("Entered input is incorrect!\n")
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
		pi = 0.0
		k = 0
		i = 0
		input = "0"
		
		print("*** The BBP Formula to Calculate PI ***\n")
		input = raw_input("Please enter digit to calculate to (nth): ")
		
		#Check if the input is acceptable
		result = checkIsNumber(input)
		if (result == 1):
			k = int(input)

			if (k <= 0):
				print("Error - Please give a number greater than 0!\n")
			elif (k > 10):
				print("Error - Please give a number less than 10!\n")
			else:
				#BBP formula, using integral SUM and base 16 for PI
				for i in range(k):
					pi += ( 1.0 / pow( 16, i ) ) * ( (4.0 / (8.0 * i + 1.0)) -
															(2.0 / (8.0 * i + 4.0)) -
															(1.0 / (8.0 * i + 5.0)) -
															(1.0 / (8.0 * i + 6.0)) )
				#Set the output to only show the nth digit by using k variable
				print("PI result at nth digit: %0.*f\n" % (k, pi))
		menu()
	elif (userInput == '2' or userInput == 'q'):
		print("\nNow quitting the program!\n")
		checker = 0
	else:
		os.system('clear')
		print("Incorrect input, try again!\n")
		menu()