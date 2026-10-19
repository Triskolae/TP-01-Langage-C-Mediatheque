# Ma Petite Médiathèque — TP1 Langage C

## Présentation

Projet d'apprentissage du langage C, réalisé à partir d'un premier travail d'algorithmique.

L'objectif est de développer progressivement une application console permettant de gérer une collection de livres, tout en découvrant les structures, les fonctions, les tableaux et la programmation modulaire.

## Architecture

```text
01_Mediatheque_C/
├── main.c
├── Main.h
├── README.md
└── src/
    ├── menu.c
    ├── afficher.c
    ├── lire.c
    ├── recherche.c
    └── ajouter.c

```

### Choix d'architecture

Le programme est réparti en plusieurs fichiers afin de séparer les responsabilités :

| Fichier | Rôle |
|---|---|
| `main.c` | Menu principal, collection et gestion des choix |
| `Main.h` | Structure `Livre`, constantes et prototypes |
| `menu.c` | Affichage des sous-menus |
| `afficher.c` | Affichage et filtrage des livres |
| `lire.c` | Lecture et validation des saisies |
| `ajouter.c` | Fichier prévu pour l'ajout de livres |
| `recherche.c` | Fichier prévu pour la recherche de livres|

`main.c` pilote le programme, tandis que les fichiers du dossier `src/` regroupent les fonctionnalités spécialisées.

Le fichier `Main.h` permet aux différents modules de partager les mêmes déclarations.

## Fonctionnement actuel

La médiathèque utilise un tableau pouvant contenir **100 livres**.

Chaque livre est représenté par une structure `Livre` contenant un identifiant, un titre, un auteur, une description et un état de disponibilité.

Le programme démarre avec **3 livres de démonstration**. Pour le bien de nos tests.

Les fonctionnalités actuellement opérationnelles sont :

- Afficher tous les livres.
- Afficher uniquement les livres disponibles.
- Afficher uniquement les livres empruntés.
- Naviguer entre les menus.
- Contrôler les choix saisis par l'utilisateur.

Les options d'ajout et de recherche sont présentes dans le menu principal, mais ne sont pas encore implémentées.

## Compilation et exécution

Depuis la racine du projet, sous PowerShell :

```powershell
gcc -Wall -Wextra -std=c11 main.c src/*.c -o main.exe
.\main.exe
```

## Prochaines évolutions

- Implémenter l'ajout de livres avec confirmation et correction.
- Développer la recherche par identifiant, titre et auteur.
- Poursuivre la gestion de la collection et les fonctionnalités prévues par le projet.

---

**Langage :** C  
**Type :** Application console  
**Statut :** En cours de développement
