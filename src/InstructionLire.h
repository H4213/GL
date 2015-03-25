#if !defined ( INSTRUCTIONLIRE_H )
#define INSTRUCTIONLIRE_H
#include "Instruction.h"
#include "Variable.h"


class InstructionLire : public Instruction {

public:
	InstructionLire(Variable *v);
	InstructionLire():Instruction(Identifiants::ID_INSTRUCTIONLIRE){est_vide = true;}
	virtual ~InstructionLire(){}
	
	Variable* getVariable(){return variable;}
	virtual void executer(map<string,double> &mapV);

private:
	Variable *variable;

};


#endif 