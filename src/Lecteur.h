#if !defined ( LECTEUR_H )
#define LECTEUR_H

#include <boost/regex.hpp>
#include <stdlib.h>

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


using namespace boost;
using namespace std;

static const regex simpleSym("\\(|\\+|\\)|\\-|\\*|\\/|\\;|\\=|,");
static const regex doubleSym(":\\=");
static const regex varSym("var[‘ ‘ , \n , \t]");
static const regex constSym("const[' ',\n , \t]");
static const regex readSym("read[' ' , \n , \t]");
static const regex writeSym("write[' ' , \n , \t]");
static const regex idSym("[a-zA-Z][a-zA-Z0-9]*");
static const regex valSym("[0-9]+");

class Lecteur
{

    private :
        vector<Symbole>::iterator readHeader;
        vector<Symbole> symTerminaux;

		bool isSimpleSym (string s);
        bool isDoubleSym (string s);
        bool isVarSym (string s);
        bool isConstSym (string s);
        bool isReadSym (string s);
        bool isWriteSym (string s);
        bool isIdSym (string s);
        bool isValSym (string s);
        bool isEOF (string s);
        bool isTerminal (string s);

        vector<string> sepSep(string s, string sep);
        vector<string> sepSym (string s , string sym);
        vector<string> sepWords (vector<string> s);
        Symbole createSymbole(string s);

    public :
        Lecteur();
        Lecteur(string s);
		Symbole* getNext();


};


#endif
