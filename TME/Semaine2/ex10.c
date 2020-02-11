#include <cini.h>

void drawLine(int x1, int y1, int x2, int y2, string color) {
  int i, j;
  for (i = x1; i <= x2; i++) {
    for (j = y1; j <= y2; j++) {
      CINI_draw_pixel(i, j, color);
    }
  }
}

void carre(int x, int X, int Y) {
  drawLine(X, Y, X, Y + x, "blue");
  drawLine(X, Y, X + x, Y, "red");
  drawLine(X + x, Y, X + x, Y + x, "green");
  drawLine(X, Y + x, X + x, Y + x, "black");
}

void carre_remontant(int x, int X, int Y) {
  while (X >= 0 && Y >= 0) {
    carre(x, X, Y);
    X = X - 20;
    Y = Y - 20;
  }
}

int main(void) {
  CINI_open_window(500, 500, "Carrement graphique");
  CINI_fill_window("white");
  carre_remontant(200, 250, 250);
  CINI_loop();
  return 0;
}