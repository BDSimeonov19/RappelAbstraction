#include "arrayDisplay.h"
int arr[1000];
int arrSize;

void arrayPrompt() 
{
	
}
void arrayDisplay() 
{
	cout << "\tCurrent array\n";
	for (int i = 0; i < arrSize; i++) 
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

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

