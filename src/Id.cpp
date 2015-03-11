#include "Id.h"
#include "Identifiants.h"
#include <string>
using namespace std;

Id::Id(string nom):Symbole(Identifiants::ID_ID)
{
	_symbole_string = nom;
}	