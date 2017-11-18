#include "afn.h"

int main(int argc, char *argv[])
{
    /*int tab[TAILLE]={5,6,8};
      int tabA[TAILLE] = {4,5,6,89};
      int tabB[TAILLE] = {6,7,8,9,12,89};
      int i;*/
    afn a;
    pile p;
    ensemble dep,succ,cor[TAILLE];
    ens_initVide(succ);
    ens_initVide(dep);
    ens_ajouterElement(dep,1);
    ens_ajouterElement(dep,3);
    afn_initAfn(&a);
    afn_successeurPartie(a,dep,'a',succ);
    ens_afficher(succ);
    /*ens_afficher(a.transition[1][1]);
    
      afn_afficherTrans(a);
      afn_emonder(a);
      printf("TRANS EMONDER\n");
      afn_afficherTrans(a);
    */
    pile_initVide(p);
    pile_afficher(p);
    pile_empiler(p,1);
    pile_empiler(p,3);
    pile_afficher(p);
    fprintf(stdout,"%d\n",pile_hautPile(p));
    pile_depiler(p);
    pile_afficher(p);
    fprintf(stdout,"%d\n",pile_hautPile(p));
    exit(0);
} 
