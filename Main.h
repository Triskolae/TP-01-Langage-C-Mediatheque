#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    int id;
    char titre[50];
    char auteur[50];
    char description[200];
    bool disponible;
} Livre;

void Menu();
void afficherCollection(Livre collection[], int taille);
short lire(char *saisie, size_t taille, short nbChoix);

#endif
