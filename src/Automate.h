#ifndef AUTOMATE_H
#define AUTOMATE_H
#include <deque>
#include <vector>
#include "Symbole.h"
#include "Etat.h"
#include <map>
#include <utility>
#include <algorithm>


#include "Addition.h"
#include "Affectation.h"
#include "Const.h"
#include "Division.h"
#include "Ecrire.h"
#include "Egal.h"
#include "FermeParenthese.h"
#include "Id.h"
#include "Lire.h"
#include "Multiplication.h"
#include "OuvreParenthese.h"
#include "PointVirgule.h"
#include "Soustraction.h"
#include "Var.h"
#include "Virgule.h"
#include "Variable.h"
#include "Constante.h"
#include "Identifiants.h"
#include "Programme.h"
//Addition.h                Expression.h                  Multiplication.h
//Affectation.h             ExpressionMultiplicative.h    Nombre.h
//Automate.h                             OperationMultiplicative.h
//Constante.h                                                              PartieDeclarative.h
//DeclarationConstante.h    InstructionAffectation.h                     PartieInstructive.h
//Declaration.h   InstructionEcrire.h
//DeclarationVariable.h     Instruction.h                            Programme.h                InstructionLire.h                     Symbole.h                    EndOfFile.h                                        Variable.h
//ExpressionAdditive.h

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

		void analyseStatique();
	private:
		deque<Symbole*> _pileSymboles;
		deque<Etat*> _pileEtats;
};

#endif
