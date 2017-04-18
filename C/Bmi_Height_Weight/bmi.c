/************************* bmi.c ****************************
Student Name: Erik                        Student Number: 0864583
Date: Tue, Sept.19 / 2013                 Course Name: CIS1500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/

/*
	This program was created during my 1st year of Software Engineering at University of Guelph.
	It is a very simple script for an assignment in my CIS*1500 class.
	Since this is a script I did in 1st year of University, this is not a current representation of my skill after graduating University of Guelph in Software Engineering.
	
	The script is on Body mass index (BMI), if you don't know what that is, see below link:
	https://en.wikipedia.org/wiki/Body_mass_index

	The program will get the height and weight from the user, and after print out all the information back to the user.
	The last thing it will print out is the BMI algorithm that was given in class by the professor and was implemented into the code.
	
	Please see the README.txt for more information!
*/

#include <stdio.h>

int main (){
	double weight = 0;
	double height = 0;	
	double bmi = 0;
	
	/* Get the height and the weight from the user */
	printf("Please enter a height: ");
	scanf("%lf",&height);
	printf("Please enter a weight: ");
	scanf("%lf",&weight);
	
	/* Printing out all the information to the screen */	
	printf("Height: %.0lf\n", height);
	printf("Weight: %.0lf\n", weight);
	
	/* Calculate the BMI code, the algorithm was given in class */
	bmi = ( weight / ( height * height ) ) * 703;
	printf("BMI: %.4lf\n", bmi);
	
	return 0;
}

