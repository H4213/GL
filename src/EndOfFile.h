#if !defined ( ENDOFILE_H )
#define ENDOFILE_H
#include "Symbole.h"


class EndOfFile : public Symbole {

public:
	EndOfFile();
	virtual ~EndOfFile(){}
	
	virtual void executer(map<string,double> &mapV){}

};


#endif 
