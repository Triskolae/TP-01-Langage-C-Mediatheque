/**
 * @file menu.c
 * @brief Navigation dans le menu principal et affichage des sous-menus.
 * @author Sarah et Tristan (projet en binome)
 * @date 2026-10-23 (mise a jour de la documentation)
 * @details Navigation dans le menu principal et affichage des sous-menus.
 */

#include "../Menu.h"
#include <stdio.h>


/** Gestion du menu principal de la mediatheque */
/**
 * @brief Affiche le menu principal et oriente les actions utilisateur.
 * @param mediatheque Pointeur vers la mediatheque concernee.
 * @note Transmet la mediatheque aux fonctions pouvant la modifier.
 */
void lancerMenuPrincipal(Mediatheque *mediatheque) {
    if (mediatheque == NULL) {
        return;
    }

    short choixMenu = -1;
    char saisie[100];

    do {
        /** MENU PRINCIPAL */
        printf("\n========== MA PETITE MEDIATHEQUE ==========\n");
        printf("1 : Ajouter un livre\n");
        printf("2 : Afficher les livres\n");
        printf("3 : Rechercher un livre\n");
        printf("4 : Supprimer un livre\n");
        printf("5 : Trier la mediathèque\n");
        printf("6 : Emprunter un livre\n");
        printf("7 : Rendre un livre\n");
        printf("0 : Quitter\n");
        printf("Saisissez votre choix : ");

        choixMenu = lireChoixMenu(saisie, sizeof saisie, 8);

        switch (choixMenu) {
            case -1:
                printf("\nFin de la saisie.\n");
                return;

            case -2:
                break;

            case 1:
                /** Fonction à créer dans src/ajouter.c */
                ajouterLivre(mediatheque);
                break;

            case 2:
                /** Fonction définie dans src/afficher.c */
                afficher(mediatheque);
                break;

            case 3:
                /** Fonction à créer dans src/rechercher.c */
                rechercher(mediatheque);
                break;

            case 4:
                supprimer(mediatheque);
                break;
                
            case 5:
                trier(mediatheque);
                break;

            case 6:
                gererEmprunt(mediatheque);
                break;

            case 7:
                gererRetour(mediatheque);
                break;

            case 0:
                printf("\nFermeture de la médiathèque.\n");
                break;
        }

    } while (choixMenu != 0);
}


/** Sous-menu d'affichage des livres */
/**
 * @brief Affiche les choix du sous-menu d affichage.
 */
void afficherMenuAffichage(void) {
    printf("\n========== AFFICHAGE ==========\n");
    printf("Quels livres souhaitez-vous afficher ?\n");
    printf("1 : Tous les livres\n");
    printf("2 : Livres disponibles\n");
    printf("3 : Livres empruntes\n");
    printf("0 : Retour au menu principal\n");
    printf("Saisissez votre choix : ");
}

/** Sous-menu de recherche */
/**
 * @brief Affiche les choix du sous-menu de recherche.
 */
void afficherMenuRecherche(void) {
    printf("\n========== RECHERCHE ==========\n");
    printf("1 : Par identifiant\n");
    printf("2 : Par titre\n");
    printf("3 : Par auteur\n");
    printf("0 : Retour au menu principal\n");
    printf("Saisissez votre choix : ");
}

/** Sous-menu de confirmation d'ajout */
/**
 * @brief Affiche les choix de confirmation d un ajout.
 */
void afficherMenuConfirmation(void) {
    printf("\nQue souhaitez-vous faire ?\n");
    printf("1 : Confirmer\n");
    printf("2 : Corriger un ou plusieurs champs\n");
    printf("3 : Annuler\n");
    printf("Saisissez votre choix : ");
}

/** Sous-menu de correction d'un livre */
/**
 * @brief Affiche les champs pouvant etre corriges.
 */
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

/**
 * @brief Affiche les criteres de recherche d'un livre a emprunter.
 */
void afficherMenuSelectionLivre(void) {
    printf("\n========== SELECTIONNER UN LIVRE ==========\n");
    printf("Comment souhaitez-vous rechercher le livre ?\n");
    printf("1 : Par ID\n");
    printf("2 : Par titre\n");
    printf("3 : Par auteur\n");
    printf("0 : Retour au menu principal\n");
    printf("Saisissez votre choix : ");
}
