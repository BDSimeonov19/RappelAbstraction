
//=========================Libraries=========================
#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
/*
===TO FIGURE OUT===
#pragma once
#undef FOREGROUND_BLUE;
#undef FOREGROUND_GREEN;
#undef FOREGROUND_RED;
#undef FOREGROUND_INTENSITY;
#define blue 0x0001;
#define green 0x0002;
#define red 0x0004;
#define intensity 0x0008;
*/

using namespace std;
//=========================Functions=========================

int menuChoosing(int* choice) 
{
	switch (_getch()) 
	{
		case 'w':
			if (*choice != 0) 
			{
				return(*choice - 1);
			}
			break;
		case 's':
			if (*choice != 1)
			{
				return(*choice + 1);
			}
			break;
		case '\r':
			return(2);
	}
	return(*choice);
}

//Menu
void menu() 
{
	HANDLE hdlOut = GetStdHandle(STD_OUTPUT_HANDLE);
	int* option = new int;
	*option = 0;
	while (true) 
	{
		cout << "Input Visualization" << endl;
		cout << "Choose the data type you want to visualize:" << endl;
		if (*option == 0) 
		{
			SetConsoleTextAttribute(hdlOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
		cout << "String" << endl;
		SetConsoleTextAttribute(hdlOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		if (*option == 1)
		{
			SetConsoleTextAttribute(hdlOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		}
		cout << "Array" << endl;
		SetConsoleTextAttribute(hdlOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		*option=menuChoosing(option);
		if (*option == 2) 
		{
			system("cls");
			break;
		}
		Sleep(100);
		system("cls");
	}
	delete option;
}

//===========================Main============================
int main() 
{
	menu();
	cout << "Hello";
}