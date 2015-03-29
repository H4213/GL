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
	void OptionDefault();
	bool analyseStatique(Programme* Pr);
<<<<<<< HEAD
	Programme* transformation(Programme* Pr);
=======

>>>>>>> 4aa819774a29fb5904fe174a28a4159dde08ba49
private:
	Command _command;
	Automate _automate;
	Programme *_programme;

};

#endif
