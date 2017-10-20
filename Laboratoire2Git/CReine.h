#ifndef CREINE_H
#define CREINE_H

#include "CPiece.h"

class CPlateau;


/**
  * Cette classe permet d'implanter une Reine dans un jeu d'�chec.
  */
class CReine : public CPiece
{
protected:
	CReine (CPlateau* J, int PX, int PY, int Force, int Coul);

public:
	CReine (CPlateau* J, int Coul);

/**
  * Dessine un Carre de la bonne taille et y mets le bon caract�re pour la pi�ce,
  * de la bonne couleur.
  */
	void Afficher();

/**
  * Il y a ici une validation sp�cifique pour ne permettre que les mouvements
  * droits et diagonaux.
  * incX D�placment demand� en X.
  * incY D�placement demand� en Y.
  * retourne Vrai si le d�placement a eu lieu correctement, faux sinon.
  */
	bool Bouger (int incX, int incY);

	/********************************
	/**  modification (DEBUT)*/
	std::string type_piece();
	/**  modification (FIN)
	/********************************/
};

#endif





