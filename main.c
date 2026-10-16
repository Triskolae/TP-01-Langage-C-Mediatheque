#include "./Main.h"
#include <stdio.h>

int main(void) {

  short userInput;

  do {
    printf("========== MA PETITE MEDIATHEQUE ==========\n");
    printf("1 : Ajouter un livre\n");
    printf("2 : Afficher les livres\n");
    printf("3 : Rechercher un livre\n");
    printf("0 : Quitter\n");
    printf("Saisissez votre choix :\n");
    userInput = scanf("Saisissez votre choix : %d", &userInput);

    /* recupérer choix utilisateur et valider conformité + ajouter les IF ou SWITCH des differents resultat*/
  
  } while (0);
	return 0;
}

// gcc -o main main.c
// gcc main.c src/Menu.c -o programme
