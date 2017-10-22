#include "CTour.h"


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
/**  modification (FIN)
/********************************/