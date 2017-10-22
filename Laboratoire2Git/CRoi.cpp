#include "CRoi.h"

/********************************
/**  modification (DEBUT)*/
#include "CPlateau.h"
/**  modification (FIN)
/********************************/

#include <iostream>
using namespace std;


CRoi::CRoi (CPlateau* J, int Coul) : 
		CReine(J, 4, (Coul == 1 ? 0 : 7), 5, Coul)
{
	/********************************
	/**  modification (DEBUT)*/
	aRoque = false;
	/**  modification (FIN)
	/********************************/
}

/********************************
/**  modification (DEBUT)*/
CRoi::CRoi(CPlateau* J, int PX, int PY, int Force, int Coul)
	: CReine(J, PX, PY, Force, Coul)
{
	aRoque = false;
}
/**  modification (FIN)
/********************************/

void CRoi::Afficher()
{
	setCouleur();
	dessineCase();
	cout << ("R");
}

/********************************
/**  modification (DEBUT)*/
bool CRoi::valideTourRoque(int ajustCase, int incY, int incX, int posXAttendue, int posYAttendue)
{
	bool ok = false;
	if ((Jeu->Case(incY, incX + ajustCase)->type_piece() == "CTour") && (Jeu->Case(incY, incX + ajustCase)->isCoulBlanc() == this->isCoulBlanc()))
	{
		if ((Jeu->Case(incY, incX + ajustCase)->getPosX() == posXAttendue) && (Jeu->Case(incY, incX + ajustCase)->getPosY() == posYAttendue))
		{
			ok = true;
		}
	}
	return ok;
}

bool CRoi::valideRoiRoque(int PosX, int PosY, int posXAttendue, int posYAttendue)
{
	bool ok = false;
	if (!echec((*this->Jeu), PosX, PosY, this->isCoulBlanc())) //si le roi n'est pas en echec
	{
		if ((this->PosX == posXAttendue) && (this->PosY == posYAttendue)) //et a sa position initiale
		{
			ok = true;
		}
	}
	return ok;
}

bool CRoi::casesDeplacementNonEchec(int incX, int incY)
{
	bool ok = false;
	int valeurMultiplication = incX / abs(incX);
	if (Jeu->Case(incY, incX)->isCaseVide() && Jeu->Case(incY, incX - valeurMultiplication)->isCaseVide()) //si les cases que le roi veux traverser sont libres
	{
		if (!echec((*this->Jeu), incX, incY, this->Jeu->Case(incY, incX)->isCoulBlanc())) //si la case la plus loin n'est pas en echec
		{
			if (!echec((*this->Jeu), incX, incY, this->Jeu->Case(incY, incX - valeurMultiplication)->isCoulBlanc())) //si la case du milieu n'est pas en echec
			{
				ok = true;
			}
		}
	}
	return ok;
}

bool CRoi::mouvementRoque(int incX, int incY, int xTour, int yTour)
{
	bool ok = false;
	if (CPiece::Bouger(incX, incY) && CPiece::Bouger(xTour, yTour)) //on bouge le roi et la tour apres
	{
		this->aRoque = true;
		ok = true;
	}
	return ok;
}

bool CRoi::Bouger (int incX, int incY)
{
	if (abs(incX) <= 1 && + abs(incY) <= 1 )
		return CPiece::Bouger(incX, incY);

	//le roi peut bouger en roquant
	if ((abs(incX) == 2) && (abs(incY) == 0)) { //si le roi veux se déplacer de deux cases en horizontal
		if (casesDeplacementNonEchec(incX, incY)) {
			if (valideRoiRoque(PosX, PosY, 4, 0)) { //Roi Blanc
				//Petit roque
				if ((valideTourRoque(1, incY, incX, 7, 0)) && (mouvementRoque(incX, incY, 7, 0)))
					return true;
				//Grand roque
				if ((valideTourRoque(-2, incY, incX, 0, 0)) && (mouvementRoque(incX, incY, 0, 0)))
					return true;
			}
			if (valideRoiRoque(PosX, PosY, 4, 7)) { //Roi Noir
				//Petit roque
				if ((valideTourRoque(1, incY, incX, 7, 7)) && (mouvementRoque(incX, incY, 7, 7)))
					return true;
				//Grand roque
				if ((valideTourRoque(-2, incY, incX, 0, 7)) && (mouvementRoque(incX, incY, 0, 7)))
					return true;
			}
		}
	}
	return false;
}

/**  modification (FIN)
/********************************/

/********************************
/**  modification (DEBUT)*/
std::string CRoi::type_piece() const
{
	return "CRoi";
}

bool CRoi::echec(CPlateau const&plateau, int posX, int posY, int couleur)
{
	bool echec = false; 
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (plateau.Case(i, j)->type_piece() != "CCasevide")
			{
				if (plateau.Case(i,j)->isCoulBlanc() != plateau.Case(posX, posY)->isCoulBlanc())
				{
					CPlateau* copieplateau = new CPlateau(plateau);
					if (copieplateau->Bouger(i, j, posX, posY))
					{
						echec = true; 
					}
					delete copieplateau;
				}
			}
		}
	}

	return echec; 
}


/**  modification (FIN)
/********************************/