#ifndef LIVRE_H
#define LIVRE_H

#include <stdbool.h>
#include <stddef.h>

#define TAILLE_MAX 100

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
