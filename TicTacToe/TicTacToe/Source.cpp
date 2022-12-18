#include <iostream>
#include <stdlib.h>
using namespace std;

char display[3][3] = { {'_','_','_'},{'_','_','_'},{'_','_','_'} };

int row, column;

char turn = 'O';

bool done = false;
bool draw = false;

void board() {

	// Initial board set up, and future displays of the board
		
	cout << "\t\t"<<"  0       1       2" << "\n";
	cout << "\t0\t__"<<display[0][0]<<"__ | __"<<display[0][1]<<"__ | __"<<display[0][2]<<"__\n";
	cout << "\t1\t__" << display[1][0] << "__ | __" << display[1][1] << "__ | __" << display[1][2] << "__\n";
	cout << "\t2\t__" << display[2][0] << "__ | __" << display[2][1] << "__ | __" << display[2][2] << "__\n";
		
}

void player() {

	// Player insertion into displays
	cout << "\t\nSelect a row: ";

	cin >> row;

	cout << "\t\nSelect a column: ";

	cin >> column;

	//Determines if space selected is filled
	if (display[row][column] == '_') {

		display[row][column] = turn;
		
	}
	else {
		cout << "\t\nSpace already selected. Please select again\n";
		player();
	}

}

bool gameOver() {

	// Checks for winner columns and rows

	for (int i = 0; i < 3; i++) {
		if(display[i][0]==turn)
			if (display[i][0] == display[i][1] && display[i][0] == display[i][2]) {
				return false;
			}
		if(display[0][i]==turn)
			if (display[0][i] == display[1][i] && display[0][i] == display[2][i]) {
				return false;
			}
	}

	// Checks for winner diagonals
	
	if (display[0][0] == turn) {
		if (display[0][0] == display[1][1] && display[0][0] == display[2][2]) 
			return false;
	}
	if (display[0][2] == turn) {
		if (display[0][2] == display[1][1] && display[0][2] == display[2][0])
			return false;
	}
	

	// Checks if game is in continue
	
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (display[i][j] != 'X' && display[i][j] != 'O')
				return true;

	// When this code is reached, board must be in draw
						
	draw = true;
	done = true;
	return false;
}




int main() {

	// Gameplay Loop
	while (gameOver()) {

		board();

		if (turn == 'O')
			turn = 'X';
		else if (turn == 'X')
			turn = 'O';

		cout << "\t\n" << turn << "'s move!\n";

		player();

		//gameOver();

	}

	//Determines winner.
	if (!draw) {
		board();
		cout << "\t\n" << turn << " WINS!";
	}
	else {
		board();
		cout << "\t\nDRAW!";
	}

}