#include <stdio.h>

void affiche_tab(float tab[],int taille){
  int i;
  for (i=0; i < taille; i++){
    printf("%2.f\t",tab[i]);
  }
  printf("\n");
}

void affiche_p(float tab[],int taille, int p){
  int i;
  printf("%2.f\t",tab[0]);
  for (i=1;i<taille;i++){
    if (i % p == 0)
      printf("\n");
    printf("%2.f\t",tab[i]);
  }
  printf("\n");
}

void echange(float tab[],int i, int j){
  float tmp = tab[i];
  tab[i] = tab[j];
  tab[j] = tmp;
}

int main(void){
  int i=0,j=2;
  float tab[3] = {1.0,2.5,3.8};
  affiche_tab(tab,3);
  echange(tab,0,2);
  affiche_tab(tab,3);
  return 0;
}