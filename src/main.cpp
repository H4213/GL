#include "Lecteur.h"



/*
 *
 */
int main(int argc, char** argv) {

    Lecteur l;

    vector<string> phrase;
    phrase.push_back("var   x,y,z;const n= 3, n2=5;read x; write l; x:=18+5/4;");
    vector<string> result = l.sepWords(phrase);

    cout << "resultat" << endl;

    int i;
    cout << result.size() << endl;
    for ( i = 0 ; i< result.size() ; i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}

