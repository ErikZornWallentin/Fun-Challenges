/* 	
	Author: Erik Zorn - Wallentin 
	Created: May. 17 / 2016
	
	This program was created to polish and improve my C# programming skills.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
	
	The script is on Metric Conversion, if you don't know what that is, see below link:
    www.metric-conversions.org/length/kilometers-to-meters.htm
	
    The program will calculate Kilometre to Metre, and Metre to Kilometre.
    The program also handled error checking, it will give an error on blank input, or characters.
		
    It starts off by waiting for user input. 
    In both textbox's on the screen you input a number and hit "Calculate" button to calculate Metric Conversion!
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

namespace MetricConverter {
    public partial class MetricConverter : Form {
        private float result = 0f;


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
	            Console.WriteLine("Value is " + value);
                return true;
            }catch (FormatException){
                return false;
            }
        }

        /*-------
		Purpose: Checks if the string can be converted to float or not, will return a true or false and float result depending on situation
		Parameters: s (String input to check if it can be converted to float)
		Return: true / false (only return true if it was converted, false if string was not converted)
	    -------*/
        private Boolean tryParseFloat(String s) {
            try{
	            float value = float.Parse(s);
                result = value;
                return true;
            }catch (FormatException){
                result = 0f;
                return false;
            }
        }

        /*-------
		Purpose: Calculates conversion from Kilometre to Metre, and Metre to Kilometre.
		Parameters: NONE
		Return: NONE
	    -------*/
	    private void calculate(){
            String kilometreInput = textBox1.Text;
		    String metreInput = textBox2.Text;
		    float kilometreConverted = 0f;
		    float metreConverted = 0f;

            /* Error checking for certain input boundaries  */
            if (string.IsNullOrEmpty(kilometreInput)){
			    textBox1.Text = "1";
                label4.Text = "Input is empty! Put in a number to calculate!";
                label4.Location = new Point(20, 220);
		    }else{
                Boolean errorCheck = tryParseFloat(kilometreInput);
                if (errorCheck == true){
                    /* Calculate the conversions */
				    metreConverted = result / 0.001f;
                    
                    /* Show conversions to the user */
                    label4.Text = kilometreInput + "km = " + metreConverted +"m";
                    label4.Location = new Point(110, 220);
                } else {
                    label4.Text = "Please use numbers, not characters";
                    label4.Location = new Point(50, 220);
                }
            }

            if (string.IsNullOrEmpty(metreInput)){
			    textBox2.Text = "1";
                label5.Text = "Input is empty! Put in a number to calculate!";
                label5.Location = new Point(20, 250);
		    }else{
                Boolean errorCheck = tryParseFloat(metreInput);
                if (errorCheck == true){
                    /* Calculate the conversions */
				    kilometreConverted = result * 0.001f;
                    
                    /* Show conversions to the user */
                    label5.Text = metreInput + "m = " + kilometreConverted +"km";
                    label5.Location = new Point(110, 250);
                } else {
                    label5.Text = "Please use numbers, not characters";
                    label5.Location = new Point(50, 250);
                }
            }
        }

        public MetricConverter() {
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
