#include <deque>
#include "Automate.h"
#include <iostream>
#include <algorithm>
#include <sstream>
Automate::Automate(string fileContent)
{
	lecteur = new Lecteur(fileContent);
    error_state = false;
	success_state =false;
}
void Automate::afficherPiles()
{
	Symbole *s;
	cout << endl << " pile symb :";
	deque<Symbole*>::iterator is = _pileSymboles.begin();
	/*while(is != _pileSymboles.end())
	{
		s = (*is);
		s->print();
		cout << ",";
		is++;
	}*/
	cout << endl << " pile etat :";
	deque<Etat*>::iterator ie = _pileEtats.begin();
	while(ie != _pileEtats.end())
	{
		cout  << (*ie)->nom()<<",";
		ie++;
	}
}
/* /!\Attention /!\
 * Le lecteur n'est pas reinitialisé à la deuxième analyse
 * */
Programme*  Automate::analyser()
{

	error_state = false;
    success_state = false;
	//libération des piles avant leurs utilisations
	deque<Symbole*>::iterator is = _pileSymboles.begin();
	while(is != _pileSymboles.end())
	{
		delete *is++;
	}
	_pileSymboles.clear();

	deque<Etat*>::iterator ie = _pileEtats.begin();
	while(ie != _pileEtats.end())
	{
		delete *ie++;
	}
	_pileEtats.clear();


	Symbole *s = NULL;
	empilerEtat(new E0());

	while((s = courant()) != NULL && !error_state && !success_state)
	{
        cout <<"Symbole: ";
		 courant()->print();
		 cout << "Etat: " << sommetEtat()->nom() << endl;
		 afficherPiles();
		sommetEtat()->transition(*this, s);
	}
	return (Programme*)_pileSymboles.front();

}

Etat *Automate::sommetEtat()
{
	return _pileEtats.front();
}
void Automate::empilerSymbole(Symbole*s)
{
	this->_pileSymboles.push_front(s);
}
Symbole* Automate::depilerSymbole()
{
	Symbole *s = _pileSymboles.front();
	_pileSymboles.pop_front();
	return s;
}
void Automate::empilerEtat(Etat*e)
{
	this->_pileEtats.push_front(e);
}
void Automate::depilerEtat(int n)
{
	for(int i = 0; i < n;i++)
	{
		delete _pileEtats.front();
		_pileEtats.pop_front();
	}
}

void Automate::decalage(Symbole *s, Etat*e, bool avancerSymbole)
{
	cout << "decalage ";
	empilerEtat(e);
	empilerSymbole(s);
	if(avancerSymbole)
	{
	avancerLecteur();
	cout <<"avec consommation";
	}
	cout << endl;
}

void Automate::reduction(Symbole *s)
{
	//on empilera l'etat de Aller-A(sommetEtat, sommetSymbole)
	cout << "reduction \n ";
	_pileEtats.front()->transition(*this, s);
	/*_pileSymboles.front()->print();*/
}

void Automate::accepter()
{

	cout <<endl << "BRAVOOO! J'accepte! " << endl;
	success_state = true;;

}
void Automate::erreur()
{
	std::cout << "Erreur : le symbole ";  courant()->print();
	cout <<" inattendu à l'etat " << sommetEtat()->nom();
	error_state = true;
}
void Automate::avancerLecteur()
{
	 lecteur->moveReadHeader();
}

Symbole* Automate::courant()
{
	return lecteur->getNext();
}

bool Automate::analyseStatique(Programme* Pr) {
	Pr=transformation(Pr);
	if (1==0) //(this->_pileSymboles.size() != 1  ||  *_pileSymboles.front() != Identifiants::ID_PROGRAMME)
	{
		cout<<"Veuillez proceder à l'analyse syntaxique"<<endl;
		return 1;

	}
	else
	{
		//nitialisation des maps de variables et constantes déclarés
		map<string, int> variables;
		vector<string> constantes;


		//Programme* Pr =dynamic_cast<Programme*> (_pileSymboles.front());
       //Recuperation des variables et verification de l'unicité
       		cout<<"Avant le getVariables"<<endl;

        vector<Id*> allVariables =  Pr->getVariables();
		cout<<"après"<<endl;

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
			cout<<instructions.size()<<endl;

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


	}
	cout<<"Succes de la verfification statique"<<endl;
}

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
		instructions[i]=instructions[i]->transformation(constantes);
	}
	
	Programme* PrResult = new Programme(partiesDeclaratives[partiesDeclaratives.size()-1],Pr->getPartieInstructive());
	return PrResult;
}




