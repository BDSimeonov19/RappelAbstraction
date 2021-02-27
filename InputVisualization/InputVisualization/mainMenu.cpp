#include "Libraries.h"
#include "arrayDisplay.h"
#include "stringDisplay.h"
int choice;

//=========================Functions=========================

//Change choice in menu
int menuChoosing()
{
	switch (_getch())
	{
	case 'w':
		if (choice != 0)
		{
			choice -= 1;
			return(choice);
		}
		break;
	case 's':
		if (choice != 1)
		{	
			choice += 1;
			return(choice);
		}
		break;
	case '\r':
		return(2);
	}
	return(choice);
}

void checkChoice()
{
	//User has chosen string
	if (choice == 0)
	{
		stringInput();
	}
	//User has chosen array
	else if (choice == 1)
	{
		arraySize();
	}
}

//Menu
void menu()
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
		cout << "Input Visualization\n";
		cout << "Choose the data type you want to visualize:\n";
		cout << "(Use w & s to move up and down. Press enter to select)\n";
		if (choice == 0)
		{
			SetConsoleTextAttribute(hdlOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
		cout << "String" << endl;
		SetConsoleTextAttribute(hdlOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		if (choice == 1)
		{
			SetConsoleTextAttribute(hdlOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
		cout << "Array" << endl;
		SetConsoleTextAttribute(hdlOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		if (menuChoosing() == 2)
		{
			system("cls");
			checkChoice();
			break;
		}
		Sleep(100);
		system("cls");
	}
}
