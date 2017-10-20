#ifndef CREINE_H
#define CREINE_H

#include "CPiece.h"

class CPlateau;


/**
  * Cette classe permet d'implanter une Reine dans un jeu d'échec.
  */
class CReine : public CPiece
{
protected:
	CReine (CPlateau* J, int PX, int PY, int Force, int Coul);

public:
	CReine (CPlateau* J, int Coul);

/**
  * Dessine un Carre de la bonne taille et y mets le bon caractère pour la pièce,
  * de la bonne couleur.
  */
	void Afficher();

/**
  * Il y a ici une validation spécifique pour ne permettre que les mouvements
  * droits et diagonaux.
  * incX Déplacment demandé en X.
  * incY Déplacement demandé en Y.
  * retourne Vrai si le déplacement a eu lieu correctement, faux sinon.
  */
	bool Bouger (int incX, int incY);

	/********************************
	/**  modification (DEBUT)*/
	std::string type_piece();
	/**  modification (FIN)
	/********************************/
};

#endif





