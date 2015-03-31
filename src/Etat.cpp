	#include "Etat.h"
#include "Automate.h"
#include "Symbole.h"
#include "Identifiants.h"

#include "PartieDeclarative.h"
#include "PartieInstructive.h"
#include "Programme.h"
#include "Expression.h"

#include "Id.h"
#include "Lire.h"
#include "Ecrire.h"
#include "InstructionLire.h"
#include "InstructionEcrire.h"
#include "InstructionAffectation.h"
#include "Terme.h"
#include "Facteur.h"
#include "DeclarationVariable.h"
#include "DeclarationConstante.h"

#include "ExpressionParenthesee.h"

#include "ExpressionAdditive.h"
#include "ExpressionMultiplicative.h"

#include "LigneDeclarationVariable.h"
#include "LigneDeclarationConstante.h"

void E0::transition(Automate & automate, Symbole *s)
{
	PartieDeclarative *symbole;
	switch(*s)
	{
		case Identifiants::ID_LIRE:
		case Identifiants::ID_ECRIRE:
		case Identifiants::ID_VAR:
		case Identifiants::ID_CONST:
		case Identifiants::ID_ID:
		case Identifiants::ID_ENDOFFILE:
			//reduction par la regle 3 : PD -> .
			symbole = new PartieDeclarative();
			//on depile |b| etats
			automate.depilerEtat(0);
			automate.reduction(symbole);
		break;
		//non terminaux
		case Identifiants::ID_PROGRAMME:
			automate.decalage(s, new E1(), false);
		break;
		case Identifiants::ID_PARTIEDECLARATIVE:
			automate.decalage(s, new E2(), false);
		break;
		default:
			automate.erreur();
		break;
	}

}

void E1::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_ENDOFFILE:
			automate.accepter();
		break;
		default:
			automate.erreur();
		break;
	}

}

void E2::transition(Automate & automate, Symbole *s)
{
	PartieInstructive *symbole;
	switch(*s)
	{
		case Identifiants::ID_LIRE:
		case Identifiants::ID_ECRIRE:
		case Identifiants::ID_ID:
		case Identifiants::ID_ENDOFFILE:
			//reduction par la regle 11 : PI-> .
			symbole= new PartieInstructive();
			//on depile |b| etats
			automate.depilerEtat(0);
			automate.reduction(symbole);
		break;
		case Identifiants::ID_CONST:
		//decalage vers l'etat 6
			automate.decalage(s, new E6(), true);
		break;
		case Identifiants::ID_VAR:
		//decalage vers l'etat 5
			automate.decalage(s, new E5(), true);
		break;


		case Identifiants::ID_PARTIEINSTRUCTIVE:
			automate.decalage(s, new E3(), false);
		break;
		case Identifiants::ID_DECLARATION:
		case Identifiants::ID_LIGNEDECLARATIONVARIABLE:
		case Identifiants::ID_LIGNEDECLARATIONCONSTANTE:
			automate.decalage(s, new E4(), false);
		break;
		default:
			automate.erreur();
		break;
	}

}

void E3::transition(Automate & automate, Symbole *s)
{
	Programme *programme;
	PartieInstructive *pi;
	PartieDeclarative *pd;
	switch(*s)
	{
		case Identifiants::ID_LIRE:
		//decalage vers l'etat 10
			automate.decalage(s, new E10(), true);
		break;
		case Identifiants::ID_ECRIRE:
		//decalage vers l'etat 9
			automate.decalage(s, new E9(), true);
		break;
		case Identifiants::ID_ID:
			automate.decalage(s, new E8(), true);
		break;

		case Identifiants::ID_ENDOFFILE:

			//reduction par la regle 1 : Pr -> PD PI
			pi = (PartieInstructive*)automate.depilerSymbole();
			pd = (PartieDeclarative*)automate.depilerSymbole();
			programme = new Programme(pd, pi);
			automate.depilerEtat(2);
			automate.reduction(programme);
		break;

		//non terminaux
		case Identifiants::ID_INSTRUCTION:
		case Identifiants::ID_INSTRUCTIONLIRE:
		case Identifiants::ID_INSTRUCTIONECRIRE:
		case Identifiants::ID_INSTRUCTIONAFFECTATION:
			automate.decalage(s, new E7(), false);
		break;

		default:
			automate.erreur();
		break;
	}
}

