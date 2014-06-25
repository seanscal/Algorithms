// quizprep3.cpp : Defines the entry point for the console application.
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
	void setFirstName(string fName) //setter
	{
		this->firstName = fName;
	}
	void setLastName(string lName) //setter
	{
		this->lastName = lName;
	}
	void setSalary(double salary) //setter
	{
		if (salary > 0)
		{
			this->salary = salary;
		}
	}
	void setDepartmentType(DepartmentType departmentType) //setter
	{
		this->departmentType = departmentType;
	}
	string getFirstName() { return firstName; } //getter
	string getLastName()  { return lastName; }  //getter
	double getSalary()    { return salary; }    //getter
	DepartmentType getDepartmentType() { return departmentType; } //getter
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

	//added elements for BFS function
	//max number of employees in the queue
	int capacity = 7;
	// boundary indices of queue
	int front = 0, back = 0;

	// how many employees are currently in the queue
	int count = 0;

	// set the capacity and allocate the array
	EmployeeNode* *stack = new EmployeeNode*[capacity]; //stack is set at size 7

	//enqueue and dequeue functions for BFS
	void enqueue(EmployeeNode* root);
	EmployeeNode* dequeue();

public:
	void insert(Employee* employee);
	void remove(string firstName);
	Employee* breadthFirstSearch(string firstName);
	Employee* depthFirstSearch(string firstName);
	void traverseInOrder();
	void traversePreOrder();
	void traversePostOrder();
};
void EmployeeBinarySearchTree::insert(EmployeeNode* node, EmployeeNode* *root) //??this had EmployeeNode?
{
	//private insert function of class
	if (*root == NULL)
	{
		*root = node;
		return;
	}

	else if (node->employee->getFirstName() < (*root)->employee->getFirstName())
	{
		insert(node, &(*root)->left);
	}

	else if (node->employee->getFirstName() >= (*root)->employee->getFirstName())
	{
		//accounts for case when two firstNames are the same
		insert(node, &(*root)->right);
	}
}

void EmployeeBinarySearchTree::insert(Employee* employee)
{
	EmployeeNode* newNode = new EmployeeNode(employee);

	// Calls private insert function
	insert(newNode, &root);
}
void EmployeeBinarySearchTree::traverseInOrder(EmployeeNode* root)
{
	//private traverseInOrder function of class
	//displays tree in order of fistName

	if (root != NULL) //conditional statement: tree has members
	{
		traverseInOrder(root->left);
		root->employee->display();
		traverseInOrder(root->right);
	}

}

void EmployeeBinarySearchTree::traverseInOrder()
{
	// Calls private traverseInOrder function
	traverseInOrder(root);
}
void EmployeeBinarySearchTree::traversePreOrder(EmployeeNode* root)
{
	//private traversePreOrder function of class
	//node followed by children left and right

	if (root != NULL) //conditional statement: tree has members
	{
		root->employee->display();
		traversePreOrder(root->left);
		traversePreOrder(root->right);
	}

}

void EmployeeBinarySearchTree::traversePreOrder()
{
	// Calls private traversePreOrder function
	traversePreOrder(root);
}

void EmployeeBinarySearchTree::traversePostOrder(EmployeeNode* root)
{
	//private traversePostOrder function of class
	//displays bottom left up - displays root last

	if (root != NULL) //conditional statement: tree has members
	{
		traversePostOrder(root->left);
		traversePostOrder(root->right);
		root->employee->display();
	}

}

void EmployeeBinarySearchTree::traversePostOrder()
{
	//Calls private traversePreOrder function
	traversePostOrder(root);

}

Employee* EmployeeBinarySearchTree::depthFirstSearch(string firstName, EmployeeNode* root)
{
	// private depthFirstSearch function of class

	if (root != NULL) //conditional statement, tree has members
	{
		if (firstName == root->employee->getFirstName())
		{
			return root->employee;
		}

		else if (firstName < root->employee->getFirstName())
		{
			return depthFirstSearch(firstName, root->left); //calls search function shifting left
		}

		else if (firstName >= root->employee->getFirstName()) //accounts for same name
		{
			return depthFirstSearch(firstName, root->right);
		}

		else //employee not in the tree
			return NULL;

	}

	return NULL; //if all else fails return null
}

