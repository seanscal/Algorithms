// Scalabrini_Kevin_Lab_2_Simple_Menu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include "iostream"
#include <vector>
#include <string>

using namespace std;

string userarr[] = { "alice", "thomas", "yoda" };
string pwarr[] = { "wonderland", "anderson", "minch"};
string welcomearr[] = { "Follow me down the rabbit hole", "There is no spoon", "Do. Or do not. There is no try" };
vector<string> usernames(userarr,userarr+3) ;
vector<string> passwords(pwarr, pwarr+3);
vector<string> welcomes(welcomearr, welcomearr + 3);

void CreateMenu()
{
	cout << "[1] Login\n[2] Register\n[3] Login as a Guest\n[0] Quit" << endl;
	cout << "\nPlease Enter a Selection" << endl;
}

void Login(int correctindex)
{
	string username;
	string password;
	char response;

	cout << "Username: ";
	cin >> username;

	for (int i = 0; i < usernames.size(); i++)
	{
		if (usernames[i] == username)
			correctindex = i;
	}

	if (correctindex == -1)
	{
		cout << "\nUsername not found." << endl<<endl;
		/*cin >> response;
		if (response == 'n')
		{
			exit;
		}
		else
		{
			Login(correctindex);
		}*/
	}
	else
	{
		cout << "Password: ";
		cin >> password;
		if (passwords[correctindex] == password)
			cout << welcomes[correctindex]<<endl<<endl;
		else
			cout << "Incorrect Password. "<<endl<<endl;
	}
}

void Register()
{
	string user;
	string pw;
	string vpw;
	string welcome;

	cout << "\nEnter the desired username: ";
	cin >> user;
	
	cout << "\nEnter your desired password: ";
	cin >> pw;
	cout << "\nVerify your Password: ";
	cin >> vpw;

	if (pw == vpw)
	{

		usernames.push_back(user);
		passwords.push_back(pw);
		cout << "\nEnter your desired welcome message: ";
		cin >> welcome;
		welcomes.push_back(welcome);
		cout << "\nYou have been registered, you may now log in" << endl << endl;
	}
	else
	{
		cout << "Passwords do not match." << endl << endl;
	}
}

void main()
{
	int input = -1;
	while (input != 0)
	{
		CreateMenu();
		cin >> input;
		if (input == 1)
		{
			int correctindex = -1;
			cout << "You Selected : [1] Login" << endl << endl;
			cout << "Please enter your username, and then enter your password" << endl;
			Login(correctindex);
		}

		else if (input == 2)
		{
			cout << "You Selected : [2] Register" << endl << endl;
			Register();
		}
		else if (input == 3)
		{
			cout << "You Selected : [3] Login as a Guest" << endl << endl;
		}
		else
		{
			if (input != 0)
				cout << "Not an option, please enter a valid option" << endl;
		}
	}

	if (input == 0)
	{
		cout << "You Selected: [0] Quit" << endl;
		cout << "Press any key to exit" << endl;
		_getch();
	}
}



