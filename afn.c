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

void afn_initAfn(afn *a)
{

    int i,j,etat1,etat2;
    char lettre;

    for(i=0;i<TAILLE;i++)
    {
	a->initial[i] = 0;
	a->final[i] = 0;
	for(j=0;j<TAILLE;j++)
	    ens_initVide(a->transition[i][j]);

    }

    fprintf(stdout,"états initiaux (entrer une valeur négative pour arrêter) :\n");
    do
    {
	scanf("%d",&etat1);
	if(etat1 >= 0)
	{
    
	    a->initial[etat1] = 1;
	    a->initial[0]++;   
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
    
	    a->final[etat1] = 1;
	    a->final[0]++;   
	}
    }
    while(etat1 >= 0);
    
    viderBuffer();
    fprintf(stdout,"transitions p x q (entrer une valeur négative de p pour arrêter) :\n");
    do
    {
	scanf("%d %c %d",&etat1,&lettre,&etat2);
	if(etat1 >= 0 && etat2 >=0 && lettre >= 0)
	    ens_ajouterElement(a->transition[etat1][etat2],(int)lettre-96);
    }
    while(etat1 >= 0);

}

void afn_successeurPartie(afn a,ensemble depart,char c,ensemble succ)
{
    int i,j;
    ens_initVide(succ);
    for(i=1;i<=TAILLE;i++)
	if(depart[i])
	    for(j=1;j<TAILLE;j++)
		if(ens_existe(a.transition[i][j],(c-96)))
		    ens_ajouterElement(succ,j);
}


void afn_determiniser(afn a)
{

}

void afn_afficherTrans(afn a)
{/*
    int i,j;
    for(i=1;i<TAILLE;i++)
	for(j=1;j<TAILLE;j++)
	    if(a.transition[i][j] != 0)
	    fprintf(stdout,"(%d,%c,%d)\n",i,a.transition[i][j],j);*/
}
/*  
 
void afn_successeur(afn a, int etat, ensemble succ)
{
    int i,j;
    succ[0]=0;
    
    for(i=1;i<TAILLE;i++)
    {
	for(j=0;j<TAILLE
	if(a.transition[etat][i] > 0)
	{
	    succ[i] = 1;
	    succ[0]++;
	}
	else
	    succ[i] = 0;
	    }
}


void afn_predecesseur(afn a, int etat, ensemble pre)
{
    int i;
    pre[0]=0;

    for(i=1;i<TAILLE;i++)
    {
	if(a.transition[i][etat] > 0)
	{
	    pre[i] = 1;
	    pre[0]++;
	}
	else
	    pre[i] = 0;
	    }
}


void afn_accessibles(afn a, ensemble accessible)
{
    ensemble at,dt,succ;
    int i,p;
    
    for(i=0;i<TAILLE;i++)
	at[i] = a.initial[i];
    ens_initVide(dt); // états déjà traités

    while(at[0] != 0)
    {
	p = ens_premierElement(at);
	afn_successeur(a,p,succ);
	ens_ajouterElement(dt,p);
	ens_enleverElement(at,p);
	ens_priveDe(succ,dt);
	ens_union(at,succ,at);
	
    }
    for(i=0;i<TAILLE;i++)
	accessible[i] = dt[i];
 
}


void afn_coAccessibles(afn a, ensemble coAccessible)
{
    ensemble at,dt,pre;
    int i,q;
    
    for(i=0;i<TAILLE;i++)
	at[i] = a.final[i];
    ens_initVide(dt); // états déjà traités

    while(at[0] != 0)
    {
	q = ens_premierElement(at);
	afn_predecesseur(a,q,pre);
	ens_ajouterElement(dt,q);
	ens_enleverElement(at,q);
	ens_priveDe(pre,dt);
	ens_union(at,pre,at);
	
    }
    for(i=0;i<TAILLE;i++)
	coAccessible[i] = dt[i];
 
}
    

void afn_emonder(afn a)
{
    ensemble utile,acc,coacc;
    int i,j;
    
    afn_accessibles(a,acc);
    afn_coAccessibles(a,coacc);

    ens_intersection(acc,coacc,utile); // L'ensemble des états utiles

    ens_intersection(utile,a.initial,a.initial);
    ens_intersection(utile,a.final,a.final);

    // Calcul des transition émondée.
    for(i=1;i<TAILLE;i++)
	for(j=1;j<TAILLE;j++)
	    if(!(a.transition[i][j] != 0 && ens_existe(utile,i) && ens_existe(utile,j)))
	    a.transition[i][j] = 0;
}
*/


