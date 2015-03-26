#if !defined ( DECLARATIONid_H )
#define DECLARATIONid_H
#include "Declaration.h"
#include "Id.h"

#include "Nombre.h"
#include <string>
#include <vector>
using namespace std;

class DeclarationConstante : public Symbole {

public:
	DeclarationConstante(Id *c, Nombre*n, DeclarationConstante *dC = new DeclarationConstante());
	DeclarationConstante():Symbole(Identifiants::ID_DECLARATIONCONSTANTE){est_vide = true;}
	virtual ~DeclarationConstante(){}
	
	Id* getId(){return id;}
	DeclarationConstante* getDeclarationConstante(){return declarationAutreConstante;}
	virtual void executer(map<string,double> &mapV);
	void print();

private:
	Id* id;
	Nombre*val;
	DeclarationConstante* declarationAutreConstante;
};


#endif
