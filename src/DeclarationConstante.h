#if !defined ( DECLARATIONCONSTANTE_H )
#define DECLARATIONCONSTANTE_H
#include "Declaration.h"
#include "Constante.h"

#include <string>
#include <vector>
using namespace std;

class DeclarationConstante : public Declaration {

public:
	DeclarationConstante(string nomConstante, double valeur, vector<string> autresConstantes = vector<string>(), vector<double> autresValeurs = vector<double>());
	DeclarationConstante():Declaration(Identifiants::ID_DECLARATIONCONSTANTE){}
	virtual ~DeclarationConstante(){}
	
	virtual void executer(map<string,double> &mapV);
	void print();

private:
	Constante constante;
	DeclarationConstante* declarationAutreConstante;

	void resteDuTableau(vector<string> &tabConstantes, vector<double> &tabValeurs);
};


#endif