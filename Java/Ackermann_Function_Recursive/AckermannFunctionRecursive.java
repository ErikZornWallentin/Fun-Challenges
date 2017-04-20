/* 	
	Author: Erik Zorn - Wallentin 
	Created: May. 13 / 2016
	
	This program was created to polish and improve my Java programming skills.
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
		N: 11
		Result: CRASH - Cannot handle this input
	
	Example use 4:
		M: 4
		N: 4
		Result: CRASH - Cannot handle this input
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

import java.math.BigInteger;
 
public class AckermannFunctionRecursive {
	
	/* Setup size of the GUI */
	public static final int WIDTH = 400;
	public static final int HEIGHT = 400;
	
	private JLabel textLabel1;
	private JLabel textLabel2;
	private JLabel textLabel3;
	private JLabel textLabel4;
	private JLabel textLabel5;
	private JTextField textField1;
	private JTextField textField2;
	private JButton b1;
	private JButton b2;
	
	private BigInteger result = BigInteger.ZERO;
	
	private boolean isCalculating = false;
	
	/*-------
		Purpose: Resets the program to the original state
		Parameters: NONE
		Return: NONE
	-------*/
	private void reset(){
		textLabel4.setText("");
		textField1.setText("3");
		textField2.setText("6");
	}
	
	/*-------
		Purpose: Checks if the string can be converted to BigInteger or not, will return a true or false and BigInteger result depending on situation
		Parameters: s (String input to check if it can be converted to BigInteger)
		Return: true / false (only return true if it was converted, false if string was not converted)
	-------*/
	private boolean tryParseBigInteger(String s) {
		try {
			BigInteger value = new BigInteger(s);
			result = value;
			return true;
		}catch (NumberFormatException e) {
			result = BigInteger.ZERO;
			return false;
		}
	}
	
	/*-------
		Purpose: Ackermann Function using recursion, uses m and n integer values as input
		Parameters: m and n (integers from user)
		Return: result ( the result after calculating ackermann function recursively )
	-------*/
	private BigInteger ackermannFunc(BigInteger m, BigInteger n){
		if (m.equals(BigInteger.ZERO)){
			return n.add(BigInteger.ONE);
		}else if (n.equals(BigInteger.ZERO)){
			return ackermannFunc(m.subtract(BigInteger.ONE), BigInteger.ONE);
		}else {
			return ackermannFunc(m.subtract(BigInteger.ONE), ackermannFunc(m, n.subtract(BigInteger.ONE)));
		}
	}
	
	/*-------
		Purpose: Checks if Ackermann Function is already calculating to determine what to do next, and also handles the timer calculations
		Parameters: NONE
		Return: NONE
	-------*/
	private void calculate(){
		if (isCalculating == false){
			isCalculating = true;
			b1.setEnabled(false);
			b2.setEnabled(false);
			
			String m = textField1.getText();
			String n = textField2.getText();
			BigInteger mResult = BigInteger.ZERO;
			BigInteger nResult = BigInteger.ZERO;
			boolean mFound = false;
			boolean nFound = false;
			
			textLabel4.setText("Calculating... May take a long time to finish if you have high values");
			textLabel4.setBounds(15, 290, 350, 30);
			textLabel5.setText("");
			textLabel5.setBounds(15, 290, 350, 30);
			
			if (m.isEmpty()){
				textField1.setText("1");
				textLabel4.setText("M input is empty! Put in a number to calculate!");
				textLabel4.setBounds(5, 290, 400, 30);
			}else{
				/* Error checking for certain input boundaries, don't allow characters! Needs to be done before EVAL function is used */
				boolean errorCheck = tryParseBigInteger(m);
				if (errorCheck == true){
					mResult = result;
					mFound = true;
				}else{
					textLabel4.setText("M input has characters, please use numbers");
					textLabel4.setBounds(20, 290, 400, 30);
				}
			}
			
			if (n.isEmpty()){
				textField2.setText("1");
				textLabel5.setText("N input is empty! Put in a number to calculate!");
				textLabel5.setBounds(5, 320, 400, 30);
			}else{
				/* Error checking for certain input boundaries, don't allow characters! Needs to be done before EVAL function is used */
				boolean errorCheck = tryParseBigInteger(n);
				if (errorCheck == true){
					nResult = result;
					nFound = true;
				}else{
					textLabel5.setText("N input has characters, please use numbers");
					textLabel5.setBounds(20, 320, 400, 30);
				}
			}
			
			/* Recursively do Ackermann Function */
			if (mFound == true && nFound == true){
				long startTime = System.nanoTime();
				BigInteger bigResult = ackermannFunc(mResult, nResult);
				long endTime = System.nanoTime();
				long milliseconds = (endTime - startTime) / 1000000;  //divide by 1000000 to get milliseconds.
				
				textLabel4.setText("Time taken in milliseconds: " + milliseconds);
				textLabel4.setBounds(60, 290, 300, 30);
				textLabel5.setText("Ackermann Function Result: " + bigResult);
				textLabel5.setBounds(60, 320, 300, 30);
			}
			
			isCalculating = false;
			b1.setEnabled(true);
			b2.setEnabled(true);
		}
		
	}
	
    /*-------
	Purpose: Public default constructor for our class
	Parameters: VOID ( NOTHING )
	Return: VOID ( NOTHING )
	-------*/
    public AckermannFunctionRecursive() {
        /* Create and set up the window */
        JFrame frame = new JFrame("AckermannFunctionRecursive");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 
        frame.setLayout(null);
 		
		textLabel1 = new JLabel("Ackermann Function Recursive");
		textLabel1.setFont(new Font("Serif", Font.BOLD, 24));
		
		textLabel2 = new JLabel("M:");
		textLabel2.setFont(new Font("Serif", Font.BOLD, 14));
		
		textLabel3 = new JLabel("N:");
		textLabel3.setFont(new Font("Serif", Font.BOLD, 14));
		
		textLabel4 = new JLabel("TEST1");
		textLabel4.setFont(new Font("Serif", Font.BOLD, 18));
		textLabel4.setForeground (Color.red);
		
		textLabel5 = new JLabel("TEST2");
		textLabel5.setFont(new Font("Serif", Font.BOLD, 18));
		textLabel5.setForeground (Color.red);
		
		textField1 = new JTextField();
		textField2 = new JTextField();
       
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
		frame.add(textLabel5);
		frame.add(textField1);
		frame.add(textField2);
        frame.add(b1);
        frame.add(b2);
		
		textLabel1.setBounds(20, 5, 400, 50);
		textLabel2.setBounds(130, 70, 300, 30);
		textLabel3.setBounds(130, 130, 300, 30);
		textLabel4.setBounds(170, 290, 300, 30);
		textLabel4.setBounds(170, 320, 300, 30);
		textField1.setBounds(150, 70, 150, 30);
		textField2.setBounds(150, 130, 150, 30);
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
                AckermannFunctionRecursive gui = new AckermannFunctionRecursive( );
				gui.reset();
            }
        });
    }
}