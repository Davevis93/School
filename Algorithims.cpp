/*
Matthew Jerome
CSCI 1010 Section 12
July 5, 2017
Algorithims
*/

#include <iostream>
#include <vector>
#include <stdexcept>//library for errors

using namespace std;
int searchLinear(vector<int>&, int);
int searchMax(vector<int>&);
void swap(vector<int>&, int, int);

int main(){

	/*
	Create a int vector
	Read in int values from keyboard and add them to vector until 0 inputted. Don't add the 0;
	Compute sum of all elements and output
	*/

	vector<int> values;
	int valueToEnter;
	int sum = 0;

	cout << "Enter a value or 0 to exit: ";
	cin >> valueToEnter;

	while (valueToEnter != 0){
		values.push_back(valueToEnter);
		cout << "Enter a value or 0 to exit: ";
		cin >> valueToEnter;
	}

	for (int i = 0; i < values.size(); i++){
		sum += values[i];
	}
	cout << "Sum is: " << sum << endl;
	cout << "Location of value 3 is element " << searchLinear(values, 3) << endl;
	cout << "Largest value is: " << searchMax(values) << endl;

	cin.get();
	cin.ignore();
	return 0;
}

int searchLinear(vector<int>& list, int value){//& is pass by reference which keeps performance good for vectors in functions
	for (int i = 0; i < list.size(); i++){
		if (list[i] == value){
			return i; //Immediately returns element position i and ends the if loop since return ends function
		}
	}

	return -1; //otherwise returns -1 if failure
}

int searchMax(vector<int>& list){
	if (list.size() == 0){
		throw logic_error("Error! List is empty so can't search for max value!"); //If list is empty then you can't search for largest value
	}
	int maxValue = list[0];
	for (int i = 0; i < list.size(); i++){
		if (list[i] > maxValue){
			maxValue = list[i]; //You have to search every element in order to check what the actual largest value is
		}
	}
	return maxValue;//Unlike earlier, you can't just immediately end the funciton on first successful find
}

void swap(vector<int>& list, int p, int q){//Because this is call by ref this properly changes list outside function
	int firstValue = list[p]; //Create temp copy of p (first value)
	
	list[p] = list[q]; //q overwrites p
	list[q] = firstValue; //temp p overwrites q
}
