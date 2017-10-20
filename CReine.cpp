#include "CReine.h"


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




