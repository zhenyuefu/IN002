#include <stdio.h>
#define MAX 5
int premier(int n) {
  int premier = 1;
  int i = 2;
  for (i = 2; i < n / 2; i++) {
    if (n % i == 0) {
      premier = 0;
    }
  }
  return premier;
}

int premier_while(int n) {
  int premier = 1;
  int i = 2;
  while (i < n / 2 && premier) {
    if (n % i == 0) {
      premier = 0;
    }
    i++;
  }
  return premier;
}

void listeNombresPremiers(int n_max) {
  int i = 2;
  for (i = 2; i <= n_max; i++) {
    if (premier(i) == 1) {
      printf("%d\n", i);
    }
  }
}

int main() {
  printf("liste de nombres premiers <= %d\n", MAX);
  listeNombresPremiers(MAX);
  return 0;
}