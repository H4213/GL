
#if ! defined ( COMMAND_H_ )
#define COMMAND_H_

#include <cstdlib>
#include <map>
#include <string>
#include <sstream>

using namespace std;

//------------------------------------------------------------------------
// Cette classe permet de parser les commandes d'entree main et de les
//  organiser sous forme [-option] [argument] (ex : -g nomfichier)
//	mais aussi de gerer les cas ou l'argument n'a pas d'options specifiees
//  (ex: -x)
//------------------------------------------------------------------------

class Command
{

public:

	/**
	 *\brief verifie si l'option passee en parametre existe dans la commande
	 *\param chaine_de_caracteres (ex -g -l ...)
	 *\return existence (vrai si existe faux sinon)
	 */
	bool OptionExists ( string );
	/**
	 *\brief renvoie la valeur de l'option precisee
	 *\param chaine_de_caracteres (ex -g -l ...)
	 *\return argument d'une option type -X
	 */
	string getArgument ( string );
	/**
	 *\brief renvoie la valeur de l'option precisee convertie sans verification
	 *\param chaine_de_caracteres (ex -g -l ...)
	 *\return entier
	 */
	int getArgumentAsNumber ( string );
	/**
	 *\brief renvoie le nombre d'option (type -x)
	 *\return nombre d'options passees
	 */
	int OptionCount ( );
	/**
	 *\brief renvoie le nombre d'arguments non precede par une option
	 *      (ex: nom de fichier source)
	 *\return nombre d'options passees
	 */
	int StringCount ( );
	/**
	 *\brief Separe l'option de l'argument associe
	 *\brief l'argument s'ajoute en derniere position dans la listes
	 *      des arguments
	 *\brief voir getLastString() pour recuperer ou getArgument("s#")
	 *      ou # le dernier argument sans option
	 *\brief l'option separee aura un arguement ""
	 *\param option a separer de son argument
	 */
	void SetNoArgFor ( string );
	/**
	 *\brief renvoie le dernier argument sans option
	 *      (cf. doc pour les autres arguments)
	 *\return chaine de caracteres
	 */
	string getLastString ( );
	/**
	 *\brief constructeur (force avec des parametres)
	 *\param nombre de parametres
	 *\param adresse du tableau de parametres (argv[0] ignore)
	 *\code
	 Command com(argc, argv);
	 *\endcode
	 */
	Command ( int, char** );

	map<string,string>::iterator getOptionsBegin();
    map<string,string>::iterator getOptionsEnd();
	virtual ~Command ( );


protected:

	map<string, string> params; // cle : l'option si passee en argument,
								// valeur : l'argument de l'option
	int n_options; //nombre d'options
	int n_strings; //nombre d'options sans parametres
};


#endif // COMMAND_H_
