#if !defined ( PARTIEDECLARATIVE_H )
#define PARTIEDECLARATIVE_H
#include "Symbole.h"
#include "Declaration.h"

#include <vector>
using namespace std;

class PartieDeclarative : public Symbole {

public:
	PartieDeclarative(Declaration *d, vector<Declaration*> autresDeclarations = vector<Declaration*>()); 
	PartieDeclarative():Symbole(Identifiants::ID_PARTIEDECLARATIVE){}
	virtual ~PartieDeclarative(){}
	
	virtual void executer(map<string,double> &mapV);
	void print();

private:
	Declaration *declaration;
	PartieDeclarative *sousPartieDeclarative;

	void resteDuTableau(vector<Declaration*> &vectDeclarations);

};


#endif 