void E4::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_POINTVIRGULE:
			automate.decalage(s, new E11(), true);
		break;
		default:
			automate.erreur();
		break;
	}

}

void E5::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_ID:
			automate.decalage(s, new E12(), true);
		break;
		default:
			automate.erreur();
		break;
	}

}

void E6::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_ID:
			automate.decalage(s, new E13(), true);
		break;
		default:
			automate.erreur();
		break;
	}
}

void E7::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_POINTVIRGULE:
			automate.decalage(s, new E14(), true);
		break;
		default:
			automate.erreur();
		break;
	}

}

void E8::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_AFFECTATION:
			automate.decalage(s, new E15(), true);
		break;

		case Identifiants::ID_EGAL:
			automate.decalage(new Affectation(), new E15(), true);
			cout << "Erreur récupérée (= à la place de :=)" << endl;
		break;

		default:
			automate.erreur();
		break;
	}

}

void E9::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_NOMBRE:
			automate.decalage(s, new E21(), true);
		break;
		case Identifiants::ID_ID:
			automate.decalage(s, new E20(), true);
		break;
		case Identifiants::ID_OUVREPARENTHESE:
			automate.decalage(s, new E19(), true);
		break;

		///non terminaux

		case Identifiants::ID_EXPRESSION:
		case Identifiants::ID_EXPRESSIONADDITIVE:
			automate.decalage(s, new E36(), false);
		break;
		case Identifiants::ID_TERME:
		case Identifiants::ID_EXPRESSIONMULTIPLICATIVE:
			automate.decalage(s, new E17(), false);
		break;
		case Identifiants::ID_FACTEUR:
		case Identifiants::ID_EXPRESSIONPARENTHESEE:
			automate.decalage(s, new E18(), false);
		break;
		default:
			automate.erreur();
		break;
	}

}
void E10::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_NOMBRE:
			automate.decalage(s, new E21(), true);
		break;
		case Identifiants::ID_ID:
			automate.decalage(s, new E20(), true);
		break;
		case Identifiants::ID_OUVREPARENTHESE:
			automate.decalage(s, new E19(), true);
		break;

		///non terminaux

		case Identifiants::ID_EXPRESSION:
		case Identifiants::ID_EXPRESSIONADDITIVE:
			automate.decalage(s, new E16(), false);
		break;

		case Identifiants::ID_TERME:
		case Identifiants::ID_EXPRESSIONMULTIPLICATIVE:
			automate.decalage(s, new E17(), false);
		break;
		case Identifiants::ID_FACTEUR:
		case Identifiants::ID_EXPRESSIONPARENTHESEE:
			automate.decalage(s, new E18(), false);
		break;

		default:
			automate.erreur();
		break;
	}

}
void E11::transition(Automate & automate, Symbole *s)
{
	PartieDeclarative *pd, *newPD;
	Declaration *d;
	switch(*s)
	{

		case Identifiants::ID_VAR:
		case Identifiants::ID_CONST:
		case Identifiants::ID_POINTVIRGULE:
		case Identifiants::ID_LIRE:
		case Identifiants::ID_ECRIRE:
		case Identifiants::ID_ID:
		case Identifiants::ID_ENDOFFILE:
			//reduction par la regle 2 PD -> PD D PV

			//depiler pv
			delete automate.depilerSymbole();
			//depiler D
			d = (Declaration*)automate.depilerSymbole();
			//depiler pd
			pd = (PartieDeclarative*)automate.depilerSymbole();

			newPD = new PartieDeclarative(d, pd);

			automate.depilerEtat(3);

			automate.reduction(newPD);
		break;

		default:
			automate.erreur();
		break;
	}

}

void E12::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{

		case Identifiants::ID_VIRGULE:
		case Identifiants::ID_POINTVIRGULE:
			//reduction par la regle 7 V -> .
			automate.reduction(new DeclarationVariable());

		break;

		///non terminaux
		case Identifiants::ID_DECLARATIONVARIABLE:
			automate.decalage(s, new E22(), false);
		break;
		default:
			automate.erreur();
		break;
	}
}

void E13::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{

		case Identifiants::ID_EGAL:
			automate.decalage(s, new E23(), true);
		break;

		case Identifiants::ID_NOMBRE:
			automate.decalage(new Egal(), new E23(), false);
			automate.decalage(s, new E26(), true);
			cout << "Erreur récupérée (égal manquant)" <<endl;
		break;

		default:
			automate.erreur();
		break;
	}

}

