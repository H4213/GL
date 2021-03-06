#include "ExpressionMultiplicative.h"
#include <sstream>
ExpressionMultiplicative::ExpressionMultiplicative(Terme *t, Facteur *f, OperationMultiplicative *opM):Terme(Identifiants::ID_EXPRESSIONMULTIPLICATIVE)
{
	terme = t;
	facteur = f;
	operationMultiplicative = opM;
	_symbole_string = "ExpressionMultiplicative";
}
vector<Id*> ExpressionMultiplicative::getIds()
{
	vector<Id*> result = terme->getIds();
	vector<Id*> temp =facteur->getIds();
	result.insert(result.end(),temp.begin(),temp.end());
	return result;
}
double ExpressionMultiplicative::eval(map<string,double> &mapV , map<string,double> &mapC)
{
	double d;
	double valeurTerme = terme->eval(mapV,mapC);
	double valeurFacteur = facteur->eval(mapV,mapC);

	switch(char(*operationMultiplicative))
	{
		case '*':
			d = valeurTerme * valeurFacteur;
		break;

		case '/':
			if(valeurFacteur != 0)
			{
				d = valeurTerme / valeurFacteur;
			}
			else
			{
				// TODO: erreur (division par zero)
			}
		break;
	}
	return d;
}

Expression* ExpressionMultiplicative::transformation(map<string,double> constantes)
{
	Terme * newTerme=(Terme*)(terme->transformation(constantes));
	Facteur * newFacteur=(Facteur*)(facteur->transformation(constantes));
	OperationMultiplicative * newOpM;
	double valeur1;
	double valeur2;
	if ((char) *operationMultiplicative =='*')
	{
        newOpM=new Multiplication();
        if (dynamic_cast<Nombre*>(newTerme)!=NULL)
        {
            valeur1=((Nombre*)newTerme)->getValeur();
            if (valeur1==1)
            {
                return newFacteur;
            }
        }
        if (dynamic_cast<Nombre*>(newFacteur)!=NULL)
        {
            valeur2=((Nombre*)newFacteur)->getValeur();
            if (valeur2==1)
            {
                return newTerme ;
            }
        }
        if (dynamic_cast<Nombre*>(newTerme)!=NULL && dynamic_cast<Nombre*>(newFacteur)!=NULL)
        {
            double valeur3=valeur1*valeur2;
            std::ostringstream strs;
            strs <<valeur3;
            std::string str = strs.str();
            Nombre * nombreRes=new Nombre(str);
            return nombreRes;
        }
        else
        {
            ExpressionMultiplicative * exprRes = new ExpressionMultiplicative(newTerme,newFacteur,newOpM);
            return exprRes;
        }

	}
	else if((char) *operationMultiplicative =='/')
	{
        newOpM=new Division();
        if (dynamic_cast<Nombre*>(newTerme)!=NULL)
        {
            valeur1=((Nombre*)newTerme)->getValeur();
        }
        if (dynamic_cast<Nombre*>(newFacteur)!=NULL)
        {
            valeur2=((Nombre*)newFacteur)->getValeur();
            if (valeur2==1)
            {
                return newTerme ;
            }
        }
        if (dynamic_cast<Nombre*>(newTerme)!=NULL && dynamic_cast<Nombre*>(newFacteur)!=NULL)
        {
            double valeur3=valeur1/valeur2;
            std::ostringstream strs;
            strs <<valeur3;
            std::string str = strs.str();
            Nombre * nombreRes=new Nombre(str);
            return nombreRes;
        }
        else
        {
            ExpressionMultiplicative * exprRes = new ExpressionMultiplicative(newTerme,newFacteur,newOpM);
            return exprRes;
        }

	}



}
void ExpressionMultiplicative::print()
{
	terme->print();
	operationMultiplicative->print();
	facteur->print();

}
