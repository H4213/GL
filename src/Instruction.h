#if !defined ( INSTRUCTION_H )
#define INSTRUCTION_H
#include <vector>
#include "Symbole.h"
#include "Id.h"
#include "Nombre.h"
class Instruction : public Symbole {

public:
	Instruction();
	Instruction(int id):Symbole(id){}
	virtual ~Instruction(){}

	virtual vector<Id*> getIds();

	virtual Instruction* transformation(map<string,double> constantes);

	virtual void executer(map<string,double> &mapV , map<string,double> &mapC){}

};


#endif 
