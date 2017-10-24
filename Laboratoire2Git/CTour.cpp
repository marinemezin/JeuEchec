#include "CTour.h"
/********************************
/**  modification (DEBUT)*/
#include "CPlateau.h"
#include <time.h>
/**  modification (FIN)
/********************************/

#include <iostream>
using namespace std;


CTour::CTour(CPlateau* J, int PX, int PY, int Coul) : CPiece(J, PX, PY, 5, Coul)
{
	/********************************
	/**  modification (DEBUT)*/
	aBouger = false;
	/**  modification (FIN)
	/********************************/
}


void CTour::Afficher()
{
	setCouleur();
	dessineCase();
	cout << ("T");
}


bool CTour::Bouger (int incX, int incY)
{
	/********************************
	/**  modification (DEBUT)*/
	if ((incY == 0 || incX == 0))
	{
		if (CPiece::Bouger(incX, incY)) {
			aBouger = true;
			return true;
		}
	}
	/**  modification (FIN)
	/********************************/
	else
		return false;
}

/********************************
/**  modification (DEBUT)*/
std::string CTour::type_piece() const
{
	return "CTour";
}
bool CTour::getABouger() const
{
	return aBouger;
}
bool CTour::deplacable(int x, int y) const
{
	//On observe les 4 cases (non diago) autour de la tour
	bool possible = false;
	if((x - 1) >= 0 && (x - 1) <= 7) {
		if (Jeu->Case(y, x - 1)->isCaseVide()) {
			possible = true;
		}
	}
	if ((x + 1) >= 0 && (x + 1) <= 7) {
		if (Jeu->Case(y, x + 1)->isCaseVide()) {
			possible = true;
		}
	}
	if ((y - 1) >= 0 && (y - 1) <= 7) {
		if (Jeu->Case(y - 1, x)->isCaseVide()) {
			possible = true;
		}
	}
	if ((y + 1) >= 0 && (y + 1) <= 7) {
		if (Jeu->Case(y + 1, x)->isCaseVide()) {
			possible = true;
		}
	}
	return possible;
}
void CTour::coordonneesIA(int tab[]) const
{
	int choix = rand() % 2;
	if (choix == 0) { //déplacement en ligne
		tab[0] = (rand() % 15) - 7;
		tab[1] = 0;
	}
	if (choix == 1) { //déplacement en colonne
		tab[0] = 0;
		tab[1] = (rand() % 15) - 7;
	}
}
/**  modification (FIN)
/********************************/