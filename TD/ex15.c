void permute(int *a, int *b){
  int tmp;
  tmp = * a;
  * a = * b;
  * b = tmp;
}

void permute_circulaire(int *v1, int *v2, int *v3){
  permute(&v1,&v2);
  permute(&v2,&v3);
}

int main(void){
  int a,b,c;
  a=10;b=20;c=30;
  permute_circulaire(&a,&b,&c);
}