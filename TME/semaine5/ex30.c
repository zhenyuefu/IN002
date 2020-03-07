#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 6
#define MAX 12

void init(int tab[], int T) {
    int i;
    for (i = 0; i < T; i++) {
        tab[i] = rand() % 2;
    }
    tab[T] = -1;
}

void affiche(int tab[]) {
    int i = 0;
    printf("\n");
    while (tab[i] != -1) {
        printf("%d  ", tab[i]);
        i++;
    }
}

int compress_tab(int tab_brut[], int tab_compress[]) {
    int ib = 0;
    int ic = 0;
    int p = 1;
    while (tab_brut[ib] != -1) {
        if (tab_brut[ib] == tab_brut[++ib]) {
            p++;
        } else if (p >= 2) {
            tab_compress[ic++] = p;
            tab_compress[ic++] = tab_brut[ib - 1];
            p = 1;
        } else {
            tab_compress[ic++] = tab_brut[ib - 1];
        }
    }
    tab_compress[ic] = -1;
    return 0;
}

int decompress_tab(int tab_brut[], int tab_compress[]) {
    int i;
    int ib = 0;
    int ic = 0;
    int p = 1;
    while (tab_compress[ic] != -1) {
        if (tab_compress[ic] > 1) {
            for (i = 0; i < tab_compress[ic]; i++) {
                tab_brut[ib++] = tab_compress[ic + 1];
            }
            ic += 2;
        } else {
            tab_brut[ib++] = tab_compress[ic++];
        }
    }
    tab_brut[ib] = -1;
    return 0;
}

int test_equi(int brut1[], int brut2[]) {
    int i = 0;
    while (brut1[i] != -1 || brut2[i] != -1) {
        if (brut1[i] != brut2[i]) {
            printf("\nFALSE");

            return 0;
        }
        i++;
    }
    printf("\nTRUE");
    return 1;
}

int main() {
    srand(time(NULL));
    int TAILLE = rand() % MAX + MIN;
    int brut[TAILLE + 1];
    int brut2[TAILLE + 1];
    int compress[TAILLE + 1];
    init(brut, TAILLE);
    affiche(brut);
    compress_tab(brut, compress);
    affiche(compress);
    decompress_tab(brut2, compress);
    affiche(brut2);
    test_equi(brut,brut2);
    return 0;
}