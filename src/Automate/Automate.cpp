#include "Automate.h"


Programme* Automate::analyser()
{
	Symbole *s = NULL;
	empilerEtat(new E0());
	
	while((s = courant()) != NULL)
	{
		sommetEtat()->transition(*this, s);
	}
	
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
	_pileEtats.front()->transition(this, s);
	
}

void Automate::accepter()
{
	
}
void Automate::erreur()
{
	
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
