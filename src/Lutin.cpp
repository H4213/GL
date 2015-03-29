using namespace std;
#include <iostream>

#include "Lutin.h"

Lutin::Lutin ( int argc, char **argv ) :
		_command(argc, argv)
{
	bool commandOK = true;
	bool showHelp = false;

	_programme = NULL;

	//on récupère le nom de fichier comme un argument sans option
	string inputfile = _command.getArgument("s0");
	//s'il n'y pas d'option ou qu'il n'y a pas d'argument
	if (inputfile == "")
	{
		cerr << "Erreur, veuillez specifier des arguments" << endl;
		ShowHelp();
		showHelp = true;
	}
	//on verifie que toutes les options existent
	if(_command.OptionCount() > 0)
	{
        map<string,string>::iterator it = _command.getOptionsBegin();
        for (it ; it!=_command.getOptionsEnd() ; it++)
        {
            if (it->first != "-p" && it->first != "-a" && it->first != "-e" && it->first != "-o" &&  it->first != "s0")
            {
                cerr << "Option " << it->first  <<" inconnue"<< endl;
                ShowHelp();
                commandOK = false;
            }
        }
	}

	bool option_p = _command.OptionExists("-p");
	bool option_a = _command.OptionExists("-a");
	bool option_e = _command.OptionExists("-e");
	bool option_o = _command.OptionExists("-o");

	bool option_default = (_command.OptionCount()==0);

	if (!showHelp && commandOK)
	{
		if (option_default)OptionDefault();
		if (option_o)OptionO();
		if (option_a)OptionA();
		if (option_e)OptionE();
		if (option_p)OptionP();

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
	//rappeler OptionDefault puis tester si _programme n'est pas NULL
	cout << "OptionP" << endl;
}
void Lutin::OptionA()
{
	OptionDefault();
	if (_programme != NULL )
	{
	    analyseStatique(_programme);
	}
}
void Lutin::OptionE()
{
	//rappeler OptionDefault puis tester si _programme n'est pas NULL
	OptionDefault();
	if (_programme != NULL )
	{
	    _programme->executer();
	}
}
void Lutin::OptionO()
{
	//rappeler OptionDefault puis tester si _programme n'est pas NULL
	cout << "OptionO" << endl;
}

void Lutin::OptionDefault()
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
    	_programme = NULL;
    }

    _programme =  _automate.analyser(contents);
}

bool Lutin::analyseStatique(Programme* Pr)
{
    //nitialisation des maps de variables et constantes déclarés
    map<string, int> variables;
    vector<string> constantes;
    //Recuperation des variables et verification de l'unicité
    vector<Id*> allVariables =  Pr->getVariables();
    for (int i = 0 ; i<allVariables.size() ; i++ )
    {
        if (variables.find(allVariables[i]->getNom()) != variables.end() )
           {
                cout<< "Erreur : la variable " + allVariables[i]->getNom() + " est déclaré plus d'une fois" << endl;
				return 1;
                break;
            }
        else
        {
            variables.insert(pair<string,int> (allVariables[i]->getNom(),1));
        }
    }
    // Recuperation des constantes
    vector<Id*> allConstantes = Pr->getConstantes();
    // Verification de l'unicité des constantes
    vector<string> toTest;
    for (int i = 0 ; i<allConstantes.size() ; i++)
    {
        if ( find(constantes.begin(), constantes.end(), allConstantes[i]->getNom()) == constantes.end() )
        {
            constantes.push_back(allConstantes[i]->getNom());
        }
        else
        {
            cout << "La constante " + allConstantes[i]->getNom() + " a été declaré plus d'une fois" << endl;
            return 1;
        }
    }

    //Verification des instructions.
    // Initialisation de vector d'instructions
    vector<Instruction*> instructions = Pr->getInstructions();
    for (int i = 0;i<instructions.size(); i++)
        {
        vector<Id*> identifiants = instructions[i]->getIds();
        switch ((int) *instructions[i]){
            case Identifiants::ID_INSTRUCTIONAFFECTATION:

                //Cas d'une instruction d'affectation


                if (find(constantes.begin(), constantes.end(),identifiants[0]->getNom())!=constantes.end())
                {
                    //Affectation de constante
                    cout <<"On n'affecte pas une constante !!!!"<<endl;
                    return 1;
                }
                else if(variables.find(identifiants[0]->getNom())==variables.end())
                {
                    //La variable affecté n'est pas déclaré
                    cout << "La variable "+identifiants[0]->getNom()+" n'a pas été déclaré"<<endl;
                    return 1;
                }
                else
                {
                    for( int j =1;j<identifiants.size();j++)
                    {
                        if (variables.find(identifiants[j]->getNom())!=variables.end())
                        {
                            if (variables.find(identifiants[j]->getNom())->second==1)
                            {
                                cout << "La variable "+identifiants[j]->getNom()+" n'a pas été affecté"<<endl;
                                return 1;
                            }
                        }
                        else if (find(constantes.begin(), constantes.end(), identifiants[j]->getNom())==constantes.end())
                        {
                            //variable non affecté
                            cout << "La variable "+identifiants[j]->getNom()+" n'a pas été declaré"<<endl;
                            return 1;
                        }
                    }
                    variables.find(identifiants[0]->getNom())->second=0;
                    }
                    break;

                case Identifiants::ID_INSTRUCTIONLIRE:

                        if(find(constantes.begin(),constantes.end(),identifiants[0]->getNom())!=constantes.end())
                        {
                            cout <<"La constante "+identifiants[0]->getNom()+" ne peut être réécrite"<<endl;
                            return 1;
                        }
                        else
                        if(variables.find(identifiants[0]->getNom())==variables.end())
                        {
                            cout <<"La variable "+identifiants[0]->getNom()+" n'est pas déclarée"<<endl;
                            return 1;
                        }
                        else
                        {
                            variables.find(identifiants[0]->getNom())->second=0;
                    }
                break;
                case Identifiants::ID_INSTRUCTIONECRIRE:
                    for( int j =0;j<identifiants.size();j++)
                    {
                        if ((variables.find(identifiants[j]->getNom())!=variables.end()))
                        {
                            if (variables.find(identifiants[j]->getNom())->second==1)
                            {
                            //variable non affecté
                            cout << "La variable "+identifiants[j]->getNom()+" n'a pas été affecté"<<endl;
                            return 1;
                            }
                        }
                        else if (find(constantes.begin(),constantes.end(),identifiants[j]->getNom())==constantes.end())
                        {
                            //variable non affecté
                            cout << identifiants[j]->getNom()+" n'a pas été déclaré"<<endl;
                            return 1;
                        }
                    }
                }
            }
        cout<<"Succes de la verfification statique"<<endl;
}

Lutin::~Lutin ( )
{
	if(_programme != NULL)
		delete _programme;
}
