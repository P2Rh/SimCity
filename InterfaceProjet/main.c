#include <stdio.h>
#include "stdlib.h"
#include "allegro.h"

int main() {
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(desktop_color_depth());
    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED,1024,768,0,0))!=0)
    { 	allegro_message("Pb de mode graphique") ;
        allegro_exit();
        exit(EXIT_FAILURE); }
    show_mouse(screen);


    BITMAP* buffer;
    BITMAP* page;
    BITMAP* page2;
    BITMAP* chateauEau;
    BITMAP* centraleElec;
    BITMAP * passer;
    BITMAP* goutteEau;
    BITMAP* argent;

    buffer= create_bitmap(1024,768);
    clear_bitmap(buffer);
    page= create_bitmap(1024,768);
    clear_bitmap(page);
    page2= create_bitmap(1024,768);
    clear_bitmap(page2);
    chateauEau = load_bitmap("CaseChateau.bmp",NULL);
    if(!chateauEau)
    {
        allegro_message("Erreur chargement");

    }
    centraleElec = load_bitmap("CentraleElec3.bmp",NULL);
    if(!centraleElec)
    {
        allegro_message("Erreur chargement");

    }
    passer = load_bitmap("BoutonPasser.bmp",NULL);
    if(!passer)
    {
        allegro_message("Erreur chargement");

    }
    goutteEau = load_bitmap("goutte.bmp",NULL);
    if(!goutteEau)
    {
        allegro_message("Erreur chargement");

    }
    argent= load_bitmap("coin.bmp",NULL);
    if(!argent)
    {
        allegro_message("Erreur chargement");

    }

    textprintf_ex(page,font,2,685,(255,255,255),-1,"Vos informations de jeu: ");
    rectfill(page2,0,0,1024,768,(0,255,0));

    ellipse(page,50,700,50,5,(0,0,0));
    rectfill(page, 52,702,100,710,(255,255,255));
    textprintf_ex(page,font,52,702,(255,255,255),-1,"Argent: %d");
    draw_sprite(page,argent,102,710);

    ellipse(page,300,700,50,5,(0,0,0));
    rectfill(page, 302,702,350,710,(255,255,255));
    textprintf_ex(page,font,302,702,(255,255,255),-1,"Nb habitants: %d");

    ellipse(page,550,700,50,5,(0,0,0));
    rectfill(page, 552,702,600,710,(255,255,255));
    textprintf_ex(page,font,552,702,(255,255,255),-1,"Capa eau: %d");
    draw_sprite(page,goutteEau,610,710);


    ellipse(page,800,700,50,5,(0,0,0));
    rectfill(page, 802,702,850,710,(255,255,255));
    textprintf_ex(page,font,802,702,(255,255,255),-1,"Capa elec: %d");


    ellipse(page,980,600,50,5,(0,0,0));
    rectfill(page, 982,602,1020,610,(255,255,255));
    textprintf_ex(page,font,983,610,(255,255,255),-1,"Niveau 0");

    ellipse(page,980,550,50,5,(0,0,0));
    rectfill(page, 982,552,1020,510,(255,255,255));
    textprintf_ex(page,font,982,510,(255,255,255),-1,"Niveau -1");

    ellipse(page,980,500,50,5,(0,0,0));
    rectfill(page, 982,502,1020,410,(255,255,255));
    textprintf_ex(page,font,983,411,(255,255,255),-1,"Niveau -2");

    draw_sprite(page,centraleElec,980,120);
    draw_sprite(page,chateauEau,980,220);


    blit(buffer,page,0,0,0,0,1024,768);
    blit(page2,page,0,0,0,0,1024,768);
    blit(page,screen,0,0,0,0,1024,768);
    while(!key[KEY_ESC])
    {}
    return 0;
}END_OF_MAIN()