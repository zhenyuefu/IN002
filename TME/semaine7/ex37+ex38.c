#include <SDL2/SDL.h>
#include <cini.h>

#include "cini_color.c"
#include "cini_graphic.c"

#define TAILLE_CASE 20
#define HAUTEUR 22
#define LARGEUR 10
#define VIDE 8
/* n'importe quelle valeur qui n'est pas un indice du tableau des        \
 * couleurs \                                                            \
 * \ \ \
 */

/*-------------   INSERER ICI LES DEFINITIONS DE TYPES   --------------*/

struct une_case {
    int colonne;
    int ligne;
};

struct piece {
    int pos_ligne, pos_colonne;
    struct une_case la_piece[4];
    int type;
};

/*-------------------   INSERER ICI LES FONCTIONS   -------------------*/
/* Affiche une piece */
void afficher_piece(struct piece tetromino, char *couleur) {
    int i;
    int ligne_deb, colonne_deb;

    for (i = 0; i < 4; i++) {
        ligne_deb =
            (tetromino.pos_ligne + tetromino.la_piece[i].ligne) * TAILLE_CASE;
        colonne_deb = (tetromino.pos_colonne + tetromino.la_piece[i].colonne) *
                      TAILLE_CASE;
        CINI_fill_rect(colonne_deb, ligne_deb, TAILLE_CASE, TAILLE_CASE,
                       couleur);
    }
}

/* Initialisation d'une piece, elle se trouve initialement en haut et au milieu
 * du plateau */
void initialiser(struct piece *p_tetromino, struct une_case tab[4],
                 int indice) {
    int i;
    p_tetromino->pos_colonne = LARGEUR / 2;
    p_tetromino->pos_ligne = 0;
    for (i = 0; i < 4; i++) {
        p_tetromino->la_piece[i] = tab[i];
    }

    p_tetromino->type = indice;
}

/* Afficher toutes les pieces, permet de tester si les pieces sont bien
 * declarees */
void afficher_toutes_pieces(char *color[], struct une_case tab_pieces[7][4]) {
    int i;
    int lig = 0;
    struct piece tetromino;

    for (i = 0; i < 7; i++) {
        initialiser(&tetromino, tab_pieces[i], i);
        tetromino.pos_ligne = lig;
        lig = lig + 3;
        afficher_piece(tetromino, color[tetromino.type]);
    }
}
int ok(int plateau[HAUTEUR][LARGEUR], struct piece *temp) {
    int i;
    int x, y;
    for (i = 0; i < 4; i++) {
        x = temp->pos_ligne + temp->la_piece[i].ligne;
        y = temp->pos_colonne + temp->la_piece[i].colonne;
        if (x >= 0 && x < HAUTEUR && y >= 0 && y < LARGEUR) {
            if (plateau[x][y] != -1) {
                return 0;
            }
        } else {
            return 0;
        }
    }
    return 1;
}
void afficher_plateau(int plateau[HAUTEUR][LARGEUR], char **color) {
    CINI_fill_window("black");
    int i, j;
    for (i = 0; i < HAUTEUR; i++) {
        for (j = 0; j < LARGEUR; j++) {
            if (plateau[i][j] != -1) {
                CINI_fill_rect(j * TAILLE_CASE, i * TAILLE_CASE, TAILLE_CASE,
                               TAILLE_CASE, color[plateau[i][j]]);
            }
        }
    }
}

void decaler_gauche(int plateau[HAUTEUR][LARGEUR], struct piece *temp) {
    temp->pos_colonne -= 1;
    if (!ok(plateau, temp)) {
        temp->pos_colonne += 1;
    }
}

void decaler_droit(int plateau[HAUTEUR][LARGEUR], struct piece *temp) {
    temp->pos_colonne += 1;
    if (!ok(plateau, temp)) {
        temp->pos_colonne -= 1;
    }
}

void rotation_droite(int plateau[HAUTEUR][LARGEUR], struct piece *temp) {
    int i, t;
    for (i = 0; i < 4; i++) {
        t = temp->la_piece[i].colonne;
        temp->la_piece[i].colonne = -1 * temp->la_piece[i].ligne;
        temp->la_piece[i].ligne = t;
    }
    if (!ok(plateau, temp)) {
        for (i = 0; i < 4; i++) {
            t = temp->la_piece[i].colonne;
            temp->la_piece[i].colonne = temp->la_piece[i].ligne;
            temp->la_piece[i].ligne = -t;
        }
    }
}
void rotation_gauche(int plateau[HAUTEUR][LARGEUR], struct piece *temp) {
    int i, t;
    for (i = 0; i < 4; i++) {
        t = temp->la_piece[i].ligne;
        temp->la_piece[i].ligne = -1 * temp->la_piece[i].colonne;
        temp->la_piece[i].colonne = t;
    }
    if (!(ok(plateau, temp))) {
        for (i = 0; i < 4; i++) {
            t = temp->la_piece[i].ligne;
            temp->la_piece[i].ligne = temp->la_piece[i].colonne;
            temp->la_piece[i].colonne = -t;
        }
    }
}

