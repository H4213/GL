#if !defined ( DECLARATIONCONSTANTE_H )
#define DECLARATIONCONSTANTE_H
#include "Declaration.h"
#include "Constante.h"

#include <string>
#include <vector>
using namespace std;

class DeclarationConstante : public Declaration {

public:
	DeclarationConstante(Constante *c, DeclarationConstante *dC = new DeclarationConstante());
	DeclarationConstante():Declaration(Identifiants::ID_DECLARATIONCONSTANTE){est_vide = true;}
	virtual ~DeclarationConstante(){}
	
	Constante* getConstante(){return constante;}
	DeclarationConstante* getDeclarationConstante(){return declarationAutreConstante;}
	virtual void executer(map<string,double> &mapV);
	void print();

private:
	Constante* constante;
	DeclarationConstante* declarationAutreConstante;
};


#endif