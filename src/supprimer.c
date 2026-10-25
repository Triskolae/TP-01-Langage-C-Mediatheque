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

/*
bool verifierMediatheque(const Mediatheque *mediatheque) {
    int i, j;

    if (mediatheque == NULL) {
        fprintf(stderr, "Erreur : médiathèque NULL.\n");
        return false;
    }

    if (mediatheque->nbLivres < 0 ||
        mediatheque->nbLivres > TAILLE_MAX) {
        fprintf(stderr, "Erreur : nombre de livres invalide.\n");
        return false;
    }

    for (i = 0; i < mediatheque->nbLivres; i++) {
        const Livre *livre = &mediatheque->collection[i];

        if (livre->id <= 0) {
            fprintf(stderr,
                    "Erreur : identifiant invalide à l'indice %d.\n", i);
            return false;
        }

        if (livre->titre[0] == '\0' ||
            livre->auteur[0] == '\0') {
            fprintf(stderr,
                    "Erreur : titre ou auteur vide à l'indice %d.\n", i);
            return false;
        }

        if (memchr(livre->titre, '\0', sizeof(livre->titre)) == NULL ||
            memchr(livre->auteur, '\0', sizeof(livre->auteur)) == NULL ||
            memchr(livre->description, '\0',
                   sizeof(livre->description)) == NULL) {
            fprintf(stderr,
                    "Erreur : chaîne non terminée à l'indice %d.\n", i);
            return false;
        }

        for (j = i + 1; j < mediatheque->nbLivres; j++) {
            if (livre->id == mediatheque->collection[j].id) {
                fprintf(stderr,
                        "Erreur : identifiant dupliqué (%d).\n",
                        livre->id);
                return false;
            }
        }
    }

    return true;
} */

void afficherMenuSuppression(Mediatheque *mediatheque) {
    int i;
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
        for (i = indice; i< mediatheque->nbLivres - 1; i++) {
            mediatheque->collection[i] = mediatheque->collection[i + 1];
        }
        
        mediatheque->nbLivres--;
        printf("Livre supprimé avec succès.\n");

        
        // if (!verifierMediatheque(mediatheque)) {
        //     fprintf(stderr,
        //             "Attention : la médiathèque est incohérente après suppression.\n");
        //     return;
        // }
    } else {
        printf("Suppression annulée.\n ");
    }
}
