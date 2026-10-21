#include "../Main.h"
#include <stdio.h>
#include <stdlib.h>


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
    printf("2 : Par titre (egalite exacte)\n");
    printf("3 : Par auteur (egalite exacte)\n");
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
    printf("0 : Revenir au recapitulatif\n");
    printf("Saisissez votre choix : ");
}
