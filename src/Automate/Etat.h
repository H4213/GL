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
		virtual ~Etat(){_name = "E0";}
		virtual void transition(Automate & automate, Symbole *s) = 0;

	protected:
	string _name;
};

class E0 : public Etat
{
	public:
		E0() : Etat(){_name = "E1";}
		virtual void transition(Automate & automate, Symbole *s);
};

class E1 : public Etat
{
	public:
		E1() : Etat(){_name = "E2";}
		virtual void transition(Automate & automate, Symbole *s);
};

class E2 : public Etat
{
	public:
		E2() : Etat(){_name = "E3";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E3 : public Etat
{
	public:
		E3() : Etat(){_name = "E4";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E4 : public Etat
{
	public:
		E4() : Etat(){_name = "E5";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E5 : public Etat
{
	public:
		E5() : Etat(){_name = "E6";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E6 : public Etat
{
	public:
		E6() : Etat(){_name = "E7";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E7 : public Etat
{
	public:
		E7() : Etat(){_name = "E8";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E8 : public Etat
{
	public:
		E8() : Etat(){_name = "E9";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E9 : public Etat
{
	public:
		E9() : Etat(){_name = "E10";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E10 : public Etat
{
	public:
		E10() : Etat(){_name = "E11";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E11 : public Etat
{
	public:
		E11() : Etat(){_name = "E12";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E12 : public Etat
{
	public:
		E12() : Etat(){_name = "E13";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E13 : public Etat
{
	public:
		E13() : Etat(){_name = "E14";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E14 : public Etat
{
	public:
		E14() : Etat(){_name = "E15";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E15 : public Etat
{
	public:
		E15() : Etat(){_name = "E16";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E16 : public Etat
{
	public:
		E16() : Etat(){_name = "E17";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E17 : public Etat
{
	public:
		E17() : Etat(){_name = "E18";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E18 : public Etat
{
	public:
		E18() : Etat(){_name = "E19";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E19 : public Etat
{
	public:
		E19() : Etat(){_name = "E20";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E20 : public Etat
{
	public:
		E20() : Etat(){_name = "E21";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E21 : public Etat
{
	public:
		E21() : Etat(){_name = "E22";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E22 : public Etat
{
	public:
		E22() : Etat(){_name = "E23";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E23 : public Etat
{
	public:
		E23() : Etat(){_name = "E24";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E24 : public Etat
{
	public:
		E24() : Etat(){_name = "E25";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E25 : public Etat
{
	public:
		E25() : Etat(){_name = "E26";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E26 : public Etat
{
	public:
		E26() : Etat(){_name = "E27";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E27 : public Etat
{
	public:
		E27() : Etat(){_name = "E28";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E28 : public Etat
{
	public:
		E28() : Etat(){_name = "E29";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E29 : public Etat
{
	public:
		E29() : Etat(){_name = "E30";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E30 : public Etat
{
	public:
		E30() : Etat(){_name = "E31";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E31 : public Etat
{
	public:
		E31() : Etat(){_name = "E32";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E32 : public Etat
{
	public:
		E32() : Etat(){_name = "E33";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E33 : public Etat
{
	public:
		E33() : Etat(){_name = "E34";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E34 : public Etat
{
	public:
		E34() : Etat(){_name = "E35";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E35 : public Etat
{
	public:
		E35() : Etat(){_name = "E36";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E36 : public Etat
{
	public:
		E36() : Etat(){_name = "E37";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E37 : public Etat
{
	public:
		E37() : Etat(){_name = "E38";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E38 : public Etat
{
	public:
		E38() : Etat(){_name = "E39";}
		virtual void transition(Automate & automate, Symbole *s);
};
class E39 : public Etat
{
	public:
		E39() : Etat(){_name = "E40";}
		virtual void transition(Automate & automate, Symbole *s);
};

#endif
