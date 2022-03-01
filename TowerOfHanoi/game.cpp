// game.cpp
#include <iostream>
#include "Hanoi.h"
#include <vector>
#include <bits/stdc++.h> /* transform */
#include <cmath> /* pow */
#include <time.h> /* time_t, difftime, time */

using namespace std;

// Needed function prototypes.
void printGameStatus(const vector<vector<string>> & str_arr); // Prototype of function that prints out a vector(the game graphics in this case).
void printTime(int time); // Prototype of function that converts the time from seconds to minutes and seconds, then prints it.

int main() {
	// Declare variables needed.
	Player player1;
	string name, play, move, temp;
	int moves, least_moves, disks;
	bool solved, swaped;
	time_t start, end;
    double duration;

	// Introduce the game.
	cout << "\n\n";
	cout << "******************************************** THE TOWER OF HANOI ********************************************\n\n";
	cout << "Welcome to the legendary game: The Tower of Hanoi\nThis game is a puzzle full of exciting mind twists to sharpen your brain.\n\n";
	cout << ">>>>> NAME: Type in your name or cool nickname, then press 'Enter': ";
	cin >> name;
	player1.setName(name);
	cout << "\nGood to have you here, " << player1.getName() << ".\n\n";
	cout << "The goal of the game is to order the disks to form a cone on the right rod using the middle side (M)\n";
	cout << "as a free rod to help transferring the disks. A few rules apply in this game:\n\n";
	cout << "1. You can only move the disk at the top of other disks or alone.\n";
	cout << "2. You cannot put a larger disk on top of a smaller disk.\n";
	cout << "3. You win the game when all disks are on the right-end rod/side in order(cone form).\n\n";
	cout << "To move the disks you type in two letters where the first represents the current location and the\n";
	cout << "second letter represents the preferred destination of the disk. eg. LR - this input moves the top\n";
	cout << "disk from the left side to the right side. Note that: L for left, R is for right, and M is for middle.\n\n";
	cout << "Enjoy the game!!!\n" << endl;

	cout << ">>>>> NEW GAME: Are you ready to start? (Enter any key or press q or n to exit) : ";

	while(cin >> play) 
	{
		if (play == "q" || play == "Q" || play == "no" || play == "NO" || play == "N" || play == "n") {
			cout << "\n GAME OVER. See you again soon! :)\n\n";
			cout << "***********************************************************************************************************************\n\n";
			break; // Exit game if the player wants to quit.
		}
		// Prompt user to choose the number of disks to use.
		cout << "\n>>>>> LEVEL CHOICE: How many disks do you want to try? Enter an integer between 3 and 10 (inclusive): ";
		while(!(cin >> disks) || disks < 3 || disks > 10) // Input verification or validation
		{
			cout << "\nWrong input! Enter a non-negative integer between 3 and 10: ";
			cin.clear(); // Removing the failbit flag
			while(cin.get() != '\n') // Clearing the input stream
				continue;
		}
		// Create disk array and it's graphics for display.
		vector<vector<string>> disk_2Dvector(disks, vector<string> (disks));
		string disk, no_disk;

		for(int row = 0; row < disks; row++){ 
			if (row == 0)
			{
				disk = "+++";
				switch (disks)
				{
				case (3) :
					least_moves = int(pow(2.0, double(disks))-1);
					disk_2Dvector[0][0] = "  <" + disk + ">  ";
					disk_2Dvector[0][1] = " <+" + disk + "+> ";
					disk_2Dvector[0][2] = "<++" + disk + "++>";
					break;
				case (4) :
					least_moves = int(pow(2.0, double(disks))-1);
					disk_2Dvector[0][0] = "   <" + disk + ">   ";
					disk_2Dvector[0][1] = "  <+" + disk + "+>  ";
					disk_2Dvector[0][2] = " <++" + disk + "++> ";
					disk_2Dvector[0][3] = "<+++" + disk + "+++>";
					break;
				case (5) :
					least_moves = int(pow(2.0, double(disks))-1);
					disk_2Dvector[0][0] = "    <" + disk + ">    ";
					disk_2Dvector[0][1] = "   <+" + disk + "+>   ";
					disk_2Dvector[0][2] = "  <++" + disk + "++>  ";
					disk_2Dvector[0][3] = " <+++" + disk + "+++> ";
					disk_2Dvector[0][4] = "<++++" + disk + "++++>";
					break;
				case (6) :
					least_moves = int(pow(2.0, double(disks))-1);
					disk_2Dvector[0][0] = "     <" + disk + ">     ";
					disk_2Dvector[0][1] = "    <+" + disk + "+>    ";
					disk_2Dvector[0][2] = "   <++" + disk + "++>   ";
					disk_2Dvector[0][3] = "  <+++" + disk + "+++>  ";
					disk_2Dvector[0][4] = " <++++" + disk + "++++> ";
					disk_2Dvector[0][5] = "<+++++" + disk + "+++++>";
					break;
				case (7) :
					least_moves = int(pow(2.0, double(disks))-1);
					disk_2Dvector[0][0] = "      <" + disk + ">      ";
					disk_2Dvector[0][1] = "     <+" + disk + "+>     ";
					disk_2Dvector[0][2] = "    <++" + disk + "++>    ";
					disk_2Dvector[0][3] = "   <+++" + disk + "+++>   ";
					disk_2Dvector[0][4] = "  <++++" + disk + "++++>  ";
					disk_2Dvector[0][5] = " <+++++" + disk + "+++++> ";
					disk_2Dvector[0][6] = "<++++++" + disk + "++++++>";
					break;
				case (8) :
					least_moves = int(pow(2.0, double(disks))-1);
					disk_2Dvector[0][0] = "       <" + disk + ">       ";
					disk_2Dvector[0][1] = "      <+" + disk + "+>      ";
					disk_2Dvector[0][2] = "     <++" + disk + "++>     ";
					disk_2Dvector[0][3] = "    <+++" + disk + "+++>    ";
					disk_2Dvector[0][4] = "   <++++" + disk + "++++>   ";
					disk_2Dvector[0][5] = "  <+++++" + disk + "+++++>  ";
					disk_2Dvector[0][6] = " <++++++" + disk + "++++++> ";
					disk_2Dvector[0][7] = "<+++++++" + disk + "+++++++>";
					break;
				case (9) :
					least_moves = int(pow(2.0, double(disks))-1);
					disk_2Dvector[0][0] = "        <" + disk + ">        ";
					disk_2Dvector[0][1] = "       <+" + disk + "+>       ";
					disk_2Dvector[0][2] = "      <++" + disk + "++>      ";
					disk_2Dvector[0][3] = "     <+++" + disk + "+++>     ";
					disk_2Dvector[0][4] = "    <++++" + disk + "++++>    ";
					disk_2Dvector[0][5] = "   <+++++" + disk + "+++++>   ";
					disk_2Dvector[0][6] = "  <++++++" + disk + "++++++>  ";
					disk_2Dvector[0][7] = " <+++++++" + disk + "+++++++> ";
					disk_2Dvector[0][8] = "<++++++++" + disk + "++++++++>";
					break;
				case (10) :
					least_moves = int(pow(2.0, double(disks))-1);
					disk_2Dvector[0][0] = "         <" + disk + ">         ";
					disk_2Dvector[0][1] = "        <+" + disk + "+>        ";
					disk_2Dvector[0][2] = "       <++" + disk + "++>       ";
					disk_2Dvector[0][3] = "      <+++" + disk + "+++>      ";
					disk_2Dvector[0][4] = "     <++++" + disk + "++++>     ";
					disk_2Dvector[0][5] = "    <+++++" + disk + "+++++>    ";
					disk_2Dvector[0][6] = "   <++++++" + disk + "++++++>   ";
					disk_2Dvector[0][7] = "  <+++++++" + disk + "+++++++>  ";
					disk_2Dvector[0][8] = " <++++++++" + disk + "++++++++> ";
					disk_2Dvector[0][9] = "<+++++++++" + disk + "+++++++++>";
					break;		
				}
			}
			else
			{
				no_disk = "         ";
				if (disks > 3) 
					for (int x = 3; x < disks; x++) no_disk += "  ";
				for(int col = 0; col < disks; col++) disk_2Dvector[row][col] = no_disk;
			}
		}
		// Print the initial scenario of the unsolved puzzle.
		cout << "\nGenerated a Tower of Hanoi made of " << disks << " disks.\n";
		cout << "\nHINT: The possible minimum number of moves is " << least_moves << "\n";
		printGameStatus(disk_2Dvector);

		// Code to move disks and solve the puzzle.
		temp = disk_2Dvector[0][0];
		time(&start);	// Start the timer for the player or record the current time.
		solved = false; // Reset the solved variable to make sure a new game starts.

		while (solved == false)
		{
			// Request user input or player's move.
			cout << "Make your move eg: LM means move top disk on left side to the middle. (Enter q to quit): ";
			while(!(cin >> move) || ((move.size() != 2) && (move != "q") && (move != "Q"))) // Input verification or validation
			{
				cout << "\nWrong input! Enter only two letters (uppercase or lowercase) without space: ";
				cin.clear(); // Removing the failbit flag
				while(cin.get() != '\n') // Clearing the input stream
					continue;
			}
			// Keep track of the number of moves made by adding each move.
			player1.addMoves(1);

			// Converting input string to uppercase using transform() function and ::toupper in STL 
			transform(move.begin(), move.end(), move.begin(), ::toupper); 

			if (move == "LM") {
				swaped = false;
				while (swaped == false)
				{
					for (int i = 0; i < disks; i++)
					{
						for (int j = (disks-1); j >= 0; j--)
						{
							if((disk_2Dvector[0][i] != no_disk)&&(disk_2Dvector[1][j] == no_disk)) {
								if (j != (disks-1)) { // Checking the disk below the destination position before swaping.
									if (disk_2Dvector[0][i] < disk_2Dvector[1][j+1]) { // Swap if the disk below is large.
										swap(disk_2Dvector[0][i], disk_2Dvector[1][j]);
										swaped = true;
										break;
									}
									else { // Avoid swapping if the disk below is smaller than the incoming disk.
										cout << "\n!!! Impossible move! You cannot place a large disk on top of a small disk.\n";
										player1.addMoves(-1);
										swaped = true;
										break;
									}
								}
								else { // Preventing segmentation error by accessing a nonexistant index (j == disks).
									swap(disk_2Dvector[0][i], disk_2Dvector[1][j]);
									swaped = true;
									break;
								}
							}
							if (swaped == true) break;
						}
						if (swaped == true) break;
					}
					if (swaped == false) { // If no move was no possible, don't count the move.
						cout << "\nThere is no disk to move on the side that you chose.\n";
						player1.addMoves(-1);
						swaped = true;
						break;
					}
				}			
			}
			else if (move == "ML") {
				swaped = false;
				while (swaped == false)
				{
					for (int i = 0; i < disks; i++)
					{
						for (int j = (disks-1); j >= 0; j--)
						{
							if((disk_2Dvector[1][i] != no_disk)&&(disk_2Dvector[0][j] == no_disk)) {
								if (j != (disks-1)) {
									if (disk_2Dvector[1][i] < disk_2Dvector[0][j+1]) {
										swap(disk_2Dvector[1][i], disk_2Dvector[0][j]);
										swaped = true;
										break;
									}
									else {
										cout << "\n!!! Impossible move! You cannot place a large disk on top of a small disk.\n";
										player1.addMoves(-1);
										swaped = true;
										break;
									}
								}
								else {
									swap(disk_2Dvector[1][i], disk_2Dvector[0][j]);
									swaped = true;
									break;
								}
							}
							if (swaped == true) break;
						}
						if (swaped == true) break;
					}
					if (swaped == false) { // If no move was no possible, don't count the move.
						cout << "\nThere is no disk to move on the side that you chose.\n";
						player1.addMoves(-1);
						swaped = true;
						break;
					}
				}			
			}
			else if (move == "LR") {
				swaped = false;
				while (swaped == false)
				{
					for (int i = 0; i < disks; i++)
					{
						for (int j = (disks-1); j >= 0; j--)
						{
							if((disk_2Dvector[0][i] != no_disk)&&(disk_2Dvector[2][j] == no_disk)) {
								if (j != (disks-1)) {
									if (disk_2Dvector[0][i] < disk_2Dvector[2][j+1]) {
										swap(disk_2Dvector[0][i], disk_2Dvector[2][j]);
										swaped = true;
										break;
									}
									else {
										cout << "\n!!! Impossible move! You cannot place a large disk on top of a small disk.\n";
										player1.addMoves(-1);
										swaped = true;
										break;
									}
								}
								else {
									swap(disk_2Dvector[0][i], disk_2Dvector[2][j]);
									swaped = true;
									break;
								}
							}
							if (swaped == true) break;
						}
						if (swaped == true) break;
					}
					if (swaped == false) { // If no move was no possible, don't count the move.
						cout << "\nThere is no disk to move on the side that you chose.\n";
						player1.addMoves(-1);
						swaped = true;
						break;
					}
				}			
			}
			else if (move == "RL") {
				swaped = false;
				while (swaped == false)
				{
					for (int i = 0; i < disks; i++)
					{
						for (int j = (disks-1); j >= 0; j--)
						{
							if((disk_2Dvector[2][i] != no_disk)&&(disk_2Dvector[0][j] == no_disk)) {
								if (j != (disks-1)) {
									if (disk_2Dvector[2][i] < disk_2Dvector[0][j+1]) {
										swap(disk_2Dvector[2][i], disk_2Dvector[0][j]);
										swaped = true;
										break;
									}
									else {
										cout << "\n!!! Impossible move! You cannot place a large disk on top of a small disk.\n";
										player1.addMoves(-1);
										swaped = true;
										break;
									}
								}
								else {
									swap(disk_2Dvector[2][i], disk_2Dvector[0][j]);
									swaped = true;
									break;
								}
							}
							if (swaped == true) break;
						}
						if (swaped == true) break;
					}
					if (swaped == false) { // If no move was no possible, don't count the move.
						cout << "\nThere is no disk to move on the side that you chose.\n";
						player1.addMoves(-1);
						swaped = true;
						break;
					}
				}			
			}
			else if (move == "MR") {
				swaped = false;
				while (swaped == false)
				{
					for (int i = 0; i < disks; i++)
					{
						for (int j = (disks-1); j >= 0; j--)
						{
							if((disk_2Dvector[1][i] != no_disk)&&(disk_2Dvector[2][j] == no_disk)) {
								if (j != (disks-1)) {
									if (disk_2Dvector[1][i] < disk_2Dvector[2][j+1]) {
										swap(disk_2Dvector[1][i], disk_2Dvector[2][j]);
										swaped = true;
										break;
									}
									else {
										cout << "\n!!! Impossible move! You cannot place a large disk on top of a small disk.\n";
										player1.addMoves(-1);
										swaped = true;
										break;
									}
								}
								else {
									swap(disk_2Dvector[1][i], disk_2Dvector[2][j]);
									swaped = true;
									break;
								}
								
							}
							if (swaped == true) break;
						}
						if (swaped == true) break;
					}
					if (swaped == false) { // If no move was no possible, don't count the move.
						cout << "\nThere is no disk to move on the side that you chose.\n";
						player1.addMoves(-1);
						swaped = true;
						break;
					}
				}			
			}
			else if (move == "RM") {
				swaped = false;
				while (swaped == false)
				{
					for (int i = 0; i < disks; i++)
					{
						for (int j = (disks-1); j >= 0; j--)
						{
							if((disk_2Dvector[2][i] != no_disk)&&(disk_2Dvector[1][j] == no_disk)) {
								if (j != (disks-1)) {
									if (disk_2Dvector[2][i] < disk_2Dvector[1][j+1]) {
										swap(disk_2Dvector[2][i], disk_2Dvector[1][j]);
										swaped = true;
										break;
									}
									else {
										cout << "\n!!! Impossible move! You cannot place a large disk on top of a small disk.\n";
										player1.addMoves(-1);
										swaped = true;
										break;
									}
								}
								else {
									swap(disk_2Dvector[2][i], disk_2Dvector[1][j]);
									swaped = true;
									break;
								}
							}
							if (swaped == true) break;
						}
						if (swaped == true) break;
					}
					if (swaped == false) { // If no move was no possible, don't count the move.
						cout << "\nThere is no disk to move on the side that you chose.\n";
						player1.addMoves(-1);
						swaped = true;
						break;
					}
				}			
			}
			// Exit the game if q is entered.
			else if (move == "Q") { 
				time(&end); // Record the current time.
				duration = difftime(end,start); // Calculate the time taken.
				player1.setTime(duration);
				player1.addGames(1);
				player1.addTime(duration);
				cout << "\nYou just quit the current game.\n\n";
				player1.show();
				break;
			}

			time(&end); // Record the current time.
			duration = difftime(end,start); // Calculate the current time taken.
			player1.setTime(duration); // Save the current time taken by the player.

			// Print out the resulting scenario after implementing the move.
			cout << "\n<<<<<<<<<<<<<<   CURRENT GAME STATUS   >>>>>>>>>>>>>>>" << endl << endl; 
			cout << "* Number of moves made: " << player1.getMoves() << endl;
			printTime(player1.getTime());
			cout << "HINT: The minimum number of moves for this level is " << least_moves << endl;

			printGameStatus(disk_2Dvector);

			// Check if the game is over.
			if (disk_2Dvector[2][0] == temp) {
				solved = true;
				player1.addGames(1);
				time(&end);
				duration = difftime(end,start);
				player1.setTime(duration);
				player1.addTime(duration);
				cout << "\n**** Congratulations, " << player1.getName() << "! You solved the puzzle, YEY!!!!! ****\n\n";
				moves = player1.getMoves();
				if (moves == least_moves) {
					cout << "You might be a GENIUS! You used the MINIMUM NUMBER of moves for this level!\n";
					cout << "Disks Level: "<< disks << " disks; Minimum Number of Moves: " << least_moves << endl << endl;
				}
				player1.show();
				cout << "Well done. Keep getting faster!\n\n";
			}
		}
		cout << ">>>>> NEW GAME: Do you want to start a new game? (Press any key or press q or n to exit) : ";
	}

	return 0;
}

