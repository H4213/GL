#include "Automate.h"

void Automate::decalage(Symbole *s, Etat*e)
{
	this->_pileSymboles.push_front(s);
	this->_pileEtats.push_front(e);

	this->lecture();
}

void Automate::reduction(Symbole *A, Etat*E, int tailleBeta)
{
	for(int i=0; i < tailleBeta;i++)
	{
		this->_pileSymboles.pop_front();
		this->_pileEtats.pop_front();
	}
	this->_pileSymboles.push_front(A);
	this->_pileEtats.push_front(E);


	//TODO afficher la production
}

void Automate::accepter()
{

}
void Automate::erreur()
{
	
}
void Automate::lecture()
{

}