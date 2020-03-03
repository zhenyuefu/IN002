int dicho_ite(int tab[], int taille, int elem) {
  int g = 0, d = taille - 1, m;
  while (d <= g) {
    m = (g + d) / 2;
    if (tab[m] == elem) {
      return 1;
    }
    if (tab[m] > elem) {
      d = m - 1;
    }
    if (tab[m] < elem) {
      g = m + 1;
    }
  }
  return 0;
}

int dicho_ite_rec(int tab[], int taille, int elem) {
  int milieu = taille / 2;
  if (taille == 0) {
    return 0;
  }
  if (elem == tab[milieu]) {
    return 1;
  } else if (elem > tab[milieu]) {
    return dicho_ite_rec(tab + milieu + 1, taille - milieu - 1, elem);
  } else {
    return dicho_ite_rec(tab, milieu, elem);
  }
}

int main(void) {
  // ................................
  return 0;
}