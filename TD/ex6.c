#include <assert.h>
int somme_carres(int m, int n) {
  int s, i;
  s = 0;
  i = m;
  while (i <= n) {
    s = s + i * i;
    i = i + 1;
  }
  return s;
}
int somme_carres_for(int m, int n) {
  int s, i;
  s = 0;
  for (i = m; i <= n; i++) {
    s = s + i * i;
  }
  return s;
}

int main() {
  assert(somme_carres(1, 5) == 55);
  return 0;
}