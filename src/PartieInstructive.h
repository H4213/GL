#if !defined ( PARTIEINSTRUCTIVE_H )
#define PARTIEINSTRUCTIVE_H
#include "Symbole.h"
#include "Instruction.h"

#include <vector>
using namespace std;

class PartieInstructive : public Symbole {

public:
	PartieInstructive(Instruction *i, PartieInstructive *pI = new PartieInstructive());
	PartieInstructive():Symbole(Identifiants::ID_PARTIEINSTRUCTIVE){est_vide = true;}
	virtual ~PartieInstructive(){}
	
	vector<Instruction*> getInstructions();
	Instruction* getInstruction(){return instruction;}
	PartieInstructive* getPartieInstructive(){return sousPartieInstructive;}
	virtual void executer(map<string,double> &mapV);
	void print();

private:
	Instruction *instruction;
	PartieInstructive *sousPartieInstructive;

};


#endif 
