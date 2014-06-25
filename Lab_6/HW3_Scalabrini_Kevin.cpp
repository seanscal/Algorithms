#include "Lab_6_Scalabrini_Kevin\stdafx.h"
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
	cout << "Main Menu/n[1] Create New List of Applications/n[2] Add New Application to List/n";
	cout << "[3] Display List of Applications/n[4] Update Existing Application/n[0] Quit";
	cout << "/nYour choice : ";
	cin >> choice;
	return choice;
}


Application* createNewAppArray(int size)
{
	 Application *newApps = new Application[size];
	 return newApps;
}

Application* createNewApp()
{
	Application *Newapp;
	string AppName;
	int AppPrice;
	cout << "Please enter Application Name: ";
	cin >> AppName;
	Newapp->name = AppName;
	cout << "Please enter Application Price: ";
	cin >> AppPrice;
	Newapp->price = AppPrice;
	return Newapp;
}


void addAppToAppArray(Application* app, Application* appArray, int appArraySize)
{
	//Adds a new Application app to an existing array appArray of size appArraySize
	Application *newApps = createNewAppArray(appArraySize);
	for (int i = 0; i < appArraySize; i++)
	{
		newApps[i] = appArray[i];
	}

	
	newApps[appArraySize - 1] = app[0];
	appArray = createNewAppArray(appArraySize + 1);
	for (int i = 0; i < appArraySize+1; i++)
	{
		appArray[i] = newApps[i];
	}
}




void displayAppArray(Application* appArray, int appArraySize)
{
	for (int i = 0; i < appArraySize; i++)
	{
		cout << "["<<i<<"] "<<appArray[i].name <<", $"<<appArray[i].price<< endl;
	}
}



int chooseApp(Application* appArray, int appArraySize)
{
	int number;
	displayAppArray(appArray, appArraySize);
	cout << "Please choose an index: ";
	cin >> number;
	return number;
}



void updateApp(Application* appArray, int appIndex, Application* app)
{

}

/*  - Uses chooseApp() to choose the application to be updated, then uses createNewApp() to have the updates, 
and then replaces the application in appArray at appIndex with the new application

*/