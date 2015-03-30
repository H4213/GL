#include "Id.h"
#include <sstream>
#include <string>
using namespace std;

vector<Id*> Id::getIds()
{
	vector<Id*> result;
	result.push_back(this);
	return result;
}
Id::Id(string nom):Facteur(Identifiants::ID_ID)
{
	_symbole_string = nom;
}

string Id::getNom() const
{
	return _symbole_string;
}
Expression* Id::transformation(map<string,double> constantes)
{
	
		if (constantes.find(_symbole_string)!=constantes.end())
		{
			std::ostringstream strs;
			strs <<constantes.find(_symbole_string)->second;
			std::string str = strs.str();
			Nombre * result= new Nombre(str);
			return result;
		}
		else
		{
			return this;
		}
		
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
