#ifndef CPLATEAU_H
#define CPLATEAU_H


#include "CPiece.h"

/**
  * Cette classe permet de construire, afficher en console et valider certains
  * déplacement dans un jeu d'échec.
  */
class CPlateau
{
private:
	const static int T = 8;

	CPiece*** Jeu;
	bool isIn(int val);
public:
/**
  * Constructeur qui fait un jeu de taille et de disposition standard.
  */
	CPlateau();

	/********************************
	/**  modification (DEBUT)*/
	CPlateau(CPlateau const& P); //constructeur par copie
	/**  modification (FIN)
	/********************************/

	~CPlateau();

/**
  * Affiche le jeu au complet en utilisant le polymorphisme des pièces.
  */
	void Afficher();

/**
  * Encapsuleur du tableau de CPiece.
  */
	CPiece* Case(int y, int x);

	
/**
  * Utilise le polymorphisme pour Appeler jouer sur le bon objet.
  * retourne Vrai si le coup est valide, faux sinon.
  * IniX Valeur initiale en X.
  * IniY Valeur initiale en Y.
  * finX Valeur finale en Y.
  * finX Valeur finale en Y
  */  
  	bool Bouger (int iniX, int iniY, int finX, int finY);

/** Encapsulateur qui permet de mettre des pièces ou l'on veux dans le jeu.
  * X Posision en X.
  * Y Position en Y.
  * P La pièce à ajouter.
  */
	void prendrePiece(int X, int Y);

	void deposerPiece(int X, int Y, CPiece* P);
};

#endif