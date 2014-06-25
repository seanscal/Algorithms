// Lab 11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Shape {
protected:
	string name;

public:
	Shape(){}
	Shape(string name)
	{
		setName(name);
	}
	void setName(string name)
	{
		this->name = name;
	}
	void display()
	{
		cout << "Shape: " << name << endl;
	}
};

class Point : public Shape
{
protected:
	int x, y;
public:
	Point(){}
	Point(string name, int x, int y)
		: Shape(name)
	{
		setX(x);
		setY(y);
	}
	void setX(int x)
	{
		this->x = x;
	}
	void setY(int y)
	{
		this->y = y;
	}
	int getX() { return x; }
	int getY() { return y; }
	void display()
	{
		cout << "Point:" << endl;
		Shape::display();
		cout << "X: " << x << endl;
		cout << "Y: " << y << endl;
	}
};

class Line : public Shape
{
protected:
	Point* a;
	Point* b;
public:
	Line(){}
	Line(string name, Point* a, Point* b)
		: Shape(name)
	{
		setPointA(a);
		setPointB(b);
	}
	void setPointA(Point* a){ this->a = a; }
	void setPointB(Point* b){ this->b = b; }
	Point* getPointA() { return a; }
	Point* getPointB(){ return b; }
	double length()
	{
		double ax = a->getX();
		double bx = b->getX();
		double ay = a->getY();
		double by = b->getY();
		double diffx = ax - bx;
		double diffy = ay - by;
		return sqrt(pow(diffx, 2) + pow(diffy, 2));
	}
	void display()
	{
		cout << "Line: " << endl;
		Shape::display();
		a->display();
		b->display();
		cout << "Length: " << length() << endl;
	}
};

class Rectangle : public Shape
{
protected:
	Line* top;
	Line* bottom;
	Line* left;
	Line* right;
public:
	Rectangle(){}
	Rectangle(string name, Line* top, Line* right, Line* bottom, Line* left)
		: Shape(name)
		{
			setTopLine(top);
			setRightLine(right);
			setLeftLine(left);
			setBottomLine(bottom);
		}

	void setTopLine(Line* top) { this->top = top; }
	Line* getTopLine() { return top; }

	void setRightLine(Line* right) { this->right = right; }
	Line* getRightLine() { return right; }

	void setLeftLine(Line* left) { this->left = left; }
	Line* getLeftLine() { return left; }
	
	void setBottomLine(Line* bottom) { this->bottom = bottom; }
	Line* getBottomLine() { return bottom; }
	
	double area()
	{
		double topl = top->length();
		double rightl = right->length();
		return (topl*rightl);
	}
	double perimeter()
	{
		double topl = top->length();
		double rightl = right->length();
		double leftl = left->length();
		double bottoml = bottom->length();
		return (topl + rightl + leftl + bottoml);
	}
	void display()
	{
		cout << "Rectangle: " << endl;
		Shape::display();
		top->display();
		right->display();
		bottom->display();
		left->display();
		cout << "Area: " << area() << endl;
		cout << "Perimeter: " << perimeter() << endl;
	}
};

class Square : public Rectangle
{
public:
	Square(){}
	Square(string name, Line* horizontal, Line* vertical)
		: Rectangle(name, horizontal, vertical, horizontal, vertical)
	{
		setHorizontalLine(horizontal);
		setVerticalLine(vertical);
	}
	void setHorizontalLine(Line* horizontal)
	{
		this->top = horizontal;
	}
	void setVerticalLine(Line* vertical)
	{
		this->left = vertical;
	}
	Line* getHorizontalLine() { return top; }
	Line* getVerticalLine() { return left; }
	double area()
	{
		return top->length() * left->length();
	}
	double perimeter()
	{
		return top->length() * 2 + left->length() * 2;
	}
	void display()
	{
		cout << "Square:" << endl;
		Shape::display();
		top->display();
		left->display();
		cout << "Area: " << area() << endl;
		cout << "Perimeter: " << perimeter() << endl;
	}
};

int main()
{
	cout << endl << "Test Point Class" << endl;
	Point* p1 = new Point("P1", 12, 23);
	Point* p2 = new Point("P2", 23, 34);
	p1->display();
	p2->display();

	cout << endl << "Test Line Class" << endl;
	Line* line1 = new Line("Line1", p1, p2);
	line1->display();

	cout << endl << "Test Square Class" << endl;
	Point* p3 = new Point("P3", 34, 45);
	Point* p4 = new Point("P4", 45, 56);
	Line* line2 = new Line("Line2", p3, p4);
	Square* s1 = new Square("S1", line1, line2);
	s1->display();

	cout << endl << "Test Rectangle Class" << endl;
	Point* p5 = new Point("P5", 56, 67);
	Point* p6 = new Point("P6", 67, 78);
	Line* line3 = new Line("Line3", p5, p6);
	Point* p7 = new Point("P7", 78, 89);
	Point* p8 = new Point("P8", 89, 90);
	Line* line4 = new Line("Line4", p7, p8);
	Rectangle* r1 = new Rectangle("R1", line1, line2, line3, line4);
	r1->display();
	getchar();
}

