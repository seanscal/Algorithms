// Scalabrini_Kevin_Lab_2_Simple_Menu.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "conio.h"
#include "iostream"
using namespace std;


void CreateMenu()
{
	cout << "[1] Create an Application\n[2] List all Applications\n[3] Find Applications\n[4] Create a Page\n[5] List all Pages\n[6] Find Pages\n[0] Quit" << endl;
	cout << "\nPlease Enter a Selection"<<endl;
}

void main()
{
	int input=-1;

	while (input != 0)
	{
		CreateMenu();
		cin >> input;
		if (input == 1)
		{
			cout << "You Selected : [1] Create an Application" << endl << endl;
		}
		else if (input == 2)
		{
			cout << "You Selected : [2] List all Applications" << endl << endl;
		}
		else if (input == 3)
		{
			cout << "You Selected : [3] Find Applications" << endl << endl;
		}
		else if (input == 4)
		{
			cout << "You Selected : [4] Create a Page" << endl << endl;
		}
		else if (input == 5)
		{
			cout << "You Selected : [5] List all Pages" << endl << endl;
		}
		else if (input == 6)
		{
			cout << "You Selected : [6] Find Pages" << endl<<endl;
		}
		else
		{
			if (input !=0)
				cout << "Not an option, please enter a valid option\n" << endl;
		}
	}

	if (input == 0)
	{
		cout << "You Selected: [0] Quit" << endl;
		cout << "Press any key to exit" << endl;
		_getch();
	}
}


