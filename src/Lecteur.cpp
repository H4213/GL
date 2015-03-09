#include "Lecteur.h"


void Lecteur ( )
{

}

bool Lecteur::isSimpleSym(string s)
{
    return regex_match(s,simpleSym);
}

bool Lecteur::isDoubleSym(string s)
{
    return regex_match(s,doubleSym);
}

bool Lecteur::isVarSym(string s)
{
    return regex_match(s,varSym);
}

bool Lecteur::isConstSym(string s)
{
    return regex_match(s,constSym);
}

bool Lecteur::isReadSym(string s)
{
    return regex_match(s,readSym);
}

bool Lecteur::isWriteSym(string s)
{
    return regex_match(s,writeSym);
}

bool Lecteur::isIdSym(string s)
{
    return regex_match(s,idSym);
}

bool Lecteur::isValSym(string s)
{
    return regex_match(s,valSym);
}

