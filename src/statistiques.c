/**
 * @file statistiques.c
 * @brief Calcul et affichage des statistiques de la mediatheque.
 * @author Sarah et Tristan (projet en binome)
 * @date 2026-10-30
 */

#include "../Mediatheque.h"
#include <stdio.h>

/**
 * @brief Affiche le total des livres et leur repartition par disponibilite.
 * @param mediatheque Mediatheque consultee sans modification.
 */
void afficherStatistiques(const Mediatheque *mediatheque) {
    if (mediatheque == NULL) {
        return;
    }

    int disponibles = 0;

    /* Seuls les nbLivres premiers elements de collection sont utilises. */
    for (int i = 0; i < mediatheque->nbLivres; i++) {
        if (mediatheque->collection[i].disponible) {
            disponibles++;
        }
    }

    int empruntes = mediatheque->nbLivres - disponibles;

    printf("\n========== STATISTIQUES DE LA MEDIATHEQUE ==========\n");
    printf("Nombre total de livres : %d\n", mediatheque->nbLivres);
    printf("Livres disponibles     : %d\n", disponibles);
    printf("Livres empruntes       : %d\n", empruntes);
}
