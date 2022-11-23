#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <time.h>

///DECLARATION DES STRUCTURES

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

///INITIALISATION DES STRUCTURES

void init_batiment( t_ville * ville)
{
    if(ville->ttelesmaisonsdelaville[ville->nbBatiment].type == 0)//Cas d'un terrain vague
    {
        ville->ttelesmaisonsdelaville[ville->nbBatiment].coutAchat = 1000;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX = 3;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY = 3;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].debitEau = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].debitElec = 0;
    }
    if(ville->ttelesmaisonsdelaville[ville->nbBatiment].type == 1)//Cas d'une centrale
    {
        ville->ttelesmaisonsdelaville[ville->nbBatiment].coutAchat = 100000;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX = 4;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY = 6;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].nbHabitant = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].debitEau = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].debitElec = 5000;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].etat = 5;
    }
    if(ville->ttelesmaisonsdelaville[ville->nbBatiment].type == 2)//Cas d'un chateau d'eau
    {
        ville->ttelesmaisonsdelaville[ville->nbBatiment].coutAchat = 100000;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX = 4;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY = 6;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].nbHabitant = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].debitEau = 5000;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].debitElec = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].etat = 6;
    }
    if(ville->ttelesmaisonsdelaville[ville->nbBatiment].type == 3)//Cas d'une route
    {
        ville->ttelesmaisonsdelaville[ville->nbBatiment].coutAchat = 10;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX = 1;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY = 1;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].nbHabitant = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].debitEau = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].debitElec = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].etat = 0;
    }
    if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 0)
    {
        ville->ttelesmaisonsdelaville[ville->nbBatiment].besoinEau = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].besoinElec = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].nbHabitant = 0;
    }
    if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 1)
    {
        ville->ttelesmaisonsdelaville[ville->nbBatiment].besoinEau = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].besoinElec = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].nbHabitant = 10;
    }
    if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 2)
    {
        ville->ttelesmaisonsdelaville[ville->nbBatiment].besoinEau = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].besoinElec = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].nbHabitant = 50;
    }
    if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 3)
    {
        ville->ttelesmaisonsdelaville[ville->nbBatiment].besoinEau = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].besoinElec = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].nbHabitant = 100;
    }
    if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 4)
    {
        ville->ttelesmaisonsdelaville[ville->nbBatiment].besoinEau = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].besoinElec = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].nbHabitant = 1000;
    }
    if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 5)
    {
        ville->ttelesmaisonsdelaville[ville->nbBatiment].besoinEau = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].besoinElec = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].nbHabitant = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].alimElec = 5000;
    }
    if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 6)
    {
        ville->ttelesmaisonsdelaville[ville->nbBatiment].besoinEau = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].besoinElec = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].nbHabitant = 0;
        ville->ttelesmaisonsdelaville[ville->nbBatiment].alimEau = 5000;
    }
}

void init_ville(t_ville *ville)
{
    ville->ECEflouz = 500000;
    ville->habitantTOT = 0;
    ville->nbBatiment=0;
}

///ACTUALISATION DES DONNEES



///SOUS-PROGRAMMES

int temps()
{
    clock_t t1;
    clock_t t2;
    int temps;
    t2 = clock() - t1;
    temps = t2/CLOCKS_PER_SEC;
    return(temps);
}

/*int algo_connexite( t_souris  t_bat t_ville ville, int tabarene[35][45], int* i)
{
    int tmp = *i;
    int connexe = 0;
    for(int clebouX ; clebouX < ville.ttelesmaisonsdelaville[tmp].tailleX ; clebouX ++)
    {
        for(int clebouY ; clebouY < ville.ttelesmaisonsdelaville[tmp].tailleX ; clebouY ++)
        {
            if(tabarene[ville.ttelesmaisonsdelaville[tmp].numeroCaseX+clebouX][ville.ttelesmaisonsdelaville[tmp].numeroCaseY-1] == 1);
            {
                connexe = 1;
            }
            if(tabarene[ville.ttelesmaisonsdelaville[tmp].numeroCaseX+ville.ttelesmaisonsdelaville[tmp].tailleX][ville.ttelesmaisonsdelaville[tmp].numeroCaseY+clebouY] == 1)
            {
                connexe = 1;
            }
            if(tabarene[ville.ttelesmaisonsdelaville[tmp].numeroCaseX+clebouX-1][ville.ttelesmaisonsdelaville[tmp].numeroCaseY+ville.ttelesmaisonsdelaville[tmp].tailleY] == 1)
            {
                connexe = 1;
            }
            if(tabarene[ville.ttelesmaisonsdelaville[tmp].numeroCaseX-1][ville.ttelesmaisonsdelaville[tmp].numeroCaseY+clebouY-1] == 1)
            {
                connexe = 1;
            }
        }
    }
    return(connexe);
}*/

