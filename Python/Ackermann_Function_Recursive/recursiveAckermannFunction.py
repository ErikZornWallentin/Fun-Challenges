#/************************* recursiveAckermannFunction.py ****************************
# Student Name: Erik Zorn - Wallentin  Student Number: 0864583
# Date: Monday, Feb.22 / 2016          Course Name: CIS*4500
# I have exclusive control over this submission via my password.
# By including this statement in this header comment, I certify that:
#  1) I have read and understood the University policy on academic integrity;
#  2) I have completed the Computing with Integrity Tutorial on Moodle; and
#  3) I have achieved at least 80% in the Computing with Integrity Self Test.
# I assert that this work is my own. I have appropriately acknowledged any and all material
# (data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
# Furthermore, I certify that this assignment was prepared by me specifically for this course.
#****************************************************************************/

#This program recursively calls ackermann function to calculate an input (m,n)


import sys, timeit, datetime
import time
	
def ackermann(m, n):
    if m == 0:
        return n + 1
    elif n == 0:
        return ackermann(m - 1, 1)
    else:
        return ackermann(m - 1, ackermann(m, n - 1))

print ("Ackermann function recursive in Python: Enter two numbers (Below 4 for a quick result)")

#Get the user input and pass to ackermann function (recursion)
firstNum = input("Please enter number 1: ")
secondNum = input("Please enter number 2: ")

start_time = time.time()
print ackermann(firstNum, secondNum)
print("Ackermann Function took %s seconds to complete!" % (time.time() - start_time))


