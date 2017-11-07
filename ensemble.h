#include <stdio.h>
#include <stdlib.h>

#define TAILLE 1000
typedef int ensemble[TAILLE];

// ens_creerEnsemble permet de creer un ensemble a partir d'un tableau d'entier, dont les entiers correspondent au éléments de l'ensemble.  
void ens_creerEnsemble(int tableau[],int tailleTableau, ensemble e);

void ens_afficher(ensemble e);

void ens_ajouterElement(ensemble e, int element);

void ens_union(ensemble a, ensemble b, ensemble uni);

void ens_intersection(ensemble a, ensemble b, ensemble inter);