Employee* EmployeeBinarySearchTree::depthFirstSearch(string firstName)
{
	// Calls private depthFirstSearch function
	return  depthFirstSearch(firstName, root);
}

void EmployeeBinarySearchTree::enqueue(EmployeeNode* root)
{
	if (root != NULL)
	{
		stack[back] = root;
		back = (back + 1) % capacity;
		count++;
	}
}

EmployeeNode* EmployeeBinarySearchTree::dequeue()
{
	EmployeeNode* dequeue = stack[front];
	front = (front + 1) % capacity; //modulus for rotation
	count--;
	return dequeue;
}

Employee* EmployeeBinarySearchTree::breadthFirstSearch(string firstName, EmployeeNode* root)
{
	EmployeeNode* temp = new EmployeeNode();

	enqueue(root); //enque's root to start "queue"

	while (count != 0)
	{
		temp = dequeue();

		if (temp->employee->getFirstName() == firstName)
		{
			return temp->employee;
		}

		else // (temp != NULL)
		{
			enqueue(temp->left);
			enqueue(temp->right);
		}

	}

	return NULL;

}


Employee* EmployeeBinarySearchTree::breadthFirstSearch(string firstName)
{
	// Implement this method (Extra Credit)
	//Calls private breadthFirstSearch function
	return breadthFirstSearch(firstName, root);
}



void EmployeeBinarySearchTree::remove(string firstName)
{
	// Implement this method (Extra Credit)
	//removes employee from the tree


	if (root == NULL) //edge condition ensures tree has members
	{
		return;
	}

	EmployeeNode* current = root;

	if (current->employee->getFirstName() == firstName) //employee is the root has children and leaves
	{
		EmployeeNode* tempA = current;
		EmployeeNode* tempB = current;

		current = current->right;

		//find leftMost child of right most branch
		while (current->left != NULL)
		{
			tempB = current;
			current = current->left;
		}

		root = new EmployeeNode(current->employee);

		root->left = tempA->left;
		root->right = tempA->right;
		tempB->left = NULL;
		delete tempA;
		delete tempB;
		return;

	}

	//case where employee is not tree root

	while ((current->left != NULL) || (current->right != NULL)) //checks for members
	{
		if (firstName == current->left->employee->getFirstName()) //employee on left side of tree
		{
			//create temp holders
			EmployeeNode* tempA = current->left;
			EmployeeNode* tempB = current->left;


			if (tempB->right != NULL)
			{
				current->left = new EmployeeNode(tempB->right->employee);

				tempB->right = NULL;
				current->left->left = tempA->left;
				current->left->right = tempB->right;
				delete tempA;
				return;
			}

			//else employee is the leaf

			current->left = NULL;
			delete tempA;
			return;
		}


		else if (firstName == current->right->employee->getFirstName()) //employee of right side of tree
		{
			//create temp holders
			EmployeeNode* tempA = current->right;
			EmployeeNode* tempB = current->right;

			if (tempB->left != NULL)
			{
				current->right = new EmployeeNode(tempB->left->employee);

				tempB->left = NULL;
				current->right->left = tempB->left;
				current->right->right = tempA->right;
				delete tempA;
				return;
			}
			// else employee is the leaf
			current->right = NULL;
			delete tempA;
			return;

		}

		else if (firstName < current->employee->getFirstName())
		{
			//condition employee is to the left side
			//iterate current to the next left
			current = current->left;
		}

		else if (firstName > current->employee->getFirstName())
		{
			//condition employee is to the right side
			//iterate current to the next right
			current = current->right;
		}
	} //end while loop


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
	Bob                 Frank
	Alice	 Charlie	 Edward	 Gregory
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
	if (found != NULL)
	{
		found->display();
	}
	else
	{
		cout << "Not Found" << endl;
	}

	//Remove the Employee
	//Make sure employees is in the tree
	cout << endl << "Remove Employee: " << endl;

	Employee* remove = tree->depthFirstSearch("Daniel");

	if (remove != NULL)
	{
		cout << remove->getFirstName() << " " << remove->getLastName() << endl;

		cout << "============================" << endl;
		cout << "The remaining employees are:" << endl;

		tree->remove(remove->getFirstName());
		tree->traverseInOrder();

	}

	else
	{
		cout << "The Employee is not found!" << endl;
	}

	getchar();
}