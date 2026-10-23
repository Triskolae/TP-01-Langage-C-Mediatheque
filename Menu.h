/**
 * @file Menu.h
 * @brief Declaration du point d entree du menu principal.
 * @author Sarah et Tristan (projet en binome)
 * @date 2026-10-23 (mise a jour de la documentation)
 * @details Declaration du point d entree du menu principal.
 */

#ifndef MENU_H
#define MENU_H

#include "Mediatheque.h"
/**
 * @brief Affiche le menu principal et oriente les actions utilisateur.
 * @param mediatheque Pointeur vers la mediatheque concernee.
 * @note Transmet la mediatheque aux fonctions pouvant la modifier.
 */
void lancerMenuPrincipal(Mediatheque *mediatheque);

#endif