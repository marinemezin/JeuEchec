#ifndef CTOUR_H
#define CTOUR_H


#include "CPiece.h"

class CPlateau;


/**
  * Cette classe définit les tours, qui ne font que des déplacement en ligne droite.
  * @see ca.uqac.ex4.Echec
  */
class CTour : public CPiece
{
public:
/**
  * Constructeur standard.
  */
	CTour (CPlateau* J, int PX, int PY, int Coul);

/**
  * Dessine un Carre de la bonne taille et y mets le bon caractère pour la pièce,
  * de la bonne couleur. 
  */
	void Afficher();

/**
  * Il y a ici une validation spécifique pour ne permettre que les mouvements droits.
  * incX Déplacment demandé en X.
  * incY Déplacement demandé en Y.
  * retourne Vrai si le déplacement a eu lieu correctement, faux sinon.
  */
	bool Bouger (int incX, int incY);

	/********************************
	/**  modification (DEBUT)*/
	std::string type_piece() const override;
	/**  modification (FIN)
	/********************************/
};

#endif

