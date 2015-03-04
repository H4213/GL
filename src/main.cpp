#include "Lecteur.h"



/*
 *
 */
int main(int argc, char** argv) {

    Lecteur l;

    if (l.isSimpleSym("a"))
    {
        cout << "vrai" << endl;

    }
    else
    {
        cout << "pas vrai" << endl;

    }

    return 0;
}

