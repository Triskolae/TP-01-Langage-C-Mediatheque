#include "../Livre.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

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

    // Verifier que le tableau de saisie est valide
    if (saisie == NULL || taille < 2) {
        return 0;
    }

    // Lire la saisie utilisateur
    if (fgets(saisie, taille, stdin) == NULL) {
        return 0; // EOF ou erreur de lecture
    }

    // Verifier si la saisie depasse la capacite du tableau
    if (strchr(saisie, '\n') == NULL && !feof(stdin)) {
        int caractere = getchar();

        if (caractere != '\n' && caractere != EOF) {

            // Vider le reste de la ligne pour ne pas perturber la prochaine saisie
            while (caractere != '\n' && caractere != EOF) {
                caractere = getchar();
            }

            printf("\nERREUR : saisie trop longue.\n");
            return 0;
        }
    }

    // Convertir la saisie en entier non signe
    char *fin;
    errno = 0;
    unsigned long valeur = strtoul(saisie, &fin, 10);

    // Ignorer les espaces et retours a la ligne apres le nombre
    while (*fin == ' ' || *fin == '\t' || *fin == '\n' || *fin == '\r') {
        fin++;
    }

    // Reperer le premier caractere non-espace
    // strtoul accepte le signe '-', mais nous refusons les valeurs negatives
    char *debut = saisie;
    while (*debut == ' ' || *debut == '\t') {
        debut++;
    }

    // Verifier la conversion et la compatibilite avec le type int
    if (fin == debut ||
        *fin != '\0' ||
        errno == ERANGE ||
        valeur > INT_MAX ||
        *debut == '-') {

        printf("\nERREUR : veuillez saisir un entier valide.\n");
        return 0;
    }

    return (int)valeur;
}


char *lireChaine(char *saisie, size_t taille) {
    if (saisie == NULL || taille < 2) {
        return NULL;
    }

    // Lire au maximum taille - 1 caracteres.
    if (fgets(saisie, taille, stdin) == NULL) {
        return NULL;
    }

    // Rechercher le retour a la ligne.
    char * const finLigne = strchr(saisie, '\n');

    if (finLigne != NULL) {
        *finLigne = '\0';
    } 
    
    else {
        // Verifier si des caracteres supplementaires restent.
        int caractere = getchar();

        if (caractere != '\n' && caractere != EOF) {
            // La saisie depasse la capacite autorisee.
            while (caractere != '\n' && caractere != EOF) {
                caractere = getchar();
            }

            saisie[0] = '\0';
            printf("\nERREUR : saisie trop longue.\n");
            return NULL;
        }
    }

    // Refuser une chaine vide.
    if (saisie[0] == '\0') {
        printf("\nERREUR : la saisie ne peut pas etre vide.\n");
        return NULL;
    }

    return saisie;
}


char *comparerChaines(char *chaine, char *sousChaine) {
    if (!*sousChaine) return chaine;

    for (; *chaine != '\0'; chaine++) {
        const char *h = chaine;
        const char *n = sousChaine;

        // Compare caractère par caractère en minuscules
        while (*h && *n && (tolower((unsigned char)*h) == tolower((unsigned char)*n))) {
            h++;
            n++;
        }

        if (!*n) {
            return chaine;
        }
    }

    return NULL;
}
