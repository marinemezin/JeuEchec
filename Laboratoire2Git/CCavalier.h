#ifndef CCAVALIER_H
#define CCAVALIER_H

#include "CPiece.h"


class CPlateau;

/**
  * Cette classe définit les tours, qui ne font que des déplacement en L.
  */
class CCavalier : public CPiece
{
public:
/**
  * Constructeur standard.
  */
	CCavalier (CPlateau* J, int PX, int PY, int Coul);

/**
  * Dessine un Carre de la bonne taille et y mets le bon caractère pour la pièce,
  * de la bonne couleur.
  */
	void Afficher();

/**
  * Il y a ici une validation spécifique pour ne permettre que les mouvements en L.
  * incX Déplacment demandé en X.
  * incY Déplacement demandé en Y.
  * retourne vrai si le déplacement a eu lieu correctement, faux sinon.
  */
	bool Bouger (int incX, int incY);

	/********************************
	/**  modification (DEBUT)*/
	std::string type_piece() const override;
	bool deplacable(int x, int y) const override;
	void coordonneesIA(int tab[]) const override;
	/**  modification (FIN)
	/********************************/
};

#endif
