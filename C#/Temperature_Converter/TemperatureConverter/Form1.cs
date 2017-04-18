/* 	
	Author: Erik Zorn - Wallentin 
	Created: May. 16 / 2016
	
	This program was created to polish and improve my C# programming skills.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
	
	The script is on Temperature Conversion, if you don't know what that is, see both links:
	http://www.rapidtables.com/convert/temperature/how-celsius-to-fahrenheit.htm
	http://www.metric-conversions.org/temperature/fahrenheit-to-celsius.htm
	
	The program will calculate Fahrenheit to Celsius, and Celsius to Fahrenheit.
	The program also handled error checking, it will give an error on blank input, or characters.
	Also it will solve any calculations before doing the conversion in the input box.
	
	It starts off by waiting for user input. 
	In both textbox's on the screen you input a number and hit "Calculate" button to calculate Temperature Conversion!
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

namespace TemperatureConverter {
    public partial class TemperatureConverter : Form {
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
		Purpose: Calculates conversion from Fahrenheit to Celsius, and Celsius to Fahrenheit.
		Parameters: NONE
		Return: NONE
	    -------*/
	    private void calculate(){
            String fahrenheitInput = textBox1.Text;
		    String celsiusInput = textBox2.Text;
		    float fahrenheitConverted = 0f;
		    float celsiusConverted = 0f;

            /* Error checking for certain input boundaries  */
            if (string.IsNullOrEmpty(fahrenheitInput)){
			    textBox1.Text = "1";
                label4.Text = "Input is empty! Put in a number to calculate!";
                label4.Location = new Point(20, 220);
		    }else{
                Boolean errorCheck = tryParseFloat(fahrenheitInput);
                if (errorCheck == true){
                    /* Calculate the conversions */
				    celsiusConverted = ( result - 32.0f ) / 1.8f;
                    
                    /* Show conversions to the user */
                    label4.Text = fahrenheitInput + "F = " + celsiusConverted +"C";
                    label4.Location = new Point(110, 220);
                } else {
                    label4.Text = "Please use numbers, not characters";
                    label4.Location = new Point(50, 220);
                }
            }

            if (string.IsNullOrEmpty(celsiusInput)){
			    textBox2.Text = "1";
                label5.Text = "Input is empty! Put in a number to calculate!";
                label5.Location = new Point(20, 250);
		    }else{
                Boolean errorCheck = tryParseFloat(celsiusInput);
                if (errorCheck == true){
                    /* Calculate the conversions */
				    fahrenheitConverted = ( result * 1.8f ) + 32f;
                    
                    /* Show conversions to the user */
                    label5.Text = celsiusInput + "C = " + fahrenheitConverted +"F";
                    label5.Location = new Point(110, 250);
                } else {
                    label5.Text = "Please use numbers, not characters";
                    label5.Location = new Point(50, 250);
                }
            }
        }

        public TemperatureConverter() {
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
