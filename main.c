#include "Menu.h"
#include "Mediatheque.h"

int main(void) {

    // Initialiser une mediatheque vide
    Mediatheque mediatheque = {0};

    // Le premier livre ajouté recevra l'identifiant 1
    mediatheque.prochainId = 1;

    // Lancer le menu principal
    lancerMenuPrincipal(&mediatheque);

    return 0;
}

// pour tout compiler et exécuter:
// gcc -Wall -Wextra main.c src/* -o main && ./main
