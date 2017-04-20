#=
	Author: Erik Zorn - Wallentin 
	Created: May. 11 / 2016
		
	This program was created to polish and improve my Julia programming skills during my spare time.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
		
	This is Factorial, if you don't know what that is see link:
	https://en.wikipedia.org/wiki/Factorial
		
	The program will convert the user input to a result in factorial.
		
	It starts off by waiting for user input with a menu displayed to the user.
	Menu:
		1) Calculate factorial
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
	println("1) Calculate factorial")
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
		factorialResult = 0
		factorialInput = 0
		input = "0"
		
		println("*** Calculate Factorial ***\n")
		print("Please enter value (example 4): ")
		input = chomp(readline())
		
		#Check if the input is acceptable
		errorCheck = checkIsNumber(input)
		if (errorCheck == 1)
			factorialInput = parse(Int, input)

			if (factorialInput < 0)
				factorialResult = -1
			elseif (factorialInput == 0)
				factorialResult = 1
			else
				result = factorialInput
	
				while (factorialInput > 2)
					factorialInput -= 1
					result *= factorialInput
				end
				factorialResult = result
			end
			println("Factorial result: ", factorialResult, "\n")
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