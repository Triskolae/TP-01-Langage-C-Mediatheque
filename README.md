# Ma Petite Médiathèque — TP1 Langage C

## Présentation

Projet d'apprentissage du langage C, réalisé en binôme à partir d'un premier travail d'algorithmique.

L'objectif est de développer progressivement une application console permettant de gérer une collection de livres, tout en mettant en pratique les structures, les fonctions, les tableaux, les pointeurs et la programmation modulaire.

Le projet couvre désormais les deux parties du TP : gestion de la collection (ajout, affichage, recherche), puis suppression, tri, emprunt, retour et statistiques. Une attention particulière est portée à la fiabilisation des saisies utilisateur.

## Architecture

```text
01_Mediatheque_C/
├── main.c
├── Livre.h
├── Mediatheque.h
├── Menu.h
├── Utilitaires.h
├── README.md
├── src/
│   ├── menu.c
│   ├── afficher.c
│   ├── lire.c
│   ├── rechercher.c
│   ├── ajouter.c
│   ├── supprimer.c
│   ├── trier.c
│   ├── utilitaires.c
│   ├── emprunter.c
│   ├── retourner.c
│   └── statistiques.c
└── tests/
    ├── lancer_tests.sh
    └── resultats/         # Sorties générées par le script
```

### Choix d'architecture

Le programme est réparti en plusieurs fichiers afin de séparer les responsabilités :

| Fichier | Rôle |
|---|---|
| `main.c` | Initialisation de la médiathèque et lancement du menu principal |
| `Livre.h` | Définition de la structure `Livre` et des constantes associées |
| `Mediatheque.h` | Définition de la structure `Mediatheque` et déclaration des fonctions |
| `Menu.h` | Déclaration de la fonction du menu principal |
| `Utilitaires.h` | Déclarations des fonctions utilitaires de lecture et de conversion de chaînes |
| `menu.c` | Gestion du menu principal et des sous-menus |
| `afficher.c` | Affichage et filtrage des livres |
| `lire.c` | Lecture et validation des saisies utilisateur |
| `ajouter.c` | Ajout de livres avec confirmation et correction |
| `rechercher.c` | Recherche de livres selon différents critères et sélection pour les opérations |
| `supprimer.c` | Suppression d’un livre par identifiant et réorganisation du tableau |
| `trier.c` | Interface utilisateur du tri par titre |
| `utilitaires.c` | Conversion des chaînes en minuscules et algorithme de tri à bulles |
| `emprunter.c` | Vérification, confirmation et exécution d’un emprunt |
| `retourner.c` | Vérification, confirmation et exécution d’un retour |
| `statistiques.c` | Calcul et affichage des statistiques de la collection |
| `tests/lancer_tests.sh` | Exécution de scénarios de tests et génération de leurs sorties |

La structure `Livre` regroupe les informations propres à chaque livre : identifiant, titre, auteur, année de publication, description et disponibilité.

La structure `Mediatheque` regroupe quant à elle le tableau des livres, leur nombre et le prochain identifiant à attribuer.

Les fonctions accèdent à la médiathèque par pointeur pour modifier durablement son contenu (ajout, suppression, tri, emprunt et retour). Les fonctions de consultation peuvent recevoir un pointeur `const` lorsqu'elles ne modifient pas la collection.

## Fonctionnement actuel

La médiathèque utilise un tableau pouvant contenir **100 livres maximum**.

Le programme démarre avec une collection vide. Chaque nouveau livre reçoit automatiquement un identifiant unique et est considéré comme disponible par défaut.

Les fonctionnalités actuellement implémentées sont :

