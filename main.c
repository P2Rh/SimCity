#include "maBiblio.h"

/*----------------------------------------------*/
int main()
{
    // Initialisation d'Allegro
    initialisationAllegro();

    //Installation de la souris
    if (install_mouse() == -1)
    {
        textprintf_ex(screen, font, 100, 10, makecol(255,0,0), -1, "Erreur installation de la souris");
        return 1;
    }

    show_mouse(screen); //Permet de montrer la souris à l'écran

    //Lancement menu démarage
    menuDemarrage();


    return 0;
}END_OF_MAIN();   //Macro de fin Allegro
/*----------------------------------------------*/
