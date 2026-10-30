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
#include "Utilitaires.h"

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

/**
 * @brief Recherche l'indice d'un livre à partir de son identifiant.
 *
 * Parcourt la collection de la médiathèque afin de retrouver le livre
 * correspondant à l'identifiant fourni.
 *
 * @param mediatheque Pointeur vers la médiathèque dans laquelle effectuer la recherche.
 * @param idRecherche Identifiant du livre recherché.
 *
 * @return L'indice du livre dans le tableau s'il est trouvé, -1 sinon.
 */
int chercherIndiceParId(Mediatheque *mediatheque, int idRecherche);

/**
 * @brief Affiche le menu de suppression d'un media.
 *
 * Vérifie la saisie de l'utilisateur et propose la suppression de l'élément choisi.
 *
 * @param mediatheque Pointeur vers la médiathèque dans laquelle effectuer la suppression.
 */
void supprimer(Mediatheque *mediatheque);

/**
 * @brief Supprime un média à partir de son indice dans la collection.
 *
 * Supprime le média situé à l'indice indiqué et réorganise la collection
 * afin de conserver un tableau sans emplacement vide entre les éléments.
 *
 * @param mediatheque Pointeur vers la médiathèque concernée.
 * @param indice Indice du média à supprimer dans le tableau.
 */
void supprimerMedia(Mediatheque *mediatheque, int indice);

/**
 * @brief Propose à l'utilisateur de trier la médiathèque par titre.
 *
 * Affiche un menu permettant à l'utilisateur de choisir s'il souhaite
 * effectuer un tri alphabétique des médias.
 *
 * Si l'utilisateur confirme son choix, la fonction appelle triBulles()
 * pour effectuer le tri. Dans le cas contraire, le tri est annulé.
 *
 * @param mediatheque Pointeur vers la médiathèque à trier.
 */
void trier(Mediatheque *mediatheque);

/**
 * @brief Trie les médias de la médiathèque par ordre alphabétique de titre.
 *
 * Utilise l'algorithme de tri à bulles (Bubble Sort) pour classer les médias
 * selon leur titre, sans tenir compte de la différence entre majuscules
 * et minuscules.
 *
 * À chaque itération, deux titres consécutifs sont comparés. Si le premier
 * est alphabétiquement supérieur au second, les deux médias sont échangés.
 *
 * Une fois le tri terminé, un message de confirmation est affiché.
 *
 * @param mediatheque Pointeur vers la médiathèque contenant les médias à trier.
 *
 * @note Le tri est effectué directement dans le tableau collection.
 * @note La complexité temporelle de cet algorithme est O(n²).
 * @note La comparaison des titres est réalisée après conversion temporaire
 *       des chaînes en minuscules.
 *
 * @see convertirChaineMin()
 *
 * @author Algorithme de tri à bulles adapté depuis :
 *         https://coddy.tech/visualize/sorting/bubble-sort
 */
void triBulles(Mediatheque *mediatheque);

/** Emprunt de livres (src/emprunter.c) */
/** @brief Emprunte un livre disponible en utilisant son ID.
 *  @return 1 si l'emprunt reussit, 0 sinon.
 */
int emprunterLivre(Mediatheque *mediatheque, int idCible);

/** @brief Gere la selection et la confirmation de l'emprunt. */
void gererEmprunt(Mediatheque *mediatheque);

/** @brief Selectionne un livre par ID, titre ou auteur.
 *  @return ID choisi, ou 0 en cas d'annulation ou d'echec.
 */
int selectionnerLivre(Mediatheque *mediatheque);

/** @brief Affiche le sous-menu de recherche pour une operation. */
void afficherMenuSelectionLivre(void);

/** Retour de livres (src/rendre.c) */
/**
 * @brief Rend un livre actuellement emprunte.
 * @param mediatheque Mediatheque a modifier.
 * @param idCible Identifiant du livre a rendre.
 * @return 1 si le retour reussit, 0 sinon.
 */
int rendreLivre(Mediatheque *mediatheque, int idCible);
/** @brief Gere la selection et la confirmation du retour d'un livre. */
void gererRetour(Mediatheque *mediatheque);

/** Statistiques de la mediatheque (src/statistiques.c) */
/**
 * @brief Affiche le nombre total, disponible et emprunte de livres.
 * @param mediatheque Pointeur constant vers la mediatheque a consulter.
 * @note Ne modifie pas la collection.
 */
void afficherStatistiques(const Mediatheque *mediatheque);

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

void afficherLivre(const Livre *livre);

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


#endif
