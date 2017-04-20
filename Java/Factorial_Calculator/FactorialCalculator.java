/* 	
	Author: Erik Zorn - Wallentin 
	Created: May. 12 / 2016
	
	This program was created to polish and improve my Java programming skills.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
	
	This is Factorial, if you don't know what that is see link:
	https://en.wikipedia.org/wiki/Factorial
		
	It starts off by waiting for user input. 
	In the textbox on the screen you input a number and hit "Calculate" button to calculate factorial!
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
 
public class FactorialCalculator {
	
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
		Purpose: Calculates factorial, also contains error checking to make sure the input was correct
		Parameters: NONE
		Return: NONE
	-------*/
	private void calculate(){
		String temp = textField1.getText();
		
		if (temp.isEmpty()){
			textField1.setText("1");
			textLabel3.setText("Input is empty! Put in a number to calculate!");
			textLabel3.setBounds(15, 290, 350, 30);
		}else{
			/* Error checking for certain input boundaries, don't allow characters! Needs to be done before EVAL function is used */
			boolean errorCheck = tryParseInt(temp);
			if (errorCheck == true){
				if (result < 0) {
					textLabel3.setText("Factorial Result: -1");
					textLabel3.setBounds(130, 290, 300, 30);
				} else if (result == 0) {
					textLabel3.setText("Factorial Result: 1");
					textLabel3.setBounds(130, 290, 300, 30);
				} else {
					int finalResult = result;

					while (result > 2) {
						result -= 1;
						finalResult *= result;
					}
					textLabel3.setText("Factorial Result: " + finalResult);
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
    public FactorialCalculator() {
        /* Create and set up the window */
        JFrame frame = new JFrame("FactorialCalculator");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 
        frame.setLayout(null);
 		
		textLabel1 = new JLabel("Factorial Calculator");
		textLabel1.setFont(new Font("Serif", Font.BOLD, 24));
		
		textLabel2 = new JLabel("Enter a value:");
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
		
		textLabel1.setBounds(100, 5, 250, 50);
		textLabel2.setBounds(90, 70, 200, 30);
		textLabel3.setBounds(170, 290, 300, 30);
		textField1.setBounds(185, 70, 150, 30);
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
                FactorialCalculator gui = new FactorialCalculator( );
				gui.reset();
            }
        });
    }
}