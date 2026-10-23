#ifndef MEDIATHEQUE_H
#define MEDIATHEQUE_H

#include "Livre.h"

// Structure regroupant les donnees de la mediatheque
typedef struct {
    Livre collection[TAILLE_MAX];
    int nbLivres;
    int prochainId;
} Mediatheque;

// Ajout de livres (src/ajouter.c)
void ajouterLivre(Livre collection[], int * const nbLivres, int * const prochainId);

// Sous-menus (src/menu.c)
void afficherMenuAffichage(void);
void afficherMenuRecherche(void);
void afficherMenuConfirmation(void);
void afficherMenuCorrection(void);

// Affichage des livres (src/afficher.c)
void afficher(Livre collection[], int taille);
void afficherTous(Livre collection[], int taille);
void afficherParEtat(Livre collection[], int taille, bool disponible);

// Recherche des livres (src/rechercher.c)
void rechercher(Livre collection[], int taille);
void rechercherParId(Livre collection[], int taille);
void rechercherParChampTexte(Livre collection[], int taille, ChampTexte champ);

// Lecture des saisies (src/lire.c)
short lireChoixMenu(char *saisie, size_t taille, short nbChoix);
int lireInt(char *saisie, size_t taille);
short lireAnnee(char *saisie, size_t taille);
char *lireChaine(char *saisie, size_t taille);
char *comparerChaines(char *chaine, char *sousChaine);

#endif