- **Ajouter un livre :** saisie du titre, de l'auteur, de l'année et de la description, avec récapitulatif, possibilité de correction, confirmation ou annulation.
- **Afficher les livres :** affichage de toute la collection ou filtrage selon la disponibilité.
- **Rechercher un livre :** recherche par identifiant, titre ou auteur, avec prise en charge des correspondances partielles pour les champs textuels.
- **Supprimer un livre :** recherche par identifiant et suppression de l'élément, avec décalage des livres suivants pour conserver un tableau contigu.
- **Trier la collection :** tri alphabétique croissant par titre, sans distinction des majuscules et minuscules, à l'aide d'un tri à bulles.
- **Emprunter un livre :** choix du mode de recherche (ID, titre ou auteur), sélection du livre par ID, récapitulatif et confirmation. L'emprunt n'est possible que si le livre est disponible.
- **Rendre un livre :** même parcours de sélection et de confirmation ; le retour n'est possible que si le livre est actuellement emprunté.
- **Afficher les statistiques :** nombre total de livres, livres disponibles et livres empruntés.
- **Naviguer entre les menus :** utilisation de boucles `do...while` et de structures `switch`.
- **Contrôler les saisies :** vérification des valeurs numériques, des champs vides, des longueurs de chaînes et des choix utilisateur.

Une attention particulière a été portée à la gestion des erreurs, notamment pour éviter les saisies invalides et empêcher l'ajout lorsque la collection est pleine.

Les données sont conservées uniquement en mémoire pendant l'exécution du programme : elles ne sont pas sauvegardées entre deux lancements. Les identifiants sont attribués lors de l'ajout et ne correspondent pas nécessairement à la position d'un livre dans le tableau, notamment après un tri ou une suppression.

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
| Suppression | Suppression d'un livre par ID, puis vérification de la collection |
| Tri | Tri des titres avec des différences de casse |
| Emprunt | Recherche par ID, titre ou auteur ; confirmation ; changement de disponibilité |
| Retour | Retour d'un livre emprunté ; confirmation ; changement de disponibilité |
| Statistiques | Vérification des trois compteurs après ajout, emprunt, retour et suppression |

### Tests de robustesse

Des cas particuliers sont également pris en compte dans le programme :

- **Médiathèque vide :** vérification du comportement des fonctions d'affichage et de recherche lorsqu'aucun livre n'est enregistré.
- **Collection pleine :** contrôle de la limite de 100 livres et refus d'un nouvel ajout lorsque cette capacité est atteinte.
- **Saisies invalides :** traitement des champs vides, des choix de menu incorrects et des valeurs numériques non valides.
- **Dépassement de capacité :** détection des chaînes de caractères trop longues.
- **Années de publication :** vérification des valeurs autorisées, y compris certaines années négatives.
- **Interruption de saisie :** gestion de la fin de l'entrée standard ou d'une erreur de lecture.
- **Opérations incompatibles :** refus d'emprunter un livre déjà emprunté ou de rendre un livre déjà disponible.
- **Annulation :** absence de modification de la disponibilité si l'utilisateur refuse la confirmation.

### Vérifications techniques

Le projet prévoit également une compilation avec GCC en activant les options `-Wall`, `-Wextra` et `-Wpedantic`, afin de détecter les avertissements liés au code.

Les tests sont réalisés progressivement lors du développement et de l'intégration des différentes fonctionnalités.

L'objectif est de vérifier non seulement le fonctionnement nominal de l'application, mais également son comportement face aux saisies incorrectes et aux situations particulières.

### Tests programmatiques

