#include "CRoi.h"

/********************************
/**  modification (DEBUT)*/
#include "CPlateau.h"
#include <time.h>
/**  modification (FIN)
/********************************/

#include <iostream>
using namespace std;


CRoi::CRoi(CPlateau* J, int Coul) :
	CReine(J, 4, (Coul == 1 ? 0 : 7), 5, Coul)
{
	/********************************
	/**  modification (DEBUT)*/
	aRoque = false;
	aBouger = false;
	/**  modification (FIN)
	/********************************/
}

/********************************
/**  modification (DEBUT)*/
CRoi::CRoi(CPlateau* J, int PX, int PY, int Force, int Coul)
	: CReine(J, PX, PY, Force, Coul)
{
	aRoque = false;
	aBouger = false;
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
bool CRoi::valideTourRoque(int ajustCase, int posY, int posX, 
				int posXAttendue, int posYAttendue) {
	bool ok = false;
	if ((Jeu->Case(posY, posX + ajustCase)->type_piece() == "CTour") &&
		(Jeu->Case(posY, posX + ajustCase)->isCoulBlanc() == this->isCoulBlanc())) {
		if ((Jeu->Case(posY, posX + ajustCase)->getPosX() == posXAttendue) &&
			(Jeu->Case(posY, posX + ajustCase)->getPosY() == posYAttendue)) {
			if (Jeu->Case(posY, posX + ajustCase)->getABouger() == false) {
				ok = true;
			}
		}
	}
	return ok;
}

bool CRoi::valideRoiRoque(int posX, int posY, int posXAttendue, int posYAttendue) {
	bool ok = false;
	if (!echec((*this->Jeu), posX, posY, this->isCoulBlanc())) {
		if ((this->PosX == posXAttendue) 
						&& (this->PosY == posYAttendue)) {
			ok = true;
		}
	}
	return ok;
}

bool CRoi::casesDeplacementNonEchec(int posX, int posY, int coul) {
	bool ok = false;
	int valeurMulti = posX / abs(posX);
	if (Jeu->Case(posY, posX)->isCaseVide() 
				&& Jeu->Case(posY, posX - valeurMulti)->isCaseVide()) {
		if (!echec((*this->Jeu), posX, posY, coul)) {
			if (!echec((*this->Jeu), posX - valeurMulti, posY, coul)) {
				ok = true;
			}
		}
	}
	return ok;
}

bool CRoi::mouvementRoque(int incX, int incY, int xTour, int yTour, 
					int posXTour, int posYTour)
{
	bool ok = false;
	if (CPiece::Bouger(incX, incY)) { //on bouge le roi et la tour apres
		if (Jeu->CaseModif(posYTour, posXTour)->Manger(xTour, yTour)) {
			this->aRoque = true;
			ok = true;
		}
	}
	return ok;
}
bool CRoi::roiBlancRoque(int incX, int incY)
{
	//Petit roque
	if ((valideTourRoque(1, PosY + incY, PosX + incX, 7, 0)) 
			&& (mouvementRoque(incX, incY, -2, 0, 7, 0))) {
		aBouger = true;
		return true;
	}
	//Grand roque
	if ((valideTourRoque(-2, PosY + incY, PosX + incX, 0, 0)) 
			&& (mouvementRoque(incX, incY, 3, 0, 0, 0))) {
		aBouger = true;
		return true;
	}
	return false;
}
bool CRoi::roiNoirRoque(int incX, int incY)
{
	//Petit roque
	if ((valideTourRoque(1, PosY + incY, PosX + incX, 7, 7)) 
			&& (mouvementRoque(incX, incY, -2, 0, 7, 7))) {
		aBouger = true;
		return true;
	}
	//Grand roque
	if ((valideTourRoque(-2, PosY + incY, PosX + incX, 0, 7)) 
			&& (mouvementRoque(incX, incY, 3, 0, 0, 7))) {
		aBouger = true;
		return true;
	}
}
bool CRoi::Bouger(int incX, int incY) {
	if (abs(incX) <= 1 && +abs(incY) <= 1) {
		if (CPiece::Bouger(incX, incY)) {
			aBouger = true;
			return true;
		}
	}
	if ((abs(incX) == 2) && (abs(incY) == 0) 
			&& aRoque == false && aBouger == false) { //le roi peut roquer
		if (casesDeplacementNonEchec(PosX + incX, PosY + incY, IsCoulBlanc)) {
			if (valideRoiRoque(PosX, PosY, 4, 0)) { //Roi Blanc
				return roiBlancRoque(incX, incY);
			}
			if (valideRoiRoque(PosX, PosY, 4, 7)) { //Roi Noir
				return roiNoirRoque(incX, incY);
			}
		}
	}
	return false;
}


std::string CRoi::type_piece() const {
	return "CRoi";
}


bool CRoi::deplacable(int x, int y) const {
	return CPiece::deplacable(x, y);
}


void CRoi::coordonneesIA(int tab[]) const {
	tab[0] = (rand() % 3) - 1;
	tab[1] = (rand() % 3) - 1;
}


bool CRoi::echec(CPlateau const&P, int posX, int posY, int coul) const {
	bool echec = false;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (P.Case(y, x)->type_piece() != "CCasevide") {
				if (P.Case(y, x)->isCoulBlanc() != coul) {
					CPlateau* copieplateau = new CPlateau(P);
					if (copieplateau->Bouger(x, y, posX, posY)) {
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