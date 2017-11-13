#include "afn.h"

int main(int argc, char *argv[])
{
    int tab[TAILLE]={5,6,8};
    int tabA[TAILLE] = {4,5,6,89};
    int tabB[TAILLE] = {6,7,8,9,12,89};

    ensemble e,a,b,uni,inter,succ,acc;

    afn af;

    ens_creerEnsemble(tab,3,e);
    ens_afficher(e);
    
    ens_ajouterElement(e,4);
    ens_afficher(e);

    ens_creerEnsemble(tabA,4,a);
    ens_creerEnsemble(tabB,6,b);
    ens_afficher(a);
    ens_afficher(b);
    
    ens_union(a,b,uni);
    ens_afficher(uni);

    ens_intersection(a,b,inter);
    ens_afficher(inter);
    
    ens_priveDe(a,b);
    ens_afficher(a);

    printf("%d\n",ens_premierElement(a));
    ens_enleverElement(a,4);
    ens_afficher(a);
    
    af = afn_initAfn();
    afn_successeur(af,1,succ);
    ens_afficher(succ);

    afn_accessibles(af,acc);
    ens_afficher(acc);
    
    exit(0);
} 
