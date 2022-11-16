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

    buffer= create_bitmap(1024,768);
    clear_bitmap(buffer);
    page= create_bitmap(1324,1068);
    clear_bitmap(page);
    page2= create_bitmap(1324,1068);
    clear_bitmap(page2);

    textprintf_ex(page,font,2,1070,(255,255,255),-1,"Vos informations de jeu: ");
    rectfill(page2,0,0,1324,1068,(0,255,0));
    ellipse(page,50,1100,50,10,(0,0,0));
    rectfill(page, 52,1102,100,1110,(255,255,255));
    textprintf_ex(page,font,52,1102,(255,255,255),-1,"Argent: %d",);

    ellipse(page,300,1100,50,10,(0,0,0));
    rectfill(page, 302,1102,350,1110,(255,255,255));
    textprintf_ex(page,font,302,1102,(255,255,255),-1,"Nb habitants: %d",);

    ellipse(page,550,1100,50,10,(0,0,0));
    rectfill(page, 552,1102,600,1110,(255,255,255));
    textprintf_ex(page,font,552,1102,(255,255,255),-1,"Capa eau: %d",);

    ellipse(page,800,1100,50,10,(0,0,0));
    rectfill(page, 802,1102,850,1110,(255,255,255));
    textprintf_ex(page,font,52,1102,(255,255,255),-1,"Capa elec: %d",);
    

    blit(buffer,page,0,0,0,0,1024,768);
    blit(page2,page,0,0,0,0,1324,1068);
    blit(page,screen,0,0,0,0,1324,1068);
    while(!key[KEY_ESC])
    {}
    return 0;
}END_OF_MAIN()