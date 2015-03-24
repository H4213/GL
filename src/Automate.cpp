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

	if (this->_pileSymboles.size() != 1  |  (int) *_pileSymboles.front() == Identifiants::ID_PROGRAMME)
	{
		cout<<"Veuillez proceder à l'analyse syntaxique"<<endl;
	}
	else
	{

		//nitialisation des maps de variables et constantes déclarés
		map<Variable, int> variables;
		map<Constante, int> constantes;
        dynamic_cast<Programme*> (_pileSymboles.front())->getVariables();
        //vector<Variable> temp = dynamic_cast<Programme> (*_pileSymboles.front())->getVariables();
        //this->_pileSymboles.front().partieDeclarative.getConstantes();
        //(Programme) *_pileSymboles.front();

	}

}
