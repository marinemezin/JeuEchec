#include "CPlateau.h"


#include <iostream>
using namespace std;


#include "CPiece.h"
#include "CCaseVide.h"
#include "CPion.h"
#include "CFou.h"
#include "CCavalier.h"
#include "CTour.h"
#include "CReine.h"
#include "CRoi.h"

#include "CEcran.h"


CPlateau::CPlateau()
{
	Jeu = new CPiece**[T];
	for (int z = 0; z < T; z++)
		Jeu[z] = new CPiece*[T];

	for (int y = 2; y < T - 2; y++)					//Les cases du centre
		for (int x = 0; x < T; x++)
			Jeu[y][x] = new CCaseVide (this, x, y);
			
	for (int x=0; x<T; x++)						//Les pions
	{	
		Jeu[1][x] = new CPion (this, x, 1, 1);
		Jeu[6][x] = new CPion (this, x, 6, -1);
	}
	for (int x=2; x<T; x +=3)					//Les deux Fous
	{
		Jeu[0][x] = new CFou (this, x, 0, 1);
		Jeu[7][x] = new CFou (this, x, 7, -1);
	}
	
	for (int x=1; x<T; x +=5)					//Les deux Cavaliers
	{
		Jeu[0][x] = new CCavalier (this, x, 0, 1); 
		Jeu[7][x] = new CCavalier (this, x, 7, -1);
	}

	for (int x=0; x<T; x+=7)					//Les deux tours
	{	
		Jeu[0][x] = new CTour (this, x, 0, 1);
		Jeu[7][x] = new CTour (this, x, 7, -1);
	}
	Jeu[0][3] = new CReine (this, 1);			//Reine Blanche
	Jeu[7][3] = new CReine (this, -1);			//Reine Noire

	Jeu[0][4] = new CRoi (this, 1);				//Roi Blanc
	Jeu[7][4] = new CRoi (this, -1);			//Roi Noir
}

/********************************
/**  modification (DEBUT)*/
void CPlateau::verifPriseEnPassant(CPlateau &plateau) {
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++)	{
			plateau.Jeu[i][j]->modifPriseEnPassant();
		}
	}
}

CPlateau::CPlateau(CPlateau const& plateau) {
	Jeu = new CPiece**[T];
	for (int z = 0; z < T; z++) { Jeu[z] = new CPiece*[T]; }
	for (int y = 0; y < T; y++){
		for (int x = 0; x < T; x++){
			if (plateau.Case(y, x)->type_piece() == "CPion") {
				Jeu[y][x] = new CPion(this, x, y, plateau.Case(y, x)->isCoulBlanc());
			}
			if (plateau.Case(y, x)->type_piece() == "CReine"){
				Jeu[y][x] = new CReine(this, x, y, 8, plateau.Case(y, x)->isCoulBlanc());
			}
			if (plateau.Case(y, x)->type_piece() == "CRoi"){
				Jeu[y][x] = new CRoi(this, x, y, 5, plateau.Case(y, x)->isCoulBlanc());
			}
			if (plateau.Case(y, x)->type_piece() == "CTour"){
				Jeu[y][x] = new CTour(this, x, y, plateau.Case(y, x)->isCoulBlanc());
			}
			if (plateau.Case(y, x)->type_piece() == "CCavalier"){
				Jeu[y][x] = new CCavalier(this, x, y, plateau.Case(y, x)->isCoulBlanc());
			}
			if (plateau.Case(y, x)->type_piece() == "CCasevide"){
				Jeu[y][x] = new CCaseVide(this, x, y);
			}
			if (plateau.Case(y, x)->type_piece() == "CFou"){
				Jeu[y][x] = new CFou(this, x, y, plateau.Case(y, x)->isCoulBlanc());
			}
		}
	}
}


/**  modification (FIN)
/********************************/

CPlateau::~CPlateau()
{
	for (int y = 0; y < T; y++)					// Les cases du centre
		for (int x = 0; x < T; x++)
			delete Jeu[y][x];

	for (int z = 0; z < T; z++)
		delete Jeu[z];

	delete Jeu;
}


void CPlateau::Afficher()
{
	for (int y=0; y<T; y++)
	{
		for (int x=0; x < T; x++)
			if (Jeu[y][x] != NULL)
				Jeu[y][x]->Afficher();
	}
	for (int Legende = 0; Legende < T; Legende++)
	{
		Jeu[0][Legende]->setCouleur();
		CEcran::Gotoxy (7 * Legende + 4,1);
		cout << (char)(Legende + 'a');

		Jeu[7][Legende]->setCouleur();
		CEcran::Gotoxy(7 * Legende + 4, 24);
		cout << (char)(Legende + 'a');

		Jeu[Legende][0]->setCouleur();
		CEcran::Gotoxy (1, Legende *3 + 2);
		cout << (char)(Legende + '1');
	}
	CEcran::Gotoxy (1,25);
}

/********************************
/**  modification (DEBUT)*/
CPiece* CPlateau::Case(int y, int x) const {
	return Jeu[y][x]; 
}


CPiece* CPlateau::CaseModif(int y, int x) {
	return Jeu[y][x];
}

/**  modification (FIN)
/********************************/



bool CPlateau::Bouger (int iniX, int iniY, int finX, int finY)
{
	if(!isIn(iniX) || !isIn(iniY) || !isIn(finX) || !isIn(finY)) return false;

	return  (Jeu[iniY][iniX]->Bouger(finX-iniX, finY-iniY));
}


bool CPlateau::isIn(int val)
{
	if( val < 0 || val >=T) return false;

	return true;
}


void CPlateau::prendrePiece(int X, int Y)
{
	// on efface pas Jeu[y][x], la pi�ce est prise (encore en jeu)
	Jeu[Y][X] = new CCaseVide(this, X, Y);
}


void CPlateau::deposerPiece(int X, int Y, CPiece* P)
{
	delete Jeu[Y][X];	// la piece (ou la case vide) n'est plus en jeu

	Jeu[Y][X] = P;
}
