#include "CPion.h"
/********************************
/**  modification (DEBUT)*/
#include <typeinfo>
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

bool CPion::Bouger(int incX, int incY)
{
	bool Retour = false;
	/********************************
	/**  modification (DEBUT)
	Ajout d'accolade pour augmenter la port�e
	Ajout de if (premierTour == true) premierTour = false;
	Ajout d'un else pour que le pion puisse avancer de deux cases
	Ajout de la possibilit� de prise en passant*/

	if (incY == IsCoulBlanc) {			// Si c'est la bonne direction
		if (incX == 0 && abs(incY) == 1)		// S'il avance
		{
			if (Jeu->Case(PosY + incY, PosX)->isCaseVide())
			{
				/********************************
				/**  modification (DEBUT)*/
				if (CPiece::Bouger(incX, incY)) {
					if (premierTour == true) premierTour = false;
					Retour = true;
				}
				/**  modification (FIN)
				/********************************/
			}
		}
		else {
			if (abs(incX) == 1) {			//S'il mange normalement
				if (!Jeu->Case(PosY + incY, PosX + incX)->isCaseVide())
				{
					if (CPiece::Manger(incX, incY)) {
						if (premierTour == true) premierTour = false;
						Retour = true;//on mange
					}
				}
				/********************************
				/**  modification (DEBUT)
				Prise en passant*/
				else {
					//Si c'est prise en passant
					int valeurCaseAManger = IsCoulBlanc == 1 ? 1 : -1;
					//Si la case ou je veux aller -1 ou +1 est prise par un pion venant d'avancer de deux cases
					if (!Jeu->Case(PosY + incY + valeurCaseAManger, PosX + incX)->isCaseVide() && Jeu->Case(PosY + incY + valeurCaseAManger, PosX + incX)->priseEnPassant())
					{
						if (CPiece::Manger(incX, incY))
						{
							if (premierTour == true) premierTour = false;
							Retour = true;//on mange en passant
						}
					}
				}
				/**  modification (FIN)
				/********************************/
			}
		}
	}
	/********************************
	/**  modification (DEBUT)
	S'il souhaite avancer de deux cases*/
	int valeurSoustraire = IsCoulBlanc == 1 ? -1 : 1;

	if((incY + valeurSoustraire == IsCoulBlanc) && (premierTour == true)) {
		if (incX == 0 && abs(incY) == 2)		// S'il avance au premier tour
		{
			if ((Jeu->Case(PosY + incY, PosX)->isCaseVide()) && (Jeu->Case(PosY + incY + valeurSoustraire, PosX)->isCaseVide()))
			{
				if (CPiece::Bouger(incX, incY))
				{
					if (premierTour == true) {
						premierTour = false;
						viensDavancer2Cases = true;
						tour++;
					}
					Retour = true;
				}
			}
		}
	}
	/**  modification (FIN)
	/********************************/
	/**  modification (FIN)
	/********************************/
	return Retour;
}

void CPion::Afficher()
{
	setCouleur();
	dessineCase();
	cout << ("P");
}
