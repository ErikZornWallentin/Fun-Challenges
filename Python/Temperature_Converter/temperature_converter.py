#!/usr/bin/python

'''
	Author: Erik Zorn - Wallentin 
	Created: May. 10 / 2016
		
	This program was created to polish and improve my Python programming skills during my spare time.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
		
	The script is on Temperature Conversion, if you don't know what that is, see both links:
	http://www.rapidtables.com/convert/temperature/how-celsius-to-fahrenheit.htm
	http://www.metric-conversions.org/temperature/fahrenheit-to-celsius.htm
		
	The program will calculate Fahrenheit to Celsius, and Celsius to Fahrenheit.
		
	It starts off by waiting for user input with a menu displayed to the user.
	Menu:
		1) Fahrenheit to Celsius (F to C)
		2) Celsius to Fahrenheit (C to F)
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
	print("1) Fahrenheit to Celsius (F to C)")
	print("2) Celsius to Fahrenheit (C to F)")
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
		celsiusConverted = 0.0
		fahrenheitInput = 0.0
		input = "0"
		
		print("*** Converting Fahrenheit to Celsius (F to C) ***\n")
		input = raw_input("Please enter Fahrenheit value: ")
		
		#Check if the input is acceptable
		result = checkIsNumber(input)
		if (result == 1):
			fahrenheitInput = float(input)

			#Convert from Fahrenheit to Celsius
			celsiusConverted = ( fahrenheitInput - 32 ) / 1.8
			print("Celsius result: %f\n" % celsiusConverted)
			
		menu()
	elif (userInput == '2'):
		os.system('clear')
		
		#Variables we will use our formula on
		fahrenheitConverted = 0
		celsiusInput = 0
		input = "0"
		
		print("*** Converting Celsius to Fahrenheit (C to F) ***\n")
		input = raw_input("Please enter Celsius value: ")
		
		#Check if the input is acceptable
		result = checkIsNumber(input)
		if (result == 1):
			celsiusInput = float(input)

			#Convert from Celsius to Fahrenheit
			fahrenheitConverted = ( celsiusInput * 1.8 ) + 32
			print("Fahrenheit result: %f\n" % fahrenheitConverted)
		
		menu()
	elif (userInput == '3' or userInput == 'q'):
		print("\nNow quitting the program!\n")
		checker = 0
	else:
		os.system('clear')
		print("Incorrect input, try again!\n")
		menu()