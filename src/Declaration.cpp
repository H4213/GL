
#include "Declaration.h"
// #include "Identifiants.h"

Declaration::Declaration() : Symbole(Identifiants::ID_DECLARATION)
{
	_symbole_string = "Declaration";
}

Declaration::Declaration(int id) : Symbole(id)
{

}
vector<Variable*> Declaration::getVariables() {

}
vector<Constante*> Declaration::getConstantes() {

}
