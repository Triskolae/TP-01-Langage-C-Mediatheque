
/**
 * @file emprunter.c
 * @brief Gestion de l'emprunt d'un livre dans la mediatheque.
 * @author Sarah et Tristan (projet en binome)
 * @date 2026-10-30
 */

#include "../Mediatheque.h"

/**
 * @brief Emprunte un livre a partir de son identifiant.
 * @param mediatheque Pointeur vers la mediatheque a modifier.
 * @param idCible Identifiant du livre recherche.
 * @return 1 si l'emprunt reussit, 0 si le livre est introuvable ou deja emprunte.
 */
int emprunterLivre(Mediatheque *mediatheque, int idCible) {
    if (mediatheque == NULL) {
        return 0;
    }

    int indice = chercherIndiceParId(mediatheque, idCible);
    if (indice < 0) {
        return 0;
    }

    /* Le pointeur cible le livre dans la collection : sa disponibilite
       est modifiee durablement, sans copie de la structure. */
    Livre *livre = &mediatheque->collection[indice];

    if (!livre->disponible) {
        return 0;
    }

    livre->disponible = false;
    return 1;
}
