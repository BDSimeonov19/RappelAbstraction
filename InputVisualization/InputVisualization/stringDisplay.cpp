#include "Libraries.h"

string str;
int strChoice = 0;

void insertStr();

void eraseStr();

void replaceStr();

void findStr();


// Display current state of the array
void stringDisplay()
{
	cout << "\tCurrent string\n";
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] != NULL)
			cout << str[i];
		else
			cout << "_";
	}
	cout << endl;
}


//Check user choice
void stringFunction()
{
	switch (strChoice)
	{
	case 0:
		insertStr();
		break;
	case 1:
		eraseStr();
		break;
	case 2:
		replaceStr();
		break;
	case 3:
		findStr();
		break;
	}
}



//Change choice in menu
int stringOption()
{
	switch (_getch())
	{
	case 'w':
		if (strChoice != 0)
		{
			strChoice -= 1;
			return(strChoice);
		}
		break;
	case 's':
		if (strChoice != 3)
		{
			strChoice += 1;
			return(strChoice);
		}
		break;
	case '\r':
		return(4);
		break;
	}
	return(strChoice);
}



// Prompt to ask user what they want to do
void stringPrompt()
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
		stringDisplay();
		cout << "What do you want to do?\n";
		if (strChoice == 0)
			SetConsoleTextAttribute(hdlOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Insert string\n";
		SetConsoleTextAttribute(hdlOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

		if (strChoice == 1)
			SetConsoleTextAttribute(hdlOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Erase from string\n";
		SetConsoleTextAttribute(hdlOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

		if (strChoice == 2)
			SetConsoleTextAttribute(hdlOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Replace in string\n";
		SetConsoleTextAttribute(hdlOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

		if (strChoice == 3)
			SetConsoleTextAttribute(hdlOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Find in string\n";
		SetConsoleTextAttribute(hdlOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		if (stringOption() == 4)
		{
			system("cls");
			stringFunction();
			break;
		}
		system("cls");
	}
}

// Take size input from user
void stringInput()
{
	cout << "Enter string: \n";
	getline(cin, str, '\n');
	system("cls");
	stringPrompt();
}

//========================StringFeatures========================

//Insert in string
void insertStr() {
	size_t pos;
	string insertString;

	cout << "Pick a starting position (numbers only)\n";
	cin >> pos;
	system("cls");

	if (pos > str.length() - 1 || pos < 0) {
		cout << "Invalid position";
		system("pause");
		system("cls");
		replaceStr();
	}

	cout << "Input a string to insert\n";

	cin.ignore();
	getline(cin, insertString, '\n');

	str.insert(pos, insertString);

	system("cls");
	stringPrompt();
}

//Erase from string
void eraseStr() {
	size_t pos, len;

	cout << "Pick a starting position (numbers only)\n";
	cin >> pos;
	system("cls");

	if (pos > str.length() - 1 || pos < 0) {
		cout << "Invalid position";
		system("pause");
		system("cls");
		replaceStr();
	}
	cout << "Pick a length to erase (numbers only)\n";
	cin >> len;
	system("cls");

	if (len > str.length() || len < 0) {
		cout << "Invalid length";
		system("pause");
		system("cls");
		replaceStr();
	}

	str.erase(pos, len);

	system("cls");
	stringPrompt();
}




//Replace in string
void replaceStr() {
	size_t pos, len;
	string replaceString;

	cout << "Pick a starting position (numbers only)\n";
	cin >> pos;
	system("cls");

	if (pos > str.length() - 1 || pos < 0) {
		cout << "Invalid position";
		system("pause");
		system("cls");
		replaceStr();
	}
	cout << "Pick a length to replace (numbers only)\n";
	cin >> len;
	system("cls");

	if (len > str.length() || len < 0) {
		cout << "Invalid length";
		system("pause");
		system("cls");
		replaceStr();
	}
	cout << "Input a string to replace with\n";

	cin.ignore();
	getline(cin, replaceString, '\n');

	str.replace(pos, len, replaceString);

	system("cls");
	stringPrompt();
}

void findStr() {
	string findString;

	cout << "Input a string to find\n";

	getline(cin, findString, '\n');

	size_t search = str.find(findString);

	if (search != string::npos)
		cout << "Found " << findString << " at position " << search << "\n";
	else
		cout << "Not found in string\n";

	system("pause");
	system("cls");
	stringPrompt();
}