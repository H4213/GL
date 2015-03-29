#ifndef LUTIN_H
#define LUTIN_H

#include "Command.h"
#include "Automate.h"

//------------------------------------------------------------------------
//Cette classe permet faire le lien entre les commandes utilisateur
//et l'automate
//------------------------------------------------------------------------

class Lutin
{


public:
	Lutin ( int argc, char **argv );
	virtual ~Lutin ( );

	void ShowHelp();
	void OptionP();
	void OptionA();
	void OptionE();
	void OptionO();
	Programme* OptionDefault();

private:
	Command _command;
	Automate _automate;

};

#endif 