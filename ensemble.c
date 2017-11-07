#include "ensemble.h"

ensemble ens_creerEnsemble(int tableau[],int tailleTableau)
{
    int i;
    ensemble e;
    e[0]=0;
  
    for(i=1;i<tailleTableau;i++)
    {
	if(tableau[i] == i)
	{
	    e[i] = 1;
	    e[0]++;
	}
	else
	{
	    e[i]=0;
	}
    }
    return e;
}


void ens_afficher(ensemble e)
{
    int i;

    for(i=1;i<e[0];i++)
    {
	if(e[i] == 1)
	{
	    printf("%d ",i);
	}
    }
}
