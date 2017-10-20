#ifndef CROI_H
#define CROI_H

#include "CReine.h"


class CPlateau;

/**
  * Cette classe d�finit les rois, mais seulement les d�placements de base.
  */
class CRoi : public CReine
{
public:
	CRoi (CPlateau* J, int Coul);

/**
  * Dessine un Carre de la bonne taille et y mets le bon caract�re pour la pi�ce,
  * de la bonne couleur.
  */
  	void Afficher();

/**
  * Il y a ici une validation sp�cifique pour ne permettre que les mouvements de 1 case..
  * incX D�placment demand� en X.
  * incY D�placement demand� en Y.
  * retourne Vrai si le d�placement a eu lieu correctement, faux sinon.
  */
	bool Bouger (int incX, int incY);
};

#endif
