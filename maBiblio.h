#ifndef MABIBLIO_H_INCLUDED
#define MABIBLIO_H_INCLUDED

///Bibliothèques
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>
/*----------------------------------------------*/


/*----------------------------------------------*/
///Structures
typedef struct ressources{
    int argent;
    int nbHabitants;
    int capaElec;
    int capaEau;
}t_ressources;

typedef struct element{ // Infos du terrain
    int typeElement; // 1= habitation 2= chateau eau, 3=central élec, 4=caserne 5=route
    int nivTerrain; // son niveau (ex: niveau 5= gratte ciel)
    int posX; // num ligne
    int posY; //num colonne
    int dimX;
    int dimY;
    int prix;
    int coRoute;/// 1 si connecté, 0 si non
    int coRouteX;
    int coRouteY;
    int distrib; /// quantité d'eau que le chateau ou la centrale distribue
    int aproElec; ///taux d'approvisionnement élec qui dépend du niveau de l'habitation
    int aproEau; ///taux d'approvisionnement eau qui va depend du niveau de l'habitation
    int usineViste;///0 ou 1
    int maisonVisite;///0 ou 1
}t_element;


/*----------------------------------------------*/



/*----------------------------------------------*/
///Prototypes
void menuDemarrage();
void choixMode();


/*----------------------------------------------*/


#endif // MABIBLIO_H_INCLUDED
