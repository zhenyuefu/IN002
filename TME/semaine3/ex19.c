#include <stdio.h>
#define VAL1 2
#define VAL2 7
#define VAL3 5
#define VAL4 9

void min_max(int a, int b, int c, int *min, int *max) {
    if (a > b) {
        *max = a;
        *min = b;
    } else {
        *max = b;
        *min = a;
    }
    if (c > *max) {
        *max = c;
    } else if (c < *min) {
        *min = c;
    }
}

void afficher_resultat(float moy, int min, int max) {
    printf("max = %d, min = %d, moy = %.2f\n", max, min, moy);
}

void stats(int a, int b, int c, int d, int *min, int *max, float *moy) {
    float somme = 0;
    int tab[4] = {a, b, c, d};
    int i = 0;
    int temp1;
    int temp2;

    while (tab[i] > 0 && i <= 3) {
        i += 1;
    }

    if (i == 0) {
        *min = -1;
        *max = -1;
        *moy = -1;
    } else {
        if (i == 1) {
            *min = a;
            *max = a;
            somme = a;
        } else if (i == 2) {
            min_max(a, a, b, min, max);
            somme = (a + b);
        } else if (i == 3) {
            min_max(a, b, c, min, max);
            somme = (a + b + c);
        } else {
            min_max(a, b, c, &temp1, &temp2);
            min_max(d, temp1, temp2, min, max);
            somme = (a + b + c + d);
        }
        *moy = somme / i;
    }
}

int main() {
    float moy;
    int min, max;

    // /* vous devrez bien sur modifier les parametres d'appel de la fonction stats une fois cette derniere completee */
    stats(VAL1, VAL2, VAL3, VAL4, &min, &max, &moy);

    // /* vous devrez bien sur modifier les parametres d'appel de la fonction afficher_resultat */
    afficher_resultat(moy, min, max);

    return 0;
}