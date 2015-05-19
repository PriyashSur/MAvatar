#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<vector>
#include"csv.h"
using namespace std;

class MAvatar
{
	CSVLoader* csvReader;
	string userData_path = "C:\\Users\\PRIYASH_11\\Downloads\\Facegen SDK Trial\\Fg3Sdk3G2Full\\Fg3Sdk3G2Full\\bin\\win\\vs12\\32\\debug\\";
	string** mat;
	
	unsigned int row = 0;
	unsigned int col = 0;
	//HAIR DATA VARIABLES
	CSVLoader* csvHairReader;
	string **mat2;
	unsigned int r;
	unsigned int c;
public:
	MAvatar()
	{
		string rel = userData_path;
		wstring w(rel.begin(), rel.end());
		_wchdir(w.c_str());
		csvReader = new CSVLoader(rel.append("UserData.csv"));
		csvReader->Load();
		row = csvReader->getRow();
		col = csvReader->getCol();
		mat = csvReader->loadData();
		//READING HAIR DATA FILE
		string rel2 = userData_path;
		csvHairReader = new CSVLoader(rel2.append("Hair.csv"));
		csvHairReader->Load();
		r = csvHairReader->getRow();
		c = csvHairReader->getCol();
		mat2 = csvHairReader->loadData();

	}
	~MAvatar()
	{
		mat = nullptr;
		row = 0;
		col = 0;
		userData_path.clear();
		r = 0;
		c = 0;
		mat2 = nullptr;
	}

	//COMPILE THE CODE WITH WIG
	void executeScripts();
	//COMPILE THE CODE WITHOUT WIG
	void executeScripts1();
	//USING THE SAME HEAD TEMPLATE APPLYING DIFFERENT HAIR WIGS
	void HairSelecter();
private:
	//CLEANING UP THE FILE AND MOVED TO THE USER FOLDER
	void moveToUserFolder(string dir,bool moveEverything,string userHeadData1, string userHeadData2, string userHairData1, string userHair, string ext, int i);
};
