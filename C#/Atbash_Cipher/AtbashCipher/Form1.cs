/* 	
	Author: Erik Zorn - Wallentin 
	Created: May. 17 / 2016
	
	This program was created to polish and improve my C# programming skills.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
	
	This script is on Atbash Cipher, if you don't know what that is, see below link:
	https://en.wikipedia.org/wiki/Atbash
		
	The program will use atbash cipher to convert English to Atbash or Atbash to English.
		
	It starts off by waiting for user input.
	In textbox on the screen you input a word and hit "Cipher" button to cipher the word!
	You can reset the cipher at any time to get back to the original state that the program started in.
	Program handles error checking for incorrect input, also will preserve uppercase or lowercase of letter.
		
	Atbash is a simple substitution cipher originally for the Hebrew alphabet, but possible with any known alphabet. 
	It emerged around 500-600 BCE. 
	It works by substituting the first letter of an alphabet for the last letter, the second letter for the second to last and so on, effectively reversing the alphabet. 
	Here is the Atbash substitution table:
	Plain:  abcdefghijklmnopqrstuvwxyz
	Cipher: zyxwvutsrqponmlkjihgfedcba
		
	Example Use of Atbash Cipher:
		foobar                                       ---> ullyzi
		wizard                                       ---> draziw
		gsrh rh zm vcznkov lu gsv zgyzhs xrksvi      ---> this is an example of the atbash cipher
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

namespace AtbashCipher {
    public partial class AtbashCipher : Form {
        private int result = 0;


        /*-------
		Purpose: Resets the program to the original state
		Parameters: NONE
		Return: NONE
	    -------*/
	    private void reset(){
		    textBox1.Text = "draziw";
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
		Purpose: Checks if the string can be converted to int or not, will return a true or false and int result depending on situation
		Parameters: s (String input to check if it can be converted to int)
		Return: true / false (only return true if it was converted, false if string was not converted)
	    -------*/
	    public Boolean checkIsCharacter(String s) {
		    String pat = ".*[0-9]+.*";
		    // Instantiate the regular expression object.
            Regex r = new Regex(pat, RegexOptions.IgnoreCase);
            Match m = r.Match(s);
		    if (m.Success){
			    return false;
		    }
		
		    return true;
	    }

        /*-------
		Purpose: Cipher a language from one to another, this program will convert English to Atbash or Atbash to English
		Parameters: NONE
		Return: NONE
	    -------*/
	    private void calculate(){
            String input = textBox1.Text;
            String plainText = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		    String atbashCipher = "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";
		    String finalResult = "";
		    Boolean foundLetter = false;

            /* Error checking for certain input boundaries  */
            if (string.IsNullOrEmpty(input)){
			    textBox1.Text = "draziw";
                label4.Text = "Input is empty! Put in characters to cipher!";
                label4.Location = new Point(20, 220);
		    }else{
                Boolean errorCheck = checkIsCharacter(input);
                if (errorCheck == true){
                    /* Cipher using English and Atbash */
				    for (int i = 0; i < input.Length; i++){
					    /* This loop checks for any characters that match the atbash cipher */
					    for (int n = 0; n < plainText.Length; n++){
						    if (plainText[n] == input[i]){
							    finalResult += atbashCipher[n];
							    foundLetter = true;
						    }
					    }
					
					    /* If we have no matches in the atbash cipher just add the character to the result */	
					    if (!foundLetter){
						    finalResult += input[i];
					    }
					    foundLetter = false;
				    }

                    label4.Text = "Cipher Result: " + finalResult;
                    label4.Location = new Point(65, 220);
                } else {
                    label4.Text = "Please use characters, not numbers";
                    label4.Location = new Point(50, 220);
                }
            }
        }

        public AtbashCipher() {
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
