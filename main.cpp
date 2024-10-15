// In some assignments, you will be provided with a bit of "skeleton code"
// to get you started. However, this assignment is largely geared toward
// getting you up to speed on the basics of C++ programming, so there's very
// minimal starter code here for you.

// All of your programming assignments' driver files (i.e., the .cpp file
// containing the main() function) should have a program header at the
// top. Fill in the program header below:

/*
 * Author: <Jenna Rivera>
 * Program description: <Simulates a basket ball game between 2 players>
 */

/*********************************************************************
** Program Filename: main.cpp
** Author: Jenna Rivera
** Date: 10/14/2024
** Description: A C++ program that simulates a basketball shooting game for two players
** Input: money rack position and shooting ability
** Output: both player's outcomes, total points, and this winner
*********************************************************************/
// Recall: this is the syntax for importing / including system-installed
// header files in C++. The <iostream> header file gives you access to
// input / output (I/O) tools, like std::cout, std::cin, and std::endl, so
// that your program can interface with the terminal
#include <iostream>

// You'll also need <cstdlib> and <ctime> to use srand() and rand() for
// pseudorandom number generation (PRNG)
#include <cstdlib>
#include <ctime>
using namespace std;
// TODO: Create many other functions here (you'll want several of them to
// satisfy the course's style guidelines: 
// https://web.engr.oregonstate.edu/~songyip/Teaching/CS16X/cpp_style_guideline.pdf)


/*********************************************************************
** Function: ask
** Description: prompts the user for position of money ball rack. Error message is shown and user is reprompted if input is invalid 
** Parameters: int mr
** Pre-Conditions: an int must exist
** Post-Conditions: if user input is invalid, an error message will show and user is reprompted. If not, program will continue
*********************************************************************/ 
int ask (int mr) {
	
	do {
	cout << "Where do you want to put the money-ball rack? " << endl;
	cin >> mr;
	if (mr <= 0 || mr > 5) {
		cout << "Error, invalid input" << endl;
	} else 
		return mr;
	} while (mr <= 0 || mr > 5 );

	return 0;
}

/*********************************************************************
** Function: shootask
** Description: prompts the user for shooting ability. Error message is shown and user is reprompted if input is invalid 
** Parameters: int sa
** Pre-Conditions: an int must exist
** Post-Conditions: if user input is invalid, an error message will show and user is reprompted. If not, program will continue
*********************************************************************/ 
int shootask (int sa) {
	do {
	cout << "Enter your shooting ability: " << endl;
	cin >> sa;
	if (sa <= 0 || sa > 99) {
		cout << "Error, invalid input" << endl;
	} else 
		return sa;
	} while (sa <= 0 || sa > 99);

	return 0;
}

/*********************************************************************
** Function: sim_one_shot
** Description: simulates a shot with the random number generator
** Parameters: int sa
** Pre-Conditions: an int must exist
** Post-Conditions: returns 0 or 1 based off shooting ability, 0 means missed, 1 means made
*********************************************************************/ 
int sim_one_shot (int sa) {
	int outcome = -1;
	int ran;
	ran = rand() % 100; 
	if (ran > sa) {
		outcome = 0;
	} else {
		outcome = 1;
	}
	
	return outcome;
} 

/*********************************************************************
** Function: asvalues
** Description: assigns values and points to array
** Parameters: int scores[5][5], int sa, int mr, int &sball1, int &sball2
** Pre-Conditions: a int 2d static array and four ints must exist
** Post-Conditions: 2d array is filled if the ball missed or made and is turned to points
*********************************************************************/ 
void asvalues (int scores[5][5], int sa, int mr, int &sball1, int &sball2) {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			// filling array with shot results
			scores[i][j] = sim_one_shot (sa);

			//checking for moneyball
			if (j == 4 || mr == i + 1) {
				scores[i][j] = scores[i][j] * 2;
			}

			if (i == 1 && j == 4) {
				sball1 = sim_one_shot (sa) * 3;
			}

			if (i == 2 && j == 4) {
				sball2 = sim_one_shot(sa) * 3;
			}
		}

	}

}

/*********************************************************************
** Function: print_starry
** Description: prints Starry ball shots and the points earned 
** Parameters: int sball
** Pre-Conditions: an int must exist
** Post-Conditions: The starry ball shots and points earned from the Starry ball is printed
*********************************************************************/ 
void print_starry (int sball) {
	
	cout << "Starry: ";
	if (sball == 3) {
		cout << "S ";
	} else {
		cout << "_ ";
	} 
	cout << "        | Points: " << sball << endl;
}

