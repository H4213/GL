#include "Lutin.h"
#include "Automate.h"
#include "Symbole.h"
#include "DeclarationConstante.h"
#include "DeclarationVariable.h"
#include "Programme.h"
#include "PartieDeclarative.h"
#include "PartieInstructive.h"
#include "Expression.h"


#include "Nombre.h"
#include "ExpressionAdditive.h"
#include "ExpressionMultiplicative.h"
#include "ExpressionParenthesee.h"
#include "Addition.h"
#include "Multiplication.h"
#include "Division.h"
#include "Instruction.h"
#include "InstructionLire.h"
#include "Id.h"
#include "LigneDeclarationVariable.h"
#include "LigneDeclarationConstante.h"
#include "Terme.h"
#include "Facteur.h"
#include "InstructionEcrire.h"
#include "InstructionAffectation.h"

#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{

	// Lutin monLutin(argc, argv);

	/*
	Test du constructeur declaration de variable/constante et execution des declarations et instructions
	*/
	Id *x = new Id("x");

	LigneDeclarationVariable *ldv1 = new LigneDeclarationVariable(x);

	Id *c1 = new Id("c1");
	Id *c2 = new Id("c2");

	Nombre *n1 = new Nombre("100");	
	Nombre *n2 = new Nombre("200");

	DeclarationConstante *dc1 = new DeclarationConstante(c2, n2);

	LigneDeclarationConstante *ldc = new LigneDeclarationConstante(c1, n1, dc1);

	Id *y = new Id("y");

	LigneDeclarationVariable *ldv2 = new LigneDeclarationVariable(y);

	PartieDeclarative *pd1 = new PartieDeclarative(ldv1);
	PartieDeclarative *pd2 = new PartieDeclarative(ldc, pd1);
	PartieDeclarative *pd3 = new PartieDeclarative(ldv2, pd2);

	Expression *e1 = new Nombre("3");
	Expression *e2 = new Nombre("2");
	Terme *t1 = new Nombre("3");
	Terme *t2 = new Nombre("2");
	OperationMultiplicative *opM = new Multiplication();	
	OperationAdditive *opA = new Addition();	

	Expression *eM = new ExpressionMultiplicative(t1, y, opM);
	Terme *eP = new ExpressionParenthesee(eM);
	Expression *eA = new ExpressionAdditive(e2, eP, opA);

	Instruction *lire = new InstructionLire(y);
	Instruction *ecrire1 = new InstructionEcrire(eA);
	Instruction *affecter = new InstructionAffectation(x,y);
	Instruction *ecrire2 = new InstructionEcrire(c1);

	PartieInstructive *pi1 = new PartieInstructive(lire);
	PartieInstructive *pi2 = new PartieInstructive(ecrire1,pi1);
	PartieInstructive *pi3 = new PartieInstructive(affecter,pi2);
	PartieInstructive *pi4 = new PartieInstructive(ecrire2, pi3);

	Programme p = Programme(pd3,pi4);

	p.print();	
	p.afficherVariables();
	p.afficherConstantes();
	p.executer();
	cout<<"--------"<<endl;
	p.afficherVariables();
	cout<<"--------"<<endl;
	p.afficherConstantes();
	/*
	Fin du test
	*/

    return 0;
}

