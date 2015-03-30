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
	if(error_state)
	{
		deque<Symbole*>::iterator is = _pileSymboles.begin();
		while(is != _pileSymboles.end())
		{
			delete *is++;
		}
	}

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

	if(!error_state)
	return (Programme*)_pileSymboles.front();
	else return NULL;

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

	//cout <<endl << "L'analyse syntaxique a réussi! " << endl;
	success_state = true;;

}
void Automate::erreur()
{

	Symbole *c = courant();
	cerr << "Erreur syntaxique ("<<
	c->getLigne()<< ":" << c->getColonne()<<")" <<
	 " symbole '" << c->nom() << "' inattendu" << endl;

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




