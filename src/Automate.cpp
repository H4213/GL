#include "Automate.h"
#include <iostream>

Automate::Automate(string filename)
{
	lecteur = new Lecteur(filename);
	
}

/* /!\Attention /!\
 * Le lecteur n'est pas reinitialisé à la deuxième analyse
 * */
Programme*  Automate::analyser()
{
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
	
	while((s = courant()) != NULL)
	{
		cout <<"Symbole: " << *s << "Etat: " << sommetEtat()->nom() << endl;
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
	 lecteur->moveReadHeader();
}

Symbole* Automate::courant()
{
	return lecteur->getNext();
}

void Automate::analyseStatique() {

//	if (this->_pileSymboles.size() != 1  |  (int) *_pileSymboles.front() == Identifiants::ID_PROGRAMME)
//	{
//		cout<<"Veuillez proceder à l'analyse syntaxique"<<endl;
//	}
//	else
//	{
//		//nitialisation des maps de variables et constantes déclarés
//		map<string, int> variables;
//		vector<Constante*> constantes;
//
//        //Recuperation des variables et verification de l'unicité
//        vector<Variable*> allVariables =  dynamic_cast<Programme*> (_pileSymboles.front())->getVariables();
//        for (int i = 0 ; i<allVariables.size() ; i++ )
//        {
//            pair<std::map<string,int>::iterator,bool> ret;
//            ret = variables.insert(pair<string,int>(allVariables[i]->getNom(),INT_MAX));
//            if (ret.second == false )
//            {
//                cout<< "Erreur : la variable " + allVariables[i]->getNom() + " est déclaré plus d'une fois" << endl;
//                break;
//            }
//        }
//
//        // Recuperation des constantes
//        vector<Constante*> allConstantes = dynamic_cast<Programme*> (_pileSymboles.front())->getConstantes();
//
//        // Verification de l'unicité des constantes
//        vector<string> toTest;
//
//        for (int i = 0 ; i<allConstantes.size() ; i++)
//        {
//            if ( std::find(toTest.begin(), toTest.end(), (basic_string<char>) allConstantes[i]->getNom()) != toTest.end() )
//            {
//                constantes.insert(constantes.end(), allConstantes.begin() + i , allConstantes.begin() + 2 );
//            }
//            else
//            {
//                cout << "La constante " + allConstantes[i]->getNom() + " a été declaré plus d'une fois" << endl;
//            }
//        }
//	}

}
