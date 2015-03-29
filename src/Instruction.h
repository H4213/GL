#if !defined ( INSTRUCTION_H )
#define INSTRUCTION_H
#include <vector>
#include "Symbole.h"
#include "Id.h"
class Instruction : public Symbole {

public:
	Instruction();
	Instruction(int id):Symbole(id){}
	virtual ~Instruction(){}
	virtual vector<Id*> getIds();
	virtual void executer(map<string,double> &mapV){}

};


#endif 