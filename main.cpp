// In some assignments, you will be provided with a bit of "skeleton code"
// to get you started. However, this assignment is largely geared toward
// getting you up to speed on the basics of C++ programming, so there's very
// minimal starter code here for you.

// All of your programming assignments' driver files (i.e., the .cpp file
// containing the main() function) should have a program header at the
// top. Fill in the program header below:

/*
 * Author: <Jenna Rivera>
 * Program description: <Simulates a basket ball game between 2 players.>
 */

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


// prompts the user for psotion of money ball rack and error message if input is invalid 
int ask (int mr) {
	
	do {
	cout << "Where do you want to put the money-ball rack? " << endl;
	cin >> mr;
	if (mr < 0 || mr > 5) {
		cout << "Error, invalid input" << endl;
	} else 
		return mr;
	} while (mr < 0 || mr > 5 );

	return 0;
}

// prompts the user for shooting ability and error message if input is invalid 
int shootask (int sa) {
	do {
	cout << "Enter your shooting ability: " << endl;
	cin >> sa;
	if (sa < 0 || sa > 99) {
		cout << "Error, invalid input" << endl;
	} else 
		return sa;
	} while (sa < 0 || sa > 99);

	return 0;
}

//return 0 or 1 based off sa, 0 means missed, 1 means made
int sim_one_shot (int sa) {
	int outcome = -1;
	int ran;
	ran = rand() % 100; 
	if (ran > sa) {
		outcome = 0;
	} else {
		outcome = 1;
	}
	
	// cout << "rand num: " << ran << endl;
	return outcome;
} 


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

do {
cout << "Welcome to the basketball shooting contest!" << endl;
cout << "------------------------------------------------" << endl;

// storing the 2 different total scores 

int player_scores[2] = {0,0};

for (int player = 0; player < 2; player++) {
cout << "Player " << player + 1 << ": " << endl;

int sa;
int mr;

	mr = ask(mr);
	sa = shootask(sa);
	
	int scores[5][5];
	int playerpts = 0;
	int made = 1;
	int missed = 0;
	int mball = 2;
	int sballpt = 3;
	int sball1 = 0;
	int sball2 = 0; 


	// assign values into array and setting the points
	// i is row, j is col

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			// filling array w shot results
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

	// print out the array
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

			rackpt += scores[i][j];
		}

		// adding up the points made in one rack
		playerpts += rackpt;
		cout << "| Points: " << rackpt << endl;

			if (i == 1) {
				cout << "Starry: ";
				if (sball1 == 3) {
					cout << "S ";
				} else {
					cout << "_ ";
				} 
				cout << "        | Points: " << sball1 << endl;
			}

			if (i == 2) {
				cout << "Starry: ";
				if (sball2 == 3) {
					cout << "S ";
				} else {
					cout << "_ ";
				} 
				cout << "        | Points: " << sball2 << endl;

			}
	}	

	
	// getting total points for current player 
	playerpts = playerpts + sball1 + sball2;
	player_scores[player] = playerpts;

	// printing current player's score
	cout << "Total points for Player " << player + 1 << ": " << playerpts << endl;
	cout << "------------------------------------------------" << endl;


}
	// Dtermine who won
	if (player_scores[0] > player_scores[1]) {
		cout << " Player 1 wins!" << endl;
	} else if (player_scores[0] < player_scores[1]) {
		cout << "Player 2 wins!" << endl;
	} else {
		cout << "Tie!" << endl;
	}

	play = play_again(play);
	
	

} while (play == 1);
}