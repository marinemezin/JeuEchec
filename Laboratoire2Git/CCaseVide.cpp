#include "CCaseVide.h"


#include <iostream>
using namespace std;


CCaseVide::CCaseVide(CPlateau* J, int PX, int PY) : CPiece(J, PX, PY)
{
	// rien à faire
}


bool CCaseVide::Bouger (int Bid1, int Bid2)
{
	return false;				//On ne peut jouer une case vide
}


void CCaseVide::Afficher()
{
	setCouleur();
	dessineCase();
	cout << (" ");
}

/********************************
/**  modification (DEBUT)*/
std::string CCaseVide::type_piece() const{
	return "CCasevide";
}
/**  modification (FIN)
/********************************/