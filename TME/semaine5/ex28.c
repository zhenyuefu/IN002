#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_AMIS 3
#define NB_JOURS 7

void init(float tab[][NB_JOURS]) {
    int i;
    int j;
    for (i = 0; i < NB_AMIS; i++) {
        for (j = 0; j < NB_JOURS; j++) {
            tab[i][j] = 0;
        }
    }
}

void chacunjour(float tab[][NB_JOURS]) {
    int id;
    int somme;

    int i;
    int j;
    for (i = 0; i < NB_JOURS; i++) {
        somme = rand() % 50 + 30;
        id = rand() % (NB_AMIS);
        printf("\n%d pay %d", id, somme);
        for (j = 0; j < NB_AMIS; j++) {
            if (j == id) {
                tab[j][i] = ((float)somme) / NB_AMIS * (NB_AMIS - 1);
            } else {
                tab[j][i] = -((float)somme) / NB_AMIS;
            }
        }
    }
}

void affiche(float tab[][NB_JOURS]) {
    int i;
    int j;
    printf("\n\t|");
    for (i = 0; i < NB_JOURS; i++){
        printf("\t%d",i);

    }
    printf("\n----------------------------------------------------------------------");
    for (i = 0; i < NB_AMIS; i++) {
        printf("\n%d\t|\t",i);
        for (j = 0; j < NB_JOURS; j++) {
            printf("%.2f\t",tab[i][j]);
        }
    }
}

int main(void) {
    float tab[NB_AMIS][NB_JOURS];
    srand(time(NULL));
    init(tab);
    chacunjour(tab);
    affiche(tab);
    return 0;
}