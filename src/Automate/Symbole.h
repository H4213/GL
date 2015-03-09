#ifndef SYMBOLE_H
#define SYMBOLE_H

#include <string>
using namespace std;

class Symbole
{
	protected: 
		int _ident;
		string _symbole_string;
		
	public: 
		Symbole(int id): _ident(id){}
		virtual ~Symbole(){}

		void print();
		operator int() const {return _ident;}
};

#endif
	