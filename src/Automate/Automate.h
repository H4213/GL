#ifndef AUTOMATE_H
#define AUTOMATE_H
#include <deque>
#include <vector>
#include "Symbole.h"
#include "Etat.h"

using namespace std;

class Etat;
class Automate
{
	public:
		Automate(){}
		virtual ~Automate(){}
		
		void decalage(Symbole *s, Etat*);
		void reduction(Symbole *s, Etat*, int);
		void accepter();
		void erreur();
		void lecture();
	private:
		deque<Symbole*> _pileSymboles;
		deque<Etat*> _pileEtats;
};

#endif
