#if !defined ( INSTRUCTIONLIRE_H )
#define INSTRUCTIONLIRE_H
#include "Instruction.h"
#include "Id.h"


class InstructionLire : public Instruction {

public:
	InstructionLire(Id *v);
	InstructionLire():Instruction(Identifiants::ID_INSTRUCTIONLIRE){est_vide = true;}
	virtual ~InstructionLire(){}
	vector<Id*> getIds();
	Id* getIdentifiant(){return id;}
	virtual void executer(map<string,double> &mapV);
	void transformation(vector<pair<Id*,Nombre*> > constantes);

private:
	Id *id;

};


#endif 
