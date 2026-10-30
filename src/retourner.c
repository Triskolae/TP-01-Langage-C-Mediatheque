/**
 * @file rendre.c
 * @brief Gestion du retour des livres empruntes.
 * @author Sarah et Tristan (projet en binome)
 * @date 2026-10-30
 */
#include "../Mediatheque.h"
#include <stdio.h>

/**
 * @brief Rend disponible un livre actuellement emprunte.
 * @param mediatheque Pointeur vers la mediatheque a modifier.
 * @param idCible Identifiant du livre a rendre.
 * @return 1 si le retour reussit, 0 si le livre est introuvable ou deja disponible.
 */
int rendreLivre(Mediatheque *mediatheque, int idCible) {
    if (mediatheque == NULL) {
        return 0;
    }
    int indice = chercherIndiceParId(mediatheque, idCible);
    if (indice < 0 || mediatheque->collection[indice].disponible) {
        return 0;
    }
    mediatheque->collection[indice].disponible = true;
    return 1;
}

/**
 * @brief Orchestre la recherche, la verification et la confirmation du retour.
 * @param mediatheque Pointeur vers la mediatheque a modifier apres confirmation.
 */
void gererRetour(Mediatheque *mediatheque) {
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
    printf("\n========== RECAPITULATIF DU RETOUR ==========\n");
    afficherLivre(livre);
    if (livre->disponible) {
        printf("Retour impossible : ce livre est deja disponible.\n");
        return;
    }
    printf("\nConfirmer le retour ?\n1 : Oui\n0 : Non\nVotre choix : ");
    char saisie[100];
    short confirmation = lireChoixMenu(saisie, sizeof(saisie), 2);
    if (confirmation != 1) {
        printf("Retour annule.\n");
        return;
    }
    if (rendreLivre(mediatheque, id)) {
        printf("Retour effectue avec succes !\n");
    } else {
        printf("Echec du retour.\n");
    }
}
