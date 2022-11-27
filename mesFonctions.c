#include "maBiblio.h"

/*-----------------------------------------------------------------------------------------------------*/
///Petits sous-programmes pour éviter les répétitions

//Fonction pour quitter Allegro (pour éviter de réécrire à chaque fois)
void initialisationAllegro()
{
    allegro_init();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1024,768,0,0)!=0)
    {
        allegro_message("Probleme graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}
/*----------------------------------------------------------------------------*/
//Fonction pour quitter Allegro
void quitterAllegro()
{
    allegro_exit();
    exit(EXIT_FAILURE);
}
/*----------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------*/
///Fonction pour quitter le jeu à tout moment
void exitJeu()
{
    int clic=0;
    clear_bitmap(screen);

    //Création double buffer fond noir
    /******************************************************************************/
    BITMAP* bitmapFondNoir;
    bitmapFondNoir = create_bitmap(SCREEN_W,SCREEN_H);

    clear_bitmap(bitmapFondNoir);

    /******************************************************************************/

    //Affichage boutons quitter 'oui' ou 'non'
    /******************************************************************************/
    BITMAP* boutonOui;
    boutonOui = load_bitmap("BoutonOui.bmp",NULL);

    if (!boutonOui)
    {
        allegro_message("Nous n'avons pas pu charger \"BoutonOui.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* boutonNon;
    boutonNon = load_bitmap("BoutonNon.bmp",NULL);

    if (!boutonNon)
    {
        allegro_message("Nous n'avons pas pu charger \"BoutonNon.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/

    //Affichage sur la bitmap choisie
    textout_centre_ex(bitmapFondNoir, font, "Es-tu sur de vouloir quitter notre superbe jeu ?", 510, 200, makecol(255, 255, 255), -1);
    draw_sprite(bitmapFondNoir, boutonOui, 415, 300);
    // draw_sprite(bitmapFondNoir, boutonNon, 600, 300);

    //On copie le double buffer dans screen
    blit(bitmapFondNoir,screen, 0, 0, 0, 0, 1024, 768);

    while (clic == 0){

        if (mouse_b & 1)   //Si clic gauche souris cliqué
        {
            //Si bouton 'Oui' cliqué -> quitte le jeu
            if(mouse_x>=400 && mouse_x<=639 && mouse_y>=305 && mouse_y<=515)
            {
                //allegro_message("Dommage! A la prochaine");
                quitterAllegro();
            }

            ///Annuler 'quitter la partie' ne marche pas
            /*
                //Si bouton 'Non' cliqué -> partie reprend
                if(mouse_x>=600 && mouse_x<=859 && mouse_y>=305 && mouse_y<=515)
                {
                    sleep(3);
                    clear_bitmap(screen);
                }
            }
            */
        }
    }
}
/*-----------------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------*/
///Lancement du jeu
void menuDemarrage()
{
    int clic=0;
    show_mouse(screen);   //Affichage curseur souris

    /******************************************************************************/   //Création / chargement bitmaps
    BITMAP* imageMenu1;
    imageMenu1 = load_bitmap("Images/Image menu chargement 1.bmp",NULL);

    if (!imageMenu1)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 1.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* imageMenu2;
    imageMenu2 = load_bitmap("Images/Image menu chargement 2.bmp",NULL);

    if (!imageMenu2)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 2.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* imageMenu3;
    imageMenu3 = load_bitmap("Images/Image menu chargement 3.bmp",NULL);

    if (!imageMenu3)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 3.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* imageMenu4;
    imageMenu4 = load_bitmap("Images/Image menu chargement 4.bmp",NULL);

    if (!imageMenu4)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 4.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* imageMenu5;
    imageMenu5 = load_bitmap("Images/Image menu chargement 5.bmp",NULL);

    if (!imageMenu5)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 5.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* imageMenu6;
    imageMenu6 = load_bitmap("Images/Image menu chargement 6.bmp",NULL);

    if (!imageMenu6)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 6.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* menuStart;
    menuStart = load_bitmap("Images/menuStart.bmp",NULL);

    if (!menuStart)
    {
        allegro_message("Nous n'avons pas pu charger \"menuStart.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/


    //******************************************************************************//
    //Affichage bitmaps
    blit(imageMenu1,screen, 0, 0, 0, 0, 1024, 768);
    //textout_centre_ex(screen, font, "Chargement.", 512, 384, makecol(0, 0, 0), -1);
    sleep(1);  //Pause de 1s

    clear_bitmap(screen);
    blit(imageMenu2,screen, 0, 0, 0, 0, 1024, 768);
    //textout_centre_ex(screen, font, "Chargement..", 512, 384, makecol(0, 0, 0), -1);
    sleep(1);

    clear_bitmap(screen);
    blit(imageMenu3,screen, 0, 0, 0, 0, 1024, 768);
    //textout_centre_ex(screen, font, "Chargement...", 512, 384, makecol(0, 0, 0), -1);
    sleep(1);

    clear_bitmap(screen);
    blit(imageMenu4,screen, 0, 0, 0, 0, 1024, 768);
    //textout_centre_ex(screen, font, "Chargement.", 512, 384, makecol(0, 0, 0), -1);
    sleep(1);

    clear_bitmap(screen);
    blit(imageMenu5,screen, 0, 0, 0, 0, 1024, 768);
    //textout_centre_ex(screen, font, "Chargement..", 512, 384, makecol(0, 0, 0), -1);
    sleep(1);

    clear_bitmap(screen);
    blit(imageMenu6,screen, 0, 0, 0, 0, 1024, 768);
    //textout_centre_ex(screen, font, "Chargement...", 512, 384, makecol(0, 0, 0), -1);
    sleep(1);

    clear_bitmap(screen);
    blit(menuStart,screen, 0, 0, 0, 0, 1024, 768);
    //textout_centre_ex(screen, font, "Appuyez sur 'Start' pour commencer", 512, 400, makecol(255, 255, 255), -1);
    //******************************************************************************//

    //Suppresion des anciennes bitmaps
    destroy_bitmap(imageMenu1);
    destroy_bitmap(imageMenu2);
    destroy_bitmap(imageMenu3);
    destroy_bitmap(imageMenu4);
    destroy_bitmap(imageMenu5);
    destroy_bitmap(imageMenu6);


    //Utilisation de la souris sur les boutons (boucle)
    while (clic == 0){
        //Si clic gauche souris cliqué
        if (mouse_b & 1)
        {
/*
        //Affichage des coordonnées de la souris à l’écran graphique
        textprintf_ex(screen, font, 0, 20, makecol(255, 255, 255),makecol(0,0,0), "Coordonnees de la souris en y : %4d et en x : %4d", mouse_y, mouse_x);
*/
            //Si bouton 'Nouvelle partie cliqué" -> lance le choix du mode de jeu
            if(mouse_x>=384 && mouse_x<=647 && mouse_y>=267 && mouse_y<=335)
            {
                clic=1;
                choixMode();
                clear_bitmap(screen);
            }

            //Si bouton 'Charger partie' cliqué -> charge une partie jouée
            if(mouse_x>=384 && mouse_x<=647 && mouse_y>=363 && mouse_y<=434)
            {
                clic=1;
                //chargerPartie();
                clear_bitmap(screen);
            }

            //Si bouton 'Options' cliqué -> lance les options du jeu
            if(mouse_x>=384 && mouse_x<=647 && mouse_y>=463 && mouse_y<=530)
            {
                clic=1;
                //optionsJeu();
                clear_bitmap(screen);
            }

            //Si bouton 'Crédits' cliqué -> affiche les crédits du jeu
            if(mouse_x>=384 && mouse_x<=647 && mouse_y>=555 && mouse_y<=625)
            {
                clic=1;
                //creditsJeu();
                clear_bitmap(screen);
            }

            //Si bouton 'exit' cliqué -> quitte le jeu
            if(mouse_x>=384 && mouse_x<=647 && mouse_y>=650 && mouse_y<=717)
            {
                clic=1;
                //exitJeu();
                clear_bitmap(screen);
            }
        }
    }
}
/*-----------------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------*/
///Lancement du jeu (chargement, choix des joueurs,...)
void choixMode()
{
    int clic = 0;
    show_mouse(screen);   //Affichage curseur souris

    /******************************************************************************/   //Création / chargement bitmaps
    BITMAP* choixMode;
    choixMode = load_bitmap("Images/choixMode.bmp",NULL);

    if (!choixMode)
    {
        allegro_message("Nous n'avons pas pu charger \"choixMode.bmp\"");
        quitterAllegro();
    }
    //******************************************************************************//
    //Affichage bitmaps
    clear_bitmap(screen);
    blit(choixMode,screen, 0, 0, 0, 0, 1024, 768);
    sleep(1);
    //******************************************************************************//

    //Utilisation de la souris sur les boutons (boucle)
    while (clic == 0){
        //Si clic gauche souris cliqué
        if (mouse_b & 1)
        {
            //Si bouton 'capitaliste' cliqué -> lancement partie en mode capitaliste
            if(mouse_x>=182 && mouse_x<=438 && mouse_y>=456 && mouse_y<=534)
            {
                clic=1;
                //
                clear_bitmap(screen);
            }

            //Si bouton 'communiste' cliqué -> lancement partie en mode communiste
            if(mouse_x>=603 && mouse_x<=860 && mouse_y>=456 && mouse_y<=534)
            {
                clic=1;
                //modeCapitaliste();
                clear_bitmap(screen);
            }
        }
    }
}
/*-----------------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------*/
///Coordonnées
int pixX()
{
    return ((mouse_x-124)/20)*20;    ///Retourne la postition de la case actuel (en haut a gauche de la case en coordonnées)
}
int pixY()
{
    return (mouse_y/20)*20;
}
/*-----------------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------*/
///Tracé de la route
void route(Batiment cases[35][45], BITMAP* roadfront,int i,int j,BITMAP* out, int x, int y)
{
    if(cases[i+1][j].type==2 || cases[i-1][j].type==2 )
    {
        rotate_scaled_sprite(out,roadfront,x,y,64,100);
    }
}
/*-----------------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------*/
BITMAP* Affichage(Batiment cases[35][45],BITMAP* grass,BITMAP* house,BITMAP* roadfront, BITMAP* elec, BITMAP* eau){
    BITMAP* mapG= create_bitmap(1024,768);

    //Arrière plan du jeu
    BITMAP* fond= load_bitmap("Images/fond.bmp",NULL);
    blit(fond,mapG,0,0,0,0,1024,768);

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
/*-----------------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------*/
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
/*-----------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------*/
void initVille(Ville* maVille)
{
    maVille -> argent = 500000;
    maVille -> pop = 0;
    maVille -> elec = 0;
    maVille -> eau = 0;
}
/*-----------------------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------------------*/
void statsVille(Ville* maVille, BITMAP* buffer)
{
    //textprintf_ex(page,font,500,20,makecol(255,255,255),-1,"Temps de jeu: %d:%d:%.0f",); // Temps
    textprintf_ex(buffer,font,200,740,makecol(255,255,255),-1,"%d ECE Flouz", maVille -> argent);
    textprintf_ex(buffer,font,350,740,makecol(255,255,255),-1,"%d",maVille -> pop);
    textprintf_ex(buffer,font,595,740,makecol(255,255,255),-1,"%d",maVille -> elec);
    textprintf_ex(buffer,font,880,740,makecol(255,255,255),-1,"%d",maVille -> eau);
}
/*-----------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------------*/
void boucleJeu(Ville* maVille)
{
    FILE* map;
    BITMAP* buffer;
    BITMAP* roadfront=load_bitmap("Images/roadfront.bmp",NULL);
    BITMAP* grass= load_bitmap("Images/grass.bmp",NULL);
    BITMAP* house= load_bitmap("Images/house1.bmp",NULL);
    BITMAP* mapG= create_bitmap(1024,768);
    BITMAP* elec= load_bitmap("Images/elec.bmp",NULL);
    BITMAP* eau= load_bitmap("Images/eau.bmp",NULL);
    int resEau[35][45];
    int resElec[35][45];
    int tuile=0;

    map =fopen("C:\\Users\\cleme\\Documents\\Codes\\untitled2\\cmake-build-debug\\map","r+");

    if(!map)
    {
        allegro_message("Erreur fichier texte (map) / verifier chemin acces");
        exit(EXIT_FAILURE);
    }

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
/*
    blit(mapG,buffer,0,0,0,0,1024,768);
    blit(buffer,screen,0,0,0,0,1024,768);
    blit(fond,buffer,0,0,0,0,1024,768);
*/
    while(!key[KEY_ESC])
    {
       // textprintf_ex(screen, font, 0, 20, makecol(255, 255, 255),makecol(0,0,0), "Coordonnees de la souris en y : %4d et en x : %4d", mouse_y, mouse_x);

        clear_bitmap(buffer);
        mapG=Affichage(cases,grass,house,roadfront,elec,eau); //Affichage de mapG
        blit(mapG,buffer,0,0,0,0,1024,768);

        statsVille(maVille,buffer);

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
}
/*-----------------------------------------------------------------------------------------------------*/