#difine NB_VILLES 5

void affiche_distances(int dist[NB_VILLES][NB_VILLES + 1]){
  int i,j;
  printf("km\t");
  for (i=0;i<NB_VILLES;i++){
    ptintf("%d\t",dist[i][0]);
  }
  printf("\n");
  for (i=0;i<NB_VILLES;i++){
    for (j=0;j<i;j++){
      printf("%d\t",dict[i][j]);
    }
    printf("-\t");
    for (j=i+2;j<NB_VILLES;j++){
      printf("%d\t",dict[i][j]);
    }
    printf("\n");
  }
}

int plus_proche(int ville,int dist[][NB_VILLES+1]){
  int i=0,j,j_min=1;
  while (i < NB_VILLES && dist[i][0] != ville){
    i++;
  }
  if (i == NB_VILLES){
    printf("%d n'est pas une ville dans tableau",ville);
    return -1;
  }
  else{
    if (dist[i][j_min] == 0){
      j_min = 2;
    }
    for (j=j_min+1;j<NB_VILLES;j++){
      if (dist[i][j] != 0 && dist[i][j] < dist[i][j_min]){
        j_min=j;
      }
    }
    return j_min-1;  
  }
}

int main(void){
  int distances[NB_VILLES] [NB_VILLES + 1] = {
{29, 0, 598, 900, 504, 995}, {59, 598, 0, 407, 203, 861}, {67, 900, 407, 0, 397, 621}, {75, 504, 203, 397, 0, 694}, {83, 995, 861, 621, 694, 0},
};
  return 0;
}