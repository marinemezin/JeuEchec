#include "CTour.h"


#include <iostream>
using namespace std;


CTour::CTour(CPlateau* J, int PX, int PY, int Coul) : CPiece(J, PX, PY, 5, Coul)
{
	// rien
}


void CTour::Afficher()
{
	setCouleur();
	dessineCase();
	cout << ("T");
}


bool CTour::Bouger (int incX, int incY)
{
	if ((incY == 0 || incX  == 0))
		return CPiece::Bouger(incX, incY);
	else
		return false;
}

/********************************
/**  modification (DEBUT)*/
std::string CTour::type_piece()
{
	return "CTour";
}
/**  modification (FIN)
/********************************/