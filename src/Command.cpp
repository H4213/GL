using namespace std;
#include <iostream>
#include "Command.h"

Command::Command ( int argc, char **argv ) :
		n_options(0), n_strings(0)
{
	string temp, temp2;
	stringstream ss;
	pair<map<string, string>::iterator, bool> ret;

	for (int i = 1; i < argc; i++)
	{
		temp = argv[i]; //argument courant

		if (temp.find("-") != string::npos) //si c'est une option
		{
			if (i != argc - 1) //si ce n'est pas le dernier argument
			{
				temp2 = argv[i + 1]; //on regarde l'element suivant
				if (temp2.find("-") == string::npos) //si ce n'est pas une option
				{
					ret = params.insert(
							pair<string, string>(argv[i], argv[i + 1])); //on regarde si
					if (ret.second == true)		//l'option n'existe pas déjà
						i++;		//si l'element existait on l'ignore
				}
				else
					params.insert(pair<string, string>(argv[i], "")); // sinon l'ajoute avec un argument vide
			}
			else
				params.insert(pair<string, string>(argv[i], "")); // sinon l'ajoute avec un argument vide
			n_options++; //on regarde l'element suivant
		}
		else //si l'element n'est pas une option
		{
			ss << n_strings; //on calcule le nombre d'elment sans options présent
			temp2 = "s" + ss.str(); //on construit sa clé
			params.insert(pair<string, string>(temp2, argv[i]));
			n_strings++; //on incrémente le nombre de paramètres sans option
		}
	}

}

int Command::OptionCount ( )
{
	return n_options;
}
int Command::StringCount ( )
{
	return n_strings;
}
string Command::getLastString ( )
{
	string temp;
	stringstream ss;
	ss << n_strings - 1;
	temp = "s" + ss.str();
	if (params.count(temp) == 0)
		return "";
	else
		return params[temp];
}
void Command::SetNoArgFor ( string arg )
{
	string temp;
	stringstream ss;
	if (params.count(arg) != 0)
	{
		if (params[arg] != "")
		{
			ss << n_strings;
			temp = "s" + ss.str();
			params.insert(pair<string, string>(temp, params[arg]));
			n_strings++;
			params[arg] = "";
		}
	}

}
bool Command::OptionExists ( string option )
{
	return (params.count(option) != 0);
}

string Command::getArgument ( string option )
{
	return params[option];
}
int Command::getArgumentAsNumber ( string option )
{
	bool isntNumber = false;
	int number = 0;
	string temp;
	temp = params[option];

	for (unsigned int i = 0; i < temp.size(); i++)
	{
		if (!isdigit(temp[i]))
		{
			isntNumber = true;
			break;
		}
	}
	if (!isntNumber)
		number = strtol(temp.c_str(), NULL, 10);

	return number;
}
Command::~Command ( )
{
} 

