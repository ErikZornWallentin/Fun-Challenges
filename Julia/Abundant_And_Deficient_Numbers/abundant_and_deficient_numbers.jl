#=
	Author: Erik Zorn - Wallentin 
	Created: May. 11 / 2016
		
	This program was created to polish and improve my Julia programming skills during my spare time.
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
=#

#=
	Purpose: The main menu that is displayed to the user
	Parameters: NONE
	Return: NONE
=#
function menu()
	println("Please choose one of the following using (1,2):")
	println("1) Abundant and Deficient Numbers")
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
	Purpose: Mods the given number "x" and if the remainder is 0 it will append it to the total sum
	Parameters: x (integer to be checked against )
	Return: sum (returns the sum of the divided numbers that have no remainder)
=#
function divisors(x)
	sum = 0

	for i = 1:x+1
		if (x % i == 0)
			#If you can divide the number into the given number, mod will spit out 0
			#We only care about numbers that can divide into the given number
			#Any numbers that give remainders we ignore
			
			#println("ADDING: %d" % i)
			sum += i
		end
	end
	
	#println("SUM: %d\n" % sum)
	return sum
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
		divisorsSum = 0
		result = 0
		k = 0
		input = "0"
		errorCheck = 0
		
		println("*** Abundant and Deficient Numbers ***")
		println("Numbers between 1-1000 only accepted")
		print("Check if number is abundant, deficient, or perfect: ")
		input = chomp(readline())
		
		#Check if the input is acceptable
		errorCheck = checkIsNumber(input)
		if (errorCheck == 1)
			k = parse(Int, input)
			#Check if number is abundant, deficient, or perfect
			divisorsSum = divisors(k)
		
			if (k <= 0)
				println("Make sure value is above 0!\n")
			elseif(k > 1000)
				println("Make sure value is 1000 or BELOW!\n")
			else
				if (divisorsSum < k*2)
					println("Deficient\n")
				elseif (divisorsSum > k*2)
					result = divisorsSum  - (k*2)
					println("Abundant by ", result, "\n")
				else
					println("Neither\n")
				end
			end
		else
			println("Please use numbers between 1-1000!\n")
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