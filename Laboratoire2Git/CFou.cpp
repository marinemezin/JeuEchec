#include "CFou.h"

/********************************
/**  modification (DEBUT)*/
#include "CPlateau.h"
/**  modification (FIN)
/********************************/
#include <iostream>
using namespace std;


CFou::CFou (CPlateau* J, int PX, int PY, int Coul) : CPiece(J, PX, PY, 3, Coul)
{
}




void CFou::Afficher()
{
	setCouleur();
	dessineCase();
	cout << ("F");
}


bool CFou::Bouger (int incX, int incY)
{
	if (abs(incX) == abs (incY))
		return CPiece::Bouger(incX, incY);
	else
		return false;
}

/********************************
/**  modification (DEBUT)*/

std::string CFou::type_piece() const{
	return "CFou";
}

bool CFou::deplacable(int x, int y) const {
	//Les cases diago sont vérifiées
	bool possible = false;
	if ((y - 1) >= 0 && (y - 1) <= 7){
		if ((x - 1) >= 0 && (x - 1) <= 7) {
			if (Jeu->Case(y - 1, x - 1)->isCaseVide()) { possible = true; }
		}
		if ((x + 1) >= 0 && (x + 1) <= 7) {
			if (Jeu->Case(y - 1, x + 1)->isCaseVide()) { possible = true; }
		}
	}
	if ((y + 1) >= 0 && (y + 1) <= 7){
		if ((x - 1) >= 0 && (x - 1) <= 7) {
			if (Jeu->Case(y + 1, x - 1)->isCaseVide()) { possible = true; }
		}
		if ((x + 1) >= 0 && (x + 1) <= 7) {
			if (Jeu->Case(y + 1, x + 1)->isCaseVide()) { possible = true; }
		}
	}
	return possible;
}
/**  modification (FIN)
/********************************/

