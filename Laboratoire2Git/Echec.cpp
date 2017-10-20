#include <iostream>
using namespace std;

#include "CEcran.h"
#include "CPlateau.h"
#include "CCaseVide.h"

// Prototypes
//test
char Lire();


int main ()
{
	CPlateau* P = new CPlateau(); 

	int nbrCoup = 0;
	while (nbrCoup < 10)
	{
		nbrCoup++;

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

	delete P;

	return 0;
}

char Lire()
{
	char C = 'A';
	cin >> C;

	return C;
}


