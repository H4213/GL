#include "Id.h"

#include <string>
using namespace std;

Id::Id(string nom):Facteur(Identifiants::ID_ID)
{
	_symbole_string = nom;
}	

string Id::getNom() const
{
	return _symbole_string;
}

bool Id::operator==(const Id& b)

{
    if (_symbole_string==b.getNom())
	{
        return true;
	}
    else
	{
        return false;
	}
}
