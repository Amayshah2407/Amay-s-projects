// Student Name: Amay Shah
// Student Number: 20780897
// SYDE 121 Lab Assignment: 5
// Filename: Lab 5.cpp
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts.  This coded solution has
// not been plagiarized from other sources and has not been knowingly plagiarized by others.
// Project:  Creating a tic tac toe game for a 4 by 4 table.
// Purpose: Using arrays and functions to create a game which allows users to play tic tac toe in 4 by 4 table.
// I tested the code by inputting integers between 1 and 16 (included) and it working, and obtaining a result by getting all 4 in a row and checking whether it displays the user won. I then checked if it gives an error if a number other than 1 to 16 is entered or if it is entered in something already takes and it works.
// I also played multiple games to see if it gives the correct stats after mutliple games. 
// Due Date: Friday, October 26th
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string matrix[5][5]; // Creating multidimensional array.
int games = 1, x_move, o_move; // provides all the variables present.
int x_wins = 0, o_wins = 0, ties = 0; // initializing all the variables.
char again, winner = '*'; //play again is a function used to either play the game again or not. * is a placeholder.

void print_matrix() {
    for (int i = 1; i < 5; i++)
    {  for (int j = 1; j < 5; j++) // creates 4 columns and 4 rows through the use of a loop.
    {
        if (matrix[i][j].length() == 1) //
    {
        cout << matrix[i][j] << "      "; // contains one more space than if length is not 1, in this case 2 so that it is aligned.
            } else {
                cout << matrix[i][j] << "     ";
            }
        }
        cout << endl;
    }
}

void start() { // function is a part of processing. It checks who starts and whether play can continue. If some conditions arent met then gives output of some other input or inputting something else.
    int count = 1; //
    
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 5; j++) {
            matrix[i][j] = to_string(count++); //converts the integer into a string.
        }
    }
    
    x_move = (games % 2); // determines who gets to go first. First game has X go first.
    o_move = 1 - x_move; // all even games have O go first.
    winner = '*'; // Placeholder.
    print_matrix();
}

bool not_full() { // checks if the all the spots aren't taken and there are still places users can play.
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (matrix[i][j] != "X" && matrix[i][j] != "O") {
                return true;
            }
        }
    }
    
    return false;
}

void check_winner() { // the function processes the input and provides an output. Here it checks the matrix to give the output whether someone won or not.
    string val;
    bool flag;
    
    // Checks horizontally if all in one line are X or O and if yes declares that user the winner.
    for (int i = 1; i <= 4; i++) {
        val = matrix[i][1]; // checks here if all are the same as the first number (first row and column)
        flag = true;
        for (int j = 2; j <= 4; j++) {
            if (val != matrix[i][j]) {
                flag = false;
            }
        }
        if (flag) { // if true it declares the winner depending on what the first number is.
            if (val == "X") {
                winner = 'X';
            } else {
                winner = 'O';
            }
            return;
        }
    }
    
    // Checks vertically if all in one line are X or O and if yes declares that user the winner.
    for (int i = 1; i <= 4; i++) {
        val = matrix[1][i];
        flag = true;
        for (int j = 2; j <= 4; j++) {
            if (val != matrix[j][i]) {
                flag = false;
            }
        }
        if (flag) {
            if (val == "X") {
                winner = 'X';
            } else {
                winner = 'O';
            }
            return;
        }
    }
    
    val = matrix[1][1];     // Check diagonal from right to left
    flag = true;
    for (int i = 2; i <= 4; i++) {
        if (val != matrix[i][i]) {
            flag = false;
        }
    }
    if (flag) {
        if (val == "X") {
            winner = 'X';
        } else {
            winner = 'O';
        }
        return;
    }
    
    val = matrix[1][4];     // Check diagonal from right to left
    flag = true;
    for (int i = 2; i <= 4; i++) {
        if (val != matrix[i][5 - i]) {
            flag = false;
        }
    }
    if (flag) {
        if (val == "X") {
            winner = 'X';
        } else {
            winner = 'O';
        }
        return;
    }
}

void moves() {
    int location;
    
    do {
        if (x_move) {
            cout << "Player X choose where you want to play ";
        } else {
            cout << "Player O choose where you want to play ";
        }
        cin >> location; // this takes the input of the function.
        int row = ceil((double) location / 4); // it divides value by 4 and rounds decimal to upper integer so 10/4 rounds to 3.
        int col = location % 4; // gives the location in terms of the column it is present in.
        if (!col) col += 4; // this is if it is the last number of the row, so 4,8,12,16.
        
        if (location >= 1 && location <= 16 && matrix[row][col] != "X" && matrix[row][col] != "O") { // checks if the place isnt occupied or is in the range.
            if (x_move) {
                matrix[row][col] = "X";
            } else {
                matrix[row][col] = "O";
            }
            print_matrix();
            check_winner();
            x_move = o_move;
            o_move = 1 - x_move;
        } else {
            cout << "Square has already been used by someone or is not in the values which can be inputted as it is less than 1 or greater than 16 or not an integer." << endl;
        }
    } while (winner == '*' && not_full()); // checks if no one has won and the matrix isnt full, then continues play for this do while loop.
}

int main() {
    do {
        start(); // function is called here.
        moves(); // function is called here.
        
        if (winner == 'X') {
            cout << "X has got 4 in a line. X has won the game. Congratulations!" << endl; // declares the winner. this is the output.
            x_wins++;
        } else if (winner == 'O') {
            cout << "O has got 4 in a line. O has won the game. Congratulations!" << endl; // declares winner. this is output.
            o_wins++;
        } else {
            cout << "No one got 4 X's or O's. No one won the game." << endl;
            ties++; // output
        }
        
        games++;
        cout << "Do y'all want to play Again? (Y or N): "; // asks whether users wants to play again or stop playing.
        cin >> again;
    } while (again == 'Y' || 'y');
    
    cout << "\n---------- Stats between two players ----------" << endl; // provides the stats for the two players.
    cout << " X has won " << x_wins << " time(s)." << endl;
    cout << " O has won " << o_wins << " time(s)." << endl;
    cout << "Games where no one one: " << ties << endl;
    return 0;
}

