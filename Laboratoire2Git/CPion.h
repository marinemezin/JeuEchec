#ifndef CCPION_H
#define CCPION_H

#include "CPiece.h"
#include "CPlateau.h"


/**
  * Cette classe permet d'implanter des pions au �chec.
  */
class CPion : public CPiece
{
	/********************************
	/**  modification (DEBUT)*/
private :
	bool premierTour;
	bool viensDavancer2Cases;
	int tour; //pour compter le nommbre de tour pass� depuis son premier tour
	/**  modification (FIN)
	/********************************/
public:
/**
  * Constructeur standard.
  */
	CPion(CPlateau* J, int PX, int PY, int Coul);

/**
  * Il y a ici une validation sp�cifique pour ne permettre que les mouvement d'avant
  * ou en diagonal pour une prise, et cela d'une seule case.
  * incX D�placment demand� en X.
  * incY D�placement demand� en Y.
  * retourne Vrai si le d�placement a eu lieu correctement, faux sinon.
  */
	bool Bouger(int incX, int incY);

/**
  * Dessine un Carre de la bonne taille et y mets le bon caract�re pour la pi�ce,
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


