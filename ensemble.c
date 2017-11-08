#include "ensemble.h"

void ens_creerEnsemble(int tableau[],int tailleTableau, ensemble e)
{
    int i;
    e[0]=0;
  
    for(i=0;i<tailleTableau;i++)
    {
	e[tableau[i]] = 1;
	e[0]++;

	if(e[i+1] != 1)
	    e[i+1] = 0;
    }
}


void ens_afficher(ensemble e)
{
  int i,j;

  for(i=1,j=0;j<=e[0];i++)
    {
	if(e[i] == 1)
	{
	    fprintf(stdout,"%d ",i);
	    j++;
	}
    }
    fprintf(stdout,"\n");
}


void ens_ajouterElement(ensemble e, int element)
{
    e[element]=1;
    e[0]++;
}


void ens_union(ensemble a, ensemble b, ensemble uni)
{
    int i;
    uni[0] = 0;
    
    for(i=1;i<(a[0]+b[0])+2;i++)
    {
	uni[i] = a[i] + b[i];
	if(uni[i] > 1)
	    uni[i] = 1;
	uni[0] += uni[i];
    }
}

void ens_intersection(ensemble a,ensemble b, ensemble inter)
{
  int i,j;
    inter[0] = 0;
    
    for(i=1,j=0;j<(a[0]+b[0]);i++)
    {
	if(a[i] && b[i])
	{
	    inter[i] = 1;
	    inter[0] += inter[i];
	    j++;
	}
    }
}
