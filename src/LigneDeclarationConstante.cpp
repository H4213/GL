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
vector<Id*> LigneDeclarationConstante::getVariables()
{
	vector<Id*> result;
	return result;
}
vector<Id*> LigneDeclarationConstante::getConstantes()
{
	vector<Id*> result;
	result.push_back(id);

	if (declarationConstante->estVide()==false)
	{
	vector<Id*> autresConstantes = declarationConstante->getConstantes();
	result.insert(result.end(), autresConstantes.begin(), autresConstantes.end());
	}
	return result;
}

<<<<<<< HEAD

vector<pair<Id*,Nombre*> > LigneDeclarationConstante::getConstantesValeurs()
{	
	vector<pair<Id*,Nombre*> > result;
	pair<Id*, Nombre*> temp (id,val);
	result.push_back(temp);
	if (declarationConstante->estVide()==false)
	{
		vector<pair<Id*,Nombre*> > vecTemp=declarationConstante->getConstantesValeurs();
		result.insert(result.end(),vecTemp.begin(), vecTemp.end());
	}
	return result;
}
=======
>>>>>>> 4aa819774a29fb5904fe174a28a4159dde08ba49
void LigneDeclarationConstante::executer(map<string,double> &mapV)
{
     if(declarationConstante->estVide()==false)
	{
		declarationConstante->executer(mapV);
	}
	mapV[id->getNom()]= val->getValeur();
}
