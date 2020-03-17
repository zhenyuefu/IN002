#include <stdio.h>
#define NB_PLANETES 8

struct planete {
  char nom[11];
  float densite;
  float distanceAuSoleil;
  int nbSatellites;
};

void affichePlanete(const struct planete);
void afficheToutesPlanetes(const struct planete[], const int);
void modifieDensite(struct planete);

int main(void) {
  struct planete systemeSolaire[NB_PLANETES] = {
      {"Mercure", 5.42, 58, 0},      {"Venus", 5.25, 108.2, 0},
      {"Terre", 5.52, 149.6, 1},     {"Mars", 3.94, 227.9, 2},
      {"Jupiter", 1.314, 778.3, 16}, {"Saturne", 0.69, 1427, 17},
      {"Uranus", 1.19, 2869, 15},    {"Neptune", 1.6, 4496, 2}};
  char siModifie;
  int n;
  afficheToutesPlanetes(systemeSolaire, NB_PLANETES);
  printf("\nVoulez-vous modifier la densité?(y/n):");
  while (scanf("%c", &siModifie), (siModifie != 'y') && (siModifie != 'n')) {
    printf("enter y ou n\n");
  }
  if (siModifie == 'y') {
    printf("Quelle densité souhaitez-vous modifier:(enter numero)");
    scanf("%d", &n);
    modifieDensite(systemeSolaire[n - 1]);
  }
  return 0;
}

void affichePlanete(const struct planete unePlanete) {
  printf(
      "planete:%s\ndensite:%.2f\ndistance au soleil:%.2fkm\nnombre de ses "
      "satellites:%d\n",
      unePlanete.nom, unePlanete.densite, unePlanete.distanceAuSoleil,
      unePlanete.nbSatellites);
}

void afficheToutesPlanetes(const struct planete systeme[], const int taille) {
  for (int i = 0; i < taille; i++) {
    printf("%d.", i + 1);
    affichePlanete(systeme[i]);
  }
}

void modifieDensite(struct planete unePlanete) {
  float newDensite;
  printf("Combien voulez-vous modifier:");
  scanf("%f", &newDensite);
  unePlanete.densite = newDensite;
  printf("modifie success!\n");
  affichePlanete(unePlanete);
}