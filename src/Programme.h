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
	virtual ~Programme(){} //TODO: tout nettoyer!!!!

	void afficherVariables();
	void afficherConstantes();
	vector<Instruction*> getInstructions();
	vector<Id*> getVariables();
	vector<Id*> getConstantes();
	vector<pair<Id*,Nombre*> > getConstantesValeurs();
	PartieInstructive* getPartieInstructive(){return partieInstructive;}
	PartieDeclarative* getPartieDeclarative(){return partieDeclarative;}
	void executer(){executer(map_variables, map_constantes);}
	virtual void executer(map<string,double> &mapV , map<string,double> &mapC );
	virtual void print();


private:
	PartieDeclarative *partieDeclarative;
	PartieInstructive *partieInstructive;
	map<string,double> map_variables;
	map<string,double> map_constantes;
};

#endif
