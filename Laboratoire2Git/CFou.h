#ifndef CFOU_H
#define CFOU_H

#include "CPiece.h"


class CPlateau;

/**
  * Cette classe d�finit les fous, qui ne font que des d�placement en diagonal.
  */
class CFou : public CPiece
{
public:
/**
  * Constructeur standard.
  */
	CFou (CPlateau* J, int PX, int PY, int Coul);

/**
  * Dessine un Carre de la bonne taille et y mets le bon caract�re pour la pi�ce,
  * de la bonne couleur.
  */
	void Afficher();


/**
  * Il y a ici une validation sp�cifique pour ne permettre que les mouvements diagonaux.
  * incX D�placment demand� en X.
  * incY D�placement demand� en Y.
  * retourne Vrai si le d�placement a eu lieu correctement, faux sinon.
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