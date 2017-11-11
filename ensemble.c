/******************************************
*
* Nom du fichier : ensemble.c
*
* Description: gère les différentes fonctions liées au ensembles
*
******************************************/

#include "ensemble.h"

void ens_creerEnsemble(int tableau[],int tailleTableau, ensemble e)
{
    int i;
  
    for(i=0;i<=tailleTableau;i++)
	e[tableau[i]] = 1;
    e[0]=0;
    for(i=1;i<TAILLE;i++){
	if(e[i] == 1)
	    e[0]++;
	if(e[i] != 1)
	    e[i] = 0;
    }
    
}


void ens_afficher(ensemble e)
{
    int i,j;

    for(i=1,j=0;j<e[0];i++)
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


int ens_existe(ensemble e, int element)
{
    return(e[element] == 1);
}


void ens_union(ensemble a, ensemble b, ensemble uni)
{
    int i;
    uni[0] = 0;
    
    for(i=1;i<TAILLE;i++)
    {
	if(a[i]==1 || b[i]==1)
	{
	    uni[i] = 1;
	    uni[0] ++;
	  
	}
	else
	    uni[i] = 0;

    }
}

void ens_intersection(ensemble a,ensemble b, ensemble inter)
{
    int i;
    inter[0] = 0;
    
    for(i=1;i<TAILLE;i++)
    {
	if(a[i]==1 && b[i]==1)
	{
	    inter[i] = 1;
	    inter[0]++;
	}
	else
	    inter[i]=0;
    }
}