void E14::transition(Automate & automate, Symbole *s)
{
	PartieInstructive *PI, *newPI;
	Instruction *I;
	switch(*s)
	{
		case Identifiants::ID_LIRE:
		case Identifiants::ID_ECRIRE:
		case Identifiants::ID_ID:
		case Identifiants::ID_POINTVIRGULE:
		case Identifiants::ID_ENDOFFILE:
			//reduction par la regle 10 PI->PI I pv

			//depiler 3 etats
			automate.depilerEtat(3);
			//depiler point virgule
			delete automate.depilerSymbole();
			//depiler I
			I = (Instruction*)automate.depilerSymbole();
			//depiler PI
			PI = (PartieInstructive*)automate.depilerSymbole();

			newPI = new PartieInstructive(I, PI);
			automate.reduction(newPI);
		break;

		default:
			automate.erreur();
		break;
	}

}

void E15::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_NOMBRE:
			automate.decalage(s, new E21(), true);
		break;
		case Identifiants::ID_ID:
			automate.decalage(s, new E20(), true);
		break;
		case Identifiants::ID_OUVREPARENTHESE:
			automate.decalage(s, new E19(), true);
		break;

		///non terminaux

		case Identifiants::ID_EXPRESSION:
		case Identifiants::ID_EXPRESSIONADDITIVE:
			automate.decalage(s, new E37(), false);
		break;
		case Identifiants::ID_TERME:
		case Identifiants::ID_EXPRESSIONMULTIPLICATIVE:
			automate.decalage(s, new E17(), false);
		break;
		case Identifiants::ID_FACTEUR:
		case Identifiants::ID_EXPRESSIONPARENTHESEE:
			automate.decalage(s, new E18(), false);
		break;

		default:
			automate.erreur();
		break;
	}

}

void E16::transition(Automate & automate, Symbole *s)
{
	Id *id;
	InstructionLire *il;
	switch(*s)
	{

		case Identifiants::ID_OPERATIONADDITIVE:
		case Identifiants::ID_ADDITION:
		case Identifiants::ID_SOUSTRACTION:
			automate.decalage(s, new E32(), true);
		break;


		case Identifiants::ID_POINTVIRGULE:

			//reduction par la regle 14 I -> 'lire' E
			//depiler 3 etats
			automate.depilerEtat(2);

			//dépiler l'expression
			id = (Id*)automate.depilerSymbole();
			//suppression de 'lire'
			delete automate.depilerSymbole();
			il = new InstructionLire(id);
			automate.reduction(il);
		break;

		default:
			automate.erreur();
		break;
	}
}
void E17::transition(Automate & automate, Symbole *s)
{
	Terme*t;
	switch(*s)
	{
		case Identifiants::ID_OPERATIONADDITIVE:
		case Identifiants::ID_ADDITION:
		case Identifiants::ID_SOUSTRACTION:
		case Identifiants::ID_FERMEPARENTHESE:
		case Identifiants::ID_POINTVIRGULE:
			//reduction regle 18 E -> T
			 automate.depilerEtat(1);
			 t = (Terme*)automate.depilerSymbole();
			 t->convertToExpression();
			 automate.reduction(t);
		break;
		case Identifiants::ID_OPERATIONMULTIPLICATIVE:
		case Identifiants::ID_MULTIPLICATION:
		case Identifiants::ID_DIVISION:
			//decalage vers 34
			automate.decalage(s, new E34(), true);

		break;
		default:
			automate.erreur();
		break;
	}

}
void E18::transition(Automate & automate, Symbole *s)
{
	Facteur *f;
	switch(*s)
	{
		case Identifiants::ID_OPERATIONADDITIVE:
		case Identifiants::ID_ADDITION:
		case Identifiants::ID_SOUSTRACTION:
		case Identifiants::ID_OPERATIONMULTIPLICATIVE:
		case Identifiants::ID_MULTIPLICATION:
		case Identifiants::ID_DIVISION:
		case Identifiants::ID_FERMEPARENTHESE:
		case Identifiants::ID_POINTVIRGULE:
			//reduction regle 16 T->F
			automate.depilerEtat(1);
			f = (Facteur*)automate.depilerSymbole();
			f->convertToTerme();
			automate.reduction(f);
		break;
		default:
			automate.erreur();
		break;
	}

}

