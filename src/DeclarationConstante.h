#if !defined ( DECLARATIONCONSTANTE_H )
#define DECLARATIONCONSTANTE_H
#include "Declaration.h"
#include "Constante.h"

#include <string>

class DeclarationConstante : public Declaration {

public:
	DeclarationConstante(string nomConstante, double valeur);  /*peut etre, aussi, un tableau de string et un double pour creer 
																recoursivement les autres declarations de constantes*/
	virtual ~DeclarationConstante(){}

private:
	Constante constante;
	DeclarationConstante declarationAutreConstante;

};


#endif