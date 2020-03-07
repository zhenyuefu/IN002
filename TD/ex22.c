#include <malloc.h>

char *int_to_str(int val) {
  int i, nbch = 0, tmp = val;
  char *chval;
  do {
    nbch++;
    tmp = tmp / 10;
  } while (tmp != 10);
  chval = malloc((nbch + 1) * sizeof(char));
  chval[nbch] = '\0';
  for (i = nbch - 1; i > 0; i--) {
    chval[i] = (val % 10) + 48;
    val /= 10;
  }
  return chval;
}