#include "Libraries.h"

float arr[1000];
int arrSize;
int arrChoice = 0;

void fillArray() 
{
	cout << "fill";
}

void sortArray()
{
	cout << "sort";
}
void minMaxArray()
{
	cout << "minMax";
}
void replaceIntArray()
{
	cout << "replace";
}
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
		cout << "1. Fill array\n";
		SetConsoleTextAttribute(hdlOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

		if (arrChoice == 1)
			SetConsoleTextAttribute(hdlOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "2. Sort array\n";
		SetConsoleTextAttribute(hdlOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

		if (arrChoice == 2)
			SetConsoleTextAttribute(hdlOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "3. Find min/max\n";
		SetConsoleTextAttribute(hdlOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

		if (arrChoice == 3)
			SetConsoleTextAttribute(hdlOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "4. Replace number\n";
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