#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>

typedef struct {
    int id;
    char titre[50];
    char auteur[50];
    char description[200];
    bool disponible;
} Livre;

void Menu(short choixMenu);
void afficherCollection(Livre collection[], int taille);

#endif
