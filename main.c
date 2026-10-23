/**
 * @file main.c
 * @brief Initialisation de la mediatheque et demarrage du programme.
 * @author Sarah et Tristan (projet en binome)
 * @date 2026-10-23 (mise a jour de la documentation)
 * @details Initialisation de la mediatheque et demarrage du programme.
 */

#include "Menu.h"
#include "Mediatheque.h"
/**
 * @brief Initialise la collection et lance le menu principal.
 * @note Termine le programme avec le code 0.
 * @return Code de fin du programme (0).
 */
int main(void) {

    /** Initialiser une mediatheque vide */
    Mediatheque mediatheque = {0};

    /** Le premier livre ajouté recevra l'identifiant 1 */
    mediatheque.prochainId = 1;

    /** Lancer le menu principal */
    lancerMenuPrincipal(&mediatheque);

    return 0;
}

/** pour tout compiler et exécuter: */
/** Compiler les fichiers C du dossier src avec main.c, puis executer le programme. */
