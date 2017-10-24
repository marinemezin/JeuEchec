#include <iostream>
using namespace std;

#include "CEcran.h"
#include "CPlateau.h"
#include "CCaseVide.h"
/********************************
/**  modification (DEBUT)*/
#include "CRoi.h"
#include <time.h>


// Prototypes
char Lire();
bool roiEnEchec(CPlateau plateau, int couleur);
bool tourJoueur(CPlateau &P);
bool tourIA(CPlateau &P);
bool IApeutJouer(CPlateau P, int iniX, int iniY, int finX, int finY);
bool echecetmat(CPlateau &P);
bool rendEnEchec(CPlateau &P, int posXdep, int posYdep, int posXfin, int posYfin);
//bool pat(CPlateau P, int couleur);
/**  modification (FIN)
/********************************/

/********************************
/**  modification (DEBUT)*/
int main () {
	CPlateau* P = new CPlateau(); 
	srand(time(NULL));
	int noJoueur = 1;
	while (!echecetmat(*P))	{
		CPlateau::verifPriseEnPassant(*P);
		P->Afficher();
		if (noJoueur == 1) {
			if (tourJoueur(*P)) { noJoueur = -1; }
		}
		else {
			if (tourIA(*P)) { noJoueur = 1; }
		}

		if (roiEnEchec(*P, -1)) { cout << "ECHEC joueur " << -1 << endl; }
		if (roiEnEchec(*P, 1)) { cout << "ECHEC joueur " << 1 << endl; }
	}
	if (echecetmat(*P)) { cout << "ECHEC ET MAT"; }
	return 0;
}
/**  modification (FIN)
/********************************/

char Lire()
{
	char C = 'A';
	cin >> C;

	return C;
}

/********************************
/**  modification (DEBUT)*/
//Retourne le numéro de couleur du roi en echec
bool roiEnEchec(CPlateau plateau, int couleur){
	bool echec = false;
	for (int y = 0; y < 8; y++){
		for (int x = 0; x < 8; x++){
			if ((plateau.Case(y, x)->type_piece() == "CRoi") && (plateau.Case(y, x)->isCoulBlanc() == couleur)){
				if (plateau.Case(y, x)->echec(plateau, x, y, couleur))	echec = true;
			}
		}
	}
	return echec;
}


bool tourJoueur(CPlateau &P){
	char initialX = Lire();
	char initialY = Lire();
	char finalX = Lire();
	char finalY = Lire();
	CEcran::ClrScr();
	if (P.Case(initialY - '1', initialX - 'a')->isCoulBlanc() == 1) {
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
	}
	return false;
}

bool IApeutJouer(CPlateau P, int iniX, int iniY, int finX, int finY)
{
	bool ok = false;
	CPlateau* newP = new CPlateau(P);
	if (newP->Bouger(iniX, iniY, finX, finY)) {
		if (!roiEnEchec(*newP, -1)) {
			ok = true;
		}
	}
	delete newP;
	return ok;
}
bool tourIA(CPlateau &P)
{
	int iniX = (rand() % 8);
	int iniY = (rand() % 8);
	while ((P.Case(iniY, iniX)->isCoulBlanc() != -1) || (!P.Case(iniY, iniX)->deplacable(iniX, iniY)))
	{
		iniX = (rand() % 8);
		iniY = (rand() % 8);
	}
	int finalValeur[2];
	P.Case(iniY, iniX)->coordonneesIA(finalValeur);
	int finX = iniX + finalValeur[0];
	int finY = iniY + finalValeur[1];
	bool ok = false;
	if (IApeutJouer(P, iniX, iniY, finX, finY)) {
		ok = P.Bouger(iniX, iniY, finX, finY);
	}
	while (!ok) {
		P.Case(iniY, iniX)->coordonneesIA(finalValeur);
		finX = iniX + finalValeur[0];
		finY = iniY + finalValeur[1];
		if (IApeutJouer(P, iniX, iniY, finX, finY)) {
			ok = P.Bouger(iniX, iniY, finX, finY);
		}
	}
	CEcran::ClrScr();
	return ok;
}	
bool echecetmat(CPlateau &P){
	bool echecetmat = false;
	bool ok[9];
	int posXRoi = -1, posYRoi = -1;
	for (int y = 0; y < 8; y++){
		for (int x = 0; x < 8; x++){
			if (P.Case(y, x)->type_piece() == "CRoi"){
				posXRoi = x, posYRoi = y;
				if (P.Case(posYRoi, posYRoi)->echec(P, posXRoi, posYRoi, P.Case(posYRoi, posXRoi)->isCoulBlanc())){
					int k = 0;
					for (int i = -1; i < 2; i++){
						for (int j = -1; j < 2; j++){
							ok[k] = rendEnEchec(P, posXRoi, posYRoi, posXRoi+i,posYRoi+j); 
							k++;
						}
					}
					for (int i = 0; i < 9; i++){
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
	if (P2->Bouger(posXdep, posYdep, posXfin, posYfin)){
		ok = (P2->Case(posYfin, posXfin))->echec(*P2, posXfin, posYfin, P2->Case(posYfin, posXfin)->isCoulBlanc());
	}
	else{
		ok = false;
	}
	delete P2;
	return ok;
}

/*bool pat(CPlateau P, int couleur)
{
	//Si le roi n'est pas en echec
	if (!roiEnEchec(P, couleur))
	{

	}
	//Et si n'importe quel mouvement le rendrait en echec
	//Alors il y a match nul
	return true;
}*/
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