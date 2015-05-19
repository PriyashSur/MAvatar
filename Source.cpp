#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include"MAvatar.h"

using namespace std;


int main()
{
	/*string s = "C:/Users/PRIYASH_11/Downloads/Facegen SDK Trial/Fg3Sdk3G2Full/Fg3Sdk3G2Full/bin/win/vs12/32/debug/";
	string tex_path = "photo1.jpg";
	wstring w(s.begin(),s.end());
	_wchdir(w.c_str());

	
	//PHOTOFIT PROCESSING COMMANDS
	//system("fg3pf.exe photofit face.fg photo1.jpg");

	//HEAD MESH CONSTRUCTION COMMANDS
	//system("fg3.exe construct HeadHires face.fg psHead");

	//FACEGEN SDK BASIC VIEWER WITH INTERACTIVE CONTROLS
     //system("fg3.exe view fg face.fg");

	//EXPORTING FROM TRI FORMAT TO OBJ FORMAT
	//system("fg3.exe triexport ps.obj psHead.tri psHead.bmp");*/

	MAvatar* av = new MAvatar();
	//IT WILL COMPILE WITHOUT WIG
	//av->executeScripts1();
	//IT WILL COMPILE WITH WIG
    av->executeScripts();
	//APPLY MULTIPLE WIGS TO A SINGLE HEAD TEMPLATE
	//av->HairSelecter();
	return 0;
}
