#if !defined ( PARTIEINSTRUCTIVE_H )
#define PARTIEINSTRUCTIVE_H
#include "Symbole.h"
#include "Instruction.h"
#include "Identifiants.h"

#include <vector>
using namespace std;

class PartieInstructive : public Symbole {

public:
	PartieInstructive(Instruction *i, vector<Instruction*> autresInstructions);
	PartieInstructive():Symbole(Identifiants::ID_PARTIEINSTRUCTIVE){}
	virtual ~PartieInstructive(){}

	virtual void executer();
	void print();

private:
	Instruction *instruction;
	PartieInstructive *sousPartieInstructive;
	
	void resteDuTableau(vector<Instruction*> &vectInstructions);

};


#endif 