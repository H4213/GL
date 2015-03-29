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

	cout << "OptionP" << endl;
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
    	cerr << "Erreur a l'ouverture du fichier "+_command.getArgument("s0") << endl;
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
                            cerr <<"La constante "+identifiants[0]->getNom()+" ne peut être réécrite"<<endl;
                            return 1;
                        }
                        else
                        if(variables.find(identifiants[0]->getNom())==variables.end())
                        {
                            cerr <<"La variable "+identifiants[0]->getNom()+" n'est pas déclarée"<<endl;
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
                            cerr << "une valeur dans l'expression "<< identifiants[j]->getNom() << " n'est pas connue."<<endl;
                            return 1;
                        }
                    }
                }
            }
}

<<<<<<< HEAD
Programme* Automate::transformation(Programme* Pr)
{
	PartieDeclarative* PartieDeclarativeVariable;
	PartieDeclarative* PartieDeclarativeConstante;
	
	//Transformation de la partieDeclarative
	vector<Id*> variables  = Pr->getVariables();
	vector<pair<Id*,Nombre*> > constantes = Pr->getConstantesValeurs();
	
	DeclarationVariable* finVariable= new DeclarationVariable();
	DeclarationConstante* finConstante= new DeclarationConstante();
	PartieDeclarative* finPartieDeclarative= new PartieDeclarative();

	vector<DeclarationVariable*> declarationsVariables;
	vector<DeclarationConstante*> declarationsConstantes;
	vector<PartieDeclarative*> partiesDeclaratives;
	
	partiesDeclaratives.push_back(finPartieDeclarative);
	declarationsVariables.push_back(finVariable);
	declarationsConstantes.push_back(finConstante);
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
	if(constantes.size()!=0)
	{
		
		for (int i=0;i<constantes.size()-1;i++)
		{

			DeclarationConstante* declC = new DeclarationConstante(new Id(constantes[i].first->getNom()), new Nombre(constantes[i].second->getStrValeur()), declarationsConstantes[i]);
			declarationsConstantes.push_back(declC);
		}
		
		
		
	LigneDeclarationConstante* lDC = new LigneDeclarationConstante(new Id(constantes[constantes.size()-1].first->getNom()), declarationsConstantes[declarationsConstantes.size()-1],new Nombre(constantes[constantes.size()-1].second->getStrValeur()));
	PartieDeclarative* partieDeclarativeTemp= new PartieDeclarative(lDC,partiesDeclaratives[partiesDeclaratives.size()-1]);
	partiesDeclaratives.push_back(partieDeclarativeTemp);
	}
	
	
	
	
	//Partie Declarative transformé
	// Transformation de la partie Instructive
    vector<Instruction*> instructions = Pr->getInstructions();

	for (int i=0;i<instructions.size();i++)
	{
		instructions[i]->transformation(constantes);
	}
	
	Programme* PrResult = new Programme(partiesDeclaratives[partiesDeclaratives.size()-1],Pr->getPartieInstructive());
	return PrResult;
}


=======
>>>>>>> 4aa819774a29fb5904fe174a28a4159dde08ba49
Lutin::~Lutin ( )
{
	if(_programme != NULL)
		delete _programme;
}