void sauvegarder_partie( t_ville* ville, int tabarene[35][45])
{
    FILE * sauvegarder = NULL;
    sauvegarder = fopen("partie_sauvegarde.txt","w");
    fprintf(sauvegarder, "%d\n",ville->nbBatiment);
    fprintf(sauvegarder, "%d\n",ville->ECEflouz);
    fprintf(sauvegarder, "%d\n",ville->habitantTOT);
    for(int j=0 ; j < ville->nbBatiment ; j++)
    {
        fprintf(sauvegarder, "%d\n",ville->ttelesmaisonsdelaville[j].alimEau);
        fprintf(sauvegarder, "%d\n",ville->ttelesmaisonsdelaville[j].alimElec);
        fprintf(sauvegarder, "%d\n",ville->ttelesmaisonsdelaville[j].besoinEau);
        fprintf(sauvegarder, "%d\n",ville->ttelesmaisonsdelaville[j].besoinElec);
        fprintf(sauvegarder, "%d\n",ville->ttelesmaisonsdelaville[j].coutAchat);
        fprintf(sauvegarder, "%d\n",ville->ttelesmaisonsdelaville[j].debitEau);
        fprintf(sauvegarder, "%d\n",ville->ttelesmaisonsdelaville[j].debitElec);
        fprintf(sauvegarder, "%d\n",ville->ttelesmaisonsdelaville[j].etat);
        fprintf(sauvegarder, "%d\n",ville->ttelesmaisonsdelaville[j].nbHabitant);
        fprintf(sauvegarder, "%d\n",ville->ttelesmaisonsdelaville[j].numeroCaseX);
        fprintf(sauvegarder, "%d\n",ville->ttelesmaisonsdelaville[j].numeroCaseY);
        fprintf(sauvegarder, "%d\n",ville->ttelesmaisonsdelaville[j].tailleX);
        fprintf(sauvegarder, "%d\n",ville->ttelesmaisonsdelaville[j].tailleY);
    }
    fclose(sauvegarder);
}

void menu_jeu( t_ville* ville, int tabarene[35][45], int incremente)//rentre dans ce sous programme lorsque auparavant l'utilisateur appuie sur echap
{
    BITMAP * boutonReprendre;
    BITMAP * boutonQuitter;
    BITMAP * boutonSauvegarder;
    BITMAP * fondmenu;
    BITMAP * curseur;
    boutonQuitter = load_bitmap("BTQ.bmp",NULL);
    boutonReprendre = load_bitmap("BTRPE.bmp",NULL);
    boutonSauvegarder = load_bitmap("BTSVG.bmp",NULL);
    fondmenu = load_bitmap("FondMenu.bmp",NULL);
    curseur = load_bitmap("Curseur.bmp",NULL);
    BITMAP * doublebuffer =create_bitmap(1024,768);
    int quitter=0;
    while(quitter==0)
    {
        blit(fondmenu,doublebuffer,0,0,0,0,1024,768);
        masked_blit(boutonReprendre,doublebuffer,0,0,400,350,400+boutonQuitter->w,350+boutonQuitter->h);
        masked_blit(boutonSauvegarder,doublebuffer,0,0,400,450,400+boutonSauvegarder->w,450+boutonSauvegarder->h);
        masked_blit(boutonQuitter,doublebuffer,0,0,400,550,400+boutonQuitter->w,550+boutonQuitter->h);
        if(mouse_b&1)
        {
            if(mouse_x>400 && mouse_x<400 + boutonReprendre->w && mouse_y>350 &&  mouse_y<350 + boutonReprendre->h)//clique sur le bouton reprendre
            {
                printf("jouer");
                quitter=1;//quitte le while et reprend dans le sous  prog jouer
            }
            if(mouse_x>400 && mouse_x<400 + boutonSauvegarder->w && mouse_y>450 &&  mouse_y<450 + boutonSauvegarder->h)//clique sur le bouton sauvegarder
            {
                printf("sauvegarde");
                //exit(0);
                sauvegarder_partie( ville, tabarene);
                quitter=1;
            }
            if(mouse_x>400 && mouse_x<400 + boutonQuitter->w && mouse_y>550 &&  mouse_y<550 + boutonQuitter->h)//clique sur le bouton quitter
            {
                allegro_exit();
            }
        }
        masked_blit(curseur, doublebuffer, 0, 0, mouse_x, mouse_y, 1024, 768); // affiche le curseur
        blit(doublebuffer,screen,0,0,0,0,1024,768);
    }
    destroy_bitmap(doublebuffer);
    destroy_bitmap(boutonQuitter);
    destroy_bitmap(boutonReprendre);
    destroy_bitmap(boutonSauvegarder);
}

void ajouterBatiment( t_ville *ville, int tabarene[35][45], BITMAP * doublebuffer, BITMAP * curseur)
{
    delay(0.1);
    init_batiment(ville);
    int sortie = 0;
    while(sortie == 0)//Permet de rester dans le programme tant que le joueur n'a pas cliqué sur le batiment qu'il veut poser
    {
        affichage_jeu( ville, tabarene, doublebuffer, curseur);
        if(mouse_b&1)
        {
            if(mouse_x >= 0 && mouse_x <= 900 && mouse_y >= 0 && mouse_y <= 700)
            {
                int clique_x=mouse_x;
                int clique_y=mouse_y;
                if(ville->ECEflouz >= ville->ttelesmaisonsdelaville[ville->nbBatiment].coutAchat)
                {
                    int tmp=0;
                    int tmp2=0;
                    tmp  =verification_placement(clique_x,clique_y,tabarene,ville);
                    tmp2 = verif_route(clique_x,clique_y,tabarene,ville);
                    if (tmp ==0 && (tmp2 !=0 ||ville->ttelesmaisonsdelaville[ville->nbBatiment].type==3))
                    {
                        ville->ECEflouz = ville->ECEflouz - ville->ttelesmaisonsdelaville[ville->nbBatiment].coutAchat;
                        ville->habitantTOT = ville->habitantTOT + ville->ttelesmaisonsdelaville[ville->nbBatiment].nbHabitant;
                        ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX = mouse_x/20;
                        ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY = mouse_y/20;
                        for(int i = 0 ; i<ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY ; i++)
                        {
                            for(int j = 0 ; j<ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX ; j++)
                            {
                                if(ville->ttelesmaisonsdelaville[ville->nbBatiment].type==3)//si le batiment à placer est une route on met les cases couverte à 2
                                    tabarene[ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+i][ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+j] = 2;
                                else
                                    tabarene[ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+i][ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+j] = 1;
                            }
                        }
                        ville->nbBatiment += 1;
                        affichage_jeu( ville, tabarene, doublebuffer, curseur);
                    }
                }
            }
            sortie = 1;
        }
    }
     for (int i=0 ; i<35 ; i++)
    {
        for (int j = 0 ; j<45 ; j++)
        {
           printf("%d " ,tabarene[i][j]);
        }
        printf("\n");
    }
}

