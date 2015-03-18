#ifndef ETAT_H
#define ETAT_H

#include "Automate.h"
#include <iostream>

using namespace std;

class Symbole;class Automate;

class Etat
{
	public:
		Etat();
		virtual ~Etat(){}
		virtual void transition(Automate & automate, Symbole *s) = 0;

	protected:
	string _name;
};

class E0 : public Etat
{
	public:
		E0() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};

class E1 : public Etat
{
	public:
		E1() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};

class E2 : public Etat
{
	public:
		E2() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E3 : public Etat
{
	public:
		E3() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E4 : public Etat
{
	public:
		E4() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E5 : public Etat
{
	public:
		E5() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E6 : public Etat
{
	public:
		E6() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E7 : public Etat
{
	public:
		E7() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E8 : public Etat
{
	public:
		E8() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E9 : public Etat
{
	public:
		E9() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E10 : public Etat
{
	public:
		E10() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E11 : public Etat
{
	public:
		E11() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E12 : public Etat
{
	public:
		E12() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E13 : public Etat
{
	public:
		E13() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E14 : public Etat
{
	public:
		E14() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E15 : public Etat
{
	public:
		E15() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E16 : public Etat
{
	public:
		E16() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E17 : public Etat
{
	public:
		E17() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E18 : public Etat
{
	public:
		E18() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E19 : public Etat
{
	public:
		E19() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E20 : public Etat
{
	public:
		E20() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E21 : public Etat
{
	public:
		E21() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E22 : public Etat
{
	public:
		E22() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E23 : public Etat
{
	public:
		E23() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E24 : public Etat
{
	public:
		E24() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E25 : public Etat
{
	public:
		E25() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E26 : public Etat
{
	public:
		E26() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E27 : public Etat
{
	public:
		E27() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E28 : public Etat
{
	public:
		E28() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E29 : public Etat
{
	public:
		E29() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E30 : public Etat
{
	public:
		E30() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E31 : public Etat
{
	public:
		E31() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E32 : public Etat
{
	public:
		E32() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E33 : public Etat
{
	public:
		E33() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E34 : public Etat
{
	public:
		E34() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E35 : public Etat
{
	public:
		E35() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E36 : public Etat
{
	public:
		E36() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E37 : public Etat
{
	public:
		E37() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E38 : public Etat
{
	public:
		E38() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};
class E39 : public Etat
{
	public:
		E39() : Etat(){}
		virtual void transition(Automate & automate, Symbole *s);
};

#endif
