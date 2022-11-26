#include "maBiblio.h"

/*----------------------------------------------*/
int main()
{
    // Initialisation d'Allegro
    initialisationAllegro();

    BITMAP* page;
    BITMAP* page2;
    BITMAP* buffer;
    BITMAP* coin;
    BITMAP* ChateauEau;
    BITMAP* CentralElec;
    BITMAP* goutte;
    BITMAP* elec;

    page = create_bitmap(1024, 768);
    clear_bitmap(page);
    buffer=create_bitmap(1024, 768);
    clear_bitmap(buffer);
    page2=create_bitmap(1024, 768);
    clear_bitmap(page2);
    coin = load_bitmap("coin.bmp",NULL);
    if(!coin)
    {
        allegro_message("Erreur chargement coin.bmp");
    }

    goutte = load_bitmap("goutte.bmp",NULL);
    if(!goutte)
    {
        allegro_message("Erreur chargement goutte.bmp");
    }

    ChateauEau = load_bitmap("CaseChateau.bmp",NULL);
    if(!ChateauEau)
    {
        allegro_message("Erreur chargement CaseChateau.bmp");
    }

    CentralElec = load_bitmap("CentraleElec3.bmp",NULL);

    if(!CentralElec)
    {
        allegro_message("Erreur chargement CentraleElec3.bmp");
    }
    elec = load_bitmap("elec.bmp",NULL);
    if(!elec)
    {
        allegro_message("elec.bmp");
    }


    //Installation de la souris
    if (install_mouse() == -1)
    {
        textprintf_ex(screen, font, 100, 10, makecol(255,0,0), -1, "Erreur installation de la souris");
        return 1;
    }

    show_mouse(screen); //Permet de montrer la souris à l'écran

    //Lancement menu démarage
    menuDemarrage();
    blit(buffer,screen,0,0,0,0,1024,768);


    return 0;
}END_OF_MAIN();   //Macro de fin Allegro
/*----------------------------------------------*/
