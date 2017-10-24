#include "CCavalier.h"

/********************************
/**  modification (DEBUT)*/
#include <time.h>
/**  modification (FIN)
/********************************/

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

std::string CCavalier::type_piece() const{
	return "CCavalier";
}

bool CCavalier::testPourDeplacable(int leY, int leX) const
{
	bool retour = false;
	if (leY >= 0 && leY <= 7) {
		if (leX >= 0 && leX <= 7) {
			if (Jeu->Case(leY, leX)->isCaseVide()) {
				retour = true;
			}
		}
	}
	return retour;
}

bool CCavalier::deplacable(int x, int y) const{
	bool possible = false;
	if (!possible) { possible = testPourDeplacable(y - 2, x - 1); }
	if (!possible) { possible = testPourDeplacable(y - 2, x + 1); }
	if (!possible) { possible = testPourDeplacable(y - 1, x - 2); }
	if (!possible) { possible = testPourDeplacable(y - 1, x + 2); }
	if (!possible) { possible = testPourDeplacable(y + 1, x - 2); }
	if (!possible) { possible = testPourDeplacable(y + 1, x + 2); }
	if (!possible) { possible = testPourDeplacable(y + 2, x - 1); }
	if (!possible) { possible = testPourDeplacable(y + 2, x + 1); }
	return possible;
}
void CCavalier::coordonneesIA(int tab[]) const
{
	int choix = rand() % 4;
	if ((choix == 0) || (choix == 1)) {
		if (choix == 0)	{ tab[0] = 1; }
		if (choix == 1)	{ tab[0] = -1; }
		choix = rand() % 2;
		if (choix == 0) { tab[1] = -2; }
		if (choix == 1) { tab[1] = 2; }
	}
	if ((choix == 2) || (choix == 3)) {
		if (choix == 2) { tab[0] = 2; }
		if (choix == 3) { tab[0] = -2; }
		choix = rand() % 2;
		if (choix == 0) { tab[1] = -1; }
		if (choix == 1) { tab[1] = 1; }
	}
}
/**  modification (FIN)
/********************************/