int verification_placement( int mouse_x,  int mouse_y,int tabarene[35][45], t_ville* ville)
{
    int case_x = mouse_x/20;
    int case_y = mouse_y/20;
    int tmp=0;
    for(int y=0;y<ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY;y++)
    {
        for(int x=0;x<ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX;x++)
        {
            if(tabarene[case_y+y][case_x+x]==1)
                tmp+=1;
        }
    }
    return tmp;
}


int verif_route( int mouse_x,  int mouse_y,int tabarene[35][45], t_ville* ville)
{
    int case_x = mouse_x/20;
    int case_y = mouse_y/20;
    int tmp1=0;
    for(int y=case_y-1;y<case_y + ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY+1;y++)//segment x le plus à gauche x fixe ,tailley<y<tailley+y
    {
        if(tabarene[y][case_x-1]==2)
            tmp1+=1;
    }
    for(int y=case_y-1;y<case_y + ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY+1;y++)//segment x le plus à droite x fixe ,tailley<y<tailley+y
    {
        if(tabarene[y][case_x+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX]==2)
            tmp1+=1;
    }
    for(int x=case_x-1;x<case_x +ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX+1;x++)//segment y le plus haut  y fixe ,taillex<x<taillex+x
    {
        if(tabarene[case_y-1][x]==2)
            tmp1+=1;
    }
    for(int x=case_x-1;x<case_x + ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX+1;x++)//segment y le plus bas  y fixe ,taillex<x<taillex+x
    {
        if(tabarene[case_y+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY][x]==2)
            tmp1+=1;
    }


    return tmp1;
}





