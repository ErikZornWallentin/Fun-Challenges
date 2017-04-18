/************************* simple_math_flashcards.c ****************************
Student Name: Erik Zorn - Wallentin       Student Number: 0864583
Date: Wed, Nov.06 / 2013                  Course Name: CIS1500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/

**********************
Compilation
**********************

To compile the program use the terminal and type in "gcc simple_math_flashcards.c -o simple_math_flashcards" into the terminal as long as you are in the same directory as the files.
Gcc (GNU Compiler Collection) is a compiler that will compile the c file into a binary executable (.exe file) using the above command.

**********************
Running the program(s) 
**********************

Type ./simple_math_flashcards or simple_math_flashcards to run the program in the terminal as long as you are in the same directory as the files.

****************************
GENERAL INFO FOR ANY READER 
****************************

**IMPORTANT READ FOR USER**

This program was created during my 1st year of Software Engineering at University of Guelph.
It is a very simple script for an assignment in my CIS*1500 class.
Since this is a script I did in 1st year of University, this is not a current representation of my skill after graduating University of Guelph in Software Engineering.

The script is a flashcard game that allows you to choose what type of math you want to do in take several "tests" in that category of math.

When the program runs it will ask the user for input for multiplication, addition or quit.
You need to input the proper data such as m,a, or q to advance to the next menu.
When you pick a menu option such as m, you will now play 5 rounds of a flashcard game.
The user should input the correct data and it will bring you back to the menu after 5 rounds.
The same game is played for the addition part, and if you press q for quit you will exit the program.
If you input incorrect data during flashcard game it will loop till you input the correct data.
Please follow the rest of the instructions in the program.

**************************
Bibliography / References
**************************


*****************
Known Limitations
*****************

I have a few known limitations in this program. For the very first menu error checking it will stay in a loop
until it sees a menu option(m,a,d,s,q) and if it doesn't it will output an error for a second and clear the 
screen as the error checking for an infinite loop. My clear screen is my error checking.

The next known limitation is the defensive programming for the functions like the wrong input in the addition
or division, etc. It will give an error input when it is not a number, but it does not care about when the user
only inputs the enter key. Otherwise I believe it error checks everything else.

My last known limitation is my division function. If there is a decimal form in the answer it does not care
about the decimal part for the answer. Also if the divison happens to be 6 / 0, in real life that is not 
possible and I auto set the answer in the program to equal 0. 

Program has sleep commands, please be patient and allow the display to catch up to your input.


