// Lab 8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct Donut
{
	string flavor = "Chocolate";
	double price = 0.0;
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

void appendDonut(Donut* head, Donut* donut)
{
//	- appends donut structure referenced by pointer donut to the end of the list referenced by pointer head
	// create node
	Donut* temp = new Donut;
	temp->flavor = donut->flavor;
	temp->price = donut->price;
	temp->next = NULL;
Donut* temp=current;
	if (!head) 
	{ 
		head = temp;
		return;
	}
	
	else
	{ 
		while (!head==NULL)
		{
		
		if (head->next == NULL)
		{
		temp = donut;
		temp->next = NULL;
		head->next = temp;
		head = head->next;
		}
		else
		{
			head = head->next;
		}
		}
	}
}
void displayList(Donut* head) 
{
//	- iterates over the list referenced by pointer head displaying each of the donuts by using the donut’s display() method
	int i = 0;
	while (head)
	{
		
		cout << "[" << i << "] ";
		i = i + 1;
		head->display();
		head = head->next;
	} 
	
}

int lengthOfList(Donut* head) 
{
//	- iterates over the list referenced by pointer head counting how many donuts there are in the list and returns the count
	int counter = 0;
	while (head)
	{
		counter++;
		head = head->next;
	}
	return counter;
}

Donut* findFirstDonutFlavor(Donut* head, string flavor)
{
//	- iterates over the list referenced by pointer head comparing the string parameters flavor with each of the donut’s flavor member variable.
//	If found it returns the pointer to the donut where it was found.Otherwise returns NULL
	Donut* found = NULL;
	while (head->next != NULL)
	{
		if (flavor == head->next->flavor)
		{
			found = head->next;
			return found;
		}
		head = head->next;
	}
	return found;
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

	// create the list pointing to the first donut
	Donut* list = chocolate;

	// append the rest of the donuts to the end of list
	appendDonut(list, boston);
	appendDonut(list, jelly);
	appendDonut(list, glazed);
	appendDonut(list, eclair);
	appendDonut(list, snowy);
	appendDonut(list, glazed2);
	appendDonut(list, moon);

	// display each of the donuts
	displayList(list);

	// get the length of the list
	int length = lengthOfList(list);
	cout << length << " Donuts" << endl;

	// search for the first donut 
	Donut* foundDonut = findFirstDonutFlavor(list, "Glazed");
	if (foundDonut != NULL)
	{
		cout << "Found Donut:" << endl;
		foundDonut->display();
	}
	_getch();
}