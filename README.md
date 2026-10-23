# Ma Petite Médiathèque — TP1 Langage C

## Présentation

Projet d'apprentissage du langage C, réalisé en binôme à partir d'un premier travail d'algorithmique.

L'objectif est de développer progressivement une application console permettant de gérer une collection de livres, tout en mettant en pratique les structures, les fonctions, les tableaux, les pointeurs et la programmation modulaire.

Cette première partie du TP porte principalement sur la gestion d'une collection, l'ajout, l'affichage et la recherche de livres, ainsi que sur la fiabilisation des saisies utilisateur.

## Architecture

```text
01_Mediatheque_C/
├── main.c
├── Livre.h
├── Mediatheque.h
├── Menu.h
├── README.md
└── src/
    ├── menu.c
    ├── afficher.c
    ├── lire.c
    ├── rechercher.c
    └── ajouter.c
```

### Choix d'architecture

Le programme est réparti en plusieurs fichiers afin de séparer les responsabilités :

| Fichier | Rôle |
|---|---|
| `main.c` | Initialisation de la médiathèque et lancement du menu principal |
| `Livre.h` | Définition de la structure `Livre` et des constantes associées |
| `Mediatheque.h` | Définition de la structure `Mediatheque` et déclaration des fonctions |
| `Menu.h` | Déclaration de la fonction du menu principal |
| `menu.c` | Gestion du menu principal et des sous-menus |
| `afficher.c` | Affichage et filtrage des livres |
| `lire.c` | Lecture et validation des saisies utilisateur |
| `ajouter.c` | Ajout de livres avec confirmation et correction |
| `rechercher.c` | Recherche de livres selon différents critères |

La structure `Livre` regroupe les informations propres à chaque livre : identifiant, titre, auteur, année de publication, description et disponibilité.

La structure `Mediatheque` regroupe quant à elle le tableau des livres, leur nombre et le prochain identifiant à attribuer.

Les fonctions accèdent à la médiathèque par pointeur, ce qui permet notamment de modifier durablement son contenu lors de l'ajout d'un livre.

## Fonctionnement actuel

La médiathèque utilise un tableau pouvant contenir **100 livres maximum**.

Le programme démarre avec une collection vide. Chaque nouveau livre reçoit automatiquement un identifiant unique et est considéré comme disponible par défaut.

Les fonctionnalités actuellement implémentées sont :

- **Ajouter un livre :** saisie du titre, de l'auteur, de l'année et de la description, avec récapitulatif, possibilité de correction, confirmation ou annulation.
- **Afficher les livres :** affichage de toute la collection ou filtrage selon la disponibilité.
- **Rechercher un livre :** recherche par identifiant, titre ou auteur, avec prise en charge des correspondances partielles pour les champs textuels.
- **Naviguer entre les menus :** utilisation de boucles `do...while` et de structures `switch`.
- **Contrôler les saisies :** vérification des valeurs numériques, des champs vides, des longueurs de chaînes et des choix utilisateur.

Une attention particulière a été portée à la gestion des erreurs, notamment pour éviter les saisies invalides et empêcher l'ajout lorsque la collection est pleine.

Les données sont actuellement conservées en mémoire pendant l'exécution du programme.

## Compilation et exécution

Le projet utilise le langage C, avec la norme **C11** et le compilateur GCC.

Depuis la racine du projet :

