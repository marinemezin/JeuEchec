#include "CReine.h"
/********************************
/**  modification (DEBUT)*/
#include <time.h>
/**  modification (FIN)
/********************************/
#include <iostream>
using namespace std;


CReine::CReine (CPlateau* J,  int PX, int PY, int Force, int Coul) 
			: CPiece(J, PX, PY, Force, Coul)
{
	// rien
}


CReine::CReine (CPlateau* J,  int Coul) 
: CPiece(J, 3, (Coul == 1 ? 0 : 7), 8, Coul)
{
	// rien
}



void CReine::Afficher()
{
	setCouleur();
	dessineCase();
	cout << ("D");
}


bool CReine::Bouger (int incX, int incY)
{
	if (abs(incX) == abs (incY) || incY == 0 || incX == 0)
		return CPiece::Bouger(incX, incY);
	else
		return false;
}


/********************************
/**  modification (DEBUT)*/
std::string CReine::type_piece() const
{
	return "CReine";
}


bool CReine::deplacable(int x, int y) const
{
	return CPiece::deplacable(x, y);
}


void CReine::coordonneesIA(int tab[]) const
{
	int choix = rand() % 4;
	if (choix == 0) { //déplacement en ligne
		tab[0] = (rand() % 15) - 7;
		tab[1] = 0;
	}
	if (choix == 1) { //déplacement en colonne
		tab[0] = 0;
		tab[1] = (rand() % 15) - 7;
	}
	if (choix == 2 || choix == 3) { //déplacements diago
		tab[0] = (rand() % 15) - 7;
		if (choix == 2) {
			tab[1] = tab[0] * (-1);
		}
		if (choix == 3) {
			tab[1] = tab[0];
		}
	}
}
/**  modification (FIN)
/********************************/

