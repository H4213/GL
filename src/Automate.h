#ifndef AUTOMATE_H
#define AUTOMATE_H
#include <deque>
#include <vector>
#include "Symbole.h"
#include "Programme.h"
#include "Etat.h"

#include "Lecteur.h"
using namespace std;

class Etat;
class Automate
{
	public:
		Automate(string filename);
		virtual ~Automate(){}
		
		
		Programme* analyser();
		
		void decalage(Symbole *s, Etat*, bool);
		void reduction(Symbole*);
		void accepter();
		void erreur();

		void empilerEtat(Etat*e);
		void depilerEtat(int n);

		void empilerSymbole(Symbole*s);
		Symbole* depilerSymbole();

		Etat *sommetEtat();

		void avancerLecteur();
		Symbole* courant();
		
		void analyseStatique();
		
	private:
		deque<Symbole*> _pileSymboles;
		deque<Etat*> _pileEtats;
		Lecteur *lecteur;
};

#endif
