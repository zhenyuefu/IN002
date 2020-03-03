#include <stdio.h>

#define N 10

int iterative(char *tab1, char *tab2) {
  int i = 0;
  while ((tab1[i] != '\0') && (tab2[i] != '\0') && (tab1[i] == tab2[i])) {
    i++;
  }
  if (tab1[i] == tab2[i])
    return 1;
  return 0;
}

int recursive(char *tab1, char *tab2) {
  if ((*tab1 == '\0') && (*tab2 == '\0')) {
    return 1;
  }
  if (*tab1 != *tab2) {
    return 0;
  }
}

int main(void) {
  char *chaine1 = "il fait beau";
  char *chaine2 = "il fait beau!";
  if (iterative(chaine1, chaine2)) {
    printf("Les 2 chaines sont identiques\n");
  } else {
    printf("Les 2 chaines ne sont pas identiques\n");
  }
  return 0;
}