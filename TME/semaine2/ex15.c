#include <cini.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 500

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
  CINI_draw_line(x1, y1, x2, y2, "blue");
  CINI_draw_line(x2, y2, x3, y3, "red");
  CINI_draw_line(x1, y1, x3, y3, "green");
}

void triangles(int w, int h, int epsilon) {
  int x1, y1, x2, y2, x3, y3;
  int x1temp, y1temp, x2temp, y2temp, x3temp, y3temp;
  x1 = w / 2;
  y1 = 0;
  x2 = 0;
  y2 = h;
  x3 = w;
  y3 = h;
  int i;
  drawTriangle(x1, y1, x2, y2, x3, y3);
  while ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) >= epsilon * epsilon) {
    x1temp = (x2 + 9 * x1) / 10;
    y1temp = (y2 + 9 * y1) / 10;
    x2temp = (x3 + 9 * x2) / 10;
    y2temp = (y3 + 9 * y2) / 10;
    x3temp = (x1 + 9 * x3) / 10;
    y3temp = (y1 + 9 * y3) / 10;
    x1 = x1temp;
    x2 = x2temp;
    x3 = x3temp;
    y1 = y1temp;
    y2 = y2temp;
    y3 = y3temp;
    CINI_loop_until_keyup();
    drawTriangle(x1, y1, x2, y2, x3, y3);
  }
}

int main(void) {
  CINI_open_window(WIDTH, HEIGHT, "triangles");
  CINI_fill_window("white");
  triangles(WIDTH, HEIGHT, 2);
  CINI_loop();
  return 0;
}