

#ifndef UTILITAIRES_H
#define UTILITAIRES_H

/**
 * @brief Convertit une chaîne de caractères en minuscules.
 *
 * Alloue dynamiquement une copie de la chaîne fournie, puis convertit
 * chacun de ses caractères en minuscule.
 *
 * La chaîne originale n'est pas modifiée.
 *
 * @param str Pointeur vers la chaîne de caractères à convertir.
 *
 * @return Un pointeur vers la nouvelle chaîne convertie en minuscules.
 * @return NULL si l'allocation mémoire échoue.
 *
 * @note La mémoire allouée doit être libérée par l'appelant à l'aide de free().
 * @note La chaîne retournée doit être libérée même après utilisation.
 */
char* convertirChaineMin(const char *str);

/** Lecture des saisies (src/lire.c) */
/**
 * @brief Lit et valide un choix dans un menu.
 * @param saisie Tampon recevant la saisie de l utilisateur.
 * @param taille Capacite du tampon ou nombre d elements selon le contexte.
 * @param nbChoix Nombre de valeurs possibles dans le menu.
 * @note Retourne -1 en fin d entree, -2 si la saisie est invalide.
 * @return Retourne -1 en fin d entree, -2 si la saisie est invalide.
 */
short lireChoixMenu(char *saisie, size_t taille, short nbChoix);
/**
 * @brief Lit un entier non negatif avec verification de la saisie.
 * @param saisie Tampon recevant la saisie de l utilisateur.
 * @param taille Capacite du tampon ou nombre d elements selon le contexte.
 * @note Retourne 0 lorsque la lecture ou la conversion echoue.
 * @return Retourne 0 lorsque la lecture ou la conversion echoue.
 */
int lireInt(char *saisie, size_t taille);
/**
 * @brief Lit une annee de publication et verifie ses limites.
 * @param saisie Tampon recevant la saisie de l utilisateur.
 * @param taille Capacite du tampon ou nombre d elements selon le contexte.
 * @note Retourne 0 en cas de saisie invalide ou de lecture interrompue.
 * @return Retourne 0 en cas de saisie invalide ou de lecture interrompue.
 */
short lireAnnee(char *saisie, size_t taille);
/**
 * @brief Lit une chaine non vide en respectant la taille du tampon.
 * @param saisie Tampon recevant la saisie de l utilisateur.
 * @param taille Capacite du tampon ou nombre d elements selon le contexte.
 * @note Retourne NULL si la saisie est invalide ou interrompue.
 * @return Retourne NULL si la saisie est invalide ou interrompue.
 */
char *lireChaine(char *saisie, size_t taille);
/**
 * @brief Recherche une sous-chaine sans distinguer la casse ASCII.
 * @param chaine Chaine dans laquelle effectuer la recherche.
 * @param sousChaine Texte recherche dans la chaine.
 * @note Retourne un pointeur vers la correspondance ou NULL si absente.
 * @return Retourne un pointeur vers la correspondance ou NULL si absente.
 */
const char *comparerChaines(const char *chaine, const char *sousChaine);

#endif