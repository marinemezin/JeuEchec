#include "CCavalier.h"


#include <iostream>
using namespace std;

#include "CPlateau.h"
#include "CCaseVide.h"


CCavalier::CCavalier (CPlateau* J, int PX, int PY, int Coul) : 
			CPiece(J, PX, PY, 3, Coul)
{

}


void CCavalier::Afficher()
{
	setCouleur();
	dessineCase();
	cout << ("C");
}


bool CCavalier::Bouger (int incX, int incY)
{
	if (abs(incX) + abs(incY) == 3 && incX != 0 && incY !=0 &&
		Jeu->Case(PosY+incY, PosX+incX)->isCoulBlanc() != IsCoulBlanc && 
		PosX + incX >= 0 && PosX + incX < 8 && 
		PosY + incY >= 0 && PosY + incY < 8)
	{
		Jeu->prendrePiece(PosX, PosY);

		PosX = PosX + incX;
		PosY = PosY + incY;

		Jeu->deposerPiece(PosX, PosY, this);
		return true;
	}
	else
		return false;
}

/********************************
/**  modification (DEBUT)*/

std::string CCavalier::type_piece() const
{
	return "CCavalier";
}
bool CCavalier::deplacable(int x, int y) const
{
	//Vérification des 8 cases possibles
	bool possible = false;
	if ((y - 2) >= 0 && (y - 2) <= 7) {
		if ((x - 1) >= 0 && (x - 1) <= 7) {
			if (Jeu->Case(y - 2, x - 1)->isCaseVide()) { possible = true; }
		}
		if ((x + 1) >= 0 && (x + 1) <= 7) {
			if (Jeu->Case(y - 2, x + 1)->isCaseVide()) { possible = true; }
		}
	}
	if ((y - 1) >= 0 && (y - 1) <= 7) {
		if ((x - 2) >= 0 && (x - 2) <= 7) {
			if (Jeu->Case(y - 1, x - 2)->isCaseVide()) { possible = true; }
		}
		if ((x + 2) >= 0 && (x + 2) <= 7) {
			if (Jeu->Case(y - 1, x + 2)->isCaseVide()) { possible = true; }
		}
	}
	if ((y + 1) >= 0 && (y + 1) <= 7)
	{
		if ((x - 2) >= 0 && (x - 2) <= 7) {
			if (Jeu->Case(y + 1, x - 2)->isCaseVide()) { possible = true; }
		}
		if ((x + 2) >= 0 && (x + 2) <= 7) {
			if (Jeu->Case(y + 1, x + 2)->isCaseVide()) { possible = true; }
		}
	}
	if ((y + 2) >= 0 && (y + 2) <= 7)
	{
		if ((x - 1) >= 0 && (x - 1) <= 7) {
			if (Jeu->Case(y + 2, x - 1)->isCaseVide()) { possible = true; }
		}
		if ((x + 1) >= 0 && (x + 1) <= 7) {
			if (Jeu->Case(y + 2, x + 1)->isCaseVide()) { possible = true; }
		}
	}
	return possible;
}
/**  modification (FIN)
/********************************/
