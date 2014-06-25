// Lab_8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// structure representing a donut
struct Donut
{
	string flavor = "";
	float price = 0.0;

	// constructor to initialize member variables
	Donut(string flvr, float prc)
	{
		flavor = flvr;
		price = prc;
	}

	// default, no argument constructor
	Donut(){}
};

// structure representing a collection of donuts
struct DonutTray
{
	// dynamic array of pointers to donuts
	// first * is for the dynamic array
	// second * is for pointer to donut
	Donut** donuts;

	// maximum number of donuts in tray
	int capacity;

	// boundary indices of queue
	int front = 0, back = 0;

	// how many donuts are currently in the queue
	int count = 0;

	// constructor to initialize the tray
	DonutTray(int size)
	{
		// set the capacity and allocate the array
		capacity = size;
		donuts = new Donut*[capacity];
	}
};

// putting and removing donuts from the tray
void   enqueueDonut(DonutTray* tray, Donut* donut)
{
	//enqueues the donut structure referenced by the donut pointer into the donuts array in the tray structure at the back index.
	//Increments the count and back index making sure the back index does not go beyond the tray’s capacity
		
	if (tray->count < tray->capacity)
		{
			tray->donuts[tray->back] = donut;
			tray->count++;
			tray->back++;
		}
}

Donut* dequeueDonut(DonutTray* tray)
{
	if (tray->front < tray->capacity)
			{
				tray->count--;
				tray->front++;
			}		
	Donut* returned = tray->donuts[tray->front-1];
	return returned;
}

// display a single donut and the whole tray
void   displayDonut(Donut* donut)
{
	cout << donut->flavor << " Donut, $" << donut->price<<endl;
}


void   displayDonutTray(DonutTray* tray)
{
	int count = tray->count;
	for (int i = tray->front; i < tray->back; i++)
	{
		displayDonut(tray->donuts[i]);
	}
}

int main()
{
	// create some donuts
	Donut* chocolate = new Donut("Chocolate", 0.99);
	Donut* boston = new Donut("Boston Crm", 0.99);
	Donut* jelly = new Donut("Jelly", 0.99);
	Donut* glazed = new Donut("Glazed", 0.99);
	Donut* eclair = new Donut("Eclair", 0.99);
	Donut* snowy = new Donut("Snowy", 0.99);
	Donut* moon = new Donut("Moonraker", 0.99);

	// create a small tray that can hold 5 donuts
	DonutTray* tray = new DonutTray(5);

	// add 4 donuts to the tray and display it
	enqueueDonut(tray, chocolate);
	enqueueDonut(tray, boston);
	enqueueDonut(tray, jelly);
	enqueueDonut(tray, glazed);
	displayDonutTray(tray);
	cout << endl;

	// remove a donut from the tray, display the donut and tray
	Donut* donut = dequeueDonut(tray);
	cout << "Donut Taken: " << endl;
	displayDonut(donut);
	cout << endl;
	cout << "Donuts Left: " << endl;
	displayDonutTray(tray); 
	cout << endl;

	// add two more donuts and display the tray

	enqueueDonut(tray, eclair);
	enqueueDonut(tray, snowy);
	displayDonutTray(tray);
	cout << endl;

	// remove and display two donuts, and add one more
	cout << "\n";
	donut = dequeueDonut(tray);
	displayDonut(donut);
	cout << "\n";
	displayDonutTray(tray);
	cout << "\n";
	donut = dequeueDonut(tray);
	displayDonut(donut);
	enqueueDonut(tray, moon);
	cout << endl;

	// display final tray
	displayDonutTray(tray);
	_getch();
} 