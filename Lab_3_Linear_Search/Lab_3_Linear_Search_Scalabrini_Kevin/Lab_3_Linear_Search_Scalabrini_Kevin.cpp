#include "stdafx.h"
#include <array>
#include <iostream>
#include <string>
using namespace std;

void displayBook(int bookIndex, string titles[], string authors[], int isbns[], int bookCount)
{
	int foundIndex=-1;
	for (int i = 0; i < bookCount; i++)
	{
		if (i == bookIndex)
		{
			foundIndex = i;
		}
	}

	if (foundIndex = -1)
	{
		cout << "Not a valid entry. Book not found.\n\n";
	}
	else
	{
		cout << "The book at index " << bookIndex << " is: " << titles[foundIndex]<<endl;
		cout << "The author of the book is: " << authors[foundIndex]<<endl;
		cout << "The ISBN is: " << isbns[foundIndex]<<endl<<endl;
	}
}
int searchBooksByTitle(string title, string titles[], int bookCount)
{
	int returned=-1;
	for (int i = 0; i < bookCount; i++)
	{
		if (titles[i] == title)
		{
			returned = i;
		}
	}
	return returned;
}

int searchBooksByAuthor(string author, string authors[], int bookCount)
{
	int returned = -1;
	for (int i = 0; i < bookCount; i++)
	{
		if (authors[i] == author)
		{
			returned = i;
		}
	}
	return returned;
}

int searchBooksByIsbn(int isbn, int isbns[], int bookCount)
{
	int returned = -1;
	for (int i = 0; i < bookCount; i++)
	{
		if (isbns[i] == isbn)
		{
			returned = i;
		}
	}
	return returned;
}

const int BOOK_COUNT = 10;

void main()
{
	string titles[] =
	{
		"Ender's Game", "Red Mars", "Dune",
		"Foundation", "Blade Runner", "Neuromancer",
		"Farenheit 451", "2001 A Space Odissey", "Forever War",
		"One Hundred Years of Solitud"
	};
	string authors[] =
	{
		"Orson Scott Card", "Kim Stanley Robinson", "Frank Herbert",
		"Isaac Asimov", "Philip K. Dick", "William Gibson",
		"Ray Bradbury", "Arthur C. Clarke", "Joe Haldeman",
		"Gabriel Garcia Marquez"
	};
	int isbns[] =
	{
		123, 234, 345,
		321, 432, 543,
		654, 765, 876,
		987
	};

	int enteredIndex;
	cout << "Enter the index of the book to see: ";
	cin >> enteredIndex;
	displayBook(enteredIndex, titles, authors, isbns, BOOK_COUNT);

	string enteredTitle;
	cout << "Enter the title of the book to see: ";
	cin >> enteredTitle;
	int index = searchBooksByTitle(enteredTitle, titles, BOOK_COUNT);
	displayBook(index, titles, authors, isbns, BOOK_COUNT);

	string enteredAuthor;
	cout << "Enter the author of the book to see: ";
	cin >> enteredAuthor;
	index = searchBooksByAuthor(enteredAuthor, titles, BOOK_COUNT);
	displayBook(index, titles, authors, isbns, BOOK_COUNT);

	int enteredISBN;
	cout << "Enter the ISBN of the book to see: ";
	cin >> enteredISBN;
	index = searchBooksByIsbn(enteredISBN, isbns, BOOK_COUNT);
	displayBook(index, titles, authors, isbns, BOOK_COUNT);

	getchar();
}

