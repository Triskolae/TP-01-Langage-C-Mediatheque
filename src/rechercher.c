/**
 * @file rechercher.c
 * @brief Recherche de livres par identifiant, titre ou auteur.
 * @author Sarah et Tristan (projet en binome)
 * @date 2026-10-23 (mise a jour de la documentation)
 * @details Recherche de livres par identifiant, titre ou auteur.
 */

#include "../Mediatheque.h"
#include <stdio.h>
#include <string.h>
/**
 * @brief Pilote la recherche en fonction du critere choisi.
 * @param mediatheque Pointeur vers la mediatheque concernee.
 */
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
/**
 * @brief Recherche et affiche un livre par son identifiant.
 * @param mediatheque Pointeur vers la mediatheque concernee.
 */
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
            afficherLivre(livre);
            found = true;
            break;
        }
        i++;
    }
    if (!found && idRecherche != 0) {
        printf("Aucun média trouvé pour l'id %d\n", idRecherche);
    }
}

/**
 * @brief Recherche et affiche les livres correspondant au texte saisi.
 * @param mediatheque Pointeur vers la mediatheque concernee.
 * @param champ Champ textuel utilise pour la recherche.
 */
/** La recherche textuelle peut correspondre a plusieurs livres :
 *  le parcours ne s arrete pas a la premiere correspondance. */
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
            afficherLivre(livre);
        }

        i++;
    }

    if (!livreTrouve) {
        printf("\nAucun livre correspondant.\n");
    }
}

/**
 * @brief Selectionne un livre par ID, titre ou auteur pour une operation.
 * @param mediatheque Mediatheque consultee sans modification.
 * @return ID selectionne, ou 0 si annulation, erreur ou absence de resultat.
 * @note Une recherche textuelle affiche toutes les correspondances, puis
 *       exige l'ID d'un livre appartenant aux resultats affiches.
 */
int selectionnerLivre(Mediatheque *mediatheque) {
    if (mediatheque == NULL || mediatheque->nbLivres == 0) {
        printf("La mediatheque est vide.\n");
        return 0;
    }

    char saisie[100];
    afficherMenuSelectionLivre();
    short choix = lireChoixMenu(saisie, sizeof(saisie), 4);
    if (choix <= 0) {
        return 0;
    }

    if (choix == 1) {
        printf("ID du livre recherche : ");
        int id = lireInt(saisie, sizeof(saisie));
        if (id <= 0 || chercherIndiceParId(mediatheque, id) < 0) {
            printf("Livre introuvable ou ID invalide.\n");
            return 0;
        }
        return id;
    }

    ChampTexte champ = (choix == 2) ? CHAMP_TITRE : CHAMP_AUTEUR;
    printf("Saisissez tout ou partie %s : ",
           (champ == CHAMP_TITRE) ? "du titre" : "du nom de l'auteur");
    if (lireChaine(saisie, sizeof(saisie)) == NULL) {
        printf("Recherche annulee : saisie invalide.\n");
        return 0;
    }

    /* Conserver le critere pour verifier l'ID choisi apres affichage. */
    char recherche[100];
    strcpy(recherche, saisie);
    int nombreResultats = 0;
    for (int i = 0; i < mediatheque->nbLivres; i++) {
        const Livre *livre = &mediatheque->collection[i];
        const char *texte = (champ == CHAMP_TITRE) ? livre->titre : livre->auteur;
        if (comparerChaines(texte, recherche) != NULL) {
            afficherLivre(livre);
            nombreResultats++;
        }
    }

    if (nombreResultats == 0) {
        printf("Aucun livre correspondant.\n");
        return 0;
    }

    printf("\nID du livre choisi parmi ces resultats (0 pour annuler) : ");
    int id = lireInt(saisie, sizeof(saisie));
    if (id <= 0) {
        return 0;
    }

    /* Evite de pouvoir selectionner un livre absent des resultats. */
    for (int i = 0; i < mediatheque->nbLivres; i++) {
        const Livre *livre = &mediatheque->collection[i];
        const char *texte = (champ == CHAMP_TITRE) ? livre->titre : livre->auteur;
        if (livre->id == id && comparerChaines(texte, recherche) != NULL) {
            return id;
        }
    }
    printf("Cet ID ne figure pas parmi les resultats.\n");
    return 0;
}
