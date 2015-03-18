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
		_pileEtats.pop_front();
}

void Automate::decalage(Symbole *s, Etat*e)
{
	empilerEtat(e);
	empilerSymbole(s);
	avancerLecteur();
}

/*void Automate::reduction(Symbole *A)
{
	this->_pileSymboles.push_front(A);
	
	Etat *sommet = _pileEtats.front();
	sommet->transition(*this, A);
}*/

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
