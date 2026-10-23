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
void ajouterLivre(Mediatheque *mediatheque);

// Sous-menus (src/menu.c)
void afficherMenuAffichage(void);
void afficherMenuRecherche(void);
void afficherMenuConfirmation(void);
void afficherMenuCorrection(void);

// Affichage des livres (src/afficher.c)
void afficher(const Mediatheque *mediatheque);
void afficherTous(const Mediatheque *mediatheque);
void afficherParEtat(const Mediatheque *mediatheque, bool disponible);

// Recherche des livres (src/rechercher.c)
void rechercher(const Mediatheque *mediatheque);
void rechercherParId(const Mediatheque *mediatheque);
void rechercherParChampTexte(const Mediatheque *mediatheque, ChampTexte champ);

// Lecture des saisies (src/lire.c)
short lireChoixMenu(char *saisie, size_t taille, short nbChoix);
int lireInt(char *saisie, size_t taille);
short lireAnnee(char *saisie, size_t taille);
char *lireChaine(char *saisie, size_t taille);
const char *comparerChaines(const char *chaine, const char *sousChaine);

#endif
