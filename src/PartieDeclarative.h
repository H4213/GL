#if !defined ( PARTIEDECLARATIVE_H )
#define PARTIEDECLARATIVE_H
#include "Symbole.h"
#include "Declaration.h"
#include "Variable.h"
#include "Constante.h"
#include <vector>

#include <vector>
using namespace std;

class PartieDeclarative : public Symbole {

public:
<<<<<<< HEAD
	PartieDeclarative(Declaration *d, vector<Declaration*> autresDeclarations = vector<Declaration*>());
	PartieDeclarative():Symbole(Identifiants::ID_PARTIEDECLARATIVE){}
	virtual ~PartieDeclarative(){}
	vector<Variable*> getVariables();
	vector<Constante*> getConstantes();
=======
	PartieDeclarative(Declaration *d, PartieDeclarative *pD = new PartieDeclarative()); 
	PartieDeclarative():Symbole(Identifiants::ID_PARTIEDECLARATIVE){est_vide = true;}
	virtual ~PartieDeclarative(){}

	Declaration* getDeclaration(){return declaration;}
	PartieDeclarative* getPartieDeclarative(){return sousPartieDeclarative;}
>>>>>>> dev-symboles
	virtual void executer(map<string,double> &mapV);
	void print();


private:
	Declaration *declaration;
	PartieDeclarative *sousPartieDeclarative;

};


#endif
