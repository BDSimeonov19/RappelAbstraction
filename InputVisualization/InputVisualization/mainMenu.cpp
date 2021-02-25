#include "Libraries.h"
#include "arrayDisplay.h"
int choice;

//=========================Functions=========================

//Changing choice on menu
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

//Menu
void menu()
{
	HANDLE hdlOut = GetStdHandle(STD_OUTPUT_HANDLE);
	while (true)
	{
		cout << "Input Visualization" << endl;
		cout << "Choose the data type you want to visualize:" << endl;
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
			break;
		}
		Sleep(100);
		system("cls");
	}
}

void checkChoice() 
{
	//User has chosen string
	if (choice == 0) 
	{
	
	}
	//User has chosen array
	else if(choice == 1)
	{
		arraySize();
	}
}
