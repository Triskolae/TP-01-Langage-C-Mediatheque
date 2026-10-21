#include "../Main.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

short lireChoixMenu(char *saisie, size_t taille, short nbChoix) {
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

int lireInt(char *saisie, size_t taille) {
    if (fgets(saisie, taille, stdin) == NULL) {
        return 0; // EOF ou erreur de lecture
    }

    char *fin;
    errno = 0;
    long valeur = strtoul(saisie, &fin, 10);

    // Ignorer les espaces et sauts de ligne à la fin
    while (*fin == ' ' || *fin == '\t' || *fin == '\n' || *fin == '\r') {
        fin++;
    }

    // Vérification de la validité
    // Note : strtoul accepte le signe '-' (ex: "-1" devient ULONG_MAX - 1).
    // On vérifie donc aussi que le premier caractère non-espace n'est pas '-'
    char *debut = saisie;
    while (*debut == ' ' || *debut == '\t') {
        debut++;
    }

    if (fin == saisie || *fin != '\0' || 
        errno == ERANGE || valeur > UINT_MAX || 
        *debut == '-' || *debut == '\n') {
        printf("\nERREUR : veuillez saisir un entier valide.\n");
        return 0;
    }

    return (int)valeur;
}

char* lireString() {
  printf("lireString\n");
  return "wello horld";
}
