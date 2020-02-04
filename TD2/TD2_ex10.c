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
}

int main() {}
