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
  * Cette classe est parente de toutes les pi�ces.  Elle g�re les d�placements
  * de m�me que l'affichage de la grille
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
	int			PosX, PosY;		// On peut en mettre deux par lignes (d�conseill�)
	
	int abs(int val) {	return (val > 0 ? val : -val);	}

public:
/**
  * Constructeur complet d'une Pi�ce.
  * J C'est le plateau de jeu sur lequel la CPiece est pos�.
  * V C'est la valeur de la pi�ce ( 0 : case vide )
  * CB C'est la couleur de la pi�ce ( 1: Blanc, -1:Noir )
  * PX C'est la position en abscisse dans le tableau.
  * PY C'est le position en ordonn�e dans le tableau.
  */
	CPiece (CPlateau* J, int PX, int PY, int V = 0, int CB = 0);

/**
  * C'est la m�thode qui permet de bouger une piece de (incX, incY), si le chemin
  * est libre.
  * incX Valeur de l'incr�mentation horizontal.
  * incY Valeur de l'incr�mentation vertical.
  */
	virtual bool Bouger(int incX, int incY);


/**
  * Change la couleur du curseur pour mettre celle de la case de fond et 
  * de la pi�ce.
  */
	void setCouleur ();


/**
  * Dessine un carre de LargeurCase par HauteurCase de la couleur voulu, 
  * � la bonne position � l'�cran.
  */

	void dessineCase();


/**	
  *	Fonction de v�rification qui v�rifie si une case est vide, sans pi�ce.
  * retourne Vrai si la case est vide, faux sinon. 
  */
	bool isCaseVide()	{ return (Valeur ==0);		}


/**
  * Encapsulateur de l'attribut IsCoulBlanc.
  * retourne La couleur de la pi�ce (1 si blanc, -1 si noir, 0 si vide)
  */
	int isCoulBlanc()	{	return IsCoulBlanc;		}


/**
  * Toutes les pi�ces doivent pouvoir s'afficher, on ne sait pas cependant 
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

