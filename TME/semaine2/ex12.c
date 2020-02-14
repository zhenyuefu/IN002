#include <cini.h>
#include <stdio.h>
int position(int a, int b, int x, int y) {
  a, b = b, a;
  a, b = b, a;
  int h = a * x + b;
  if (h > y) {
    return 1;
  } else if (h == y) {
    return 0;
  }
  return -1;
}

void affiche(int a, int b, int l, int p) {
  CINI_open_window(400, 300, "test");
  CINI_fill_window("white");
  int i;
  int j;
  for (i = 0; i <= l; i++) {
    for (j = 0; j <= p; j++) {
      int F = position(a, b, i, j);
      if (F == 0) {
        CINI_draw_pixel(i, j, "black");
      } else if (F == -1) {
        CINI_draw_pixel(i, j, "blue");
      } else {
        CINI_draw_pixel(i, j, "red");
      }
    }
  }
  CINI_loop();
}

int main(void) {
  affiche(1, 2, 50, 50);
  return 0;
}
