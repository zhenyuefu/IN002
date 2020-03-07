#include <cini.h>
#include <stdlib.h>
#include <time.h>

#define N 4
#define COEFX 50 /* coefficients d'echelle */
#define COEFY 38
#define DX 250 /* position dans la fenetre */
#define DY 420

void calcule_bornes_sup(int pourcentages[]) {
  pourcentages[0] -= 1;
  for (int i = 1; i < N; i++) {
    pourcentages[i] = pourcentages[i - 1] + pourcentages[i];
  }
}

int tire_non_equi(int bornes[]) {
  int nbTire;
  nbTire = rand() % 100;
  for (int i = 0; i < N; i++) {
    if (nbTire <= bornes[i]) {
      return i;
    }
  }
  return -1;
}

int main(void) {

  float tab_A[N] = {0.5, 0.2, -0.15, 0.85};  /* les coefficients a_i */
  float tab_B[N] = {0, -0.26, 0.28, 0.04};   /* les coefficients b_i */
  float tab_C[N] = {0, 0.23, 0.26, -0.04};   /* les coefficients c_i */
  float tab_D[N] = {0.16, 0.22, 0.24, 0.85}; /* les coefficients d_i */
  float tab_E[N] = {0, 0, 0, 0};             /* les coefficients e_i */
  float tab_F[N] = {0, 1.6, 0.44, 1.6};      /* les coefficients f_i */

  int tab_P[N] = {1, 7, 7, 85}; /* pourcentages de chaque transformation */

  char *couleurs[N] = {"lime green", "fuchsia", "yellow", "turquoise"};

  /* Definition de variables supplementaires si necessaire */
  int nbTrans;
  float x = 0.0, y = 0.0;
  float xpre, ypre;
  /* Calcul des bornes des intervalles */
  calcule_bornes_sup(tab_P);
  srand(time(NULL));

  CINI_open_window(500, 500, "feuille");

  do {

    /* Choix du numero de la transformation a appliquer */

    nbTrans = tire_non_equi(tab_P);

    /* Calcul du point a tracer (coordonnees x et y) */
    xpre = x;
    ypre = y;
    x = xpre * tab_A[nbTrans] + ypre * tab_B[nbTrans] + tab_E[nbTrans];
    y = xpre * tab_C[nbTrans] + ypre * tab_D[nbTrans] + tab_F[nbTrans];

    CINI_draw_pixel(DX + x * COEFX, DY - y * COEFY, couleurs[nbTrans]);

  } while (!CINI_key_down());

  return 0;
}
