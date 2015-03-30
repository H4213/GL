#if !defined ( INSTRUCTIONLIRE_H )
#define INSTRUCTIONLIRE_H
#include "Instruction.h"
#include "Id.h"


class InstructionLire : public Instruction {

public:
	InstructionLire(Id *idO);
	InstructionLire():Instruction(Identifiants::ID_INSTRUCTIONLIRE){est_vide = true;}
	virtual ~InstructionLire(){}
	
	vector<Id*> getIds();
	Id* getIdentifiant(){return id;}
	void transformation(vector<pair<Id*,Nombre*> > constantes);
	virtual void executer(map<string,double> &mapV , map<string,double> &mapC);
	virtual void print();

private:
	Id *id;

};


#endif 