void E19::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_NOMBRE:
			automate.decalage(s, new E21(), true);
		break;
		case Identifiants::ID_ID:
			automate.decalage(s, new E20(), true);
		break;
		case Identifiants::ID_OUVREPARENTHESE:
			automate.decalage(s, new E19(), true);
		break;


		//non-terminaux

		case Identifiants::ID_EXPRESSION:
		case Identifiants::ID_EXPRESSIONADDITIVE:
			automate.decalage(s, new E38(), false);
		break;
		case Identifiants::ID_TERME:
		case Identifiants::ID_EXPRESSIONMULTIPLICATIVE:
			automate.decalage(s, new E17(), false);
		break;
		case Identifiants::ID_FACTEUR:
		case Identifiants::ID_EXPRESSIONPARENTHESEE:
			automate.decalage(s, new E18(), false);
		break;

		default:
			automate.erreur();
		break;
	}

}

void E20::transition(Automate & automate, Symbole *s)
{
	Id *id;
	switch(*s)
	{
		case Identifiants::ID_OPERATIONADDITIVE:
		case Identifiants::ID_ADDITION:
		case Identifiants::ID_SOUSTRACTION:
		case Identifiants::ID_OPERATIONMULTIPLICATIVE:
		case Identifiants::ID_MULTIPLICATION:
		case Identifiants::ID_DIVISION:
		case Identifiants::ID_FERMEPARENTHESE:
		case Identifiants::ID_POINTVIRGULE:
			//reduction regle 20 F -> Id

			automate.depilerEtat(1);
			id = (Id*)automate.depilerSymbole();
			id->convertToFacteur();
			automate.reduction(id);
		break;
		default:
			automate.erreur();
		break;
	}

}

void E21::transition(Automate & automate, Symbole *s)
{
	Nombre*n;
	switch(*s)
	{
		case Identifiants::ID_OPERATIONADDITIVE:
		case Identifiants::ID_ADDITION:
		case Identifiants::ID_SOUSTRACTION:
		case Identifiants::ID_OPERATIONMULTIPLICATIVE:
		case Identifiants::ID_MULTIPLICATION:
		case Identifiants::ID_DIVISION:
		case Identifiants::ID_FERMEPARENTHESE:
		case Identifiants::ID_POINTVIRGULE:
			//reduction regle 21 F->val
			 automate.depilerEtat(1);
			 n = (Nombre*)automate.depilerSymbole();
			 n->convertToFacteur();
			 automate.reduction(n);

		break;
		default:
			automate.erreur();
		break;
	}

}

void E22::transition(Automate & automate, Symbole *s)
{
	Id *id;
	DeclarationVariable *dv;
	switch(*s)
	{
		case Identifiants::ID_POINTVIRGULE:
			//reduction regle 4 D-> 'var' id V
             automate.depilerEtat(3);
			 dv = (DeclarationVariable*) automate.depilerSymbole();
			 id = (Id*)automate.depilerSymbole();
			 delete automate.depilerSymbole();

			 automate.reduction(new LigneDeclarationVariable(id, dv));

		break;
		case Identifiants::ID_VIRGULE:
			automate.decalage(s, new E24(), true);
		break;

		case Identifiants::ID_ID:
			automate.decalage(new Virgule(), new E24(), false);
			automate.decalage(s, new E25(), true);
			cout << "Erreur récupérée (virugule manquant)" <<endl;
		break; 

		default:
			automate.erreur();
		break;
	}

}

void E23::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_NOMBRE:
			automate.decalage(s, new E26(), true);
		break;
		default:
			automate.erreur();
		break;
	}

}

void E24::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_ID:
			automate.decalage(s, new E25(), true);
		break;
		default:
			automate.erreur();
		break;
	}

}

void E25::transition(Automate & automate, Symbole *s)
{

	DeclarationVariable *dv;
	Id *id;
	switch(*s)
	{
		case Identifiants::ID_VIRGULE:
		case Identifiants::ID_POINTVIRGULE:
			//reduction regle 6 V-> V v id

			automate.depilerEtat(3);
			 id = (Id*)automate.depilerSymbole();

			 delete automate.depilerSymbole();

			 dv = (DeclarationVariable*) automate.depilerSymbole();

			 automate.reduction(new DeclarationVariable(id, dv));
		break;
		default:
			automate.erreur();
		break;
	}

}

