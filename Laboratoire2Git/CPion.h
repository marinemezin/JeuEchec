#ifndef CCPION_H
#define CCPION_H

#include "CPiece.h"
#include "CPlateau.h"


/**
  * Cette classe permet d'implanter des pions au échec.
  */
class CPion : public CPiece
{
	/********************************
	/**  modification (DEBUT)*/
private :
	bool premierTour;
	bool viensDavancer2Cases;
	int tour; //pour compter le nommbre de tour passé depuis son premier tour
	/**  modification (FIN)
	/********************************/
public:
/**
  * Constructeur standard.
  */
	CPion(CPlateau* J, int PX, int PY, int Coul);

/**
  * Il y a ici une validation spécifique pour ne permettre que les mouvement d'avant
  * ou en diagonal pour une prise, et cela d'une seule case.
  * incX Déplacment demandé en X.
  * incY Déplacement demandé en Y.
  * retourne Vrai si le déplacement a eu lieu correctement, faux sinon.
  */
	bool Bouger(int incX, int incY);

/**
  * Dessine un Carre de la bonne taille et y mets le bon caractère pour la pièce,
  * de la bonne couleur.
  */
	void Afficher();

	/********************************
	/**  modification (DEBUT)*/
	bool priseEnPassant() override;
	std::string type_piece() const override;
	void modifPriseEnPassant() override;
	bool deplacable(int x, int y) const override;
	void coordonneesIA(int tab[]) const override;
	/**  modification (FIN)
	/********************************/
};

#endif


