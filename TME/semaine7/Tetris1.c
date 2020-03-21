#include <SDL/SDL.h>
#include <cini.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE_CASE 20
#define HAUTEUR 22
#define LARGEUR 10
#define VIDE 8
// n'importe quelle valeur qui n'est pas un indice du tableau des couleurs

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

void afficher_piece(struct piece, char *);
void initialiser(struct piece *, struct une_case[], int);
void afficher_toutes_pieces(char *[], struct une_case[][]);
void afficher_plateau(int[][], char *[]);
int descendre(int[][], struct piece *);
int decaler_gauche(int[][], struct piece *);
int decaler_droite(int[][], struct piece *);
int rotation_gauche(int[][], struct piece *);
int rotation_droite(int[][], struct piece *);
void supprimer_lignes(int[][]);
void save(int[][], struct piece *);
void hard_drop(int[][], struct piece *);
int filled(int[][], struct piece *);
int game_over(int[][], struct piece *);
/*---------------------------------------------------------------------*/

int main(int argc, char *argv[]) {
  /*---------------------   les declarations   ---------------------*/

  int indice; /* l'indice (type) de la piece jouee */
  int touche; /* identifie la frappe du joueur */

  int plateau_jeu[LARGEUR][HAUTEUR];
  char *color[] = {"light salmon", "fuchsia", "lime green", "white",
                   "yellow",       "cyan",    "grey"};
  struct une_case tab_pieces[7][4] = {
      {{0, 0}, {0, 1}, {1, 0}, {1, 1}}, {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
      {{0, 0}, {0, 1}, {0, 2}, {1, 2}}, {{0, 2}, {1, 0}, {1, 1}, {1, 2}},
      {{0, 0}, {1, 0}, {1, 1}, {2, 1}}, {{0, 1}, {1, 0}, {1, 1}, {2, 0}},
      {{0, 0}, {1, 0}, {1, 1}, {2, 0}}};
  struct piece tetromino_moving;
  int i, j;
  /*--------------------  les initialisations  ---------------------*/

  srand(time(NULL));

  for (i = 0; i < LARGEUR; i++) {
    for (j = 0; j < HAUTEUR; j++) {
      plateau_jeu[i][j] = VIDE;
    }
  }

  /*----------------------  ouverture de la fenêtre graphique -------*/

  CINI_open_window(LARGEUR * TAILLE_CASE, HAUTEUR * TAILLE_CASE, "black");

  /* Affichage de test des pieces */
  /* Instruction a mettre en commentaire pour la suite */
  // afficher_toutes_pieces(color, tab_pieces);

  /*----------------------  la boucle de jeu  ----------------------*/

  do {
    afficher_plateau(plateau_jeu, color);
    indice = rand() % 7;
    initialiser(&tetromino_moving, tab_pieces[indice], indice);
    if (game_over(plateau_jeu, &tetromino_moving)) {
      break;
    }
    afficher_piece(tetromino_moving, color[indice]);

    do {
      touche = CINI_loop_until_keyup();
      afficher_piece(tetromino_moving,
                     "black"); /* "efface" la piece en l'affichant en noir ...
                                */
      if (!descendre(plateau_jeu, &tetromino_moving)) {
        save(plateau_jeu, &tetromino_moving);
        break;
      }
      switch (touche) {
        case SDLK_LEFT:
          decaler_gauche(plateau_jeu, &tetromino_moving);
          break;
        case SDLK_RIGHT:
          decaler_droite(plateau_jeu, &tetromino_moving);
          break;
        case SDLK_d:
          rotation_gauche(plateau_jeu, &tetromino_moving);
          break;
        case SDLK_g:
          rotation_droite(plateau_jeu, &tetromino_moving);
          break;
        case SDLK_DOWN:
          hard_drop(plateau_jeu, &tetromino_moving);
          break;
        default:
          break;
      }
      afficher_piece(tetromino_moving,
                     color[indice]); /* ... avant de la reafficher
                                          apres modification
             */
    } while ((touche != SDLK_DOWN) && (touche != SDLK_ESCAPE));

    /* on supprime les lignes completes si elles existent */
    supprimer_lignes(plateau_jeu);

  } while (touche != SDLK_ESCAPE);
  return 0;
}

/*-------------------   INSERER ICI LES FONCTIONS   -------------------*/
/* Affiche une piece */
void afficher_piece(struct piece tetromino, char *couleur) {
  int i;
  int ligne_deb, colonne_deb;

  for (i = 0; i < 4; i++) {
    ligne_deb =
        (tetromino.pos_ligne + tetromino.la_piece[i].ligne) * TAILLE_CASE;
    colonne_deb =
        (tetromino.pos_colonne + tetromino.la_piece[i].colonne) * TAILLE_CASE;
    CINI_fill_rect(colonne_deb, ligne_deb, TAILLE_CASE, TAILLE_CASE, couleur);
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

void afficher_plateau(int plateau[LARGEUR][HAUTEUR], char *color[]) {
  int i, j;
  CINI_fill_window("black");
  for (i = 0; i < LARGEUR; i++) {
    for (j = 0; j < HAUTEUR; j++) {
      if (plateau[i][j] != VIDE)
        CINI_fill_rect(i * TAILLE_CASE, j * TAILLE_CASE, TAILLE_CASE,
                       TAILLE_CASE, color[plateau[i][j]]);
    }
  }
}

// return 1 if descendre,return 0 if not
int descendre(int plateau[LARGEUR][HAUTEUR], struct piece *tetromino) {
  int ligne_n, colonne_n;
  int i;
  tetromino->pos_ligne++;
  for (i = 0; i < 4; i++) {
    ligne_n = tetromino->pos_ligne + tetromino->la_piece[i].ligne;
    colonne_n = tetromino->pos_colonne + tetromino->la_piece[i].colonne;
    if (plateau[colonne_n][ligne_n] != VIDE || ligne_n >= HAUTEUR) {
      tetromino->pos_ligne--;
      return 0;
    }
  }
  return 1;
}

int decaler_gauche(int plateau[LARGEUR][HAUTEUR], struct piece *tetromino) {
  int colonne_n;
  int i;
  tetromino->pos_colonne--;
  for (i = 0; i < 4; i++) {
    colonne_n = tetromino->pos_colonne + tetromino->la_piece[i].colonne;
    if (colonne_n < 0 || filled(plateau, tetromino)) {
      tetromino->pos_colonne++;
      return 0;
    }
  }
  return 1;
}

int decaler_droite(int plateau[LARGEUR][HAUTEUR], struct piece *tetromino) {
  int colonne_n;
  int i;
  tetromino->pos_colonne++;
  for (i = 0; i < 4; i++) {
    colonne_n = tetromino->pos_colonne + tetromino->la_piece[i].colonne;
    if (colonne_n >= LARGEUR || filled(plateau, tetromino)) {
      tetromino->pos_colonne--;
      return 0;
    }
  }
  return 1;
}

int rotation_gauche(int plateau[LARGEUR][HAUTEUR], struct piece *tetromino) {
  int colonne_n[4], ligne_n[4];
  int p_colonne, p_ligne;
  int i;
  for (i = 0; i < 4; i++) {
    colonne_n[i] = tetromino->la_piece[i].ligne;
    ligne_n[i] = -tetromino->la_piece[i].colonne;
    p_colonne = tetromino->pos_colonne + colonne_n[i];
    p_ligne = tetromino->pos_ligne + ligne_n[i];
    if (p_colonne < 0 || p_colonne > LARGEUR || p_ligne < 0 ||
        p_ligne > HAUTEUR || plateau[p_colonne][p_ligne] != VIDE) {
      return 0;
    }
  }
  for (i = 0; i < 4; i++) {
    tetromino->la_piece[i].colonne = colonne_n[i];
    tetromino->la_piece[i].ligne = ligne_n[i];
  }
  return 1;
}

int rotation_droite(int plateau[LARGEUR][HAUTEUR], struct piece *tetromino) {
  int colonne_n[4], ligne_n[4];
  int p_colonne, p_ligne;
  int i;
  for (i = 0; i < 4; i++) {
    colonne_n[i] = -tetromino->la_piece[i].ligne;
    ligne_n[i] = tetromino->la_piece[i].colonne;
    p_colonne = tetromino->pos_colonne + colonne_n[i];
    p_ligne = tetromino->pos_ligne + ligne_n[i];
    if (p_colonne < 0 || p_colonne > LARGEUR || p_ligne < 0 ||
        p_ligne > HAUTEUR || plateau[p_colonne][p_ligne] != VIDE) {
      return 0;
    }
  }
  for (i = 0; i < 4; i++) {
    tetromino->la_piece[i].colonne = colonne_n[i];
    tetromino->la_piece[i].ligne = ligne_n[i];
  }
  return 1;
}

void supprimer_lignes(int plateau[LARGEUR][HAUTEUR]) {
  int complete;
  int c, l, ligne_down;
  for (l = 0; l < HAUTEUR; l++) {
    complete = 1;
    for (c = 0; c < LARGEUR; c++) {
      if (plateau[c][l] == VIDE) {
        complete = 0;
      }
    }
    if (complete) {
      for (ligne_down = l; ligne_down > 0; ligne_down--) {
        for (c = 0; c < LARGEUR; c++) {
          plateau[c][ligne_down] = plateau[c][ligne_down - 1];
        }
      }
      for (c = 0; c < LARGEUR; c++) {
        plateau[c][0] = VIDE;
      }
    }
  }
}

void save(int plateau[LARGEUR][HAUTEUR], struct piece *tetromino) {
  int i;
  int i_ligne, i_colonne;
  for (i = 0; i < 4; i++) {
    i_ligne = tetromino->pos_ligne + tetromino->la_piece[i].ligne;
    i_colonne = tetromino->pos_colonne + tetromino->la_piece[i].colonne;
    plateau[i_colonne][i_ligne] = tetromino->type;
  }
}

void hard_drop(int plateau[LARGEUR][HAUTEUR], struct piece *tetromino) {
  while (descendre(plateau, tetromino)) {
    ;
  }
  save(plateau, tetromino);
}

int filled(int plateau[LARGEUR][HAUTEUR], struct piece *tetromino) {
  int i;
  int i_ligne, i_colonne;
  for (i = 0; i < 4; i++) {
    i_ligne = tetromino->pos_ligne + tetromino->la_piece[i].ligne;
    i_colonne = tetromino->pos_colonne + tetromino->la_piece[i].colonne;
    if (plateau[i_colonne][i_ligne] != VIDE) {
      return 1;
    }
  }
  return 0;
}

int game_over(int plateau[LARGEUR][HAUTEUR], struct piece *tetromino) {
  if (filled(plateau, tetromino)) {
    CINI_fill_window("black");
    CINI_draw_string(10, (HAUTEUR / 2) * TAILLE_CASE - 10, "white",
                     "GAME OVER");
    CINI_loop_until_keyup();
    return 1;
  }
  return 0;
}
