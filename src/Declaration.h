#if !defined ( DECLARATION_H )
#define DECLARATION_H
#include "Symbole.h"
#include <vector>
#include "Variable.h"
#include "Constante.h"
#include "Id.h"

class Declaration : public Symbole {

public:
	Declaration();
	Declaration(int id):Symbole(id){}
	virtual ~Declaration(){}

    virtual vector<Id*> getVariables(){}
    virtual vector<Id*> getConstantes(){}
	virtual void executer(map<string,double> &mapV , map<string,double> &mapC){}
	virtual void print(){}
};



#endif
