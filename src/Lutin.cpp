using namespace std;
#include <iostream>

#include "Lutin.h"

Lutin::Lutin ( int argc, char **argv ) :
		_command(argc, argv)
{

	bool commandOK = true;
	bool showHelp = false;


	//on récupère le nom de fichier comme un argument sans option
	string inputfile = _command.getArgument("s0");
	//s'il n'y pas d'option ou qu'il n'y a pas d'argument
	if (inputfile == "")
	{
		ShowHelp();
		showHelp = true;
	}
	//s'il y a plusieurs options
	if(_command.OptionCount() > 1)
	{
		commandOK = false;
		cerr << "Vous pouvez utiliser une option à la fois!" << endl;
	}

	bool option_p = _command.OptionExists("-p");
	bool option_a = _command.OptionExists("-a");
	bool option_e = _command.OptionExists("-e");
	bool option_o = _command.OptionExists("-o");

	bool option_default = (_command.OptionCount()==0);

	if (!showHelp && commandOK) //si l'aide ne doit pas s'afficher
	{
		if     (option_p)OptionP();
		else if(option_a)OptionA();
		else if(option_e)OptionE();
		else if(option_o)OptionO();
		else if(option_default)OptionDefault();
		else 
		{
			cerr << "Option inconnue"<< endl;
			ShowHelp();
		}
	}	

}
void Lutin::ShowHelp()
{
	cerr << "help" << endl;
}
void Lutin::OptionP()
{
	cout << "OptionP" << endl;
}
void Lutin::OptionA()
{
	
	cout << "OptionA" << endl;
}
void Lutin::OptionE()
{
	cout << "OptionE" << endl;
}
void Lutin::OptionO()
{
	cout << "OptionO" << endl;
}
void Lutin::OptionDefault()
{
	cout << "OptionDefault" << endl;
}
Lutin::~Lutin ( )
{

}
