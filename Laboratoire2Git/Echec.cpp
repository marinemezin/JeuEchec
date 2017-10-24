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

// Prototypes
char Lire();
int roiEnEchec(CPlateau plateau);
bool tourJoueur(CPlateau &P);
bool tourIA(CPlateau &P);
void finalValue(CPiece* piece, CPlateau &P, int tab[]);
bool echecetmat(CPlateau &P);


int main ()
{

	CPlateau* P = new CPlateau(); 
	srand(time(NULL));
	int nbrCoup = 0;
	int noJoueur = 1;
	int echecJoueur = 0;
	/********************************
	/**  modification (DEBUT)*/	
	while (nbrCoup < 30)
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

		echecJoueur = roiEnEchec(*P);
		if (echecJoueur != 0)
		{
			cout << "ECHEC joueur " << echecJoueur << endl;
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
int roiEnEchec(CPlateau plateau)
{
	int echec = 0;
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (plateau.Case(y, x)->type_piece() == "CRoi")
			{
				if (plateau.Case(y, x)->echec(plateau, x, y, plateau.Case(y, x)->isCoulBlanc()))
				{
					echec = plateau.Case(y, x)->isCoulBlanc();
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

	//Si la case peut bouger
	if (P.Case(initialX - 'a', initialY - '1')->deplacable(finalX - 'a', finalY - '1')) {
		//Si le déplacement ne rendra pas en echec le joueur
		//On prend la case à laquelle on veux aller
		//On regarde si une pièce adverse peut aller sur notre case
		//Si oui le if retourne true + ! = false
		//Si aucune case ne peux nous manger sur notre destination, if return false + ! = true
		if (!P.Case(finalX - 'a', finalY - '1')->echec(P, finalX - 'a', finalY - '1', P.Case(initialX - 'a', initialY - '1')->isCoulBlanc())) {
			//On fait le déplacement et si le déplacement s'est bien passé
			if (P.Bouger(initialX - 'a', initialY - '1', finalX - 'a', finalY - '1')) {
				return true;
			}
		}
	}
	return false;
}

void finalValue(CPiece* piece, CPlateau &P, int tab[])
{
	if (piece->type_piece() == "CPion")
	{
		tab[0] = (rand() % 3) - 1;
		tab[1] = -1; //ne peut pas avancer de deux cases au premier coup
	}
	if (piece->type_piece() == "CReine")
	{
		int choix = rand() % 4;
		if (choix == 0) //déplacement en ligne
		{
			tab[0] = (rand() % 15) - 7;
			tab[1] = 0;
		}
		if (choix == 1) //déplacement en colonne
		{
			tab[0] = 0;
			tab[1] = (rand() % 15) - 7;
		}
		if (choix == 2 || choix == 3) //déplacements diago
		{
			tab[0] = (rand() % 15) - 7;
			if (choix == 2) { tab[1] = tab[0] * (-1); }
			if (choix == 3) { tab[1] = tab[0]; }
		}
	}
	if (piece->type_piece() == "CRoi")
	{
		tab[0] = (rand() % 3) - 1;
		tab[1] = (rand() % 3) - 1;
	}
	if (piece->type_piece() == "CTour")
	{
		int choix = rand() % 2;
		if (choix == 0) //déplacement en ligne
		{
			tab[0] = (rand() % 15) - 7;
			tab[1] = 0;
		}
		if (choix == 1) //déplacement en colonne
		{
			tab[0] = 0;
			tab[1] = (rand() % 15) - 7;
		}
	}
	if (piece->type_piece() == "CCavalier")
	{
		//Choix du x : +1, -1, +2, -2 et choix du y en fonction
		int choix = rand() % 4;
		if (choix == 0) {
			tab[0] = 1;
			choix = rand() % 2;
			if (choix == 0) { tab[1] = -2; }
			if (choix == 1) { tab[1] = 2; }
		}
		if (choix == 1) {
			tab[0] = -1;
			choix = rand() % 2;
			if (choix == 0) { tab[1] = -2; }
			if (choix == 1) { tab[1] = 2; }
		}
		if (choix == 2) {
			tab[0] = 2;
			choix = rand() % 2;
			if (choix == 0) { tab[1] = -1; }
			if (choix == 1) { tab[1] = 1; }
		}
		if (choix == 3) {
			tab[0] = -2;
			choix = rand() % 2;
			if (choix == 0) { tab[1] = -1; }
			if (choix == 1) { tab[1] = 1; }
		}
	}
	if (piece->type_piece() == "CFou")
	{
		int choix = rand() % 2;
		tab[0] = (rand() % 15) - 7;
		if (choix == 0) { tab[1] = tab[0] * (-1); }
		if (choix == 1) { tab[1] = tab[0]; }
	}
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
	finalValue(P.Case(initialY, initialX), P, finalValeur);
	int finalX = initialX + finalValeur[0];
	int finalY = initialY + finalValeur[1];

	//Tenter de bouger le pion
	bool ok = P.Bouger(initialX, initialY, finalX, finalY);

	//Tant que le pion n'a pas bougé recalculer une variation
	while (!ok)
	{
		finalValue(P.Case(initialY , initialX), P, finalValeur);
		finalX = initialX + finalValeur[0];
		finalY = initialY + finalValeur[1];

		//Tenter de bouger le pion
		ok = P.Bouger(initialX, initialY, finalX, finalY);
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
				if (P.Case(y, x)->type_piece() == "CRoi")
				{
					posXRoi = x; //attention à la fin des boucles il retournera le dernier roi qu'il a rencontré et ne vérifiera pas les deux rois : ok on met dedans
					posYRoi = y;
					if (P.Case(posYRoi, posYRoi)->echec(P, posYRoi, posXRoi, P.Case(posYRoi, posXRoi)->isCoulBlanc()))
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
					}
					for (int i = 0; i < 9; i++)
					{
						if (ok[i] == false)
						{
							echecetmat = true;
						}
					}
				}
			}
		}
		
		return echecetmat;
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