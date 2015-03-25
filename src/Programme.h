#if !defined ( PROGRAMME_H )
#define PROGRAMME_H
#include "Symbole.h"
#include "PartieDeclarative.h"
#include "PartieInstructive.h"
#include "Variable.h"

using namespace std;


class Programme : public Symbole {

public:
<<<<<<< HEAD
	Programme(PartieDeclarative partieD, PartieInstructive partieI);
	virtual ~Programme(){}
	vector<Variable*> getVariables();
	vector<Constante*> getConstantes();
=======
	Programme(PartieDeclarative *partieD, PartieInstructive *partieI);
	Programme():Symbole(Identifiants::ID_PROGRAMME){}
	virtual ~Programme(){} //TODO: tout nettoyer!!

	void afficherVariables();
	// map<string,double> getVariables();		
	void executer(){executer(map_variables);}
	virtual void executer(map<string,double> &mapV);

	
	map<string,double> getMap(){return map_variables;}
>>>>>>> eba44e39f24c62f3d560db3081ec1095d5871ea5

private:
	PartieDeclarative *partieDeclarative;
	PartieInstructive *partieInstructive;
	map<string,double> map_variables;

};

#endif
