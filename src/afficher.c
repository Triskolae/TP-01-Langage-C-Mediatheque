/**
 * @file afficher.c
 * @brief Affichage de la collection et filtrage selon la disponibilite.
 * @author Sarah et Tristan (projet en binome)
 * @date 2026-10-23 (mise a jour de la documentation)
 * @details Affichage de la collection et filtrage selon la disponibilite.
 */

#include "../Mediatheque.h"
#include <stdio.h>
/**
 * @brief Pilote l affichage de la collection selon le filtre choisi.
 * @param mediatheque Pointeur vers la mediatheque concernee.
 */
void afficher(const Mediatheque *mediatheque) {
    short choixMenu = -1;
    char saisie[100];

    if (mediatheque->nbLivres == 0) {
        printf("La médiathèque est vide.\n");
        return;
    }

    do {
        /** Sous-menu défini dans src/menu.c */
        afficherMenuAffichage();

        choixMenu = lireChoixMenu(saisie, sizeof(saisie), 4);

        switch (choixMenu) {
            case -1:
                return;
                
            case -2:
                break;
            
            case 1:
                afficherTous(mediatheque);
                break;

            case 2:
                afficherParEtat(mediatheque, true);
                break;

            case 3:
                afficherParEtat(mediatheque, false);
                break;

            case 0:
                break;

            default:
                printf("Choix invalide.\n");
                break;
        }

    } while (choixMenu != 0);
}
/**
 * @brief Affiche les informations de tous les livres.
 * @param mediatheque Pointeur vers la mediatheque concernee.
 */
void afficherTous(const Mediatheque *mediatheque) {
    printf("\nVoici la collection des médias :\n");

    int i = 0;

    while (i < mediatheque->nbLivres) {
        const Livre *livre = &mediatheque->collection[i];

        if (livre->id > 0) {
            printf("\nID : %d\n", livre->id);
            printf("Titre : %s\n", livre->titre);
            printf("Auteur : %s\n", livre->auteur);
            printf("Description : %s\n", livre->description);
            printf("Etat : %s\n", livre->disponible ? "disponible" : "emprunté");
        }

        i++;
    }
}
/**
 * @brief Affiche les livres correspondant a un etat de disponibilite.
 * @param mediatheque Pointeur vers la mediatheque concernee.
 * @param disponible Etat de disponibilite utilise pour le filtrage.
 */
void afficherParEtat(const Mediatheque *mediatheque, bool disponible) {
    printf("\nVoici la collection des médias %s :\n", disponible ? "disponibles" : "empruntés");

    int i = 0;
    int compteur = 0;

    while (i < mediatheque->nbLivres) {
        const Livre *livre = &mediatheque->collection[i];

        if (livre->id > 0 && livre->disponible == disponible) {

            printf("\nID : %d\n", livre->id);
            printf("Titre : %s\n", livre->titre);
            printf("Auteur : %s\n", livre->auteur);
            printf("Description : %s\n", livre->description);
            printf("Etat : %s\n", livre->disponible ? "disponible" : "emprunté");

            compteur++;
        }

        i++;
    }

    if (compteur == 0) {
        printf("Aucun livre %s.\n",
               disponible ? "disponible" : "emprunté");
    }
}
