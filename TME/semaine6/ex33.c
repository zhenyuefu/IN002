#include <stdio.h>

int est_deb(char *, char *);
int est_incluse(char *, char *);

int main(void) {
  char *chaine1 = "beta", *chaine2 = "alphabet";
  printf("%d\n", est_deb(chaine1, chaine2));
  if (est_incluse(chaine1, chaine2) == 1) {
    printf("%s est incluse dans %s", chaine1, chaine2);
  }
  if (est_incluse(chaine1, chaine2) == 0) {
    printf("%s n'est pas incluse dans %s", chaine1, chaine2);
  }
  return 0;
}

int est_deb(char *ch1, char *ch2) {
  if (*ch1 == '\0') {
    return 1;
  }
  if ((*ch1 != '\0' && *ch1 != *ch2) || (*ch2 == '\0')) {
    return 0;
  }
  return est_deb(ch1 + 1, ch2 + 1);
}

int est_incluse(char *ch1, char *ch2) {
  if (est_deb(ch1, ch2) == 1) {
    return 1;
  }
  if (*ch2 == '\0') {
    return 0;
  }
  return est_incluse(ch1, ch2 + 1);
}
