#if !defined ( DECLARATION_H )
#define DECLARATION_H
#include "Symbole.h"
#include "Id.h"
#include "Nombre.h"

#include <vector>

class Declaration : public Symbole {

public:
	Declaration();
	Declaration(int id):Symbole(id){}
	virtual ~Declaration(){}

    virtual vector<Id*> getVariables(){}
    virtual vector<Id*> getConstantes(){}
    virtual vector<pair<Id*,Nombre*> > getConstantesValeurs(){}
	virtual void executer(map<string,double> &mapV , map<string,double> &mapC){}
	virtual void print(){}
};



#endif
