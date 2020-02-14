#include <stdio.h>

float prixEntree(int numberAdult, int numberChild) {
  int famille = 0;
  float prix = 0;
  while (numberChild >= 1 && numberAdult >= 2) {
    famille = famille + 1;
    prix = prix + 57.8;
    numberAdult = numberAdult - 2;
    numberChild = numberChild - 3;
  }
  prix = numberChild * 10.75 + numberAdult * 22.7 + prix;
  return prix;
}

int main(void) {
  printf("%f", prixEntree(25, 36));
  return 0;
}