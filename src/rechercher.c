#include "../Mediatheque.h"
#include <stdio.h>
#include <string.h>

void rechercher(const Mediatheque *mediatheque) {
    short choixMenu = -1;
    char saisie[100];

    if (mediatheque->nbLivres == 0) {
        printf("La médiathèque est vide.\n");
        return;
    }

    do {
        afficherMenuRecherche();

        choixMenu = lireChoixMenu(saisie, sizeof(saisie), 4);

        switch (choixMenu) {
            case -1:
                return;

            case -2:
                break;

            case 1:
                rechercherParId(mediatheque);
                break;

            case 2:
                rechercherParChampTexte(mediatheque, CHAMP_TITRE);
                break;

            case 3:
                rechercherParChampTexte(mediatheque, CHAMP_AUTEUR);
                break;

            case 0:
                break;

            default:
                printf("Choix invalide.\n");
                break;
        }
    } while (choixMenu != 0);
}

void rechercherParId(const Mediatheque *mediatheque) {
    printf("Veuillez entrer l'id du média recherché: ");
    int idRecherche = 0;
    char saisie[100];
    bool found = false;

    idRecherche = lireInt(saisie, sizeof(saisie));

    int i = 0;

    while (i < mediatheque->nbLivres) {
        const Livre *livre = &mediatheque->collection[i];

        if (livre->id == idRecherche) {
            printf("\nID : %d\n", livre->id);
            printf("Titre : %s\n", livre->titre);
            printf("Auteur : %s\n", livre->auteur);
            printf("Description : %s\n", livre->description);
            printf("Etat : %s\n", livre->disponible ? "disponible" : "emprunté");
            found = true;
            break;
        }
        i++;
    }
    if (!found && idRecherche != 0) {
        printf("Aucun média trouvé pour l'id %d\n", idRecherche);
    }
}

void rechercherParChampTexte(const Mediatheque *mediatheque, ChampTexte champ) {
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

    while (i < mediatheque->nbLivres) {
        const Livre *livre = &mediatheque->collection[i];

        const char *chaineAComparer = NULL;
        switch (champ) {
            case CHAMP_TITRE:
                chaineAComparer = livre->titre;
                break;
            case CHAMP_AUTEUR:
                chaineAComparer = livre->auteur;
                break;
        }

        if (chaineAComparer != NULL && comparerChaines(chaineAComparer, saisie) != NULL) {
            livreTrouve = true;
            printf("\nID : %d\n", livre->id);
            printf("Titre : %s\n", livre->titre);
            printf("Auteur : %s\n", livre->auteur);
            printf("Description : %s\n", livre->description);
            printf("Etat : %s\n", livre->disponible ? "disponible" : "emprunté");
        }

        i++;
    }

    if (!livreTrouve) {
        printf("\nAucun livre correspondant.\n");
    }
}
