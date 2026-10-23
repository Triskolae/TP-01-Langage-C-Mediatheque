/**
 * @file lire.c
 * @brief Lecture et validation des saisies utilisateur.
 * @author Sarah et Tristan (projet en binome)
 * @date 2026-10-23 (mise a jour de la documentation)
 * @details Lecture et validation des saisies utilisateur.
 */

#include "../Mediatheque.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

/**
 * @brief Vérifie que la saisie utilisateur correspond bien à une entrée du menu.
 * utilisation de l'IA (Gemini) pour gérer les cas limites de saisie utilisateur
 * @param saisie Tampon recevant la saisie de l utilisateur.
 * @param taille Capacite du tampon ou nombre d elements selon le contexte.
 * @param nbChoix Nombre de valeurs possibles dans le menu.
 * @note Retourne -1 en fin d entree, -2 si la saisie est invalide.
 * @return Retourne -1 en fin d entree, -2 si la saisie est invalide.
 */
short lireChoixMenu(char *saisie, size_t taille, short nbChoix) {
  if (fgets(saisie, taille, stdin) == NULL) {
    return -1; /** EOF, ex: CTRL + D (Linux) / CTRL + Z -> Entrée (Windows) */
  }

  char *fin;
  errno = 0;
  long valeur = strtol(saisie, &fin, 10);

  /** Ignorer les espaces après le nombre */
  /** Ignorer les espaces terminaux avant de verifier que la saisie
   *  ne contient aucun caractere non numerique. */
  while (*fin == ' ' || *fin == '\t' ||
    *fin == '\n' || *fin == '\r') {
    fin++;
  }

  /** Vérifier la validité de la saisie */
  if (fin == saisie || *fin != '\0' ||
    errno == ERANGE ||
    valeur < SHRT_MIN || valeur > SHRT_MAX ||
    valeur < 0 || valeur >= nbChoix || saisie[0] == '\n') {
      /** saisie[0] == '\n' => empêche de quitter le programme si user tape Entrée */
    printf("\nERREUR : veuillez saisir un entier valide.\n");
    return -2;
  }

  return (short)valeur;
}

/**
 * @brief Lit un entier non negatif avec verification de la saisie.
 * utilisation de l'IA (Gemini) pour gérer les cas limites
 * @param saisie Tampon recevant la saisie de l utilisateur.
 * @param taille Capacite du tampon ou nombre d elements selon le contexte.
 * @note Retourne 0 lorsque la lecture ou la conversion echoue.
 * @return Retourne 0 lorsque la lecture ou la conversion echoue.
 */
