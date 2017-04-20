#=
	Author: Erik Zorn - Wallentin 
	Created: May. 10 / 2016
		
	This program was created to polish and improve my Julia programming skills during my spare time.
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
=#

#=
	Purpose: The main menu that is displayed to the user
	Parameters: NONE
	Return: NONE
=#
function menu()
	println("Please choose one of the following using (1,2,3):")
	println("1) Fahrenheit to Celsius (F to C)")
	println("2) Celsius to Fahrenheit (C to F)")
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
		celsiusConverted = 0.0
		fahrenheitInput = 0.0
		input = "0"
		
		println("*** Converting Fahrenheit to Celsius (F to C) ***\n")
		print("Please enter Fahrenheit value: ")
		input = chomp(readline())
		
		#Check if the input is acceptable
		result = checkIsNumber(input)
		if (result == 1)
			fahrenheitInput = float(input)

			#Convert from Fahrenheit to Celsius
			celsiusConverted = ( fahrenheitInput - 32 ) / 1.8
			println("Celsius result: ", celsiusConverted, "\n")
		end
			
		menu()
	elseif (userInput == "2")
		clear()
		
		#Variables we will use our formula on
		fahrenheitConverted = 0
		celsiusInput = 0
		input = "0"
		
		println("*** Converting Celsius to Fahrenheit (C to F) ***\n")
		print("Please enter Celsius value: ")
		input = chomp(readline())
		
		#Check if the input is acceptable
		result = checkIsNumber(input)
		if (result == 1)
			celsiusInput = float(input)

			#Convert from Celsius to Fahrenheit
			fahrenheitConverted = ( celsiusInput * 1.8 ) + 32
			println("Fahrenheit result: ", fahrenheitConverted, "\n")
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