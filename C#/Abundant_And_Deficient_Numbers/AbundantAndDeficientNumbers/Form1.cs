/* 	
	Author: Erik Zorn - Wallentin 
	Created: May. 17 / 2016
	
	This program was created to polish and improve my C# programming skills.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
	
	This is script is on Abundant and Deficient Number, if you don't know what that is, see below link:
	http://www.positiveintegers.org/IntegerTables/1-100

	Example use's:
	Consider the number 21. Its divisors are 1, 3, 7 and 21, and their sum is 32. 
	Because 32 is less than 2 x 21, the number 21 is deficient. 
	Its deficiency is 2 x 21 - 32 = 10.

	The integer 12 is the first abundant number. Its divisors are 1, 2, 3, 4, 6, and 12, and their sum is 28. 
	Because 28 is greater than 2 x 12, the number 12 is abundant. 
	It's abundant by is 28 - 24 = 4.

	The program will determine if the given number is abundant, deficient or neither.
	The program also has error checking and will only accept numbers between 1-1000.
	Any other input that is not a number between 1-1000 will throw and error.

	It starts off by waiting for user input. 
	In both textbox's on the screen you input a number and hit "Calculate" button to determine what the number is.
	You can reset the converter at any time to get back to the original state that the program started in.
*/

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Text.RegularExpressions;

namespace AbundantAndDeficientNumbers {
    public partial class AbundantAndDeficientNumbers : Form {
        private int result = 0;


        /*-------
		Purpose: Resets the program to the original state
		Parameters: NONE
		Return: NONE
	    -------*/
	    private void reset(){
		    textBox1.Text = "21";
		    label4.Text = "";
	    }

        /*-------
		Purpose: Checks if the string can be converted to int or not, will return a true or false and float result depending on situation
		Parameters: s (String input to check if it can be converted to float)
		Return: true / false (only return true if it was converted, false if string was not converted)
	    -------*/
        private Boolean tryParseInt(String s) {
            try{
	            int value = Int32.Parse(s);
	            result = value;
                return true;
            }catch (FormatException){
                return false;
            }
        }

        /*-------
		Purpose: Mods the given number "x" and if the remainder is 0 it will append it to the total sum
		Parameters: x (number to be checked against )
		Return: sum (returns the sum of the divided numbers that have no remainder)
	    -------*/
	    private int divisors(int x){
		    int sum = 0;

		    for (int i = 1; i <= x; i++){
			    if (x % i == 0){
				    /* If you can divide the number into the given number, mod will spit out 0 */
				    /* We only care about numbers that can divide into the given number */
				    /* Any numbers that give remainders we ignore */

				    sum += i;
			    }
		    }

		    return sum;
	    }

        /*-------
		Purpose: Calculates if number is abundant, deficient, or neither.
					It also has error checking and shows result to the user.
		Parameters: NONE
		Return: NONE
	    -------*/
	    private void calculate(){
            String input = textBox1.Text;

            /* Error checking for certain input boundaries  */
            if (string.IsNullOrEmpty(input)){
			    textBox1.Text = "21";
                label4.Text = "Input is empty! Put in a number to calculate!";
                label4.Location = new Point(20, 220);
		    }else{
                Boolean errorCheck = tryParseInt(input);
                if (errorCheck == true){
                    /* Check if number is abundant, deficient, or perfect */
				    int divisorsSum = divisors(result);
				
				    /* Error checking for certain input boundaries, don't allow below 1 or above 10 and don't allow input to be blank! */
				    if (result <= 0){
					    label4.Text = "Make sure value is above 0!";
					    label4.Location = new Point(70, 220);
				    }else if (result > 1000){
					    label4.Text = "Make sure value is 1000 or BELOW!";
					    label4.Location = new Point(50, 220);
				    }else{
					    if (divisorsSum < result*2){
						    label4.Text = "Deficient";
						    label4.Location = new Point(130, 220);
					    }else if (divisorsSum > result*2){
						    int abundant = divisorsSum  - (result*2);
						    label4.Text = "Abundant by " + abundant;
						    label4.Location = new Point(100, 220);
					    }else{
						    label4.Text = "Neither";
						    label4.Location = new Point(130, 220);
					    }
				    }
                } else {
                    label4.Text = "Please use numbers, not characters";
                    label4.Location = new Point(50, 220);
                }
            }
        }

        public AbundantAndDeficientNumbers() {
            InitializeComponent();
            reset();
        }

        private void button1_Click(object sender, EventArgs e) {
               reset();
        }

        private void button2_Click(object sender, EventArgs e) {
               calculate();
        }
    }
}
