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
bool echectest(CPlateau plateau);


int main ()
{
	CPlateau* P = new CPlateau(); 

	int nbrCoup = 0;
	/********************************
	/**  modification (DEBUT)*/	
	while (nbrCoup < 30)
	{

		if (!echectest(*P))
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
		else
		{
			cout<<"ECHEC"<<endl;
		}

		/*//IA BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if (!echectest(*P))
		{
			nbrCoup++;
			CPlateau::verifPriseEnPassant(*P);
			P->Afficher();

			char initialX = rand() % 8 + 1;
			char initialY = rand() % 8 + 1;

			char finalX = rand() % 8 + 1;
			char finalY = rand() % 8 + 1;

			CEcran::ClrScr();

			bool ok = P->Bouger(initialX, initialY, finalX, finalY);
			while (!ok)
			{
				char initialX = rand() % 8 + 1;
				char initialY = rand() % 8 + 1;

				char finalX = rand() % 8 + 1;
				char finalY = rand() % 8 + 1;

				ok = P->Bouger(initialX, initialY, finalX, finalY);
			}
		}
		else
		{
			cout << "ECHEC" << endl;
		}*/
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
bool echectest(CPlateau plateau)
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
	return (plateau.Case(posX, posY))->echec(plateau, posX, posY, plateau.Case(posX,posY)->isCoulBlanc());
	return false;
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