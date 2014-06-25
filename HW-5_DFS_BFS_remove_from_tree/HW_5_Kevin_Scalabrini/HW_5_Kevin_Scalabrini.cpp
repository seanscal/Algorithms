// HW_5_Kevin_Scalabrini.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <string>
#include <queue>
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
	void display()
	{
		cout << firstName << " " << lastName << " $" << salary << endl;
	}
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
};

struct EmployeeNode
{
	Employee* employee;
	EmployeeNode* left = NULL;
	EmployeeNode* right = NULL;
	EmployeeNode(){}
	EmployeeNode(Employee* employee)
	{
		this->employee = employee;
	}
};

class EmployeeBinarySearchTree
{
private:
	EmployeeNode* root = NULL;
	void insert(EmployeeNode* node, EmployeeNode** root);
	void traverseInOrder(EmployeeNode* root);
	void traversePreOrder(EmployeeNode* root);
	void traversePostOrder(EmployeeNode* root);
	Employee* breadthFirstSearch(string firstName, EmployeeNode* root);
	Employee* depthFirstSearch(string firstName, EmployeeNode* root);
	void remove(string firstName, EmployeeNode** root);
	static EmployeeNode* minimum(EmployeeNode* root);

public:
	void insert(Employee* employee);
	void remove(string firstName);
	Employee* breadthFirstSearch(string firstName);
	Employee* depthFirstSearch(string firstName);
	void traverseInOrder();
	void traversePreOrder();
	void traversePostOrder();
};

void EmployeeBinarySearchTree::insert(Employee* employee)
{
	EmployeeNode* n = new EmployeeNode(employee);
	insert(n, &root);
}

void EmployeeBinarySearchTree::insert(EmployeeNode* node, EmployeeNode** root)
{
	EmployeeNode* n = new EmployeeNode;
	n = node;
	n->left = NULL;
	n->right = NULL;
	if (!*root)
	{
		*root = node;
		return;
	}
	if (n->employee->getFirstName() > (*root)->employee->getFirstName())
	{
		insert(n, &((*root)->right));
	}
	else if (n->employee->getFirstName() < (*root)->employee->getFirstName())
	{
		insert(n, &((*root)->left));
	}
	else
	{
		insert(n, &((*root)->right));
	}
}

void EmployeeBinarySearchTree::traverseInOrder()
{
	traverseInOrder(root);
}

void EmployeeBinarySearchTree::traverseInOrder(EmployeeNode* root)
{
	// Displays in order all the employees in the tree rooted at root
    
    if (root != NULL)
    {
        traverseInOrder(root->left);
        root->employee->display();
        traverseInOrder(root->right);
    }

}

void EmployeeBinarySearchTree::traversePreOrder(EmployeeNode* root)
{
	if (root)
	{
		root->employee->display();
		
		traversePreOrder(root->left);traversePreOrder(root->right);
	}
}

void EmployeeBinarySearchTree::traversePreOrder()
{
	traversePreOrder(root);
}

void EmployeeBinarySearchTree::traversePostOrder(EmployeeNode* root)
{
	if (root != NULL)
	{
		traversePostOrder(root->left);
		traversePostOrder(root->right);
		
		root->employee->display();
	}
}

void EmployeeBinarySearchTree::traversePostOrder()
{
	traversePostOrder(root);
}

Employee* EmployeeBinarySearchTree::depthFirstSearch(string firstName)
{
	return EmployeeBinarySearchTree::depthFirstSearch(firstName, root);
}

Employee* EmployeeBinarySearchTree::depthFirstSearch(string firstName, EmployeeNode* root)
{
	if (!root)
	{
		return NULL;
	}

	string rootfname = root->employee->getFirstName();

	if (rootfname == firstName)
	{
		return root->employee;
	}
	else if (firstName < rootfname)
	{
		return EmployeeBinarySearchTree::depthFirstSearch(firstName, root->left);
	}
	else
	{
		return EmployeeBinarySearchTree::depthFirstSearch(firstName, root->right);
	}
	return NULL;
}

Employee* EmployeeBinarySearchTree::breadthFirstSearch(string firstName)
{
	return EmployeeBinarySearchTree::breadthFirstSearch(firstName, root);
}

Employee* EmployeeBinarySearchTree::breadthFirstSearch(string firstName, EmployeeNode* root)
{
	if (!root)
	{
		return 0;
	}
	queue<EmployeeNode* > q;
	q.push(root);
	while (!q.empty())
	{
		EmployeeNode* en = q.front();
		q.pop();
		if (en->employee->getFirstName() == firstName)
		{
			return en->employee;
		}
		if (en->left)
		{
			q.push(en->left);
		}
		if (en->right)
		{
			q.push(en->right);
		}
	}
	return 0;
}

