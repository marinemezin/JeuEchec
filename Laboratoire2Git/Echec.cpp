#include <iostream>
using namespace std;

#include "CEcran.h"
#include "CPlateau.h"
#include "CCaseVide.h"
/********************************
/**  modification (DEBUT)*/
#include "CRoi.h"
/**  modification (FIN)
/********************************/

// Prototypes
char Lire();


int main ()
{
	CPlateau* P = new CPlateau(); 

	int nbrCoup = 0;
	while (nbrCoup < 10)
	{
		nbrCoup++;
		CPlateau::verifPriseEnPassant(*P);
		P->Afficher();

		char initialX = Lire();
		char initialY = Lire();
	
		char finalX = Lire();
		char finalY = Lire();

		CEcran::ClrScr();
		if (P->Bouger(initialX - 'a', initialY - '1', finalX - 'a', finalY - '1'));
		else
			cout << ("Ca marche pas!!!") << endl;
	}

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
bool echec(CPlateau plateau)
{
	int posX = 0;
	int posY = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (plateau.Case(i, j)->type_piece() == "CRoi")
			{
				posX = i;
				posY = j;
			}
		}
	}
	//return (plateau.Case(posX, posY))->echec(plateau, posX, posY);
	return false;
}
/**  modification (FIN)
/********************************/

