#if !defined ( PARTIEDECLARATIVE_H )
#define PARTIEDECLARATIVE_H
#include "Symbole.h"
#include "Declaration.h"

#include <vector>
using namespace std;

class PartieDeclarative : public Symbole {

public:
	PartieDeclarative(Declaration *d, PartieDeclarative *pD = new PartieDeclarative()); 
	PartieDeclarative():Symbole(Identifiants::ID_PARTIEDECLARATIVE){est_vide = true;}
	virtual ~PartieDeclarative(){}

	Declaration* getDeclaration(){return declaration;}
	PartieDeclarative* getPartieDeclarative(){return sousPartieDeclarative;}
	virtual void executer(map<string,double> &mapV);
	void print();

private:
	Declaration *declaration;
	PartieDeclarative *sousPartieDeclarative;

};


#endif 