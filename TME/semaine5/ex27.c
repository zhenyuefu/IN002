#include <stdio.h>

int nbMots(char *chaineDeMots) {
  int i = 1, nb = 1;
  if (chaineDeMots[0] == '\0') {
    return 0;
  }
  while (chaineDeMots[i] != '\0') {
    if (chaineDeMots[i] == ' ' && chaineDeMots[i + 1] != ' ' &&
        chaineDeMots[i - 1] != ' ' && chaineDeMots[i + 1] != '\0') {
      nb++;
    }
    i++;
  }
  return nb;
}

int main(void) {
  char *chaine = "3 mots ici";
  printf("%d", nbMots(chaine));
  return 0;
}