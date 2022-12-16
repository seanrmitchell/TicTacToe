#include <iostream>
using namespace std;


	int playerInput() {
		int input = 0;

		while (!(input < 10 && input > 0)) {
			cout << "Type a number 1-9: ";
			cin >> input;
		}

		return input;

	}

	void Board() {

		cout << "_____|_____|_____ \n";
		cout << "  ";
		cout << "";
		cout << "  |     |     \n";
		cout << "-----|-----|----- \n";
		cout << "     |     |      \n";
		cout << "-----|-----|----- \n";
		cout << "     |     |      \n";
		cout << "-----|-----|----- \n";
		
	}

	void playBoard() {

	}


int main() {

	Board board;
	board.baseBoard();

	return 0;
}