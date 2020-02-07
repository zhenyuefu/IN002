#include <stdio.h>
float prixEntree(int nA, int nE) {
  int F = 0;
  if (nA % 2 == 0 && nA >= 0 && nE >= 0) {
    F = 1;
  }
  if (F == 0) {
    return nA * 22.7 + nE * 10.75;
  }
  if (nE % 3 == 0) {
    return (nA - 2) * 22.7 + (nE - 3) * 10.75 + 57.8;
  }
  return (nA - 2) * 22.7 + (nE - nE % 3) * 10.75 + 57.8;
}

int main(void) { printf("%f", prixEntree(2, 3)); }