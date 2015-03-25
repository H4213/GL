#include "LigneDeclarationConstante.h"

LigneDeclarationConstante::LigneDeclarationConstante(Id*idO, DeclarationConstante*dc, Nombre *v)
: Declaration(Identifiants::ID_LIGNEDECLARATIONCONSTANTE)
{
	id = idO;
	declarationConstante = dc;
	val = v;
}

LigneDeclarationConstante::~LigneDeclarationConstante()
{
	delete id;
	delete declarationConstante;
	delete val;
}