#include "../Livre.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

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
                rechercherParChampTexte(collection, taille, CHAMP_TITRE);
                break;

            case 3:
                rechercherParChampTexte(collection, taille, CHAMP_AUTEUR);
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

void rechercherParChampTexte(Livre collection[], int taille, ChampTexte champ) {
    bool livreTrouve = false;
    const char *nomChamp = (champ == CHAMP_AUTEUR) ? "l'auteur" : "le titre";
    printf("Veuillez entrer %s du média recherché : ", nomChamp);

    char saisie[100];

    if (lireChaine(saisie, sizeof(saisie)) == NULL) {
        printf("Saisie invalide.\n");
        return;
    }
    
    if (strlen(saisie) > 100) {
        printf("Erreur : la recherche peut contenir au maximum 100 caractères.\n");
        return;
    }
    int i = 0;

    while (i < taille) {
        char *chaineAComparer = NULL;
        switch (champ) {
            case CHAMP_TITRE:
                chaineAComparer = collection[i].titre;
                break;
            case CHAMP_AUTEUR:
                chaineAComparer = collection[i].auteur;
                break;
        }

        if (chaineAComparer != NULL && comparerChaines(chaineAComparer, saisie) != NULL) {
            livreTrouve = true;
            printf("\nID : %d\n", collection[i].id);
            printf("Titre : %s\n", collection[i].titre);
            printf("Auteur : %s\n", collection[i].auteur);
            printf("Description : %s\n", collection[i].description);
            printf("Etat : %s\n",
                   collection[i].disponible ? "disponible" : "emprunté");
        }

        i++;
    }

    if (!livreTrouve) {
        printf("\nAucun livre correspondant.\n");
    }
}
