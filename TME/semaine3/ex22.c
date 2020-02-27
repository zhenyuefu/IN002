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

int lancer(int LAN) {
  int n = -1;
  while (n > LAN || n < 0) {
    printf("please type your lancer entre 0 and %d:__\b\b", LAN);
    scanf("%d", &n);
  }

  return n;
}

int lancer_aleatoire(int LAN) {
  // int lancer(int LAN) {
  return rand() % LAN;
}

void score(int new1, int new2, int *score, int b, int tour, int *temp) {
  printf("temp origin=%d\n", *temp);
  if (*temp == 1) {
    *score += new1;
    *temp -= 1;
  } else if (*temp >= 2) {
    if (new2 >= 0) {
      *score += new1 + new2;
      *temp -= 2;
    } else {
      *score += new1;
      *temp -= 1;
    }
  }
  if (*temp >= 2) {
    *score += new1;
    *temp -= 1;
  }

  printf("temp final=%d\n", *temp);

  *score += new1;
  if (new2 >= 0) {
    *score += new2;
  }

  printf("Score apres tour %d: %d \n", tour, *score);
  if (b == 1) {
    printf("score incomplet : spare en cours\n");
  } else if (b == 2) {
    printf("score incomplet : strike en cours\n");
  }
}

void TOUR(int *somme, int *tour, int *s_or_n, int *temp) {
  int score1 = 0;
  int score2 = -1;
  *temp += *s_or_n;
  // TOUR NORMAL
  printf("TOUR%d\n", *tour);
  score1 = lancer(NBQUILLES);
  printf("Quilles renversees :%d\n", score1);
  if (score1 < NBQUILLES) {
    score2 = lancer(NBQUILLES - score1);
    printf("Quilles renversees :%d\n", score2);
    if (score2 + score1 == NBQUILLES) {
      *s_or_n = 1;
    } else {
      *s_or_n = 0;
    }
  } else {
    *s_or_n = 2;
  }
  score(score1, score2, somme, *s_or_n, *tour, temp);

  // TOUR SUPPLEMENTAIRE
  if (*tour == 10 && *s_or_n > 0) {
    printf("TOUR SUPPLEMENTAIRE\n");
    if (*s_or_n == 2) {
      score1 = lancer(NBQUILLES);
      *somme += score1;
      if (score1 < 10) {
        score2 = lancer(NBQUILLES - score1);
      } else {
        score2 = lancer(NBQUILLES);
      }
      printf("Quilles renversees :%d\n", score1);
      *somme += score2;
      printf("Quilles renversees :%d\n", score2);
    } else {
      score1 = lancer(NBQUILLES);
      *somme += score1;
      printf("Quilles renversees :%d\n", score1);
    }
    if (temp > 0) {
      *somme += score1;
    }
    printf("Score apres tour supplementaire : %d\n", *somme);
  }
}

int jeu() {
  int somme = 0, s_or_n = 0, temp = 0;
  int tour;
  for (tour = 1; tour <= NBTOURS; tour++) {
    TOUR(&somme, &tour, &s_or_n, &temp);
  }
  return 0;
}

int main() {
  srand(time(NULL));
  jeu();
  return 0;
}