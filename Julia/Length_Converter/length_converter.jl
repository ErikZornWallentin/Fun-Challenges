#=
	Author: Erik Zorn - Wallentin 
	Created: May. 11 / 2016
		
	This program was created to polish and improve my Julia programming skills during my spare time.
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
=#

#=
	Purpose: The main menu that is displayed to the user
	Parameters: NONE
	Return: NONE
=#
function menu()
	println("Please choose one of the following using (1,2,3):")
	println("1) Centimetre to Feet (cm to ft)")
	println("2) Feet to Centimetre (ft to cm)")
	println("3) Quit the program (q)")
end

#=
	Purpose: Checks if the input is only numbers, and gives a correct return value ( success or failure ) depending on the result
	Parameters: input ( string input to be checked if it's only numbers )
	Return: result (EXIT_SUCESS is 0 or EXIT_FAILURE is 1 or higher)
=#
function checkIsNumber(input)
	periodCounter = 0
	
	for i = 1:endof(input)
		if (input[i] == '-' && i == 1)
			#Do nothing as we will accept negative numbers
		elseif (input[i] == '.')
			periodCounter = periodCounter + 1
			if (periodCounter > 1)
				println("Entered input is not a number!\n")
				return 0
			end
		elseif (isdigit(input[i]) == false)
			println("Entered input is not a number!\n")
			return 0
		end
	end
	
	return 1
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
		feetConverted = 0.0
		centimetreInput = 0.0
		input = "0"
		
		println("*** Converting Centimetre to Feet (cm to ft) ***\n")
		print("Please enter Centimetre value: ")
		input = chomp(readline())
		
		#Check if the input is acceptable
		result = checkIsNumber(input)
		if (result == 1)
			centimetreInput = float(input)

			#Convert from Centimetre to Feet
			feetConverted = centimetreInput * 0.032808
			println("Feet result: ", feetConverted, "\n")
		end
			
		menu()
	elseif (userInput == "2")
		clear()
		
		#Variables we will use our formula on
		centimetreConverted = 0.0
		feetInput = 0.0
		input = "0"
		
		println("*** Feet to Centimetre (ft to cm) ***\n")
		print("Please enter Feet value: ")
		input = chomp(readline())
		
		#Check if the input is acceptable
		result = checkIsNumber(input)
		if (result == 1)
			feetInput = float(input)

			#Convert from Feet to Centimetre
			centimetreConverted = feetInput / 0.032808
			println("Centimetre result: ", centimetreConverted, "\n")
		end
		
		menu()
	elseif (userInput == "3" || userInput == "q")
		println("\nNow quitting the program!\n")
		checker = 0
	else
		clear()
		println("Incorrect input, try again!\n")
		menu()
	end
end