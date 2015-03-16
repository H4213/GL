#include "DeclarationConstante.h"
#include "Identifiants.h"

DeclarationConstante::DeclarationConstante(string nomConstante, double valeur, vector<string> autresConstantes, vector<double> autresValeurs) : Declaration(Identifiants::ID_DECLARATIONCONSTANTE)
{
	constante = Constante(nomConstante,valeur);
	//TODO
}