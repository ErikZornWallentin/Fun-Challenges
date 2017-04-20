#=
	Author: Erik Zorn - Wallentin 
	Created: May. 11 / 2016
		
	This program was created to polish and improve my Julia programming skills during my spare time.
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
=#

#=
	Purpose: The main menu that is displayed to the user
	Parameters: NONE
	Return: NONE
=#
function menu()
	println("Please choose one of the following using (1,2,3):")
	println("1) Kilometre to Metre (km to m)")
	println("2) Metre to Kilometre (m to km)")
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
		metresConverted = 0.0
		kilometresInput = 0.0
		input = "0"
		
		println("*** Converting Kilometre to Metre (km to m) ***\n")
		print("Please enter Kilometre value: ")
		input = chomp(readline())
		
		#Check if the input is acceptable
		result = checkIsNumber(input)
		if (result == 1)
			kilometresInput = float(input)

			#Convert from Kilometre to Metre
			metresConverted = kilometresInput / 0.001
			println("Metre result: ", metresConverted, "\n")
		end
			
		menu()
	elseif (userInput == "2")
		clear()
		
		#Variables we will use our formula on
		kilometresConverted = 0
		metresInput = 0
		input = "0"
		
		println("*** Metre to Kilometre (m to km) ***\n")
		print("Please enter Metre value: ")
		input = chomp(readline())
		
		#Check if the input is acceptable
		result = checkIsNumber(input)
		if (result == 1)
			metresInput = float(input)

			#Convert from Metre to Kilometre
			kilometresConverted = metresInput * 0.001
			println("Kilometre result: ", kilometresConverted, "\n")
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