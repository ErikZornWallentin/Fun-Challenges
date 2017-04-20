#!/usr/bin/python

'''
	Author: Erik Zorn - Wallentin 
	Created: May. 10 / 2016
		
	This program was created to polish and improve my Python programming skills during my spare time.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
		
	This script is on Atbash Cipher, if you don't know what that is, see below link:
	https://en.wikipedia.org/wiki/Atbash
	
	The program will use atbash cipher to convert English to Atbash or Atbash to English.
		
	Atbash is a simple substitution cipher originally for the Hebrew alphabet, but possible with any known alphabet. 
	It emerged around 500-600 BCE. 
	It works by substituting the first letter of an alphabet for the last letter, the second letter for the second to last and so on, effectively reversing the alphabet. 
	Here is the Atbash substitution table:
	Plain:  abcdefghijklmnopqrstuvwxyz
	Cipher: zyxwvutsrqponmlkjihgfedcba
		
	Example Use of Atbash Cipher:
		foobar                                       ---> ullyzi
		wizard                                       ---> draziw
		gsrh rh zm vcznkov lu gsv zgyzhs xrksvi      ---> this is an example of the atbash cipher
		
	It starts off by waiting for user input with a menu displayed to the user.
	Menu:
		1) Atbash Cipher
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
	print("1) Atbash Cipher")
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
	Purpose: Checks if the input is only characters and gives a correct return value ( success or failure ) depending on the result
	Parameters: input ( char array input to be checked if it's only characters )
	Return: result (EXIT_SUCESS is 0 or EXIT_FAILURE is 1 or higher)
'''
def checkIsCharacter(input):
	
	for i in range(len(input)):
		if (input[i].isdigit() == True):
			print ("Entered input is incorrect!\n")
			return 0
	return 1

'''
	Purpose: Converts plain english to atbash or atbash to plain english
	Parameters: input ( char array input to be checked if it's only characters )
	Return: NONE
'''
def cipher(input):
	plainText = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
	atbashCipher = "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA"
	finalResult = ""
	resultSlot = 0
	foundLetter = 0
	
	#Cipher using English and Atbash
	for i in range(len(input)):
		#This loop checks for any characters that match the atbash cipher
		for n in range(len(plainText)):
			if (plainText[n] == input[i]):
				finalResult += atbashCipher[n]
				resultSlot = resultSlot + 1
				foundLetter = 1
			
		#If we have no matches in the atbash cipher just add the character to the result
		if (foundLetter == 0):
			finalResult += input[i]
			resultSlot = resultSlot + 1
		foundLetter = 0
	print("Cipher result: %s\n" % finalResult)

userInput = '0'
checker = 1

os.system('clear')
menu()

while (checker == 1):
	userInput = raw_input("Please enter a menu option: ")
	
	if (userInput == '1'):
		os.system('clear')
		
		#Variables that are used for error checking to see if input is a number or not 
		input = "0"
		
		print("*** Atbash Cipher ***\n")
		print("Example 1: INPUT -> draziw ---- OUTPUT -> wizard")
		print("Example 2: INPUT -> gsrh rh zm vcznkov ---- OUTPUT -> this is an example")
		input = raw_input("Cipher input using Atbash and English: ")
		
		#Check if the input is acceptable
		result = checkIsCharacter(input)
		if (result == 1):
			cipher(input)
		menu()
	elif (userInput == '2' or userInput == 'q'):
		print("\nNow quitting the program!\n")
		checker = 0
	else:
		os.system('clear')
		print("Incorrect input, try again!\n")
		menu()