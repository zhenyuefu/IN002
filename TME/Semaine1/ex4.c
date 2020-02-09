#include <assert.h>
#include <stdio.h>

int alternative(int n1, int n2, int n3) {
  int res;
  if (n1 > 8) {
    res = 3;
  } else {
    if (n3 == 20) {
      res = 2;
    } else {
      if ((n2 >= 10) && (n3 >= 10)) {
        res = 1;
      } else {
        res = 0;
      }
    }
  }
  return res;
}

int main() {
  assert(alternative(9, 0, 0) == 3);    // n1>8
  assert(alternative(7, 0, 20) == 2);   // n1<=8 and n3==20
  assert(alternative(7, 15, 15) == 1);  // n1<=8 and n3!=20 and n3>=10 and
                                        // n2>=10
  assert(alternative(7, 8, 15) == 0);  // n1<=8 and n3!=20 and (n3<10 and n2<10)
  return 0;
}
