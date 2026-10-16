#include "../Main.h"
#include "stdio.h"

void afficherCollection(Livre collection[], int taille) {
  printf("Voici la collection\n");
  for (int i = 0; i < taille - 1; i++) {
    printf("{ id: %d, titre: %s, auteur: %s, disponible: %s }\n",
      collection[i].id, collection[i].titre, collection[i].auteur, collection[i].disponible ? "true" : "false");
  }
}