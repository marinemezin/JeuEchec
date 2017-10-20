#ifndef CCASEVIDE_H
#define CCASEVIDE_H

#include "CPiece.h"


class CPlateau;

/**
  * Cette classe permet représenter dans le jeu une case vide.
  */
class CCaseVide : public CPiece
{
public:
/**
  * Constructeur par défaut.
  */
	CCaseVide(CPlateau* J, int PX, int PY);

/**
  * La méthode Bouger de CPiece est ici redéfinie pour interdire de bouger 
  * une case vide.
  * retourne Toujours faux.
  */
	bool Bouger (int Bid1, int Bid2);
	
/**
  * Affiche le Carre et un espace, juste pour la forme.
  */
	void Afficher();

	/********************************
	/**  modification (DEBUT)*/
	std::string type_piece() const override;
	/**  modification (FIN)
	/********************************/

};

#endif
