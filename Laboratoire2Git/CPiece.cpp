#include "CPiece.h"
/********************************
/**  modification (DEBUT)*/
#include <string>
/**  modification (FIN)
/********************************/

#include <iostream>
using namespace std;

#include "CPlateau.h"
#include "CEcran.h"
#include "CPiece.h"
#include "CCaseVide.h"

bool CPiece::CheminVide (int incX, int incY)
{
	bool CheminLibre = true;
	
	int Dy = 0;
	if (incY != 0) Dy =  incY / abs (incY);
	int Dx = 0;
	if (incX != 0) Dx =  incX / abs (incX);
	
	int Fini = 0;
	int y = PosY + Dy, x = PosX + Dx;

	while (CheminLibre && (y != PosY+incY || x != PosX + incX) )		
	{
		if (Jeu->Case(y,x)->isCoulBlanc() != 0)
			CheminLibre = false;
		y = y + Dy;
		x = x + Dx;
	}

	if (CheminLibre)
	{
		int setCouleurArriver = Jeu->Case(PosY+incY, PosX + incX)->isCoulBlanc();
		if (!(IsCoulBlanc == -setCouleurArriver || setCouleurArriver == 0))
			CheminLibre = false;
	}
	else
		;	// C'esti un mauvais coup
	return CheminLibre;			
}


CPiece::CPiece (CPlateau* J, int PX, int PY, int V, int CB)
{
	Jeu			= J;
	Valeur		= V;
	IsCoulBlanc = CB;				// 1 = Blanc, -1 = noir
	PosX		= PX;
	PosY		= PY;
}


bool CPiece::Bouger(int incX, int incY)
{
	if (PosX + incX >= 0 && PosX + incX < 8 && 
		PosY + incY >= 0 && PosY + incY < 8)
	{
		if (CheminVide(incX, incY))
		{
			Jeu->prendrePiece(PosX, PosY);

			PosX = PosX + incX;
			PosY = PosY + incY;

			Jeu->deposerPiece(PosX, PosY, this);
			return true;
		}
	}
	return false;
}


/**
* Change la couleur du curseur pour mettre celle de la case de fond et 
* de la pièce
*/
void CPiece::setCouleur ()
{
	int fore = Noir, fond = Blanc;

	if ((PosX+PosY) % 2 ==0)	fond = Noir;
	else						fond = Blanc;

	if (IsCoulBlanc == 1)		fore  = Rouge;
	else						fore = Bleu;

	CEcran::setCouleur (fond, fore);
}


void CPiece::dessineCase()
{
	for (int y=0; y<HauteurCase; y++)
	{
		CEcran::Gotoxy (PosX *LargeurCase + 1, PosY*HauteurCase + 1 + y);
		for (int x=0; x < LargeurCase; x++)
			cout <<(" ");
	}
	CEcran::Gotoxy (PosX *LargeurCase + 1 + (int)(LargeurCase/2), 
					PosY*HauteurCase+1 + (int)(HauteurCase/2));
}


/********************************
/**  modification (DEBUT)
Cette méthode sera fausse pour toutes les pièces et sera juste redéfinie dans les pions*/
bool CPiece::priseEnPassant()
{
	return false;
}

bool CPiece::Manger(int incX, int incY)
{
	if (PosX + incX >= 0 && PosX + incX < 8 &&
		PosY + incY >= 0 && PosY + incY < 8)
	{
		Jeu->prendrePiece(PosX, PosY);

		PosX = PosX + incX;
		PosY = PosY + incY;

		Jeu->deposerPiece(PosX, PosY, this);
		return true;
	}
	return false;
}

std::string CPiece::type_piece()
{
	return "CPiece";
}

/**  modification (FIN)
/********************************/

