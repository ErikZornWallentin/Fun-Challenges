****************************************************
Erik Zorn-Wallentin	 Accuracy_Vs_Resilience_Calculator.html
Thursday, March. 17 / 2016
****************************************************

**********************
Compilation
**********************

JavaScript runs on a web browser so your file needs to be in .html ending format and open it in any web browser!

*********************************************************************
Running the program(s) and GENERAL INFO FOR ANY READER 
*********************************************************************

**IMPORTANT READ FOR USER**

The was created during my 3rd year of University.
This was part of a personal project that I did on my spare time.
I needed to calculate an attacker accuracy vs defender resilience, and this program does just that.
I pulled inspiration from a theorycrafter that posted their "guess" of what the system is in Summoners War (Mobile App).
I did modifications and changed the system a bit to my own needs, his also does not consider every possibility and was not complete.
Mine is fully complete and handles every case, with simpler logic and better modifications.

Understanding the Calculator:
	
	
	Accuravy Vs Resililence
		Chances of resisting debuff is either 10% or (Resilience - Accuracy), whichever is higher.
		Chances of applying debuff is 90% or 100% - (Resilience - Accuracy).
		There will always be at least 10% chance of resisting debuff, or 10% to land debuff depending on situation.
		
	Debuff Definition: A negative "Status Effect" on any monster that gives them detrimental effects.
		Example: Power Down Status Effect on a monster gives the monster -30% power, as a negative effect to the monster Power attribute.
		
	The purpose of this calculator is when a monster wants to put a "Debuff" on another monster, this function will determine if is activated,
	if it passes the activation test and calculates if the debuff will land on the enemy monster or not depending on the attackers accuracy vs 
	the defender resilience.
		
	This is a visual representation of what is happening in the code, and for any developer / user to also understand what is happening. 
		
	*** The number codes from Applied - # or Failed - # are for the programmer to know where it was a success or fail in the code quickly. ***
		
	Activation Chance: The value to determine the skill's activation chance. Needs to pass this check to even check attacker acc vs defender resilience.
	Activation Random Number: The value that goes against the Activation Chance value. This is randomly rolled or allows for user input.
	Debuff Effect Random Number: The value that goes against the status effect chance of landing. This is randomly rolled or allows for user input.
	Attack Accuracy: A value that is between 0-100. Higher Accuracy of attacker means higher chance of debuff applying.
	Defender Resilience: A value that is between 0-100. Higher resilience of defender means less chance of a debuff applying.

Brief Description:
	- Chances of resisting debuff is either 10% or (Resilience - Accuracy), whichever is higher.
	- Chances of applying debuff is 90% or 100% - (Resilience - Accuracy).
	- There will always be at least 10% chance of resisting debuff / land debuff depending on situation. 
	
Generate Activation Number (Check Box): If it is checked it will automatically generate a new Activation Random Number for you.
Geberate Debuff Effect Number (Check Box): If it is checked it will automatically generate a new Debuff Effect Random Number for you.

Output Results:
	It will let you know if you passed the activation check or not, if you fail it will automatically show failed on everything.
	If the activation check passed, it will put attacker accuracy vs defender resilience against each other.
	It will show if the debuff was applied or not, and give a number code back to show where in the code it passed or failed.
	
Example Use 1:
	Activation Chance: 100
	Activation Random Number: 27
	Debuff Effect Random Number: 90
	Attacker Accuracy: 92
	Defender Resilience: 100
	Generate Activation Number: NOT CHECKED
	Generate Debuff Effect Number: NOT CHECKED
	
	--- OUTPUT ---
	Activation Check: PASS
	Debuff Applied: DEBUFF APPLIED - 3
	Debuff Chance: 90%
	
Example Use 2:	
	Activation Chance: 100
	Activation Random Number: 27
	Debuff Effect Random Number: 20
	Attacker Accuracy: 29
	Defender Resilience: 100
	Generate Activation Number: NOT CHECKED
	Generate Debuff Effect Number: NOT CHECKED
	
	--- OUTPUT ---
	Activation Check: PASS
	Debuff Applied: DEBUFF APPLIED - 1
	Debuff Chance: 29%
		


**************************
Bibliography / References
**************************

http://summonerswar.wikia.com/wiki/User:M%CD%A2ystr%CD%A2ile/Accuracy-Resistance_Calculator

*****************
Known Limitations
*****************

NONE


