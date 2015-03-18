#include "Nombre.h"
#include "Identifiants.h"

#include <string>

Nombre::Nombre(double v):Expression(Identifiants::ID_NOMBRE)
{
	_symbole_string = "Nombre";
}