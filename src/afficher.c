#include "../Livre.h"
#include <stdio.h>

void afficher(Livre collection[], int taille) {
    short choixMenu = -1;
    char saisie[100];

    if (taille == 0) {
        printf("La médiathèque est vide.\n");
        return;
    }

    do {
        // Sous-menu défini dans src/menu.c
        afficherMenuAffichage();

        choixMenu = lireChoixMenu(saisie, sizeof(saisie), 4);

        if (choixMenu == -1) {
            break;
        }

        if (choixMenu == -2) {
            continue;
        }

        switch (choixMenu) {
            /*case -1:
                return;
                
            case -2:
                break; +1.5 points*/
            
            case 1:
                afficherTous(collection, taille);
                break;

            case 2:
                afficherParEtat(collection, taille, true);
                break;

            case 3:
                afficherParEtat(collection, taille, false);
                break;

            case 0:
                break;

            default:
                printf("Choix invalide.\n");
                break;
        }

    } while (choixMenu != 0);
}

void afficherTous(Livre collection[], int taille) {
    printf("\nVoici la collection des médias :\n");

    int i = 0;

    while (i < taille) {
        if (collection[i].id > 0) {
            printf("\nID : %d\n", collection[i].id);
            printf("Titre : %s\n", collection[i].titre);
            printf("Auteur : %s\n", collection[i].auteur);
            printf("Description : %s\n", collection[i].description);
            printf("Etat : %s\n",
                   collection[i].disponible ? "disponible" : "emprunté");
        }

        i++;
    }
}

void afficherParEtat(Livre collection[], int taille, bool disponible) {
    printf("\nVoici la collection des médias %s :\n",
           disponible ? "disponibles" : "empruntés");

    int i = 0;
    int compteur = 0;

    while (i < taille) {
        if (collection[i].id > 0 &&
            collection[i].disponible == disponible) {

            printf("\nID : %d\n", collection[i].id);
            printf("Titre : %s\n", collection[i].titre);
            printf("Auteur : %s\n", collection[i].auteur);
            printf("Description : %s\n", collection[i].description);
            printf("Etat : %s\n",
                   collection[i].disponible ? "disponible" : "emprunté");

            compteur++;
        }

        i++;
    }

    if (compteur == 0) {
        printf("Aucun livre %s.\n",
               disponible ? "disponible" : "emprunté");
    }
}
