#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Mediatheque.h"

char* convertirChaineMin(const char *str) {
    char *copie = malloc(strlen(str) + 1);

    if (copie == NULL) {
        return NULL;
    }

    strcpy(copie, str);

    for (int i = 0; copie[i]; i++) {
        copie[i] = tolower((unsigned char)copie[i]);
    }

    return copie;
}

/** Utilisation d'un algorithme de tri à bulles depuis https://coddy.tech/visualize/sorting/bubble-sort */
void triBulles(Mediatheque *mediatheque) {
    int i;
    int j;
    Livre temp;
    
    for (i = 0; i < mediatheque->nbLivres - 1; i++) {
        for (j = 0; j < mediatheque->nbLivres - i - 1; j++) {
            char *titre1 = convertirChaineMin(mediatheque->collection[j].titre);
            char *titre2 = convertirChaineMin(mediatheque->collection[j + 1].titre);
        
            if (titre1 != NULL && titre2 != NULL) {
                if (strcmp(titre1, titre2) > 0) {
                    temp = mediatheque->collection[j];
                    mediatheque->collection[j] = mediatheque->collection[j + 1];
                    mediatheque->collection[j + 1] = temp;
                }
            }
            free(titre1);
            free(titre2);
        }
    }

    printf("Médiathèque triée avec succès.\n");
}
