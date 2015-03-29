#include "Automate.h"
#include "Symbole.h"
#include "DeclarationConstante.h"
#include "DeclarationVariable.h"
#include "Programme.h"
#include "PartieDeclarative.h"
#include "PartieInstructive.h"
#include "Expression.h"
#include "Constante.h"
#include "Variable.h"
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


	/*
	Test de l'execut de l'instruction Lire
	*/
//	 map<string,double> m;
//	 Id *variable = new Id("gab");
//	 m["gab"];
//	 Instruction *i = new InstructionLire(variable);
//	 i->executer(m);
//	 cout << m["gab"] << endl;
	/*
	Fin du test
	*/
//-------------------------------------------------------------------------------
	/*
	Test de l'eval des expressions
	*/
	// map<string,double> m;
	// Nombre *n1 = new Nombre(3);
	// Nombre *n2 = new Nombre(5);
	// OperationAdditive *opA = new Addition();
	// Expression *expA1 = new ExpressionAdditive(n1, n2, opA); // expA1 : 3+5 = 8
	// cout<< "expA1: "<<expA1->eval(m)<< endl; 

	// ExpressionParenthesee *expP = new ExpressionParenthesee(expA1); // expP: (3+5) =8
	// cout<< "expP: "<<expP->eval(m)<< endl;

	// Nombre *n3 = new Nombre(6);
	// OperationMultiplicative *opM = new Multiplication();
	// Expression *expM1 = new ExpressionMultiplicative(n3, expP, opM); //expM1: (3+5)*6 =48
	// cout<< "expM1: "<<expM1->eval(m)<< endl;
	/*
	Fin du teste
	*/

// -----------------------------------------------------------------

	/*
	Test du constructeur declaration de variable/constante et execution des declarations et instructions
	*/
	// Id *x = new Id("x");

	// LigneDeclarationVariable *ldv1 = new LigneDeclarationVariable(x);

	// Id *c1 = new Id("c1");
	// Id *c2 = new Id("c2");

	// Nombre *n1 = new Nombre("100");	
	// Nombre *n2 = new Nombre("200");

	// DeclarationConstante *dc1 = new DeclarationConstante(c2, n2);

	// LigneDeclarationConstante *ldc = new LigneDeclarationConstante(c1, n1, dc1);

	// Id *y = new Id("y");

	// LigneDeclarationVariable *ldv2 = new LigneDeclarationVariable(y);

	// PartieDeclarative *pd1 = new PartieDeclarative(ldv1);
	// PartieDeclarative *pd2 = new PartieDeclarative(ldc, pd1);
	// PartieDeclarative *pd3 = new PartieDeclarative(ldv2, pd2);

	// Expression *e1 = new Nombre("3");
	// Expression *e2 = new Nombre("2");
	// Terme *t1 = new Nombre("3");
	// Terme *t2 = new Nombre("2");
	// OperationMultiplicative *opM = new Multiplication();	
	// OperationAdditive *opA = new Addition();	

	// Expression *eM = new ExpressionMultiplicative(t1, y, opM);
	// Terme *eP = new ExpressionParenthesee(eM);
	// Expression *eA = new ExpressionAdditive(e2, eP, opA);

	// Instruction *lire = new InstructionLire(y);
	// Instruction *ecrire1 = new InstructionEcrire(eA);
	// Instruction *affecter = new InstructionAffectation(x,y);
	// Instruction *ecrire2 = new InstructionEcrire(c1);

	// PartieInstructive *pi1 = new PartieInstructive(lire);
	// PartieInstructive *pi2 = new PartieInstructive(ecrire1,pi1);
	// PartieInstructive *pi3 = new PartieInstructive(affecter,pi2);
	// PartieInstructive *pi4 = new PartieInstructive(ecrire2, pi3);

	// Programme p = Programme(pd3,pi4);

	// p.print();	
	// p.afficherVariables();
	// p.afficherConstantes();
	// p.executer();
	// cout<<"--------"<<endl;
	// p.afficherVariables();
	// cout<<"--------"<<endl;
	// p.afficherConstantes();
	/*
	Fin du test
	*/

// --------------------------------------------------------------------


	// // ...\lutin.exe cmd.txt -option (-p -a -e -o)

	// FILE *fichier = NULL;
	// string contents;
 //    char caractere;
	// char* options = "no option";
	// bool option_o = false;

 //    if (argc == 2)
 //    {
 //        fichier = fopen (argv[1], "r"); // Ouverture du fichier .txt argv[1]
 //    }
	//  else if (argc == 3)
	//  {
	//  	fichier = fopen (argv[1], "r"); // Ouverture du fichier .txt argv[1]
	//  	options = argv[2];				// Récupération de l'option
	//  }
	//  else if (argc == 4)
	//  {
	//  	fichier = fopen (argv[1], "r"); // Ouverture du fichier .txt argv[1]
	//  	options = argv[2];				// Récupération de l'option
	//  	option_o = true;
	//  }
 //    if (fichier != NULL)
 //    {
	// 		fseek(fichier, 0, SEEK_END);
	// 		contents.resize(ftell(fichier));
	// 		rewind(fichier);
	// 		fread(&contents[0], 1, contents.size(), fichier);
	// 		fclose(fichier);
 //    }
 //    else
	// {
	// 	exit(EXIT_FAILURE);
	// }

 //     Automate automate(contents);
 //     Programme *p = automate.analyser();
 //     automate.analyseStatique(p);
 //     p->executer();
 //     p->print();

    return 0;



}

