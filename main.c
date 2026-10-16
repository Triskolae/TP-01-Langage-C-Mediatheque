#include "./Main.h"
#include <stdio.h>

int main(void) {

  short choixMenu;
  choixMenu = -1;
  Menu(choixMenu);
	return 0;
}

// gcc -o main main.c
// gcc main.c src/Menu.c -o main

// gcc -Wall -Wextra -o main main.c
// gcc -Wall -Wextra main.c src/Menu.c -o main

// gcc -Wall -Wextra main.c functions/* -o main
