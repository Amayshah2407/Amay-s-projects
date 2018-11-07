// Student Name: Amay Shah 
// Student Number: 20780897
// SYDE 121 02 Assignment 01
// File name: Lab02_01
// I hereby declare that this code, submitted for credit for this course. 
// SYDE 121 is a product of my own efforts. This code solution has not been plagariazed from other sources. 
// Project: Palindromic prime
// Purpose: Determine all the prime numbers, palindromic numbers and odd numbers out of those primes which exist under a given number inputted by a user. 
// Due date: 3rd October, 2018, Wednesday. 

#include <iostream>

using namespace std;

// function to find all primes and palindromics (that are less then 10,000)
int all_primes(int input){
	// loop to go through every number starting from 2 until the input number. If even one is divisble, the number is considered not prime. 
	for (int number = 2; number <= input; number++){
		bool divisor_works = true;
		
		// loop to test every divisor less than the test number
		for (int divisor = 2; divisor < number; divisor++){
			if (number % divisor == 0) // divisor is true till % of number is equal to 0
				divisor_works = false;
		}
		// if bool divisor_works is true - this means the number is a prime 
		if (divisor_works){
			cout << number << endl; // print prime number
			// separating prime number into their ndividual ones, tens, hundredths, thousands components to then reverse and test for palindrome. 
			int ones = number % 10;
			int tens = (number / 10) % 10; 
			int hundreds = (number / 100) % 10;
			int thousands = (number / 1000) % 10;
			int ten_thousands = (number / 10000) % 10;
			int hundred_thousands = (number /100000) % 10;
			
			// checking for palindromic primes
			if (number < 100 && number > 9){
				if (ones == tens)
					cout << number << " is also palindromic." << endl;
			}
			else if (number < 1000 && number > 99){ // for palindromics 100 - 999
				if (ones == hundreds)
					cout << number << " is also palindromic." << endl; // limit is 1000, numbers, above that won't be able to determine if number is palindromic or not. 
			}	

			// checking to see if sum is odd
			if ((ones + tens) % 2 != 0 // for primes 1 - 99
				|| (ones + tens + hundreds) % 2 != 0  // for primes 100 - 999
				|| (ones + tens + hundreds + thousands) % 2 != 0 // for primes 1000 - 9999
				|| (ones + tens + hundreds + thousands + ten_thousands) % 2 != 0 // for primes 10000 - 99999
				|| (ones + tens + hundreds + thousands + ten_thousands + hundred_thousands) % 2 != 0) // for primes 100000 - 999999. Limit of this function is till 1000000
			{
				cout << "The sum of digits for " <<  number << " is odd." << endl;
			}
		}
	}
	return 0;
}

int main(){

	int user_input; // declare user input variable
	cout << "Please enter a number greater than 1 to show primes less than or equal to your number: ";
	cin >> user_input;
	
	while(user_input <= 1){
		cout << "Please enter a number greater than 1:" << endl;
		cin >> user_input;
	}	

	all_primes(user_input);
	return 0;
}
