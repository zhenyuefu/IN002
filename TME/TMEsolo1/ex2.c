/*
   Nous souhaitons ecrire un programme calculant le prix a payer pour l'achat de
2 articles de prix PRIX1 et PRIX2 sachant qu'une reduction de REDUC% est faite
automatiquement. A cette premiere reduction s'ajoute ensuite une reduction de
FIDELITE% pour les porteurs de la carte de fidelite de l'enseigne.

 Completez les fonctions :
- prix, qui prend en parametres le prix de chacun des deux articles (un reel),
le statut du client (un caratere, 'F' s'il est porteur de la carte de fidelite
et tout autre caractere sinon) et qui renvoie le prix a payer.
- main, pour que le prix a payer soit affiche (vous devez remplacer les ... en
parametre de la fonction printf)

 Les valeurs initiales des prix, de REDUC, FIDELITE et STATUT sont definies par
des primitives #define.

 Pour tester votre programme vous pouvez bien sur modifier les valeurs associees
a PRIX1, PRIX2, sREDUC, FIDELITE et STATUT.

*/

#include <stdio.h>
#define PRIX1 30
#define PRIX2 70
#define REDUC 30.0
#define FIDELITE 10.0
#define STATUT 'F'

float prix(int prix1, int prix2, char statut) {
  float prixPayer;
  prixPayer = prix1 + prix2;
  prixPayer = prixPayer * (1 - REDUC / 100);
  if (statut == 'F') {
    prixPayer = prixPayer * (1 - FIDELITE / 100);
  }
  return prixPayer;
}

int main() {
  printf("Prix a payer : %.2f\n", prix(PRIX1, PRIX2, STATUT));
  return 0;
}