#include "./src/Main.h"
#include <stdio.h>

int main(void) {

  /*vérifier si il faut instancier choix_utilisateur*/
  
  do {
    printf("========== MA PETITE MEDIATHEQUE ==========\n");
    printf("1 : Ajouter un livre\n");
    printf("2 : Afficher les livres\n");
    printf("3 : Rechercher un livre\n");
    printf("0 : Quitter\n");
    printf("Saisissez votre choix :\n");

    /* recupérer choix utilisateur et valider conformité + ajouter les IF ou SWITCH des differents resultat*/
  
  } while (0);
	return 0;
}

// gcc -o main main.c
// gcc main.c src/Menu.c -o programme
