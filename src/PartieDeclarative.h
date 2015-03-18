#if !defined ( PARTIEDECLARATIVE_H )
#define PARTIEDECLARATIVE_H
#include "Symbole.h"
#include "Declaration.h"
#include "Identifiants.h"

#include <vector>
using namespace std;

class PartieDeclarative : public Symbole {

public:
	PartieDeclarative(Declaration d, vector<Declaration> autresDeclarations); 
	PartieDeclarative():Symbole(Identifiants::ID_PARTIEDECLARATIVE){}
	virtual ~PartieDeclarative(){}

void resteDuTableau(vector<Declaration> &vectDeclarations);
void print();

private:
	Declaration declaration;
	PartieDeclarative* sousPartieDeclarative;

};


#endif 