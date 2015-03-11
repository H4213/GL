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

bool Lecteur::isTerminal(string s)
{
    if(isValSym(s)||isIdSym(s)||isWriteSym(s)||isReadSym(s)||isConstSym(s)||isVarSym(s)||isDoubleSym(s)||isSimpleSym(s))
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
            cout << word << "|";
            words.push_back(word);
        }
        i=j+1;
        j = s.find_first_of(sep,i);
        if (j== -1 )
        {
            word = s.substr(i , s.size());
            cout<< word << endl;
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
            cout << word + sym <<"|";
            words.push_back(word);
            words.push_back(sym);
        }
        i=j+1;
        j = s.find_first_of(sym,i);
        if (j == -1)
        {
            word = s.substr(i,s.size());
            cout << word << endl;
            words.push_back(word);
        }
    }
    return words;

}

vector<string> Lecteur::sepWords (vector<string> phrase)
{
    vector<string> result;
    int i;
    for (i = 0 ; i<phrase.size() ; i++ )
    {
        if (!isTerminal(phrase[i]))
        {
            if(phrase[i].find(";")!=-1)
            {
                vector<string> temp = sepWords (sepSym(phrase[i], ";"));
                result.insert(result.end(), temp.begin() , temp.end());
            }
            else if (phrase[i].find(" ")!=-1)
            {
                vector<string> temp = sepWords(sepSep(phrase[i]," "));
                result.insert(result.end(), temp.begin() , temp.end());
            }
            else if (phrase[i].find("\n")!=-1)
            {
                vector<string> temp = sepWords(sepSep(phrase[i],"\n"));
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
            else if(phrase[i].find("\0")!=-1)
            {
                vector<string> temp = sepWords (sepSep(phrase[i], "\0"));
                
            }
            else
            {
				cout<<"erreur lexical "<<phrase[i]<<" n'est pas reconnu"<<endl;
			}

        }
        else
        {
            s.push_back(phrase[i]);
        }
    }
    return result;
}