EmployeeNode* EmployeeBinarySearchTree::minimum(EmployeeNode *root)
{
	if (!root->left)
	{
		EmployeeNode* min = root;
		root = NULL;
		return min;
	}

	return minimum(root->left);
}

void EmployeeBinarySearchTree::remove(string firstName)
{
	EmployeeBinarySearchTree::remove(firstName, &root);
}

void EmployeeBinarySearchTree::remove(string firstName, EmployeeNode** root)
{
	{
		if (!(*root))
		{
			return;
		}
		string empfname = (*root)->employee->getFirstName();
		if (firstName < empfname)
		{
			remove(firstName, &(*root)->left);
		}
		else if (firstName > empfname)
		{
			remove(firstName, &(*root)->right);
		}
		else if ((*root)->left && (*root)->right)
		{
			EmployeeNode* rightMinNode = minimum((*root)->right);
			(*root)->employee = rightMinNode->employee;
			EmployeeNode* min = (*root)->right;
			
			if (!min->left)
				(*root)->right = NULL;
			else if (!min->left->left)
				(*root)->right->left = NULL;

			remove(firstName, &(*root)->right);
		}
		else
		{
			EmployeeNode *toDelete = *root;
			if (!(*root)->left)
			{
				*root = (*root)->right;
			}
			else if (!(*root)->right)
			{
				*root = (*root)->left;
			}
			else
			{
				*root = 0;
			}
			toDelete->left = 0;
			toDelete->right = 0;
			delete toDelete;
		}
	}
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

	EmployeeBinarySearchTree* tree = new EmployeeBinarySearchTree();

	tree->insert(dan);
	tree->insert(bob);
	tree->insert(alice);
	tree->insert(charlie);
	tree->insert(frank);
	tree->insert(edward);
	tree->insert(gregory);

	/*
	The tree now looks like this:

	Daniel
	Bob				Frank
	Alice		Charlie		Edward		Gregory
	*/

	cout << endl << "In Order: " << endl;
	tree->traverseInOrder();

	cout << endl << "Pre Order: " << endl;
	tree->traversePreOrder();

	cout << endl << "Post Order: " << endl;
	tree->traversePostOrder();




	cout << endl << "Depth First Search: " << endl;
	Employee* found = tree->depthFirstSearch("Bob");
	if (found != NULL)
	{
		found->display();
	}
	else
	{
		cout << "Not Found" << endl;
	}
	
	cout << endl << "Breadth First Search: " << endl;
	found = tree->breadthFirstSearch("Frank");
	if (found)
	{
		found->display();
	}
	else
	{
		cout << "Not Found" << endl;
	}
	
	cout << endl << "\n\n****************************REMOVE FUNCTION TESTING*****************************";
	cout << endl << "Remove Daniel (Check top of tree, or where node is 2+ levels from bottom): " << endl;
	tree->remove("Daniel");
	tree->traverseInOrder();

	cout << endl << "Put Daniel Back: " << endl;
	tree->insert(dan);
	tree->traverseInOrder();


	cout << endl << "Remove Frank (check where node is one level from bottom): " << endl;
	tree->remove("Frank");
	tree->traverseInOrder();

	cout << endl << "Put Frank Back: " << endl;
	tree->insert(frank);
	tree->traverseInOrder();


	cout << endl << "Remove Gregory (Check bottom level): " << endl;
	tree->remove("Gregory");
	tree->traverseInOrder();

	cout << endl << "Put Gregory Back: " << endl;
	tree->insert(gregory);
	tree->traverseInOrder();
	cout << endl << "****************************REMOVE FUNCTION TESTING*****************************";
	getchar();

}

/*
Sample Output:

In Order:
Alice Wonderland $3.21123e+006
Bob Marley $3.21123e+006
Charlie Gargia $3.21123e+006
Daniel Craig $123123
Edward Norton $2.12112e+007
Frank Herbert $233223
Gregory Peck $344334

Pre Order:
Daniel Craig $123123
Bob Marley $3.21123e+006
Alice Wonderland $3.21123e+006
Charlie Gargia $3.21123e+006
Frank Herbert $233223
Edward Norton $2.12112e+007
Gregory Peck $344334

Post Order:
Alice Wonderland $3.21123e+006
Charlie Gargia $3.21123e+006
Bob Marley $3.21123e+006
Edward Norton $2.12112e+007
Gregory Peck $344334
Frank Herbert $233223
Daniel Craig $123123

Depth First Search:
Bob Marley $3.21123e+006

Breadth First Search:
Frank Herbert $233223
*/