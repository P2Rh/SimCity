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

    rectfill(page2,0,0,1324,1068,(0,255,0));



    blit(buffer,page,0,0,0,0,1024,768);
    blit(page2,page,0,0,0,0,1324,1068);
    blit(page,screen,0,0,0,0,1324,1068);
    while(!key[KEY_ESC])
    {}
    return 0;
}END_OF_MAIN()