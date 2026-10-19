#include "../Main.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

short lire(char *saisie, size_t taille, short nbChoix) {
  if (fgets(saisie, taille, stdin) == NULL) {
    return -1; // EOF, ex: CTRL + D (Linux) / CTRL + Z -> Entrée (Windows)
  }

  char *fin;
  errno = 0;
  long valeur = strtol(saisie, &fin, 10);

  // Ignorer les espaces après le nombre
  while (*fin == ' ' || *fin == '\t' ||
    *fin == '\n' || *fin == '\r') {
    fin++;
  }

  // Vérifier la validité de la saisie
  if (fin == saisie || *fin != '\0' ||
    errno == ERANGE ||
    valeur < SHRT_MIN || valeur > SHRT_MAX ||
    valeur < 0 || valeur >= nbChoix || saisie[0] == '\n') {
      // saisie[0] == '\n' => empêche de quitter le programme si user tape Entrée
    printf("\nERREUR : veuillez saisir un entier valide.\n");
    return -2;
  }

  return (short)valeur;
}
