#include "../Mediatheque.h"
#include <stdio.h>
#include <string.h>

/** Utilisation d'un algorithme de tri à bulles depuis https://coddy.tech/visualize/sorting/bubble-sort */
void triBulles(Mediatheque *mediatheque) {
    int i;
    int j;
    Livre temp;
    
    for (i = 0; i < mediatheque->nbLivres - 1; i++) {
        for (j = 0; j < mediatheque->nbLivres - i - 1; j++) {
            if (strcmp(mediatheque->collection[j].titre, mediatheque->collection[j + 1].titre) > 0) {
                temp = mediatheque->collection[j];
                mediatheque->collection[j] = mediatheque->collection[j + 1];
                mediatheque->collection[j + 1] = temp;
            }
        }
    }

    printf("Médiathèque triée avec succès.\n");
}

void trier(Mediatheque *mediatheque) {
    int reponse;
    char saisie[100];

    printf("========== TRIER LA MEDIATHEQUE ==========\n");

    do {
        printf("Trier les médias par titre ? (1 = Oui, 2 = Non)\n");
        reponse = lireInt(saisie, sizeof(saisie));

    } while (reponse != 1 && reponse != 2);

    if (reponse == 1) {
        triBulles(mediatheque);
    } else {
        printf("Tri annulé.\n");
    }
}
