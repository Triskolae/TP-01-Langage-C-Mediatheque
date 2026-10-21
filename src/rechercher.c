#include "../Main.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

void rechercher(Livre collection[], int taille) {
    short choixMenu = -1;
    char saisie[100];

    if (taille == 0) {
        printf("La médiathèque est vide.\n");
        return;
    }

    do {
        afficherMenuRecherche();

        choixMenu = lireChoixMenu(saisie, sizeof(saisie), 4);
        
        if (choixMenu == -1) {
            break;
        }

        if (choixMenu == -2) {
            continue;
        }

        switch (choixMenu) {
            case 1:
                rechercherParId(collection, taille);
                break;

            case 2:
                rechercherParTitre(collection, taille);
                break;

            case 3:
                //
                printf("Not implemented yet.\n");
                break;

            case 0:
                break;

            default:
                printf("Choix invalide.\n");
                break;
        }
    } while (choixMenu != 0);
}

void rechercherParId(Livre collection[], int taille) {
    printf("Veuillez entrer l'id du média recherché: ");
    int idRecherche = 0;
    char saisie[100];
    bool found = false;

    idRecherche = lireInt(saisie, sizeof(saisie));

    int i = 0;

    while (i < taille) {
        if (collection[i].id == idRecherche) {
            printf("\nID : %d\n", collection[i].id);
            printf("Titre : %s\n", collection[i].titre);
            printf("Auteur : %s\n", collection[i].auteur);
            printf("Description : %s\n", collection[i].description);
            printf("Etat : %s\n",
                   collection[i].disponible ? "disponible" : "emprunté");
            found = true;
            break;
        }
        i++;
    }
    if (!found && idRecherche != 0) {
        printf("Aucun média trouvé pour l'id %d\n", idRecherche);
    }
}

void rechercherParTitre(Livre collection[], int taille) {
    printf("Veuillez entrer le titre du média recherché: ");

    char saisie[100];

    if (lireChaine(saisie, sizeof(saisie)) == NULL) {
        printf("Saisie invalide.\n");
        return;
    }

    int i = 0;

    while (i < taille) {
        if (comparerChaines(collection[i].titre, saisie) != NULL) {
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
