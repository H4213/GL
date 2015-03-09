#include "main.h"
#include "Symbole.h"
#include "Soustraction.h"
#include "Addition.h"
#include "Ecrire.h"

int main()
{
	//test pour voir si on arrive bien a recuperer leurs strings
	Symbole* s = new Soustraction();
	s->	print();
	s = new Addition();
	s->	print();
	s = new Ecrire();
	s->	print();
	//fin du test

	return 0;	
}
