#include "Libraries.h"

float arr[1000];
int arrSize;
int arrChoice = 0;
int arrSortChoice = 0;
bool arrFilled = false;

void fillArray();

void sortArray();

void minMaxArray();

void replaceIntArray();

//Check user choice
void arrFunction() 
{
	switch (arrChoice) 
	{
	case 0:
		fillArray();
		break;
	case 1:
		sortArray();
		break;
	case 2:
		minMaxArray();
		break;
	case 3:
		replaceIntArray();
		break;
	}
}



//Change choice in menu
int arrayOption()
{
	switch (_getch())
	{
	case 'w':
		if (arrChoice != 0)
		{
			arrChoice -= 1;
			return(arrChoice);
		}
		break;
	case 's':
		if (arrChoice != 3)
		{
			arrChoice += 1;
			return(arrChoice);
		}
		break;
	case '\r':
		return(4);
		break;
	}
	return(arrChoice);
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
	cout << "\n\n";
}


// Prompt to ask user what they want to do
void arrayPrompt() 
{
	HANDLE hdlOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hdlOut == INVALID_HANDLE_VALUE)
	{
		cerr << "Encountered an Error: " << GetLastError();
		Sleep(1000);
		system("cls");
	}
	while (true)
	{
		arrayDisplay();
		cout << "What do you want to do?\n";
		if (arrChoice == 0)
			SetConsoleTextAttribute(hdlOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Fill array\n";
		SetConsoleTextAttribute(hdlOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

		if (arrChoice == 1)
			SetConsoleTextAttribute(hdlOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Sort array\n";
		SetConsoleTextAttribute(hdlOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

		if (arrChoice == 2)
			SetConsoleTextAttribute(hdlOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Find min/max\n";
		SetConsoleTextAttribute(hdlOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

		if (arrChoice == 3)
			SetConsoleTextAttribute(hdlOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Replace number\n";
		SetConsoleTextAttribute(hdlOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		if (arrayOption() == 4)
		{
			system("cls");
			arrFunction();
			break;
		}
		system("cls");
	}
}


// Take size input from user
void arraySize()
{
	cout << "Enter array size (Max: 1000) : ";
	cin >> arrSize;
	//Check if input is valid
	if (arrSize > 1000 || arrSize < 0)
	{
		system("cls");
		cout << "Invalid size\n";
		arraySize();
	}
	else
	{
		system("cls");
		arrayPrompt();
	}
}

//========================ArrayFeatures========================

//Fill array
void fillArray()
{
	arrFilled = true;
	for (int i = 0; i < arrSize; i++) {
		system("cls");
		arrayDisplay();
		cout << "\n";
		cout << "Input " << arrSize - i << " number(s) to be placed in the array.\n";
		cin >> arr[i];
	}
	system("cls");
	arrayPrompt();
}

// Sort array options
int sortOption()
{
	switch (_getch())
	{
	case 'w':
		if (arrSortChoice != 0)
		{
			arrSortChoice -= 1;
			return(arrSortChoice);
		}
		break;
	case 's':
		if (arrSortChoice != 1)
		{
			arrSortChoice += 1;
			return(arrSortChoice);
		}
		break;
	case '\r':
		return(2);
		break;
	}
	return(arrSortChoice);
}

// Bubble sort
void sorting(bool asc) {
	// Sort ascending
	if (asc) {
		for (int i = 0; i < arrSize; i++) {
			for (int j = 0; j < arrSize - i - 1; j++) {
				if (arr[j] > arr[j + 1])
				{
					int temp;
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}

	// Sort descending
	else {
		for (int i = 0; i < arrSize; i++) {
			for (int j = 0; j < arrSize - i - 1; j++) {
				if (arr[j] < arr[j + 1])
				{
					int temp;
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}

	arrayPrompt();
}

// Sort choice check
void sortFunction() {
	switch (arrSortChoice)
	{
	case 0:
		sorting(1);
		break;
	case 1:
		sorting(0);
		break;
	}
}

// Sort array menu
void sortArray() {
	if (arrFilled == false) {
		cout << "The array currently doesn't contain anything.\n";
		system("pause");
		system("cls");
		arrayPrompt();
	}

	HANDLE hdlOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hdlOut == INVALID_HANDLE_VALUE)
	{
		cerr << "Encountered an Error: " << GetLastError();
		Sleep(1000);
		system("cls");
	}
	while (true)
	{
		arrayDisplay();
		cout << "How do you want to sort your array?\n";
		if (arrSortChoice == 0)
			SetConsoleTextAttribute(hdlOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Ascending order\n";
		SetConsoleTextAttribute(hdlOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

		if (arrSortChoice == 1)
			SetConsoleTextAttribute(hdlOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Descending order\n";
		SetConsoleTextAttribute(hdlOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

		if (sortOption() == 2)
		{
			system("cls");
			sortFunction();
			break;
		}
		system("cls");
	}
}

// Find min/max
void minMaxArray() {
	if (arrFilled == false) {
		cout << "The array currently doesn't contain anything.\n";
		system("pause");
		system("cls");
		arrayPrompt();
	}

	float min = arr[0];
	float max = arr[0];
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}

	cout << "The smallest value of the array is " << min << "\n";
	cout << "The largest value of the array is " << max << "\n";
	system("pause");
	system("cls");
	arrayPrompt();
}

// Replace in array
void replaceIntArray() {
	if (arrFilled == false) {
		cout << "The array currently doesn't contain anything.\n";
		system("pause");
		system("cls");
		arrayPrompt();
	}

	float replaced, replacing;
	cout << "Choose which number to be replaced\n";
	cin >> replaced;
	system("cls");

	cout << "Choose which number to replace with\n";
	cin >> replacing;
	system("cls");

	for (int i = 0; i < arrSize; i++) {
		if (arr[i] == replaced)
			arr[i] = replacing;
	}
	
	arrayPrompt();
}