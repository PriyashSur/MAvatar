#include"MAvatar.h"

void MAvatar::moveToUserFolder(string dir, bool moveEverything,string userHeadData1, string userHeadData2, string userHairData1, string userHair, string ext, int i)
{
	
	string cmd5;
	cmd5.append("mkdir " + mat[i][0]+"_"+dir);
	system(cmd5.c_str());
	cmd5.clear();
	if (moveEverything)
	{
		cmd5.append("move " + mat[i][0] + ".fg " + mat[i][0] + "_" + dir);
		system(cmd5.c_str());
		cmd5.clear();
		//MOVING THE HEAD DATA FILES
		cmd5.append("move " + userHeadData1 + mat[i][0] + "_" + dir);
		system(cmd5.c_str());
		cmd5.clear();
		cmd5.append("move " + userHeadData2 + " " + mat[i][0] + "_" + dir);
		system(cmd5.c_str());
		cmd5.clear();
	}
	if (!userHair.empty())
	{
		//MOVING THE HAIR DATA FILES
		cmd5.append("move " + userHairData1 + mat[i][0] + "_" + dir);
		system(cmd5.c_str());
		cmd5.clear();
		if (ext == "bmp")
		{
			cmd5.append("move " + userHair + ".bmp " + mat[i][0] + "_" + dir);
		}
		else if (ext == "tga")
		{
			cmd5.append("move " + userHair + ".tga " + mat[i][0] + "_" + dir);
		}
		else
		{
			cmd5.append("move " + userHair + ".jpg " + mat[i][0] + "_" + dir);
		}
		system(cmd5.c_str());
		cmd5.clear();
	}
		//MOVING THE OBJ,MTL AND 2 TEXTURE FILE IN USER FOLDER
	    cmd5.append("move " + mat[i][0] + ".obj " + mat[i][0] + "_" + dir);
		system(cmd5.c_str());
		cmd5.clear();
		cmd5.append("move " + mat[i][0] + ".mtl " + mat[i][0] + "_" + dir);
		system(cmd5.c_str());
		cmd5.clear();
		cmd5.append("move " + mat[i][0] + "1.jpg " + mat[i][0] + "_" + dir);
		system(cmd5.c_str());
		cmd5.clear();
		if (ext == "bmp"&&!userHair.empty())
		{
			cmd5.append("move " + mat[i][0] + "2.jpg " + mat[i][0] + "_" + dir);
		}
		else if (ext == "tga"&&!userHair.empty())
		{
			cmd5.append("move " + mat[i][0] + "2.png " + mat[i][0] + "_" + dir);
		}
		system(cmd5.c_str());
		cmd5.clear();
	
}


