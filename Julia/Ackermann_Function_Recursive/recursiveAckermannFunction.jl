#/************************* recursiveAckermannFunction.jl ****************************
# Student Name: Erik Zorn - Wallentin  Student Number: 0864583
# Date: Thur, Feb.18 / 2016            Course Name: CIS*4500
# I have exclusive control over this submission via my password.
# By including this statement in this header comment, I certify that:
#  1) I have read and understood the University policy on academic integrity;
#  2) I have completed the Computing with Integrity Tutorial on Moodle; and
#  3) I have achieved at least 80% in the Computing with Integrity Self Test.
# I assert that this work is my own. I have appropriately acknowledged any and all material
# (data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
# Furthermore, I certify that this assignment was prepared by me specifically for this course.
#****************************************************************************/

#This program iteratively calls ackermann function to calculate an input (m,n)
#=	Exampe use:
	M = 3
	N = 3
	Result = 61
=#

function ackermannRecursive( m, n )
    if m == 0
        return n + 1
    elseif n == 0
        return ackermannRecursive( m-1, 1)
    else
        return ackermannRecursive( m-1, ackermannRecursive( m, n-1 ) )
    end
end

@time a = 1
println("Ignore the above time, because Julia reports it as inaccurate on the first call so I made a dummy call")
println("Ackermann function recursive in Julia: Enter two numbers (Below 4 for a quick result)")

print("Please enter number 1: ")
firstNumber = chomp(readline())
firstNumber = parse(Int, firstNumber)

print("Please enter number 2: ")
secondNumber = chomp(readline())
secondNumber = parse(Int, secondNumber)

@time result = ackermannRecursive(firstNumber, secondNumber)
println("")
println("Ackermann Function Result: ", result)
