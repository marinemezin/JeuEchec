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
bool rendEnEchec(CPlateau &P, int Xdep, int Ydep, int Xfin, int Yfin);
bool roiBloque(CPlateau P, int X, int Y);
bool pat(CPlateau P, int couleur);
/**  modification (FIN)
/********************************/

/********************************
/**  modification (DEBUT)*/
int main () {
	CPlateau* P = new CPlateau(); 
	srand(time(NULL));
	int noJoueur = 1;
	while (!echecetmat(*P) || pat(*P, 1) || pat(*P, -1)) {
		CPlateau::verifPriseEnPassant(*P);
		P->Afficher();
		if (noJoueur == 1) {
			if (tourJoueur(*P)) { noJoueur = -1; }
		}
		else {
			if (tourIA(*P)) { noJoueur = 1; }
		}
		CEcran::ClrScr();
		if (roiEnEchec(*P, -1)) { cout << "ECHEC joueur " << -1 << endl; }
		if (roiEnEchec(*P, 1)) { cout << "ECHEC joueur " << 1 << endl; }
	}
	if (echecetmat(*P)) { cout << "ECHEC ET MAT"; }
	if (pat(*P, 1) || pat(*P, -1)) { cout << "Match nul"; }
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
bool roiEnEchec(CPlateau plateau, int couleur){
	bool echec = false;
	for (int y = 0; y < 8; y++){
		for (int x = 0; x < 8; x++){
			if ((plateau.Case(y, x)->type_piece() == "CRoi") 
				&& (plateau.Case(y, x)->isCoulBlanc() == couleur)){
				if (plateau.Case(y, x)->echec(plateau, x, y, couleur)) {
					echec = true;
				}
			}
		}
	}
	return echec;
}


bool tourJoueur(CPlateau &P){
	char iniX = Lire();
	char iniY = Lire();
	char finX = Lire();
	char finY = Lire();
	if (P.Case(iniY - '1', iniX - 'a')
		->isCoulBlanc() == 1) {
		if (P.Case(iniY - '1', iniX - 'a')
			->deplacable(finX - 'a', finY - '1')) {
			CPlateau* newP = new CPlateau(P);
			if (newP->Bouger(iniX - 'a', iniY - '1', finX - 'a', finY - '1')) {
				if (!roiEnEchec(*newP, 1)) {
					if (P.Bouger(iniX - 'a', iniY - '1', finX - 'a', finY - '1')) {
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


bool tourIA(CPlateau &P) {
	int iniX = (rand() % 8);
	int iniY = (rand() % 8);
	while ((P.Case(iniY, iniX)->isCoulBlanc() != -1) 
		|| (!P.Case(iniY, iniX)->deplacable(iniX, iniY))) {
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
			ok = P.Bouger(iniX, iniY, finX, finY); }
	}
	return ok;
}	


bool echecetmat(CPlateau &P) {
	bool echecetmat = false;
	bool ok[9];
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (P.Case(y, x)->type_piece() == "CRoi") {
				if (P.Case(y, x)
					->echec(P, x, y, P.Case(y, x)
						->isCoulBlanc())){
					int k = 0;
					for (int i = -1; i < 2; i++) {
						for (int j = -1; j < 2; j++) {
							ok[k] = rendEnEchec(P, x, y, x+i,y+j); 
							k++;
						}
					}
					for (int i = 0; i < 9; i++) {
						if (ok[i] == false) { echecetmat = true; }
					}
				}	
			}
		}
	}
	return echecetmat;
}


bool rendEnEchec(CPlateau &P, int Xdep, int Ydep, int Xfin, int Yfin) {
	bool ok = false;
	CPlateau* P2 = new CPlateau(P);
	if (P2->Bouger(Xdep, Ydep, Xfin, Yfin)) {
		ok = (P2->Case(Yfin, Xfin))
			->echec(*P2, Xfin, Yfin, P2->Case(Yfin, Xfin)
				->isCoulBlanc());
	}
	delete P2;
	return ok;
}


bool roiBloque(CPlateau P, int X, int Y)
{
	int k = 0, compteur = 0;
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if ((X + i) >= 0 && (X + i) <= 7
				&& (Y + j) >= 0 && (Y + j) <= 7
				&& (i != 0) && (j != 0)){
				compteur++;
				if (rendEnEchec(P, X, Y, X + i, Y + j)) {
					k++;
				}
			}
		}
	}
	if(k == compteur){
		return true;
	}
	return false;
}


bool pat(CPlateau P, int couleur)
{
	bool retour = false;
	if (!roiEnEchec(P, couleur)) {
		for (int y = 0; y < 8; y++) {
			for (int x = 0; x < 8; x++) {
				if ((P.Case(y, x)->type_piece() == "CRoi") 
						&& (P.Case(y, x)->isCoulBlanc())) {
					retour = roiBloque(P, x, y);
				}
			}
		}
	}
	return retour;
}
/**  modification (FIN)
/********************************/