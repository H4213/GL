
#include "Declaration.h"

Declaration::Declaration() : Symbole(Identifiants::ID_DECLARATION)
{
	_symbole_string = "Declaration";
	est_vide = true;
}

Declaration::Declaration(int id) : Symbole(id)
{

}
vector<Variable*> Declaration::getVariables() {

}

vector<Constante*> Declaration::getConstantes() {

}