void E26::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_VIRGULE:
		case Identifiants::ID_POINTVIRGULE:
			//reduction regle 9 C->.

			automate.reduction(new DeclarationConstante());
		break;
		//non terminaux

		case Identifiants::ID_CONST:
		case Identifiants::ID_DECLARATIONCONSTANTE:
			automate.decalage(s, new E27, false);
		break;

		default:
			automate.erreur();
		break;
	}
}

void E27::transition(Automate & automate, Symbole *s)
{

	DeclarationConstante *dc;

	Id *id;
	Nombre *n;
	switch(*s)
	{
		case Identifiants::ID_VIRGULE:
            automate.decalage(s, new E28(), true);
            break;
		case Identifiants::ID_POINTVIRGULE:
			//reduction regle 5 C -> 'const' id '=' val C
			automate.depilerEtat(5);
			dc = (DeclarationConstante*)automate.depilerSymbole();
			n = (Nombre*)automate.depilerSymbole();
			delete automate.depilerSymbole();
			id = (Id*)automate.depilerSymbole();
			delete automate.depilerSymbole();


			automate.reduction(new LigneDeclarationConstante(id, n, dc));

		break;

		case Identifiants::ID_ID:
			automate.decalage(new Virugule(), new E28(), false);
			automate.decalage(s, new E29(), true);
			cout << "Erreur récupérée (virgule manquante)" <<endl;
		break;

		default:
			automate.erreur();
		break;
	}

}
void E28::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_ID:
		automate.decalage(s, new E29(), true);
		break;

		default:
			automate.erreur();
		break;
	}

}
void E29::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_EGAL:
		automate.decalage(s, new E30(), true);
		break;


		case Identifiants::ID_NOMBRE:
			automate.decalage(new Egal(), new E30(), false);
			automate.decalage(s, new E31(), true);
			cout << Erreur récupérée (égal manquant) <<endl;
		break;


		default:
			automate.erreur();
		break;
	}

}

void E30::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_NOMBRE:
		automate.decalage(s, new E31(), true);
		break;

		default:
			automate.erreur();
		break;
	}

}

void E31::transition(Automate & automate, Symbole *s)
{
	DeclarationConstante*dc;
	Nombre *n;
	Id*id;
	switch(*s)
	{
		case Identifiants::ID_VIRGULE:
		case Identifiants::ID_POINTVIRGULE:
			//reduction regle 8 C -> C v id '=' val

			automate.depilerEtat(5);
			dc = (DeclarationConstante*)automate.depilerSymbole();
			n = (Nombre*)automate.depilerSymbole();
			
			delete automate.depilerSymbole();
			id = (Id*)automate.depilerSymbole();
			delete automate.depilerSymbole();

			automate.reduction(new DeclarationConstante(id, n, dc));
		break;
		default:
			automate.erreur();
		break;
	}


}

void E32::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_NOMBRE:
			automate.decalage(s, new E21(), true);
		break;
		case Identifiants::ID_ID:
			automate.decalage(s, new E20(), true);
		break;
		case Identifiants::ID_OUVREPARENTHESE:
			automate.decalage(s, new E19(), true);
		break;


		//non-terminaux

		case Identifiants::ID_TERME:
		case Identifiants::ID_EXPRESSIONMULTIPLICATIVE:
			automate.decalage(s, new E33(), false);
		break;
		case Identifiants::ID_FACTEUR:
		case Identifiants::ID_EXPRESSIONPARENTHESEE:
			automate.decalage(s, new E18(), false);
		break;


		default:
			automate.erreur();
		break;
	}

}

void E33::transition(Automate & automate, Symbole *s)
{
	Terme *t;
	Expression *e;
	OperationAdditive *opA;
	switch(*s)
	{
		case Identifiants::ID_OPERATIONADDITIVE:
		case Identifiants::ID_ADDITION:
		case Identifiants::ID_SOUSTRACTION:
		case Identifiants::ID_FERMEPARENTHESE:
		case Identifiants::ID_POINTVIRGULE:
			//reduction regle 17 E->E opA F

			automate.depilerEtat(3);
			t = (Terme*)automate.depilerSymbole();
			opA = (OperationAdditive *) automate.depilerSymbole();
			e = (Expression*)automate.depilerSymbole();

			automate.reduction(new ExpressionAdditive(e, t, opA));

		break;
		case Identifiants::ID_OPERATIONMULTIPLICATIVE:
		case Identifiants::ID_MULTIPLICATION:
		case Identifiants::ID_DIVISION:
			//decalage vers 34
			automate.decalage(s, new E34(), true);

		break;
		default:
			automate.erreur();
		break;
	}

}

