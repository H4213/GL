
#include "Declaration.h"

Declaration::Declaration() : Symbole(Identifiants::ID_DECLARATION)
{
	_symbole_string = "Declaration";
	est_vide = true;
}



vector<Id*> Declaration::getVariables() {

}

vector<Id*> Declaration::getConstantes() {

}
map<string,double> Declaration::getConstantesValeurs(){
	
}


