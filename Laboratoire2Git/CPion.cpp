#include "CPion.h"
/********************************
/**  modification (DEBUT)*/
#include <string>
#include <time.h>
/**  modification (FIN)
/********************************/
#include <iostream>
using namespace std;


CPion::CPion(CPlateau* J, int PX, int PY, int Coul) : CPiece(J, PX, PY, 1, Coul)
{
	/********************************
	/**  modification (DEBUT)*/
	premierTour = true;
	viensDavancer2Cases = false;
	tour = 0;
	/**  modification (FIN)
	/********************************/
}

/********************************
/**  modification (DEBUT)*/
bool CPion::priseEnPassant() {
	if (viensDavancer2Cases == true)
	{
		return true;
	}
	return false;
}
/**  modification (FIN)
/********************************/

/********************************
/**  modification (DEBUT)*/
bool CPion::avancerBouger(int incX, int incY)
{
	bool retour = false;
	if (incX == 0 && abs(incY) == 1) {		// S'il avance
		if (Jeu->Case(PosY + incY, PosX)->isCaseVide()) {
			if (CPiece::Bouger(incX, incY)) {
				if (premierTour == true) premierTour = false;
				retour = true;
			}
		}
	}
	return retour;
}
bool CPion::mangerBouger(int incX, int incY)
{
	bool retour = false;
	if (!Jeu->Case(PosY + incY, PosX + incX)->isCaseVide()) {
		if (CPiece::Manger(incX, incY)) {
			if (premierTour == true) premierTour = false;
			retour = true;//on mange
		}
	}
	else { //prise en passant
		int valeurCaseAManger = IsCoulBlanc == 1 ? -1 : 1;
		if (!Jeu->Case(PosY + incY + valeurCaseAManger, PosX + incX)->isCaseVide() && Jeu->Case(PosY + incY + valeurCaseAManger, PosX + incX)->priseEnPassant()) {
			if (CPiece::Bouger(incX, incY)) {
				Jeu->prendrePiece(PosX, PosY + valeurCaseAManger);
				if (premierTour == true) { premierTour = false; }
				retour = true;//on mange en passant
			}
		}
	}
	return retour;
}
bool CPion::avancer2casesBouger(int incX, int incY)
{
	bool retour = false;
	int valeurSoustraire = IsCoulBlanc == 1 ? -1 : 1;
	if ((incY + valeurSoustraire == IsCoulBlanc) && (premierTour == true)) {
		if (incX == 0 && abs(incY) == 2) {		// S'il avance au premier tour
			if ((Jeu->CaseModif(PosY + incY, PosX)->isCaseVide()) 
				&& (Jeu->CaseModif(PosY + incY + valeurSoustraire, PosX)->isCaseVide())) {
				if (CPiece::Bouger(incX, incY))	{
					if (premierTour == true) {
						premierTour = false;
						viensDavancer2Cases = true;
						tour++;
					}
					retour = true;
				}
			}
		}
	}
	return retour;
}
bool CPion::Bouger(int incX, int incY)
{
	bool retour = false;
	if (incY == IsCoulBlanc) {			// Si c'est la bonne direction
		if (incX == 0 && abs(incY) == 1) {		// S'il avance
			retour = avancerBouger(incX, incY);
		}
		else {
			if (abs(incX) == 1) {			//S'il mange normalement
				retour = mangerBouger(incX, incY);
			}
		}
	}
	//S'il souhaite avancer de deux cases
	retour = avancer2casesBouger(incX, incY);
	return retour;
}
/**  modification (FIN)
/********************************/

void CPion::Afficher()
{
	setCouleur();
	dessineCase();
	cout << ("P");
}

/********************************
/**  modification (DEBUT)*/
std::string CPion::type_piece() const {
	return "CPion";
}

void CPion::modifPriseEnPassant() {
	if (tour == 2) {
		tour = 0;
		viensDavancer2Cases = false;
	}
	if (tour == 1) { tour++; }
}


bool CPion::deplacable(int x, int y) const {
	//IA joue les pions noirs
	bool possible = false;
	if ((y - 1) >= 0 && (y - 1) <= 7) {
		if (Jeu->Case(y - 1, x)->isCaseVide()) { possible = true; }
		//S'il peut manger
		if ((x - 1) >= 0 && (x - 1) <= 7 && (Jeu->Case(y - 1, x - 1)->isCoulBlanc() == 1)) { possible = true; }
		if ((x + 1) >= 0 && (x + 1) <= 7 && (Jeu->Case(y - 1, x + 1)->isCoulBlanc() == 1)) { possible = true; }
	}
	return possible;
}
void CPion::coordonneesIA(int tab[]) const {
	int choix = rand() % 2;
	tab[0] = (rand() % 3) - 1;
	if (choix == 0) { tab[1] = -1; }
	if (choix == 1) { tab[1] = -2; }
}
/**  modification (FIN)
/********************************/
