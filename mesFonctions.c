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
    imageMenu1 = load_bitmap("Image menu chargement 1.bmp",NULL);

    if (!imageMenu1)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 1.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* imageMenu2;
    imageMenu2 = load_bitmap("Image menu chargement 2.bmp",NULL);

    if (!imageMenu2)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 2.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* imageMenu3;
    imageMenu3 = load_bitmap("Image menu chargement 3.bmp",NULL);

    if (!imageMenu3)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 3.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* imageMenu4;
    imageMenu4 = load_bitmap("Image menu chargement 4.bmp",NULL);

    if (!imageMenu4)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 4.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* imageMenu5;
    imageMenu5 = load_bitmap("Image menu chargement 5.bmp",NULL);

    if (!imageMenu5)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 5.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* imageMenu6;
    imageMenu6 = load_bitmap("Image menu chargement 6.bmp",NULL);

    if (!imageMenu6)
    {
        allegro_message("Nous n'avons pas pu charger \"Image menu chargement 6.bmp\"");
        quitterAllegro();
    }
    /******************************************************************************/
    BITMAP* menuStart;
    menuStart = load_bitmap("menuStart.bmp",NULL);

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
    choixMode = load_bitmap("choixMode.bmp",NULL);

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

            if(mouse_x>=182 && mouse_x<=438 && mouse_y>=456 && mouse_y<=534)
            {
                clic=1;
                //modeCommuniste();
                clear_bitmap(screen);
            }

            //Si bouton 'capitaliste' cliqué -> lancement partie en mode communiste
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