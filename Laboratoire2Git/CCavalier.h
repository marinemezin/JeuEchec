#ifndef CCAVALIER_H
#define CCAVALIER_H

#include "CPiece.h"


class CPlateau;

/**
  * Cette classe d�finit les tours, qui ne font que des d�placement en L.
  */
class CCavalier : public CPiece
{
public:
/**
  * Constructeur standard.
  */
	CCavalier (CPlateau* J, int PX, int PY, int Coul);

/**
  * Dessine un Carre de la bonne taille et y mets le bon caract�re pour la pi�ce,
  * de la bonne couleur.
  */
	void Afficher();

/**
  * Il y a ici une validation sp�cifique pour ne permettre que les mouvements en L.
  * incX D�placment demand� en X.
  * incY D�placement demand� en Y.
  * retourne vrai si le d�placement a eu lieu correctement, faux sinon.
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
