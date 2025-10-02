#ifndef BOOKS_H
#define BOOKS_H

#define MAX_BOOKS 100

typedef struct {
    char titre[100];
    char auteur[100];
    int annee;
    char isbn[20];
} Livre;

void chargerLivres();
void sauvegarderLivres();
void ajouterLivre();
void afficherLivres();
void rechercherLivre();
void modifierLivre();
void supprimerLivre();

#endif
