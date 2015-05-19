#ifndef CSV_H
#define CSV_H
#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;

class CSVLoader
{
	ifstream reader;
	long long counter = 0;
	long long c = 0;
	string file;
	vector<string>v;
	vector<string>label;
	string** mat;
public:
	CSVLoader(string file)
	{
		ifstream read;
		string l;
		this->file = file;
	}
	~CSVLoader()
	{
		v.clear();
		label.clear();
		mat = nullptr;
		file = nullptr;
		reader.clear();
		reader.close();

	}
	//PARSING THE DATA FROM CSV FILE 
	void Load();
	//FIND THE SPECIFIED COLUMN ON THE 1ST ROW
	int Find_Column_Label(string str);
	//GET THE TOTAL ROW OF THE CSV FILE
	long long getRow(){ return counter; }
	//vector<string>getData(){ return v; }
	//GET THE TOTAL COLUMN FROM THE CSV FILE
	long long getCol(){ return c; }
	//LOAD THE PARSED DATA IN A MATRIX FORM OF TYPE STRING
	string** loadData();
};

#endif
