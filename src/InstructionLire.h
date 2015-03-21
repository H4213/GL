#if !defined ( INSTRUCTIONLIRE_H )
#define INSTRUCTIONLIRE_H
#include "Instruction.h"
#include "Variable.h"
#include "Instruction.h"


class InstructionLire : public Instruction {

public:
	InstructionLire(Variable *v);
	InstructionLire():Instruction(Identifiants::ID_INSTRUCTIONLIRE){}
	virtual ~InstructionLire(){}
	
	virtual void executer();

private:
	Variable *variable;

};


#endif 