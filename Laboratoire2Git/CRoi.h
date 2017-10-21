#ifndef CROI_H
#define CROI_H

#include "CReine.h"


class CPlateau;

/**
  * Cette classe définit les rois, mais seulement les déplacements de base.
  */
class CRoi : public CReine
{
public:
	CRoi (CPlateau* J, int Coul);
	/********************************
	/**  modification (DEBUT)*/
	CRoi::CRoi(CPlateau* J, int PX, int PY, int Force, int Coul);
	/**  modification (FIN)

/**
  * Dessine un Carre de la bonne taille et y mets le bon caractère pour la pièce,
  * de la bonne couleur.
  */
  	void Afficher();

/**
  * Il y a ici une validation spécifique pour ne permettre que les mouvements de 1 case..
  * incX Déplacment demandé en X.
  * incY Déplacement demandé en Y.
  * retourne Vrai si le déplacement a eu lieu correctement, faux sinon.
  */
	bool Bouger (int incX, int incY);

	/********************************
	/**  modification (DEBUT)*/
	std::string type_piece() const override;
	bool echec(CPlateau &plateau, int posX, int posY);
	/**  modification (FIN)
	/********************************/
};

#endif

