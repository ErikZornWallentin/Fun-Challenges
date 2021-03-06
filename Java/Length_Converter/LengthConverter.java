/* 	
	Author: Erik Zorn - Wallentin 
	Created: May. 12 / 2016
	
	This program was created to polish and improve my Java programming skills.
	This was created in several languages in my repository of code to show the differences in each language with the same functionality.
	
	The script is on Length Conversion, if you don't know what that is, see below link:
	http://www.metric-conversions.org/length/centimeters-to-feet.htm
		
	The program will calculate Centimetre to Feet, and Feet to Centimetre.
	The program also handled error checking, it will give an error on blank input, or characters.
		
	It starts off by waiting for user input. 
	In both textbox's on the screen you input a number and hit "Calculate" button to calculate Length Conversion!
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
 
public class LengthConverter {
	
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
	
	private float result;
	
	/*-------
		Purpose: Resets the program to the original state
		Parameters: NONE
		Return: NONE
	-------*/
	private void reset(){
		textLabel4.setText("");
		textLabel5.setText("");
		textField1.setText("1");
		textField2.setText("1");
	}
	
	/*-------
		Purpose: Checks if the string can be converted to float or not, will return a true or false and float result depending on situation
		Parameters: s (String input to check if it can be converted to float)
		Return: true / false (only return true if it was converted, false if string was not converted)
	-------*/
	public boolean tryParseFloat(String s) {
		try {
			float value = Float.parseFloat(s);
			result = value;
			return true;
		}catch (NumberFormatException e) {
			result = 0f;
			return false;
		}
	}
	
	/*-------
		Purpose: Calculates conversion from Centimetre to Feet, and Feet to Centimetre.
		Parameters: NONE
		Return: NONE
	-------*/
	private void calculate(){
		String centimetreInput = textField1.getText();
		String feetInput = textField2.getText();
		float centimetreConverted = 0f;
		float feetConverted = 0f;
		
		if (centimetreInput.isEmpty()){
			textField1.setText("1");
			textLabel4.setText("Input is empty! Put in a number to calculate!");
			textLabel4.setBounds(15, 290, 350, 30);
		}else{
			centimetreInput = textField1.getText();

			/* Error checking for certain input boundaries, don't allow characters! Needs to be done before EVAL function is used */
			boolean errorCheck = tryParseFloat(centimetreInput);
			if (errorCheck == true){
				/* Calculate the conversions */
				feetConverted = result * 0.032808f;

				/* Show conversions to the user */
				textLabel4.setText(centimetreInput + "cm = " + feetConverted +"ft");
				textLabel4.setBounds(150, 290, 300, 30);
			}else{
				textLabel4.setText("Please use numbers, not characters");
				textLabel4.setBounds(60, 290, 300, 30);
			}
		}
		
		if (feetInput.isEmpty()){
			textField2.setText("1");
			textLabel5.setText("Input is empty! Put in a number to calculate!");
			textLabel5.setBounds(15, 320, 350, 30);
		}else{
			feetInput = textField2.getText();

			/* Error checking for certain input boundaries, don't allow characters! Needs to be done before EVAL function is used */
			boolean errorCheck = tryParseFloat(feetInput);
			if (errorCheck == true){
				/* Calculate the conversions */
				centimetreConverted = result / 0.032808f;

				/*  Show conversions to the user */
				textLabel5.setText(feetInput + "ft = " + centimetreConverted +"cm");
				textLabel5.setBounds(150, 320, 300, 30);
			}else{
				textLabel5.setText("Please use numbers, not characters");
				textLabel5.setBounds(60, 320, 300, 30);
			}
		}
	}
	
    /*-------
	Purpose: Public default constructor for our class
	Parameters: VOID ( NOTHING )
	Return: VOID ( NOTHING )
	-------*/
    public LengthConverter() {
        /* Create and set up the window */
        JFrame frame = new JFrame("LengthConverter");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 
        frame.setLayout(null);
 		
		textLabel1 = new JLabel("Length Converter");
		textLabel1.setFont(new Font("Serif", Font.BOLD, 24));
		
		textLabel2 = new JLabel("Centimetre to Feet (cm to ft):");
		textLabel2.setFont(new Font("Serif", Font.BOLD, 14));
		
		textLabel3 = new JLabel("Feet to Centimetre (ft to cm):");
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
		
		textLabel1.setBounds(80, 5, 250, 50);
		textLabel2.setBounds(10, 70, 200, 30);
		textLabel3.setBounds(10, 130, 200, 30);
		textLabel4.setBounds(170, 290, 300, 30);
		textLabel5.setBounds(170, 320, 300, 30);
		textField1.setBounds(210, 70, 150, 30);
		textField2.setBounds(210, 130, 150, 30);
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
                LengthConverter gui = new LengthConverter( );
				gui.reset();
            }
        });
    }
}