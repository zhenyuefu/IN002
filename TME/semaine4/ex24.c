#include <stdio.h>
#define taille 10

int nbEl = 0;

int indiceInsert(int tab[taille], int el) {
  if (nbEl == taille)
    return -1;
  if (nbEl == 0)
    return 0;
  if (el < tab[0])
    return 0;
  for (int i = 0; i <= nbEl; i++) {
    if (tab[i] == el)
      return -1;
    if (tab[i] < el && tab[i + 1] > el) {
      return i;
    }
  }
  return nbEl;
}

int insertElt(int tab[taille], int el) {
  int indice = indiceInsert(tab, el);
  if (indice == -1)
    return 0;
  nbEl++;
  for (int j = nbEl; j > indice; j--) {
    tab[j] = tab[j - 1];
  }
  tab[indice] = el;
  return 1;
}

int main(void) {
  int tab[taille] = {0};
  int el, stats;
  for (int i = 0; i <= taille; i++) {
    printf("input a number:");
    scanf("%d", &el);
    stats = insertElt(tab, el);
    if (stats == 0)
      printf("insert failed\n");
    else {
      for (int j = 0; j < nbEl; j++) {
        printf("%d\t", tab[j]);
      }
      printf("\n");
    }
  }
  return 0;
}