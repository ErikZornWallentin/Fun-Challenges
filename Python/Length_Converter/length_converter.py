#!/usr/bin/python

'''
	Author: Erik Zorn - Wallentin 
	Created: May. 10 / 2016
		
	This program was created to polish and improve my Python programming skills during my spare time.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
		
	The script is on Length Conversion, if you don't know what that is, see below link:
	http://www.metric-conversions.org/length/centimeters-to-feet.htm
		
	The program will calculate Centimetre to Feet, and Feet to Centimetre.
		
	It starts off by waiting for user input with a menu displayed to the user.
	Menu:
		1) Centimetre to Feet (cm to ft)
		2) Feet to Centimetre (ft to cm)
		3) Quit the program (q)
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
	print("Please choose one of the following using (1,2,3):")
	print("1) Centimetre to Feet (cm to ft)")
	print("2) Feet to Centimetre (ft to cm)")
	print("3) Quit the program (q)")

'''
	Purpose: Checks if the input is only numbers, and gives a correct return value ( success or failure ) depending on the result
	Parameters: input ( string input to be checked if it's only numbers )
	Return: result (EXIT_SUCESS is 0 or EXIT_FAILURE is 1 or higher)
'''
def checkIsNumber(input):
	periodCounter = 0
	negativeNumber = False
	
	for i in range(len(input)):
		if (input[i] == '-' and i == 0):
			#Do nothing as we will accept negative numbers
			negativeNumber = True
		elif (input[i] == '.'):
			periodCounter = periodCounter + 1
			if (periodCounter > 1):
				print ("Entered input is not a number!\n")
				return 0
		elif (input[i].isdigit() == False):
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
		feetConverted = 0.0
		centimetreInput = 0.0
		input = "0"
		
		print("*** Converting Centimetre to Feet (cm to ft) ***\n")
		input = raw_input("Please enter Centimetre value: ")
		
		#Check if the input is acceptable
		result = checkIsNumber(input)
		if (result == 1):
			centimetreInput = float(input)

			#Convert from Centimetre to Feet
			feetConverted = centimetreInput * 0.032808
			print("Feet result: %f\n" % feetConverted)
			
		menu()
	elif (userInput == '2'):
		os.system('clear')
		
		#Variables we will use our formula on
		centimetreConverted = 0
		feetInput = 0
		input = "0"
		
		print("*** Feet to Centimetre (ft to cm) ***\n")
		input = raw_input("Please enter Feet value: ")
		
		#Check if the input is acceptable
		result = checkIsNumber(input)
		if (result == 1):
			feetInput = float(input)

			#Convert from Feet to Centimetre
			centimetreConverted = feetInput / 0.032808
			print("Centimetre result: %f\n" % centimetreConverted)
		
		menu()
	elif (userInput == '3' or userInput == 'q'):
		print("\nNow quitting the program!\n")
		checker = 0
	else:
		os.system('clear')
		print("Incorrect input, try again!\n")
		menu()