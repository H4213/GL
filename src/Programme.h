#if !defined ( PROGRAMME_H )
#define PROGRAMME_H
#include "Symbole.h"
#include "PartieDeclarative.h"
#include "PartieInstructive.h"
#include "Variable.h"

using namespace std;


class Programme : public Symbole {

public:

	Programme(PartieDeclarative *partieD, PartieInstructive *partieI);
	Programme():Symbole(Identifiants::ID_PROGRAMME){est_vide=true;}
	virtual ~Programme(){}

	void afficherVariables();
	//map<string,double> getVariables(){return map_variables;}
	vector<Id*> getVariables();
	vector<Id*> getConstantes();
	PartieInstructive* getPartieInstructive(){return partieInstructive;}
	PartieDeclarative* getPartieDeclarative(){return partieDeclarative;}
	void executer(){executer(map_variables);}
	virtual void executer(map<string,double> &mapV);

private:
	PartieDeclarative *partieDeclarative;
	PartieInstructive *partieInstructive;
	map<string,double> map_variables;
};

#endif
