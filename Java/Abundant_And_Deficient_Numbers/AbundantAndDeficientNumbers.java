/* 	
	Author: Erik Zorn - Wallentin 
	Created: May. 12 / 2016
	
	This program was created to polish and improve my Java programming skills.
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

import java.io.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

import java.awt.*;
import javax.swing.*;
import javax.swing.SwingUtilities;

import javax.swing.border.*;
import java.awt.event.*;
import javax.swing.event.*;
import javax.swing.event.DocumentListener;

import java.util.logging.*;
import javax.swing.JFileChooser;

import javax.swing.filechooser.*;

public class AbundantAndDeficientNumbers {
	
	/* Setup size of the GUI */
	public static final int WIDTH = 400;
	public static final int HEIGHT = 400;
	
	private JLabel textLabel1;
	private JLabel textLabel2;
	private JLabel textLabel3;
	private JLabel textLabel4;
	private JTextField textField1;
	private JButton b1;
	private JButton b2;
	
	private int result;
	
	/*-------
		Purpose: Resets the program to the original state
		Parameters: NONE
		Return: NONE
	-------*/
	private void reset(){
		textLabel3.setText("");
		textField1.setText("21");
	}
	
	/*-------
		Purpose: Checks if the string can be converted to int or not, will return a true or false and int result depending on situation
		Parameters: s (String input to check if it can be converted to int)
		Return: true / false (only return true if it was converted, false if string was not converted)
	-------*/
	private boolean tryParseInt(String s) {
		try {
			int value = Integer.parseInt(s);
			result = value;
			return true;
		}catch (NumberFormatException e) {
			result = 0;
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
		String input = textField1.getText();
		
		if (input.isEmpty()){
			textField1.setText("21");
			textLabel3.setText("Input is empty! Put in a number to calculate!");
			textLabel3.setBounds(60, 320, 350, 30);
		}else{
			/* Error checking for certain input boundaries, don't allow characters! Needs to be done before EVAL function is used */
			boolean errorCheck = tryParseInt(input);
			if (errorCheck == true){
				/* Check if number is abundant, deficient, or perfect */
				int divisorsSum = divisors(result);

				/* Error checking for certain input boundaries, don't allow below 1 or above 10 and don't allow input to be blank! */
				if (result <= 0){
					textLabel3.setText("Make sure value is above 0!");
					textLabel3.setBounds(110, 320, 350, 30);
				}else if (result > 1000){
					textLabel3.setText("Make sure value is 1000 or BELOW!");
					textLabel3.setBounds(80, 320, 350, 30);
				}else{
					if (divisorsSum < result*2){
						textLabel3.setText("Deficient");
						textLabel3.setBounds(170, 320, 350, 30);
					}else if (divisorsSum > result*2){
						int abundant = divisorsSum  - (result*2);
						textLabel3.setText("Abundant by " + abundant);
						textLabel3.setBounds(140, 320, 350, 30);
					}else{
						textLabel3.setText("Neither");
						textLabel3.setBounds(170, 320, 350, 30);
					}
				}
			}else{
				textLabel3.setText("Please use numbers, not characters");
				textLabel3.setBounds(80, 320, 300, 30);
			}
		}
	}
	
    /*-------
	Purpose: Public default constructor for our class
	Parameters: VOID ( NOTHING )
	Return: VOID ( NOTHING )
	-------*/
    public AbundantAndDeficientNumbers() {
        /* Create and set up the window */
        JFrame frame = new JFrame("AbundantAndDeficientNumbers");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 
        frame.setLayout(null);
 		
		textLabel1 = new JLabel("Abundant and Deficient Numbers");
		textLabel1.setFont(new Font("Serif", Font.BOLD, 24));
		
		textLabel2 = new JLabel("Check if number is abundant, deficient, or perfect:");
		textLabel2.setFont(new Font("Serif", Font.BOLD, 14));
		
		textLabel3 = new JLabel("TEST1");
		textLabel3.setFont(new Font("Serif", Font.BOLD, 15));
		textLabel3.setForeground (Color.red);
		
		textLabel4 = new JLabel("Numbers between 1-1000 only accepted");
		textLabel4.setFont(new Font("Serif", Font.BOLD, 13));
		
		textField1 = new JTextField();
		
		b1 = new JButton("Reset");
		b1.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e){
				reset();
			}
		});
        b2 = new JButton("Calculate");
		b2.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e){
				calculate();
			}
		});
		
		frame.add(textLabel1);
		frame.add(textLabel2);
		frame.add(textLabel3);
		frame.add(textLabel4);
		
		frame.add(textField1);
        frame.add(b1);
        frame.add(b2);
		
		textLabel1.setBounds(20, 5, 350, 50);
		textLabel2.setBounds(35, 70, 350, 30);
		textLabel3.setBounds(170, 320, 350, 30);
		textLabel4.setBounds(80, 130, 350, 30);
		
		textField1.setBounds(40, 100, 300, 30);
        b1.setBounds(150, 240, 100, 30);
        b2.setBounds(150, 280, 100, 30);
 
        /*Set the size and display of the window */
        frame.setSize(WIDTH, HEIGHT);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        /* Schedule a job for the event-dispatching thread: creating and showing this application's GUI */
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                AbundantAndDeficientNumbers gui = new AbundantAndDeficientNumbers( );
				gui.reset();
            }
        });
    }
}