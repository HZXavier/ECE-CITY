#include "header.h"

void affichage_jeu(t_ville *ville, int tabarene[35][45], BITMAP *doublebuffer, BITMAP *curseur)
{///Afficher le plateau de jeu au niveau 0 avec la boite à outils et les données du joueur
    ///Création des pointeurs BITMAP
    BITMAP *cabane;
    BITMAP *maison;
    BITMAP *gratteCiel;
    BITMAP *centrale;
    BITMAP *chateauEau;
    BITMAP *immeuble;
    BITMAP *terrainVague;
    BITMAP *route;
    BITMAP *map;
    BITMAP *parametre;
    BITMAP *boutonmoinsun;
    BITMAP *boutonmoinsdeux;
    BITMAP *pause;
    ///Chargement des BITMAPS à partir des fichiers .BMP
    pause = load_bitmap("BoutonPause.bmp", NULL);
    boutonmoinsun = load_bitmap("Bouton-1.bmp", NULL);
    boutonmoinsdeux = load_bitmap("Bouton-2.bmp", NULL);
    cabane = load_bitmap("Cabane.bmp", NULL);
    maison = load_bitmap("Maison.bmp", NULL);
    gratteCiel = load_bitmap("GratteCiel.bmp", NULL);
    centrale = load_bitmap("CentraleElectrique.bmp", NULL);
    chateauEau = load_bitmap("ChateauEau.bmp", NULL);
    immeuble = load_bitmap("Immeuble.bmp", NULL);
    terrainVague = load_bitmap("TerrainVague.bmp", NULL);
    route = load_bitmap("Route.bmp", NULL);
    map = load_bitmap("MapSimCity.bmp", NULL);
    parametre = load_bitmap("Engrenage.bmp", NULL);
    ///Affichage des differentes BITMAPS aux coordonnées et tailles correspondantes
    masked_blit(boutonmoinsun, doublebuffer, 0, 0, 944, 0, 984, 40);
    masked_blit(boutonmoinsdeux, doublebuffer, 0, 0, 904, 0, 944, 40);
    rectfill(doublebuffer, 0, 0, 1024, 768, makecol(0, 0, 112));
    masked_blit(map, doublebuffer, 0, 0, 0, 0, 900, 700);
    masked_blit(maison, doublebuffer, 0, 0, 940, 100, 940 + 60, 100 + 60);
    rect(doublebuffer, 940, 100, 940 + 60, 100 + 60, makecol(255, 0, 0));
    masked_blit(centrale, doublebuffer, 0, 0, 930, 200, 930 + 80, 200 + 120);
    rect(doublebuffer, 930, 200, 930 + 80, 200 + 120, makecol(255, 0, 0));
    masked_blit(chateauEau, doublebuffer, 0, 0, 930, 360, 930 + 80, 360 + 120);
    rect(doublebuffer, 930, 360, 930 + 80, 360 + 120, makecol(255, 0, 0));
    masked_blit(route, doublebuffer, 0, 0, 960, 520, 960 + 20, 520 + 20);
    rect(doublebuffer, 960, 520, 960 + 20, 520 + 20, makecol(255, 0, 0));
    masked_blit(parametre, doublebuffer, 0, 0, 984, 0, 1024, 40);
    masked_blit(boutonmoinsun, doublebuffer, 0, 0, 944, 0, 984, 40);
    masked_blit(boutonmoinsdeux, doublebuffer, 0, 0, 904, 0, 944, 40);
    masked_blit(pause, doublebuffer, 0, 0, 904, 40, 944, 80);
    ///Affichage des données du joueur
    textprintf_ex(doublebuffer, font, 0, 705, makecol(255, 255, 255), -1, "ARGENT : %d", ville->ECEflouz);
    textprintf_ex(doublebuffer, font, 130, 705, makecol(255, 255, 255), -1, "HABITANTS : %d", ville->habitantTOT);
    textprintf_ex(doublebuffer, font, 300, 705, makecol(255, 255, 255), -1, "BATIMENTS : %d", ville->nbBatiment-ville->nbRoute);
    textprintf_ex(doublebuffer, font, 440, 705, makecol(255, 255, 255), -1, "AlimEau : %d", ville->alimEauTot);
    textprintf_ex(doublebuffer, font, 580, 705, makecol(255, 255, 255), -1, "AlimElec : %d", ville->alimElecTot);
    textprintf_ex(doublebuffer, font, 720, 705, makecol(255, 255, 255), -1, "BesoinEau : %d", ville->besoinEauTot);
    textprintf_ex(doublebuffer, font, 870, 705, makecol(255, 255, 255), -1, "BesoinElec : %d", ville->besoinElecTot);
    int compteur = temps();//création d'un timer
    textprintf_ex(doublebuffer, font, 1000, 60, makecol(255, 255, 255), -1, "%d", compteur);//affichage du compteur
    //affichage d'une grille sur la map pour délimiter chaque case
    for (int i = 0; i < 46; i++)
    {
        for (int j = 0; j < 36; j++)
        {
            rect(doublebuffer, 0, 0, 20 * i, 20 * j, makecol(0, 0, 0));//affichage d'un rectangle vide aux coordonnées de la case i,j
        }
    }
    for (int k = 0; k < ville->nbBatiment; k++)///Boucle qui affiche tous les batiments sur la map en recupérant les informations depuis le tableau de batiment
    {
        if (ville->ttelesmaisonsdelaville[k].type == 0) //Cas d'une habitation
        {
            if (ville->ttelesmaisonsdelaville[k].etat == 1) //Cas d'un terrain vague
            {
                masked_blit(terrainVague, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
            }
            if (ville->ttelesmaisonsdelaville[k].etat == 2) //Cas d'une cabane
            {
                masked_blit(cabane, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
            }
            if (ville->ttelesmaisonsdelaville[k].etat == 3) //Cas d'une maison
            {
                masked_blit(maison, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
            }
            if (ville->ttelesmaisonsdelaville[k].etat == 4) //Cas d'un immeuble
            {
                masked_blit(immeuble, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
            }
            if (ville->ttelesmaisonsdelaville[k].etat == 5) //Cas d'un gratte ciel
            {
                masked_blit(gratteCiel, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
            }
        }
        if (ville->ttelesmaisonsdelaville[k].type == 1) //Cas centrale
        {
            masked_blit(centrale, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
        }
        if (ville->ttelesmaisonsdelaville[k].type == 2) //Cas chateau d'eau
        {
            masked_blit(chateauEau, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
        }
        if (ville->ttelesmaisonsdelaville[k].type == 3) //Cas d'une route
        {
            masked_blit(route, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
        }
    }
    masked_blit(curseur, doublebuffer, 0, 0, mouse_x, mouse_y, 1024, 768); //Affiche le curseur
    blit(doublebuffer, screen, 0, 0, 0, 0, 1024, 768);//Affiche le double buffer sur l'écran
    clear_bitmap(doublebuffer);//Réinistialise le double buffer
}

void affichage_niveauEau(t_ville *ville, int tabarene[35][45], BITMAP *doublebuffer, BITMAP *curseur)
{///Affichage du niveau Eau(-1) : Meme programme que pour l'affichage du jeu en retirant l'affichage de la capacité totale électrique, des centrales électriques et du bouton pour les construire
    BITMAP *cabane;
    BITMAP *maison;
    BITMAP *gratteCiel;
    BITMAP *chateauEau;
    BITMAP *immeuble;
    BITMAP *terrainVague;
    BITMAP *routeEau;
    BITMAP *map;
    BITMAP *parametre;
    BITMAP *boutonmoinsun;
    BITMAP *boutonmoinsdeux;
    BITMAP *pause;
    pause = load_bitmap("BoutonPause.bmp", NULL);
    boutonmoinsun = load_bitmap("Bouton-1.bmp", NULL);
    boutonmoinsdeux = load_bitmap("Bouton-2.bmp", NULL);
    cabane = load_bitmap("Cabane.bmp", NULL);
    maison = load_bitmap("Maison.bmp", NULL);
    gratteCiel = load_bitmap("GratteCiel.bmp", NULL);
    chateauEau = load_bitmap("ChateauEau.bmp", NULL);
    immeuble = load_bitmap("Immeuble.bmp", NULL);
    terrainVague = load_bitmap("TerrainVague.bmp", NULL);
    routeEau = load_bitmap("RouteEau.bmp", NULL);
    map = load_bitmap("MapSimCity.bmp", NULL);
    parametre = load_bitmap("Engrenage.bmp", NULL);
    rectfill(doublebuffer, 0, 0, 1024, 768, makecol(0, 0, 112));
    masked_blit(map, doublebuffer, 0, 0, 0, 0, 900, 700);
    masked_blit(maison, doublebuffer, 0, 0, 940, 100, 940 + 60, 100 + 60);
    rect(doublebuffer, 940, 100, 940 + 60, 100 + 60, makecol(255, 0, 0));
    masked_blit(chateauEau, doublebuffer, 0, 0, 930, 360, 930 + 80, 360 + 120);
    rect(doublebuffer, 930, 360, 930 + 80, 360 + 120, makecol(255, 0, 0));
    masked_blit(routeEau, doublebuffer, 0, 0, 960, 520, 960 + 20, 520 + 20);
    rect(doublebuffer, 960, 520, 960 + 20, 520 + 20, makecol(255, 0, 0));
    masked_blit(parametre, doublebuffer, 0, 0, 984, 0, 1024, 40);
    masked_blit(boutonmoinsun, doublebuffer, 0, 0, 944, 0, 984, 40);
    masked_blit(boutonmoinsdeux, doublebuffer, 0, 0, 904, 0, 944, 40);
    masked_blit(pause, doublebuffer, 0, 0, 904, 40, 944, 80);
    textprintf_ex(doublebuffer, font, 0, 705, makecol(255, 255, 255), -1, "ARGENT : %d", ville->ECEflouz);
    textprintf_ex(doublebuffer, font, 130, 705, makecol(255, 255, 255), -1, "HABITANTS : %d", ville->habitantTOT);
    textprintf_ex(doublebuffer, font, 300, 705, makecol(255, 255, 255), -1, "BATIMENTS : %d", ville->nbBatiment-ville->nbRoute);
    textprintf_ex(doublebuffer, font, 440, 705, makecol(255, 255, 255), -1, "AlimEau : %d", ville->alimEauTot);
    textprintf_ex(doublebuffer, font, 720, 705, makecol(255, 255, 255), -1, "BesoinEau : %d", ville->besoinEauTot);
    int compteur = temps();
    textprintf_ex(doublebuffer, font, 1000, 60, makecol(255, 255, 255), -1, "%d", compteur);
    for (int i = 0; i < 46; i++)
    {
        for (int j = 0; j < 36; j++)
        {
            rect(doublebuffer, 0, 0, 20 * i, 20 * j, makecol(0, 0, 0));
        }
    }
    for (int k = 0; k < ville->nbBatiment; k++)
    {
        if (ville->ttelesmaisonsdelaville[k].type == 0) // habitation
        {
            if (ville->ttelesmaisonsdelaville[k].etat == 1) // terrain vague
            {
                masked_blit(terrainVague, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
            }
            if (ville->ttelesmaisonsdelaville[k].etat == 2) // cabane
            {
                masked_blit(cabane, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
            }
            if (ville->ttelesmaisonsdelaville[k].etat == 3) // maison
            {
                masked_blit(maison, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
            }
            if (ville->ttelesmaisonsdelaville[k].etat == 4) // immeuble
            {
                masked_blit(immeuble, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
            }
            if (ville->ttelesmaisonsdelaville[k].etat == 5) // gratte ciel
            {
                masked_blit(gratteCiel, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
            }
        }
        if (ville->ttelesmaisonsdelaville[k].type == 2) // chateau d'eau
        {
            masked_blit(chateauEau, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
        }
        if (ville->ttelesmaisonsdelaville[k].type == 3) // route
        {
            masked_blit(routeEau, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
        }
    }
    masked_blit(curseur, doublebuffer, 0, 0, mouse_x, mouse_y, 1024, 768); //Affiche le curseur
    blit(doublebuffer, screen, 0, 0, 0, 0, 1024, 768);//Affiche le double buffer sur l'écran
    clear_bitmap(doublebuffer);//Réinistialise le double buffer
}

void affichage_niveauElec(t_ville *ville, int tabarene[35][45], BITMAP *doublebuffer, BITMAP *curseur)
{///Affichage du niveau Electrique(-2) : Meme programme que pour l'affichage du jeu en retirant l'affichage de la capacité totale en eau, des chateaux d'eau et du bouton pour les construire
    BITMAP *cabane;
    BITMAP *maison;
    BITMAP *gratteCiel;
    BITMAP *centrale;
    BITMAP *immeuble;
    BITMAP *terrainVague;
    BITMAP *routeElec;
    BITMAP *map;
    BITMAP *parametre;
    BITMAP *boutonmoinsun;
    BITMAP *boutonmoinsdeux;
    BITMAP *pause;
    pause = load_bitmap("BoutonPause.bmp", NULL);
    boutonmoinsun = load_bitmap("Bouton-1.bmp", NULL);
    boutonmoinsdeux = load_bitmap("Bouton-2.bmp", NULL);
    cabane = load_bitmap("Cabane.bmp", NULL);
    maison = load_bitmap("Maison.bmp", NULL);
    gratteCiel = load_bitmap("GratteCiel.bmp", NULL);
    centrale = load_bitmap("CentraleElectrique.bmp", NULL);
    immeuble = load_bitmap("Immeuble.bmp", NULL);
    terrainVague = load_bitmap("TerrainVague.bmp", NULL);
    routeElec = load_bitmap("RouteElectricite.bmp", NULL);
    map = load_bitmap("MapSimCity.bmp", NULL);
    parametre = load_bitmap("Engrenage.bmp", NULL);
    rectfill(doublebuffer, 0, 0, 1024, 768, makecol(0, 0, 112));
    masked_blit(map, doublebuffer, 0, 0, 0, 0, 900, 700);
    masked_blit(maison, doublebuffer, 0, 0, 940, 100, 940 + 60, 100 + 60);
    rect(doublebuffer, 940, 100, 940 + 60, 100 + 60, makecol(255, 0, 0));
    masked_blit(centrale, doublebuffer, 0, 0, 930, 200, 930 + 80, 200 + 120);
    rect(doublebuffer, 930, 200, 930 + 80, 200 + 120, makecol(255, 0, 0));
    masked_blit(routeElec, doublebuffer, 0, 0, 960, 520, 960 + 20, 520 + 20);
    rect(doublebuffer, 960, 520, 960 + 20, 520 + 20, makecol(255, 0, 0));
    masked_blit(parametre, doublebuffer, 0, 0, 984, 0, 1024, 40);
    masked_blit(boutonmoinsun, doublebuffer, 0, 0, 944, 0, 984, 40);
    masked_blit(boutonmoinsdeux, doublebuffer, 0, 0, 904, 0, 944, 40);
    masked_blit(pause, doublebuffer, 0, 0, 904, 40, 944, 80);
    textprintf_ex(doublebuffer, font, 0, 705, makecol(255, 255, 255), -1, "ARGENT : %d", ville->ECEflouz);
    textprintf_ex(doublebuffer, font, 130, 705, makecol(255, 255, 255), -1, "HABITANTS : %d", ville->habitantTOT);
    textprintf_ex(doublebuffer, font, 300, 705, makecol(255, 255, 255), -1, "BATIMENTS : %d", ville->nbBatiment-ville->nbRoute);
    textprintf_ex(doublebuffer, font, 580, 705, makecol(255, 255, 255), -1, "AlimElec : %d", ville->alimElecTot);
    textprintf_ex(doublebuffer, font, 870, 705, makecol(255, 255, 255), -1, "BesoinElec : %d", ville->besoinElecTot);
    int compteur = temps();
    textprintf_ex(doublebuffer, font, 1000, 60, makecol(255, 255, 255), -1, "%d", compteur);
    for (int i = 0; i < 46; i++)
    {
        for (int j = 0; j < 36; j++)
        {
            rect(doublebuffer, 0, 0, 20 * i, 20 * j, makecol(0, 0, 0));
        }
    }
    for (int k = 0; k < ville->nbBatiment; k++)
    {
        if (ville->ttelesmaisonsdelaville[k].type == 0) // habitation
        {
            if (ville->ttelesmaisonsdelaville[k].etat == 1) // terrain vague
            {
                masked_blit(terrainVague, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
            }
            if (ville->ttelesmaisonsdelaville[k].etat == 2) // cabane
            {
                masked_blit(cabane, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
            }
            if (ville->ttelesmaisonsdelaville[k].etat == 3) // maison
            {
                masked_blit(maison, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
            }
            if (ville->ttelesmaisonsdelaville[k].etat == 4) // immeuble
            {
                masked_blit(immeuble, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
            }
            if (ville->ttelesmaisonsdelaville[k].etat == 5) // gratte ciel
            {
                masked_blit(gratteCiel, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
            }
        }
        if (ville->ttelesmaisonsdelaville[k].type == 1) // centrale
        {
            masked_blit(centrale, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
        }
        if (ville->ttelesmaisonsdelaville[k].type == 3) // route
        {
            masked_blit(routeElec, doublebuffer, 0, 0, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseX + ville->ttelesmaisonsdelaville[k].tailleX, 20 * ville->ttelesmaisonsdelaville[k].numeroCaseY + ville->ttelesmaisonsdelaville[k].tailleY);
        }
    }
    masked_blit(curseur, doublebuffer, 0, 0, mouse_x, mouse_y, 1024, 768); //Affiche le curseur
    blit(doublebuffer, screen, 0, 0, 0, 0, 1024, 768);//Affiche le double buffer sur l'écran
    clear_bitmap(doublebuffer);//Réinistialise le double buffer
}
