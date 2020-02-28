#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define taille 10
#define maximum 1000

void placeElt(float tab[], int i) {
  int j = i - 1;
  float key = tab[i];
  while ((j >= 0) && (tab[j] > key)) {
    tab[j + 1] = tab[j];
    j--;
  }
  tab[j + 1] = key;
}

void initTable(float tab[]) {
  srand((unsigned)time(NULL));
  for (int i = 0; i < taille; i++) {
    tab[i] = (rand() % maximum) / 10;
  }
}

void affichage(float tab[]) {
  for (int i = 0; i < taille; i++) {
    printf("%.2f  ", tab[i]);
  }
}

int main(void) {
  float tab[taille];
  initTable(tab);
  for (int i = 0; i < taille; i++) {
    placeElt(tab, i);
  }
  affichage(tab);
  return 0;
}