Depuis la racine du projet, compiler le programme, puis lancer le script :

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic main.c src/*.c -o main
chmod +x tests/lancer_tests.sh
./tests/lancer_tests.sh
```

Le script exécute des scénarios de saisie et enregistre les sorties dans `tests/resultats/`. **Il ne vérifie pas automatiquement que les résultats sont corrects** : les fichiers générés doivent être examinés et comparés aux comportements attendus. Les scénarios actuellement scriptés concernent surtout l'ajout, l'affichage, la recherche et la robustesse des saisies. La suppression, le tri, l'emprunt, le retour et les statistiques doivent également être vérifiés manuellement ou faire l'objet de scénarios complémentaires.

## Répartition du travail

Le projet **Ma Petite Médiathèque** est développé en binôme par **Sarah et Tristan**.

Le travail a été réparti principalement par fonctionnalités, tout en conservant une collaboration sur l'architecture, l'intégration des modules et la gestion des erreurs.

### Sarah — Ajout, emprunt, retour, statistiques et documentation

Sarah s'est principalement chargée du **développement du système d'ajout de livres**, puis de **l'emprunt, du retour et des statistiques de base**. Elle a également contribué à **l'organisation générale du projet**, à l'intégration des fonctionnalités et à quelques **corrections mineures sur la gestion des menus**.

**Développement de l'ajout (`src/ajouter.c`) :**
- Mise en place de la saisie des informations d'un livre : titre, auteur, année de publication et description.
- Création d'un récapitulatif permettant à l'utilisateur de vérifier les informations saisies.
- Développement d'un système de confirmation, de correction ou d'annulation de l'ajout.
- Possibilité de corriger individuellement les champs avant l'enregistrement définitif.
- Attribution automatique d'un identifiant unique et initialisation de la disponibilité du livre.
- Mise à jour du nombre de livres et du prochain identifiant de la médiathèque.

**Emprunt, retour et statistiques (`src/emprunter.c`, `src/retourner.c`, `src/statistiques.c`) :**
- Mise en place des opérations d'emprunt et de retour, avec contrôle de la disponibilité et valeurs de retour `1` (succès) ou `0` (échec).
- Ajout d'un parcours de sélection commun par ID, titre ou auteur, avec récapitulatif et confirmation avant modification.
- Calcul et affichage des nombres de livres au total, disponibles et empruntés.
- Adaptation des déclarations et du menu principal pour intégrer ces fonctionnalités, en réutilisant les fonctions existantes.

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
- Participation à l'intégration des fonctionnalités développées en binôme.


L'organisation du projet, l'intégration des fonctionnalités et les ajustements du code ont également fait l'objet d'un travail commun.

Le développement est suivi sur **GitHub** (https://github.com/Triskolae/TP-01-Langage-C-Mediatheque), avec des branches individuelles permettant à chacun de développer ses fonctionnalités avant de les intégrer au projet.

## Prochaines évolutions

Les fonctionnalités obligatoires des deux parties du TP sont présentes dans le code. Les évolutions ci-dessous restent **envisagées et non implémentées** dans cette version :

- Afficher le livre le plus ancien et le plus récent selon l'année de publication.
- Compter les auteurs différents dans la collection.
- Identifier le livre le plus emprunté et l'auteur dont les livres cumulent le plus d'emprunts. **Ces deux statistiques nécessitent d'ajouter un compteur historique d'emprunts**, absent de la structure `Livre` actuelle.
- Proposer davantage d'options de tri (année croissante/décroissante, auteur ou titre dans les deux sens).
- Améliorer le parcours de correction d'un ajout pour proposer directement la confirmation après une modification de champ.
- Éventuellement permettre la modification d'un livre déjà enregistré.

## Utilisation de l'intelligence artificielle

L'IA, notamment ChatGPT, a été utilisée comme **outil d'accompagnement pédagogique et d'assistance au développement** tout au long du projet. 
Elle a permis de clarifier certaines notions du langage C, d'identifier des erreurs et d'améliorer la documentation. 
Les propositions générées ont été examinées, adaptées et testées par le binôme avant leur intégration. 
L'IA a ainsi servi de support à l'apprentissage et à la résolution de problèmes, sans remplacer la compréhension du fonctionnement du programme ni les vérifications réalisées par les étudiants.

---

**Langage :** C (C11)  
**Type :** Application console  
**Auteurs :** Sarah et Tristan  
**Statut :** Parties 1 et 2 — Fonctionnalités implémentées ; vérifications complémentaires possibles
