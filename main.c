#include "Menu.h"
#include "Mediatheque.h"

int main(void) {

    // Initialiser une mediatheque vide
    Mediatheque mediatheque = {0};

    // Le premier livre ajouté recevra l'identifiant 1
    mediatheque.prochainId = 1;

    // Lancer le menu principal
    lancerMenuPrincipal(
        mediatheque.collection,
        &mediatheque.nbLivres,
        &mediatheque.prochainId
    );

    return 0;
}

// gcc -o main main.c
// gcc main.c src/Menu.c -o main

// gcc -Wall -Wextra -o main main.c
// gcc -Wall -Wextra main.c src/Menu.c -o main

// pour tout compiler et exécuter:
// gcc -Wall -Wextra main.c src/* -o main && ./main

// gérer le ENTRER différement du 0
