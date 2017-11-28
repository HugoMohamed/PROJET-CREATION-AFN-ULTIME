/******************************************
 *
 * Nom du fichier : afn.c
 *
 * Description : Gère les différentes fonctions qui vont permettre
 * la reconnaissance d'un mot et la déterminisation d'un AFN
 *
 ******************************************/

#include <string.h>
#include "afn.h"

void afn_initAfnVide(afn *a)
{
    int i,j;

    for(i=0;i<TAILLE;i++)
    {
	a->initial[i] = 0;
	a->final[i] = 0;
	for(j=0;j<TAILLE;j++)
	    ens_initVide(a->transition[i][j]);

    }
}

void afn_initAfn(afn *a)
{

    int b,i,j,etat1,etat2;
    char c,lettre,ligne[TAILLE];
    FILE* f;
    f = fopen("afn.txt","r");
    if(f == NULL)
    {
	fprintf(stderr,"erreur, fichier manquant.\n");
	exit(-1);
	}
    for(i=0;i<TAILLE;i++)
    {
	a->initial[i] = 0;
	a->final[i] = 0;
	for(j=0;j<TAILLE;j++)
	    ens_initVide(a->transition[i][j]);

    }
    
    do
    {
	fgets(ligne,TAILLE,f);
	sscanf(ligne,"%c %d",&c,&b);
	if(c=='i')
	{
	    a->initial[b] = 1;
	    a->initial[0]++;
	}
	if(c=='f')
	{
	    a->final[b] = 1;
	    a->final[0]++;
	}
    }
    while(c!='e');

    do
    {
	fgets(ligne,TAILLE,f);
	sscanf(ligne,"%c %d %c %d",&c,&etat1,&lettre,&etat2);
	if(c=='t')
	ens_ajouterElement(a->transition[etat1][etat2],(int)lettre-96);
    }
    while(c!='E');
    
    fclose(f);
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

//Fonctionne quand on fait toutes fonctions en interne, mais pas avec l'appel aux fonctions
//a l'afn de base, b l'afd, corres un tableau d'ensemble
//les états i de b correspondent aux ensembles corres[i]
//exemple: b[2]=1 => état 2 = corres[2] = {x,y,...}
int afn_determiniser(afn *a, afn *b,ensemble *corres)
{
    int i,j,n,m,lettre,uni,sommet;
    ensemble succ;
    pile p;
    for(i=0;i<=TAILLE;i++)
	ens_initVide(corres[i]);
    afn_initAfn(a);
    afn_initAfnVide(b);
    //On itinialise la pile, on crée la première partie à traiter, on initialise les initiaux de b
    pile_initVide(p);
    ens_recopierEnsemble(a->initial,corres[1]);
    ens_ajouterElement(b->initial,1);
    pile_empiler(p,1);

    i = 2;

    while(p[0] > 0)
    {
      
	//On traite les transition partant de l'état au sommet de la pile
	sommet = pile_hautPile(p);
	pile_depiler(p);

	//On traite toutes les lettres
	for(lettre=1;lettre<TAILLE;lettre++)
	{

	    ens_initVide(succ);

	    for(n=1;n<TAILLE;n++)
		if(ens_existe(corres[sommet],n))
		    for(m=1;m<TAILLE;m++)

			if(ens_existe(a->transition[n][m],lettre))
			    ens_ajouterElement(succ,m);
	    
	    //Si des transitions (et donc des successeurs) existent
	    if(succ[0] > 0)
	    {
		//On considère l'ensemble des successeurs unique
		uni = 1;

		//On vérifie l'unicité
		for(j=1;j<TAILLE;j++)
		    if(ens_identique(corres[j],succ))
		    {
			//Si l'ensemble existe déjà dans corres[], on fait la
			//transition ver cet ensemble
			ens_ajouterElement(b->transition[sommet][j],lettre);
			uni = 0;
		    }
		//Si l'ensemble est unique, on le recopie dans corres[] et on
		//l'ajoute à la pile
		if(uni == 1)
		{
		    pile_empiler(p,i);
		    ens_recopierEnsemble(succ,corres[i]);
		    ens_ajouterElement(b->transition[sommet][i],lettre);
		    i++;
		}
	    }
	}
    }
    n = i;
    //On rempli les états finaux de b
    for(i=1;i<TAILLE;i++)
    {
	if(ens_existe(a->final,i))
	{
	    for(j=1;j<TAILLE;j++)
	    {
		if(ens_existe(corres[j],i))
		    ens_ajouterElement(b->final,j);
	    }
	}
    }

    return n;
}


void afn_afficherTrans(afn *a)
{
    int i,j,k;
    for(i=1;i<TAILLE;i++)
	for(j=1;j<TAILLE;j++)
	    for(k=1;k<TAILLE;k++)
		if(ens_existe(a->transition[i][j],k))
		    fprintf(stdout,"(%d,%c,%d)\n",i,(char)k+96,j);
}

int afn_estReconnu(afn *a, char *mot)
{
    int i=0,p=1;


    while(i < strlen(mot))
    {
        p = afn_existeTransition(a,p,mot[i]);
	i++;
    }
    if(!(ens_existe(a->final,p)))
	return 0;
    return 1;
    // on empile l'état ou il existe une transition (p,x,q) avec p appartient a I et x = mot[0]
    // on va au bout d'un chemin en faisant a chaque fois mot[i] i++
    // on renvoie 0 si la pile devient vide
    // on renvoie 1 si on trouve une transition (p,x,q) avec x = derniere lettre de m, et q appartient a F.
    
}

int afn_existeTransition(afn *a,int p,char x)
{
    int i=0;
    for(i=1;i<TAILLE;i++)
	if(ens_existe(a->transition[p][i],(int)x-96))
	    return i;
    return 0;
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


