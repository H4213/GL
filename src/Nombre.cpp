#include "Nombre.h"

#include <string>

Nombre::Nombre(double v):Expression(Identifiants::ID_NOMBRE)
{
	_symbole_string = "Nombre";
}