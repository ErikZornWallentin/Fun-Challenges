#/************************* iterativeAckermannFunction.py ****************************
# Student Name: Erik Zorn - Wallentin  Student Number: 0864583
# Date: Thur, Feb.18 / 2016           Course Name: CIS*4500
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

class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def isEmpty(self):
        return (self.items == [])

import sys, timeit, datetime
import time
	
def ackermann(tempM, tempN):
	m = tempM
	n = tempN
	s = Stack()
	s.push(m)
	while not s.isEmpty():
		m = s.pop()
		if m == 0:
			n = n + 1
		elif n == 0:
			s.push(m-1)
			n = 1
		else:
			s.push(m-1)
			s.push(m)
			n = n - 1
	return n

print ("Ackermann function iterative in Python: Enter two numbers (Below 4 for a quick result)")

#Get the user input and pass to ackermann function (recursion)
firstNum = input("Please enter number 1: ")
secondNum = input("Please enter number 2: ")

start_time = time.time()
print ackermann(firstNum, secondNum)
print("Ackermann Function took %s seconds to complete!" % (time.time() - start_time))


