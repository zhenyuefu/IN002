/* Nous souhaitons afficher le nombre de multiples d'un nombre N1, qui sont
 aussi diviseurs d'un nombre N2

  Completez les fonctions :
 - compteMultDiv qui prend deux entiers en parametres et qui renvoie le nombre
 de multiples du premier entier qui sont aussi diviseurs du second,
  - main qui affiche le resultat attendu du programme (vous devez remplacer les
 ... de la fonction printf).

     Les valeurs de N1 et N2 sont definies par des primitives #define.

    Vous pouvez bien sur modifier les valeurs associees a N1 et N2 pour tester
 votre programme
*/

#include <stdio.h>

#define N1 3
#define N2 69

int compteMultDiv(int n1, int n2) {
  int i, nb = 0;
  for (i = n1; i <= n2; i++) {
    if ((i % n1 == 0) && (n2 % i == 0)) {
      nb++;
    }
  }
  return nb;
}

int main(void) {
  /* Affichage du nombre de diviseurs */
  printf("%d\n", compteMultDiv(N1, N2));
  return 0;
}