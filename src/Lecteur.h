#if !defined ( LECTEUR_H )
#define LECTEUR_H

#include <boost/regex.hpp>
#include <stdlib.h>

using namespace boost;
using namespace std;

static const regex simpleSym("\\(|\\+|\\)|\\-|\\*|\\/|\\;|\\=");
static const regex doubleSym(":\\=");
static const regex varSym("var[‘ ‘ , \n , \t]");
static const regex constSym;
static const regex readSym;
static const regex writeSym;
static const regex idSym;
static const regex valSym;

class Lecteur
{

    private :
        string temp;

    public :
        Lecteur(){}

        bool isSimpleSym (string s);
        bool isDoubleSym (string s);
        bool isVarSym (string s);
        bool isConstSym (string s);
        bool isReadSym (string s);
        bool isWriteSym (string s);
        bool isIdSym (string s);
        bool isValSym (string s);


};


#endif
