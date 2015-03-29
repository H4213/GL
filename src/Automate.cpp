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
	cerr << "L'analyse syntaxique a échouée pres du Symbole '";
	courant()->print();
	cerr << "'";
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




