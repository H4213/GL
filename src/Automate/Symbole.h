#ifndef SYMBOLE_H
#define SYMBOLE_H

class Symbole
{
	protected: 
		int _ident;
	public: 
		Symbole(int id): _ident(id)
		{}
		virtual ~Symbole(){}
		void print();
		operator int() const {return _ident;}
};

#endif
