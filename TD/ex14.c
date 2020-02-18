#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_VALEURS 1000
#define VMIN 0
#define VMAX 32000

int valeur_aleatoire(int min, int max) {
  // renvoie une valeur choisie aleatoirement entre min et max
  int r = rand() % (max + 1) + min;
  return r;
}

int minimum(int val, int valMin) {
  // renvoie la plus petite valeur entre val et valMin
  if (val < valMin) {
    return val;
  }
  return valMin;
}

int maximum(int val, int valMax) {
  // renvoie la plus grande valeur entre val et valMax
  if (val > valMax) {
    return val;
  }
  return valMax;
}

void minimum_maximum(int val, int *val_min, int *val_max){
  if (val < * val_min){
    *val_min = val;
  }
  if (val > * val_max){
    *val_max = val;
  }
}

int main(void) {
  int i, val;
  int min = VMAX, max = VMIN;
  srand((unsigned)time(NULL));
  for (i = 0; i < NB_VALEURS; i++) {
    val = valeur_aleatoire(VMIN, VMAX);
    minimum_maximum(val,&min,&max);
  }
  printf("MIN = %d, MAX = %d\n", min, max);
  return 0;
}