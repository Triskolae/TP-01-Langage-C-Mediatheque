/**
 * @file Livre.h
 * @brief Definitions des types et constantes associes aux livres.
 * @author Sarah et Tristan (projet en binome)
 * @date 2026-10-23 (mise a jour de la documentation)
 * @details Definitions des types et constantes associes aux livres.
 */

#ifndef LIVRE_H
#define LIVRE_H

#include <stdbool.h>
#include <stddef.h>

#define TAILLE_MAX 100

// Utilisation d'un enum pour réutiliser la fonction rechercherParChampTexte()
typedef enum {
    CHAMP_TITRE,
    CHAMP_AUTEUR
} ChampTexte;

typedef struct {
    int id;
    char titre[100];
    char auteur[100];
    short annee;
    char description[200];
    bool disponible;
} Livre;

#endif