/*********************************************************************
** Function: print_shots
** Description: calculates total points from on rack and prints out the scoreboard for current player and points made for one rack
** Parameters: int scores[5][5],int &playerpts, int sball1, int sball2
** Pre-Conditions: a int 2d static array and three ints must exist
** Post-Conditions: prints each shot outcome and calculates and prints the total points in a row
*********************************************************************/ 
void print_shots(int scores[5][5],int &playerpts, int sball1, int sball2) {
	for (int i = 0; i < 5; i++) {
			int rackpt = 0;
		cout << "Rack " << i + 1 << ": ";
		for (int j = 0; j < 5; j++) {
			if(scores[i][j] == 0){
				cout << "_ ";
			} else if (scores[i][j] == 1) {
				cout << "X ";
			} else if (scores[i][j] == 2) {
				cout << "M ";
			} 

		// adding up the points made in one rack
			rackpt += scores[i][j];
		}

		playerpts += rackpt;
		cout << "| Points: " << rackpt << endl;

		if (i == 1) {
			print_starry(sball1);
		} 
		if (i == 2) {
			print_starry(sball2);
		}
	}
}

/*********************************************************************
** Function: total_current
** Description: calculates total score for current player and prints to terminal
** Parameters: int player_scores[], int player, int &playerpts, int sball1, int sball2
** Pre-Conditions: a int array and four ints must exist
** Post-Conditions: gets total score for current player and prints to terminal
*********************************************************************/ 
void total_current(int player_scores[], int player, int &playerpts, int sball1, int sball2) {
	// getting total points for current player 
	playerpts = playerpts + sball1 + sball2;
	player_scores[player] = playerpts;
	cout << "Total points for Player " << player + 1 << ": " << playerpts << endl;
	cout << "------------------------------------------------" << endl;
}

/*********************************************************************
** Function: who_wins
** Description: compares player's scores. Whoever has the highest score wins, if the same score, it is a tie
** Parameters: int player_scores[2]
** Pre-Conditions: an int array must exist
** Post-Conditions: prints winner or tie to the terminal
*********************************************************************/ 
void who_wins(int player_scores[2]) {
	
	if (player_scores[0] > player_scores[1]) {
		cout << " Player 1 wins!" << endl;
	} else if (player_scores[0] < player_scores[1]) {
		cout << "Player 2 wins!" << endl;
	} else {
		cout << "Tie!" << endl;
	}
}

/*********************************************************************
** Function: play_again
** Description: asks the user if they would like to play again (1-yes, 0-no)
** Parameters: int play
** Pre-Conditions: an int must exist
** Post-Conditions: the user can play again or quit the program
*********************************************************************/ 
int play_again (int play) {
	do {
	cout << "Play again? (1-yes, 0-no): ";
	cin >> play;
	if (play < 0 || play > 1) {
		cout << "Error, invalid input" << endl;
	} else 
		if (play == 0) {
			cout << "Thanks for playing!" << endl;
		}
		return play;
	} while (play < 0 || play > 1);

	return 0;
}



// Recall: This is the main() function. It's the entrypoint to your program
// (i.e., it is where your program will both start and end).
int main() {
	// This line seeds your PRNG. You don't need to call srand() anywhere else.
	// After it's been called, you can then proceed to use the rand() function
	// to generate pseudorandom numbers at any point in your program.
	srand(time(nullptr));

	// TODO: complete the main function, having it call other functions (and
	// perhaps having those functions call other functions, and so on) to
	// complete the program as described in the assignment description document
	// on Canvas.;

int play;
/* in a do while loop so user has a choice to play again*/
do {
cout << "Welcome to the basketball shooting contest!" << endl;
cout << "------------------------------------------------" << endl;

/*storing the 2 different total scores*/
int player_scores[2] = {0,0};

/* for loop for two players*/
for (int player = 0; player < 2; player++) {
cout << "Player " << player + 1 << ": " << endl;
	int sa;
	int mr;
	
	/*prompting for money rack*/
	mr = ask(mr);
	/*prompting for shooting ability*/
	sa = shootask(sa);
	
	int scores[5][5];
	int playerpts = 0;
	int made = 1;
	int missed = 0;
	int mball = 2;
	int sballpt = 3;
	int sball1 = 0;
	int sball2 = 0; 

	/*assigns values and points to array*/
	asvalues(scores, sa, mr, sball1, sball2);
	
	/*calculates total points from on rack and prints out the scoreboard for current player and points made for one rack*/
	print_shots(scores, playerpts, sball1, sball2);
	
	/*calculates total score for current player and prints to terminal*/
	total_current(player_scores, player, playerpts, sball1, sball2);

}
	/* Determinea who won*/
	who_wins(player_scores);

	/*asks the user if they want to play again*/
	play = play_again(play);
	

} while (play == 1);
}