#include "Automate.h"


Programme* Automate::analyser()
{
	Symbole *s = NULL;
	_pileEtats.push_front(new E0());
	
	//while((s = lecteur.getCourant()) != NULL)
	{
		_pileEtats.front()->transition(*this, s);
	}
	
}

void Automate::decalage(Symbole *s, Etat*e, bool avecComsommer)
{
	this->_pileSymboles.push_front(s);
	this->_pileEtats.push_front(e);


	//avancer
	if(avecComsommer)
	this->avancerAuSuivant();
}

void Automate::reduction(Symbole *A)
{
	
	this->_pileSymboles.push_front(A);
	
	Etat *sommet = _pileEtats.front();
	sommet->transition(*this, A);
}

void Automate::accepter()
{

}
void Automate::erreur()
{
	
}
void Automate::avancerAuSuivant()
{
	 lecteur.moveReadHeader();
}
void Automate::lecture()
{
}
