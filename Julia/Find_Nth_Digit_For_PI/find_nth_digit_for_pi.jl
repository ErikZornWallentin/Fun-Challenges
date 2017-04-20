#=
	Author: Erik Zorn - Wallentin 
	Created: May. 11 / 2016
		
	This program was created to polish and improve my Julia programming skills during my spare time.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
		
	This script uses Bailey-Borwein-Plouffe Formula (BBP Formula) to calculate PI to the nth digit.
		
	If you don't know the BBP formula see this wiki link:
	https://en.wikipedia.org/wiki/Bailey%E2%80%93Borwein%E2%80%93Plouffe_formula
		
	The program will convert the user input to a result in PI at nth digit.
		
	It starts off by waiting for user input with a menu displayed to the user.
	Menu:
		1) Calculate PI to nth digit *max 10 digits*
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
	println("The BBP Formula to Calculate PI")
	println("Please choose one of the following using (1,2):")
	println("1) Calculate PI to nth digit *max 10 digits*")
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
		pi = 0.0
		k = 0
		input = "0"
		
		println("*** The BBP Formula to Calculate PI ***\n")
		print("Please enter digit to calculate to (nth): ")
		input = chomp(readline())
		
		#Check if the input is acceptable
		errorCheck = checkIsNumber(input)
		if (errorCheck == 1)
			k = parse(Int, input)

			if (k <= 0)
				println("Error - Please give a number greater than 0!\n")
			elseif (k > 10)
				println("Error - Please give a number less than 10!\n")
			else
				#BBP formula, using integral SUM and base 16 for PI
				for i = 0:k-1
					pi += ( 1.0 / (16^i) ) * ( (4.0 / (8.0 * i + 1.0)) -
															(2.0 / (8.0 * i + 4.0)) -
															(1.0 / (8.0 * i + 5.0)) -
															(1.0 / (8.0 * i + 6.0)) )
				end
				#Set the output to only show the nth digit by using k variable
				println("PI result at nth digit: ", round(pi, k), "\n")
			end
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