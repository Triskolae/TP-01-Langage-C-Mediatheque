#ifndef MEDIATHEQUE_H
#define MEDIATHEQUE_H

#include "Livre.h"

// Structure regroupant les donnees de la mediatheque
typedef struct {
    Livre collection[TAILLE_MAX];
    int nbLivres;
    int prochainId;
} Mediatheque;

#endif
