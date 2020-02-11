#include <cini.h>
#define X 200

void diagonale(int x) {
  int i = 0;
  for (i = 0; i <= x; i++) {
    CINI_draw_pixel(i, i, "white");
  }
}

int main(void) {
  CINI_open_window(X, X, "title");
  diagonale(X);
  CINI_loop();
  return 0;
}