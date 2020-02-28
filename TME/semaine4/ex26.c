#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define taille1 9
#define taille2 7
#define maximum 100

void initTable(int tab[], int taille) {
  srand((unsigned)time(NULL));
  for (int i = 0; i < taille; i++) {
    tab[i] = (rand() % maximum);
  }
}

void placeElt(int tab[], int i) {
  int j = i - 1;
  int key = tab[i];
  while ((j >= 0) && (tab[j] > key)) {
    tab[j + 1] = tab[j];
    j--;
  }
  tab[j + 1] = key;
}

void tries(int tab1[], int tab2[], int tabresult[]) {
  int i1 = 0, i2 = 0;
  int i = 0;
  while ((i1 < taille1) && (i2 < taille2)) {
    if (tab1[i1] <= tab2[i2]) {
      tabresult[i] = tab1[i1];
      i1++;
    } else {
      tabresult[i] = tab2[i2];
      i2++;
    }
    i++;
  }
  if (i1 == taille1) {
    for (i = i; i < taille1 + taille2; i++) {
      tabresult[i] = tab2[i2];
      i2++;
    }
  } else {
    for (i = i; i < taille1 + taille2; i++) {
      tabresult[i] = tab1[i1];
      i1++;
    }
  }
}

void affichage(int tab[], int taille) {
  for (int i = 0; i < taille; i++) {
    printf("%d  ", tab[i]);
  }
  printf("\n");
}

int main(void) {
  int tab1[taille1], tab2[taille2];
  int tabresult[taille1 + taille2];
  initTable(tab1, taille1);
  for (int i = 0; i < taille1; i++) {
    placeElt(tab1, i);
  }
  initTable(tab2, taille2);
  for (int i = 0; i < taille2; i++) {
    placeElt(tab2, i);
  }
  affichage(tab1, taille1);
  affichage(tab2, taille2);
  tries(tab1, tab2, tabresult);
  affichage(tabresult, taille1 + taille2);
  return 0;
}