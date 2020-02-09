#include <assert.h>
#include <stdio.h>

int signeProduit(int a, int b) {
  if (a == 0 || b == 0)
    return 0;
  else if ((a > 0 && b > 0) || (a < 0 && b < 0))
    return 1;
  else
    return -1;
}

int main() {
  printf("%d\n", signeProduit(22, 22));
  printf("%d\n", signeProduit(22, -22));
  printf("%d", signeProduit(22, 0));
  assert(signeProduit(1, 1) == 1);
  assert(signeProduit(0, 1) == 0);
  assert(signeProduit(1, -1) == -1);
  return 0;
}