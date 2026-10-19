#include "../Main.h"
#include "stdio.h"

void afficherCollection(Livre collection[], int taille) {
  short choixMenu = -1;
  char saisie[100];

  if (taille == 0) {
    printf("La médiathèque est vide.\n");
    return;
  }

  do {
    printf("\n========== AFFICHAGE ==========\n");
    printf("Quels livres souhaitez-vous afficher ? Saisissez votre choix :\n");
    printf("1 : Tous les livres\n");
    printf("2 : Livres disponibles\n");
    printf("3 : Livres empruntés\n");
    printf("0 : Retour au menu principal\n");

    choixMenu = lire(saisie, sizeof(saisie), 4);
    if (choixMenu == -1) {
      break;
    }
    if (choixMenu == -2) {
      continue;
    }

    switch (choixMenu) {
      case 1:
        afficherTous(collection, taille);
        break;
      case 2:
        afficherParEtat(collection, taille, true);
        break;
      case 3:
        afficherParEtat(collection, taille, false);
        break;
      case 0:
        break;
      default:
        printf("Not implemented yet\n");
        break;
    }
  } while (choixMenu != 0);
}

void afficherTous(Livre collection[], int taille) {
  printf("\nVoici la collection des médias:\n");
  int i = 0;
  while (i < taille) {
    if (collection[i].id > 0) {
    printf("{ id: %d, titre: %s, auteur: %s, disponible: %s }\n",
      collection[i].id, collection[i].titre, collection[i].auteur, collection[i].disponible ? "disponible" : "emprunté");
    }
    i++;
  }
}

void afficherParEtat(Livre collection[], int taille, bool disponible) {
  printf("\nVoici la collection des médias %s:\n", disponible ? "disponibles" : "empruntés");
  int i = 0;
  int compteur = 0;

  while (i < taille) {
    if (collection[i].id > 0 && collection[i].disponible == disponible) {
    printf("{ id: %d, titre: %s, auteur: %s, état: %s }\n",
      collection[i].id, collection[i].titre, collection[i].auteur, collection[i].disponible ? "disponible" : "emprunté");
      compteur++;
    }
    i++;
  }
  
  if (compteur == 0) {
    printf("Aucun livre %s.\n", disponible ? "disponible" : "emprunté");
  }
}
