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


// Recall: This is the main() function. It's the entrypoint to your program
// (i.e., it is where your program will both start and end).
int main() {
	// This line seeds your PRNG. You don't need to call srand() anywhere else.
	// After it's been called, you can then proceed to use the rand() function
	// to generate pseudorandom numbers at any point in your program.
	int play;
	srand(time(nullptr));

	// TODO: complete the main function, having it call other functions (and
	// perhaps having those functions call other functions, and so on) to
	// complete the program as described in the assignment description document
// on Canvas.;
do {

int player1 = 0;
int player2 = 0;

// whie loop for two players, inside while loop if statement, if player was one, assign ppoint sto player one, inside other function a for loop in a for loop to run a 2d array.

for (int i = 0; i < 2; i++)
int sa;
int mr;

	mr = ask(mr);
	sa = shootask(sa);

	cout << mr << endl;
	cout << sa << endl;





// keping track of shots and racks
int rack = 1; 
while (rack <= 7) {
	int shots = 0;
	while (shots < 5) {
		if ()



	}




}	
	int arr[5][5];

	

	// 2D array 5 rows 5 columns 
	// Store in the array at print to the terminal
	// I wasn't planning to but I guess you could
	// go through the array that stores points and add them
	// no
}



}
