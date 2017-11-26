#include "afn.h"

int main(int argc, char *argv[])
{
    int i,j,k,n;
    ensemble corres[TAILLE];
    afn a,b;
    afn_initAfn(&a);
    afn_initAfnVide(&b);
    n = afn_determiniser(&a,&b,corres);
    // affiche les transitions
    fprintf(stdout,"Liste des transitions :\n");
    for(i=1;i<TAILLE;i++)
	for(j=1;j<TAILLE;j++)
	    for(k=1;k<TAILLE;k++)
		if(ens_existe(b.transition[i][j],k))
		    fprintf(stdout,"(%d,%c,%d)\n",i,(char)k+96,j);
    // correspondances
    fprintf(stdout,"Avec les correspondances :\n");
    for(i=1;i<n;i++)
    {
	fprintf(stdout,"%d = ",i);
	ens_afficher(corres[i]);
    }

/*int tab[TAILLE]={5,6,8};
      int tabA[TAILLE] = {4,5,6,89};
      int tabB[TAILLE] = {6,7,8,9,12,89};
    afn a;
    pile p;
    afn a;
    ensemble dep,succ,cor[TAILLE];
    ens_initVide(succ);
    ens_initVide(dep);
    ens_ajouterElement(dep,1);
    ens_ajouterElement(dep,3);
    afn_initAfn(&a);
    afn_successeurPartie(a,dep,'a',succ);
    ens_afficher(succ);
    ens_recopierEnsemble(succ,cor[1]);
    afn_successeurPartie(a,dep,'b',succ);
    ens_afficher(succ);
    ens_recopierEnsemble(succ,cor[2]);
    
     ens_afficher(a.transition[1][1]);
    
      afn_afficherTrans(a);
      afn_emonder(a);
      printf("TRANS EMONDER\n");
      afn_afficherTrans(a);
    
    pile_initVide(p);
    pile_afficher(p);
    pile_empiler(p,1);
    pile_empiler(p,3);
    pile_afficher(p);
    fprintf(stdout,"%d\n",pile_hautPile(p));
    pile_depiler(p);
    pile_afficher(p);
    fprintf(stdout,"%d\n",pile_hautPile(p));*/
    exit(0);
} 
