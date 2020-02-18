#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NBTOURS 10
#define NBLANCERS 2
#define NBQUILLES 10

/* Il sera probablement n�cessaire de modifier les parametres et valeur de
  retour des fonctions lancer, lancer_aleatoire, score et jeu */

/* Les declarations actuelles permettent de compiler et d'executer le programme
 */

int lancer() {}

int lancer_aleatoire(int nbQuillDebout) {
  int nbRenverse = rand() % (nbQuillDebout + 1);
  return nbRenverse;
}

void score() {}

void tour() {}

int jeu() { return 0; }

int main() {
  srand(time(NULL));
  jeu();
  return 0;
}