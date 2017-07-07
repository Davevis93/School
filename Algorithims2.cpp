/*
Matthew Jerome
CSCI 1010 Section 12
July 6, 2017
Algorithims: Swap, min/max index, selection sorting
*/

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

//Vector Prototypes
//void swap(vector<int>&, int, int);
//int minIndex(vector<int>&);
//void bubbleSort(vector<int>&);
//void selectionSort(vector<int>&);
//int minIndex4SelectionSort(vector<int>&, int = 0);

//Array Prototypes
void swapArray(int[], int, int);
void bubbleSortArray(int[], int);
int minIndexArray(int[], int, int = 0);
void selectionSortArray(int[], const int);

const int SIZE = 10;

int main(){

	//vector<int> list;
	int myArray[SIZE] = { 10, 10, 6, 5, 5, 3, 2, 5, 8, 9 };

	int minI = minIndexArray(myArray, SIZE);

	//bubbleSortArray(myArray, SIZE);


	cout << "Hello World!" << endl;
	cout << "Min index is at " << minI << ". " << endl;
	cout << endl;
	//cout << "Minimum value is " << minIndex(list) << endl;

	selectionSortArray(myArray, SIZE);

	for (int i = 0; i < SIZE; i++){
		cout << i << ": " << myArray[i] << endl;
	}

	cin.get();
	cin.ignore();
	return 0;
}

void initializeVector(vector<int>& list) {
	int vectorInput;
	
	cout << "Enter a number or 0 to exit: ";
	cin >> vectorInput;

	while (vectorInput != 0) {		
		list.push_back(vectorInput);
		cout << "Enter a number or 0 to exit: ";
		cin >> vectorInput;
	}
}

//----------------------SWAP FUNCTIONS------------------------------------
void swap(vector<int>& list, int p, int q){
	if (p != q){
		int first = list[p];
		list[p] = list[q];
		list[q] = first;
	}
}

void swapArray(int array[], int p, int q){
	if (p != q){
		int first = array[p];
		array[p] = array[q];
		array[q] = first;
	}
}

//---------------------MIN INDEX FUNCTIONS--------------------------------
int minIndex(vector<int>& list){

	if (list.size() == 0){
		throw logic_error("Error! List is empty!");
	}

	int index = 0;
	for (int i = 0; i < list.size(); i++){
		if (list[i] < list[index]){ //index is holder of min value index position. If a new position is lower than old min than min updates
			index = i;
		}
	}
	return index; //Returns min index position. doing return list[index] would return min value
}

int minIndex4SelectionSort(vector<int>& list, int start){
	if (list.size() == 0){
		throw logic_error("Error! List is Empty!");
	}

	int index = start;//
	for (int i = start; i < list.size(); i++){
		if (list[i] < list[index]){ //index is holder of min value index position. If a new position is lower than old min than min updates
			index = i;
		}
	}
	return index; //Returns min index position. doing return list[index] would return min value
}

int minIndexArray(int array[], int size, int start){
	if (size <= 0){
		throw logic_error( "Error! Size must be positive." );
	}
	if (start < 0 || start >= size){
		throw logic_error("Error! Start must be from 0 to size-1." );
	}
	int index = start;
	for (int i = start; i < size; i++){
		if (array[i] < array[index]){
			index = i;
		}
	}
	return index;
}

//--------------------BUBBLE SORT FUNCTIONS-------------------------------
void bubbleSort(vector<int>& list){
	bool didSwap = true;

	while (didSwap){ //If it ever reads that a swap was done then do another full pass through the numbers
		didSwap = false; //Keep running until you don't do a swap

		for (int i = 1; i < list.size(); i++){
			if (list[i] < list[i - 1]){ //If i is less than previous i then swap. If i is NOT less than previous i then the if loop does nothing
				swap(list, i, i-1); //Just call the swap function made earlier. p is i, q is i-1
				didSwap = true; //Set to true to show we did a swap and reverse the previous false setting
			}
		}
	}
}

void bubbleSortArray(int array[], int size){
	bool didSwapArray = true;

	while (didSwapArray){
		didSwapArray = false;

		for (int i = 1; i < size; i++){
			swapArray(array, i, i - 1);
			didSwapArray = true;
		}
	}
}


//--------------------SELECTION SORT FUNCTIONS----------------------------
void selectionSort(vector<int>& list) {
	if (list.size() > 1){
		for (int ScanStart = 0; ScanStart < list.size(); ScanStart++) {
			int minIndex = searchMinIndex(list, ScanStart);
			swap(list, ScanStart, minIndex);
		}
	}
}

void selectionSortArray(int array[], const int size){
	for (int i = 0; i < size; i++){
		int minI = minIndexArray(array, size, i);
		swapArray(array, i, minI);
	}

}
