#!/usr/bin/python

'''
	Author: Erik Zorn - Wallentin 
	Created: May. 10 / 2016
		
	This program was created to polish and improve my Python programming skills during my spare time.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
		
	This is script is on Abundant and Deficient Number, if you don't know what that is, see below link:
	http://www.positiveintegers.org/IntegerTables/1-100
		
	The program will determine if the given number is abundant, deficient or neither.
	The program also has error checking and will only accept numbers between 1-1000.
	Any other input that is not a number between 1-1000 will throw and error.
		
	It starts off by waiting for user input with a menu displayed to the user.
	Menu:
		1) Abundant and Deficient Numbers
		2) Quit the program (q)
	Choosing an option from the menu will allow you to do a specific task and ask for more input.
	Once it gives you the result from the task it will return you to the menu.
	
	Example Use:
		Consider the number 21. Its divisors are 1, 3, 7 and 21, and their sum is 32. 
		Because 32 is less than 2 x 21, the number 21 is deficient. 
		Its deficiency is 2 x 21 - 32 = 10.
		
		The integer 12 is the first abundant number. Its divisors are 1, 2, 3, 4, 6, and 12, and their sum is 28. 
		Because 28 is greater than 2 x 12, the number 12 is abundant. 
		It's abundant by is 28 - 24 = 4.
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
	print("1) Abundant and Deficient Numbers")
	print("2) Quit the program (q)")

'''
	Purpose: Checks if the input is only numbers, and gives a correct return value ( success or failure ) depending on the result
	Parameters: input ( string input to be checked if it's only numbers )
	Return: result (EXIT_SUCESS is 0 or EXIT_FAILURE is 1 or higher)
'''
def checkIsNumber(input):
	periodCounter = 0
	
	for i in range(len(input)):
		if (input[i].isdigit() == False):
			print ("Entered input is incorrect!\n")
			return 0
	return 1

'''
	Purpose: Mods the given number "x" and if the remainder is 0 it will append it to the total sum
	Parameters: x (integer to be checked against )
	Return: sum (returns the sum of the divided numbers that have no remainder)
'''
def divisors(x):
	sum = 0

	for i in range(1, x+1):
		if (x % i == 0):
			#If you can divide the number into the given number, mod will spit out 0
			#We only care about numbers that can divide into the given number
			#Any numbers that give remainders we ignore
			
			#print("ADDING: %d" % i)
			sum += i
	#print("SUM: %d\n" % sum)
	return sum

userInput = '0'
checker = 1

os.system('clear')
menu()

while (checker == 1):
	userInput = raw_input("Please enter a menu option: ")
	
	if (userInput == '1'):
		os.system('clear')
		
		#Variables that are used for error checking to see if input is a number or not 
		divisorsSum = 0
		result = 0
		k = 0
		input = "0"
		errorCheck = 0
		
		print("*** Abundant and Deficient Numbers ***\n")
		print("Numbers between 1-1000 only accepted")
		input = raw_input("Check if number is abundant, deficient, or perfect: ")
		
		#Check if the input is acceptable
		errorCheck = checkIsNumber(input)
		if (errorCheck == 1):
			k = int(input)
			#Check if number is abundant, deficient, or perfect
			divisorsSum = divisors(k)
		
			if (k <= 0):
				print("Make sure value is above 0!\n")
			elif(k > 1000):
				print("Make sure value is 1000 or BELOW!\n")
			else:
				if (divisorsSum < k*2):
					print("Deficient\n")
				elif (divisorsSum > k*2):
					result = divisorsSum  - (k*2)
					print("Abundant by %d\n" % result)
				else:
					print("Neither\n")
		else:
			print("Please use numbers between 1-1000!\n")
		menu()
	elif (userInput == '2' or userInput == 'q'):
		print("\nNow quitting the program!\n")
		checker = 0
	else:
		os.system('clear')
		print("Incorrect input, try again!\n")
		menu()