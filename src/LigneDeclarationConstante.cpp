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
vector<Id*> LigneDeclarationConstante::getConstantes()
{
	vector<Id*> result;
	result.push_back(id);
	
	if (declarationConstante != NULL)
	{
	vector<Id*> autresConstantes = declarationConstante->getConstantes();
	result.insert(result.end(), autresConstantes.begin(), autresConstantes.end());
	}
}
