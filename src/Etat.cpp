#include "Etat.h"
#include "Automate.h"
#include "Symbole.h"
#include "Identifiants.h"

#include "PartieDeclarative.h"
#include "PartieInstructive.h"
#include "Programme.h"
#include "Expression.h"

#include "Lire.h"
#include "Ecrire.h"
#include "InstructionLire.h"

#include "Variable.h"

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
			automate.empilerSymbole(symbole);
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
		default:
			automate.erreur();
		break;
	}

}

void E9::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_VAR:
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
			automate.decalage(s, new E36(), false);
		break;


		////*******************************/////
		//// Pas complet
		////*******************************/////
		default:
			automate.erreur();
		break;
	}

}
void E10::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_VAR:
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
			automate.decalage(s, new E16(), false);
		break;
		////*******************************/////
		//// TODO Pas complet
		////*******************************/////
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
			//reduction par la regle 2 PD -> PD D PV

			//depiler pv
			delete automate.depilerSymbole();
			//depiler D
			d = (Declaration*)automate.depilerSymbole();
			//depiler pd
			pd = (PartieDeclarative*)automate.depilerSymbole();
			
			//newPD = new PartieDeclarative(pd, d);

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
			//TODO reduction par la regle 7 PD -> PD D PV

			
		break;

		///non terminaux
		case Identifiants::ID_VARIABLE:
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
		
		case Identifiants::ID_VIRGULE:
		case Identifiants::ID_POINTVIRGULE:
			automate.decalage(s, new E23(), true);
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
			//reduction par la regle 10

			//depiler 3 etats
			automate.depilerEtat(3);
			//depiler point virgule
			automate.depilerSymbole();
			//depiler I
			I = (Instruction*)automate.depilerSymbole();
			//depiler PI
			PI = (PartieInstructive*)automate.depilerSymbole();

			//newPI = new PartieInstructive(PI, I);
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
		case Identifiants::ID_VAR:
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
			automate.decalage(s, new E37(), false);
		break;


		////*******************************/////
		//// TODO Pas complet
		////*******************************/////
		default:
			automate.erreur();
		break;
	}

}

void E16::transition(Automate & automate, Symbole *s)
{
	Instruction *newI;
	Variable *v;
	Lire *l;
	InstructionLire *il;
	switch(*s)
	{
		case Identifiants::ID_OPERATIONADDITIVE:
			automate.decalage(s, new E32(), true);
		break;


		case Identifiants::ID_POINTVIRGULE:

			//depiler 3 etats
			automate.depilerEtat(2);
			//reduction par la regle 14
			v = (Variable*)automate.depilerSymbole();
			delete automate.depilerSymbole();
			il = new InstructionLire(v);
			automate.reduction(il);
		break;

		default:
			automate.erreur();
		break;
	}
}
void E17::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_OPERATIONADDITIVE:
		case Identifiants::ID_FERMEPARENTHESE:
		case Identifiants::ID_POINTVIRGULE:
			//reduction regle 18
			 
		break;
		case Identifiants::ID_OPERATIONMULTIPLICATIVE:
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
	switch(*s)
	{
		case Identifiants::ID_OPERATIONADDITIVE:
		case Identifiants::ID_OPERATIONMULTIPLICATIVE:
		case Identifiants::ID_FERMEPARENTHESE:
		case Identifiants::ID_POINTVIRGULE:
			//TODO reduction regle 16
			 
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
		case Identifiants::ID_VAR:
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
		break;

		///TODO pas complet

		default:
			automate.erreur();
		break;
	}

}

void E20::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_OPERATIONADDITIVE:
		case Identifiants::ID_OPERATIONMULTIPLICATIVE:
		case Identifiants::ID_FERMEPARENTHESE:
		case Identifiants::ID_POINTVIRGULE:
			//TODO reduction regle 20
			 
		break;
		default:
			automate.erreur();
		break;
	}

}

