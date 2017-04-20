#=
	Author: Erik Zorn - Wallentin 
	Created: May. 11 / 2016
		
	This program was created to polish and improve my Julia programming skills during my spare time.
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
=#

#=
	Purpose: The main menu that is displayed to the user
	Parameters: NONE
	Return: NONE
=#
function menu()
	println("Please choose one of the following using (1,2):")
	println("1) Atbash Cipher")
	println("2) Quit the program (q)")
end

#=
	Purpose: Checks if the input is only numbers, and gives a correct return value ( success or failure ) depending on the result
	Parameters: input ( string input to be checked if it's only numbers )
	Return: result (EXIT_SUCESS is 0 or EXIT_FAILURE is 1 or higher)
=#
function checkIsNumber(input)
	for i = 1:endof(input)
		if (isdigit(input[i]) == false)
			println("Entered input is incorrect!\n")
			return 0
		end
	end
	
	return 1
end

#=
	Purpose: Checks if the input is only characters and gives a correct return value ( success or failure ) depending on the result
	Parameters: input ( char array input to be checked if it's only characters )
	Return: result (EXIT_SUCESS is 0 or EXIT_FAILURE is 1 or higher)
=#
function checkIsCharacter(input)
	for i = 1:endof(input)
		if (isdigit(input[i]) == true)
			println("Entered input is incorrect!\n")
			return 0
		end
	end
	
	return 1
end

#=
	Purpose: Converts plain english to atbash or atbash to plain english
	Parameters: input ( char array input to be checked if it's only characters )
	Return: NONE
=#
function cipher(input)
	plainText = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
	atbashCipher = "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA"
	finalResult = ""
	resultSlot = 0
	foundLetter = 0
	
	#Cipher using English and Atbash
	for i = 1:endof(input)
		#This loop checks for any characters that match the atbash cipher
		for n = 1:endof(plainText)
			if (plainText[n] == input[i])
				finalResult = finalResult * string(atbashCipher[n])
				resultSlot = resultSlot + 1
				foundLetter = 1
			end
		end
		#If we have no matches in the atbash cipher just add the character to the result
		if (foundLetter == 0)
			finalResult = finalResult * string(input[i])
			resultSlot = resultSlot + 1
		end
		foundLetter = 0
	end
	println("Cipher result: ", finalResult, "\n")
end
	
clear() = run(@unix ? `clear` : `cmd /c cls`)

userInput = "0"
checker = 1

clear()
menu()

while (checker == 1)
	print("Please enter a menu option: ")
	userInput = chomp(readline())

	if (userInput == "1")
		clear()
		
		#Variables we will use our formula on
		input = "0"
		
		println("*** Atbash Cipher ***")
		println("Example 1: INPUT -> draziw ---- OUTPUT -> wizard")
		println("Example 2: INPUT -> gsrh rh zm vcznkov ---- OUTPUT -> this is an example")
		print("Cipher input using Atbash and English: ")
		input = chomp(readline())
		
		#Check if the input is acceptable
		result = checkIsCharacter(input)
		if (result == 1)
			cipher(input)
		end
			
		menu()
	elseif (userInput == "2" || userInput == "q")
		println("\nNow quitting the program!\n")
		checker = 0
	else
		clear()
		println("Incorrect input, try again!\n")
		menu()
	end
end