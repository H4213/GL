#include "Lutin.h"
#include <iostream>

using namespace std;

Lutin::Lutin ( int argc, char **argv ) :
		_command(argc, argv)
{
	bool commandOK = true;
	bool showHelp = false;

	_programme = NULL;
	_command.SetNoArgFor("-p");
	_command.SetNoArgFor("-a");
	_command.SetNoArgFor("-e");
	_command.SetNoArgFor("-o");

	//on r�cup�re le nom de fichier comme un argument sans option
	string inputfile = _command.getArgument("s0");
	//s'il n'y a pas d'argument
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
		OptionDefault();
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
	if (_programme != NULL )
	{
	    _programme->print();
	}
}
void Lutin::OptionA()
{
	if (_programme != NULL )
	{
	    analyseStatique(_programme);
	}
}
void Lutin::OptionE()
{
	if (_programme != NULL )
	{
	    _programme->executer();
	}
}
void Lutin::OptionO()
{
	if (_programme != NULL )
	{
	   	Programme *newProgramme = transformation(_programme);
        // delete _programme;
        _programme = newProgramme;

	}
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
    	cerr << "Erreur a l'ouverture du fichier "+_command.getArgument("s0") << endl;
    	_programme = NULL;
    }

    _programme =  _automate.analyser(contents);
}

bool Lutin::analyseStatique(Programme* Pr)
{
    //nitialisation des maps de variables et constantes d�clar�s
    map<string, int> variables;
    vector<string> constantes;
    //Recuperation des variables et verification de l'unicit�
    vector<Id*> allVariables =  Pr->getVariables();
    for (int i = 0 ; i<allVariables.size() ; i++ )
    {
        if (variables.find(allVariables[i]->getNom()) != variables.end() )
           {
                cerr<< "la variable " + allVariables[i]->getNom() + " est deja declaree" << endl;
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
    // Verification de l'unicit� des constantes
    vector<string> toTest;
    for (int i = 0 ; i<allConstantes.size() ; i++)
    {
        if ( find(constantes.begin(), constantes.end(), allConstantes[i]->getNom()) == constantes.end() )
        {
            constantes.push_back(allConstantes[i]->getNom());
        }
        else
        {
            cerr << "La constante " + allConstantes[i]->getNom() + " a ete declar� plus d'une fois" << endl;
            return 1;
        }
    }

    //Verification des instructions.
    // Initialisation de vector d'instructions
    vector<string> variableUtilise;
    vector<Instruction*> instructions = Pr->getInstructions();
    for (int i = 0;i<instructions.size(); i++)
        {
        vector<Id*> identifiants = instructions[i]->getIds();
        switch ((int) *instructions[i]){
            case Identifiants::ID_INSTRUCTIONAFFECTATION:
                //Cas d'une instruction d'affectation
                variableUtilise.push_back(identifiants[0]->getNom());
                if (find(constantes.begin(), constantes.end(),identifiants[0]->getNom())!=constantes.end())
                {
                    //Affectation de constante
                    cerr <<"Tentative d'affectation de la constante" << identifiants[0]->getNom()<<endl;
                    return 1;
                }
                else if(variables.find(identifiants[0]->getNom())==variables.end())
                {
                    //La variable affect� n'est pas d�clar�
                    cerr << "La variable "+identifiants[0]->getNom()+" n'a pas ete d�claree"<<endl;
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
                                cerr << "La variable "+identifiants[j]->getNom()+" n'a pas ete affectee"<<endl;
                                return 1;
                            }
                        }
                        else if (find(constantes.begin(), constantes.end(), identifiants[j]->getNom())==constantes.end())
                        {
                            //variable non affect�
                            cerr << "La variable "+identifiants[j]->getNom()+" n'a pas ete declaree"<<endl;
                            return 1;
                        }
                    }
                    variables.find(identifiants[0]->getNom())->second=0;
                    }
                    break;

                case Identifiants::ID_INSTRUCTIONLIRE:


                        variableUtilise.push_back(identifiants[0]->getNom());
                        if(find(constantes.begin(),constantes.end(),identifiants[0]->getNom())!=constantes.end())
                        {
                            cerr <<"La constante "+identifiants[0]->getNom()+" ne peut etre reecrite"<<endl;
                            return 1;
                        }
                        else
                        if(variables.find(identifiants[0]->getNom())==variables.end())
                        {
                            cerr <<"La variable "+identifiants[0]->getNom()+" n'est pas d�claree"<<endl;
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
                        variableUtilise.push_back(identifiants[j]->getNom());
                        if ((variables.find(identifiants[j]->getNom())!=variables.end()))
                        {
                            if (variables.find(identifiants[j]->getNom())->second==1)
                            {
                            //variable non affect�
                            cerr << "La variable "+identifiants[j]->getNom()+" n'a pas ete affecte"<<endl;
                            return 1;
                            }
                        }
                        else if (find(constantes.begin(),constantes.end(),identifiants[j]->getNom())==constantes.end())
                        {

                            cerr << identifiants[j]->getNom()+" n'a pas ete declare"<<endl;
                            return 1;
                        }
                    }
                }
            }
            //verification de l'utilisation des variables
            map<string,int>::iterator it;
            for (it = variables.begin() ; it!=variables.end() ; it++)
            {
                if (find(variableUtilise.begin(), variableUtilise.end() , it->first ) == variableUtilise.end())
                {
                    cerr << "variable non utilisee :" <<  it->first << endl;
                }
            }
}


