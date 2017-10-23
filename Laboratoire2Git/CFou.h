#ifndef CFOU_H
#define CFOU_H

#include "CPiece.h"


class CPlateau;

/**
  * Cette classe définit les fous, qui ne font que des déplacement en diagonal.
  */
class CFou : public CPiece
{
public:
/**
  * Constructeur standard.
  */
	CFou (CPlateau* J, int PX, int PY, int Coul);

/**
  * Dessine un Carre de la bonne taille et y mets le bon caractère pour la pièce,
  * de la bonne couleur.
  */
	void Afficher();


/**
  * Il y a ici une validation spécifique pour ne permettre que les mouvements diagonaux.
  * incX Déplacment demandé en X.
  * incY Déplacement demandé en Y.
  * retourne Vrai si le déplacement a eu lieu correctement, faux sinon.
  */
	bool Bouger (int incX, int incY);

	/********************************
	/**  modification (DEBUT)*/
	std::string type_piece() const override;
	bool deplacable(int x, int y) const override;
	/**  modification (FIN)
	/********************************/
};

#endif