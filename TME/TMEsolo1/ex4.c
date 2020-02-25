#include <stdio.h>

#define VAL1 20
#define VAL2 11
#define VAL3 7

void ma_fonction(int a, int b, int c, int *somme, int *somme_carres) {
  *somme = a + b + c;
  *somme_carres = a * a + b * b + c * c;
}

void afficherResultat(int somme, int somme_carres) {
  printf("Somme=%d, Somme carres=%d\n", somme, somme_carres);
}

int main() {
  int v1 = VAL1, v2 = VAL2, v3 = VAL3;
  int somme, somme_carres;
  ma_fonction(v1, v2, v3, &somme, &somme_carres);
  afficherResultat(somme, somme_carres);
  return 0;
}
