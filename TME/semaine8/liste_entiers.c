#include "liste_entiers.h"

#include <stdio.h>
#include <stdlib.h>

cellule_t *creerListe(int n) {
  /* cree une liste de n entiers saisi par l'utilisateur
    renvoie l'adresse du premier element de la liste */
  int i;
  int val;
  cellule_t *tete = NULL;
  cellule_t *ptr;

  printf("Saisie des %d elements de la liste\n", n);
  for (i = 0; i < n; i++) {
    printf("Element %d :", i + 1);
    scanf("%d", &val);
    ptr = malloc(sizeof(cellule_t));
    ptr->donnee = val;
    ptr->suivant = tete;
    tete = ptr;
  }
  return tete;
}

void AfficherListeInt(cellule_t *liste) {
  cellule_t *current;
  current = liste;
  while (current != NULL) {
    printf("%d ", current->donnee);
    current = current->suivant;
  }
}

int nb_occurences(int val, cellule_t *liste) {
  int nombre = 0;
  cellule_t *current;
  current = liste;
  while (current != NULL) {
    if (current->donnee == val) {
      nombre++;
    }
    current = current->suivant;
  }
  return nombre;
}

int tous_plus_grand(int val, cellule_t *liste) {
  int tpg = 1;
  cellule_t *current;
  current = liste;
  while (current != NULL) {
    if (current->donnee < val) {
      tpg = 0;
    }
    current = current->suivant;
  }
  return tpg;
}

cellule_t *Maximum(cellule_t *liste) {
  cellule_t *current, *maximum;
  current = liste;
  maximum = liste;
  while (current != NULL) {
    if (current->donnee > maximum->donnee) {
      maximum = current;
    }
    current = current->suivant;
  }
  return maximum;
}

int Renvoyer_val_element_pos(int pos, cellule_t *liste) {
  int i;
  cellule_t *current;
  current = liste;
  for (i = 0; i <= pos; i++) {
    current = current->suivant;
  }
  return current->donnee;
}

cellule_t *Concatener_it(cellule_t *liste1, cellule_t *liste2) {
  cellule_t *current;
  if (liste1 == NULL) {
    if (liste2 == NULL) {
      return NULL;
    }
    return liste2;
  }
  current = liste1;
  while (current != NULL) {
    current = current->suivant;
  }
  current->suivant = liste2;
  return liste1;
}

int nb_maximum(cellule_t *liste) {
  cellule_t *current;
  int nb, max;
  current = liste;
  max = current->donnee;
  nb = 0;
  while (current != NULL) {
    if (current->donnee > max) {
      max = current->donnee;
      nb = 0;
    }
    if (current->donnee == max) {
      nb++;
    }
    current = current->suivant;
  }
  return nb;
}
