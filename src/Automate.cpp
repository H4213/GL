#include "Automate.h"
#include <iostream>
#include <algorithm>
Programme*  Automate::analyser()
{
	Symbole *s = NULL;
	empilerEtat(new E0());
	
	while((s = courant()) != NULL)
	{
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
	empilerEtat(e);
	empilerSymbole(s);
	if(avancerSymbole)
	avancerLecteur();
}

void Automate::reduction(Symbole *s)
{
	//on empilera l'etat de Aller-A(sommetEtat, sommetSymbole)
	_pileEtats.front()->transition(*this, s);
	
}

void Automate::accepter()
{
	
}
void Automate::erreur()
{
	std::cout << "Erreur : le symbole " << _pileSymboles.front() << 
					" inattendu à l'etat " << sommetEtat()->nom();
}
void Automate::avancerLecteur()
{
	 //lecteur.moveReadHeader();
}

Symbole* Automate::courant()
{
	//return lecteur.getNext();
	return NULL;
}

void Automate::analyseStatique() {

	if (this->_pileSymboles.size() != 1  |  (int) *_pileSymboles.front() == Identifiants::ID_PROGRAMME)
	{
		cout<<"Veuillez proceder à l'analyse syntaxique"<<endl;
	}
	else
	{
		Programme* Pr =dynamic_cast<Programme*> (_pileSymboles.front());
		
		//Initialisation des maps de variables  et constantes déclarés
		map<string, int> variables;
		vector<string> constantes;

        //Recuperation des variables déclarées et verification de l'unicité
        vector<Variable*> allVariables =  Pr->getVariables();
        for (int i = 0 ; i<allVariables.size() ; i++ )
        {
            pair<std::map<string,int>::iterator,bool> ret;
            ret = variables.insert(pair<string,int>(allVariables[i]->getNom(),-1));
            if (ret.second == false )
            {
                cout<< "Erreur : la variable " + allVariables[i]->getNom() + " est déclaré plus d'une fois" << endl;
                break;
            }
        }

        // Recuperation des constantes déclarées
        vector<Constante*> allConstantes = Pr->getConstantes();

        // Verification de l'unicité des constantes
        vector<string> toTest;

        /*for (int i = 0 ; i<allConstantes.size() ; i++)
        {
            if ( std::find(toTest.begin(), toTest.end(), (basic_string<char>) allConstantes[i]->getNom()) != toTest.end() )
            {
                constantes.insert(constantes.end(), allConstantes.begin() + i , allConstantes.begin() + 2 );
            }
            else
            {
                cout << "La constante " + allConstantes[i]->getNom() + " a été declaré plus d'une fois" << endl;
            }
        }*/
        
        //TODO: Verifier unicité entre constante et variables
        
        //Verification des instructions.
        // Initialisation de vector d'instructions
        
        vector<Instruction*> instructions = Pr->getInstructions();
        
        for (int i = 0;i<instructions.size(); i++)
        {
			InstructionAffectation* affectation = dynamic_cast<InstructionAffectation*> (instructions[i]);
			
			//Cas d'une instruction d'affectation
			if (affectation != NULL)
			{
				string temp = affectation->getVariable()->getNom();
				if(variables.find(temp)==variables.end())
				{
					//La variable affecté n'est pas déclaré
					cout << "La variable "+temp+" n'a pas été déclaré"<<endl;
				}
				else
				{
					//TODO:getIds à implémenter
					vector<string> idTemp = affectation->getExpression()->getIds();
					for( int j =0;j<idTemp.size();j++)
					{
						
						if ((variables.find(idTemp[j])==variables.end()) && (find(constantes.begin(),constantes.end(),idTemp[j])==constantes.end()))
						{
						//identifiant non déclaré	
							cout << idTemp[j]+" n'a pas été déclaré"<<endl;
						}
						else if (variables.find(idTemp[j])->second==NULL)
						{
						//variable non affecté
							cout << "La variable "+idTemp[j]+" n'a pas été affecté"<<endl;
						}
					}
					
					
				}
			}
			else 
			{
				InstructionLire* lire = dynamic_cast<InstructionLire*> (instructions[i]);
				
				if (lire!=NULL)
				{
					if((find(constantes.begin(),constantes.end(),(lire->getVariable()->getNom())))!=constantes.end())
					{
						cout <<"La constante "+lire->getVariable()->getNom()+" ne peut être réécrite"<<endl;
					}
					if(variables.find(lire->getVariable()->getNom())==variables.end())
					{
						cout <<"La variable "+lire->getVariable()->getNom()+" n'est pas déclarée"<<endl;
					} 
				}
				else
				{
					InstructionEcrire* ecrire = dynamic_cast<InstructionEcrire*> (instructions[i]);
					if (ecrire!=NULL)
					{
						vector<string> idTemp = ecrire->getExpression()->getIds();
						
					
						for( int j =0;j<idTemp.size();j++)
						{
							
							if ((variables.find(idTemp[j])==variables.end()) && ((find(constantes.begin(),constantes.end(),idTemp[j]))==constantes.end()))
							{
							//identifiant non déclaré	
								cout << idTemp[j]+" n'a pas été déclaré"<<endl;
							}
							else if (variables.find(idTemp[j])->second==NULL)
							{
							//variable non affecté
								cout << "La variable "+idTemp[j]+" n'a pas été affecté"<<endl;
							}
						}
					}
					
				}
					
					
			}	
		}
		
	}

}
