#include "../Main.h"
#include "stdio.h"

void afficherCollection(Livre collection[], int taille) {
  short choixMenu = -1;
  char saisie[100];

  if (taille == 0) {
    printf("La médiathèque est vide.\n");
    return;
  }

  printf("Voici la collection, %d éléments:\n", taille);
  int i = 0;
  while (i < taille) {
    printf("{ id: %d, titre: %s, auteur: %s, disponible: %s }\n",
      collection[i].id, collection[i].titre, collection[i].auteur, collection[i].disponible ? "true" : "false");
      i++;
  }

  printf("\n========== AFFICHAGE ==========\n");
  printf("Quels livres souhaitez-vous afficher ? Saisissez votre choix :\n");
  printf("1 : Tous les livres\n");
  printf("2 : Livres disponibles\n");
  printf("3 : Livres empruntés\n");
  printf("0 : Retour au menu principal\n");

  choixMenu = lire(saisie, sizeof(saisie), 4);
  printf("choixMenu%d\n", choixMenu);
  
}