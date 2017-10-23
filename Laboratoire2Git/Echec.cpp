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
bool tourJoueur(CPlateau &P);
bool tourIA(CPlateau &P);


int main ()
{

	CPlateau* P = new CPlateau(); 
	srand(time(NULL));
	int nbrCoup = 0;
	int noJoueur = 1;
	/********************************
	/**  modification (DEBUT)*/	
	while (nbrCoup < 30)
	{

		if (!echectest(*P))
		{
			nbrCoup++;
			CPlateau::verifPriseEnPassant(*P);
			P->Afficher();
			
			//if (noJoueur == 1) {
				//if (tourJoueur(*P)) { noJoueur = -1; }
			//}
			//else {
				if (tourIA(*P)) { noJoueur = 1; }
			//}
		}
		else
		{
			cout<<"ECHEC"<<endl;
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
bool echectest(CPlateau plateau)
{
	bool echec = false;
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (plateau.Case(y, x)->type_piece() == "CRoi")
			{
				if ((!echec) && (plateau.Case(y, x))->echec(plateau, x, y, plateau.Case(y, x)->isCoulBlanc()))
				{
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
	if (P.Bouger(initialX - 'a', initialY - '1', finalX - 'a', finalY - '1')) {
		return true;
	}
	return false;
}

//IA joue les pions noirs
bool tourIA(CPlateau &P) {
	int initialX = (rand() % 8) + 1;
	int initialY = (rand() % 8) + 1;
	//tant que le pion trouvé n'est pas un pion noir ni un pion déplacable on cherche un autre pion
	while ((P.Case(initialY - 1, initialX - 1)->isCoulBlanc() != -1) && (!P.Case(initialY - 1, initialX - 1)->deplacable(initialX - 1, initialY - 1)))
	{
		initialX = (rand() % 8) + 1;
		initialY = (rand() % 8) + 1;
	}

	//Choisir des valeurs au hasard en fonction du pion sélectionné
	//Si c'est un pion n'augmenter ou diminuer que la valeur Y
	//Si il y a une pièce dans telle ou telle direction alors il mange
	//Same pour toutes les autres pièces
	int finalX = (rand() % 8) + 1;
	int finalY = (rand() % 8) + 1;

	//Tenter de bouger le pion
	bool ok = P.Bouger(initialX, initialY, finalX, finalY);

	//Tant que le pion n'a pas bougé refaire toutes les opérations en sélectionnant un autre pion
	//Ou en gardant le meme
	while (!ok)
	{
		while (P.Case(initialY - 1, initialX - 1)->isCoulBlanc() != -1)
		{
			initialX = (rand() % 8) + 1;
			initialY = (rand() % 8) + 1;
		}

		finalX = (rand() % 8) + 1;
		finalY = (rand() % 8) + 1;

		cout << initialX << " " << initialY << " " << finalX << " " << finalY << endl;

		ok = P.Bouger(initialX, initialY, finalX, finalY);
		cout << "newok" << endl;
	}
	CEcran::ClrScr();
	//system("PAUSE");
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