Programme* Lutin::transformation(Programme* Pr)
{
	PartieDeclarative* PartieDeclarativeVariable;
	PartieDeclarative* PartieDeclarativeConstante;

	//Transformation de la partieDeclarative
	vector<Id*> variables  = Pr->getVariables();
	map<string,double > constantes = Pr->getConstantesValeurs();

	DeclarationVariable* finVariable= new DeclarationVariable();
	DeclarationConstante* finConstante= new DeclarationConstante();
	PartieDeclarative* finPartieDeclarative= new PartieDeclarative();

	vector<DeclarationVariable*> declarationsVariables;
	vector<DeclarationConstante*> declarationsConstantes;
	vector<PartieDeclarative*> partiesDeclaratives;

	partiesDeclaratives.push_back(finPartieDeclarative);
	declarationsVariables.push_back(finVariable);
	declarationsConstantes.push_back(finConstante);
	//Declaration de Variables
	if(variables.size()!=0)
	{

		for (int i=0;i<variables.size()-1;i++)
		{
			DeclarationVariable* decl=new DeclarationVariable(new Id(variables[i]->getNom()), declarationsVariables[i]);
			declarationsVariables.push_back(decl);
		}
		LigneDeclarationVariable* lDV = new LigneDeclarationVariable(new Id(variables[variables.size()-1]->getNom()),declarationsVariables[declarationsVariables.size()-1]);

		PartieDeclarative* partieDeclarativeTemp= new PartieDeclarative(lDV,partiesDeclaratives[partiesDeclaratives.size()-1]);
		partiesDeclaratives.push_back(partieDeclarativeTemp);
	}

	//Declaration de Constantes
	if(constantes.size()!=0)
	{

		map<string,double>::iterator it=constantes.begin();
		it++;
		for (it;it!=constantes.end();++it)
		{
			std::ostringstream strs;
			strs << it->second;
			std::string str = strs.str();

			DeclarationConstante* declC = new DeclarationConstante(new Id(it->first), new Nombre(str), declarationsConstantes[declarationsConstantes.size()-1]);
			declarationsConstantes.push_back(declC);
		}

			std::ostringstream strs;
			strs <<constantes.begin()->second;
			std::string str = strs.str();



	LigneDeclarationConstante* lDC = new LigneDeclarationConstante(new Id(constantes.begin()->first),new Nombre(str), declarationsConstantes[declarationsConstantes.size()-1]);




	PartieDeclarative* partieDeclarativeTemp= new PartieDeclarative(lDC,partiesDeclaratives[partiesDeclaratives.size()-1]);
	partiesDeclaratives.push_back(partieDeclarativeTemp);
	}

	//Partie Declarative transform�
	// Transformation de la partie Instructive
	PartieInstructive * partieInstructiveVide= new PartieInstructive();
    	vector<Instruction*> instructions = Pr->getInstructions();
	vector<PartieInstructive*> newInstructions;

	for (int i=0;i<instructions.size();i++)
	{
		if (i==0)
		{
			Instruction* instru=instructions[0]->transformation(constantes);

			PartieInstructive* pITemp = new PartieInstructive(instru,partieInstructiveVide);


			newInstructions.push_back(pITemp);

		}
		else
		{
			PartieInstructive * pITemp = new PartieInstructive(instructions[i]->transformation(constantes),newInstructions[i-1]);
			newInstructions.push_back(pITemp);
		}
	}


	Programme* PrResult = new Programme(partiesDeclaratives[partiesDeclaratives.size()-1],newInstructions[newInstructions.size()-1]);

	return PrResult;
}



Lutin::~Lutin ( )
{
	if(_programme != NULL)
	{
		delete _programme;
	}
}