void descendre(int plateau[HAUTEUR][LARGEUR], struct piece *temp) {
    temp->pos_ligne += 1;
    if (!ok(plateau, temp)) {
        temp->pos_ligne -= 1;
    }
}

void hard_drop(int plateau[HAUTEUR][LARGEUR], struct piece *temp) {
    while (ok(plateau, temp)) {
        temp->pos_ligne += 1;
    }
    temp->pos_ligne -= 1;
}

void engister(int plateau[HAUTEUR][LARGEUR], struct piece *temp) {
    int i, x, y;
    for (i = 0; i < 4; i++) {
        x = temp->pos_ligne + temp->la_piece[i].ligne;
        y = temp->pos_colonne + temp->la_piece[i].colonne;
        plateau[x][y] = temp->type;
    }
}

void supprimer_lignes(int plateau[HAUTEUR][LARGEUR]) {
    int i, j, b;
    for (i = HAUTEUR - 1; i >= 0; i--) {
        b = 1;
        for (j = 0; j < LARGEUR; j++) {
            if (plateau[i][j] == -1) {
                b = 0;
            }
        }
        if (b) {
            for (b = i; b >= 0; b--) {
                for (j = 0; j < LARGEUR; j++) {
                    plateau[b][j] = plateau[b - 1][j];
                }
            }
            for (j = 0; j < LARGEUR; j++) {
                plateau[0][j] = -1;
            }
        }
    }
}
/*---------------------------------------------------------------------*/

int main(int argc, char *argv[]) {
    /*---------------------   les declarations   ---------------------*/

    int indice; /* l'indice (type) de la piece jouee */
    int touche; /* identifie la frappe du joueur */
    struct piece temp;

    char *color[] = {"light salmon", "fuchsia", "lime green", "white",
                     "yellow",       "cyan",    "grey"};

    struct une_case tab_pieces[7][4] = {
        {{0, 0}, {0, 1}, {1, 0}, {1, 1}}, {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
        {{0, 0}, {0, 1}, {0, 2}, {1, 2}}, {{0, 2}, {1, 0}, {1, 1}, {1, 2}},
        {{0, 0}, {1, 0}, {1, 1}, {2, 1}}, {{0, 1}, {1, 0}, {1, 1}, {2, 0}},
        {{0, 0}, {1, 0}, {1, 1}, {2, 0}}};

    int plateau[HAUTEUR][LARGEUR];
    // char couleur[HAUTEUR][LARGEUR];

    /*--------------------  les initialisations  ---------------------*/

    // plateau
    int i, j;
    for (i = 0; i < HAUTEUR; i++) {
        for (j = 0; j < LARGEUR; j++) {
            plateau[i][j] = -1;
        }
    }

    srand(time(NULL));

    /* (a completer) */

    /*----------------------  ouverture de la fenetre graphique
     * -------*/

    CINI_open_window(LARGEUR * TAILLE_CASE, HAUTEUR * TAILLE_CASE, "black");

    /* Affichage de test des pieces */
    /* Instruction a mettre en commentaire pour la suite */
    afficher_toutes_pieces(color, tab_pieces);
    CINI_loop_until_keyup();

    /*----------------------  la boucle de jeu  ----------------------*/

    do {
        /* afficher_plateau( );*/
        afficher_plateau(plateau, color);
        indice = rand() % 7;
        /* initialiser( ); */
        initialiser(&temp, tab_pieces[indice], indice);
        /* afficher_piece( ); */
        afficher_piece(temp, color[indice]);

        do {
            touche = CINI_loop_until_keyup();
            /* afficher_piece( ); */ /* "efface" la piece en l'affichant
                                      * en noir
                                      * ...
                                      */
            /* descendre( ); */
            switch (touche) {
                case SDLK_LEFT:
                    decaler_gauche(plateau, &temp);
                    break;
                case SDLK_RIGHT:
                    decaler_droit(plateau, &temp);
                    break;
                case SDLK_d:
                    rotation_gauche(plateau, &temp);
                    break;
                case SDLK_g:
                    rotation_droite(plateau, &temp);
                    break;
                case SDLK_LSHIFT:
                    descendre(plateau, &temp);
                    break;
                case SDLK_ESCAPE:
                    exit(0);
                /*case SDLK_g:
           hard_drop( );
           break; */
                default:
                    break;
            }
            /* afficher_piece( ); */
            afficher_plateau(plateau, color);
            afficher_piece(temp, color[indice]);
            /* ... avant de la reafficher
                                                                  apres
               modification
             */
        } while ((touche != SDLK_DOWN) && (touche != SDLK_BACKSPACE));

        hard_drop(plateau, &temp);
        engister(plateau, &temp);

        /* on supprime les lignes completes si elles existent */
        // /* supprimer_lignes( ); */
        supprimer_lignes(plateau);
        afficher_plateau(plateau, color);

    } while (touche != SDLK_ESCAPE);

    return 0;
}
