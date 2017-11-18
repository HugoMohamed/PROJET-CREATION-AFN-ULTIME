#include "pile.h"

void pile_initVide(pile p)
{
    int i;
    for(i=0;i<TAILLE;i++)
	p[i] = 0;
}

void pile_empiler(pile p, int element)
{
    int i = 1;
    while(p[i] > 0)
	i++;
    p[i] = element;
    p[0]++;
}

void pile_depiler(pile p)
{
    int i = 1;
    while(p[i] > 0)
	i++;
    p[i-1] = 0;
    p[0]--;
}

void pile_afficher(pile p)
{
    int i;
    for(i=1; i<=p[0];i++)
	fprintf(stdout,"%d ",p[i]);
    fprintf(stdout,"\n");
}
