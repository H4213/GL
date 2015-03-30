#include "Division.h"
#include "Identifiants.h"

Division::Division(): OperationMultiplicative(Identifiants::ID_DIVISION)
{
	_symbole_string = "/";
	_operation = '/';
}