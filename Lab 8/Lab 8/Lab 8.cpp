//
//  main.cpp
//  Q2_Practice
//
//  Created by Beth Amyouny on 6/4/14.
//  Copyright (c) 2014 Amyouny. All rights reserved.
//
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct Donut{
	string name;
	double price;
	int    age;
	Donut* next = NULL; //points to next donut

	Donut(string name, double price, int age)
	{
		this->name = name;
		this->price = price;
		this->age = age;

	}
	void display()
	{
		cout << this << " Donut: " << endl;
		cout << " Name: " << name << endl;
		cout << " Price: " << price << endl;
		cout << " Age: " << age << endl;
		cout << " Next: " << next << endl; //next is a pointer it lives at an address and it holds an          address
	}
};

struct DonutList{

	Donut* head;
	string name;
	int length;

	DonutList()
	{
		head = NULL;
		length = 0;
		name = "New Donut List";
	}
	DonutList(string name)
	{
		head = NULL;
		length = 0;
		this->name = name;
	}
	void display()
	{
		Donut* current = head;
		int counter = 0;

		while (current != NULL)
		{
			cout << "==================" << endl;
			cout << "counter: " << counter << endl;

			current->display();
			current = current->next;
			counter++;
		}
	}

	void append(Donut* newDonut)
	{
		if (head == NULL)
		{
			head = newDonut;
			return;
		}
		Donut* current = head;

		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newDonut;
		length++;
	}

	void concatenate(DonutList* anotherList)
	{
		Donut* temp = head;
		while (head->next)
		{
			head = head->next;
		}
		this->head->next = anotherList->head;
		head = temp;
	}

};

int main()
{

	Donut* chocolate = new Donut("Chocolate", 0.99, 2);
	Donut* bostonCream = new Donut("Boston Cream", 1.09, 2);
	Donut* jelly = new Donut("Jelly", 0.89, 2);
	Donut* glazed = new Donut("Glazed", 0.99, 2);
	Donut* grape = new Donut("Grape", 1.09, 2);
	Donut* cookie = new Donut("Cookie", 0.89, 2);


	DonutList* list = new DonutList("World Runs on Dunkin");

	list->append(chocolate);
	list->append(bostonCream);
	list->append(jelly);
	cout << "Donut List: " << list->name << endl;
	list->display();

	DonutList* list2 = new DonutList("Starbucks");

	list2->append(glazed);
	list2->append(grape);
	list2->append(cookie);
	cout << "\nDonut List: " << list2->name << endl;
	list2->display();


	cout << "\n\n CONCATENATE\n";
	list->concatenate(list2);
	cout << "Donut List: " << list->name << endl;
	list->display();



	getchar();

}