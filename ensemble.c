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


void ens_ajouterEnsemble(ensemble e, int element)
{
    int i;

    for(i=0;i<e[0];i++)
	if(i == element)
	    e[i] = 1;
    e[0]++;
}


ensemble ens_union(ensemble a, ensemble b)
{
    int i;
    ensemble uni;
    uni[0] = 0;
    
    for(i=1;i<(a[0]+b[0]);i++)
    {
	uni = a[i] + b[i];
	if(uni[i] > 1)
	    uni[i] = 1;
	uni[0] += uni[i];
    }

    return uni;
}
