#include "Lecteur.h"
//include "stdafx.h"
#include "Symbole.h"
#include "Declaration.h"
#include "DeclarationVariable.h"

#include <string>
using namespace std;


int main(int argc, char *argv[])
{
	string s = "salut, ";
	string s1 = "ça ";
	string s2 = "va ";
	string s3 = "mlle ";
	string s4 = "? ";

	std::vector<string> v;
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);

	DeclarationVariable d = DeclarationVariable(s,v);
	d.print();
	d.comptageVariables();

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
 //     /* vector<string> phrase;
 //       phrase.push_back(contents);

 //    vector<string> result = l.sepWords(phrase);

 //    cout << "resultat" << endl;

 //    int i;
 //    cout << result.size() << endl;
 //    for ( i = 0 ; i< result.size() ; i++)
 //    {
 //        cout << result[i] << endl;
 //    }*/
    return 0;
}

