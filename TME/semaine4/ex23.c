#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_temp(float temperature[31]) {
  srand(time(NULL));
  for (int i = 0; i < 31; i++) {
    temperature[i] = (rand() % 500 - 200) / 10;
  }
}

void affichage(float temperature[31]) {
  for (int i = 0; i < 31; i++) {
    printf("temperature de %d jour est %.2f\n", i + 1, temperature[i]);
  }
}

float moy_temp(float temperature[31]) {
  float moy, somme = 0;
  for (int i = 0; i < 31; i++) {
    somme = somme + temperature[i];
  }
  moy = somme / 31;
  return moy;
}

float moy_temp_negative(float temperature[31]) {
  float moy, somme = 0;
  int nbJourNegative = 0;
  for (int i = 0; i < 31; i++) {
    if (temperature[i] < 0) {
      nbJourNegative++;
      somme = somme + temperature[i];
    }
  }
  if (nbJourNegative == 0)
    return -1;
  moy = somme / nbJourNegative;
  return moy;
}

int main(void) {
  float temperature[31];
  float moyTemp, moyTempNegative;
  init_temp(temperature);
  affichage(temperature);
  moyTemp = moy_temp(temperature);
  printf("temperature moyenne est %.2f\n", moyTemp);
  moyTempNegative = moy_temp_negative(temperature);
  if (moyTempNegative == -1)
    printf("Aucunetemperature au-dessous de zero.");
  else
    printf("temperature moyenne negative est %.2f\n", moyTempNegative);
  return 0;
}