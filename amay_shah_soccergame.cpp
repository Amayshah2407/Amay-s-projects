// Student Name: Amay Shah
// Student Number: 20780897
// SYDE 121 Lab Assignment: 4
// Filename: Lab 4.cpp
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts.  This coded solution has
// not been plagiarized from other sources and has not been knowingly plagiarized by others.
// Project:  Simulating a  soccer game
// Purpose: To randomise the events in a soccer game and seeing the results after the match for different conditions:
// goals, free kicks, shots, red and yellow cards.
// Due Date: Monday, October 15th

#include <iostream> // Defining Directory
#include <stdlib.h>// Obtaining Directory
#include <time.h> // Obtaining library
using namespace std;

void card_recieved(int team);
// Function to check whether the team recieved a card.
void check_goal_scored(int team, bool penalty);
// Checks whether the team scored a goal or missed.

int main();

int A_score = 0, B_score = 0;
int A_shots_on_goal = 0, B_shots_on_goal = 0;
int A_shots_off_goal = 0, B_shots_off_goal = 0;
int A_blocked_shots = 0, B_blocked_shots = 0;
int A_fouls = 0, B_fouls = 0;
int A_yellow_cards = 0, B_yellow_cards = 0;
int A_red_cards = 0, B_red_cards = 0; // all the variables are being initiated.

void card_recieved(int team) { // Function Body
    int card = rand() % 4; // Using rand to generate random number
    
    if (team) {
        if (card == 1) {
            A_yellow_cards++;
            cout << "A player from Team A gets a yellow card." << endl;
        } else {
            A_red_cards++;
            cout << "A player from Team A gets a red card." << endl;
        }
    } else {
        if (card == 1) {
            B_yellow_cards++;
            cout << "A player from Team B gets a yellow card." << endl;
        } else {
            B_red_cards++;
            cout << "A player from Team B gets a red card." << endl;
        }
    }
}

void check_goal_scored(int team, bool penalty) { //Function Body
    int goal = rand() % 4;// Using rand to generate random number
    
    if (team) {
        if (goal == 0) {
            A_score++;
            A_shots_on_goal++; // in the case that shot is on goal and scores.
            cout << "-> Team A's shot on goal has not been saved. What a brilliant goal. " << endl;
        } else if (goal == 1) {
            A_shots_on_goal++;
            B_blocked_shots++; // in the case that shot is on target but saved.
            cout << "-> Team A took a shot on goal but was saved." << endl;
        } else if (goal == 2) {
            A_shots_off_goal++; // shot is not on target.
            cout << "-> That's a shot off target for team A. Good attempt though." << endl;
        } else if (!penalty) {
            B_blocked_shots++; // keeper saves shot on target.
            cout << "-> Team A takes a shot but it is saved by the keeper." << endl;
        }
    } else {
        if (goal == 0) {
            B_score++;
            B_shots_on_goal++;
            cout << "-> Team B's shot on goal has not been saved. What a brilliant goal." << endl;
        } else if (goal == 1) {
            B_shots_on_goal++;
            A_blocked_shots++;
            cout << "-> Team B took a shot on goal but was saved." << endl;
        } else if (goal == 2) {
            B_shots_off_goal++;
            cout << "-> That's a shot off target for team B. Good attempt though." << endl;
        } else if (!penalty) {
            A_blocked_shots++;
            cout << "-> Team B takes a shot but it is saved by the keeper." << endl;
        }
    }
}

int main() {
    srand(time(NULL));
    
    int events = rand() % 30 + 1; // Using rand to randomise the output which is given, different for each time program runs.
    cout << "Soccer Intramural 2018 ";
    cout << "Total number of events in the game (shots, cards, goals): " << events << endl;
    
    for (int i = 1; i <= events; i++) {
        
        if (i == events / 2 + 1) { // Proides output of all the stats (echoing)
            cout << "\n----- HALF TIME -----" << endl;
            cout << "\nTEAM A:\n"
            << "\nScore: " << A_score
            << "\nShots on target: " << A_shots_on_goal
            << "\nShots off target: " << A_shots_off_goal
            << "\nBlocked Shots: " << A_blocked_shots
            << "\nFouls committed: " << A_fouls
            << "\nYellow Cards: " << A_yellow_cards
            << "\nRed Cards: " << A_red_cards << endl;
            cout << "\nTEAM B:\n"
            << "\nScore: " << B_score
            << "\nShots on target: " << B_shots_on_goal
            << "\nShots off target: " << B_shots_off_goal
            << "\nBlocked Shots: " << B_blocked_shots
            << "\nFouls committed: " << B_fouls
            << "\nYellow Cards: " << B_yellow_cards
            << "\nRed Cards: " << B_red_cards << endl;
            cout << "\n---------------------\n" << endl;
        }
        
        int num = rand() % 6 + 1; // Using rand to randomise, generates random input.
        
        if (num == 1) {
            check_goal_scored(1, false);
        } else if (num == 2) {
            check_goal_scored(0, false);
        } else if (num == 3) {
            B_fouls++;
            check_goal_scored(1, false);
            card_recieved(0);
        } else if (num == 4) {
            A_fouls++;
            check_goal_scored(0, false);
            card_recieved(1);
        } else if (num == 5) {
            B_fouls++;
            check_goal_scored(1, true);
            card_recieved(0);
        } else {
            A_fouls++;
            check_goal_scored(0, true);
            card_recieved(1);
        }
    }
    
    cout << "\n----- GAME OVER -----" << endl; // Output final statistics for the game
    cout << "\nTEAM A:\n" // team A statistics
    << "\nScore: " << A_score
    << "\nShots on goal: " << A_shots_on_goal
    << "\nShots off goal: " << A_shots_off_goal
    << "\nBlocked Shots: " << A_blocked_shots
    << "\nFouls: " << A_fouls
    << "\nYellow Cards: " << A_yellow_cards
    << "\nRed Cards: " << A_red_cards << endl;
    cout << "\nTEAM B:\n" // team B statistics
    << "\nScore: " << B_score
    << "\nShots on goal: " << B_shots_on_goal
    << "\nShots off goal: " << B_shots_off_goal
    << "\nBlocked Shots: " << B_blocked_shots
    << "\nFouls: " << B_fouls
    << "\nYellow Cards: " << B_yellow_cards
    << "\nRed Cards: " << B_red_cards << endl;
    
    if (A_score < B_score) { // Output Final Result depending on goals scored after full time.
        cout << "\nTEAM B wins the game, what an effort!\n" << endl;
    } else if (A_score > B_score) {
        cout << "\nTEAM A wins the game, what an effort!\n" << endl;
    } else {
        cout << "\nTeam A and B same the number of goals. The match ends as a tie. \n" << endl;
    }
    
    return 0;
}
