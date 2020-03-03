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

int lancer(int nbQuillDebout) {
  int nbRenverse;
  scanf("%d", &nbRenverse);
  while (nbRenverse <= 0 || nbRenverse >= nbQuillDebout) {
    scanf("%d", &nbRenverse);
  }
  return nbRenverse;
}

int lancer_aleatoire(int nbQuillDebout) {
  int nbRenverse = rand() % (nbQuillDebout + 1);
  return nbRenverse;
}

void score(int *score, int *strike, int *spare,int nbRenverse) {

}

void tour(int *scoreTotal, int *strike,int *spare) {
  int nbQuillDebout = NBQUILLES;
  int nblancer = 1;
  int nbRenverse = 0;
  while (nbQuillDebout != 0 && nblancer <= NBLANCERS){
    nbRenverse = lancer_aleatoire(nbQuillDebout);
    nbQuillDebout = nbQuillDebout - nbRenverse;
    nblancer++;
    if (nblancer == 1 && nbQuillDebout == 0) {
      *strike = 1;
      score(scoreTotal,strike,spare,nbRenverse);
      break;
    }
    if (nblancer == 2 && nbQuillDebout == 0) {
      *spare = 1;
    }
  }
  score(scoreTotal, strike, spare);
}

int jeu() {
  int scoreTotal = 0;
  int spare = 0, strike = 0;
  for (int i = 0; i < NBTOURS; i++) {
    tour(&scoreTotal ,&strike,&spare);
  }
  if (strike==1){
    strike = 0;
    spare = 0;
    tour(&scoreTotal ,&strike,&spare);
  }
  else if (spare == 1) {
    strike = 0;
    spare = 0;
    tour(&scoreTotal ,&strike,&spare);
  }
  return scoreTotal ;
}

int main() {
  srand(time(NULL));
  jeu();
  return 0;
}