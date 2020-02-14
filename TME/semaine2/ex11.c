#include <stdio.h>
int jour(double e, double total, float final) {
  double somme = 1;
  int i = 0;
  while ((somme / total) < (final / 100)) {
    somme = somme * e;
    i = i + 1;
  }
  return i;
}

float pourcentage(double e, double total, double jour) {
  double somme = 1;
  int i;
  for (i = 1; i <= jour; i++) {
    if (somme >= total) {
      return 100;
    }
    somme = somme * e;
  }
  return somme / total * 100;
}

double main(void) {
  printf("%d\n", jour(3, 100000, 10));
  printf("%f", pourcentage(3, 10000000, 13));
  return 0;
}