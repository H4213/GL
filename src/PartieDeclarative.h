#if !defined ( PARTIEDECLARATIVE_H )
#define PARTIEDECLARATIVE_H
#include "Symbole.h"
#include "Declaration.h"
#include "DeclarationVariable.h"
#include "DeclarationConstante.h"
#include "Variable.h"
#include "Constante.h"
#include "Id.h"
#include <vector>
#include "Nombre.h"
#include "LigneDeclarationVariable.h"
#include "LigneDeclarationConstante.h"

using namespace std;

class PartieDeclarative : public Symbole {

public:


	PartieDeclarative(Declaration *d, PartieDeclarative *pD = new PartieDeclarative());
	PartieDeclarative():Symbole(Identifiants::ID_PARTIEDECLARATIVE){declaration=0;sousPartieDeclarative=0;est_vide = true;}
	virtual ~PartieDeclarative(){}
	
	Declaration* getDeclaration(){return declaration;}
	PartieDeclarative* getPartieDeclarative(){return sousPartieDeclarative;}
	vector<Id*> getVariables();
	vector<Id*> getConstantes();
	virtual void executer(map<string,double> &mapV);
	void print();
	map<string,double> getConstantesValeurs();


private:
	Declaration *declaration;
	PartieDeclarative *sousPartieDeclarative;

};


#endif
