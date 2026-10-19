
#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <stddef.h>

#define TAILLE_MAX 100

typedef struct {
    int id;
    char titre[50];
    char auteur[50];
    char description[200];
    bool disponible;
} Livre;

// Sous-menus (src/menu.c)
void afficherMenuAffichage(void);
void afficherMenuRecherche(void);
void afficherMenuConfirmation(void);
void afficherMenuCorrection(void);

// Affichage des livres (src/afficher.c)
void afficherCollection(Livre collection[], int taille);
void afficherTous(Livre collection[], int taille);
void afficherParEtat(Livre collection[], int taille, bool disponible);

// Lecture des saisies (src/lire.c)
short lire(char *saisie, size_t taille, short nbChoix);

#endif
