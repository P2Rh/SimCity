#ifndef UNTITLED2_LIBRARY_H
#define UNTITLED2_LIBRARY_H
typedef struct Batiment
{
    int type;
    int load;
    int num;
    int pop;
    int popMax;
    int eau;
    int elec;
    int coElec;
    int couleur;
    struct Batiment* connect;
    struct Batiment* suivant;
}Batiment;

typedef struct Ville
{
    int argent;
    int pop;
    int nbMaisons;
    int nbCentrales;
    int elec;
    int eau;

}Ville;

typedef struct maillon{
    int x;
    int y;
    struct maillon *suiv;
}t_maillon;

typedef struct file{
    t_maillon *debut; //pointeur sur le premier maillon
    t_maillon *fin; //pointeur sur le dernier maillon
    int longueur;
}t_file;

typedef struct elec
{
    int x;
    int y;
    int num;
}elec;

elec Centrale[30];
void connect(Batiment cases[35][45])






#endif //UNTITLED3_LIBRARY_H
