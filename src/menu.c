#include "../Menu.h"
#include <stdio.h>


// Gestion du menu principal de la mediatheque
void lancerMenuPrincipal(Livre collection[], int * const nbLivres, int * const prochainId) {
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

        choixMenu = lireChoixMenu(saisie, sizeof saisie, 4);

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
                ajouterLivre(collection, nbLivres, prochainId);
                break;

            case 2:
                // Fonction définie dans src/afficher.c
                afficher(collection, *nbLivres);
                break;

            case 3:
                // Fonction à créer dans src/rechercher.c
                rechercher(collection, *nbLivres);
                break;

            case 0:
                printf("\nFermeture de la médiathèque.\n");
                break;
        }

    } while (choixMenu != 0);
}


// Sous-menu d'affichage des livres
void afficherMenuAffichage(void) {
    printf("\n========== AFFICHAGE ==========\n");
    printf("Quels livres souhaitez-vous afficher ?\n");
    printf("1 : Tous les livres\n");
    printf("2 : Livres disponibles\n");
    printf("3 : Livres empruntes\n");
    printf("0 : Retour au menu principal\n");
    printf("Saisissez votre choix : ");
}

// Sous-menu de recherche
void afficherMenuRecherche(void) {
    printf("\n========== RECHERCHE ==========\n");
    printf("1 : Par identifiant\n");
    printf("2 : Par titre\n");
    printf("3 : Par auteur\n");
    printf("0 : Retour au menu principal\n");
    printf("Saisissez votre choix : ");
}

// Sous-menu de confirmation d'ajout
void afficherMenuConfirmation(void) {
    printf("\nQue souhaitez-vous faire ?\n");
    printf("1 : Confirmer\n");
    printf("2 : Corriger un ou plusieurs champs\n");
    printf("3 : Annuler\n");
    printf("Saisissez votre choix : ");
}

// Sous-menu de correction d'un livre
void afficherMenuCorrection(void) {
    printf("\n========== CORRECTION ==========\n");
    printf("Quel champ souhaitez-vous corriger ?\n");
    printf("1 : Corriger le titre\n");
    printf("2 : Corriger l'auteur\n");
    printf("3 : Corriger la description\n");
    printf("4 - Corriger l'année\n");
    printf("0 : Revenir au recapitulatif\n");
    printf("Saisissez votre choix : ");
}