**Sous Windows (PowerShell) :**

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic main.c src/*.c -o main.exe
.\main.exe
```

**Sous Linux / WSL :**

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic main.c src/*.c -o main
./main
```

Les options `-Wall`, `-Wextra` et `-Wpedantic` permettent d'activer des avertissements supplémentaires lors de la compilation.

## Tests et vérifications

Plusieurs scénarios de test ont été prévus pour vérifier le bon fonctionnement des fonctionnalités de la médiathèque et la gestion des saisies utilisateur.

### Tests fonctionnels

| Fonctionnalité | Scénarios de test |
|---|---|
| Menu principal | Navigation entre les différentes options et retour au menu principal |
| Ajout de livres | Ajout d'un livre avec des informations valides |
| Confirmation d'ajout | Confirmation, correction d'un ou plusieurs champs et annulation de l'opération |
| Identifiants | Vérification de l'attribution automatique d'un identifiant unique à chaque nouveau livre |
| Affichage | Affichage de la collection complète et filtrage des livres disponibles ou empruntés |
| Recherche | Recherche par identifiant, titre et auteur |
| Recherche textuelle | Recherche partielle et comparaison sans distinction des majuscules et minuscules |

### Tests de robustesse

Des cas particuliers sont également pris en compte dans le programme :

- **Médiathèque vide :** vérification du comportement des fonctions d'affichage et de recherche lorsqu'aucun livre n'est enregistré.
- **Collection pleine :** contrôle de la limite de 100 livres et refus d'un nouvel ajout lorsque cette capacité est atteinte.
- **Saisies invalides :** traitement des champs vides, des choix de menu incorrects et des valeurs numériques non valides.
- **Dépassement de capacité :** détection des chaînes de caractères trop longues.
- **Années de publication :** vérification des valeurs autorisées, y compris certaines années négatives.
- **Interruption de saisie :** gestion de la fin de l'entrée standard ou d'une erreur de lecture.

### Vérifications techniques

Le projet prévoit également une compilation avec GCC en activant les options `-Wall`, `-Wextra` et `-Wpedantic`, afin de détecter les avertissements liés au code.

Les tests sont réalisés progressivement lors du développement et de l'intégration des différentes fonctionnalités.

L'objectif est de vérifier non seulement le fonctionnement nominal de l'application, mais également son comportement face aux saisies incorrectes et aux situations particulières.

## Répartition du travail

Le projet **Ma Petite Médiathèque** est développé en binôme par **Sarah et Tristan**.

Le travail a été réparti principalement par fonctionnalités, tout en conservant une collaboration sur l'architecture, l'intégration des modules et la gestion des erreurs.

### Sarah — Ajout de livres, structuration et documentation

Sarah s'est principalement chargée du **développement du système d'ajout de livres** et a contribué à **l'organisation générale du projet** ainsi que quelques **corrections mineures sur la gestion des menus**.

**Développement de l'ajout (`src/ajouter.c`) :**
- Mise en place de la saisie des informations d'un livre : titre, auteur, année de publication et description.
- Création d'un récapitulatif permettant à l'utilisateur de vérifier les informations saisies.
- Développement d'un système de confirmation, de correction ou d'annulation de l'ajout.
- Possibilité de corriger individuellement les champs avant l'enregistrement définitif.
- Attribution automatique d'un identifiant unique et initialisation de la disponibilité du livre.
- Mise à jour du nombre de livres et du prochain identifiant de la médiathèque.

**Validation des données et gestion des erreurs :**
- Mise en place des vérifications nécessaires à l'ajout : champs vides, saisies trop longues et valeurs invalides.
- Développement et adaptation de la lecture des années de publication, notamment pour accepter certaines années négatives.
- Vérification de la capacité maximale de la collection et de la cohérence des données avant l'enregistrement.
- Gestion des annulations et des interruptions de saisie.

**Architecture et organisation :**
- Participation à la réorganisation des fichiers du projet pour séparer les différentes fonctionnalités.
- Évolution des structures et des fichiers d'en-tête, notamment `Livre.h` et `Mediatheque.h`.
- Adaptation de l'initialisation de la médiathèque dans `main.c`.
- Création et mise à jour de la documentation générale du projet (`README.md`).

### Tristan — Affichage, recherche et gestion des menus

Tristan s'est principalement chargé du **développement des fonctionnalités d'affichage et de recherche**, ainsi que des mécanismes de navigation et de lecture des saisies.

**Affichage de la collection (`src/afficher.c`) :**
- Développement de l'affichage des livres enregistrés dans la médiathèque.
- Parcours du tableau de structures pour présenter les informations de chaque livre.
- Mise en place des filtres permettant d'afficher uniquement les livres disponibles ou empruntés.
- Gestion des cas où la collection est vide ou lorsqu'aucun livre ne correspond au filtre.

**Recherche de livres (`src/rechercher.c`) :**
- Développement de la recherche d'un livre à partir de son identifiant.
- Mise en place de la recherche par titre.
- Ajout de la recherche par auteur.
- Gestion des recherches textuelles partielles et de la comparaison sans distinction des majuscules et minuscules.
- Gestion des recherches sans résultat et de l'affichage des livres correspondants.

**Menus et saisies (`src/menu.c`, `src/lire.c`) :**
- Développement des menus d'affichage et de recherche.
- Participation à la gestion du menu principal et à la navigation entre les fonctionnalités.
- Mise en place de fonctions communes pour lire et contrôler les saisies utilisateur.
- Vérification des choix de menu et gestion des saisies invalides.
- Amélioration du traitement des erreurs et des interruptions de lecture.

**Intégration et fiabilisation :**
- Participation


L'organisation du projet, l'intégration des fonctionnalités et les ajustements du code ont également fait l'objet d'un travail commun.

Le développement est suivi sur **GitHub**, avec des branches individuelles permettant à chacun de développer ses fonctionnalités avant de les intégrer au projet.

## Prochaines évolutions

Les prochaines étapes du développement comprennent notamment :

- Permettre la modification d'un livre déjà enregistré.
- Ajouter la suppression d'un livre.
- Gérer les emprunts et les retours.
- Trier la collection par titre.
- Afficher des statistiques sur les livres.

Optionnel si le binome à le temps :

- options de tri pour la fonction affichage (année décroissant/croissant, auteur/titre par ordre alphabetique croissant/decroissant)
- fix UX : permettre la confirmation juste après la correction d'un champ dans l'ajout de livre (plutot que repasser par le sous menu)

Ces fonctionnalités permettront de poursuivre le développement de la médiathèque dans le cadre de la seconde partie du TP.

---

**Langage :** C (C11)  
**Type :** Application console  
**Auteurs :** Sarah et Tristan  
**Statut :** Partie 1 — Terminée
