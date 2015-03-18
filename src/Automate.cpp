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

void Automate::analyseStatique() {
	
	
	
	if (this->_pileSymboles.size() != 1 && this->_pileSymboles.front()->_symbole_string == "Programme") 
	{
		cout<<"Veuillez proceder à l'analyse syntaxique"<<endl;
	}
	else 
	{
		//Initialisation des maps de variables et constantes déclarés
		map<Variable, int> variables;
		map<Constante, int> constantes;
	}  
	
}
