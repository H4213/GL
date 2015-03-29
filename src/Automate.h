#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <vector>
#include "Symbole.h"
#include "Programme.h"
#include "Etat.h"
#include "Identifiants.h"
#include "Lecteur.h"

using namespace std;

class Etat;
class Automate
{
	public:

		Automate();
		virtual ~Automate();

		Programme* analyser(string);

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
<<<<<<< HEAD
		bool analyseStatique(Programme *Pr);
		Programme* transformation(Programme *Pr);
=======

>>>>>>> 4aa819774a29fb5904fe174a28a4159dde08ba49
		void afficherPiles();

	private:
		Lecteur *lecteur;
		deque<Symbole*> _pileSymboles;
		deque<Etat*> _pileEtats;
		bool error_state;
		bool success_state;

};

#endif
