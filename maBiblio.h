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
typedef struct Batiment
{
    int type;
    int load;
    int pop;
    int popMax;
    int eau;
    int elec;
}Batiment;

typedef struct Ville
{
    int argent;
    int pop;
    int elec;
    int eau;
}Ville;
/*----------------------------------------------*/



/*----------------------------------------------*/
///Prototypes
void menuDemarrage();
void choixMode();


/*----------------------------------------------*/


#endif // MABIBLIO_H_INCLUDED