void E34::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_NOMBRE:
			automate.decalage(s, new E21(), true);
		break;
		case Identifiants::ID_ID:
			automate.decalage(s, new E20(), true);
		break;
		case Identifiants::ID_OUVREPARENTHESE:
			automate.decalage(s, new E19(), true);
		break;

		//non-terminaux
		case Identifiants::ID_FACTEUR:
		case Identifiants::ID_EXPRESSIONPARENTHESEE:
			automate.decalage(s, new E35(), false);
		break;

		default:
			automate.erreur();
		break;
	}

}

void E35::transition(Automate & automate, Symbole *s)
{
	Terme *t;
	Facteur *f;
	OperationMultiplicative *opM;
	switch(*s)
	{
		case Identifiants::ID_OPERATIONADDITIVE:
		case Identifiants::ID_ADDITION:
		case Identifiants::ID_SOUSTRACTION:
		case Identifiants::ID_OPERATIONMULTIPLICATIVE:
		case Identifiants::ID_MULTIPLICATION:
		case Identifiants::ID_DIVISION:
		case Identifiants::ID_FERMEPARENTHESE:
		case Identifiants::ID_POINTVIRGULE:
			//reduction regle 15 T -> T opM F

			automate.depilerEtat(3);
			f = (Facteur*)automate.depilerSymbole();
			opM = (OperationMultiplicative *) automate.depilerSymbole();
			t = (Terme*)automate.depilerSymbole();

			automate.reduction(new ExpressionMultiplicative(t, f, opM));



		break;
		default:
			automate.erreur();
		break;
	}

}

void E36::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		Expression *e;

		case Identifiants::ID_OPERATIONADDITIVE:
		case Identifiants::ID_ADDITION:
		case Identifiants::ID_SOUSTRACTION:
			//decalage vers 34
			automate.decalage(s, new E32(), true);
		break;
		case Identifiants::ID_POINTVIRGULE:
			// reduction regle 13 I -> 'ecrire' E

			automate.depilerEtat(2);
			e = (Expression*)automate.depilerSymbole();
			delete automate.depilerSymbole();

			automate.reduction(new InstructionEcrire(e));

		break;
		default:
			automate.erreur();
		break;
	}

}

void E37::transition(Automate & automate, Symbole *s)
{
	Expression *e;
	Id *id;
	switch(*s)
	{
		case Identifiants::ID_OPERATIONADDITIVE:
		case Identifiants::ID_ADDITION:
		case Identifiants::ID_SOUSTRACTION:
			//decalage vers 34
			automate.decalage(s, new E32(), true);
		break;
		case Identifiants::ID_POINTVIRGULE:
			//reduction regle 12 I -> id ':=' E
			automate.depilerEtat(3);

			e = (Expression*)automate.depilerSymbole();
			delete automate.depilerSymbole();
			id = (Id*)automate.depilerSymbole();

			automate.reduction(new InstructionAffectation(id, e));


		break;
		default:
			automate.erreur();
		break;
	}


}

void E38::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_FERMEPARENTHESE:
			//decalage vers 34
			automate.decalage(s, new E39(), true);
		break;
		case Identifiants::ID_OPERATIONADDITIVE:
		case Identifiants::ID_ADDITION:
		case Identifiants::ID_SOUSTRACTION:
			//decalage vers 32
			automate.decalage(s, new E32(), true);
		break;
		default:
			automate.erreur();
		break;
	}

}


void E39::transition(Automate & automate, Symbole *s)
{
	Expression *e;
	switch(*s)
	{
		case Identifiants::ID_OPERATIONADDITIVE:
		case Identifiants::ID_ADDITION:
		case Identifiants::ID_SOUSTRACTION:
		case Identifiants::ID_OPERATIONMULTIPLICATIVE:
		case Identifiants::ID_MULTIPLICATION:
		case Identifiants::ID_DIVISION:
		case Identifiants::ID_FERMEPARENTHESE:
		case Identifiants::ID_POINTVIRGULE:
			//reduction regle 19 F -> '(' E ')'
			 automate.depilerEtat(3);

			 delete automate.depilerSymbole();
			 e = (Expression*)automate.depilerSymbole();
			 delete automate.depilerSymbole();

			 automate.reduction(new ExpressionParenthesee(e));
		break;
		default:
			automate.erreur();
		break;
	}

}
