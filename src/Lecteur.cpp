#include "Lecteur.h"


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
