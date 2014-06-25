// Lab 10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct Donut
{
	string flavor;
	double price;
	Donut* prev = NULL;
	Donut* next = NULL;
	Donut(){}
	Donut(string flavor, double price)
	{
		this->flavor = flavor;
		this->price = price;
	}
	void display()
	{
		cout << flavor << "\t$" << price << endl;
	}
};

struct DonutTray
{
	Donut* head = NULL;
	Donut* tail = NULL;
	int length = 0;
	DonutTray(){}
	void append(Donut* donut);
	void prepend(Donut* donut);
	void insert(Donut* donut, int index);
	void remove(int index);
	void display()
	{
		Donut* current = head;
		int counter = 0;
		while (current)
		{
			cout << "[" << counter << "] ";
			current->display();
			current = current->next;
			counter++;
		}
		cout << "======================" << endl;
	}
};

void DonutTray::append(Donut* donut)
{
	Donut* current = head; 
	
	if (!current)
	{
		
		current = donut;
		head = current;
		tail = head;
		return;
	}

	while (current->next)
	{
		current = current->next;
	}
	donut->prev = current;
	current->next = donut; 
	tail = current->next;
}

void DonutTray::prepend(Donut* donut) \
{
	//-prepends the donut structure referenced by the donut 
	//pointer at the beginning of the donut tray updating head, 
	//trail, and length accordingly
	
	Donut* current = tail;
	if (!current)
	{
		current = donut;
		head = current;
		tail = head;
		return;
	}

	while (current->prev)
	{
		current = current->prev;
	}
	donut->next = current;
	current->prev = donut;
	head = current->prev;
}

void DonutTray::insert(Donut* donut, int index)
{
	
	//-inserts the donut structure referenced by the donut pointer at the location indicated by the integer parameter index
	int matchindex = 1;

	Donut* current = head;
	if (!current)
	{
		current = donut;
		head = current;
		tail = head;
		return;
	}

	while (current->next)
	{
		if (matchindex == index)
			break;
		current = current->next;
		matchindex++;
	}
	current->next->prev = donut;
	donut->next = current->next;
	donut->prev = current;
	current->next = donut;
	length++;
}
void DonutTray::remove(int index)
{
	//-removes the donut structure located at the location at index in the tray
	int matchindex = 1;

	Donut* current = head;
	if (index == 0)
	{
		current = current->next;
		return;
	}

	while (current->next)
	{	
		if (matchindex == index)
			break;
		current = current->next;
		matchindex++;
	}
	current->next = current->next->next;
	current->next->prev = current;
	length--;
	
}
int main()
{
	// create some donuts
	Donut* chocolate = new Donut("Chocolate", 0.99);
	Donut* boston = new Donut("Boston Crm", 1.99);
	Donut* jelly = new Donut("Jelly", 2.99);
	Donut* glazed = new Donut("Glazed", 1.99);
	Donut* eclair = new Donut("Eclair", 1.99);
	Donut* snowy = new Donut("Snowy", 0.99);
	Donut* glazed2 = new Donut("Glazed", 0.99);
	Donut* moon = new Donut("Moonraker", 2.99);
	Donut* vanilla = new Donut("Vanilla", 1.99);
	Donut* strawberry = new Donut("Strawberry", 0.99);
	Donut* caramel = new Donut("Caramel", 2.99);
	Donut* coffee = new Donut("Coffee", 1.99);

	// create a donut tray
	DonutTray* tray = new DonutTray;

	// append some donuts
	tray->append(chocolate);
	tray->append(boston);
	tray->append(jelly);
	tray->append(glazed);

	tray->display();

	// prepend some donuts
	tray->prepend(eclair);
	tray->prepend(snowy);
	tray->prepend(glazed2);
	tray->prepend(moon);

	tray->display();

	// insert some donuts
	tray->insert(vanilla, 2);
	tray->insert(strawberry, 4);
	tray->insert(caramel, 7);
	tray->insert(coffee, 9);
	tray->display();

	// remove some donuts
	tray->remove(3);
	tray->display();
	tray->remove(5);
	tray->display();
	getchar();
}
