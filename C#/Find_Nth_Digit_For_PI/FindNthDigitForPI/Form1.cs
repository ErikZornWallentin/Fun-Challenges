/* 	
	Author: Erik Zorn - Wallentin 
	Created: May. 17 / 2016
	
	This program was created to polish and improve my C# programming skills.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
	
	This script uses Bailey-Borwein-Plouffe Formula (BBP Formula) to calculate PI to the nth digit.
		
	If you don't know the BBP formula see this wiki link:
	https://en.wikipedia.org/wiki/Bailey%E2%80%93Borwein%E2%80%93Plouffe_formula
		
	It starts off by waiting for user input. 
	In the textbox on the screen you input a number and hit "Calculate" button to calculate PI to nth digit!
	Make sure it is below 10 otherwise it will throw an error to say it should be between 0-10.	
		
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

namespace FindNthDigitForPI {
    public partial class FindNthDigitForPI : Form {
        private int result = 0;


        /*-------
		Purpose: Resets the program to the original state
		Parameters: NONE
		Return: NONE
	    -------*/
	    private void reset(){
		    textBox1.Text = "1";
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
		Purpose: Calculates PI to the nth digit, also contains error checking to make sure the input was correct
		Parameters: NONE
		Return: NONE
	    -------*/
	    private void calculate(){
            String temp = textBox1.Text;
		    double pi = 0f;
            int k = 0;

            /* Error checking for certain input boundaries  */
            if (string.IsNullOrEmpty(temp)){
			    textBox1.Text = "1";
                label4.Text = "Input is empty! Put in a number to calculate!";
                label4.Location = new Point(20, 220);
		    }else{
                Boolean errorCheck = tryParseInt(temp);
                if (errorCheck == true){
                    k = result;
				
				    /* BBP formula, using integral SUM and base 16 for PI */
				    for (int i = 0; i < k; i++){
					    pi += ( 1.0 / Math.Pow( 16, i ) ) * ( (4.0 / (8.0 * i + 1.0)) -
															      (2.0 / (8.0 * i + 4.0)) -
															      (1.0 / (8.0 * i + 5.0)) -
															      (1.0 / (8.0 * i + 6.0)) );
				    }
				
				    /* Error checking for certain input boundaries, don't allow below 1 or above 10 and don't allow input to be blank! */
				    if (k <= 0){
					    label4.Text = "Make sure value is above 0!";
					    label4.Location = new Point(50, 220);
				    }else if (k > 10){
					    label4.Text = "Make sure value is 10 or BELOW!";
					    label4.Location = new Point(50, 220);
				    }else{
					    /* Set the output to only show the nth digit, we could allow it through if the user wants to see how far it works */
                        double piResult = Math.Round(pi, k, MidpointRounding.AwayFromZero);
					    label4.Text = "PI Result: " + piResult;
                        label4.Location = new Point(70, 220);
				    }
                } else {
                    label4.Text = "Please use numbers, not characters";
                    label4.Location = new Point(50, 220);
                }
            }
        }

        public FindNthDigitForPI() {
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
