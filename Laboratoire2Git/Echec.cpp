#include <iostream>
using namespace std;

#include "CEcran.h"
#include "CPlateau.h"
#include "CCaseVide.h"
/********************************
/**  modification (DEBUT)*/
#include "CRoi.h"
#include <time.h>
/**  modification (FIN)
/********************************/


/********************************
/**  modification (DEBUT)*/
// Prototypes
char Lire();
bool roiEnEchec(CPlateau plateau, int couleur);
bool tourJoueur(CPlateau &P);
bool tourIA(CPlateau &P);
bool echecetmat(CPlateau &P);
bool rendEnEchec(CPlateau &P, int posXdep, int posYdep, int posXfin, int posYfin);
/**  modification (FIN)
/********************************/


int main ()
{
	CPlateau* P = new CPlateau(); 
	srand(time(NULL));
	int nbrCoup = 0;
	int noJoueur = 1;
	int echecJoueur = 0;
	/********************************
	/**  modification (DEBUT)*/	
	while (!echecetmat(*P))
	{
		nbrCoup++;
		CPlateau::verifPriseEnPassant(*P);
		P->Afficher();
			
		//if (noJoueur == 1) {
			if (tourJoueur(*P)) {
				noJoueur = -1;
			}/*
		}
		else {
			if (tourIA(*P)) {
				noJoueur = 1;
			}
		}*/

		if (roiEnEchec(*P, -1)) {
			cout << "ECHEC joueur " << -1 << endl;
		}
		if (roiEnEchec(*P, 1)) {
			cout << "ECHEC joueur " << 1 << endl;
		}
	}
	/**  modification (FIN)
	/********************************/
	/*CPlateau* P2 = new CPlateau(*P);
	delete P2;
	cout << endl;
	delete P;

	system("PAUSE");*/
	return 0;
}

char Lire()
{
	char C = 'A';
	cin >> C;

	return C;
}

/********************************
/**  modification (DEBUT)*/
//Retourne le numéro de couleur du roi en echec
bool roiEnEchec(CPlateau plateau, int couleur)
{
	bool echec = false;
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if ((plateau.Case(y, x)->type_piece() == "CRoi") && (plateau.Case(y, x)->isCoulBlanc() == couleur))
			{
				if (plateau.Case(y, x)->echec(plateau, x, y, couleur)) {
					echec = true;
				}
			}
		}
	}
	return echec;
}


bool tourJoueur(CPlateau &P)
{
	char initialX = Lire();
	char initialY = Lire();
	char finalX = Lire();
	char finalY = Lire();
	CEcran::ClrScr();
	if (P.Case(initialY - '1', initialX - 'a')->deplacable(finalX - 'a', finalY - '1')) {
		CPlateau* newP = new CPlateau(P);
		if (newP->Bouger(initialX - 'a', initialY - '1', finalX - 'a', finalY - '1')) {
			if (!roiEnEchec(*newP, 1)) {
				if (P.Bouger(initialX - 'a', initialY - '1', finalX - 'a', finalY - '1')) {
					delete newP;
					return true;
				}
			}
		}
		delete newP;
	}
	return false;
}

//IA joue les pions noirs
bool tourIA(CPlateau &P) {
	int initialX = (rand() % 8);
	int initialY = (rand() % 8);
	//tant que le pion trouvé n'est pas un pion noir ni un pion déplacable on cherche un autre pion
	while ((P.Case(initialY, initialX)->isCoulBlanc() != -1) || (!P.Case(initialY, initialX)->deplacable(initialX, initialY)))
	{
		initialX = (rand() % 8);
		initialY = (rand() % 8);
	}

	//Choisir des valeurs au hasard en fonction du pion sélectionné
	int finalValeur[2];
	P.Case(initialY, initialX)->coordonneesIA(finalValeur);
	int finalX = initialX + finalValeur[0];
	int finalY = initialY + finalValeur[1];

	//Tenter de bouger le pion
	CPlateau* newP = new CPlateau(P);
	bool ok = false;
	if (newP->Bouger(initialX, initialY, finalX, finalY)) {
		if (!roiEnEchec(*newP, -1)) {
			ok = P.Bouger(initialX, initialY, finalX, finalY);
		}
	}
	delete newP;

	//Tant que le pion n'a pas bougé recalculer une variation
	while (!ok)
	{
		P.Case(initialY, initialX)->coordonneesIA(finalValeur);
		finalX = initialX + finalValeur[0];
		finalY = initialY + finalValeur[1];

		//Tenter de bouger le pion
		if (newP->Bouger(initialX, initialY, finalX, finalY)) {
			if (!roiEnEchec(*newP, -1)) {
				ok = P.Bouger(initialX, initialY, finalX, finalY);
			}
		}
	}
	CEcran::ClrScr();
	//system("PAUSE");
	return ok;


}	
bool echecetmat(CPlateau &P)
	{
		bool echecetmat = false;
		bool ok[9];
		int posXRoi = -1;
		int posYRoi = -1;
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				if (P.CaseModif(y, x)->type_piece() == "CRoi")
				{
					posXRoi = x; 
					posYRoi = y;
					if (P.CaseModif(posYRoi, posYRoi)->echec(P, posXRoi, posYRoi, P.CaseModif(posYRoi, posXRoi)->isCoulBlanc()))
					{
						int k = 0;
						for (int i = -1; i < 2; i++)
						{
							for (int j = -1; j < 2; j++)
							{
								ok[k] = rendEnEchec(P, posXRoi, posYRoi, posXRoi+i,posYRoi+j); 
								k++;
							}
						}
						for (int i = 0; i < 9; i++)
						{
							if (ok[i] == false)		echecetmat = true;
						}
					}
					
				}
			}
		}
		
		return echecetmat;
	}

bool rendEnEchec(CPlateau &P, int posXdep, int posYdep, int posXfin, int posYfin)
{
	bool ok = false;
	CPlateau* P2 = new CPlateau(P);
	if (P2->Bouger(posXdep, posYdep, posXfin, posYfin))
	{
		ok = (P2->CaseModif(posYfin, posXfin))->echec(*P2, posXfin, posYfin, P2->CaseModif(posYfin, posXfin)->isCoulBlanc());
	}
	delete P2;
	return ok;
}
/**  modification (FIN)
/********************************/

/********************************
/**  modification (DEBUT)*/
/*Test de l'echec !!! 
e7e5
h2h4
e8e7
h1h3
h7h6
h3e3
h6h5
e3e5
*/
/**  modification (FIN)
/********************************/