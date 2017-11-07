#define TAILLE 1000
typedef int ensemble[TAILLE]

// ens_creerEnsemble permet de creer un ensemble a partir d'un tableau d'entier, dont les entiers correspondent au éléments de l'ensemble.  
ensemble ens_creerEnsemble(int tableau[],int tailleTableau);

void ens_afficher(ensemble e);

void ens_ajouterEnsemble(ensemble e, int element);
