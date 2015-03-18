#ifndef AUTOMATE_H
#define AUTOMATE_H
#include <deque>
#include <vector>
#include "../Symbole.h"
#include "../Programme.h"
#include "Etat.h"

using namespace std;

class Etat;
class Automate
{
	public:
		Automate(){}
		virtual ~Automate(){}
		
		
		Programme* analyser();
		
		void decalage(Symbole *s, Etat*);
		void reduction(Symbole *s);
		void accepter();
		void erreur();
		void lecture();
	private:
		deque<Symbole*> _pileSymboles;
		deque<Etat*> _pileEtats;
};

#endif
