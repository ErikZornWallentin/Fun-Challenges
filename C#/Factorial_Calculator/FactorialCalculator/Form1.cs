/* 	
	Author: Erik Zorn - Wallentin 
	Created: May. 17 / 2016
	
	This program was created to polish and improve my C# programming skills.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
	
	This is Factorial, if you don't know what that is see link:
	https://en.wikipedia.org/wiki/Factorial
		
	It starts off by waiting for user input. 
	In the textbox on the screen you input a number and hit "Calculate" button to calculate factorial!
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

namespace FactorialCalculator {
    public partial class FactorialCalculator : Form {
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
		Purpose: Calculates factorial, also contains error checking to make sure the input was correct
		Parameters: NONE
		Return: NONE
	    -------*/
	    private void calculate(){
            String temp = textBox1.Text;

            /* Error checking for certain input boundaries  */
            if (string.IsNullOrEmpty(temp)){
			    textBox1.Text = "1";
                label4.Text = "Input is empty! Put in a number to calculate!";
                label4.Location = new Point(20, 220);
		    }else{
                Boolean errorCheck = tryParseInt(temp);
                if (errorCheck == true){
                    if (result < 0) {
					    label4.Text = "Factorial Result: -1";
                        label4.Location = new Point(70, 220);
				    } else if (result == 0) {
					    label4.Text = "Factorial Result: 1";
                        label4.Location = new Point(70, 220);
				    } else {
					    int finalResult = result;

					    while (result > 2) {
						    result -= 1;
						    finalResult *= result;
					    }
					    label4.Text = "Factorial Result: " + finalResult;
                        label4.Location = new Point(70, 220);
				    }
                } else {
                    label4.Text = "Please use numbers, not characters";
                    label4.Location = new Point(50, 220);
                }
            }
        }

        public FactorialCalculator() {
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
