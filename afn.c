/******************************************
 *
 * Nom du fichier : afn.c
 *
 * Description : Gère les différentes fonctions qui vont permettre
 * la déterminisation d'un AFN
 *
 *
 ******************************************/

// Déteriniser un AFN A c'est émonder l'automate des parties de A

// afd = afn_emonder(afn_partie); (un truc du style)
#include "afn.h"

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

afn afn_initAfn()
{
    afn a;
    int i,j,etat1,etat2,lettre;
    for(i=0;i<TAILLE;i++)
    {
	a.initial[i] = 0;
	a.final[i] = 0;
	for(j=0;j<TAILLE;j++)
	    a.transition[i][j] = 0;
    }

    fprintf(stdout,"états initiaux (entrer une valeur négative pour arrêter) :\n");
    do
    {
	scanf("%d",&etat1);
	if(etat1 >= 0)
	{
    
	    a.initial[etat1] = 1;
	    a.initial[0]++;   
	}
    }
    while(etat1 >= 0);
    
    viderBuffer();
    fprintf(stdout,"états finaux (entrer une valeur négative pour arrêter) :\n");
    do
    {
	scanf("%d",&etat1);
	if(etat1 >= 0)
	{
    
	    a.final[etat1] = 1;
	    a.final[0]++;   
	}
    }
    while(etat1 >= 0);
    
    viderBuffer();
    fprintf(stdout,"transitions p x q (entrer une valeur négative de p pour arrêter) :\n");
    do
    {
	scanf("%d %d %d",&etat1,&lettre,&etat2);
	if(etat1 >= 0 && etat2 >=0 && lettre >= 0)
	    a.transition[etat1][etat2] = lettre;
    }
    while(etat1 >= 0);
    
    return a;
}
    
 
void afn_successeur(afn a, int etat, ensemble succ)
{
    int i;
    succ[0]=0;
    
    for(i=1;i<TAILLE;i++)
    {
	if(a.transition[etat][i] > 0)
	{
	    succ[i] = 1;
	    succ[0]++;
	}
	else
	    succ[i] = 0;
    }
}
	

int afn_estPuit(afn a, int etat)
{

}


void afn_accessibles(afn a, ensemble accessible)
{/*
    ensemble at,dt;
  
    ensemble at = a.initial; // états a traiter
    ensemble dt = ens_initEnsembleVide(dejaTraiter); // états déjà traités

    while(at[0] != 0)
    */
	}


void afn_coAccessibles(afn a, ensemble coAccessible)
{

}


void afn_emonder(afn a)
{

}


void afn_determiniser(afn a)
{

}
