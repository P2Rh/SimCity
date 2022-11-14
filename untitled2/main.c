#include <stdio.h>
#include <allegro.h>

int main() {
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(desktop_color_depth());
    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED,1024,768,0,0))!=0)
    { 	allegro_message("Pb de mode graphique") ;
        allegro_exit();
        exit(EXIT_FAILURE); }
    BITMAP* buffer;
    BITMAP* grass= load_bitmap("Images/grass.bmp",NULL);
    BITMAP* house= load_bitmap("Images/house1.bmp",NULL);
    FILE* map;
    map =fopen("C:\\Users\\stone\\CLionProjects\\untitled2\\cmake-build-debug\\map","r+");
    if(!map)
    {
        allegro_message("erreur fichier texte (map)");
        exit(EXIT_FAILURE);
    }

    int tuile=0;


    if (!grass)
    {
        allegro_message("pas pu trouver images/hotplanet.bmp");
        exit(EXIT_FAILURE);
    }
    buffer= create_bitmap(1024,768);
    clear_bitmap(buffer);
    for(int j=0;j<35;j++)
    {
        for(int i=0;i<45;i++)
        {
            fscanf(map,"%d",&tuile);
            if(tuile==0)
            {stretch_sprite(buffer,grass,124+i*20,j*20,20,20);}
            if(tuile==1)
            {stretch_sprite(buffer,house,124+i*20,j*20,20,20);}
        }
    }

    for(int i=0;i<=45;i++)
    {
        line(buffer,124+i*20,0,124+i*20,700,255);

    }
    for(int i=1;i<=35;i++)
    {
        line(buffer,124,i*20,1024,i*20,255);
    }

    blit(buffer,screen,0,0,0,0,1024,768);
    while(!key[KEY_ESC])
    {}
    return 0;
}END_OF_MAIN()
