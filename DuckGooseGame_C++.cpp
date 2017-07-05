#include <iostream>

using namespace std;

const int NUMCHILDREN = 25;

bool initializeDuckArray(int[], int);
void runDuckGooseGame(int[], int, int, int);

int main() {

	int inCircle[NUMCHILDREN];
	int ducksLeft;
	int teacher = 0;

	cout << "Welcome to the duck duck goose game!" << endl << endl;
	cout << endl;
	cout << "There are " << NUMCHILDREN << " children playing the game." << endl;
	cout << "Enter how many times does the teacher says duck before saying goose? ";
	cin >> ducksLeft;

	while (ducksLeft < 0) {
		cout << "Please enter a positive number or zero for duck: ";
		cin >> ducksLeft;
	}
		
	cout << endl;

	initializeDuckArray(inCircle, NUMCHILDREN);
	runDuckGooseGame(inCircle, NUMCHILDREN, teacher, ducksLeft);

	cin.get();
	cin.ignore();
	return 0;
}

/*
Initializes the inCircle array with all elements as true

Precondition: None
Postcondition: inCircle initialized to be all true
Parameters: int inCircle, int size
Return: an initialized inCircle array set as all true
*/
bool initializeDuckArray(int inCircle[], int size) {
for (int i = 0; i < size; i++) {
	inCircle[i] = true;
	}
return inCircle;
}
/*
Calculates which child is a goose and outputs them to the screen

Precondition: user input ducksLeft 
Postcondition: None
Parameters: int inCircle, int size, int teacher, int ducksLeft
Return: None
*/

void runDuckGooseGame(int inCircle[], int size, int teacher, int ducksLeft) {
	//int i = inCircle[0]; Just saved these in case I need to revert
	int inCount = 0;
	int ducksLeftFunc = ducksLeft;
	//while (inCircle[i] = true && i < size) {
	for (int i = 0; i < size; i++){
			if (inCircle[i] = true && teacher == inCount && ducksLeftFunc > 0) {
				ducksLeftFunc--;
			}
			else if (inCircle[i] = true && teacher == inCount && ducksLeftFunc == 0) {
				cout << "Child removed: " << inCount +1 << endl;
				inCircle[i] = false;
				inCircle[size]--;
				ducksLeftFunc = ducksLeft;
			}
			//i++;
			inCount++;
			teacher++;
	}
}
