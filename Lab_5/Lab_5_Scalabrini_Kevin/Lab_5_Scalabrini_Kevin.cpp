#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string select(string tableName, string fields[])
{
	ifstream file;
	file.open(tableName.c_str());
	string content;
	while (file.good())
	{
		string row;
		getline(file, row);
		int x = row.find_first_of(",");
		cout << x << endl;
		content += row;
	}
	file.close();
	return content;
}

int main()
{
	cout << "hello !!!" << endl;
	string fields[] = { "Name", "Price" };
	string result = select("applications.csv", fields);
	cout << result;
	getchar();
}