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
void enfiler(t_file *f,int x,int y)
{
    t_maillon* New=(t_maillon*)malloc(sizeof(t_maillon));
    if(f->fin==NULL)
    {f->fin=New;
        f->debut=New;
        New->suiv=NULL;}
    else
    {
        f->fin->suiv=New;
        f->fin=New;
        New->suiv=NULL;

    }
    New->x=x;
    New->y=y;
    f->longueur++;
}
t_maillon* defiler(t_file *f)
{
    t_maillon* temp;
    temp=f->debut;
    if(f->debut==NULL || f->longueur==0)
    {
        printf("FILE VIDE");
        return NULL;
    }
    else{
        if(f->longueur==1)
        {

            f->debut=f->fin=NULL;
            f->longueur--;
            return temp;
        }
        else{

            f->debut=temp->suiv;}
        free(temp);
        f->longueur--;
        return temp;}}

void bfs(t_file *f,Batiment cases[35][45],int z)
{
    t_maillon* temp;
    while(temp!=NULL)
    {temp=defiler(f);
        if(temp!=NULL)
        {printf("\nx=%d et y=%d",temp->x,temp->y);
    for(int x=-1;x<2;x=x+2) {

            if (cases[temp->y][temp->x + x].type == 2 && cases[temp->y][temp->x + x].couleur == 0) {
                enfiler(f, temp->x + x, temp->y);
                cases[temp->y][temp->x+x].couleur = 1;
                cases[temp->y][temp->x+x].coElec = z;

        }
        if(cases[temp->y][temp->x+x].type == 1)
        {
            cases[temp->y][temp->x+x].coElec = z;
            for(int i=0;i<35;i++)
            {
                for(int j=0;j<45;j++)
                {
                    if(cases[i][j].num==cases[temp->y][temp->x+x].num)
                    {
                        cases[i][j].coElec=z;
                    }
                }
            }
            printf("\nConnecte a la centrale %d",z);
        }}
    for (int y = -1; y < 2; y=y+2) {
        if (cases[temp->y+y][temp->x].type == 2 && cases[temp->y +y][temp->x].couleur == 0) {
            enfiler(f, temp->x, temp->y+y);
            cases[temp->y+y][temp->x].couleur = 1;
            cases[temp->y+y][temp->x].coElec = z;
            printf("Check maison x=%d y=%d",temp->x,temp->y+y);
    }
        if(cases[temp->y+y][temp->x].type == 1)
        {
            cases[temp->y+y][temp->x].coElec = z;
            for(int i=0;i<35;i++)
            {
                for(int j=0;j<45;j++)
                {
                    if(cases[i][j].num==cases[temp->y+y][temp->x].num)
                    {
                        cases[i][j].coElec=z;
                    }
                }
            }
        }
    }
}}}
void route(Batiment cases[35][45], BITMAP* roadfront,int i,int j,BITMAP* out, int x, int y)
{
    if(cases[i+1][j].type==2 || cases[i-1][j].type==2 )
    {
        rotate_scaled_sprite(out,roadfront,x,y,64,100);
    }
}
void rempEau(Batiment cases)
{

}
void  rempElec(Batiment cases[35][45],Ville* city)
{
    connect(cases);
    int elec[50];
    for(int i=0;i<50;i++)
    {
        elec[i]=-1;
    }
    for(int i=0;i<city->nbMaisons;i++)
    {
        for(int j=0;j<35;j++)
        {
            for(int k=0;k<45;k++)
            {
                if(cases[j][k].type==1 && elec[cases[j][k].num]==-1)
                {
                    elec[cases[j][k].num]=1;
                }
            }
        }
    }
}
void connect(Batiment cases[35][45])
{
    int elecX[30]={0};
    int elecY[30]={0};
    int nb=0;
    int route=0;
    t_file f;
    t_maillon* temp=NULL;
    f.debut=f.fin=NULL;
    f.longueur=0;
    for(int i=0;i<35;i++)
    {
        for(int j=0;j<45;j++)
        {
            cases[i][j].couleur=0;
            if(cases[i][j].load==3)
            {
               cases[i][j].coElec=nb;
               elecY[nb]=i;
               elecX[nb]=j;
               nb++;
            }
        }
    }
    for(int z=0;z<nb;z++)
    {
        for(int y=-1;y<5;y=y+5)
        {
            for(int x=0;x<6;x++)
            {
                if(cases[elecY[z]+y][elecX[z]+x].type==2)
                {
                    route++;
                    cases[elecY[z]+y][elecX[z]+x].coElec=z;
                    enfiler(&f,elecX[z]+x,elecY[z]+y);
                    cases[elecY[z]+y][elecX[z]+x].couleur=1;
                }
            }
        }
        for(int y=0;y<4;y++)
        {
            for(int x=-1;x<7;x=x+7)
            {
                if(cases[elecY[z]+y][elecX[z]+x].type==2)
                {
                    route++;
                    cases[elecY[z]+y][elecX[z]+x].coElec=z;
                    cases[elecY[z]+y][elecX[z]+x].couleur=1;
                    enfiler(&f,elecX[z]+x,elecY[z]+y);
                }
            }
        }
        if(route!=0)
        {bfs(&f,cases,z);
        }
    }
        }
    //free(f);
BITMAP* Affichage(Batiment cases[35][45],BITMAP* grass,BITMAP* house,BITMAP* roadfront, BITMAP* elec, BITMAP* eau,BITMAP* mapG){
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
void Construction(Batiment cases[35][45],BITMAP* house,BITMAP* mapG,BITMAP* roadfront,BITMAP* elec,BITMAP* eau,Ville* city) //Propose de construire lors de l'activation
{
    BITMAP* buffer= create_bitmap(1024,768);
    int build=0;
    int coli=0;

        int choix=0;
        while (choix==0)
        {
            if(key[KEY_W])
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
                while(!mouse_b & 3)
                {
                    blit(mapG,buffer,0,0,0,0,1024,768);
                    stretch_sprite(buffer, house,pixX()+124,pixY(),60,60);
                    show_mouse(buffer);
                    blit(buffer,screen,0,0,0,0,1024,768);
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
                                cases[y+i][x+j].num=city->nbMaisons;
                                cases[y+i][x+j].type=1;     //Permet d'indiquer l'aire de la maison dans la structure
                                cases[y+i][x+j].load=-1;
                            }
                        }
                        city->nbMaisons++;
                        cases[y][x].load=1;                 //Permet d'afficher le sprite de la maison seulement en haut a gauche
                    }}}
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
                            city->nbCentrales++;
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
        free(buffer);

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
    Ville city;
    city.nbMaisons=0;
    city.nbCentrales=0;
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
    if (!house)
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
            cases[i][j].coElec=-1;
            cases[i][j].connect=NULL;
            //resEau[i][j]=-1;
            //resElec[i][j]=-1;
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
        mapG=Affichage(cases,grass,house,roadfront,elec,eau,mapG); //Affichage de mapG
        blit(mapG,buffer,0,0,0,0,1024,768);
        show_mouse(buffer);
        if(key[KEY_C])
        {
            Construction(cases,house,mapG,roadfront,elec,eau,&city);
            connect(cases);
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
            textprintf_ex(buffer,font,10,10,makecol(255,0,0),-1,"Case x=%d,Case y=%d",pixX()/20,pixY()/20);
            rectfill(buffer,124+pixX(),pixY(),124+pixX()+20,pixY()+20,makecol(255,255,0));
        }
        blit(buffer,screen,0,0,0,0,1024,768);
    }
    return 0;
}END_OF_MAIN()
