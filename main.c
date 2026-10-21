#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Main.h"

int main(void) {

    // Collection de démonstration
    Livre collection[TAILLE_MAX] = {
        {1, "Harry Potter", "J.K. Rowling",
         "Un jeune sorcier découvre Poudlard.", true},

        {2, "Dune", "Frank Herbert",
         "Une aventure sur la planète Arrakis.", true},

        {3, "L'Assassin Royal", "Robin Hobb",
         "L'histoire de Fitz.", false}
    };

    int nbLivres = 3;
    // int prochainId = 4;

    short choixMenu = -1;
    char saisie[100];

    do {
        // MENU PRINCIPAL
        printf("\n========== MA PETITE MEDIATHEQUE ==========\n");
        printf("1 : Ajouter un livre\n");
        printf("2 : Afficher les livres\n");
        printf("3 : Rechercher un livre\n");
        printf("0 : Quitter\n");
        printf("Saisissez votre choix : ");

        choixMenu = lireChoixMenu(saisie, sizeof(saisie), 4);

        if (choixMenu == -1) {
            printf("\nFin de la saisie.\n");
            break;
        }

        if (choixMenu == -2) {
            continue;
        }

        switch (choixMenu) {

            case 1:
                // Fonction à créer dans src/ajouter.c
                printf("\nAjout : à implémenter.\n");
                break;

            case 2:
                // Fonction définie dans src/afficher.c
                afficher(collection, nbLivres);
                break;

            case 3:
                // Fonction à créer dans src/rechercher.c
                rechercher(collection, nbLivres);
                break;

            case 0:
                printf("\nFermeture de la médiathèque.\n");
                break;
        }

    } while (choixMenu != 0);

    return 0;
}

// gcc -o main main.c
// gcc main.c src/Menu.c -o main

// gcc -Wall -Wextra -o main main.c
// gcc -Wall -Wextra main.c src/Menu.c -o main

// pour tout compiler et exécuter:
// gcc -Wall -Wextra main.c src/* -o main && ./main

// gérer le ENTRER différement du 0
