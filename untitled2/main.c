#include <stdio.h>
#include <allegro.h>
#include "library.h"
int pixX()
{
    return ((mouse_x-124)/20)*20;    ///Retourne la postition de la case actuel (en haut a gauche de la case en coordonnées)
}
int pixY()
{
    return (mouse_y/20)*20;
}
void route(Batiment cases[35][45], BITMAP* roadfront,int i,int j,BITMAP* out, int x, int y)
{
    if(cases[i+1][j].type==2 || cases[i-1][j].type==2 )
    {
        rotate_scaled_sprite(out,roadfront,x,y,64,100);
    }
}
BITMAP* Affichage(Batiment cases[35][45],BITMAP* grass,BITMAP* house,BITMAP* roadfront, BITMAP* elec, BITMAP* eau){
    BITMAP* mapG= create_bitmap(1024,768);
    for(int j=0;j<35;j++)
    {
        for(int i=0;i<45;i++)
        {
            if(cases[j][i].load==0)
            {
                stretch_sprite(mapG,grass,124+i*20,j*20,20,20);
            }
            if(cases[j][i].load==1)
            {
                stretch_sprite(mapG,house,124+i*20,j*20,60,60);
            }
            if(cases[j][i].load==2)
            {
                stretch_sprite(mapG,roadfront,124+i*20,j*20,20,20);
            }
            if(cases[j][i].load==3)
            {
                stretch_sprite(mapG,elec,124+i*20,j*20,120,80);
            }
            if(cases[j][i].load==4)
            {
                stretch_sprite(mapG,eau,124+i*20,j*20,80,120);
            }
        }
    }
    return mapG;
}
void Construction(Batiment cases[35][45],BITMAP* house,BITMAP* mapG,BITMAP* roadfront,BITMAP* elec,BITMAP* eau) //Propose de construire lors de l'activation
{
    BITMAP* buffer= create_bitmap(1024,768);
    int build=0;
    int coli=0;

        int choix=0;
        while (choix==0)
        {
            if(key[KEY_M])
            {
                choix=1;
            }
            if(key[KEY_R])
            {
                choix=2;
            }
            if(key[KEY_E])
            {
                choix=3;
            }
            if(key[KEY_Q])
            {
                choix=4;
            }
        }
        while(build!=1 && !mouse_b & 3)
        {coli=0;
        clear_bitmap(buffer);
        blit(mapG,buffer,0,0,0,0,1024,768);
        switch(choix)
        {
            case 1:
                stretch_sprite(buffer, house,pixX()+124,pixY(),60,60);
                if(mouse_b & 1)  //Si on appuie sur clic gauche
                {
                    for(int i=0;i<3;i++)            //Cherche si il y a des batiments deja construits pour placer la maison
                    {
                        for(int j=0;j<3;j++)
                        {
                            if(cases[pixY()/20+i][pixX()/20+j].type!=0)
                            {
                                coli=1;
                            }
                        }
                    }
                    if(coli==0)                     //Si il n'y a aucune collision, on peut construire
                    {
                        int x=pixX()/20;
                        int y=pixY()/20;
                        build=1;
                        for(int i=0;i<3;i++)
                        {
                            for(int j=0;j<3;j++)
                            {
                                cases[y+i][x+j].type=1;     //Permet d'indiquer l'aire de la maison dans la structure
                                cases[y+i][x+j].load=-1;
                            }
                        }
                        cases[y][x].load=1;                 //Permet d'afficher le sprite de la maison seulement en haut a gauche
                    }}
                break;
            case 2:
                while(!mouse_b & 3)
                {   clear_bitmap(buffer);

                    blit(mapG,buffer,0,0,0,0,1024,768);
                    stretch_sprite(buffer, roadfront,pixX()+124,pixY(),20,20);
                    show_mouse(buffer);
                    blit(buffer,screen,0,0,0,0,1024,768);
                if(mouse_b & 1 )
                {
                    cases[pixY()/20][pixX()/20].type=2;
                    cases[pixY()/20][pixX()/20].load=2;

                }}
                break;
            case 3:
                while(!mouse_b & 3)
                {   clear_bitmap(buffer);

                    blit(mapG,buffer,0,0,0,0,1024,768);
                    stretch_sprite(buffer, elec,pixX()+124,pixY(),120,80);
                    show_mouse(buffer);
                    blit(buffer,screen,0,0,0,0,1024,768);
                if(mouse_b & 1)  //Si on appuie sur clic gauche
                {
                    for(int i=0;i<4;i++)            //Cherche si il y a des batiments deja construits pour placer la maison
                    {
                        for(int j=0;j<6;j++)
                        {
                            if(cases[pixY()/20+i][pixX()/20+j].type!=0)
                            {
                                coli=1;
                            }
                        }
                    }
                        if(coli==0)                     //Si il n'y a aucune collision, on peut construire
                        {
                            int x=pixX()/20;
                            int y=pixY()/20;
                            build=1;
                            for(int i=0;i<4;i++)
                            {
                                for(int j=0;j<6;j++)
                                {
                                    cases[y+i][x+j].type=3;     //Permet d'indiquer l'aire de la maison dans la structure
                                    cases[y+i][x+j].load=-1;
                                }
                            }
                            cases[y][x].load=3;                 //Permet d'afficher le sprite de la maison seulement en haut a gauche
                        }}}
                    break;
                case 4:
                    while(!mouse_b & 3)
                    {   clear_bitmap(buffer);

                        blit(mapG,buffer,0,0,0,0,1024,768);
                        stretch_sprite(buffer, eau,pixX()+124,pixY(),80,120);
                        show_mouse(buffer);
                        blit(buffer,screen,0,0,0,0,1024,768);
                        if(mouse_b & 1)  //Si on appuie sur clic gauche
                        {
                            for(int i=0;i<6;i++)            //Cherche si il y a des batiments deja construits pour placer la maison
                            {
                                for(int j=0;j<4;j++)
                                {
                                    if(cases[pixY()/20+i][pixX()/20+j].type!=0)
                                    {
                                        coli=1;
                                    }
                                }
                            }
                            if(coli==0)                     //Si il n'y a aucune collision, on peut construire
                            {
                                int x=pixX()/20;
                                int y=pixY()/20;
                                build=1;
                                for(int i=0;i<6;i++)
                                {
                                    for(int j=0;j<4;j++)
                                    {
                                        cases[y+i][x+j].type=4;     //Permet d'indiquer l'aire de la maison dans la structure
                                        cases[y+i][x+j].load=-1;
                                    }
                                }
                                cases[y][x].load=4;                 //Permet d'afficher le sprite de la maison seulement en haut a gauche
                            }}}
                break;
                }

                }

        show_mouse(buffer);
        blit(buffer,screen,0,0,0,0,1024,768);

    }


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
    BITMAP* roadfront=load_bitmap("Images/roadfront.bmp",NULL);
    BITMAP* grass= load_bitmap("Images/grass.bmp",NULL);
    BITMAP* house= load_bitmap("Images/house1.bmp",NULL);
    BITMAP* mapG= create_bitmap(1024,768);
    BITMAP* elec= load_bitmap("Images/elec.bmp",NULL);
    BITMAP* eau= load_bitmap("Images/eau.bmp",NULL);
    FILE* map;
    int resEau[35][45];
    int resElec[35][45];
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
    Batiment cases[35][45];
    for(int i=0;i<35;i++)
    {
        for(int j=0;j<45;j++)
        {
            cases[i][j].load=-1;
            resEau[i][j]=-1;
            resElec[i][j]=-1;
        }
    }

    for(int j=0;j<35;j++)                                   //Remplissage de la structure grâce au fichier .txt
    {
        for(int i=0;i<45;i++)
        {
            fscanf(map,"%d",&cases[j][i].type);
            if(cases[j][i].type==0)
            {cases[j][i].load=0;}
            if(cases[j][i].type==1)
            {
                cases[j][i].type=1;
                if(cases[j][i].load==-1)
                {
                    cases[j][i].load=1;
                    cases[j+1][i].load=-2;
                    cases[j+2][i].load=-2;
                    for(int l=0;l<3;l++)
                    {
                        for(int c=1;c<3;c++)
                        {
                            cases[j+l][i+c].load=-2;
                        }
                    }
                }

            }
        }
    }
    blit(mapG,buffer,0,0,0,0,1024,768);
    blit(buffer,screen,0,0,0,0,1024,768);
    while(!key[KEY_ESC])
    {
        clear_bitmap(buffer);
        mapG=Affichage(cases,grass,house,roadfront,elec,eau); //Affichage de mapG
        blit(mapG,buffer,0,0,0,0,1024,768);
        show_mouse(buffer);
        if(key[KEY_C])
        {
            Construction(cases,house,mapG,roadfront,elec,eau);
        }

        /*for(int i=0;i<=45;i++)
        {
            line(buffer,124+i*20,0,124+i*20,700,255);

        }
        for(int i=1;i<=35;i++)
        {
            line(buffer,124,i*20,1024,i*20,255);
        }*/ //Grille
        if(mouse_x>124 && mouse_y<700)  //Séléction de la case
        {
            textprintf_ex(buffer,font,10,10,makecol(255,0,0),-1,"Case x=%d,Case y=%d",mouse_x,mouse_y);
            rectfill(buffer,124+pixX(),pixY(),124+pixX()+20,pixY()+20,makecol(255,255,0));
        }
        blit(buffer,screen,0,0,0,0,1024,768);
    }
    return 0;
}END_OF_MAIN()
