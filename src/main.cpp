// #include "Lecteur.h"
//include "stdafx.h"
#include "Symbole.h"
#include "DeclarationConstante.h"
#include "DeclarationVariable.h"
#include "Programme.h"
#include "PartieDeclarative.h"
#include "PartieInstructive.h"

#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{

	
	/* 
	Test du constructeur declaration de variable/constante et execution des declarations
	*/

	string s = "salut, ";
	string s1 = "ça ";
	string s2 = "va ";
	string s3 = "mlle ";
	string s4 = "? ";

	vector<string> v = vector<string>();
	cout<<"size: "<<v.size()<<endl;
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);

	Declaration *dv = new DeclarationVariable(s,v);
	//d->print();

	string c1 = "const1";
	string c2 = "const2";
	string c3 = "const3";

	std::vector<string> vc;
	vc.push_back(c2);
	vc.push_back(c3);

	double v1=12;
	double v2=13;
	double v3= -8;

	std::vector<double> vv;
	vv.push_back(v2);
	vv.push_back(v3);

	Declaration *dc = new DeclarationConstante(c1, v1, vc, vv);

	std::vector<Declaration*> vd;
	vd.push_back(dc);

	PartieInstructive *pi = new PartieInstructive();
	PartieDeclarative *pd = new PartieDeclarative(dv, vd);	
	Programme p = Programme(pd,pi);

	p.afficherVariables();
	p.executer();
	p.afficherVariables();

	/*
	Fin du test
	*/

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
	// else if (argc == 3)
	// {
	// 	fichier = fopen (argv[1], "r"); // Ouverture du fichier .txt argv[1]
	// 	options = argv[2];				// Récupération de l'option
	// }
	// else if (argc == 4)
	// {
	// 	fichier = fopen (argv[1], "r"); // Ouverture du fichier .txt argv[1]
	// 	options = argv[2];				// Récupération de l'option
	// 	option_o = true;
	// }


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

 //      Lecteur l(contents);

 //        cout << "getnext 3 fois" << endl;
 //      int i;
 //      for (i=0 ; i<3 ; i++){
 //       l.getNext()->print();
 //      }

         return 0;

}

