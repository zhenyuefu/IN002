#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

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

void afficheRes(int resultat[]) {
  for (int i = 0; i < N; i++) {
    printf("%d ", resultat[i]);
  }
}

int main(void) {
  int pc[N] = {17, 28, 50, 5};
  int res[N] = {0, 0, 0, 0};
  calcule_bornes_sup(pc);
  srand(time(NULL));
  for (int i = 0; i < 10000; i++) {
    res[tire_non_equi(pc)]++;
  }
  afficheRes(res);
  return 0;
}