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

int chercherIndiceParId(Mediatheque *mediatheque, int idRecherche);

void supprimer(Mediatheque *mediatheque);

void supprimerMedia(Mediatheque *mediatheque, int indice);

void trier(Mediatheque *mediatheque);

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
