#include "CRoi.h"


#include <iostream>
using namespace std;


CRoi::CRoi (CPlateau* J, int Coul) : 
		CReine(J, 4, (Coul == 1 ? 0 : 7), 5, Coul)
{
	// rien
}


void CRoi::Afficher()
{
	setCouleur();
	dessineCase();
	cout << ("R");
}


bool CRoi::Bouger (int incX, int incY)
{
	if (abs(incX) <= 1 && + abs(incY) <= 1 )
		return CPiece::Bouger(incX, incY);
	else
		return false;
}
