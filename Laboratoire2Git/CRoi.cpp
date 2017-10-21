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
	// rien
}

/********************************
/**  modification (DEBUT)*/
CRoi::CRoi(CPlateau* J, int PX, int PY, int Force, int Coul)
	: CReine(J, PX, PY, Force, Coul)
{
	// rien
}
/**  modification (FIN)
/********************************/

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

/********************************
/**  modification (DEBUT)*/
std::string CRoi::type_piece() const
{
	return "CRoi";
}

bool echec(CPlateau const&plateau, int posX, int posY, int couleur)
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
					if ((copieplateau->Case(i, j))->Bouger(posX, posY))
					{
						echec=true;
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