void MAvatar::executeScripts()
{
	string cmd;
	for (int i = 0; i < row; i++)
	{
		cmd.clear();
		cmd.append("fg3pf.exe photofit ");
		cmd.append(mat[i][0]+".fg ");
		string tmp = cmd;
		//PARSING THE HAIR DATA AND USER IMAGE FROM CSV FILE
		for (int j = 2; j < col; j++)
		{
			if (j != col - 1)
			{
				tmp.append(mat[i][j] + " ");
			}
			else
				tmp.append(mat[i][j]);
		}
		//-------------------------PHOTOFIT COMMAND PROCESSING END------------------------//
		//PHOTOFIT PROCESSING COMMANDS/SCRIPTS
		system(tmp.c_str());
		//HEAD MESH CONSTRUCTION COMMANDS
		string cmd2,cmd4;
		string userHead = mat[i][0] + "Head";
		string userHair = mat[i][0] + "Hair";
		string userOutFile = mat[i][0] + ".fg ";
		//CONSTRUCTING FACE BASED ON AGE SHAPE AND COLOR
		string cmd5;
		cmd5.append("fg3.exe controls " + userOutFile + "gender " + "shape");
		system(cmd5.c_str());
		cmd5.clear();
		cmd5.append("fg3.exe controls " + userOutFile + "age " + "shape 25");
		system(cmd5.c_str());
		cmd5.clear();
		cmd5.append("fg3.exe controls " + userOutFile + "age " + "color 25");
		system(cmd5.c_str());
		cmd5.clear();
		//CONSTRUCTING HEAD
		cmd2.append("fg3.exe construct HeadHires "+userOutFile+userHead);
		cout << "Head Mesh Construction..." << endl;
		system(cmd2.c_str());
		//CONSTRUCTING HAIR 
		cout << "Hair Mesh Construction..." << endl;
		cmd4.append("fg3.exe construct ");
		string hairAsset = mat[i][1];
		hairAsset = hairAsset.substr(0, hairAsset.find_last_of("."));
		cmd4.append(hairAsset+" ");
		cmd4.append(userOutFile + userHair);
		system(cmd4.c_str());
		//CONSTRUCTION OF DATA FOR EXPORTING THE .TRI TO .OBJ FORMAT AND THE HAIR AND HEAD DATA
		string cmd3;
		string userOBJ = mat[i][0] + ".obj ";
		string userHeadData1 = userHead + ".tri ";
		string userHeadData2 = userHead + ".bmp ";
		string userHairData1 = userHair + ".tri ";
		string ext = mat[i][1];
		ext = ext.substr(ext.find_last_of(".")+1);
		string userHairData2;
		if (ext == "bmp")
		{
			userHairData2 = userHair + ".bmp";
		}
		else
		{
			userHairData2 = userHair + ".tga";
		}
		//EXPORTING THE TRI FORMAT TO OBJ FORMAT
		cmd3.append("fg3.exe triexport "+userOBJ+userHeadData1+userHeadData2+userHairData1+userHairData2);
		system(cmd3.c_str());

		//MOVE EVERYTHING TO USER NAMED FOLDER
		moveToUserFolder("WithWig",true,userHeadData1, userHeadData2, userHairData1, userHair, ext, i);

		//-------------------------PHOTOFIT HAIR AND HAIR COMMAND PROCESSING END------------------------//
		cmd2.clear();
		cmd3.clear();
		userHead.clear();
		userOutFile.clear();
		userOBJ.clear();
		userHeadData1.clear();
		userHeadData2.clear();
	}
}

//SIMULATION OF APPLYING DIFF HAIRS WITH FROM A SINGLE HEAD TEMPLATE
void MAvatar::HairSelecter()
{
	string user = "priyash";
	string userHead = user + "Head";
	string userhair = user + "Hair";
	string userOutFile = user + ".fg ";
	string userHeadData1 = userHead + ".tri ";
	string userHeadData2 = userHead + ".bmp ";
	string userHairData1 = userhair + ".tri ";
	string userHairData2;
	string cmd;
	cmd.append("fg3pf.exe photofit " + userOutFile + "photo1.jpg");
	system(cmd.c_str());
	cout << "Starting Head Mesh Construction..." << endl;
	string cmd2;
	cmd2.append("fg3.exe construct HeadHires " + userOutFile + userHead);
	system(cmd2.c_str());
	cout << "Starting Hair Mesh Construction ..." << endl;
	//MOVING TO THE USER FOLDER
	string cmd5;
	cmd5.append("mkdir " + user);
	system(cmd5.c_str());
	cmd5.clear();
	for (int i = 0; i < r; i++)
	{
		string temp = mat2[i][1];
		string ext = temp;
		ext = ext.substr(ext.find_last_of(".")+1);
		string hairAsset = temp;
		hairAsset = hairAsset.substr(0, hairAsset.find_last_of("."));
		string cmd3;
		cmd3.append("fg3.exe construct " + hairAsset+" " + userOutFile + userhair);
		system(cmd3.c_str());
		string cmd4;
		string usr = user;
		if (ext == "bmp")
		{
			userHairData2 = userhair + ".bmp";
		}
		else 
		{
			userHairData2 = userhair + ".tga";
		}
		stringstream ss;
		ss << i; 
		usr.append(ss.str());
		cmd4.append("fg3.exe triexport " + usr + ".obj " + userHeadData1 + userHeadData2 + userHairData1 + userHairData2);
		system(cmd4.c_str());

		cmd5.append("move " + userHairData1 + user);
		system(cmd5.c_str());
		cmd5.clear();

		if (ext == "bmp")
		{
			cmd5.append("move " + userhair + ".bmp " + user);
		}
		else
		{
			cmd5.append("move " + userhair + ".tga " + user);
		}
		system(cmd5.c_str());
		cmd5.clear();

		cmd5.append("move " + usr+".obj " + user);
		system(cmd5.c_str());
		cmd5.clear();

		cmd5.append("move " + usr+".mtl " + user);
		system(cmd5.c_str());
		cmd5.clear();

		cmd5.append("move " + usr + "1.jpg " + user);
		system(cmd5.c_str());
		cmd5.clear();

		if (ext == "bmp")
		{
			cmd5.append("move " + usr + "2.jpg " + user);
		}
		else
		{
			cmd5.append("move " + usr + "2.png " + user);
		}
		system(cmd5.c_str());
		cmd5.clear();

		usr.clear();
		cmd4.clear();
		cmd3.clear();
	}
	cmd5.append("move " + userOutFile + user);
	system(cmd5.c_str());
	cmd5.clear();

	cmd5.append("move " + userHeadData1 + user);
	system(cmd5.c_str());
	cmd5.clear();

	cmd5.append("move " + userHeadData2 + user);
	system(cmd5.c_str());
	cmd5.clear();

	
}

