#include "../Mediatheque.h"
#include <stdio.h>
#include <string.h>

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
