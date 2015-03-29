#include <deque>
#include "Automate.h"
#include <iostream>
#include <algorithm>
#include <sstream>


Automate::Automate()
{
    error_state = false;
	success_state =false;
}

Automate::~Automate()
{
	deque<Symbole*>::iterator is = _pileSymboles.begin();
	while(is != _pileSymboles.end())
	{
		//on suprimme tout sauf le programme construit
		if(*(*is) != Identifiants::ID_PROGRAMME)
		delete *is;
		is++;
	}/**/

	deque<Etat*>::iterator ie = _pileEtats.begin();
	while(ie != _pileEtats.end())
	{
		delete *ie++;
	}
}

void Automate::afficherPiles()
{
	Symbole *s;
	cout << endl << " pile symb :";
	deque<Symbole*>::iterator is = _pileSymboles.begin();
	while(is != _pileSymboles.end())
	{
		s = (*is);
		s->print();
		cout << ",";
		is++;
	}
	cout << endl << " pile etat :";
	deque<Etat*>::iterator ie = _pileEtats.begin();
	while(ie != _pileEtats.end())
	{
		cout  << (*ie)->nom()<<",";
		ie++;
	}
}

Programme*  Automate::analyser(string fileContent)
{
	lecteur = new Lecteur(fileContent);

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
		sommetEtat()->transition(*this, s);
	}
	delete lecteur;

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
	{
	avancerLecteur();
	}
}

void Automate::reduction(Symbole *s)
{
	//on empilera l'etat de Aller-A(sommetEtat, sommetSymbole)
	_pileEtats.front()->transition(*this, s);
}

void Automate::accepter()
{

	cout <<endl << "L'analyse syntaxique a réussi! " << endl;
	success_state = true;;

}
void Automate::erreur()
{
	std::cerr << "Erreur : le symbole ";  courant()->print();
	cerr <<" inattendu à l'etat " << sommetEtat()->nom();
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

bool Automate::analyseStatique(Programme* Pr)
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



