#include <stdio.h>

void echange(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void tri(int *a, int *b) {
  if (*a > *b) {
    echange(a, b);
  }
}

void tri_3(int *a, int *b, int *c) {
  tri(a, b);
  tri(a, c);
  tri(b, c);
}

int main(void) {
  int a = 2, b = 1, c = 3;
  tri(&a, &b);
  printf("a=%d, b=%d\n", a, b);
  tri_3(&a, &b, &c);
  printf("a=%d, b=%d, c=%d\n", a, b, c);
}