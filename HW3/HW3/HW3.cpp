
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct Application {
	string name;
	float price;
};

int displayMainMenu()
{
	int choice;
	cout << "Main Menu" << endl;
	cout << "[1] Create New Array of Applications" << endl;
	cout << "[2] Add New Application to Array" << endl;
	cout << "[3] Display Array of Applications" << endl;
	cout << "[4] Update Existing Application" << endl;
	cout << "[0] Quit" << endl;
	cout << "Your choice : ";
	cin >> choice;
	return choice;
}

Application* createNewAppArray(int size)
{
	Application* newApp = new Application[size];
	Application* app = newApp;
	return app;
}

Application* createNewApp()
{
	Application* newApp = new Application;
	string name;
	float price;
	cout << endl;
	cout << "Please enter App Name: ";
	cin >> name;
	newApp->name = name;
	cout << "Please enter App Price : ";
	cin >> price;
	cout << endl;
	newApp->price = price;

	return newApp;
}
void addAppToAppArray(Application* app, Application* appArray, int appArrayCount)
{
	appArray[appArrayCount].name = app->name;
	appArray[appArrayCount].price = app->price;
}

void displayAppArray(Application* appArray, int appArraySize)
{
	cout << endl;
	for (int i = 0; i < appArraySize; i++)
	{
		cout << "[" << i << "] " << appArray[i].name << ", $" << appArray[i].price << endl;
	}
	cout << endl;
}
int chooseApp(Application* appArray, int appArraySize)
{
	int app;
	displayAppArray(appArray, appArraySize);
	cout << "Select an App: ";
	cin >> app;
	return app;
}

void updateApp(Application* appArray, int appIndex, Application* app)
{
	appArray[appIndex].name = app->name;
	appArray[appIndex].price = app->price;
	//Uses chooseApp() to choose the application to be updated, 
		//then uses createNewApp() to have the updates, and then replaces the application in appArray at appIndex with the new application
}

int main()
{
	// menu choices
	const int QUIT = 0;
	const int CREATE_NEW_APP_ARRAY = 1;
	const int CREATE_NEW_APP = 2;
	const int READ_ALL_APPS = 3;
	const int UPDATE_APP = 4;
	const int DELETE_APP = 5;

	Application* appArray = new Application;	// array of applications
	Application* app;		// pointer to an application

	int choice;				// current menu choice
	int appArraySize;		// size of the array containing applications
	int appArrayCount = 0;	// how many applications have been added to array
	int appIndex;			// which application to update
	int arrayCreated = 0;
	do
	{
		choice = displayMainMenu();	// display menu and return choice
		switch (choice)
		{
		case CREATE_NEW_APP_ARRAY:
			arrayCreated = 1;
			// ask how many applications,
			// read in the size,
			// create application array dynamically
			cout << "\nHow Many Applications? ";
			cin >> appArraySize;
			cout << endl;
			appArray = createNewAppArray(appArraySize);
			break;
		case CREATE_NEW_APP:
			// create a new application
			// add it to the array
			// keep count of how many apps we've created so far
			if (arrayCreated == 1)
			{
				if (appArrayCount < appArraySize)
				{
					app = createNewApp();
					addAppToAppArray(app, appArray, appArrayCount);
					appArrayCount++;
					break;
				}
				else
					cout << "\nList Full, Please create another. " << endl << endl;
			}
			else
				cout << "\nPlease first Choose option 1) create a new App Array." << endl << endl;
		case READ_ALL_APPS:
			// pass application array to function to display them all
			displayAppArray(appArray, appArrayCount);
			break;
		case UPDATE_APP:
			// display all the apps and ask user to choose one
			// create a new app to get all the updates user wants to perform
			// update the selected application with the data in the app just created
			appIndex = chooseApp(appArray, appArrayCount);
			app = createNewApp();
			updateApp(appArray, appIndex, app);
			break;
		}
	} while (choice != QUIT);
}