#include <stdio.h>

int compte(char chaine[],char cr){
  int i = 0;
  int compt = 0;
  while (chaine[i] != "\0"){
    if (chaine[i] == cr){
      compt ++;
    }
    i++;
  }
  return compt;
}

void affiche_occur(char chaine[]){
  int i = 0,j;
  while (chaine[i] != "\0"){
    j = 0;
    while (j<i && chaine[j] != chaine[i]){
      j++;
      }
    if (i==j){
      printf("%c apparait %d fois dans le tableau \n",chaine[i],compte(chaine+i,chaine[i]));
    }
    i++;
  }
}

int frequence_max(char chaine[]){
  int i, nb_i;
  int nb_max = compte(chaine,chaine[0]);
  int i_max = 0;
  i = 1;
  while (chaine[i] != "\0"){
    nb_i = compte(chaine,chaine[i]);
    if (nb_i > nb_max){
      i_max = i;
      nb_max = nb_i;
    }
    i++;
    }
  return i_max;
}

int main(void){
  char chaine[] = "hello, le soleil brille !";
  affiche_occur(chaine);
  int i_max;
  i_max = frequence_max(chaine);
  printf("le caractere le plus frequent dans le tableau et %c(%d occurences)\n",chaine[i_max],compte(chaine,chaine[i_max]));
  return 0; 
}