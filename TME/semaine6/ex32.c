#include <stdio.h>
#define N 5
int iterative(int r, int tab[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        if (tab[i] == r) {
            return 1;
        }
    }
}

int recursive(int r, int tab[], int len) {
    if (r == *tab) {
        return 1;
    } else if (len == 1) {
        return 0;
    } else {
        return recursive(r, ++tab, --len);
    }
}

int affche_TF(int k) {
    if (k == 1) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }
}

int main() {
    int r = 1;
    int tab[3] = {1, 2, 3};
    affche_TF(recursive(4, tab, 3));
    return 0;
}