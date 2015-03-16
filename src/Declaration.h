#if !defined ( DECLARATION_H )
#define DECLARATION_H
#include "Symbole.h"


class Declaration : public Symbole {

public:
	Declaration();
	Declaration(int id);
	virtual ~Declaration(){}

};


#endif