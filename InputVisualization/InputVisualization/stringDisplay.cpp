#include "Libraries.h"

string str;

// To do
void stringPrompt()
{

}

// Display current state of the array
void stringDisplay()
{
	cout << "\tCurrent array\n";
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] != NULL)
			cout << str[i] << " ";
		else
			cout << "_ ";
	}
	cout << endl;
}

// Take size input from user
void stringInput()
{
	cout << "Enter string: ";
	getline(cin, str, '\n');
	stringDisplay();
}