int lireInt(char *saisie, size_t taille) {

    /** Verifie que le tableau de saisie est valide */
    if (saisie == NULL || taille < 2) {
        return 0;
    }

    /** Lire la saisie utilisateur */
    if (fgets(saisie, taille, stdin) == NULL) {
        return 0; /** EOF ou erreur de lecture */
    }

    /** Verifie si la saisie dépasse la capacite du tableau */
    if (strchr(saisie, '\n') == NULL && !feof(stdin)) {
        int caractere = getchar();

        if (caractere != '\n' && caractere != EOF) {

            /** Vide le reste de la ligne pour ne pas perturber la prochaine saisie */
            while (caractere != '\n' && caractere != EOF) {
                caractere = getchar();
            }

            printf("\nERREUR : saisie trop longue.\n");
            return 0;
        }
    }

    /** Conversion de la saisie en entier non signé */
    char *fin;
    errno = 0;
    unsigned long valeur = strtoul(saisie, &fin, 10);

    /** Ignore les espaces et retours à la ligne apres le nombre */
    while (*fin == ' ' || *fin == '\t' || *fin == '\n' || *fin == '\r') {
        fin++;
    }

    /** Reperes le premier caractere non-espace. strtoul accepte le signe '-', mais nous refusons les valeurs negatives */
    char *debut = saisie;
    while (*debut == ' ' || *debut == '\t') {
        debut++;
    }

    /** Verifie la conversion et la compatibilité avec le type int */
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

/** Spécifique aux année de pulications car elles peuvent être négatives
 * @brief Lit une annee de publication et verifie ses limites.
 * @param saisie Tampon recevant la saisie de l utilisateur.
 * @param taille Capacite du tampon ou nombre d elements selon le contexte.
 * @note Retourne 0 en cas de saisie invalide ou de lecture interrompue.
 * @return Retourne 0 en cas de saisie invalide ou de lecture interrompue.
 */
short lireAnnee(char *saisie, size_t taille) {

    /** Verifier que le tableau de saisie est valide */
    if (saisie == NULL || taille < 2) {
        return 0;
    }

    if (fgets(saisie, taille, stdin) == NULL) {
        return 0; /** EOF ou erreur de lecture */
    }

    /** Refuser une saisie trop longue et vider le reste de la ligne */
    if (strchr(saisie, '\n') == NULL && !feof(stdin)) {
        int caractere = getchar();

        if (caractere != '\n' && caractere != EOF) {
            do {
                caractere = getchar();
            } while (caractere != '\n' && caractere != EOF);

            printf("\nERREUR : saisie trop longue.\n");
            return 0;
        }
    }

    char *fin;
    errno = 0;

    /** strtol permet de conserver le signe de la valeur saisie */
    long valeur = strtol(saisie, &fin, 10);

    /** Ignorer les espaces apres le nombre */
    while (*fin == ' ' || *fin == '\t' ||
           *fin == '\n' || *fin == '\r') {
        fin++;
    }

    /** Refuser une saisie non numerique, negative, nulle ou hors limites */
    if (fin == saisie || *fin != '\0' || errno == ERANGE || valeur == 0 || valeur < -1800 || valeur > SHRT_MAX) {

        printf("\nERREUR : année de publication invalide.\n");
        return 0;
    }

    return (short)valeur;
}

/**
 * @brief Lit une chaine non vide en respectant la taille du tampon.
 * utilisation de l'IA (Gemini) pour gérer les cas limites de saisie utilisateur
 * @param saisie Tampon recevant la saisie de l utilisateur.
 * @param taille Capacite du tampon ou nombre d elements selon le contexte.
 * @note Retourne NULL si la saisie est invalide ou interrompue.
 * @return Retourne NULL si la saisie est invalide ou interrompue.
 */
char *lireChaine(char *saisie, size_t taille) {
    if (saisie == NULL || taille < 2) {
        return NULL;
    }

    /** Lire au maximum taille - 1 caracteres. */
    if (fgets(saisie, taille, stdin) == NULL) {
        return NULL;
    }

    /** Rechercher le retour a la ligne. */
    char * const finLigne = strchr(saisie, '\n');

    if (finLigne != NULL) {
        *finLigne = '\0';
    } 
    
    else {
        /** Verifier si des caracteres supplementaires restent. */
        int caractere = getchar();

        if (caractere != '\n' && caractere != EOF) {
            /** La saisie depasse la capacite autorisee. */
            while (caractere != '\n' && caractere != EOF) {
                caractere = getchar();
            }

            saisie[0] = '\0';
            printf("\nERREUR : saisie trop longue.\n");
            return NULL;
        }
    }

    /** Refuser une chaine vide. */
    if (saisie[0] == '\0') {
        printf("\nERREUR : la saisie ne peut pas etre vide.\n");
        return NULL;
    }

    return saisie;
}

/**
 * @brief Recherche une sous-chaine sans distinguer la casse ASCII.
 * utilisation de l'IA (Gemini) pour gérer les cas limites de saisie utilisateur
 * @param chaine Chaine dans laquelle effectuer la recherche.
 * @param sousChaine Texte recherche dans la chaine.
 * @note Retourne un pointeur vers la correspondance ou NULL si absente.
 * @return Retourne un pointeur vers la correspondance ou NULL si absente.
 */
const char *comparerChaines(const char *chaine, const char *sousChaine) {
    if (!*sousChaine) return chaine;

    for (; *chaine != '\0'; chaine++) {
        const char *h = chaine;
        const char *n = sousChaine;

        /** Compare caractère par caractère en minuscules */
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
