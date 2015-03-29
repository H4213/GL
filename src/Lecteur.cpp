#include "Lecteur.h"

Lecteur::Lecteur (string s)
{
    vector<string> phrase;
    phrase.push_back(s+"$");

    sepWords(phrase);

    cout << "resultat" << endl;

    int i;
    cout << symTerminaux.size() << endl;
    for ( i = 0 ; i< symTerminaux.size() ; i++)
    {
        symTerminaux[i]->print();
    }
    readHeader = symTerminaux.begin();
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

bool Lecteur::isEOF(string s)
{
    return regex_match(s, eofSym);
}

bool Lecteur::isTerminal(string s)
{
    if(isValSym(s)||isIdSym(s)||isWriteSym(s)||isReadSym(s)||isConstSym(s)||isVarSym(s)||isDoubleSym(s)||isSimpleSym(s)|isEOF(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

vector<string> Lecteur::sepSep(string s,string sep)
{
    vector<string> words;
    size_t i = 0;
    size_t j = s.find_first_of(sep, i);
    string word = "";
    while( j != -1 )
    {
        word = s.substr(i,j-i);
        if ( word != "") {
            //cout << word << "|";
            words.push_back(word);
        }
        i=j+1;
        j = s.find_first_of(sep,i);
        if (j== -1 )
        {
            word = s.substr(i , s.size());
            words.push_back(word);
        }
    }

    return words;
}

vector<string> Lecteur::sepSym(string s , string sym)
{
    vector<string> words;
    size_t i = 0;
    size_t j = s.find_first_of(sym, i);
    string word = "";
    while( j != -1 )
    {
        word = s.substr(i,j-i);

        if ( word != "") {
            words.push_back(word);
            words.push_back(sym);
        }
        else
        {
            words.push_back(sym);
        }
        i=j+1;
        j = s.find_first_of(sym,i);
        if (j == -1)
        {
            word = s.substr(i,s.size());
            if (word!="")
            {
                words.push_back(word);
            }
        }
    }
    return words;

}

vector<string> Lecteur::sepWords(vector<string> phrase)
{
    vector<string> result;
    int i;
    for (i = 0 ; i<phrase.size() ; i++ )
    {
        if (!isTerminal(phrase[i]))
        {
            if (phrase[i].find("\n")!=-1)
            {
                vector<string> temp = sepWords(sepSep(phrase[i],"\n"));
                result.insert(result.end(), temp.begin() , temp.end());
            }
            else if(phrase[i].find(" ")!=-1)
            {
                vector<string> temp = sepWords(sepSep(phrase[i]," "));
                result.insert(result.end(), temp.begin() , temp.end());
            }
            else if (phrase[i].find(";")!=-1)
            {
                vector<string> temp = sepWords (sepSym(phrase[i], ";"));
                result.insert(result.end(), temp.begin() , temp.end());
            }
            else if(phrase[i].find(",")!=-1)
            {
                vector<string> temp = sepWords (sepSym(phrase[i], ","));
                result.insert(result.end(), temp.begin() , temp.end());
            }

            else if(phrase[i].find("+")!=-1)
            {
                vector<string> temp = sepWords (sepSym(phrase[i], "+"));
                result.insert(result.end(), temp.begin() , temp.end());
            }
            else if(phrase[i].find("-")!=-1)
            {
                vector<string> temp = sepWords (sepSym(phrase[i], "-"));
                result.insert(result.end(), temp.begin() , temp.end());
            }
            else if(phrase[i].find("*")!=-1)
            {
                vector<string> temp = sepWords (sepSym(phrase[i], "*"));
                result.insert(result.end(), temp.begin() , temp.end());
            }
            else if(phrase[i].find("/")!=-1)
            {
                vector<string> temp = sepWords (sepSym(phrase[i], "/"));
                result.insert(result.end(), temp.begin() , temp.end());
            }
            else if(phrase[i].find(":=")!=-1)
            {
                vector<string> temp = sepWords (sepSym(phrase[i], ":="));
                result.insert(result.end(), temp.begin() , temp.end());
            }
            else if(phrase[i].find("=")!=-1)
            {
                vector<string> temp = sepWords (sepSym(phrase[i], "="));
                result.insert(result.end(), temp.begin() , temp.end());
            }
            else if (phrase[i].find("(")!=-1)
            {
                vector<string> temp = sepWords (sepSym(phrase[i], "("));
                result.insert(result.end(), temp.begin() , temp.end());
            }
            else if (phrase[i].find(")")!=-1)
            {
                vector<string> temp = sepWords (sepSym(phrase[i], ")"));
                result.insert(result.end(), temp.begin() , temp.end());
            }
            else if(phrase[i].find("EOF")!=-1)
            {
                vector<string> temp = sepWords (sepSep(phrase[i], "EOF"));

            }
            else
            {
                cout<<"erreur lexical "<< phrase[i]<<" n'est pas reconnu"<<endl;
            }
        }
        else
        {
            Symbole *newSymbole = createSymbole(phrase[i]);
            result.push_back(phrase[i]);
            symTerminaux.push_back(newSymbole);
            //cout << "creation de :" << phrase[i] << endl;
            //newSymbole.print();
        }
    }
    return result;
}
Symbole* Lecteur::createSymbole(string s)
{
    Symbole* newSym;
    if (s=="var")
    {
        Var *result = new Var();
           newSym=result;
    }
    else if (s=="const")
    {
     Const * result = new Const();
        newSym=result;
    }
    else if (s=="ecrire")
    {
      Ecrire * result = new Ecrire();
         newSym=result;
    }
    else if (s=="lire")
    {
      Lire * result = new Lire();
         newSym=result;
    }
    else if (s==":=")
    {
      Affectation  * result = new Affectation();
         newSym=result;
    }
    else if (s=="=")
    {
      Egal  * result = new Egal();
         newSym=result;
    }
    else if (s=="(")
    {
       OuvreParenthese * result =new  OuvreParenthese();// Egal();
          newSym=result;
    }
    else if (s==")")
    {
       FermeParenthese * result = new FermeParenthese();// Egal();
          newSym=result;
	}
    else if (s==";")
    {
        PointVirgule * result= new PointVirgule();
           newSym=result;
    }
    else if (s==",")
    {
       Virgule * result=new Virgule();
          newSym=result;
    }
    else if (s=="+")
    {
      Addition  * result=new Addition();
         newSym=result;
    }
    else if (s=="-")
    {
       Soustraction * result= new Soustraction();
          newSym=result;
    }
    else if (s=="/")
    {
       Division * result= new Division();
          newSym=result;
    }
    else if (s=="*")
    {
       Multiplication * result= new Multiplication();
          newSym=result;
    }
    else if (isValSym(s))
    {
        Nombre * result= new Nombre(s);
           newSym=result;
    }
    else if (s=="$")
    {
       EndOfFile * result= new EndOfFile();
       newSym=result;
    }
    else
    {
       Id * result=new  Id(s);   
       newSym=result;
    }
	return newSym;
}


Symbole* Lecteur::getNext()
{
	if ( readHeader < symTerminaux.end() )
	{
		return *readHeader;

	}
	else
	{
		return NULL;
	}
}


void Lecteur::moveReadHeader()
{
	if (readHeader != symTerminaux.end())
	{
		readHeader++;
	}
}



