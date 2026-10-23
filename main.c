#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Livre.h"
#include "Menu.h"

int main(void) {

    // Collection de démonstration
    Livre collection[TAILLE_MAX] = {
        {1, "Harry Potter", "J.K. Rowling",
         "Un jeune sorcier découvre Poudlard.", true},

        {2, "Dune", "Frank Herbert",
         "Une aventure sur la planète Arrakis.", true},

        {3, "L'Assassin Royal", "Robin Hobb",
         "L'histoire de Fitz.", false},

        {4, "Dune 2", "Frank Herbert",
         "Une autre aventure sur la planète Arrakis.", false},
    };

    int nbLivres = 4;
    // int prochainId = 4;

    lancerMenuPrincipal(collection, nbLivres);

    return 0;
}

// gcc -o main main.c
// gcc main.c src/Menu.c -o main

// gcc -Wall -Wextra -o main main.c
// gcc -Wall -Wextra main.c src/Menu.c -o main

// pour tout compiler et exécuter:
// gcc -Wall -Wextra main.c src/* -o main && ./main

// gérer le ENTRER différement du 0