// Method to print out a vector.
void printGameStatus(const vector<vector<string>> & str_arr){
	cout << endl << endl;
    for(int r = 0; r < str_arr.size(); r++)
	{ 
		cout << "|";
		for(int c = 0; c < 3; c++) cout << str_arr[c][r] << "|";
		cout << endl;
	}
	switch (str_arr.size())
	{
	case 3: cout << "\n    (L)       (M)       (R)\n\n";
		break;
	case 4: cout << "\n     (L)         (M)         (R)\n\n";
		break;
	case 5: cout << "\n      (L)           (M)           (R)\n\n";
		break;
	case 6: cout << "\n       (L)            (M)             (R)\n\n";
		break;
	case 7: cout << "\n        (L)              (M)               (R)\n\n";
		break;
	case 8: cout << "\n         (L)                  (M)                 (R)\n\n";
		break;
	case 9: cout << "\n          (L)                    (M)                   (R)\n\n";
		break; 
	case 10: cout << "\n          (L)                      (M)                     (R)\n\n";
		break;
	}
}

// Function that that converts the time from seconds to minutes and seconds.
void printTime(int time) {
	int minutes, seconds;
	minutes = int(time/60);
	seconds = time - (minutes*60);
	cout << "* Current time taken: " << minutes << " minutes and " << seconds << " seconds.\n\n";
}
