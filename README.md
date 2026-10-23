# Ma Petite Médiathèque — TP1 Langage C

## Présentation

Projet d'apprentissage du langage C, réalisé à partir d'un premier travail d'algorithmique.

L'objectif est de développer progressivement une application console permettant de gérer une collection de livres, tout en découvrant les structures, les fonctions, les tableaux et la programmation modulaire.

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
| `main.c` | Initialisation de la collection et lancement du menu principal |
| `Livre.h` | Structure `Livre`, constantes et prototypes des fonctions |
| `Mediatheque.h` | Fichier préparé pour la future structure `Mediatheque` |
| `Menu.h` | Déclaration de la fonction du menu principal |
| `menu.c` | Gestion du menu principal et affichage des sous-menus |
| `afficher.c` | Affichage et filtrage des livres |
| `lire.c` | Lecture et validation des saisies |
| `ajouter.c` | Développement de l'ajout de livres |
| `rechercher.c` | Recherche de livres par différents critères |

`main.c` initialise la collection et lance le menu principal, dont la gestion est désormais assurée par `menu.c`.

Les fichiers du dossier `src/` regroupent les fonctionnalités spécialisées.

Le fichier `Livre.h` permet aux différents modules de partager les déclarations liées aux livres. `Menu.h` déclare la fonction de lancement du menu principal, tandis que `Mediatheque.h` prépare une future évolution de la gestion de la collection.

## Fonctionnement actuel

La médiathèque utilise un tableau pouvant contenir **100 livres**.

Chaque livre est représenté par une structure `Livre` contenant un identifiant, un titre, un auteur, une description et un état de disponibilité.

Le programme démarre avec **4 livres de démonstration**, pour le bien de nos tests.

Les fonctionnalités actuellement opérationnelles sont :

- Afficher tous les livres.
- Afficher uniquement les livres disponibles.
- Afficher uniquement les livres empruntés.
- Rechercher un livre selon les critères proposés.
- Naviguer entre les menus.
- Contrôler les choix saisis par l'utilisateur.

La fonction d'ajout de livres est en cours de développement dans `ajouter.c`, mais n'est pas encore raccordée au menu principal.

## Compilation et exécution

Depuis la racine du projet, sous PowerShell :

```powershell
gcc -Wall -Wextra -Wpedantic -std=c11 main.c src/*.c -o main.exe
.\main.exe
```

## Prochaines évolutions

- Finaliser l'ajout de livres avec confirmation et correction.
- Raccorder la fonction d'ajout au menu principal.
- Poursuivre la gestion de la collection et les fonctionnalités prévues par le projet.

---

**Langage :** C  
**Type :** Application console  
**Statut :** En cours de développement
