#include <stdio.h>
#include <stdlib.h>
#include "books.h"

int main() {
    int choix;
    chargerLivres();

    do {
        printf("\n=== Gestionnaire de Bibliotheque ===\n");
        printf("1. Ajouter un livre\n");
        printf("2. Lister les livres\n");
        printf("3. Rechercher un livre\n");
        printf("4. Modifier un livre\n");
        printf("5. Supprimer un livre\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterLivre(); break;
            case 2: afficherLivres(); break;
            case 3: rechercherLivre(); break;
            case 4: modifierLivre(); break;
            case 5: supprimerLivre(); break;
            case 0: sauvegarderLivres(); printf("Au revoir !\n"); break;
            default: printf("Choix invalide !\n");
        }
    } while (choix != 0);

    return 0;
}
