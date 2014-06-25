// Lab 12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

enum DepartmentType
{
	HR, ENGINEERING, SALES, MARKETING
};

class Employee
{
private:
	string firstName;
	string lastName;
	double salary;
	DepartmentType departmentType;
public:
	Employee* left = NULL;
	Employee* right = NULL;
	Employee(){}
	Employee(string fName, string lName, double salary, DepartmentType dept)
	{
		setFirstName(fName);
		setLastName(lName);
		setSalary(salary);
		setDepartmentType(dept);
	}
	void setFirstName(string fName)
	{
		this->firstName = fName;
	}
	void setLastName(string lName)
	{
		this->lastName = lName;
	}
	void setSalary(double salary)
	{
		if (salary > 0)
		{
			this->salary = salary;
		}
	}
	void setDepartmentType(DepartmentType departmentType)
	{
		this->departmentType = departmentType;
	}
	string getFirstName() { return firstName; }
	string getLastName()  { return lastName; }
	double getSalary()    { return salary; }
	DepartmentType getDepartmentType() { return departmentType; }
	void display()
	{
		cout << firstName << " " << lastName << " $" << salary << endl;
	}
};

void insert(Employee* node, Employee** root)
{
	if (*root == NULL)
	{
		*root = node;
		return;
	}

	if (node->getFirstName() < (*root)->getFirstName())
	{
		insert(node, &((*root)->left));
	}
	else if (node->getFirstName() >= (*root)->getFirstName())
	{
		insert(node, &(*root)->right);
	}
}

void traverseInOrder(Employee* root)
{
	if (root != NULL)
	{
		traverseInOrder(root->left);
		root->display();
		traverseInOrder(root->right);
	}
}

Employee* depthFirstSearch(string firstName, Employee* root)
{
	if (root != NULL)
	{
		if (firstName == root->getFirstName())
		{
			return root;
		}
		else if (firstName > root->getFirstName())
		{
			return depthFirstSearch(firstName, root->right);
		}
		else if (firstName < root->getFirstName())
		{
			return depthFirstSearch(firstName, root->left);
		}
	}
	return NULL;
}
int main()
{
	Employee* alice = new Employee("Alice", "Wonderland", 3211232, ENGINEERING);
	Employee* bob = new Employee("Bob", "Marley", 3211232, MARKETING);
	Employee* charlie = new Employee("Charlie", "Gargia", 3211232, MARKETING);
	Employee* dan = new Employee("Daniel", "Craig", 123123, HR);
	Employee* edward = new Employee("Edward", "Norton", 21211212, ENGINEERING);
	Employee* frank = new Employee("Frank", "Herbert", 233223, SALES);
	Employee* gregory = new Employee("Gregory", "Peck", 344334, MARKETING);

	Employee* root = NULL;

	insert(dan, &root);
	insert(bob, &root);
	insert(alice, &root);
	insert(charlie, &root);
	insert(frank, &root);
	insert(edward, &root);
	insert(gregory, &root);
	/*
	The tree now looks like this:

						Daniel
			Bob						Frank
	Alice		Charlie		Edward		Gregory
	*/


	cout << endl << "In Order: " << endl;
	traverseInOrder(root);

	cout << endl << "Depth First Search: " << endl;
	Employee* found = depthFirstSearch("Edward", root);
	if (found != NULL)
	{
		found->display();
	}
	else
	{
		cout << "Not Found" << endl;
	}
	getchar();
}