void MAvatar::executeScripts1()
{
	string cmd;
	for (int i = 0; i < row; i++)
	{
		cmd.clear();
		cmd.append("fg3pf.exe photofit ");
		cmd.append(mat[i][0] + ".fg ");
		string tmp = cmd;
		//PARSING THE HAIR DATA AND USER IMAGE FROM CSV FILE
		for (int j = 2; j < col; j++)
		{
			if (j != col - 1)
			{
				tmp.append(mat[i][j] + " ");
			}
			else
				tmp.append(mat[i][j]);
		}
		//-------------------------PHOTOFIT COMMAND PROCESSING END------------------------//
		//PHOTOFIT PROCESSING COMMANDS/SCRIPTS
		system(tmp.c_str());
		//HEAD MESH CONSTRUCTION COMMANDS
		string cmd2, cmd4;
		string userHead = mat[i][0] + "Head";
		string userOutFile = mat[i][0] + ".fg ";
		//CONSTRUCTING HEAD
		cmd2.append("fg3.exe construct HeadHires " + userOutFile + userHead);
		cout << "Head Mesh Construction..." << endl;
		system(cmd2.c_str());
		//CONSTRUCTION OF DATA FOR EXPORTING THE .TRI TO .OBJ FORMAT AND THE HAIR AND HEAD DATA
		string cmd3;
		string userOBJ = mat[i][0] + ".obj ";
		string userHeadData1 = userHead + ".tri ";
		string userHeadData2 = userHead + ".bmp";
		string ext = mat[i][1];
		ext = ext.substr(ext.find_last_of(".") + 1);
		//EXPORTING THE TRI FORMAT TO OBJ FORMAT
		cmd3.append("fg3.exe triexport " + userOBJ + userHeadData1 + userHeadData2);
		system(cmd3.c_str());

		//MOVE EVERYTHING TO USER NAMED FOLDER
		moveToUserFolder("WithOut_Wig",false,userHeadData1, userHeadData2, "", "", ext, i);

		//-------------------------PHOTOFIT HAIR AND HAIR COMMAND PROCESSING END------------------------//
		cmd2.clear();
		cmd3.clear();
		userHead.clear();
		userOutFile.clear();
		userOBJ.clear();
		userHeadData1.clear();
		userHeadData2.clear();
	}
}
