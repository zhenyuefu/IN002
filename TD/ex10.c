#include <assert.h>
float surface_float(float l, float L) { return l * L; }
/* La probleme vient de la representation des nombres
flottants, la valeur representee en memoire peut etre
une valeur approchee du nombre <<reellement>> calcule.
Le resultat de la fonction surface_float(1.1,1.1) donnera
la valeur 1.21000003814697265625
le test assert(surface_float(1.1,1.1)==1.2) sera faux*/

/* il ne faut jamais faire de test d'égalité entre des
valeurs de type float. */

float valeur_absolue(float x) {
  if (x >= 0) {
    return x;
  }
  return -x;
}

int egal_eps(float x1, float x2, float epsilon) {
  if (valeur_absolue(x1 - x2) < epsilon) {
    return 1;
  }
  return 0;
}

int main(void) {
  assert(egal_eps(surface_float(1.1, 1.1), 1.21, 0.0001) == 1);
  assert(egal_eps(surface_float(1.1, 1.1), 1.22, 0.0001) == 0);
  return 0;
}