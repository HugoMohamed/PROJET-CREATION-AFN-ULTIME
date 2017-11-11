/******************************************
*
* Nom du fichier : ensemble.h
*
* Description: header de ensemble.c
*
******************************************/

#include <stdio.h>
#include <stdlib.h>

#define TAILLE 1000
typedef int ensemble[TAILLE];

// ens_creerEnsemble permet de creer un ensemble a partir d'un tableau d'entier, dont les entiers correspondent au éléments de l'ensemble.  
void ens_creerEnsemble(int tableau[],int tailleTableau, ensemble e);

// Permet d'afficher les éléments d'un ensemble e.
void ens_afficher(ensemble e);

// Permet d'ajouter l'élément element à l'ensemble e
void ens_ajouterElement(ensemble e, int element);

// Renvoie 1 si l'élément existe dans l'ensemble e et 0 sinon
int ens_existe(ensemble e, int element);

// Dispose dans l'ensemble uni les éléments de a union b
void ens_union(ensemble a, ensemble b, ensemble uni);

// dispose dans l'ensemble inter les éléments de a inter b
void ens_intersection(ensemble a, ensemble b, ensemble inter);
