
#!/usr/bin/env bash

# À lancer depuis la racine du projet.
set -u

mkdir -p tests/resultats

if [[ ! -x ./main ]]; then
    echo "Compile d'abord le programme :"
    echo "gcc -std=c11 -Wall -Wextra -Wpedantic -Werror main.c src/*.c -o main"
    exit 1
fi

executer_test() {
    local nom="$1"
    local description="$2"
    local entrees="$3"
    local fichier="tests/resultats/${nom}.txt"
    local statut

    {
        echo "========================================"
        echo "TEST : $nom"
        echo "DESCRIPTION : $description"
        echo "========================================"
        echo
        echo "Entrées envoyées :"
        printf '%s\n' "$entrees"
        echo
        echo "Résultat obtenu :"
        printf '%s' "$entrees" | ./main
        statut=$?
        echo
        echo
        echo "Code de sortie : $statut"
        echo "Résultat attendu : à comparer au plan de tests."
    } > "$fichier" 2>&1

    echo "Résultat enregistré : $fichier"
}

executer_test "01_ajout_valide" \
    "Ajout confirmé" \
    $'1\nDune\nFrank Herbert\n1965\nRoman de science-fiction\n1\n0\n'

executer_test "02_ajout_annule" \
    "Ajout annulé" \
    $'1\nDune\nFrank Herbert\n1965\nRoman de science-fiction\n3\n0\n'

executer_test "03_correction_titre" \
    "Correction du titre" \
    $'1\nDune\nFrank Herbert\n1965\nRoman de science-fiction\n2\n1\nDune revise\n0\n1\n0\n'

executer_test "04_choix_hors_limites" \
    "Choix 9" $'9\n0\n'

executer_test "05_choix_texte" \
    "Choix alphabétique" $'abc\n0\n'

executer_test "06_choix_vide" \
    "Choix vide" $'\n0\n'

executer_test "07_choix_negatif" \
    "Choix négatif" $'-1\n0\n'

executer_test "08_choix_mal_forme" \
    "Nombre suivi de texte" $'1abc\n0\n'

executer_test "09_titre_vide" \
    "Titre vide" \
    $'1\n\nDune\nFrank Herbert\n1965\nRoman\n1\n0\n'

executer_test "10_auteur_vide" \
    "Auteur vide" \
    $'1\nDune\n\nFrank Herbert\n1965\nRoman\n1\n0\n'

executer_test "11_description_vide" \
    "Description vide" \
    $'1\nDune\nFrank Herbert\n1965\n\nRoman valide\n1\n0\n'

executer_test "12_titre_special" \
    "Accents et apostrophe" \
    $'1\nL’Étranger\nAlbert Camus\n1942\nRoman français\n1\n0\n'

executer_test "13_annee_invalide" \
    "Année non numérique" \
    $'1\nDune\nFrank Herbert\nabc\n1965\nRoman\n1\n0\n'

executer_test "14_annee_zero" \
    "Année égale à zéro" \
    $'1\nDune\nFrank Herbert\n0\n1965\nRoman\n1\n0\n'

executer_test "15_annee_min" \
    "Année -1801" \
    $'1\nDune\nFrank Herbert\n-1801\n1965\nRoman\n1\n0\n'

executer_test "16_annee_max" \
    "Année 32768" \
    $'1\nDune\nFrank Herbert\n32768\n1965\nRoman\n1\n0\n'

executer_test "17_affichage_vide" \
    "Affichage collection vide" \
    $'2\n1\n0\n0\n'

executer_test "18_afficher_tous" \
    "Ajout puis affichage" \
    $'1\nDune\nFrank Herbert\n1965\nRoman\n1\n2\n1\n0\n0\n'

executer_test "19_recherche_titre" \
    "Recherche titre existant" \
    $'1\nDune\nFrank Herbert\n1965\nRoman\n1\n3\n2\nDune\n0\n0\n'

executer_test "20_recherche_absente" \
    "Recherche titre absent" \
    $'1\nDune\nFrank Herbert\n1965\nRoman\n1\n3\n2\nInexistant\n0\n0\n'

executer_test "21_recherche_id_absent" \
    "Recherche ID absent" \
    $'1\nDune\nFrank Herbert\n1965\nRoman\n1\n3\n1\n999\n0\n0\n'

if command -v python3 >/dev/null 2>&1; then
    entrees=$(python3 -c "print('1'); print('A'*100); print('Dune'); print('Frank Herbert'); print('1965'); print('Roman'); print('1'); print('0')")
    executer_test "22_titre_trop_long" \
        "Titre de 100 caractères" "$entrees"

    entrees=$(python3 -c "print('1'); print('Dune'); print('Frank Herbert'); print('1965'); print('A'*200); print('Description valide'); print('1'); print('0')")
    executer_test "23_description_trop_longue" \
        "Description de 200 caractères" "$entrees"
fi

echo
echo "Tests terminés. Résultats dans tests/resultats/"
