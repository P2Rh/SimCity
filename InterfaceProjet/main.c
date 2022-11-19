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
    page= create_bitmap(1324,1068);
    clear_bitmap(page);
    page2= create_bitmap(1324,1068);
    clear_bitmap(page2);
    chateauEau = load_bitmap("CaseChateau.bmp",NULL);
    centraleElec = load_bitmap("CentraleElec3.bmp",NULL);
    passer = load_bitmap("BoutonPasser.bmp",NULL);
    goutteEau = load_bitmap("goutte.bmp",NULL);
    argent= load_bitmap("coin.bmp",NULL);

    textprintf_ex(page,font,2,685,(255,255,255),-1,"Vos informations de jeu: ");
    rectfill(page2,0,0,1324,1068,(0,255,0));

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


    ellipse(page,800,1100,50,5,(0,0,0));
    rectfill(page, 802,1102,850,1110,(255,255,255));
    textprintf_ex(page,font,52,1102,(255,255,255),-1,"Capa elec: %d",);


    ellipse(page,1280,600,50,5,(0,0,0));
    rectfill(page, 1282,602,1320,610,(255,255,255));
    textprintf_ex(page,font,1282,610,(255,255,255),-1,"Niveau 0");

    ellipse(page,1280,550,50,5,(0,0,0));
    rectfill(page, 1282,552,1320,510,(255,255,255));
    textprintf_ex(page,font,1282,510,(255,255,255),-1,"Niveau -1");

    ellipse(page,1280,500,50,5,(0,0,0));
    rectfill(page, 1282,502,1320,510,(255,255,255));
    textprintf_ex(page,font,1282,510,(255,255,255),-1,"Niveau -2");

    draw_sprite(page,centraleElec,1050,120);
    draw_sprite(page,chateauEau,1050,220);


    blit(buffer,page,0,0,0,0,1024,768);
    blit(page2,page,0,0,0,0,1324,1068);
    blit(page,screen,0,0,0,0,1324,1068);
    while(!key[KEY_ESC])
    {}
    return 0;
}END_OF_MAIN()