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
		cerr << "Erreur, veuillez specifier des arguments" << endl;
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

	if (!showHelp && commandOK) 
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
	cerr << "Utilisation :" << endl;
	cerr << "../lut [-p] [-a] [-e] [-o] source.lt" << endl;
	cerr << "[-p] affiche le code source reconnu" << endl;
	cerr << "[-a] analyse le programme de maniere statique" << endl;
	cerr << "[-e] execute interactivement le programme" << endl;
	cerr << "[-o] optimise les expressions et instructions" << endl;
}
void Lutin::OptionP()
{
	//rappeler OptionDefault pour recuperer Programme*
	cout << "OptionP" << endl;
}
void Lutin::OptionA()
{
	//rappeler OptionDefault pour recuperer Programme*
	cout << "OptionA" << endl;
}
void Lutin::OptionE()
{
	//rappeler OptionDefault pour recuperer Programme*
	cout << "OptionE" << endl;
}
void Lutin::OptionO()
{
	//rappeler OptionDefault pour recuperer Programme*
	cout << "OptionO" << endl;
}

Programme* Lutin::OptionDefault()
{
	FILE *fichier = NULL;
	string contents;
	fichier = fopen (_command.getArgument("s0").c_str(), "r");
	if (fichier != NULL)
    {
			fseek(fichier, 0, SEEK_END);
			contents.resize(ftell(fichier));
			rewind(fichier);
			fread(&contents[0], 1, contents.size(), fichier);
			fclose(fichier);
    }
    else
    {
    	cerr << "Erreur a l'ouverture du fichier "
    	+_command.getArgument("s0") << endl;
    	return NULL;
    }

    return _automate.analyser(contents);
}
Lutin::~Lutin ( )
{

}
