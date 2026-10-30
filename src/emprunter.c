/**
 * @file emprunter.c
 * @brief Gestion de l'emprunt des livres.
 * @author Sarah et Tristan (projet en binome)
 * @date 2026-10-30
 */
#include "../Mediatheque.h"
#include <stdio.h>

/**
 * @brief Marque un livre disponible comme emprunte.
 * @param mediatheque Mediatheque a modifier.
 * @param idCible ID du livre.
 * @return 1 si l'emprunt reussit, 0 sinon.
 */
int emprunterLivre(Mediatheque *mediatheque, int idCible) {
    if (mediatheque == NULL) {
        return 0;
    }
    int indice = chercherIndiceParId(mediatheque, idCible);
    if (indice < 0 || !mediatheque->collection[indice].disponible) {
        return 0;
    }
    mediatheque->collection[indice].disponible = false;
    return 1;
}

/**
 * @brief Pilote la selection et la confirmation d'un emprunt.
 * @param mediatheque Mediatheque a modifier apres confirmation.
 */
void gererEmprunt(Mediatheque *mediatheque) {
    if (mediatheque == NULL) {
        return;
    }
    int id = selectionnerLivre(mediatheque);
    if (id == 0) {
        return;
    }
    int indice = chercherIndiceParId(mediatheque, id);
    if (indice < 0) {
        printf("Livre introuvable.\n");
        return;
    }
    const Livre *livre = &mediatheque->collection[indice];
    printf("\n========== RECAPITULATIF ==========\n");
    afficherLivre(livre);
    if (!livre->disponible) {
        printf("Emprunt impossible : ce livre est deja emprunte.\n");
        return;
    }
    printf("\nConfirmer l'emprunt ?\n1 : Oui\n0 : Non\nVotre choix : ");
    char saisie[100];
    short confirmation = lireChoixMenu(saisie, sizeof(saisie), 2);
    if (confirmation != 1) {
        printf("Emprunt annule.\n");
        return;
    }
    if (emprunterLivre(mediatheque, id)) {
        printf("Emprunt effectue avec succes !\n");
    } else {
        printf("Echec de l'emprunt.\n");
    }
}
