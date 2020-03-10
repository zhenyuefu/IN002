#include <stdio.h>
#include <stdlib.h>
#define N 3
void init(char plateau[N][N]) {
    int i;
    int j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            plateau[i][j] = '_';
        }
    }
}

void afficher(char plateau[N][N]) {
    int i;
    int j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%c  ", plateau[i][j]);
        }
        printf("\n");
    }
}
int choisir_menu12q() {
    printf("1. partie a 2 joueurs\n2. partie contre l’ordinateur\n3. quitter\n");
    int p;
    if (scanf("%d", &p) == 1) {
        if (p <= 3 && p >= 1) {
            return p;
        }
    }
}

void jouer(char plateau[N][N], int joueur) {
    int x, y;
    char s = 'O';
    if (joueur == 2) {
        s = 'X';
    }
    afficher(plateau);
    printf("row colom:_ _\b\b\b");
    scanf("%d %d", &x, &y);
    while (x, y > N || x, y <= 0 || plateau[x - 1][y - 1] != '_') {
        printf("wrong\nrow colom:_ _\b\b\b");
        scanf("%d %d", &x, &y);
    }

    plateau[x - 1][y - 1] = s;
    afficher(plateau);
}
void jouerOrdinateur(char plateau[N][N]) {
    int x = rand() % 3;
    int y = rand() % 3;
    while (x, y > N || x, y <= 0 || plateau[x][y] != '_') {
        int x = rand() % 3;
        int y = rand() % 3;
    }
    plateau[x][y] = 'O';
}
int partie_gagnee(char plateau[N][N]) {
    int i, j;
    char p = ' ';
    int b = 1;
    // chaque ligne
    for (i = 0; i < N; i++) {
        b = 1;
        p = ' ';
        for (j = 0; j < N; j++) {
            if (p == ' ') {
                p = plateau[i][j];
            } else if (p != plateau[i][j] || p == '_') {
                b = 0;
            }
        }
        if (b == 1) {
            return 1;
        }
    }
    //chaque colonnee
    for (j = 0; j <= N; j++) {
        p = ' ';
        b = 1;
        for (i = 0; i <= N; i++) {
            if (p == ' ') {
                p = plateau[i][j];
            } else if (p != plateau[i][j] || p == '_') {
                b = 0;
            }
        }
        if (b == 1) {
            return 1;
        }
    }
    // chaque diagonal
    p = ' ';
    b = 1;
    for (j = 0; j < N; j++) {
        if (p == ' ') {
            p = plateau[j][j];
        } else if (p != plateau[j][j] || p == '_') {
            b = 0;
        }
    }
    if (b == 1) {
        return 1;
    }
    p = ' ';
    b = 1;
    for (j = 0; j < N; j++) {
        if (p == ' ') {
            p = plateau[j][N - 1 - j];
        } else if (p != plateau[j][N - 1 - j] || p == '_') {
            b = 0;
        }
    }
    if (b == 1) {
        return 1;
    }
    return 0;
}

int si_rempli(char plateau[][N]) {
    int i = -1, j = -1;
    while (i++ < N) {
        j = 0;
        while (j++ < N) {
            if (plateau[i][j] == '_') {
                return 0;
            }
        }
    }
    return 1;
}
void jouer_a(char plateau[N][N], int nb_joueurs) {
    int i;
    int j;
    int choice = choisir_menu12q();
    if (choice == 3) {
        exit(0);
    }
    while (si_rempli(plateau) == 0) {
        // joueur1
        if (choice == 1) {
            jouer(plateau, 1);
        } else {
            jouerOrdinateur(plateau);
        }
        if (partie_gagnee(plateau) == 1) {
            printf("joueur 1 win");
            break;
        } else if (si_rempli(plateau)) {
            printf("GAME OVER");
            break;
        }
        // joueur2
        jouer(plateau, 2);
        if (partie_gagnee(plateau) == 1) {
            printf("joueur 2 win");
            break;
        }
    }
}

int main() {
    char plateau[N][N];
    init(plateau);
    jouer_a(plateau, 2);
    return 0;
}