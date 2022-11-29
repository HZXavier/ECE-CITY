#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <time.h>

/// DECLARATION DES STRUCTURES

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
    int sommets[];

}t_bat;

typedef struct arc
{
    int arrivee;
    int cout;
} t_arc;

typedef struct maillon
{
    t_arc arc;
    struct maillon* next;
} maillon;

typedef struct sommet
{
    int numero; // indice sommet
    t_arc arcs;
    int pcc; // valeur plus court chemin
} t_sommet;

typedef struct graphe
{
    int tailleSommets;
    int tailleArcs;
    t_sommet* tabData[];

} t_graphe;

typedef struct ville
{
    int mode;
    t_bat ttelesmaisonsdelaville[100];
    int habitantTOT;
    int alimEauTot;
    int alimElecTot;
    int besoinEauTot;
    int besoinElecTot;
    int ECEflouz;
    int nbBatiment;
    int nbRoute;

} t_ville;

// prototypes des fonctions
t_arc init_liaisonlist();
void ajoutEnPremier(t_arc, maillon);
t_arc init_arc(int arrivee, int cout);
t_graphe init_graph(int nombreSommets, int nombresArcs);
void ajoutSommet(t_graphe graphe, t_sommet sommet);
void ajoutBat(t_graphe, t_bat batiment); //crée plusieurs sommets pour les batiments qui font plusieurs cases
t_sommet init_sommet(t_bat);
void ajoutArc(t_arc arc, t_sommet sommet);
void dijkstra(int depart, t_graphe graphe);
void majEau(t_bat chateau, t_ville ville);
void majElec(t_bat centrale, t_ville ville);

void init_batiment(t_ville *ville);
void init_ville(t_ville *ville);
void sauvegarder_partie(t_ville *ville, int tabarene[35][45]);
void charger_partie(t_ville *ville, int tabarene[35][45], BITMAP *doublebuffer, BITMAP *curseur, int incremente);
void menu_jeu(t_ville *ville, int tabarene[35][45], int incremente);
void affichage_jeu(t_ville *ville, int tabarene[35][45], BITMAP *doublebuffer, BITMAP *curseur);
void affichage_niveauEau(t_ville *ville, int tabarene[35][45], BITMAP *doublebuffer, BITMAP *curseur);
void affichage_niveauElec(t_ville *ville, int tabarene[35][45], BITMAP *doublebuffer, BITMAP *curseur);
void jouer(t_ville *ville, int tabarene[35][45], BITMAP *doublebuffer, BITMAP *curseur, int incremente);
void ajouterBatiment(t_ville *ville, int tabarene[35][45], BITMAP *doublebuffer, BITMAP *curseur);
void menu_debut(t_ville *ville, int tabarene[35][45], BITMAP *doublebuffer, BITMAP *curseur, int incremente);
void delay(float temps);

int verification_placement(int mouse_x, int mouse_y, int tabarene[35][45], t_ville *ville);
int verif_route(int mouse_x, int mouse_y, int tabarene[35][45], t_ville *ville);

#endif // HEADER_H_INCLUDED
