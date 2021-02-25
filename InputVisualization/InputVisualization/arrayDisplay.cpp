#include "Libraries.h"

int arr[1000];
int arrSize;

// To do
void arrayPrompt() 
{

}

// Display current state of the array
void arrayDisplay() 
{
	cout << "\tCurrent array\n";
	for (int i = 0; i < arrSize; i++) 
	{
		if (arr[i] != NULL)
			cout << arr[i] << " ";
		else
			cout << "_ ";
	}
	cout << endl;
}

// Take size input from user
void arraySize()
{
	cout << "Enter array size (Max: 1000) : ";
	cin >> arrSize;
	//Check if input is valid
	if (arrSize > 1000 || arrSize < 0)
	{
		cout << "Invalid size";
		arraySize();
	}
	else
	{
		arrayDisplay();
	}
}