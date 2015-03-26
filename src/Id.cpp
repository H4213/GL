#include "Id.h"

#include <string>
using namespace std;

Id::Id(string nom):Facteur(Identifiants::ID_ID)
{
	_symbole_string = nom;
}	
