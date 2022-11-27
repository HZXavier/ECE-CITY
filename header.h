#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <time.h>

///DECLARATION DES STRUCTURES
typedef struct arc
{
    int arrivee;
    int cout;
}t_arc;

typedef struct sommet
{
  int numero; //indice sommet
  char* ligne;
  char* nom;
  int x;
  int y;
  //listedge_t edges;
  int pcc; //valeur plus court chemin
  int cout;
}t_sommet;

typedef struct graphe
{
    int tailleSommets;
    int tailleArcs;
    t_sommet* tabData;

}t_graphe;


typedef struct batiment
{
    int type;
    int etat;
    int nbHabitant;
    int coutAchat;
    int tailleX;
    int tailleY;
    int numeroCaseX;
    int numeroCaseY;
    int besoinEau;
    int besoinElec;
    int alimEau;
    int alimElec;
    int debitEau;
    int debitElec;
}t_bat;


typedef struct ville
{
    t_bat ttelesmaisonsdelaville[50];
    int habitantTOT;
    int alimEauTot;
    int alimElecTot;
    int ECEflouz;
    int nbBatiment;
}t_ville;

void init_batiment( t_ville * ville);
void init_ville( t_ville *ville);
void sauvegarder_partie( t_ville* ville, int tabarene[35][45]);
void charger_partie( t_ville *ville, int tabarene[35][45], BITMAP * doublebuffer, BITMAP * curseur, int incremente);
void menu_jeu( t_ville* ville, int tabarene[35][45], int incremente);
void affichage_jeu( t_ville* ville, int tabarene[35][45], BITMAP * doublebuffer, BITMAP * curseur);
void affichage_niveauEau( t_ville* ville, int tabarene[35][45], BITMAP * doublebuffer, BITMAP * curseur);
void affichage_niveauElec( t_ville* ville, int tabarene[35][45], BITMAP * doublebuffer, BITMAP * curseur);
void jouer( t_ville* ville, int tabarene[35][45], BITMAP * doublebuffer, BITMAP * curseur, int incremente);
void ajouterBatiment( t_ville *ville, int tabarene[35][45], BITMAP * doublebuffer, BITMAP * curseur);
void menu_debut( t_ville *ville, int tabarene[35][45], BITMAP * doublebuffer, BITMAP * curseur, int incremente);
void delay(float temps);
int verification_placement( int mouse_x,  int mouse_y,int tabarene[35][45], t_ville* ville);
int verif_route( int mouse_x,  int mouse_y,int tabarene[35][45], t_ville* ville);

#endif // HEADER_H_INCLUDED
