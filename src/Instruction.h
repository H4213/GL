#if !defined ( INSTRUCTION_H )
#define INSTRUCTION_H
#include "Symbole.h"


class Instruction : public Symbole {

public:
	Instruction();
	Instruction(int id):Symbole(id){}
	virtual ~Instruction(){}

};


#endif 