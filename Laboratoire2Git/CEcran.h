#ifndef CECRAN_H
#define CECRAN_H
//#define LINUX
/**
  * Cette classe fournis des services de gestion d'écran en utilisant ansi.
  */
class CEcran
{
public:
/**
  * Efface l'écran au complet.
  */
	static void ClrScr();

/**
  * DessineCasement à la position x, y.
  * x Positon en x entre 1 et 80.
  * y Positon en y entre 1 et 25.
  */
	static void Gotoxy(int x,int y);

/** 
  * Changer la couleur de fond et d'écriture.
  * f La couleur de fond.
  * l La couleur d'écriture.
  */
	static void setCouleur (int f,int l);
};

#endif