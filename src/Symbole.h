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
		bool est_vide;
		int ligne;
		int colonne;

		bool estConstante(string nom, map<string,double> &mapC);
		bool estVariable(string nom, map<string,double> &mapV);
		
	public: 
		Symbole();
		Symbole(int id): _ident(id){est_vide = false;}
		virtual ~Symbole(){}

		operator int() const {return _ident;}
		bool estVide(){return est_vide;}
		virtual void executer(map<string,double> &mapV , map<string,double> &mapC){}
		virtual void print();
		virtual void setEmplacement(int l , int c);

		int getLigne(){return ligne;}
		int getColonne(){return colonne;}

		string nom(){return _symbole_string;}
};

#endif
