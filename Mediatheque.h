/**
 * @file Mediatheque.h
 * @brief Structure de la mediatheque et declarations des fonctions partagees.
 * @author Sarah et Tristan (projet en binome)
 * @date 2026-10-23 (mise a jour de la documentation)
 * @details Structure de la mediatheque et declarations des fonctions partagees.
 */

#ifndef MEDIATHEQUE_H
#define MEDIATHEQUE_H

#include "Livre.h"

/** Structure regroupant les donnees de la mediatheque */
typedef struct {
    Livre collection[TAILLE_MAX];
    int nbLivres;
    int prochainId;
} Mediatheque;

/** Ajout de livres (src/ajouter.c) */
/**
 * @brief Saisit un livre et l ajoute apres confirmation.
 * @param mediatheque Pointeur vers la mediatheque concernee.
 * @note Modifie la collection, nbLivres et prochainId de l appelant uniquement si l ajout est confirme.
 */
void ajouterLivre(Mediatheque *mediatheque);

/** Sous-menus (src/menu.c) */
/**
 * @brief Affiche les choix du sous-menu d affichage.
 */
void afficherMenuAffichage(void);
/**
 * @brief Affiche les choix du sous-menu de recherche.
 */
void afficherMenuRecherche(void);
/**
 * @brief Affiche les choix de confirmation d un ajout.
 */
void afficherMenuConfirmation(void);
/**
 * @brief Affiche les champs pouvant etre corriges.
 */
void afficherMenuCorrection(void);

/** Affichage des livres (src/afficher.c) */
/**
 * @brief Pilote l affichage de la collection selon le filtre choisi.
 * @param mediatheque Pointeur vers la mediatheque concernee.
 */
void afficher(const Mediatheque *mediatheque);
/**
 * @brief Affiche les informations de tous les livres.
 * @param mediatheque Pointeur vers la mediatheque concernee.
 */
void afficherTous(const Mediatheque *mediatheque);
/**
 * @brief Affiche les livres correspondant a un etat de disponibilite.
 * @param mediatheque Pointeur vers la mediatheque concernee.
 * @param disponible Etat de disponibilite utilise pour le filtrage.
 */
void afficherParEtat(const Mediatheque *mediatheque, bool disponible);

/** Recherche des livres (src/rechercher.c) */
/**
 * @brief Pilote la recherche en fonction du critere choisi.
 * @param mediatheque Pointeur vers la mediatheque concernee.
 */
void rechercher(const Mediatheque *mediatheque);
/**
 * @brief Recherche et affiche un livre par son identifiant.
 * @param mediatheque Pointeur vers la mediatheque concernee.
 */
void rechercherParId(const Mediatheque *mediatheque);
/**
 * @brief Recherche et affiche les livres correspondant au texte saisi.
 * @param mediatheque Pointeur vers la mediatheque concernee.
 * @param champ Champ textuel utilise pour la recherche.
 */
void rechercherParChampTexte(const Mediatheque *mediatheque, ChampTexte champ);

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