void E21::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_OPERATIONADDITIVE:
		case Identifiants::ID_OPERATIONMULTIPLICATIVE:
		case Identifiants::ID_FERMEPARENTHESE:
		case Identifiants::ID_POINTVIRGULE:
			//TODO reduction regle 21
			 
		break;
		default:
			automate.erreur();
		break;
	}

}

void E22::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_POINTVIRGULE:
			//TODO reduction regle 4
			 
		break;
		case Identifiants::ID_VIRGULE:
			automate.decalage(s, new E24(), true);
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
		//TODO à reverifier
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
		//TODO à reverifier
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
	switch(*s)
	{
		case Identifiants::ID_VIRGULE:
		case Identifiants::ID_POINTVIRGULE:
			//TODO reduction regle 6
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
			//TODO reduction regle 9
		break;
		//non terminaux

		case Identifiants::ID_CONST:
			automate.decalage(s, new E27, true);
		break;

		default:
			automate.erreur();
		break;
	}
}

void E27::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_VIRGULE:
		automate.decalage(s, new E28(), true);
		break;
		case Identifiants::ID_POINTVIRGULE:
			//TODO reduction regle 5
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
		
		
		/*case Identifiants::ID_NOMBRE:
		automate.decalage(new Egal(), new E30(), false);
		automate.decalage(s, new E31(), true);
		cout << Erreur récupérée (égal manquant) <<endl;
		break;*/
		

		default:
			automate.erreur();
		break;
	}

}

void E30::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		//TODO à verifier
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
	switch(*s)
	{
		case Identifiants::ID_VIRGULE:
		case Identifiants::ID_POINTVIRGULE:
			//TODO reduction regle 8
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
		case Identifiants::ID_VAR:
			automate.decalage(s, new E21(), true);
		break;
		case Identifiants::ID_ID:
			automate.decalage(s, new E20(), true);
		break;
		case Identifiants::ID_OUVREPARENTHESE:
			automate.decalage(s, new E19(), true);
		break;


		//non-terminaux 

		///TODO  non-terminaux


		default:
			automate.erreur();
		break;
	}

}

void E33::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_OPERATIONADDITIVE:
		case Identifiants::ID_FERMEPARENTHESE:
		case Identifiants::ID_POINTVIRGULE:
			//TODO reduction regle 17
			 
		break;
		case Identifiants::ID_OPERATIONMULTIPLICATIVE:
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
		case Identifiants::ID_VAR:
			automate.decalage(s, new E21(), true);
		break;
		case Identifiants::ID_ID:
			automate.decalage(s, new E20(), true);
		break;
		case Identifiants::ID_OUVREPARENTHESE:
			automate.decalage(s, new E19(), true);
		break;

		default:
			automate.erreur();
		break;
	}

}

void E35::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_OPERATIONADDITIVE:
		case Identifiants::ID_OPERATIONMULTIPLICATIVE:
		case Identifiants::ID_FERMEPARENTHESE:
		case Identifiants::ID_POINTVIRGULE:
			//TODO reduction regle 15
			 
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
		case Identifiants::ID_OPERATIONADDITIVE:
			//decalage vers 34
			automate.decalage(s, new E32(), true);
		break;
		case Identifiants::ID_POINTVIRGULE:
			//TODO reduction regle 13
			 
		break;
		default:
			automate.erreur();
		break;
	}

}

void E37::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_OPERATIONADDITIVE:
			//decalage vers 34
			automate.decalage(s, new E32(), true);
		break;
		case Identifiants::ID_POINTVIRGULE:
			//TODO reduction regle 12
			 
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
		default:
			automate.erreur();
		break;
	}

}


void E39::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_OPERATIONADDITIVE:
		case Identifiants::ID_OPERATIONMULTIPLICATIVE:
		case Identifiants::ID_FERMEPARENTHESE:
		case Identifiants::ID_POINTVIRGULE:
			//TODO reduction regle 19
			 
		break;
		default:
			automate.erreur();
		break;
	}

}
