#include "../Main.h"
#include <stdio.h>
#include <string.h>

// Procédure de réaffichage du réacapitulatif de saisie utilisateur, propre a l'operation d'ajout d'un livre
static void afficherRecapitulatifAjout(const Livre * const livre) {
    if (livre == NULL) {
        return;
    }

    printf("\n--- RECAPITULATIF DE VOTRE SAISIE ---\n");
    printf("Titre       : %s\n", livre->titre);
    printf("Auteur      : %s\n", livre->auteur);
    printf("Description : %s\n", livre->description);
}


//fonction principale AJOUT DE LIVRE :

void ajouterLivre(Livre collection[], int * const nbLivres) {
// on met int * const nbLivre car je souhaites que le pointeur ne puisse pas être redirigé vers une autre adresse dans la fonction, mais que l'on puisse modifier l'entier pointé.

    // Verifier que les adresses recues sont valides:
    if (collection == NULL || nbLivres == NULL) {
        fprintf(stderr, "ERREUR : parametre invalide.\n");
        return;
    }

    // Verifier la coherence du nombre de livres
    if (*nbLivres < 0 || *nbLivres > TAILLE_MAX) {
        fprintf(stderr, "ERREUR : nombre de livres invalide.\n");
        return;
    }

    // Refuser l'ajout si la collection est pleine
    if (*nbLivres == TAILLE_MAX) {
        printf("ERREUR : mediatheque pleine (%d livres).\n", TAILLE_MAX);
        return;
    }

    Livre nouveauLivre = {0};
    // crée une structure locale qui contient les informations du livre en cours de saisie


    // Saisir TITRE
    do {
        printf("Saisissez le titre du livre : ");

        if (lireChaine(nouveauLivre.titre,
                       sizeof nouveauLivre.titre) != NULL) {
            break;
        }

        // Arreter l'ajout si l'entree standard est fermée ou si une erreur de lecture survient.
        if (feof(stdin) || ferror(stdin)) {
            printf("Lecture interrompue : ajout annulé.\n");
            return;
        }

    } while (1);


    // Saisir AUTEUR
    do {
        printf("Saisissez l'auteur du livre : ");

        if (lireChaine(nouveauLivre.auteur,
                       sizeof nouveauLivre.auteur) != NULL) {
            break;
        }

        if (feof(stdin) || ferror(stdin)) {
            printf("Lecture interrompue : ajout annule.\n");
            return;
        }

    } while (1);


    // Saisir DESCRIPTION
    do {
        printf("Saisissez la description du livre : ");

        if (lireChaine(nouveauLivre.description,
                       sizeof nouveauLivre.description) != NULL) {
            break;
        }

        if (feof(stdin) || ferror(stdin)) {
            printf("Lecture interrompue : ajout annule.\n");
            return;
        }

    } while (1);


    // Boucle de confirmation de l'ajout :
    short choix;

    do {
        afficherRecapitulatifAjout(&nouveauLivre);

        // Afficher le menu de confirmation existant de Tristan (Confirmer / Corriger / Anuler)
        afficherMenuConfirmation();

        // Lire le choix de l'utilisateur
        char saisie[20];
        choix = lireChoixMenu(saisie, sizeof saisie, 4);

        if (choix == -1) {
            printf("Lecture interrompue : ajout annule.\n");
            return;
        }

        if (choix == -2) {
            // Saisie invalide : reafficher le menu.
            continue;
        }

        if (choix == 0) {
            printf("ERREUR : veuillez choisir 1, 2 ou 3.\n");
            continue;
        }

        // CHOIX UTILISATEUR valide: ANNULATION
        if (choix == 3) {
            printf("Ajout du livre annulé.\n");
            printf("Retour au menu principal.\n");
            return;
        }

        // CHOIX UTILISATEUR valide: CORRECTION
        if (choix == 2) {
            char saisieCorrection[20];
            short choixCorrection;

            // Boucle de correction
            do {
                afficherMenuCorrection();

                choixCorrection = lireChoixMenu(
                    saisieCorrection,
                    sizeof saisieCorrection,
                    4
                );

                if (choixCorrection == -1) {
                    printf("Lecture interrompue : ajout annulé.\n");
                    return;
                }

                if (choixCorrection == -2) {
                    continue;
                }

                if (choixCorrection == 0) {
                    break;
                }

                // Nous traiterons ici la modification de champ:
                char *champ = NULL;
                size_t tailleChamp = 0;
                const char *nomChamp = NULL;

                switch (choixCorrection) {
                    case 1:
                        champ = nouveauLivre.titre;
                        tailleChamp = sizeof nouveauLivre.titre; //Ici on préfère utiliser sizeof car :
                        //champ est l'dresse du tableau de caractères à modifier
                        //tailleChamp est la capacité totale de ce tableau en octets
                        //nomChamp est le texte utilisé dans le printf
                        //Et titre est un tableau directement déclaré dans la structure Livre, sizeof retourne sa capacité totale.
                        // La fonction lireChaine() ne serait donc pas pertinente car elle  ne sert pas à déterminer la capacité d'un tableau. Elle sert à lire une chaîne de caractères en respectant une capacité qu'on lui fournit.
                        nomChamp = "titre";
                        break;

                    case 2:
                        champ = nouveauLivre.auteur;
                        tailleChamp = sizeof nouveauLivre.auteur;
                        nomChamp = "auteur";
                        break;

                    case 3:
                        champ = nouveauLivre.description;
                        tailleChamp = sizeof nouveauLivre.description;
                        nomChamp = "description";
                        break;

                    default:
                        continue;
                }

                // Lire la correction dans un tableau temporaire :
                char correction[
                    sizeof nouveauLivre.titre
                    + sizeof nouveauLivre.auteur
                    + sizeof nouveauLivre.description
                ];

                char *resultat;

                do {
                    printf("Saisissez le nouveau %s : ", nomChamp);

                    resultat = lireChaine(correction, tailleChamp);

                    if (resultat == NULL && (feof(stdin) || ferror(stdin))) {
                        printf("Lecture interrompue : ajout annule.\n");
                        return;
                    }

                } while (resultat == NULL);

                // Appliquer la correction uniquement apres validation
                strcpy(champ, correction);

                printf("Champ corrigé avec succes.\n");

            } while (choixCorrection != 0);

            // Revenir au recap
            continue;
        }

        // CHOIX UTILISATEUR valide: CONFIRMATION
        if (choix == 1) {
            // A implementer : identifiant, disponibilite,
            // enregistrement dans collection et compteur.
            printf("Confirmation : enregistrement a implementer.\n");
            return;
        }

    } while (1);
}
