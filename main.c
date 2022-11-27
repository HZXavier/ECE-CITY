#include "header.h"

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
    ///D�claration et Initialisation des structures
    t_ville ville;
    init_ville(&ville);
    ///D�claration des variables
    int tabarene[35][45];//Cr�ation du tableau d'occupation de chaque case de la map
    int incremente = 0;
    ///Ouverture des bitmaps
    BITMAP * doublebuffer;
    BITMAP * curseur;
    curseur = load_bitmap("CURSEUR.bmp",NULL);
    doublebuffer= create_bitmap(1024,768) ;
    //load_bitmap()
    ///Lancement du Jeu
    //Boucle qui permet d'initialiser les cases du tableau d'occupation des cases � 0
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
