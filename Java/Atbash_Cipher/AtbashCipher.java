/* 	
	Author: Erik Zorn - Wallentin 
	Created: May. 12 / 2016
	
	This program was created to polish and improve my Java programming skills.
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

public class AtbashCipher {
	
	/* Setup size of the GUI */
	public static final int WIDTH = 400;
	public static final int HEIGHT = 400;
	
	private JLabel textLabel1;
	private JLabel textLabel2;
	private JLabel textLabel3;
	private JLabel textLabel4;
	private JLabel textLabel5;
	private JLabel textLabel6;
	private JLabel textLabel7;
	private JLabel textLabel8;
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
		textField1.setText("draziw");
	}
	
	/*-------
		Purpose: Checks if the string can be converted to int or not, will return a true or false and int result depending on situation
		Parameters: s (String input to check if it can be converted to int)
		Return: true / false (only return true if it was converted, false if string was not converted)
	-------*/
	public boolean checkIsCharacter(String s) {
		String regrex = ".*[0-9]+.*";
		
		if (s.matches(regrex)){
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
		String input = textField1.getText();
		String plainText = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		String atbashCipher = "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";
		String finalResult = "";
		boolean foundLetter = false;
		
		if (input.isEmpty()){
			textField1.setText("draziw");
			textLabel3.setText("Input is empty! Put in characters to cipher!");
			textLabel3.setBounds(15, 320, 350, 30);
		}else{
			/* Error checking for certain input boundaries, don't allow characters! Needs to be done before EVAL function is used */
			boolean errorCheck = checkIsCharacter(input);
			if (errorCheck == true){
				/* Cipher using English and Atbash */
				for (int i = 0; i < input.length(); i++){
					/* This loop checks for any characters that match the atbash cipher */
					for (int n = 0; n < plainText.length(); n++){
						char plainTextChar = plainText.charAt(n);
						char inputChar = input.charAt(i); 
						if (plainTextChar == inputChar){
							finalResult += atbashCipher.charAt(n);
							foundLetter = true;
						}
					}
					
					/* If we have no matches in the atbash cipher just add the character to the result */	
					if (!foundLetter){
						finalResult += input.charAt(i);
					}
					foundLetter = false;
				}
				textLabel3.setText("Cipher Result: " + finalResult);
				textLabel3.setBounds(30, 320, 300, 30);
			}else{
				textLabel3.setText("Please use characters, not numbers");
				textLabel3.setBounds(60, 320, 300, 30);
			}
		}
	}
	
    /*-------
	Purpose: Public default constructor for our class
	Parameters: VOID ( NOTHING )
	Return: VOID ( NOTHING )
	-------*/
    public AtbashCipher() {
        /* Create and set up the window */
        JFrame frame = new JFrame("AtbashCipher");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
 
        frame.setLayout(null);
 		
		textLabel1 = new JLabel("Atbash Cipher");
		textLabel1.setFont(new Font("Serif", Font.BOLD, 24));
		
		textLabel2 = new JLabel("Cipher input using Atbash and English:");
		textLabel2.setFont(new Font("Serif", Font.BOLD, 14));
		
		textLabel3 = new JLabel("TEST1");
		textLabel3.setFont(new Font("Serif", Font.BOLD, 15));
		textLabel3.setForeground (Color.red);
		
		textLabel4 = new JLabel("Atbash is a substitution cipher originally for the Hebrew alphabet.");
		textLabel4.setFont(new Font("Serif", Font.BOLD, 11));
		
		textLabel5 = new JLabel("It works by reversing the alphabet.");
		textLabel5.setFont(new Font("Serif", Font.BOLD, 12));
		
		textLabel6 = new JLabel("Here is the Atbash substitution table:");
		textLabel6.setFont(new Font("Serif", Font.BOLD, 12));
		
		textLabel7 = new JLabel("Plain: abcdefghijklmnopqrstuvwxyz");
		textLabel7.setFont(new Font("Serif", Font.BOLD, 12));

		textLabel8 = new JLabel("Cipher: zyxwvutsrqponmlkjihgfedcba");
		textLabel8.setFont(new Font("Serif", Font.BOLD, 12));
		
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
		frame.add(textLabel5);
		frame.add(textLabel6);
		frame.add(textLabel7);
		frame.add(textLabel8);
		
		frame.add(textField1);
        frame.add(b1);
        frame.add(b2);
		
		textLabel1.setBounds(120, 5, 350, 50);
		textLabel2.setBounds(70, 70, 270, 30);
		textLabel3.setBounds(170, 320, 300, 30);
		textLabel4.setBounds(10, 130, 350, 30);
		textLabel5.setBounds(80, 150, 350, 30);
		textLabel6.setBounds(70, 170, 350, 30);
		textLabel7.setBounds(70, 190, 350, 30);
		textLabel8.setBounds(70, 210, 350, 30);
		
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
                AtbashCipher gui = new AtbashCipher( );
				gui.reset();
            }
        });
    }
}