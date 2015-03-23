#ifndef SYMBOLE_H
#define SYMBOLE_H
#include "Identifiants.h"

#include <string>
#include <map>
using namespace std;

class Symbole
{
	protected: 
		int _ident;
		string _symbole_string;
		
	public: 
		Symbole();
		Symbole(int id): _ident(id){}		
		virtual ~Symbole(){}

		operator int() const {return _ident;}
		virtual void print();
		virtual void executer(map<string,double> &mapV){}
};

#endif
	