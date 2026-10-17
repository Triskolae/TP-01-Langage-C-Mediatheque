#include "../Main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu()
{
  short choixMenu = -1;
  char saisie[100];

  Livre collection[6] = {
    {
      1,
      "Harry Potter à l'école des sorciers",
      "J.K. Rowling",
      "Un jeune sorcier découvre ses pouvoirs et entre à Poudlard.",
      true
    },
    {
      2,
      "Harry Potter et la Chambre des Secrets",
      "J.K. Rowling",
      "Harry retourne a Poudlard et enquête sur un mystère dangereux.",
      false
    },
    {
      3,
      "Dune",
      "Frank Herbert",
      "Paul Atréides decouvre les enjeux politiques et écologiques d'Arrakis.",
      true
    },
    {
      4,
      "L'Assassin Royal",
      "Robin Hobb",
      "Fitz, fils illégitime d'un prince, est formé aux arts de l'assassinat.",
      true
    }
  };

  int nbLivres = 0;
  for (int i = 0; i < (int)(sizeof(collection) / sizeof(collection[0])); i++) {
    if (collection[i].id > 0) {
      nbLivres++;
    }
  }

  do {
    printf("\n========== MA PETITE MEDIATHEQUE ==========\n");
    printf("1 : Ajouter un livre\n");
    printf("2 : Afficher les livres\n");
    printf("3 : Rechercher un livre\n");
    printf("0 : Quitter\n");
    printf("Saisissez votre choix :\n");
    
    choixMenu = lire(saisie, sizeof(saisie), 4);
    // Gestion des cas d'errreurs de lire()
    if (choixMenu == -1) {
      break;
    }
    if (choixMenu == -2) {
      continue;
    }

    switch (choixMenu) {
      case 1:
        printf("\n-> Ajout element\n");
        printf("Not implemented yet\n");
        break;
      case 2:
        printf("\n-> Afficher les livres\n");
        afficherCollection(collection, nbLivres);
        break;
      case 3:
        printf("\n-> Rechercher un livre\n");
        printf("Not implemented yet\n");
        break;
      case 0:
        printf("\n-> Quitter\n");
        break;
    }
  } while (choixMenu != 0);
}
