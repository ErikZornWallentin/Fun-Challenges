/* 	
	Author: Erik Zorn - Wallentin 
	Created: May. 17 / 2016
	
	This program was created to polish and improve my C# programming skills.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
	
	This is Ackermann Function, if you don't know what that is see link:
	https://en.wikipedia.org/wiki/Ackermann_function
	
	It starts off by waiting for user input in M or N text boxes.
	Once you give a numerical value, and press the calculate button it will calculate the result for you.
	If you use low values from 0-3 in M and N it will calculate it almost instantly.
	
	Java is not a very good language to calculate Ackermann Function in, as it cannot handle very high m or n values.
	The program also contains error checking in m and n values.
	
	Example use 1:
		M: 1
		N: 1
		Result: 3

	Example use 2:
		M: 2
		N: 2
		Result: 7
		
	Example use 3:
		M: 3
		N: 10
		Result: CRASH - Cannot handle this input
	
	Example use 4:
		M: 4
		N: 4
		Result: CRASH - Cannot handle this input
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

namespace AckermannFunctionRecursive {
    public partial class AckermannFunctionRecursive : Form {
        private int result = 0;
        private Boolean isCalculating = false;


        /*-------
		Purpose: Resets the program to the original state
		Parameters: NONE
		Return: NONE
	    -------*/
	    private void reset(){
		    textBox1.Text = "1";
		    textBox2.Text = "1";
		    label4.Text = "";
            label5.Text = "";
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
		Purpose: Ackermann Function using recursion, uses m and n integer values as input
		Parameters: m and n (integers from user)
		Return: result ( the result after calculating ackermann function recursively )
	    -------*/
	    private long ackermannFunc(long m, long n){
		    if (m == 0){
			    return n + 1;
		    }else if (n == 0){
			    return ackermannFunc(m - 1, 1);
		    }else {
			    return ackermannFunc(m - 1, ackermannFunc(m, n - 1));
		    }
	    }

        /*-------
		Purpose: Checks if Ackermann Function is already calculating to determine what to do next, and also handles the tim
		Parameters: NONE
		Return: NONE
	    -------*/
	    private void calculate(){
            if (isCalculating == false){
			    isCalculating = true;
                String m = textBox1.Text;
		        String n = textBox2.Text;
		        long mResult = 0;
		        long nResult = 0;
                Boolean mFound = false;
			    Boolean nFound = false;

                /* Error checking for certain input boundaries  */
                if (string.IsNullOrEmpty(m)){
			        textBox1.Text = "1";
                    label4.Text = "M input is empty! Put in a number to calculate!";
                    label4.Location = new Point(20, 220);
		        }else{
                    Boolean errorCheck = tryParseInt(m);
                    if (errorCheck == true){
				        mResult = result;
					    mFound = true;
                    } else {
                        label4.Text = "M input has characters, please use numbers";
                        label4.Location = new Point(20, 220);
                    }
                }

                if (string.IsNullOrEmpty(n)){
			        textBox2.Text = "1";
                    label5.Text = "N input is empty! Put in a number to calculate!";
                    label5.Location = new Point(20, 250);
		        }else{
                    Boolean errorCheck = tryParseInt(n);
                    if (errorCheck == true){
                        nResult = result;
					    nFound = true;
                    } else {
                        label5.Text = "N input has characters, please use numbers";
                        label5.Location = new Point(20, 250);
                    }
                }

                /* Recursively do Ackermann Function */
			    if (mFound == true && nFound == true){
				    var timer = System.Diagnostics.Stopwatch.StartNew();
                 
                    timer.Start();
				    long longResult = ackermannFunc(mResult, nResult);
                    timer.Stop();
                    var elapsed = timer.Elapsed;
				
				    label4.Text = "Time taken in milliseconds: " + elapsed.ToString("mm':'ss':'fff");
				    label4.Location = new Point(50, 220);
				    label5.Text = "Ackermann Function Result: " + longResult;
				    label5.Location = new Point(50, 250);
			    }
                isCalculating = false;
            }
        }

        public AckermannFunctionRecursive() {
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
