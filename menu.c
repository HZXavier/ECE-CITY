#include "header.h"

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
            delay(0.1);
            while(a == 0)
            {
                blit(fondmenu, doublebuffer, 0, 0, 0, 0, 1024, 768);
                masked_blit(boutonCommuniste, doublebuffer, 0, 0, 380, 350, 380+boutonCommuniste->w, 350+boutonCommuniste->h);//affiche le logo jouer
                masked_blit(boutonCapitaliste, doublebuffer, 0, 0, 380, 450, 380+boutonCapitaliste->w, 450+boutonCapitaliste->h);//affiche le logo jouer
                masked_blit(curseur, doublebuffer, 0, 0, mouse_x, mouse_y, 1024, 768); // affiche le curseur
                if(mouse_x > 380 && mouse_x < 380 + boutonCommuniste->w && mouse_y > 350 && mouse_y < 350 + boutonCommuniste->h && mouse_b & 1 )
                {
                    delay(0.1);
                    jouer( ville, tabarene, doublebuffer, curseur, incremente);
                }
                if(mouse_x > 380 && mouse_x < 380 + boutonCapitaliste->w && mouse_y > 450 && mouse_y < 450 + boutonCapitaliste->h && mouse_b & 1)
                {
                    delay(0.1);
                    jouer( ville, tabarene, doublebuffer, curseur, incremente);
                }
                if(mouse_x > 380 && mouse_x < 380 + boutonRegles->w && mouse_y > 550 && mouse_y < 550 + boutonRegles->h && mouse_b & 1)
                {
                    //////

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
