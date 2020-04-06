#include <stdio.h>

#include "liste_entiers.h"

int main(void) {
  cellule_t *ma_liste = creerListe(5);
  int nb_occ;
  AfficherListeInt(ma_liste);
  printf("\n");
  nb_occ = nb_occurences(5, ma_liste);
  printf("5 occurence %d fois\n", nb_occ);
  if (tous_plus_grand(5, ma_liste)) {
    printf("5 est plus grand\n");
  }
  printf("le plus grand: %d\n", Maximum(ma_liste)->donnee);
  printf("5 eme element est: %d\n", Renvoyer_val_element_pos(5, ma_liste));
  return 0;
}
