/* 	
	Author: Erik Zorn - Wallentin 
	Created: May. 12 / 2016
	
	This program was created to polish and improve my Java programming skills.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
	
	This script uses Bailey-Borwein-Plouffe Formula (BBP Formula) to calculate PI to the nth digit.
		
	If you don't know the BBP formula see this wiki link:
	https://en.wikipedia.org/wiki/Bailey%E2%80%93Borwein%E2%80%93Plouffe_formula
		
	It starts off by waiting for user input. 
	In the textbox on the screen you input a number and hit "Calculate" button to calculate PI to nth digit!
	Make sure it is below 10 otherwise it will throw an error to say it should be between 0-10.	
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

import java.math.BigDecimal;
 
public class FindNthDigitForPI {
	
	/* Setup size of the GUI */
	public static final int WIDTH = 400;
	public static final int HEIGHT = 400;
	
	private JLabel textLabel1;
	private JLabel textLabel2;
	private JLabel textLabel3;
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
		textField1.setText("1");
	}
	
	/*-------
		Purpose: Checks if the string can be converted to int or not, will return a true or false and int result depending on situation
		Parameters: s (String input to check if it can be converted to int)
		Return: true / false (only return true if it was converted, false if string was not converted)
	-------*/
	public boolean tryParseInt(String s) {
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
		Purpose: Calculates PI to the nth digit, also contains error checking to make sure the input was correct
		Parameters: NONE
		Return: NONE
	-------*/
	private void calculate(){
		String temp = textField1.getText();
		float pi = 0f;
		int k = 0;
		
		if (temp.isEmpty()){
			textField1.setText("1");
			textLabel3.setText("Input is empty! Put in a number to calculate!");
			textLabel3.setBounds(15, 290, 350, 30);
		}else{
			/* Error checking for certain input boundaries, don't allow characters! Needs to be done before EVAL function is used */
			boolean errorCheck = tryParseInt(temp);
			if (errorCheck == true){
				k = result;
				
				/* BBP formula, using integral SUM and base 16 for PI */
				for (int i = 0; i < k; i++){
					pi += ( 1.0 / Math.pow( 16, i ) ) * ( (4.0 / (8.0 * i + 1.0)) -
															  (2.0 / (8.0 * i + 4.0)) -
															  (1.0 / (8.0 * i + 5.0)) -
															  (1.0 / (8.0 * i + 6.0)) );
				}
				
				/* Error checking for certain input boundaries, don't allow below 1 or above 10 and don't allow input to be blank! */
				if (k <= 0){
					textLabel3.setText("Make sure value is above 0!");
					textLabel3.setBounds(90, 290, 350, 30);
				}else if (k > 10){
					textLabel3.setText("Make sure value is 10 or BELOW!");
					textLabel3.setBounds(80, 290, 350, 30);
				}else{
					/* Set the output to only show the nth digit, we could allow it through if the user wants to see how far it works */
					BigDecimal roundOff;
					BigDecimal piRound = new BigDecimal(pi);
					roundOff = piRound.setScale(k, BigDecimal.ROUND_HALF_EVEN);
					textLabel3.setText("PI Result: " + roundOff);
					textLabel3.setBounds(130, 290, 300, 30);
				}
			}else{
				textLabel3.setText("Please use numbers, not characters");
				textLabel3.setBounds(60, 290, 300, 30);
			}
		}
	}
	
    /*-------
	Purpose: Public default constructor for our class
	Parameters: VOID ( NOTHING )
	Return: VOID ( NOTHING )
	-------*/
    public FindNthDigitForPI() {
        /* Create and set up the window */
        JFrame frame = new JFrame("FindNthDigitForPI");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 
        frame.setLayout(null);
 		
		textLabel1 = new JLabel("The BBP Formula to Calculate PI");
		textLabel1.setFont(new Font("Serif", Font.BOLD, 24));
		
		textLabel2 = new JLabel("Calculate PI to nth digit *Max 10 Digits*:");
		textLabel2.setFont(new Font("Serif", Font.BOLD, 14));
		
		textLabel3 = new JLabel("TEST1");
		textLabel3.setFont(new Font("Serif", Font.BOLD, 18));
		textLabel3.setForeground (Color.red);
		
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
		frame.add(textField1);
        frame.add(b1);
        frame.add(b2);
		
		textLabel1.setBounds(20, 5, 350, 50);
		textLabel2.setBounds(05, 70, 270, 30);
		textLabel3.setBounds(170, 290, 300, 30);
		textField1.setBounds(270, 70, 70, 30);
        b1.setBounds(150, 200, 100, 30);
        b2.setBounds(150, 240, 100, 30);
 
        /*Set the size and display of the window */
        frame.setSize(WIDTH, HEIGHT);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        /* Schedule a job for the event-dispatching thread: creating and showing this application's GUI */
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                FindNthDigitForPI gui = new FindNthDigitForPI( );
				gui.reset();
            }
        });
    }
}