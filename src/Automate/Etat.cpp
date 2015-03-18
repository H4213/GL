#include "Etat.h"
#include "Automate.h"
#include "../Symbole.h"
#include "../Identifiants.h"

#include "../PartieDeclarative.h"
#include "../PartieInstructive.h"


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
			//reduction par la regle 3
			symbole= new PartieDeclarative();
			automate.reduction(symbole);
		break;
		
		case Identifiants::ID_PROGRAMME:
			automate.transition(automate,                                                                                                                                                                                                                     
		break;
		default:
			                                   
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
			//reduction par la regle 11
			symbole= new PartieInstructive();
			//automate.reduction(symbole);
		break;
		case Identifiants::ID_CONST:
		//decalage vers l'etat 6 
			automate.decalage(s, new E6());
		break;
		case Identifiants::ID_VAR:
		//decalage vers l'etat 5
			automate.decalage(s, new E5());
		break;
		
		
		case Identifiants::ID_ID:
		
		default:
			automate.erreur();
		break;
	}

}

void E3::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case Identifiants::ID_LIRE:
		//decalage vers l'etat 10 
			automate.decalage(s, new E10());
		break;
		case Identifiants::ID_ECRIRE:
		//decalage vers l'etat 9 
			automate.decalage(s, new E9());
		break;
		case Identifiants::ID_ID:
			automate.decalage(s, new E8());
		break;
		default:
			automate.erreur();
		break;
	}
}

void E4::transition(Automate & automate, Symbole *s)
{
	

}

void E5::transition(Automate & automate, Symbole *s)
{
	

}

void E6::transition(Automate & automate, Symbole *s)
{
	

}

void E7::transition(Automate & automate, Symbole *s)
{
	

}

void E8::transition(Automate & automate, Symbole *s)
{
	

}

void E9::transition(Automate & automate, Symbole *s)
{
	

}
void E10::transition(Automate & automate, Symbole *s)
{
	

}
void E11::transition(Automate & automate, Symbole *s)
{
	

}

void E12::transition(Automate & automate, Symbole *s)
{
	

}

void E13::transition(Automate & automate, Symbole *s)
{
	

}

void E14::transition(Automate & automate, Symbole *s)
{
	

}

void E15::transition(Automate & automate, Symbole *s)
{
	

}

void E16::transition(Automate & automate, Symbole *s)
{
	

}
void E17::transition(Automate & automate, Symbole *s)
{
	

}

void E18::transition(Automate & automate, Symbole *s)
{
	

}

void E19::transition(Automate & automate, Symbole *s)
{
	

}

void E20::transition(Automate & automate, Symbole *s)
{
	

}

void E21::transition(Automate & automate, Symbole *s)
{
	

}

void E22::transition(Automate & automate, Symbole *s)
{
	

}

void E23::transition(Automate & automate, Symbole *s)
{
	

}

void E24::transition(Automate & automate, Symbole *s)
{
	

}

void E25::transition(Automate & automate, Symbole *s)
{
	

}

void E26::transition(Automate & automate, Symbole *s)
{
	

}

void E27::transition(Automate & automate, Symbole *s)
{
	

}

void E29::transition(Automate & automate, Symbole *s)
{
	

}

void E30::transition(Automate & automate, Symbole *s)
{
	

}

void E31::transition(Automate & automate, Symbole *s)
{
	

}

void E32::transition(Automate & automate, Symbole *s)
{
	

}

void E33::transition(Automate & automate, Symbole *s)
{
	

}

void E34::transition(Automate & automate, Symbole *s)
{
	

}

void E35::transition(Automate & automate, Symbole *s)
{
	

}

void E36::transition(Automate & automate, Symbole *s)
{
	

}

void E37::transition(Automate & automate, Symbole *s)
{
	

}

void E38::transition(Automate & automate, Symbole *s)
{
	

}


void E39::transition(Automate & automate, Symbole *s)
{
	

}
