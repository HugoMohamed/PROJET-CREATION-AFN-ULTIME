#include "afn.h"

int main(int argc, char *argv[])
{
    int tab[TAILLE]={1,2,3};
    int tabA[TAILLE] = {4,5,6};
    int tabB[TAILLE] = {7,8,9};

    ensemble e,a,b,uni,inter;
    
    ens_creerEnsemble(tab,4,e);
    ens_afficher(e);
    
    ens_ajouterElement(e,4);
    ens_afficher(e);

    ens_creerEnsemble(tabA,6,a);
    ens_creerEnsemble(tabB,6,b);
    
    ens_union(a,b,uni);
    ens_afficher(uni);

    ens_intersection(a,b,inter);
    ens_afficher(inter);
    
    exit(0);
} 
