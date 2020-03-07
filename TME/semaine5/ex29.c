#include <stdio.h>
#include <stdlib.h>

void affiche(char *chaine) {
  int i = 0;
  while (chaine[i] != '\0') {
    if ((chaine[i] > 'a' && chaine[i] < 'z') ||
        (chaine[i] > 'A' && chaine[i] < 'Z')) {
      printf("%c", chaine[i]);
    }
    i++;
  }
  printf("\n");
}

char *conservantLettres(char *chaine) {
  char *lettres;
  int nbLettres = 0, i = 0, j = 0;
  while (chaine[i] != '\0') {
    if ((chaine[i] > 'a' && chaine[i] < 'z') ||
        (chaine[i] > 'A' && chaine[i] < 'Z')) {
      nbLettres++;
    }
    i++;
  }
  lettres = (char *)malloc(nbLettres * sizeof(char));
  i = 0;
  while (chaine[i] != '\0') {
    if ((chaine[i] > 'a' && chaine[i] < 'z') ||
        (chaine[i] > 'A' && chaine[i] < 'Z')) {
      lettres[j] = chaine[i];
      j++;
    }
    i++;
  }
  return lettres;
}

int main(void) {
  char *chaine = "2b2b2b";
  char *chaine2;
  affiche(chaine);
  chaine2 = conservantLettres(chaine);
  printf("%s\n", chaine2);
  return 0;
}