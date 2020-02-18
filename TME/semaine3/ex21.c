#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PIERRE 1
#define FEUILLE PIERRE+1
#define CISEAUX FEUILLE+1
#define NBESSAIS 3
#define POINTSGAGNANTS 3 

  /* Il sera probablement n�cessaire de modifier les parametres et valeur de retour des fonctions 
    choix_ordinateur, choix_joueur, score et jeu */

  /* Les declarations actuelles permettent de compiler et d'executer le programme */

void affichage_objet(int obj){
  /* hypoth�se : obj = PIERRE ou
     obj = FEUILLE ou obj = CISEAUX
   
   affiche le nom de l'objet correspondant � obj */
  
  if (obj == PIERRE){
    printf("PIERRE");
  } else {
    if (obj == FEUILLE){
      printf("FEUILLE");
    } else {
      printf("CISEAUX");
    }
  }
}

int choix_ordinateur(void) {
/* hypoth�se : PIERRE < FEUILLE < CISEAUX
  toutes les valeurs comprises entre PIERRE et CISEAUX sont "valables"
  renvoie une valeur choisie al�atoirement entre PIERRE et CISEAUX */
  return rand()%3+1;
}

int choix_joueur() {
/* hypoth�ses : PIERRE < FEUILLE < CISEAUX 
  renvoie la valeur choisie par le joueur
  v�rifie qu'elle est comprise entre PIERRE et CISEAUX 
  redemande la saisie si ce n'est pas le cas
  
  Si apr�s NBESSAIS le joueur n'a pas saisi de valeur valable,
  cette derni�re est tir�e au sort */
  int i;
  int a;
  for (i=1;i<=3;i++){
      printf("please type your choice\nPIERRE=1,FEUILLE=2, CISEAUX=3\n");
      scanf("%d",&a);
      if (a<=3 && a>=1){
          return a;
      }
  }
  return rand()%3+1;
}

void score(int *s_o,int *s_j,int c_o,int c_j){
    /* hypoth�ses : le coup du joueur et celui de l'ordinateur sont valables 
                    (�gaux � PIERRE, FEUILLE ou CISEAUX)
    augmente de 1 le score du joueur si le coup du joueur est gagnant
    augmente de 1 le score de l'ordinateur si le coup de l'ordinateur est gagnant */
    if (c_o-c_j==-1 || c_o-c_j==2){
        *s_j+=1;
    } else if(c_o==c_j){
    }else{
        *s_o+=1;
    }
}


void jeu() {
    /* boucle de jeu, la partie s'arr�te d�s qu'un des deux joueurs 
    atteint POINTSGAGNANTS points */
    int s_o=0;
    int s_j=0;
    int c_o;
    int c_j;
    int i=1;
    while (s_o<POINTSGAGNANTS && s_j<POINTSGAGNANTS && i<=NBESSAIS){
        printf("======round %d======\n",i);
        c_o=choix_ordinateur();
        c_j=choix_joueur();
        printf("choix_ordinateur est ");
        affichage_objet(c_o);
        printf("\n");
        printf("choix_joueur est ");
        affichage_objet(c_j);
        printf("\n");
        score(&s_o,&s_j,c_o,c_j);
        printf("score du_joueur=%d,score de l'ordinateur=%d\n",s_j,s_o);
        printf("\n");
        i+=1;
    } 
    printf("====== e n d ======\n");
    if (s_o<s_j){
        printf("le gagner est le joueur\n");
    }else if (s_o>s_j){
        printf("le gagner est l'ordinateur\n");
    }else{
        printf("match nul");
    }
}

int main() {
    srand(time(NULL));
    jeu();
    return 0;
}
