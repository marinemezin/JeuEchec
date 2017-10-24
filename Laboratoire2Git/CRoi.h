#ifndef CROI_H
#define CROI_H

#include "CReine.h"


class CPlateau;

/**
  * Cette classe d�finit les rois, mais seulement les d�placements de base.
  */
class CRoi : public CReine
{
	/********************************
	/**  modification (DEBUT)*/
	bool aRoque; //le joueur ne peut roquer qu'une fois par partie
	bool valideTourRoque(int ajustCase, int incY, int incX, int posXAttendue, int posYAttendue);
	bool valideRoiRoque(int PosX, int PosY, int posXAttendue, int posYAttendue);
	bool mouvementRoque(int incX, int incY, int xTour, int yTour, int positionXTour, int positionYTour);
	bool casesDeplacementNonEchec(int incX, int incY, int couleur);
	bool aBouger;
	bool casesEnEchec(int X, int Y, int couleur);
	/**  modification (FIN)
	/********************************/
public:
	CRoi (CPlateau* J, int Coul);
	/********************************
	/**  modification (DEBUT)*/
	CRoi::CRoi(CPlateau* J, int PX, int PY, int Force, int Coul);
	/**  modification (FIN)

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

	/********************************
	/**  modification (DEBUT)*/
	std::string type_piece() const override;
	bool deplacable(int x, int y) const override;
	/**  modification (FIN)
	/********************************/
};

#endif

