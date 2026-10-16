#include "../Main.h"
#include <stdio.h>
#include <stdbool.h>

void Menu(short choixMenu)
{ 
  Livre bibli[4] = {
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
    
    /* recupérer choix utilisateur et valider conformité + ajouter les IF ou SWITCH des differents resultat*/
    if(scanf("%hd", &choixMenu) != 1) {
      printf("\nERREUR : veuillez saisir un entier.\n");

      int c;
      while ((c = getchar()) != '\n' && c != EOF) {
      }
      choixMenu = -1;
      continue;
    }
    
    if (choixMenu < 0 || choixMenu > 3) {
      printf("\nERREUR : choisir un entier entre 0 et 3.\n");
    } else {
      switch (choixMenu) {
        case 1:
          printf("Ajout element\n");
          break;
        case 2:
          printf("Afficher les livres\n");
          afficherCollection(bibli, sizeof(bibli) / sizeof(bibli[0]));
          break;
        case 3:
          printf("Rechercher un livre\n");
          break;
        case 0:
          printf("Quitter\n");
          break;
      }
    }
  } while (choixMenu != 0);
}
