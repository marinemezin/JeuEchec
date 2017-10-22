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

		/*//IA BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if (!echectest(*P))
		{
			nbrCoup++;
			CPlateau::verifPriseEnPassant(*P);
			P->Afficher();

			int initialX = rand() % 8 + 1;
			int initialY = rand() % 8 + 1;
			while (P->Case(initialX, initialY)->isCoulBlanc() != -1)
			{
				initialX = rand() % 8 + 1;
				initialY = rand() % 8 + 1;
			}
			int finalX = rand() % 8 + 1;
			int finalY = rand() % 8 + 1;
			cout << initialX << " " << initialY << " " << finalX << " " << finalY << endl;

			bool ok = P->Bouger(initialX, initialY, finalX, finalY);
			while (!ok)
			{
				while (P->Case(initialX, initialY)->isCoulBlanc() != -1)
				{
					initialX = rand() % 8 + 1;
					initialY = rand() % 8 + 1;
				}

				finalX = initialX + rand() % 3;
				finalY = initialY + rand() % 3;

				cout << initialX << " " << initialY << " " << finalX << " " << finalY << endl;

				ok = P->Bouger(initialX, initialY, finalX, finalY);
				cout << "newok" << endl;
			}
			CEcran::ClrScr();
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
	bool echec = false;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (plateau.Case(j, i)->type_piece() == "CRoi")
			{
				if ((!echec) && (plateau.Case(j, i))->echec(plateau, i, j, plateau.Case(j, i)->isCoulBlanc()))
				{
					echec = true;
				}
			}
		}
	}
	return echec;
	//return false;
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