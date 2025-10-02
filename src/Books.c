#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "books.h"

Livre bibliotheque[MAX_BOOKS];
int totalLivres = 0;

void chargerLivres() {
    FILE *f = fopen("./data/books.txt", "r");
    if (f == NULL) return;
    while (fscanf(f, "%99[^;];%99[^;];%d;%19s\n",
                  bibliotheque[totalLivres].titre,
                  bibliotheque[totalLivres].auteur,
                  &bibliotheque[totalLivres].annee,
                  bibliotheque[totalLivres].isbn) != EOF) {
        totalLivres++;
    }
    fclose(f);
}

void sauvegarderLivres() {
    FILE *f = fopen("./data/books.txt", "w");
    if (f == NULL) {
        printf("Erreur ouverture fichier\n");
        return;
    }
    for (int i = 0; i < totalLivres; i++) {
        fprintf(f, "%s;%s;%d;%s\n",
                bibliotheque[i].titre,
                bibliotheque[i].auteur,
                bibliotheque[i].annee,
                bibliotheque[i].isbn);
    }
    fclose(f);
}

void ajouterLivre() {
    if (totalLivres >= MAX_BOOKS) {
        printf("Bibliotheque pleine !\n");
        return;
    }
    Livre l;
    printf("Titre: "); scanf(" %[^
]", l.titre);
    printf("Auteur: "); scanf(" %[^
]", l.auteur);
    printf("Annee: "); scanf("%d", &l.annee);
    printf("ISBN: "); scanf(" %s", l.isbn);

    bibliotheque[totalLivres++] = l;
    printf("Livre ajoute avec succes !\n");
}

void afficherLivres() {
    if (totalLivres == 0) {
        printf("Aucun livre enregistre.\n");
        return;
    }
    for (int i = 0; i < totalLivres; i++) {
        printf("%d. %s - %s (%d) [ISBN:%s]\n", i+1,
               bibliotheque[i].titre,
               bibliotheque[i].auteur,
               bibliotheque[i].annee,
               bibliotheque[i].isbn);
    }
}

void rechercherLivre() {
    char mot[100];
    printf("Entrez un mot cle (titre ou auteur): ");
    scanf(" %[^
]", mot);

    for (int i = 0; i < totalLivres; i++) {
        if (strstr(bibliotheque[i].titre, mot) != NULL ||
            strstr(bibliotheque[i].auteur, mot) != NULL) {
            printf("%d. %s - %s (%d) [ISBN:%s]\n", i+1,
                   bibliotheque[i].titre,
                   bibliotheque[i].auteur,
                   bibliotheque[i].annee,
                   bibliotheque[i].isbn);
        }
    }
}

void modifierLivre() {
    int id;
    afficherLivres();
    printf("Numero du livre a modifier: ");
    scanf("%d", &id);
    if (id < 1 || id > totalLivres) {
        printf("ID invalide.\n");
        return;
    }
    id--;
    printf("Nouveau titre: "); scanf(" %[^
]", bibliotheque[id].titre);
    printf("Nouvel auteur: "); scanf(" %[^
]", bibliotheque[id].auteur);
    printf("Nouvelle annee: "); scanf("%d", &bibliotheque[id].annee);
    printf("Nouvel ISBN: "); scanf(" %s", bibliotheque[id].isbn);

    printf("Livre modifie avec succes !\n");
}

void supprimerLivre() {
    int id;
    afficherLivres();
    printf("Numero du livre a supprimer: ");
    scanf("%d", &id);
    if (id < 1 || id > totalLivres) {
        printf("ID invalide.\n");
        return;
    }
    id--;
    for (int i = id; i < totalLivres - 1; i++) {
        bibliotheque[i] = bibliotheque[i+1];
    }
    totalLivres--;
    printf("Livre supprime avec succes !\n");
}
