#include "CFou.h"


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

std::string CFou::type_piece()
{
	return "CFou";
}

/**  modification (FIN)
/********************************/

