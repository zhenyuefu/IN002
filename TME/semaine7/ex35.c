#include <stdio.h>
#define NB_PLANETES 8

struct planet {
    char nom[10];
    float densite;
    float kilometres;
    int satellites;
};

typedef struct planet planete;

void affichePlanete(planete p) {
    printf("%s : \n", p.nom);
    printf("densite=%.2f\n", p.densite);
    printf("sa distance au soleil en millions de kilometres=%.2f\n", p.kilometres);
    printf("le nombre de ses satellites=%d\n", p.satellites);
}

void afficheToutesPlanetes(planete p[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("----------------\n");
        affichePlanete(p[i]);
    }
}

void modifieDensite(planete *p,float densite){
    p->densite=densite;
}

int main() {
    planete systemeSolaire[NB_PLANETES] = {{"Mercure", 5.42, 58, 0}, {"Venus", 5.25, 108.2, 0}, {"Terre", 5.52, 149.6, 1}, {"Mars", 3.94, 227.9, 2}, {"Jupiter", 1.314, 778.3, 16}, {"Saturne", 0.69, 1427, 17}, {"Uranus", 1.19, 2869, 15}, {"Neptune", 1.6, 4496, 2}};
    afficheToutesPlanetes(systemeSolaire,NB_PLANETES);
    return 0;
}