void affichage_jeu( t_ville* ville, int tabarene[35][45], BITMAP * doublebuffer, BITMAP * curseur)
{
    //printf("affichage : argent : %d, habitants : %d batiments : %d\n",ville->ECEflouz,ville->habitantTOT, ville->nbBatiment);

    BITMAP * cabane;
    BITMAP * maison;
    BITMAP * gratteCiel;
    BITMAP * centrale;
    BITMAP * chateauEau;
    BITMAP * immeuble;
    BITMAP * terrainVague;
    BITMAP * route;
    BITMAP * map;
    BITMAP * parametre;
    BITMAP * boutonmoinsun;
    BITMAP * boutonmoinsdeux;
    BITMAP * pause;
    pause = load_bitmap("BoutonPause.bmp",NULL);
    boutonmoinsun = load_bitmap ("Bouton-1.bmp",NULL);
    boutonmoinsdeux = load_bitmap ("Bouton-2.bmp",NULL);
    cabane= load_bitmap("Cabane.bmp",NULL);
    maison= load_bitmap("Maison.bmp",NULL);
    gratteCiel= load_bitmap("GratteCiel.bmp",NULL);
    centrale= load_bitmap("CentraleElectrique.bmp",NULL);
    chateauEau= load_bitmap("ChateauEau.bmp",NULL);
    immeuble= load_bitmap("Immeuble.bmp",NULL);
    terrainVague= load_bitmap("TerrainVague.bmp",NULL);
    route= load_bitmap("Route.bmp",NULL);
    map = load_bitmap("MapSimCity.bmp",NULL);
    parametre = load_bitmap("Engrenage.bmp",NULL);
    masked_blit(boutonmoinsun, doublebuffer, 0, 0, 944, 0, 984, 40);
    masked_blit(boutonmoinsdeux, doublebuffer, 0, 0, 904, 0, 944, 40);
    rectfill(doublebuffer, 0,0,1024,768, makecol( 0, 0, 112));
    masked_blit(map, doublebuffer, 0, 0, 0, 0, 900, 700);
    masked_blit(maison, doublebuffer, 0, 0, 940, 100, 940+60, 100+60);
    rect(doublebuffer, 940, 100, 940+60, 100+60, makecol(255, 0, 0));
    masked_blit(centrale, doublebuffer, 0, 0, 930, 200, 930+80, 200+120);
    rect(doublebuffer, 930, 200, 930+80, 200+120, makecol(255, 0, 0));
    masked_blit(chateauEau, doublebuffer, 0, 0, 930, 360, 930+80, 360+120);
    rect(doublebuffer, 930, 360, 930+80, 360+120, makecol(255, 0, 0));
    masked_blit(route, doublebuffer, 0, 0, 960, 520, 960+20, 520+20);
    rect(doublebuffer, 960, 520, 960+20, 520+20, makecol(255, 0, 0));
    masked_blit(parametre, doublebuffer, 0, 0, 984, 0, 1024, 40);
    masked_blit(boutonmoinsun, doublebuffer, 0, 0, 944, 0, 984, 40);
    masked_blit(boutonmoinsdeux, doublebuffer, 0, 0, 904, 0, 944, 40);
    masked_blit(pause, doublebuffer, 0, 0, 904, 40, 944, 80);
    textprintf_ex(doublebuffer, font, 100, 705, makecol(255, 255,255), -1, "ARGENT : %d", ville->ECEflouz);
    textprintf_ex(doublebuffer, font, 300, 705, makecol(255, 255, 255), -1, "NOMBRE HABITANTS : %d", ville->habitantTOT);
    textprintf_ex(doublebuffer, font, 500, 705, makecol(255, 255, 255), -1, "NOMBRE BATIMENTS : %d", ville->nbBatiment);
    int compteur = temps();
    textprintf_ex(doublebuffer, font, 1010, 60, makecol(255, 255, 255), -1, "%d", compteur);
    for(int i=0;i<46;i++)
    {
        for(int j=0;j<36;j++)
        {
            rect(doublebuffer,0,0,20*i,20*j,makecol(0,0,0));
        }
    }
    if(ville->nbBatiment >> 1)
    {
        for(int k = 0; k<ville->nbBatiment ; k++)
        {
            if(ville->ttelesmaisonsdelaville[k].type == 0)//habitation
            {
                 if(ville->ttelesmaisonsdelaville[k].etat == 0)//terrain vague
                {
                    masked_blit(terrainVague, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
                }
                 if(ville->ttelesmaisonsdelaville[k].etat == 1)//cabane
                {
                    masked_blit(cabane, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
                }
                 if(ville->ttelesmaisonsdelaville[k].etat == 2)//maison
                {
                    masked_blit(maison, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
                }
                 if(ville->ttelesmaisonsdelaville[k].etat == 3)//immeuble
                {
                    masked_blit(immeuble, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
                }
                 if(ville->ttelesmaisonsdelaville[k].etat == 4)//gratte ciel
                {
                    masked_blit(gratteCiel, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
                }
            }
            if(ville->ttelesmaisonsdelaville[k].type == 1)//centrale
            {
                masked_blit(centrale, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
            }
            if(ville->ttelesmaisonsdelaville[k].type == 2)//chateau d'eau
            {
                masked_blit(chateauEau, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
            }
            if(ville->ttelesmaisonsdelaville[k].type == 3)//route
            {
                masked_blit(route, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
            }
        }
    }
    if(ville->nbBatiment == 1)
    {
        if(ville->ttelesmaisonsdelaville[ville->nbBatiment].type == 0)//habitation
        {
             if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 0)//terrain vague
            {
                masked_blit(terrainVague, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
            }
             if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 1)//cabane
            {
                masked_blit(cabane, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
            }
             if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 2)//maison
            {
                masked_blit(maison, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
            }
             if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 3)//immeuble
            {
                masked_blit(immeuble, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
            }
             if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 4)//gratte ciel
            {
                masked_blit(gratteCiel, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
            }
        }
        if(ville->ttelesmaisonsdelaville[ville->nbBatiment].type == 1)//centrale
        {
            masked_blit(centrale, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
        }
        if(ville->ttelesmaisonsdelaville[ville->nbBatiment].type == 2)//chateau d'eau
        {
            masked_blit(chateauEau, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
        }
        if(ville->ttelesmaisonsdelaville[ville->nbBatiment].type == 3)//route
        {
            masked_blit(route, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
        }
    }
    masked_blit(curseur, doublebuffer, 0, 0, mouse_x, mouse_y, 1024, 768); // affiche le curseur
    blit(doublebuffer, screen, 0, 0, 0, 0, 1024, 768);
    clear_bitmap(doublebuffer);
}

void affichage_niveauEau( t_ville* ville, int tabarene[35][45], BITMAP * doublebuffer, BITMAP * curseur)
{
    BITMAP * cabane;
    BITMAP * maison;
    BITMAP * gratteCiel;
    BITMAP * chateauEau;
    BITMAP * immeuble;
    BITMAP * terrainVague;
    BITMAP * routeEau;
    BITMAP * map;
    BITMAP * parametre;
    BITMAP * boutonmoinsun;
    BITMAP * boutonmoinsdeux;
    BITMAP * pause;
    pause = load_bitmap("BoutonPause.bmp",NULL);
    boutonmoinsun = load_bitmap ("Bouton-1.bmp",NULL);
    boutonmoinsdeux = load_bitmap ("Bouton-2.bmp",NULL);
    cabane= load_bitmap("Cabane.bmp",NULL);
    maison= load_bitmap("Maison.bmp",NULL);
    gratteCiel= load_bitmap("GratteCiel.bmp",NULL);
    chateauEau= load_bitmap("ChateauEau.bmp",NULL);
    immeuble= load_bitmap("Immeuble.bmp",NULL);
    terrainVague= load_bitmap("TerrainVague.bmp",NULL);
    routeEau= load_bitmap("RouteEau.bmp",NULL);
    map = load_bitmap("MapSimCity.bmp",NULL);
    parametre = load_bitmap("Engrenage.bmp",NULL);
    rectfill(doublebuffer, 0,0,1024,768, makecol( 0, 0, 112));
    masked_blit(map, doublebuffer, 0, 0, 0, 0, 900, 700);
    masked_blit(maison, doublebuffer, 0, 0, 940, 100, 940+60, 100+60);
    rect(doublebuffer, 940, 100, 940+60, 100+60, makecol(255, 0, 0));
    masked_blit(chateauEau, doublebuffer, 0, 0, 930, 360, 930+80, 360+120);
    rect(doublebuffer, 930, 360, 930+80, 360+120, makecol(255, 0, 0));
    masked_blit(routeEau, doublebuffer, 0, 0, 960, 520, 960+20, 520+20);
    rect(doublebuffer, 960, 520, 960+20, 520+20, makecol(255, 0, 0));
    masked_blit(parametre, doublebuffer, 0, 0, 984, 0, 1024, 40);
    masked_blit(boutonmoinsun, doublebuffer, 0, 0, 944, 0, 984, 40);
    masked_blit(boutonmoinsdeux, doublebuffer, 0, 0, 904, 0, 944, 40);
    masked_blit(pause, doublebuffer, 0, 0, 904, 40, 944, 80);
    textprintf_ex(doublebuffer, font, 100, 705, makecol(255, 255,255), -1, "ARGENT : %d", ville->ECEflouz);
    textprintf_ex(doublebuffer, font, 300, 705, makecol(255, 255, 255), -1, "NOMBRE HABITANTS : %d", ville->habitantTOT);
    textprintf_ex(doublebuffer, font, 500, 705, makecol(255, 255, 255), -1, "NOMBRE BATIMENTS : %d", ville->nbBatiment);
    int compteur = temps();
    textprintf_ex(doublebuffer, font, 1010, 60, makecol(255, 255, 255), -1, "%d", compteur);
    for(int i=0;i<46;i++)
    {
        for(int j=0;j<36;j++)
        {
            rect(doublebuffer,0,0,20*i,20*j,makecol(0,0,0));
        }
    }
    if(ville->nbBatiment >> 1)
    {
        for(int k = 0; k<ville->nbBatiment ; k++)
        {
            if(ville->ttelesmaisonsdelaville[k].type == 0)//habitation
            {
                 if(ville->ttelesmaisonsdelaville[k].etat == 0)//terrain vague
                {
                    masked_blit(terrainVague, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
                }
                 if(ville->ttelesmaisonsdelaville[k].etat == 1)//cabane
                {
                    masked_blit(cabane, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
                }
                 if(ville->ttelesmaisonsdelaville[k].etat == 2)//maison
                {
                    masked_blit(maison, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
                }
                 if(ville->ttelesmaisonsdelaville[k].etat == 3)//immeuble
                {
                    masked_blit(immeuble, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
                }
                 if(ville->ttelesmaisonsdelaville[k].etat == 4)//gratte ciel
                {
                    masked_blit(gratteCiel, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
                }
            }
            if(ville->ttelesmaisonsdelaville[k].type == 2)//chateau d'eau
            {
                masked_blit(chateauEau, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
            }
            if(ville->ttelesmaisonsdelaville[k].type == 3)//route
            {
                masked_blit(routeEau, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
            }
        }
    }
    if(ville->nbBatiment == 1)
    {
        if(ville->ttelesmaisonsdelaville[ville->nbBatiment].type == 0)//habitation
        {
             if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 0)//terrain vague
            {
                masked_blit(terrainVague, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
            }
             if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 1)//cabane
            {
                masked_blit(cabane, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
            }
             if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 2)//maison
            {
                masked_blit(maison, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
            }
             if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 3)//immeuble
            {
                masked_blit(immeuble, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
            }
             if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 4)//gratte ciel
            {
                masked_blit(gratteCiel, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
            }
        }
        if(ville->ttelesmaisonsdelaville[ville->nbBatiment].type == 2)//chateau d'eau
        {
            masked_blit(chateauEau, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
        }
        if(ville->ttelesmaisonsdelaville[ville->nbBatiment].type == 3)//route
        {
            masked_blit(routeEau, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
        }
    }
    masked_blit(curseur, doublebuffer, 0, 0, mouse_x, mouse_y, 1024, 768); // affiche le curseur
    blit(doublebuffer, screen, 0, 0, 0, 0, 1024, 768);
    clear_bitmap(doublebuffer);
}

void affichage_niveauElec( t_ville* ville, int tabarene[35][45], BITMAP * doublebuffer, BITMAP * curseur)
{
    BITMAP * cabane;
    BITMAP * maison;
    BITMAP * gratteCiel;
    BITMAP * centrale;
    BITMAP * immeuble;
    BITMAP * terrainVague;
    BITMAP * routeElec;
    BITMAP * map;
    BITMAP * parametre;
    BITMAP * boutonmoinsun;
    BITMAP * boutonmoinsdeux;
    BITMAP * pause;
    pause = load_bitmap("BoutonPause.bmp",NULL);
    boutonmoinsun = load_bitmap ("Bouton-1.bmp",NULL);
    boutonmoinsdeux = load_bitmap ("Bouton-2.bmp",NULL);
    cabane= load_bitmap("Cabane.bmp",NULL);
    maison= load_bitmap("Maison.bmp",NULL);
    gratteCiel= load_bitmap("GratteCiel.bmp",NULL);
    centrale= load_bitmap("CentraleElectrique.bmp",NULL);
    immeuble= load_bitmap("Immeuble.bmp",NULL);
    terrainVague= load_bitmap("TerrainVague.bmp",NULL);
    routeElec= load_bitmap("RouteElectricite.bmp",NULL);
    map = load_bitmap("MapSimCity.bmp",NULL);
    parametre = load_bitmap("Engrenage.bmp",NULL);
    rectfill(doublebuffer, 0,0,1024,768, makecol( 0, 0, 112));
    masked_blit(map, doublebuffer, 0, 0, 0, 0, 900, 700);
    masked_blit(maison, doublebuffer, 0, 0, 940, 100, 940+60, 100+60);
    rect(doublebuffer, 940, 100, 940+60, 100+60, makecol(255, 0, 0));
    masked_blit(centrale, doublebuffer, 0, 0, 930, 200, 930+80, 200+120);
    rect(doublebuffer, 930, 200, 930+80, 200+120, makecol(255, 0, 0));
    masked_blit(routeElec, doublebuffer, 0, 0, 960, 520, 960+20, 520+20);
    rect(doublebuffer, 960, 520, 960+20, 520+20, makecol(255, 0, 0));
    masked_blit(parametre, doublebuffer, 0, 0, 984, 0, 1024, 40);
    masked_blit(boutonmoinsun, doublebuffer, 0, 0, 944, 0, 984, 40);
    masked_blit(boutonmoinsdeux, doublebuffer, 0, 0, 904, 0, 944, 40);
    masked_blit(pause, doublebuffer, 0, 0, 904, 40, 944, 80);
    textprintf_ex(doublebuffer, font, 100, 705, makecol(255, 255,255), -1, "ARGENT : %d", ville->ECEflouz);
    textprintf_ex(doublebuffer, font, 300, 705, makecol(255, 255, 255), -1, "NOMBRE HABITANTS : %d", ville->habitantTOT);
    textprintf_ex(doublebuffer, font, 500, 705, makecol(255, 255, 255), -1, "NOMBRE BATIMENTS : %d", ville->nbBatiment);
    int compteur = temps();
    textprintf_ex(doublebuffer, font, 1010, 60, makecol(255, 255, 255), -1, "%d", compteur);
    for(int i=0;i<46;i++)
    {
        for(int j=0;j<36;j++)
        {
            rect(doublebuffer,0,0,20*i,20*j,makecol(0,0,0));
        }
    }
    if(ville->nbBatiment >> 1)
    {
        for(int k = 0; k<ville->nbBatiment ; k++)
        {
            if(ville->ttelesmaisonsdelaville[k].type == 0)//habitation
            {
                 if(ville->ttelesmaisonsdelaville[k].etat == 0)//terrain vague
                {
                    masked_blit(terrainVague, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
                }
                 if(ville->ttelesmaisonsdelaville[k].etat == 1)//cabane
                {
                    masked_blit(cabane, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
                }
                 if(ville->ttelesmaisonsdelaville[k].etat == 2)//maison
                {
                    masked_blit(maison, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
                }
                 if(ville->ttelesmaisonsdelaville[k].etat == 3)//immeuble
                {
                    masked_blit(immeuble, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
                }
                 if(ville->ttelesmaisonsdelaville[k].etat == 4)//gratte ciel
                {
                    masked_blit(gratteCiel, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
                }
            }
            if(ville->ttelesmaisonsdelaville[k].type == 1)//centrale
            {
                masked_blit(centrale, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
            }
            if(ville->ttelesmaisonsdelaville[k].type == 3)//route
            {
                masked_blit(routeElec, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY, 20*ville->ttelesmaisonsdelaville[k].numeroCaseX+ville->ttelesmaisonsdelaville[k].tailleX, 20*ville->ttelesmaisonsdelaville[k].numeroCaseY+ville->ttelesmaisonsdelaville[k].tailleY);
            }
        }
    }
    if(ville->nbBatiment == 1)
    {
        if(ville->ttelesmaisonsdelaville[ville->nbBatiment].type == 0)//habitation
        {
             if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 0)//terrain vague
            {
                masked_blit(terrainVague, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
            }
             if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 1)//cabane
            {
                masked_blit(cabane, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
            }
             if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 2)//maison
            {
                masked_blit(maison, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
            }
             if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 3)//immeuble
            {
                masked_blit(immeuble, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
            }
             if(ville->ttelesmaisonsdelaville[ville->nbBatiment].etat == 4)//gratte ciel
            {
                masked_blit(gratteCiel, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
            }
        }
        if(ville->ttelesmaisonsdelaville[ville->nbBatiment].type == 1)//centrale
        {
            masked_blit(centrale, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
        }
        if(ville->ttelesmaisonsdelaville[ville->nbBatiment].type == 3)//route
        {
            masked_blit(routeElec, doublebuffer, 0, 0, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseX+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleX, 20*ville->ttelesmaisonsdelaville[ville->nbBatiment].numeroCaseY+ville->ttelesmaisonsdelaville[ville->nbBatiment].tailleY);
        }
    }
    masked_blit(curseur, doublebuffer, 0, 0, mouse_x, mouse_y, 1024, 768); // affiche le curseur
    blit(doublebuffer, screen, 0, 0, 0, 0, 1024, 768);
    clear_bitmap(doublebuffer);
}

void jouer( t_ville* ville, int tabarene[35][45], BITMAP * doublebuffer, BITMAP * curseur, int incremente)
{
    int compteur = temps();
    int compteur2 = 0;
    while(compteur % 15 != 0)
    {

        if(mouse_x >= 984 && mouse_x <= 1024 && mouse_y >= 0 && mouse_y <= 40 && mouse_b&1)//Condition de sortie du jeu
        {
            menu_jeu( ville, tabarene, incremente);
        }
        if(mouse_x >= 944 && mouse_x <= 984 && mouse_y >= 0 && mouse_y <= 40 && mouse_b&1)
        {
            int rester=1;
            delay(0.1);
            while(rester ==1)
            {
                affichage_niveauEau( ville, tabarene, doublebuffer, curseur);
                if(mouse_x >= 944 && mouse_x <= 984 && mouse_y >= 0 && mouse_y <= 40 && mouse_b&1)
                {
                    rester =0;
                    delay(0.1);
                }
            }
        }
        if(mouse_x >= 904 && mouse_x <= 944 && mouse_y >= 0 && mouse_y <= 40 && mouse_b&1)
        {
            int rester=1;
            delay(0.1);
            while(rester ==1)
            {
                affichage_niveauElec( ville, tabarene, doublebuffer, curseur);
                if(mouse_x >= 904 && mouse_x <= 944 && mouse_y >= 0 && mouse_y <= 40 && mouse_b&1)
                {
                    rester =0;
                    delay(0.1);
                }
            }
        }
        if(mouse_x >= 904 && mouse_x <= 944 && mouse_y >= 40 && mouse_y <= 80 && mouse_b&1)// mettre en pause
        {
            int rester=1;
            delay(0.1);
            BITMAP * pause;
            BITMAP * play;
            BITMAP * fondmenu;
            fondmenu = load_bitmap("FondMenu.bmp",NULL);
            pause = load_bitmap("BoutonPause.bmp",NULL);
            play = load_bitmap("BoutonPlay.bmp",NULL);
            while(rester ==1)
            {
                compteur2 = temps();
                clear(doublebuffer);
                masked_blit(fondmenu, doublebuffer, 0, 0, 0, 0, 1024, 768);
                masked_blit(play, doublebuffer, 0, 0, 409, 282, 612, 485);
                masked_blit(curseur, doublebuffer, 0, 0, mouse_x, mouse_y, 1024, 768); // affiche le curseur
                blit(doublebuffer,screen,0,0,0,0,1024,768);
                if(mouse_x >= 409 && mouse_x <= 612 && mouse_y >= 282 && mouse_y <= 485 && mouse_b&1)
                {
                    rester =0;
                    delay(0.1);
                    compteur = compteur - compteur2;
                }
            }
        }
        if(mouse_x >= 940 && mouse_x <= 940+60 && mouse_y >= 100 && mouse_y <= 100+60 && mouse_b&1)//poser une maison
        {
            ville->ttelesmaisonsdelaville[ville->nbBatiment].type = 0;
            ville->ttelesmaisonsdelaville[ville->nbBatiment].etat = 0;
            ajouterBatiment( ville, tabarene, doublebuffer, curseur);
        }
        if(mouse_x >= 930 && mouse_x <= 930+80 && mouse_y >= 200 && mouse_y <= 200+120 && mouse_b&1)
        {
            ville->ttelesmaisonsdelaville[ville->nbBatiment].type = 1;
            ville->ttelesmaisonsdelaville[ville->nbBatiment].etat = 0;
            ajouterBatiment( ville, tabarene, doublebuffer, curseur);
        }
        if(mouse_x >= 930 && mouse_x <= 930+80 && mouse_y >= 360 && mouse_y <= 360+120 && mouse_b&1)
        {
            ville->ttelesmaisonsdelaville[ville->nbBatiment].type = 2;
            ville->ttelesmaisonsdelaville[ville->nbBatiment].etat = 0;
            ajouterBatiment( ville, tabarene, doublebuffer, curseur);
        }
        if(mouse_x >= 960 && mouse_x <= 960+20 && mouse_y >= 520 && mouse_y <= 520+20 && mouse_b&1)
        {
            ville->ttelesmaisonsdelaville[ville->nbBatiment].type = 3;
            ville->ttelesmaisonsdelaville[ville->nbBatiment].etat = 0;
            ajouterBatiment( ville, tabarene, doublebuffer, curseur);
        }
        compteur = temps();
        affichage_jeu( ville, tabarene, doublebuffer, curseur);
    }
    printf("\nactualisation des etats");
    jouer( ville, tabarene, doublebuffer, curseur, incremente+1);
}

void charger_partie( t_ville *ville, int tabarene[35][45], BITMAP * doublebuffer, BITMAP * curseur, int incremente)
{
    FILE * newGame = NULL;
    newGame = fopen("partie_sauvegarde.txt","r");
    if(newGame == NULL)
    {
        printf("pas de partie en cours");
        menu_debut(  ville, tabarene, doublebuffer, curseur, incremente);
    }
    else
    {
        fscanf(newGame, "%d", &ville->nbBatiment);
        fscanf(newGame, "%d", &ville->ECEflouz);
        fscanf(newGame, "%d", &ville->habitantTOT);
        for(int j=0 ; j < ville->nbBatiment; j++)
        {
            fscanf(newGame, "%d ",&ville->ttelesmaisonsdelaville[j].alimEau);
            fscanf(newGame, "%d ",&ville->ttelesmaisonsdelaville[j].alimElec);
            fscanf(newGame, "%d ",&ville->ttelesmaisonsdelaville[j].besoinEau);
            fscanf(newGame, "%d ",&ville->ttelesmaisonsdelaville[j].besoinElec);
            fscanf(newGame, "%d ",&ville->ttelesmaisonsdelaville[j].coutAchat);
            fscanf(newGame, "%d ",&ville->ttelesmaisonsdelaville[j].debitEau);
            fscanf(newGame, "%d ",&ville->ttelesmaisonsdelaville[j].debitElec);
            fscanf(newGame, "%d ",&ville->ttelesmaisonsdelaville[j].etat);
            fscanf(newGame, "%d ",&ville->ttelesmaisonsdelaville[j].nbHabitant);
            fscanf(newGame, "%d ",&ville->ttelesmaisonsdelaville[j].numeroCaseX);
            fscanf(newGame, "%d ",&ville->ttelesmaisonsdelaville[j].numeroCaseY);
            fscanf(newGame, "%d ",&ville->ttelesmaisonsdelaville[j].tailleX);
            fscanf(newGame, "%d ",&ville->ttelesmaisonsdelaville[j].tailleY);
        }
        fclose(newGame);
        jouer( ville, tabarene, doublebuffer, curseur, incremente);
    }
}

void menu_debut( t_ville *ville, int tabarene[35][45], BITMAP * doublebuffer, BITMAP * curseur, int incremente)
{
    int a = 0;
    BITMAP * boutonNewGame;
    BITMAP * boutonCharger;
    BITMAP* fondmenu;
    BITMAP* boutonCommuniste;
    BITMAP* boutonCapitaliste;

    boutonCommuniste = load_bitmap("ModeCommuniste.bmp", NULL);
    boutonCapitaliste = load_bitmap("ModeCapitaliste.bmp", NULL);

    fondmenu = load_bitmap("FondMenu.bmp",NULL);
    boutonCharger = load_bitmap("BTCHP.bmp",NULL);
    boutonNewGame = load_bitmap("BTNVP.bmp",NULL);
    while (a == 0)
    {
        blit(fondmenu, doublebuffer, 0, 0, 0, 0, 1024, 768);
        //utilisation de masked_blit pour supprimer les fonds magentas des BITMAPS
        //charger // jouer
        masked_blit(boutonNewGame, doublebuffer, 0, 0, 380, 350, 380+boutonNewGame->w, 350+boutonNewGame->h);//affiche le logo jouer
        masked_blit(boutonCharger, doublebuffer, 0, 0, 380, 450, 380+boutonNewGame->w, 450+boutonNewGame->h);//affiche le logo jouer
        masked_blit(curseur, doublebuffer, 0, 0, mouse_x, mouse_y, 1024, 768); // affiche le curseur

        if (mouse_x > 380 && mouse_x < 380 + boutonNewGame->w && mouse_y > 350 && mouse_y < 350 + boutonNewGame->h && mouse_b & 1) // clique sur le bouton jouer
        {
            while(a == 0)
            {
                delay(0.1);
                blit(fondmenu, doublebuffer, 0, 0, 0, 0, 1024, 768);
                masked_blit(boutonCommuniste, doublebuffer, 0, 0, 380, 350, 380+boutonCommuniste->w, 350+boutonCommuniste->h);//affiche le logo jouer
                masked_blit(boutonCapitaliste, doublebuffer, 0, 0, 380, 450, 380+boutonCapitaliste->w, 450+boutonCapitaliste->h);//affiche le logo jouer
                masked_blit(curseur, doublebuffer, 0, 0, mouse_x, mouse_y, 1024, 768); // affiche le curseur
                if(mouse_x > 380 && mouse_x < 380 + boutonCommuniste->w && mouse_y > 350 && mouse_y < 350 + boutonCommuniste->h && mouse_b & 1 )
                {
                    delay(0.1);
                    jouer( ville, tabarene, doublebuffer, curseur, incremente);
                }
                else if(mouse_x > 380 && mouse_x < 380 + boutonCapitaliste->w && mouse_y > 350 && mouse_y < 350 + boutonCapitaliste->h && mouse_b & 1 )
                {
                    delay(0.1);
                    jouer( ville, tabarene, doublebuffer, curseur, incremente);
                }
                blit(doublebuffer, screen, 0, 0, 0, 0, 1024, 768);
            }

            a=1;//quitter le while
        }
        else if(mouse_x > 380 && mouse_x < 380 + boutonNewGame->w && mouse_y > 450 && mouse_y < 450 + boutonNewGame->h && mouse_b & 1)//clique sur le bouton charger partie
        {
            delay(0.1);
            charger_partie( ville, tabarene, doublebuffer, curseur, incremente);
            a=1;//quitter le while
        }
        blit(doublebuffer, screen, 0, 0, 0, 0, 1024, 768);
        clear_bitmap(doublebuffer);
        delay(0.01);
    }
}

void delay(float temps)
{
    clock_t arrivee = clock() + (temps * CLOCKS_PER_SEC); // On calcule le moment où l'attente devra s'arréter
    while (clock() < arrivee);
}

///MAIN

int main()
{
    ///Initialisation des fonctions
    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(desktop_color_depth());
    ///Initialisation de la console graphique Allegro
    if ((set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1024, 728, 0, 0)) != 0)
    {
        allegro_message("Pb de mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    ///Déclaration et Initialisation des structures
    t_ville ville;
    init_ville(&ville);
    ///Déclaration des variables
    int tabarene[35][45];//Création du tableau d'occupation de chaque case de la map
    int incremente = 0;
    ///Ouverture des bitmaps
    BITMAP * doublebuffer;
    BITMAP * curseur;
    curseur = load_bitmap("CURSEUR.bmp",NULL);
    doublebuffer= create_bitmap(1024,768) ;
    //load_bitmap()
    ///Lancement du Jeu
    //Boucle qui permet d'initialiser les cases du tableau d'occupation des cases à 0
    for (int i=0 ; i<35 ; i++)
    {
        for (int j = 0 ; j<45 ; j++)
        {
            tabarene[i][j] = 0;
        }
    }
    //Programme qui affiche le menu
    menu_debut( &ville, tabarene, doublebuffer, curseur, incremente);
    free(ville.ttelesmaisonsdelaville);
    allegro_exit();
    return 0;
}END_OF_MAIN();
