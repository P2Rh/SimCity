#include "maBiblio.h"//
// Created by hugoc on 26/11/2022.
//
int interface(t_ressources* ressources, BITMAP* page, BITMAP* page2, BITMAP* buffer, BITMAP* ChateauEau, BITMAP* CentraleElec, BITMAP* coin, BITMAP* goutte,BITMAP* elec) {

    show_mouse(page);
    blit(page2,page,0,0,0,0,1024,768);
    rectfill(page2,0,0,1024,768,(0,255,0));

    textprintf_ex(page, font, 112, 20, makecol(255, 255, 255), -1, "Nombre habitants: %d", ressources->nbHabitants);
    textprintf_ex(page, font, 300, 20, makecol(255, 255, 255), -1, "Argent: %d",ressources->argent);
    draw_sprite(page,coin,305,20);
    textprintf_ex(page, font, 112, 40, makecol(255, 255, 255), -1, "Capa elec:%d",ressources->capaElec);
    draw_sprite(page,elec,157,40);
    textprintf_ex(page, font, 500, 40, makecol(255, 255, 255), -1, "Capa eau:%d",ressources->capaEau);
    draw_sprite(page,goutte,505,40);



}


