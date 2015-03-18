#if !defined ( DECLARATIONCONSTANTE_H )
#define DECLARATIONCONSTANTE_H
#include "Declaration.h"
#include "Constante.h"

#include <string>
#include <vector>
using namespace std;

class DeclarationConstante : public Declaration {

public:
	DeclarationConstante(string nomConstante, double valeur, vector<string> autresConstantes, vector<double> autresValeurs); 
	virtual ~DeclarationConstante(){}

private:
	Constante constante;
	DeclarationConstante* declarationAutreConstante;

};


#endif