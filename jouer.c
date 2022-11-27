#include "header.h"

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

void delay(float temps)
{
    clock_t arrivee = clock() + (temps * CLOCKS_PER_SEC); // On calcule le moment où l'attente devra s'arréter
    while (clock() < arrivee);
}
