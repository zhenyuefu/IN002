#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_VALEURS 50
#define VMIN -20
#define VMAX 20

int valeur_aleatoire(int min, int max) {
    if (min >= 0) {
        return rand() % (max - min) + min;
    }
    return (rand() % (max - min)) + min;
}
void pos_neg_zero(int N) {
    if (N > 0) {
        printf("%d est positive\n", N);
    } else if (N < 0) {
        printf("%d est negative\n", N);
    } else {
        printf("%d est zero\n", N);
    }
}
int main() {
    /* initialisation du generateur de nombres aleatoires */
    int a;
    int i;
    srand(time(NULL));
    for (i = 1; i <= NB_VALEURS; i++) {
        a = valeur_aleatoire(VMIN, VMAX);
        pos_neg_zero(a);
    }
    a = valeur_aleatoire(VMIN, VMAX);
    return 0;
}