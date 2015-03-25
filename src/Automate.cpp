#include "Automate.h"
#include "limits.h"

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
