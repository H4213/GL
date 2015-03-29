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
	// cout<< "expA1: "<<expA1->eval(m)<< endl; //ça ne marche que si ExpressionA. est un pointeur (pourquoi?????)

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
	Test du constructeur declaration de variable/constante et execution des declarations
	*/
	Id *id1 = new Id("id1");
	Id *id2 = new Id("id2");
	Id *id3 = new Id("id3");
	Id *id4 = new Id("id4");

	DeclarationVariable *dv1 = new DeclarationVariable(id4);
	DeclarationVariable *dv2 = new DeclarationVariable(id3, dv1);
	DeclarationVariable *dv3 = new DeclarationVariable(id2, dv2);

	LigneDeclarationVariable *ldv = new LigneDeclarationVariable(id1, dv3);

	PartieInstructive *pi = new PartieInstructive();
	PartieDeclarative *pd = new PartieDeclarative(ldv);
	Programme p = Programme(pd,pi);

	p.print();	
	p.afficherVariables();
	p.executer();
	cout<<"--------"<<endl;
	p.afficherVariables();

	// //d->print();

	// string c1 = "const1";
	// string c2 = "const2";
	// string c3 = "const3";

	// std::vector<string> vc;
	// vc.push_back(c2);
	// vc.push_back(c3);

	// double v1=12;
	// double v2=13;
	// double v3= -8;

	// std::vector<double> vv;
	// vv.push_back(v2);
	// vv.push_back(v3);

	// Declaration *dc = new DeclarationConstante(c1, v1, vc, vv);

	// std::vector<Declaration*> vd;
	// vd.push_back(dc);

	

	// p.afficherVariables();
	// p.executer();
	// p.afficherVariables();
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

