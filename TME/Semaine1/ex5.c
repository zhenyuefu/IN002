#include <assert.h>
#include <math.h>
#include <stdio.h>
int descriminant(int a, int b, int c) {
  float delta = b * b - 4 * a * c;
  return delta;
}

void afficheRacines(int a, int b, int c) {
  int delta = descriminant(a, b, c);
  if (delta < 0)
    printf("No racines found");
  else if (delta == 0)
    printf("found 1 racine:%f", (-b + sqrt(delta)) / 2 * a);
  else
    printf("found 2 racines:%f,and %f", (-b + sqrt(delta)) / 2 * a,
           (-b - sqrt(delta)) / 2 * a);
}

int main() { assert(descriminant(2, 2, 2) == 2 * 2 - 4 * 2 * 2); }