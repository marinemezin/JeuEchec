#ifndef CPIECE_H
#define CPIECE_H

#include "CCoul.h"
/********************************
/**  modification (DEBUT)*/
#include <string>
/**  modification (FIN)
/********************************/

class CPlateau;

/*
  * Cette classe est parente de toutes les pièces.  Elle gère les déplacements
  * de même que l'affichage de la grille
  */

class CPiece : public  CCoul
{
private:
	const static int LargeurCase = 7;
	const static int HauteurCase = 3;

	int		Valeur;
	bool	CheminVide (int incX, int incY);

protected:
    CPlateau*	Jeu;
	int			IsCoulBlanc;
	int			PosX, PosY;		// On peut en mettre deux par lignes (déconseillé)
	
	int abs(int val) {	return (val > 0 ? val : -val);	}

public:
/**
  * Constructeur complet d'une Pièce.
  * J C'est le plateau de jeu sur lequel la CPiece est posé.
  * V C'est la valeur de la pièce ( 0 : case vide )
  * CB C'est la couleur de la pièce ( 1: Blanc, -1:Noir )
  * PX C'est la position en abscisse dans le tableau.
  * PY C'est le position en ordonnée dans le tableau.
  */
	CPiece (CPlateau* J, int PX, int PY, int V = 0, int CB = 0);

/**
  * C'est la méthode qui permet de bouger une piece de (incX, incY), si le chemin
  * est libre.
  * incX Valeur de l'incrémentation horizontal.
  * incY Valeur de l'incrémentation vertical.
  */
	virtual bool Bouger(int incX, int incY);


/**
  * Change la couleur du curseur pour mettre celle de la case de fond et 
  * de la pièce.
  */
	void setCouleur ();


/**
  * Dessine un carre de LargeurCase par HauteurCase de la couleur voulu, 
  * à la bonne position à l'écran.
  */

	void dessineCase();


/**	
  *	Fonction de vérification qui vérifie si une case est vide, sans pièce.
  * retourne Vrai si la case est vide, faux sinon. 
  */
	bool isCaseVide()	{ return (Valeur ==0);		}


/**
  * Encapsulateur de l'attribut IsCoulBlanc.
  * retourne La couleur de la pièce (1 si blanc, -1 si noir, 0 si vide)
  */
	int isCoulBlanc()	{	return IsCoulBlanc;		}


/**
  * Toutes les pièces doivent pouvoir s'afficher, on ne sait pas cependant 
  * encore comment.
  */
	virtual void Afficher() = 0;


	/********************************
	/**  modification (DEBUT)*/
	virtual bool priseEnPassant();
	virtual bool Manger(int incX, int incY);
	virtual std::string type_piece() const;
	virtual void modifPriseEnPassant() { /*rien*/ };
	/**  modification (FIN)
	/********************************/
};

#endif

