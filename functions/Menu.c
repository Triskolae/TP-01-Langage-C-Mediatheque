#include "../Main.h"
#include <stdio.h>
#include <stdlib.h>
// #include <errno.h>
// #include <limits.h>
#include <string.h>

void Menu()
{
  short choixMenu = -1;
  char saisie[100];

  Livre bibli[6] = {
  {
    1,
    "Harry Potter a l'ecole des sorciers",
    "J.K. Rowling",
    "Un jeune sorcier decouvre ses pouvoirs et entre a Poudlard.",
    true
  },
  {
    2,
    "Harry Potter et la chambre des secrets",
    "J.K. Rowling",
    "Harry retourne a Poudlard et enquete sur un mystere dangereux.",
    false
  },
  {
    3,
    "Dune",
    "Frank Herbert",
    "Paul Atreides decouvre les enjeux politiques et ecologiques d'Arrakis.",
    true
  },
  {
    4,
    "L'Assassin royal",
    "Robin Hobb",
    "Fitz, fils illegitime d'un prince, est forme aux arts de l'assassinat.",
    true
  }
};

  do {
    printf("\n========== MA PETITE MEDIATHEQUE ==========\n");
    printf("1 : Ajouter un livre\n");
    printf("2 : Afficher les livres\n");
    printf("3 : Rechercher un livre\n");
    printf("0 : Quitter\n");
    printf("Saisissez votre choix :\n");
    
    // LIRE choix_menu
    choixMenu = lire(saisie, sizeof(saisie), 4);
    printf("choixMenu%d\n", choixMenu);

    if (choixMenu == -1) {
      break;
    }
    if (choixMenu == -2) {
      continue;
    }
    // fin LIRE choix_menu

    // if (choixMenu < 0 || choixMenu > 3) {
    //   printf("\nERREUR : veuillez choisir un entier entre 0 et 3.\n");
    // } else {
    switch (choixMenu) {
      case 1:
        printf("\n-> Ajout element\n");
        printf("Not implemented yet\n");
        break;
      case 2:
        printf("\n-> Afficher les livres\n");
        afficherCollection(bibli, sizeof(bibli) / sizeof(bibli[0]));
        break;
      case 3:
        printf("\n-> Rechercher un livre\n");
        printf("Not implemented yet\n");
        break;
      case 0:
        printf("\n-> Quitter\n");
        break;
    }
    // }
  } while (choixMenu != 0);
}
