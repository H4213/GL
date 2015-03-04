#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "Symbole.h"
#include "Etat.h"

class Etat;

class Automate
{
	public:
		Automate(){}
		virtual ~Automate(){}
		
		void decalage(Symbole s, Etat*);
};

#endif
