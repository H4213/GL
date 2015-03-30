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



map<string,double> LigneDeclarationConstante::getConstantesValeurs()
{	
	map<string,double> result;
	pair<string,double> temp (id->getNom(),val->getValeur());
	result.insert(temp);
	if (declarationConstante->estVide()==false)
	{
		
		map<string,double> vecTemp = declarationConstante->getConstantesValeurs();
		result.insert(vecTemp.begin(), vecTemp.end());
	}
	return result;
}

void LigneDeclarationConstante::executer(map<string,double> &mapV)
{
     if(declarationConstante->estVide()==false)
	{
		declarationConstante->executer(mapV);
	}
	mapV[id->getNom()]= val->getValeur();
}
