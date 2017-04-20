#!/usr/bin/python

'''
	Author: Erik Zorn - Wallentin 
	Created: May. 10 / 2016
		
	This program was created to polish and improve my Python programming skills during my spare time.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
		
	The script is on Metric Conversion, if you don't know what that is, see below link:
	www.metric-conversions.org/length/kilometers-to-meters.htm
		
	The program will calculate Kilometre to Metre, and Metre to Kilometre.
		
	It starts off by waiting for user input with a menu displayed to the user.
	Menu:
		1) Kilometre to Metre (km to m)
		2) Metre to Kilometre (m to km)
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
	print("1) Kilometre to Metre (km to m)")
	print("2) Metre to Kilometre (m to km)")
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
		metresConverted = 0.0
		kilometresInput = 0.0
		input = "0"
		
		print("*** Converting Kilometre to Metre (km to m) ***\n")
		input = raw_input("Please enter Kilometre value: ")
		
		#Check if the input is acceptable
		result = checkIsNumber(input)
		if (result == 1):
			kilometresInput = float(input)

			#Convert from Kilometre to Metre
			metresConverted = kilometresInput / 0.001
			print("Metre result: %f\n" % metresConverted)
			
		menu()
	elif (userInput == '2'):
		os.system('clear')
		
		#Variables we will use our formula on
		kilometresConverted = 0
		metresInput = 0
		input = "0"
		
		print("*** Metre to Kilometre (m to km) ***\n")
		input = raw_input("Please enter Metre value: ")
		
		#Check if the input is acceptable
		result = checkIsNumber(input)
		if (result == 1):
			metresInput = float(input)

			#Convert from Metre to Kilometre
			kilometresConverted = metresInput * 0.001
			print("Kilometre result: %f\n" % kilometresConverted)
		
		menu()
	elif (userInput == '3' or userInput == 'q'):
		print("\nNow quitting the program!\n")
		checker = 0
	else:
		os.system('clear')
		print("Incorrect input, try again!\n")
		menu()