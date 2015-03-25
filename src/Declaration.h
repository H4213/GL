#if !defined ( DECLARATION_H )
#define DECLARATION_H
#include "Symbole.h"
#include <vector>
#include "Variable.h"
#include "Constante.h"


class Declaration : public Symbole {

public:
	Declaration();
	Declaration(int id);
	virtual ~Declaration(){}
    vector<Variable*> getVariables();
    vector<Constante*> getConstantes();
	virtual void executer(map<string,double> &mapV){}
};



#endif
