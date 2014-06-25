#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

void displayApplication(int appIndex, string appNames[], float appPrices[]);
void displayAllApplications(string appNames[], float appPrices[], int appCount);
void swapApps(int appIndex1, int appIndex2, string appNames[], float appPrices[]);
int  pivot(int first, int last, string appNames[], float appPrices[]);
void quickSort(int first, int last, string appNames[], float appPrices[]);
int  binarySearchForPrice(float searchPrice, int first, int last, float appPrices[]);

void main()
{
	string appNames[] =
	{
		"Pages", "Keynote", "Numbers",
		"Word", "PowerPoint", "Excel",
		"Documents", "Presentation", "Sheets"
	};

	float appPrices[] =
	{
		3.99, 2.99, 1.99,
		19.99, 29.99, 39.99,
		34.99, 24.99, 14.99
	};

	displayAllApplications(appNames, appPrices, 9);
	quickSort(0, 8, appNames, appPrices);
	displayAllApplications(appNames, appPrices, 9);
	int foundIndex = binarySearchForPrice(25.99, 0, 9, appPrices);

	cout << "Search for item with price 25.99:" << endl;
	if (foundIndex == -1)
	{
		cout << "Not Found" << endl;
	}
	else
	{
		cout << "Found at index " << foundIndex << endl<<endl;
	}
	cout << "Search for item with price 24.99:" << endl;

	foundIndex = binarySearchForPrice(24.99, 0, 9, appPrices);	
	if (foundIndex == -1)
	{
		cout << "Not Found" << endl;
	}
	else
	{
		cout << "Found at index " << foundIndex << endl << endl;
	}
	getchar();
}
void displayApplication(int appIndex, string appNames[], float appPrices[])
{
	cout << appIndex << ") " << appNames[appIndex] << " " << appPrices[appIndex] << endl;
}

void displayAllApplications(string appNames[], float appPrices[], int appCount)
{
	for (int i = 0; i < appCount; i++)
	{
		displayApplication(i, appNames, appPrices);
	}
	cout << endl;
}

void swapApps(int appIndex1, int appIndex2, string appNames[], float appPrices[])
{
	string tempAppNames = appNames[appIndex1];
	appNames[appIndex1] = appNames[appIndex2];
	appNames[appIndex2] = tempAppNames;

	float tempAppPrices = appPrices[appIndex1];
	appPrices[appIndex1] = appPrices[appIndex2];
	appPrices[appIndex2] = tempAppPrices;

}

int  pivot(int first, int last, string appNames[], float appPrices[])
{
	float p = appPrices[first];
	int i = first;
	int j = last + 1;
	do
	{
		do
		{
			i++;
		} while
			(appPrices[i] < p && i < last);

		do
		{
			j--;
		} while (appPrices[j] > p);

		swapApps(i, j, appNames, appPrices);
	} while (i<j);
	swapApps(i, j, appNames, appPrices);
	swapApps(first, j, appNames, appPrices);
	return j;
}

void quickSort(int first, int last, string appNames[], float appPrices[])
{
	int p;
	if (first < last)
	{
		p = pivot(first, last, appNames, appPrices);
		quickSort(first, p - 1, appNames, appPrices);
		quickSort(p + 1, last, appNames, appPrices);
	}
}

int  binarySearchForPrice(float searchPrice, int first, int last, float appPrices[])
{
	if (last < first)
	{
		return -1;
	}

	int middle = (first + last) / 2;
	if (searchPrice < appPrices[middle])
	{
		return binarySearchForPrice(searchPrice,first, middle - 1, appPrices);
	}
	else if (searchPrice > appPrices[middle])
	{
		return binarySearchForPrice(searchPrice, middle+1, last, appPrices);
	}
	else
	{
		return middle;
	}
}