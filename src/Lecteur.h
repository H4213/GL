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
#include "Nombre.h"
#include "EndOfFile.h"


using namespace boost;
using namespace std;

static const regex simpleSym("\\(|\\+|\\)|\\-|\\*|\\/|\\;|\\=|,");
static const regex doubleSym(":\\=");
static const regex varSym("var[‘ ‘ , \n , \t]");
static const regex constSym("const[' ',\n , \t]");
static const regex readSym("lire[' ' , \n , \t]");
static const regex writeSym("ecrire[' ' , \n , \t]");
static const regex idSym("[a-z][a-zA-Z0-9]*");
static const regex valSym("[0-9]+");
static const regex eofSym("\\$");

class Lecteur
{

    private :
        vector<Symbole*>::iterator readHeader;
        vector<Symbole*> symTerminaux;

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
        vector<string> sepWords (vector<string> s , map<string,int> &occ);
        Symbole* createSymbole(string s);
        string code; // corp du code
        vector<int> findEmplacement(string s , int lastOcc ); // trouve la ligne (case 1) et la colonne (case 2) du string actuel dans le code

    public :
        Lecteur(){}
        Lecteur(string s);
		Symbole* getNext();
		void moveReadHeader();


};


#endif
