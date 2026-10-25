#include "../Mediatheque.h"
#include <stdio.h>

#include <stdbool.h>
#include <string.h>

int chercherIndiceParId(Mediatheque *mediatheque, int idRecherche) {
    Livre livre;
    int indice = 0;

    while (indice < mediatheque->nbLivres) {
        livre = mediatheque->collection[indice];
        if (livre.id == idRecherche) {
            return indice;
        }
        indice++;
    }
    return -1;
}

void supprimerMedia(Mediatheque *mediatheque, int indice) {
    int i;

    for (i = indice; i< mediatheque->nbLivres - 1; i++) {
        mediatheque->collection[i] = mediatheque->collection[i + 1];
    }

    mediatheque->nbLivres--;
    printf("Livre supprimé avec succès.\n");
}

void supprimer(Mediatheque *mediatheque) {
    int indice;
    int reponse;
    int idRecherche = 0;
    char saisie[100];

    if (mediatheque == NULL) {
        fprintf(stderr, "ERREUR : parametre invalide.\n");
        return;
    }

    if (mediatheque->nbLivres == 0) {
        fprintf(stderr, "ERREUR : médiathèque vide, impossible de supprimer.\n");
        return;
    }

    printf("Veuillez entrer l'id du média à supprimer: ");
    idRecherche = lireInt(saisie, sizeof(saisie));

    indice = chercherIndiceParId(mediatheque, idRecherche);

    if (indice == -1) {
        printf("Aucun livre pour cet identifiant.\n");
        return;
    }

    const Livre *livreASupprimer = &mediatheque->collection[indice];

    printf("========== LIVRE À SUPPRIMER ==========\n");
    afficherLivre(livreASupprimer);
    do {
        printf("Confirmer la suppression ? (1 = Oui, 2 = Non): ");
        reponse = lireInt(saisie, sizeof(saisie));
    } while (reponse != 1 && reponse != 2);

    if (reponse == 1) {
        supprimerMedia(mediatheque, indice);
    } else {
        printf("Suppression annulée.\n ");
    }
}
